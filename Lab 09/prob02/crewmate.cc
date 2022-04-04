#include "crewmate.h"

#include <iostream>
#include <string>

#include "astronaut.h"
#include "cpputils/graphics/image.h"

// Implement the methods in the Crewmate class here.
const int a = 235;
const int b = 52;
Crewmate::Crewmate() : Astronaut("Crewmate", graphics::Color(a, b, b)) {}
Crewmate::Crewmate(std::string n, graphics::Color c) : Astronaut(n, c) {}
bool Crewmate::GetIsAlive() const { return alive_; }
void Crewmate::SetIsAlive(bool a) { alive_ = a; }
int Crewmate::GetTaskCount() const { return count_; }
// Increment its member variable for task count
void Crewmate::DoTask(std::string t) {
  count_++;
  std::cout << GetName() << " is doing " << t << "\n";
}
// Override GetColor and GetIconFilename from Astronaut
graphics::Color Crewmate::GetColor() const {
  const int a = 256;
  if (alive_ == false) {
    graphics::Color shifted((Astronaut::GetColor().Red() + a) / 2,
                            (Astronaut::GetColor().Green() + a) / 2,
                            (Astronaut::GetColor().Blue() + a) / 2);
    return shifted;
  } else {
    return Astronaut::GetColor();
  }
}
// Crewmate is dead
std::string Crewmate::GetIconFilename() const {
  if (alive_ == true) {
    return Astronaut::GetIconFilename();
  } else {
    return "ghost.bmp";
  }
}
