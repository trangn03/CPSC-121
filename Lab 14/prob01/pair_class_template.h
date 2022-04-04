#include <iostream>

template <class T>

class MyPair {
 private:
  T value1_;
  T value2_;

 public:
  MyPair(T v1, T v2) {
    value1_ = v1;
    value2_ = v2;
  }
  T GetValue1() { return value1_; }
  T GetValue2() { return value2_; }
  void Display() { std::cout << "[" << value1_ << ", " << value2_ << "]"; }
  void DisplayReverse() {
    std::cout << "[" << value2_ << ", " << value1_ << "]";
  }
  T MaxValue() {
    if (value1_ > value2_) {
      return value1_;
    } else {
      return value2_;
    }
  }
  T MinValue() {
    if (value1_ < value2_) {
      return value1_;
    } else {
      return value2_;
    }
  }
  void SwapValue() {
    T swap = value1_;
    value1_ = value2_;
    value2_ = swap;
  }
};
