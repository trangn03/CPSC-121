#include <iostream>
#include <vector>

#include "recursion.h"

//
// Calls the functions from recursion.h.
// You do NOT need to edit this file.
//
int main() {
  std::string choice;
  while (choice != "quit") {
    std::cout << "Which problem do you want to test? "
              << "(IsEven, SumArray, RaiseIntToPower), or \"quit\": ";
    std::cin >> choice;
    if (choice == "IsEven") {
      int value;
      std::cout << "What number do you want to check for evenness? ";
      std::cin >> value;
      std::cout << "Calculating..." << std::endl;
      bool is_even = IsEven(value);
      std::cout << value << " is " << (is_even ? "even" : "odd") << std::endl;
    } else if (choice == "SumArray") {
      int size;
      std::cout << "What size is your array? ";
      std::cin >> size;
      std::vector<int> array;
      for (int i = 0; i < size; i++) {
        int value;
        std::cout << "Enter an integer: ";
        std::cin >> value;
        array.push_back(value);
      }
      std::cout << "Calculating..." << std::endl;
      // Start index in the array is always 0.
      int sum = SumArray(array, 0);
      std::cout << "The sum is " << sum << std::endl;
    } else if (choice == "RaiseIntToPower") {
      int integer;
      int power;
      std::cout << "What integer do you want to use? ";
      std::cin >> integer;
      std::cout << "To what power do you want to raise " << integer << "? ";
      std::cin >> power;
      std::cout << "Calculating..." << std::endl;
      int result = RaiseIntToPower(integer, power);
      std::cout << "The result is: " << result << std::endl;
    }
  }
  return 0;
}
