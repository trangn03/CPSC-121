#include <iostream>

#include "pogil.h"

int main() {
  std::string name1;
  std::string name2;
  std::string name3;
  std::string name4;
  int grade1;
  int grade2;
  int grade3;
  int grade4;

  std::cout << "Enter the Manager's name: ";
  std::cin >> name1;
  std::cout << "Enter the Manager's current points: ";
  std::cin >> grade1;

  std::cout << "Enter the Presenter's name: ";
  std::cin >> name2;
  std::cout << "Enter the Manager's current points: ";
  std::cin >> grade2;

  std::cout << "Enter the Recorder's name: ";
  std::cin >> name3;
  std::cout << "Enter the Recorder's current points: ";
  std::cin >> grade3;

  std::cout << "Enter the Reflector's name: ";
  std::cin >> name4;
  std::cout << "Enter the Reflector's current points: ";
  std::cin >> grade4;

  int grade;
  std::cout << "How many points do you give this group? (between 0 and 10): ";
  std::cin >> grade;
  std::cout << std::endl;

  // TODO: Create Student objects from the names and grades above.
  // TODO: Create a PogilGroup object using the addresses of the Students.
  // TODO: Set the PogilGroup's grade with the grade variable from above.
  // TODO: Call PrintGroupInformation using the address of the PogilGroup.

  return 0;
}
