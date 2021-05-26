///Ultimate Owner: Carson Pittman
///Reference: https://www.cxyxiaowu.com/1663.html   https://www.geeksforgeeks.org/avl-tree-set-1-insertion/   https://www.tutorialspoint.com/cplusplus-program-to-implement-avl-tree

#ifndef SEARCH_ENGINE_AVL_H
#define SEARCH_ENGINE_AVL_H

#include <string>
#include <iostream>
#include <vector>
#include <set>

using std::string;
using std::cin;
using std::cerr;
using std::cout;
using std::endl;
using std::vector;
using std::set;

typedef string Key; ///word
typedef set<string> Val; ///document id

class AVLNode;
class AVLTree;

class AVLFindCursor {
public:
  // member functions
  AVLFindCursor(bool isFoundIn, AVLNode* parentIn, int chlIdxIn); ///keeps a reference to the place for the key
  AVLFindCursor() {}
  Val& getVal();

  // member variables
  bool isFound;
  AVLNode* parent;
  int chlIdx;
};

class AVLFindKey {
public:
  AVLFindKey(AVLNode* uIn, const Key& keyIn); ///Used to search the key
  AVLNode* u{};
  const Key&key;
};

class AVLNode {
public:
  AVLNode(AVLTree& t): h(0), size(1), tree(t), parent(nullptr), chl{nullptr, nullptr} {}
  AVLNode(AVLTree& t, const Key& k, const Val& v): h(0), size(1), tree(t), parent(nullptr), chl{nullptr, nullptr}, key(k), val(v) {}
  AVLNode(AVLTree& t, const AVLFindKey& fk, const Val& val): h(0), size(1), tree(t), parent(nullptr), chl{nullptr, nullptr}, key(fk.key), val(val) {}

  int collect_height_safe(AVLNode* u);
  int collect_height();

  int h, size;

  // chl[0] is for the left child
  // chl[1] is for the right child

  AVLTree& tree;
  AVLNode* parent;
  AVLNode* chl[2];
  Key key;
  Val val;


  void update_up(); ///Balancing the tree

  int get_balance_factor();

  void ll_rotate();

  void right_rotate();

  int get_chlIdx_wrt_parent();

  void lr_rotate();

  void left_rotate();

  void rl_rotate();

  void rr_rotate();

  void update_stat();

  int collect_size();

  int collect_size_safe(AVLNode *u);
};

class AVLTree {
public:

  AVLTree():root(nullptr) {}
  void insert(const Key& key, Val val);///insert function for new word

  void setRoot(AVLNode *r);
  AVLFindCursor find(const Key key); ///allow the user to find a specific keyword

  int size();

private:
  void bind_parent_child(AVLNode *p, int chldIdx, AVLNode *q); ///Inserting the node to the correct position
  AVLFindCursor find(const AVLFindKey fk);///called public find cursor

  AVLNode* root;

  void do_insert(AVLFindKey fk, AVLFindCursor cur, Val val); ///called by public insert
};

#endif //SEARCH_ENGINE_AVL_H
