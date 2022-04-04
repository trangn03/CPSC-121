#include "joey.h"
#include "kangaroo.h"

#ifndef DOE_H
#define DOE_H

// Doe class here.
class Doe : public Kangaroo {
 private:
  Joey j;
  std::string value_name;

 public:
  Doe();
  Doe(std::string a, std::string b);
  Joey& GetJoey();
  void Bounce();
};

#endif  // DOE_H
