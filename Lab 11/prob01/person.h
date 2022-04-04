#include <string>

#ifndef PERSON_H
#define PERSON_H

class Person {
 private:
  std::string name_;
  Person* child_ = nullptr;

 public:
  Person(std::string name);
  std::string GetName() const;
  Person* GetChild() const;
  void SetChild(Person* cp);
  void Print() const;
};
#endif  // PERSON_H
