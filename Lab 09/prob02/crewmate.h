#include <string>

#include "astronaut.h"
#include "cpputils/graphics/image.h"
// These header guards are necessary to keep your class from being defined
// multiple times when it is included from multiple files.
#ifndef CREWMATE_H
#define CREWMATE_H

// Define your crewmate class here.
class Crewmate : public Astronaut {
 private:
  bool alive_ = true;
  int count_ = 0;

 public:
  Crewmate();
  Crewmate(std::string, graphics::Color);
  graphics::Color GetColor() const override;
  std::string GetIconFilename() const override;
  bool GetIsAlive() const;
  void SetIsAlive(bool);
  int GetTaskCount() const;
  void DoTask(std::string);
};
#endif  // CREWMATE_H
