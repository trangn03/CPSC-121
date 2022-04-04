#include "button.h"

#include <iostream>
#include <string>

#include "rect.h"

Button::Button() : value_name{"button"}, Rect{0, 0, 0, 0} {}
Button::Button(std::string b, Rect rec) : value_name{b}, Rect{rec} {}
bool Button::GetActive() { return value_active; }
void Button::SetActive(bool s) { this->value_active = s; }
Rect Button::GetRect() { return Rect(GetX(), GetY(), GetWidth(), GetHeight()); }
std::string Button::GetName() { return value_name; }
void Button::Click() {
  std::cout << "Clicked " << value_name;  // or GetName()
}
