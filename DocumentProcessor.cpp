#include "DocumentProcessor.h"

set<char> DocumentProcessor::delimiters {' ', '-', '\0'};
set<char> DocumentProcessor::nonWordChars {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', '(', ')',
'<', '>', '+', '-', '*', '/', '=', ',', '.', '?', '`', '"', '\'', '[', ']', '{', '}' };
set<char> DocumentProcessor::wordTrailingChars {',', '.', ':'};
set<string> DocumentProcessor::stopWords {};
const char*  DocumentProcessor::kTypeNames[] { "Null", "False", "True", "Object", "Array", "String", "Number" };
string DocumentProcessor::docSuffix {".json"};
std::wstring DocumentProcessor::wWord {};
stemming::english_stem<> DocumentProcessor::StemEnglish;

DocumentProcessor::DocumentProcessor(string folder): docsFolderPath(folder) {
  /*
   * Handle Stop Words
   */
  {
    auto stopWordFilePath(docsFolderPath+"stopwords.txt");
    ifstream stopWordIfs(stopWordFilePath);
    string line;
    while (std::getline(stopWordIfs, line)) {
      stopWords.insert(stemmed(line.c_str()));
    }
  }

    ///Reference: https://stackoverflow.com/questions/31659867/how-to-read-data-from-all-files-in-a-directory-using-c-language
  DIR* dir;
  struct dirent *entry;
  if ((dir = opendir(docsFolderPath.c_str())) != nullptr) {
    int docNum = 0;
    int keyWordCnt4ThisDoc;
    while ((entry = readdir (dir)) != nullptr) {
      std::string fileName(entry->d_name);
      if (fileName.size() > 5 && fileName.substr(fileName.size()-4, 4) == "json") { ///checking if its a valid file name
        /*
         * indeed a valid document in json format
         */
        string docHash = fileName.substr(0, fileName.size()-5);
        docHashes.push_back(docHash);
        string fullPath = docsFolderPath + fileName;
        FILE* fp = fopen(fullPath.c_str(), "r");
        fseek(fp, 0, SEEK_END);
        int size = ftell(fp);
        rewind(fp);
        char* jsonStrBuf = new char[size+1];
        fread(jsonStrBuf, size, 1, fp);
        jsonStrBuf[size] = '\0';

          ///Using rapid json to parse the documents
        Document d;
        d.Parse(jsonStrBuf);
        keyWordCnt4ThisDoc = 0;

        delete[] jsonStrBuf;

        MyDocument myDoc;
        myDoc.title = d["metadata"].GetObject().FindMember("title")->value.GetString();
        auto authorsArr = d["metadata"].GetObject().FindMember("authors")->value.GetArray();
        for (auto aItr = authorsArr.Begin(); aItr != authorsArr.End(); ++aItr) {
            string lastName = aItr->GetObject().FindMember("last")->value.GetString();
          myDoc.authors.push_back(lastName);

          toLowerCase(lastName);
            ///Inserting author into hash table
          if (!myAuthor2Hashes.find(lastName)) {
            set<string> docHashes;
            docHashes.insert(docHash);
            myAuthor2Hashes.insert(lastName, docHashes);
          } else {
            myAuthor2Hashes.foundVal->insert(docHash);
          }

          auto a2hItr = author2Hashes.find(lastName);
          if (a2hItr == author2Hashes.end()) {
            set<string> docHashes;
            docHashes.insert(docHash);
            author2Hashes.insert(make_pair(lastName, docHashes));
          }
          else {
            a2hItr->second.insert(docHash);
          }

        }

          ///parse each word in body text
        auto bodyTextArr = d["body_text"].GetArray();
        char thisWord[100];
        for (auto itr = bodyTextArr.Begin(); itr != bodyTextArr.End(); ++itr) {
          auto text = itr->FindMember("text");
          auto str = text->value.GetString();
          myDoc.body += str;
          auto strLen = text->value.GetStringLength();

//          cout << "-----------Original---------------" << endl;
//          cout << str << endl;
//          cout << "-----------Original---------------" << endl;

//          cout << "-----------Stemmed---------------" << endl;
          int wordLen = 0;
          bool isWord = true;
          char ch;
//    str = "NimbleS-can™";
//    strLen = strlen(str);
          for (int i = 0; i <= strLen; ++i) {
            ch = str[i];
            if (!isDelimiter(ch)) {

              if (!isWordTrailingChars(ch)) { ///check if its a valid word / getting rid of trailing characters
                thisWord[wordLen++] = ch;
              }

              isWord = isWord && !isNotWordChar(ch);
            }
            else {
              thisWord[wordLen] = '\0';
              string keyWord = stemmed(thisWord); ///stem the word
              toLowerCase(keyWord);
              //...

              if (isWord && isNotStopWord(keyWord)) {
//                cout << keyWord << ' ';
                // Indeed a valid keyword just generated
                auto wordNumItr = word2Num.find(keyWord);
                if (wordNumItr == word2Num.end()) {
                  word2Num.insert(make_pair(keyWord, 0));
                }
                else {
                  word2Num.find(keyWord)->second += 1;
                }

                keyWordCnt4ThisDoc++;

                auto keywordDocPair = make_pair(keyWord, docHash);
                auto freqItr = wordDocFreqs.find(keywordDocPair);
                if (freqItr == wordDocFreqs.end()) { ///calculates frequency of this word in the document
//                  cout << docHash << endl;

                  Frequency freq(1, docHash);
                  wordDocFreqs.insert(make_pair(keywordDocPair, freq));
                }
                else {
                  wordDocFreqs.find(keywordDocPair)->second.numerator += 1;
                }

                AVLFindCursor cur = myInvertedIndices.find(keyWord); ///search if the word is already there
                if (!cur.isFound) {
                  set<string> docSet;
                  docSet.insert(docHash);
                  myInvertedIndices.insert(keyWord, docSet);///add if not there
                }
                else {
                  cur.parent->val.insert(docHash);///else just add the document id
                }
//          cout << thisWord << ' ';
//        std::wcout << word.c_str() << endl;
              }

              wordLen = 0;
              isWord = true;
            }
          }
//          cout << endl;
//          cout << "-----------Stemmed---------------" << endl;
        }
        myDoc.totalKeywords = keyWordCnt4ThisDoc;///update the total keywords for specific doc
        hash2Doc.insert(make_pair(docHash, myDoc));///add document to the map
        if (docNum == 269) {
          cout << endl;
        }
        cout << "========= docNum == " << ++docNum << " DONE! =============\n";
      }
    }
    cout << "Total Keyword Num == " << invertedIndices.size() << endl;
    closedir (dir);
  } else {
    std::string msg("Dir Open FAILED!");
    cout << msg << endl;
    exit(-1);
  }
}

