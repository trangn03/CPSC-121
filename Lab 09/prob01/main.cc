#include <iostream>
#include <string>

#include "shapes.h"
int main() {
  int h;
  int w;
  std::cout << "Enter the height: ";
  std::cin >> h;
  std::cout << "Enter the width: ";
  std::cin >> w;
  Rectangle r(w, h);
  Triangle t(w, h);
  Ellipse e(w, h);
  PrintShapeInfo(r);
  PrintShapeInfo(t);
  PrintShapeInfo(e);
}
