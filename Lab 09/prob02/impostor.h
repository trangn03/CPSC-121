#include <string>

#include "astronaut.h"
#include "cpputils/graphics/image.h"
#include "crewmate.h"

// These header guards are necessary to keep your class from being defined
// multiple times when it is included from multiple files.
#ifndef IMPOSTOR_H
#define IMPOSTOR_H

// Define your Impostor class here.
class Impostor : public Astronaut {
 public:
  Impostor();
  Impostor(std::string, graphics::Color);
  void Kill(Crewmate& c);
};
#endif  // IMPOSTOR_H
