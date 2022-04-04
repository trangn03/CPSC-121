#include "human.h"

#include <iostream>
#include <memory>

#include "cat.h"

// TODO: Implement Human methods here.

Human::~Human() { std::cout << name_ << " walks away " << std::endl; }
void Human::SetName(std::string name) { name_ = name; }
std::string Human::GetName() const { return name_; }
void Human::Adopt(std::unique_ptr<Cat> c) { cat = std::move(c); }
void Human::TransferTo(Human* t) { t->Adopt(std::move(cat)); }
void Human::Print() const {
  std::cout << name_;
  if (cat != nullptr) {
    std::cout << " is a human with a cat named " << cat->GetName() << std::endl;
  } else {
    std::cout << " is a human with no cat\n";
  }
}
