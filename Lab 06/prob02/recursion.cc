#include "recursion.h"

// function to check if given value is even
bool IsEven(int value) {
  // there are two base cases
  //
  // if value is 0, return true (since 0 is even)
  if (value == 0) {
    return true;
  }
  // if value is 1, return false (since 1 is odd)
  else if (value == 1) {
    return false;
  }
  // recursive case
  // Call the IsEven function on (value - 2)
  else {
    return IsEven(value - 2);
  }
}

// function to raise a value to given power
int RaiseIntToPower(int value, int power) {
  // if power is 0, return 1
  if (power == 0) {
    return 1;
  }
  // recursive case
  else {
    return value * RaiseIntToPower(value, power - 1);
  }
}

// function to sum the integers in an array
int SumArray(const std::vector<int> array, int start_index) {
  // if start_index is last index of the array, return the last element
  if (start_index >= (int)array.size()) {
    return 0;
  }
  // otherwise , return sum of current element and all the elements after it
  else {
    return SumArray(array, start_index + 1) + array[start_index];
  }
}
