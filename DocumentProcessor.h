///Ultimate Owner: Carson Pittman

#ifndef SEARCH_ENGINE_DOCUMENTPROCESSOR_H
#define SEARCH_ENGINE_DOCUMENTPROCESSOR_H

#include <fstream>
#include <iostream>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/prettywriter.h"
#include "olestem/stemming/english_stem.h"
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <dirent.h>

#include "avl.h"
#include "utils.h"
#include "HashTable.h"

using namespace rapidjson;
using std::set;
using std::map;
using std::vector;
using std::wcout;
using std::make_pair;
using std::ifstream;
using std::pair;
using std::multimap;

#define MAX_WORD_LEN 101

class MyDocument {
public:
  MyDocument();
  string title, body;
  vector<string> authors;
  int totalKeywords;
};

class Frequency {
public:
  Frequency(int n, string h);

  int numerator; ///Number of times the word appeared
  const string hash; ///the word
};

class DocumentProcessor {
public:
  DocumentProcessor(string folder);

  static string stemmed(const char *_strIn);

  static const char* kTypeNames[];
  static set<char> delimiters;
  static set<char> nonWordChars;
  static set<char> wordTrailingChars;
  static set<string> stopWords;
  static string docSuffix;
  static std::wstring wWord;
  static stemming::english_stem<> StemEnglish;

  string docsFolderPath;
  map<pair<string, string>, Frequency> wordDocFreqs;
  map<string, int> word2Num; ///keeps track of how many times one key word show up in the index
  vector<string> docHashes; ///saves the document id
  map<string, MyDocument > hash2Doc;
  map<string, set<string> > invertedIndices;
  AVLTree myInvertedIndices;
  map<string, set<string> > author2Hashes;
  HashTable myAuthor2Hashes;

  multimap<int, string> getWordsInCorpusByFreqDesc(); ///stores number of times a word shows up in the whole corpus/index

  double getFreq(const Frequency f, const string hash); ///calculate frequency of a word in the document
private:
  bool isDelimiter(char ch); ///Check if it's delimiter

  bool isNotWordChar(char ch); ///Check if it's not a char

  bool isWordTrailingChars(char ch); ///check if the worlds has trailing chars

  bool isNotStopWord(string w);///If it is not stop word


};

#endif //SEARCH_ENGINE_DOCUMENTPROCESSOR_H
