#include "astronaut.h"

#include <string>

#include "cpputils/graphics/image.h"
// Implement the methods in the Astronaut class here.

Astronaut::Astronaut(std::string n, graphics::Color c) {
  name_ = n;
  color_ = c;
}
std::string Astronaut::GetName() const { return name_; }
graphics::Color Astronaut::GetColor() const { return color_; }
// Get the file name of Astronaut
std::string Astronaut::GetIconFilename() const { return "astronaut.bmp"; }
