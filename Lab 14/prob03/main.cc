#include <iomanip>
#include <iostream>
#include <string>

#include "minmax.h"

int main() {
  int a = 1, b = 10, c = 8, d = 42;
  double w = 3.14, x = 8.25, y = -1.11, z = 13.37;
  std::string cat = "cat", dog = "dog", abc = "abc", xyz = "xyz";
  std::cout << "The max of 1 and 10 is: " << Maximum(a, b) << "\n";
  std::cout << "The min of 8 and 42 is: " << Minimum(c, d) << "\n";
  std::cout << "The max of 3.14 and 8.25 is: " << std::fixed
            << std::setprecision(2) << Maximum(w, x) << "\n";
  std::cout << "The min of -1.11 and 13.37 is: " << Minimum(y, z) << "\n";
  std::cout << "The max of \"cat\" and \"dog\" is: " << Maximum(cat, dog)
            << "\n";
  std::cout << "The min of \"abc\" and \"xyz\" is: " << Minimum(abc, xyz)
            << "\n";
  return 0;
}
