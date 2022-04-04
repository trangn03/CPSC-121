#include <string>

#include "cpputils/graphics/image.h"

// These header guards are necessary to keep your class from being defined
// multiple times when it is included from multiple files.
#ifndef ASTRONAUT_H
#define ASTRONAUT_H

// Define your Astronaut class here.
class Astronaut {
 private:
  std::string name_;
  graphics::Color color_;

 public:
  Astronaut(std::string, graphics::Color);
  std::string GetName() const;
  virtual graphics::Color GetColor() const;
  virtual std::string GetIconFilename() const;
};
#endif  // ASTRONAUT_H
