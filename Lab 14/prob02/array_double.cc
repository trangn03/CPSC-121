#include "array_double.h"

#include <iomanip>
#include <iostream>

// TODO(labex): Implement the ArrayDouble class' nondefault constructor
ArrayDouble::ArrayDouble(int num) {
  array_ = nullptr;
  num_ = 0;
  if (num < 0) {
    throw InvalidArrayLengthException(num);
  } else {
    num_ = num;
    array_ = new double[num_];
    for (int i = 0; i < num_; i++) {
      array_[i] = 0;
    }
  }
}
// TODO(labex): Impelment the ArrayDouble class' destructor
ArrayDouble::~ArrayDouble() { delete[] array_; }

// TODO(labex): Implement the ArrayDouble class' operator[] member function
//              (operator overloading)
double& ArrayDouble::operator[](int ix) const {
  if (ix >= num_) {
    throw IndexOutOfRangeException(ix, num_);
  } else if (ix < 0) {
    throw IndexOutOfRangeException(ix, num_);
  } else {
    return array_[ix];
  }
}

// TODO(labex): Implement the ArrayDouble class' Display() member function
void ArrayDouble::Display() const {
  if (num_ == 0) {
    std::cout << "Array is empty.";
  } else {
    std::cout << "Array contents: ";
    for (int i = 0; i < num_; i++) {
      std::cout << std::fixed << std::setprecision(2);
      std::cout << array_[i] << " ";
    }
  }
}
