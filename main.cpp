///Ultimate Owner: Christopher Deng

#include <iostream>
#include <sstream>

#include "avl.h"
#include "utils.h"
#include "DocumentProcessor.h"
#include "fort.hpp"

using std::stringstream;
using std::to_string;

string cutOff(string s, int len); ///used to maintain the length of the title and authors

void do_query(DocumentProcessor &dp, const vector<string> &keywords, set<string> &docSet, const char *version) { ///Rank the resulted list
    /*
    * Make a <docHash, tf-idf> vector and rank according to tf-idf
    */
  vector<pair<string, double>> tfIdfList; ///use to store document ID and tf-idf value


  // Average TF-IDF over keywords
  ///TF-IDF https://zhuanlan.zhihu.com/p/31197209
  for (const auto &docHash : docSet) {
    tfIdfList.push_back(make_pair(docHash, 0.0)); ///Store the document with initial tf-idf value
    for (const auto &keyword : keywords) { ///calculate the tf-idf value for each word user searched
      double totalDocNumInCorpus = dp.docHashes.size();
      double totaldocNum4QueryStr = docSet.size();
      Frequency &freq = dp.wordDocFreqs.find(make_pair(keyword, docHash))->second;///calls the frequency function in a document processor
//    cout << freq.hash << endl;
      double tf = dp.getFreq(freq, docHash);
      double idf = log(totalDocNumInCorpus / (totaldocNum4QueryStr + 1));
      double tfIdf = tf * idf;
      tfIdfList.back().second += tfIdf;
    }
    tfIdfList.back().second /= keywords.size();///average tf-idf value for each documents
  }

  /*
   * Rank
   */
  std::sort(tfIdfList.begin(), tfIdfList.end(), ///sort the list based on the tf-idf value
            [](const pair<string, double> &p1, pair<string, double> &p2) -> bool {
              return p1.second > p2.second; ///custom compare for sort to sort the last
            });

  /*
   * Print
   */
    ///Reference:https://github.com/seleznevae/libfort, used to print a organized a table
  int docNum2Return = std::min(15, static_cast<int>(tfIdfList.size()));///either return first 15 or whatever there is, pick the smallest value
  fort::char_table table;
  table << fort::header
        << "No." /*<< "TD-IDF" */ << "Doc Hash" << "Title(128 chars at Most)" << "Authors(Last Names Only)" << fort::endr;
  cout << "\n============= Query Result Start [ " << version << " ] ===============\n";
  for (int i = 0; i < docNum2Return; ++i) {
    table << to_string(i + 1);

    string cell;
    stringstream ss(cell);

    string docHash = tfIdfList.at(i).first;
    ss << docHash;
    table << ss.str();

    auto myDoc = dp.hash2Doc.find(docHash)->second;
    table << cutOff(myDoc.title, 128);

    string authorsStr;
    for (const auto &au : myDoc.authors) {
      authorsStr += au;
      authorsStr += ", ";
    }
    table << cutOff(authorsStr, 128);

    table << fort::endr;
  }
  cout << table.to_string();
  cout << "============= Query Result End [ " << version << " ] ===============\n";
  cout << "\nDo you want to read more about any document above? Type In its [No.] (Enter 0 for skipping) :";

  int docNum2Read;
  cin >> docNum2Read;
  string dump;
  std::getline(cin, dump);
  if (docNum2Read > 0) {
    docNum2Read--;
    cout << "\n============= Body Begins  ===============\n";
    auto body = dp.hash2Doc.find(tfIdfList.at(docNum2Read).first)->second.body;
    int len = std::min(1500, static_cast<int>(body.length()));
    cout << body.substr(0, len) << endl;
    cout << "\n============= Body Ends  ===============\n";
  }

}

