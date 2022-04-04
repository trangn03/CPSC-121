#include "impostor.h"

#include <iostream>
#include <string>

#include "astronaut.h"
#include "cpputils/graphics/image.h"
#include "crewmate.h"
// Implement the methods in the Impostor class here.
const int a = 59;
const int b = 203;
const int c = 255;
Impostor::Impostor() : Astronaut("Impostor", graphics::Color(a, b, c)) {}
Impostor::Impostor(std::string n, graphics::Color c) : Astronaut(n, c) {}
// Kill function takes a single parameter and reference
// When Kill function called, print imposter's name and who they killed
void Impostor::Kill(Crewmate& c) {
  std::cout << GetName() << " killed " << c.GetName() << "\n";
  // Ensure the Impostor changes Crewmate when Kill is called
  c.SetIsAlive(false);
}
