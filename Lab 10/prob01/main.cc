#include <iostream>

#include "pointer_utils.h"

int main() {
  std::string choice;
  while (choice != "quit") {
    std::cout << "Which problem number do you want to test? (or \"quit\")\n"
              << "1. Negate\n2. Increment\n3. ComputeSum\n4. Swap\n5. "
                 "MakeSus\n6. GetLongestString\n: ";
    std::cin >> choice;
    if (choice == "1") {
      std::string bool_str;
      std::cout << "enter \"true\" or \"false\": ";
      std::cin >> bool_str;
      bool value = bool_str == "true";
      std::cout << "calling Negate... " << std::endl;

      Negate(&value);

      std::cout << "value is now " << (value ? "true" : "false") << std::endl;

    } else if (choice == "2") {
      int number;
      std::cout << "enter a number to increment: ";
      std::cin >> number;
      std::cout << "calling Increment... " << std::endl;

      Increment(&number);

      std::cout << "the incremented number is " << number << std::endl;
    } else if (choice == "3") {
      double first;
      double second;
      std::cout << "enter a floating point number: ";
      std::cin >> first;
      std::cout << "enter another: ";
      std::cin >> second;
      std::cout << "calling ComputeSum..." << std::endl;

      double sum = ComputeSum(&first, &second);
      std::cout << "the sum is " << sum << std::endl;
    } else if (choice == "4") {
      int first;
      int second;
      std::cout << "enter the first number: ";
      std::cin >> first;
      std::cout << "enter the second number: ";
      std::cin >> second;
      std::cout << "calling Swap..." << std::endl;

      Swap(&first, &second);

      std::cout << "first: " << first << ", second: " << second << std::endl;
    } else if (choice == "5") {
      std::string name;
      std::cout << "What is your AmongUs name? (no spaces): ";
      std::cin >> name;
      std::cout << "calling MakeSus..." << std::endl;

      MakeSus(&name);

      std::cout << name << std::endl;
    } else if (choice == "6") {
      int count;
      std::cout << "How many strings? ";
      std::cin >> count;
      std::vector<std::string> strings;
      for (int i = 0; i < count; i++) {
        std::string str;
        std::cout << "enter a string (no spaces): ";
        std::cin >> str;
        strings.push_back(str);
      }

      std::string* longest = GetLongestString(&strings);

      if (longest != nullptr) {
        std::cout << "the longest is " << *longest << std::endl;
      } else {
        std::cout << "nullptr: there was no longest string" << std::endl;
      }
    } else if (choice != "quit") {
      std::cout << "I didn't understand" << std::endl;
    }
    std::cout << std::endl;
  }
  return 0;
}
