#include "cat.h"

#include <iostream>
#include <memory>
// TODO: Implement Cat methods and CreateKitty function here.

void Cat::SetName(std::string name) { name_ = name; }
std::string Cat::GetName() const { return name_; }
Cat::~Cat() { std::cout << name_ << " stalks away\n"; }
std::unique_ptr<Cat> CreateKitty(std::string k) {
  Cat a;
  a.SetName(k);
  // std::unique_ptr<Cat> c = std::make_unique<Cat>(a);
  // return c;
  return std::move(std::make_unique<Cat>(a));
}
