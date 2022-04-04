#include <iostream>

template <class T>

T Maximum(T value1, T value2) {
  if (value1 > value2) {
    return value1;
  } else {
    return value2;
  }
}

template <class T>

T Minimum(T value1, T value2) {
  if (value1 < value2) {
    return value1;
  } else {
    return value2;
  }
}
