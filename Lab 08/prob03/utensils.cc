#include "utensils.h"

#include <iomanip>
#include <iostream>

void Food::eat(double bite) {
  if (bite < mass_) {
    mass_ -= bite;
  } else {
    mass_ = 0;
  }
}

void Food::print() { std::cout << name_ << " " << mass_ << "g\n"; }
