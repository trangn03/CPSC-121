#include <iostream>
#include <string>

#include "person.h"

int main() {
  std::string great_grandparent;
  std::string grandparent;
  std::string parent;
  std::string kid;

  std::cout << "What is the great-grandparent's name? ";
  std::cin >> great_grandparent;
  Person Great_Grandparent = Person(great_grandparent);
  std::cout << "What is the grandparent's name? ";
  std::cin >> grandparent;
  Person Grand_Parent = Person(grandparent);
  std::cout << "What is the parent's name? ";
  std::cin >> parent;
  Person Parent = Person(parent);
  std::cout << "What is the kid's name? ";
  std::cin >> kid;
  Person Kid = Person(kid);

  Great_Grandparent.SetChild(&Grand_Parent);
  Grand_Parent.SetChild(&Parent);
  Parent.SetChild(&Kid);

  std::cout << "The family tree is: \n";

  Great_Grandparent.Print();
}
