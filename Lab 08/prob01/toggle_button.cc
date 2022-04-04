#include "toggle_button.h"

#include <iostream>
#include <string>

#include "button.h"
#include "rect.h"

ToggleButton::ToggleButton() : Button{"toggle", Rect(0, 0, 0, 0)} {}
ToggleButton::ToggleButton(std::string t, Rect rec) : Button{t, rec} {}
bool ToggleButton::GetEnabled() {
  if (value_track) {
    return true;
  } else {
    return false;
  }
}
void ToggleButton::Click() {
  if (GetEnabled() == false) {
    std::cout << "Clicked " << GetName() << " "
              << "(enabled)\n";
    value_track = true;
  } else if (GetEnabled() == true) {
    std::cout << "Clicked " << GetName() << " "
              << "(disabled)\n";
    value_track = false;
  }
}