bool DocumentProcessor::isWordTrailingChars(char ch) {
  return wordTrailingChars.find(ch) != wordTrailingChars.end();
}

bool DocumentProcessor::isNotWordChar(char ch) {
  return nonWordChars.find(ch) != nonWordChars.end();
}

bool DocumentProcessor::isDelimiter(char ch) {
  return delimiters.find(ch) != delimiters.end();
}

bool DocumentProcessor::isNotStopWord(string w) {
  return w.size() > 0 && stopWords.find(w) == stopWords.end();
}

string DocumentProcessor::stemmed(const char *_strIn) {
  char strIn[MAX_WORD_LEN];
  strcpy(strIn, _strIn);
  wchar_t UnicodeTextBuffer[MAX_WORD_LEN];
  std::wmemset(UnicodeTextBuffer, 0, MAX_WORD_LEN);
  std::mbstowcs(UnicodeTextBuffer, strIn, MAX_WORD_LEN);
  wWord = UnicodeTextBuffer;
  StemEnglish(wWord);
  wcstombs(strIn, wWord.c_str(), 100);
  return string(strIn);
}

multimap<int, string> DocumentProcessor::getWordsInCorpusByFreqDesc() {
  return flip_map(word2Num);
}

double DocumentProcessor::getFreq(const Frequency f, const string hash) {
  //cout << f.hash.size()  << endl;
  return static_cast<double>(f.numerator) / static_cast<double>(hash2Doc.find(hash)->second.totalKeywords);
}


Frequency::Frequency(int n, string h):numerator(n), hash(h) {}

MyDocument::MyDocument() {

}
