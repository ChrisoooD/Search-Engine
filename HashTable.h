///Ultimate Owner: Christopher Deng
///Reference: https://oi-wiki.org/string/hash/   https://www.cxyxiaowu.com/1663.html   https://aozturk.medium.com/simple-hash-map-hash-table-implementation-in-c-931965904250   https://www.geeksforgeeks.org/c-program-hashing-chaining/

#ifndef SEARCH_ENGINE_HASHTABLE_H
#define SEARCH_ENGINE_HASHTABLE_H

#include <string>
#include <iostream>
#include <vector>
#include <set>

#define SIZE 1000000
#define M 999997
#define B 233

using std::string;
using std::cin;
using std::cerr;
using std::cout;
using std::endl;
using std::set;


typedef string Key; // author name
typedef set<string> Val; // hash set of docs
typedef unsigned long long ll;

class HashBucket { ///Actual storage of authors, similar to the node in AVL tree
public:
  HashBucket(const Key& k, const Val& v);
  Key key;
  Val val;
  HashBucket* next; ///allow the bucket to save multiple authors in one bucket
};

class HashTable {
public:
  HashTable();
  void insert(const Key& key, const Val& val);
  bool find(const Key& key);

  Val* foundVal;
private:
  HashBucket* table[SIZE];
  ll hash(const Key& key); ///hash function created by other people. Reference:  https://oi-wiki.org/string/hash/
};


#endif //SEARCH_ENGINE_HASHTABLE_H