int main() {
  DocumentProcessor dp("../docs_subset/");///Go through files in the folder


  {///Printing out the Top 50 Most Frequent Words
    cout << "Top 50 Most Frequent Word:" << endl;
    fort::char_table table;///Reference:https://github.com/seleznevae/libfort, used to print a organized a table
    table << fort::header
          << "No." << "Word" << "Total Count" << fort::endr;
    int i = 0;
    auto queryMap = dp.getWordsInCorpusByFreqDesc();///Gets the words list
    for (auto queryMapItr = queryMap.rbegin(); queryMapItr != queryMap.rend(); ++queryMapItr) {
      i++;
      int count = queryMapItr->first;
      string str = queryMapItr->second;
      table << i << str << count << fort::endr;
      if (i == 50) {
        break;
      }
    }
    cout << table.to_string();///printing out the actual table
  }

  while (true) { ///Getting Query From the User / Query Processor
    string str;
    do {
      cout << "\nPlease enter A query string [enter \"QUIT\" to terminate, STAT for statistics]: " << std::flush;
      std::getline(cin, str);
    } while(str.length() == 0);

    if (str == "QUIT") {
      break;
    }

    if (str == "STAT") { ///Printing out stats
      cout << "\n===============Statistics Begins====================\n";
      int articleNum = dp.docHashes.size();
      int wordsNum = dp.myInvertedIndices.size();
      cout << "Total article numbers: " << articleNum << endl;
      cout << "Total number of unique words indexed: " << wordsNum << endl;
      cout << "Average number of words indexed per article: " << static_cast<double>(wordsNum) / articleNum << endl;
      cout << "Total number of unique Authors( last name only ): " << dp.author2Hashes.size() << endl;
      cout << "\n===============Statistics Ends====================\n";
      continue;
    }

    cout << endl;
    string queryStr = DocumentProcessor::stemmed(str.c_str()); ///Stem the user input

    /*
     * Process Query
     */
    set<string> docSet;///save file list
    set<string> newDocSet;///also used to save file list



    string op("DEFAULT");
    stringstream qss(queryStr);
    string word;
    vector<string> keywords;
    int keyWordIdx = 0;
    bool isValidQuery = true;
    while (qss >> word) {
      if (word == "AND" || word == "OR" || word == "NOT" || word == "AUTHOR") {
        op = word; ///Checking the query word is an operator
      }
      else { ///it is an actual word
        keyWordIdx++;
        toLowerCase(word);
        word = DocumentProcessor::stemmed(word.c_str());
        if (op != "AUTHOR") { ///If it's not an AUTHOR operator
          AVLFindCursor cur = dp.myInvertedIndices.find(word);
          if (cur.isFound) {
            newDocSet = cur.getVal();
          }
          else { ///Catch case if the word is not found
            cout << "\nquery string == \"" << word << "\" NOT FOUND in [[AVL]]\n";
            newDocSet.clear();
          }
        }
        else {///The word is the key word AUTHOR
          if (dp.myAuthor2Hashes.find(word)) {
            newDocSet = *(dp.myAuthor2Hashes.foundVal);
          }
          else {///catch if the author does not exist
            cout << "\nauthor name NOT EXIST!!\n";
            isValidQuery = false;
            break;
          }
        }

        if (op == "DEFAULT") { ///If no special key word
          keywords.push_back(word);
          docSet = newDocSet;
        }
        else if (op == "AUTHOR") { ///if the key word author
          set<string> resultSet;
          std::set_intersection(docSet.begin(), docSet.end(), newDocSet.begin(), newDocSet.end(),
                                std::inserter(resultSet, resultSet.begin()));
          docSet = resultSet;

        }
        else if (op == "AND") { ///If key word AND
          keywords.push_back(word);
          if (keyWordIdx > 1) {
            set<string> resultSet;
            std::set_intersection(docSet.begin(), docSet.end(), newDocSet.begin(), newDocSet.end(),
                                  std::inserter(resultSet, resultSet.begin()));
            docSet = resultSet;

          }
          else {
            docSet = newDocSet;
          }
        }
        else if (op == "OR") { ///If the key word OR
          keywords.push_back(word);
          if (keyWordIdx > 1) {
            set<string> resultSet;
            std::set_union(docSet.begin(), docSet.end(), newDocSet.begin(), newDocSet.end(),
                           std::inserter(resultSet, resultSet.begin()));
            docSet = resultSet;
          }
          else {
            docSet = newDocSet;
          }

        }
        else if (op == "NOT") { ///If the key word NOT
          set<string> resultSet;
          std::set_difference(docSet.begin(), docSet.end(), newDocSet.begin(), newDocSet.end(),
                              std::inserter(resultSet, resultSet.begin()));
          docSet = resultSet;

        }
      }
    }

    if (isValidQuery) {
      do_query(dp, keywords, docSet, "Good Version");
    }
  }
  return 0;
}


string cutOff(string s, int len) { ///used to maintain the length of the title and authors
  if (s.length() <= len) {
    return s;
  }
  else {
    return s.substr(0, len - 3) + "...";
  }
}
