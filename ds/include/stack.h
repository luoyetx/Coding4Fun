#pragma once

#include "./base.h"
#include "./list.h"

namespace ds {

template<typename T>
class Stack {
public:
  Stack() {}

  void Push(T &val);
  void Pop();
  T *Top();
  bool Empty() const;
  size_t Size() const;

private:
  size_t size_;
  List<T> data_;
};

template<typename T>
inline void Stack<T>::Push(T &val) {

}

template<typename T>
inline void Stack<T>::Pop() {
  if (!Empty()) {
    size_--;
  }
}

template<typename T>
typename T *Stack<T>::Top() {
  if (!Empty()) {
    return &data_[Size() - 1];
  }
  else {
    return nullptr;
  }
}

template<typename T>
inline bool Stack<T>::Empty() const {
  return Size() == 0;
}

template<typename T>
inline size_t Stack<T>::Size() const {
  return size_;
}

}  // namespace ds
