#include "kangaroo.h"

#include <iostream>
#include <string>

Kangaroo::Kangaroo() { value_name = "kangaroo"; }
Kangaroo::Kangaroo(std::string k) { value_name = k; }
std::string Kangaroo::GetName() { return value_name; }
void Kangaroo::SetName(std::string k) { value_name = k; }
int Kangaroo::GetBounceCount() { return value_count; }
void Kangaroo::SetBounceCount(int c) { value_count = c; }
void Kangaroo::Bounce() {
  // increment bounce count
  value_count++;
  std::cout << value_name << " goes boing.\n";
}
