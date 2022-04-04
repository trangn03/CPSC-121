#include "person.h"

#include <iostream>
#include <string>

Person::Person(std::string name) {
  name_ = name;
  child_ = nullptr;
}
std::string Person::GetName() const { return name_; }
Person* Person::GetChild() const { return child_; }
void Person::SetChild(Person* sc) { child_ = sc; }
void Person::Print() const {
  std::cout << name_;
  if (child_ != nullptr) {
    std::cout << ", parent of ";
    child_->Print();
  } else {
    std::cout << "\n";
  }
}
