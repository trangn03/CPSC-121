#include <iostream>
#include <vector>

#include "linear_search.h"

int main() {
  std::vector<int> my_vector{3, 16, 22, 8, 11, 0, 55, 34, 27, 31};
  int choice;
  std::cout << "Vector: ";
  for (int i = 0; i < 10; i++) {
    std::cout << my_vector[i] << " ";
  }
  std::cout << "\n";
  std::cout << "Please enter a number you want to search for: ";
  std::cin >> choice;
  int index;

  // Provide code that calls the linear_search function to find the number that
  // the user provided. Return the index of the value in the vector
  // or -1 if it is not in the vector. Store the value in the variable named
  // index, so that the code below works!

  if (index == -1) {
    std::cout << choice << " is not in the vector"
              << "\n";
  } else {
    std::cout << "The index of " << choice << " in the vector is: " << index
              << "\n";
  }
  return 0;
}
