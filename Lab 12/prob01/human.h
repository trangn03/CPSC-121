#ifndef HUMAN_H
#define HUMAN_H

// TODO: Place your Human class here.

#include <memory>

#include "cat.h"

class Human {
 private:
  std::string name_;
  std::unique_ptr<Cat> cat = nullptr;

 public:
  ~Human();
  void SetName(std::string name);
  std::string GetName() const;
  void Adopt(std::unique_ptr<Cat> c);
  void TransferTo(Human* t);
  void Print() const;
};
#endif  // HUMAN_H
