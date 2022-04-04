#include <iostream>
// TODO: Include any necessary headers.
#include <vector>

#include "minimum.h"

int main() {
  int size;
  std::cout << "How many elements? ";
  std::cin >> size;

  // TODO: Construct the vector and array.
  std::vector<double> v = {};
  double array[size];

  // TODO: Prompt the user for the value of each element and populate the vector
  // and array.
  for (int i = 0; i < size; i++) {
    double user;
    std::cout << "Element " << i << ": ";
    std::cin >> user;
    v.push_back(user);
    array[i] = user;
  }

  // TODO: Call the IndexOfMin* functions using the vector or array as
  // appropriate, and display the output.

  std::cout << "Minimum index using vector: " << IndexOfMinWithVector(v)
            << "\n";
  std::cout << "Minimum index using array: " << IndexOfMinWithArray(array, size)
            << "\n";
  std::cout << "Minimum index using pointer math: "
            << IndexOfMinWithPointer(&array[0], size) << "\n";
}
