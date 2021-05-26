///Ultimate Owner: Christopher Deng
///Reference: https://oi-wiki.org/string/hash/   https://www.cxyxiaowu.com/1663.html   https://aozturk.medium.com/simple-hash-map-hash-table-implementation-in-c-931965904250   https://www.geeksforgeeks.org/c-program-hashing-chaining/


#include "HashTable.h"


HashBucket::HashBucket(const Key& k, const Val& v):key(k), val(v), next(nullptr) {}

HashTable::HashTable():foundVal(nullptr) { ///search for a author
  for (int i = 0; i < SIZE; ++i) {
    table[i] = nullptr;
  }
}

void HashTable::insert(const Key &key, const Val &val) { ///inserting a author
  ll h = hash(key);
  HashBucket* newBckt = new HashBucket(key, val);
  if (table[h] == nullptr) {
    table[h] = newBckt;
  }
  else {
    HashBucket* b = table[h];
    while (b->next != nullptr) {
      b = b->next;
    }
    b->next = newBckt;
  };
}


ll HashTable::hash(const Key& key) { ///hash function created by other people. Reference:  https://oi-wiki.org/string/hash/
  ll res = 0;
  for (int i = 0; i < key.length(); ++i) {
    res = (res * B + key[i]) % M;
  }
  return res;
}

bool HashTable::find(const Key &key) { ///Check to see if documents exist
  ll h = hash(key);
  if (table[h] == nullptr) {
    return false;
  }
  HashBucket* p = table[h];
  while (p != nullptr && p->key != key) {
    p = p->next;
  }
  if (p == nullptr) {
    return false;
  }
  foundVal = &(p->val); ///make foundVal the bucket that the has the correct author
  return true;
}
