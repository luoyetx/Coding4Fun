#pragma

#include "./base.h"
#include <vector>
#include <random>
#include <algorithm>
#include <ostream>

namespace ds {

template<typename KeyType, typename ValType>
class SkipList {
private:
  struct Node {
    KeyType key;
    ValType value;
    std::vector<Node*> forward;
  };
  static const int kMaxLevel = 32;
  using NodeType = Node*;

  NodeType head_;
  int level_;
  int length_;

public:
  SkipList() {
    level_ = 1;
    length_ = 0;
    static KeyType key;
    static ValType val;
    head_ = NewNode(key, val, kMaxLevel);
  }

  int Length() { return length_; }

  bool Search(KeyType key, ValType &val) {
    NodeType x = head_;
    for (int i = level_ - 1; i >= 0; i--) {
      while (x->forward[i] && x->forward[i]->key < key) {
        x = x->forward[i];
      }
    }
    x = x->forward[0];
    if (x && x->key == key) {
      val = x->value;
      return true;
    }
    return false;
  }

  bool Insert(KeyType key, const ValType &val) {
    NodeType update[kMaxLevel];
    // find every level path
    NodeType x = head_;
    for (int i = level_ - 1; i >= 0; i--) {
      while (x->forward[i] && x->forward[i]->key < key) {
        x = x->forward[i];
      }
      update[i] = x;
    }
    // check dup
    x = x->forward[0];
    if (x && x->key == key) {
      x->value = val;
      return false;
    }
    // create node
    int node_level = RandomLevel();
    x = NewNode(key, val, node_level);
    // update skiplist level and node list to update forward
    if (node_level > level_) {
      for (int i = level_; i < node_level; i++) {
        update[i] = head_;
      }
      level_ = node_level;
    }
    // update
    for (int i = 0; i < node_level; i++) {
      x->forward[i] = update[i]->forward[i];
      update[i]->forward[i] = x;
    }
    length_++;
    return true;
  }

  bool Delete(KeyType key) {
    NodeType update[kMaxLevel];
    NodeType x = head_;
    for (int i = level_ - 1; i >= 0; i--) {
      while (x->forward[i] && x->forward[i]->key < key) {
        x = x->forward[i];
      }
      update[i] = x;
    }
    x = x->forward[0];
    if (x && x->key == key) {
      // find it
      int nodel_level = x->forward.size();
      for (int i = 0; i < nodel_level; i++) {
        update[i]->forward[i] = x->forward[i];
      }
      DeleteNode(x);
      length_--;
      // downlevel
      while (level_ > 1 && head_->forward[level_ - 1] == nullptr) {
        level_--;
      }
      return true;
    }
    else {
      // not find it
      return false;
    }
  }

  void Print(std::ostream &os) {
    for (int i = level_ - 1; i >= 0; i--) {
      NodeType x = head_->forward[i];
      os << "Level " << i << std::endl;
      os << "(NULL, NULL)";
      while (x) {
        os << " --> (" << x->key << ", " << x->value << ")";
        x = x->forward[i];
      }
      os << " --> (NULL, NULL)" << std::endl;
    }
    os << std::endl;
  }

private:
  static NodeType NewNode(KeyType key, const ValType &val, int level) {
    NodeType node = new Node;
    node->key = key;
    node->value = val;
    node->forward = std::vector<NodeType>(level, nullptr);
    return node;
  }
  static void DeleteNode(NodeType node) {
    delete node;
  }
  // return [1, kMaxLevel]
  static int RandomLevel() {
    int level = 1;
    while ((rand()&0xFFFF) < (0.25*0xFFFF)) {
      level++;
    }
    return std::min(level, kMaxLevel);
  }
};

void TestSkipList();

}  // namespace ds
