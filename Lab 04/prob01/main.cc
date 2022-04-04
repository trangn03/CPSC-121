#include <bits/stdc++.h>
#include <stdlib.h>

#include <iostream>
#include <string>

#include "cpputils/graphics/image.h"

int HexToInteger(std::string hex) {
  // Only works on strings length 2.
  if (hex.size() != 2) {
    return -1;
  }
  // Convert hex string, base 16 string, to integer.
  const int kBaseSixteen = 16;
  return strtoul(hex.c_str(), nullptr, kBaseSixteen);
}

int main() {
  // Input hex code
  std::string hex_code;
  std::cout << "Enter a hex code: ";
  std::cin >> hex_code;
  // Get the color into 2 string
  std::string r = hex_code.substr(0, 2);
  std::string g = hex_code.substr(2, 2);
  std::string b = hex_code.substr(4, 2);
  // Convert to integer and create color object
  int red = HexToInteger(r);
  int green = HexToInteger(g);
  int blue = HexToInteger(b);
  graphics::Color color(red, green, blue);
  // Creat and save image
  graphics::Image image(50, 50);
  const int size = 500;
  image.DrawRectangle(0, 0, size, size, color);
  image.SaveImageBmp(hex_code + ".bmp");
  // Output
  std::cout << "Color swatch saved to " << hex_code << ".bmp" << std::endl;
  return 0;
}
