///Ultimate Owner: Carson Pittman
///Reference: https://www.cxyxiaowu.com/1663.html   https://www.geeksforgeeks.org/avl-tree-set-1-insertion/   https://www.tutorialspoint.com/cplusplus-program-to-implement-avl-tree


#include "avl.h"
#include "utils.h"
#include <cassert>

AVLFindCursor::AVLFindCursor(bool isFoundIn, AVLNode *parentIn, int chlIdxIn) :
  isFound(isFoundIn), parent(parentIn), chlIdx(chlIdxIn) {}

Val &AVLFindCursor::getVal() {
  return parent->val;
}

AVLFindKey::AVLFindKey(AVLNode *uIn, const Key &keyIn) : u(uIn), key(keyIn) {}

int AVLNode::collect_height_safe(AVLNode *u) {
  if (u == nullptr)
    return -1;

  return u->h;
}

int AVLNode::collect_height() {
  return 1 + std::max(collect_height_safe(chl[0]), collect_height_safe(chl[1]));
}

int AVLNode::get_balance_factor() {
  return collect_height_safe(chl[0]) - collect_height_safe(chl[1]);
}


void AVLNode::update_up() { ///Balancing the tree
  AVLNode* x = this;
  AVLNode* newRoot = nullptr;
  while (x != nullptr) {
    newRoot = x;
    x->update_stat();

    // Check if any rotation is necessary
    int xBf = x->get_balance_factor();
    int yBf;
    int zBf;
    assert(xBf >= -2 && xBf <= 2);
    if (xBf > 1) {
      yBf = x->chl[0]->get_balance_factor();
      if (yBf > 0) {
        assert(yBf == 1 || yBf == 2);
        x->ll_rotate();
      }
      else if (yBf < 0) {
        assert(yBf == -1 || yBf == -2);
        x->lr_rotate();
        x = x->parent;
        // reset heights
        x->chl[0]->update_stat();
        x->chl[1]->update_stat();
      }
      else {
        DEBUG;
        exit(1);
      }
    }
    else if (xBf < -1) {
      zBf = x->chl[1]->get_balance_factor();
      if (zBf > 0) {
        assert(zBf == 1 || zBf == 2);
        x->rl_rotate();
        x = x->parent;
        // reset heights
        x->chl[0]->update_stat();
        x->chl[1]->update_stat();
      }
      else if (zBf < 0) {
        assert(zBf == -1 || zBf == -2);
        x->rr_rotate();
      }
      else {
        DEBUG;
        exit(1);
      }
    }
    else {
      x = x->parent;
    }
  }

  tree.setRoot(newRoot);
}

void AVLNode::ll_rotate() {
  right_rotate();
}

void AVLNode::lr_rotate() {
  chl[0]->left_rotate();
  right_rotate();
}

void AVLNode::rr_rotate() {
  left_rotate();
}

void AVLNode::rl_rotate() {
  chl[1]->right_rotate();
  left_rotate();
}

void AVLNode::right_rotate() {
  AVLNode* p = this;
  AVLNode* q = p->chl[0];
  AVLNode* q1 = q->chl[1];

  if (p->parent != nullptr) {
    p->parent->chl[p->get_chlIdx_wrt_parent()] = q;
  }
  q->parent = p->parent;
  p->parent = q;
  q->chl[1] = p;

  p->chl[0] = q1;
  if (q1 != nullptr) {
    q1->parent = p;
  }
}

void AVLNode::left_rotate() {
  AVLNode* p = this;
  AVLNode* q = p->chl[1];
  AVLNode* q0 = q->chl[0];

  if (p->parent != nullptr) {
    p->parent->chl[p->get_chlIdx_wrt_parent()] = q;
  }
  q->parent = p->parent;
  p->parent = q;
  q->chl[0] = p;

  p->chl[1] = q0;
  if (q0 != nullptr) {
    q0->parent = p;
  }
}

int AVLNode::get_chlIdx_wrt_parent() {
  return parent->chl[0] == this ? 0 : 1;
}

void AVLNode::update_stat() {
  h = collect_height();
  size = collect_size();
}

int AVLNode::collect_size() {
  return 1 + collect_size_safe(chl[0]) + collect_size_safe(chl[1]);
}

int AVLNode::collect_size_safe(AVLNode *u) {
  if (u == nullptr)
    return 0;
  return u->size;
}


void AVLTree::insert(const Key& key, Val val) { ///Inserting a node
  if (root == nullptr) {
    root = new AVLNode(*this, key, val);
    return;
  }

  AVLFindKey findKey(root, key);
  auto cur = find(findKey);
  // If this key has not been stored in AVL yet
  if (!cur.isFound) {
    do_insert(findKey, cur, val);
  }

}

AVLFindCursor AVLTree::find(const Key key) { ///calls the private find cursor
  return find(AVLFindKey(root, key));
}

AVLFindCursor AVLTree::find(const AVLFindKey fk) {
  if (root == nullptr) { ///If the word trying to find does not exist
    return AVLFindCursor(false, nullptr, -1);
  }

  if (fk.key == fk.u->key) { ///If the key looking at is the key
    return AVLFindCursor(true, fk.u, -1); ///To the right child
  }
  else if (fk.key < fk.u->key) {
    if (fk.u->chl[0] == nullptr) {
      return AVLFindCursor(false, fk.u, 0);
    }
    return find(AVLFindKey(fk.u->chl[0], fk.key));///To the left child
  }
  else if (fk.key > fk.u->key) {
    if (fk.u->chl[1] == nullptr) {
      return AVLFindCursor(false, fk.u, 1);
    }
    return find(AVLFindKey(fk.u->chl[1], fk.key));
  }

  // Impossible. Otherwise it must be an error.
  cerr << "find() reaches end!" << endl;
  exit(1);
}

void AVLTree::do_insert(AVLFindKey fk, AVLFindCursor cur, Val val) {
  bind_parent_child(cur.parent, cur.chlIdx, new AVLNode(*this, fk, val)); ///Creates a new node
  cur.parent->update_up();
}

void AVLTree::bind_parent_child(AVLNode *p, int chldIdx, AVLNode *q) { ///Inserting the node to the correct position
  q->parent = p;
  p->chl[chldIdx] = q;
  p->h = p->collect_height();
}

void AVLTree::setRoot(AVLNode *r) {
  root = r;
}

int AVLTree::size() {
  return root->size;
}
