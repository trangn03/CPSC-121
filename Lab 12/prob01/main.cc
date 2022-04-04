#include <iostream>
#include <memory>
#include <string>

// TODO: Include any necessary headers.

#include "cat.h"
#include "human.h"

int main() {
  std::string name1;
  std::string name2;
  std::string cat_name;
  std::cout << "What is the first human's name? ";
  std::cin >> name1;

  std::cout << "What is the second human's name? ";
  std::cin >> name2;

  std::cout << "What is the cat's name? ";
  std::cin >> cat_name;
  std::cout << std::endl;

  // TODO: Use strings name1 and name2 to construct two Human objects and call
  // Human::Print() on both.
  Human n1;
  n1.SetName(name1);
  Human n2;
  n2.SetName(name2);
  n1.Print();
  n2.Print();

  // TODO: Use cat_name and the ``CreateKitty`` function to create a
  // unique pointer to a Cat.
  std::unique_ptr<Cat> a = CreateKitty(cat_name);

  std::cout << "First human is adopting..." << std::endl;
  // TODO: Have the first Human Adopt the cat, then print the first and second
  // Humans.
  n1.Adopt(std::move(a));
  n1.Print();
  n2.Print();

  std::cout << "First human is transferring to second human..." << std::endl;
  // TODO: Have the first Human Transfer their cat to the second Human, then
  // print the first and second Humans.
  n1.TransferTo(&n2);
  n1.Print();
  n2.Print();

  return 0;
}
