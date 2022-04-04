#include "doe.h"

#include <iostream>
#include <string>

Doe::Doe() : Kangaroo{"doe"}, j{"joey"} {}
Doe::Doe(std::string d, std::string e) : Kangaroo{d}, j{e} {}
Joey& Doe::GetJoey() { return j; }
void Doe::Bounce() {
  int value_count = GetBounceCount();
  value_count++;
  std::cout << GetName() << " goes boing.\n";
  SetBounceCount(value_count);
  j.Bounce();
}
