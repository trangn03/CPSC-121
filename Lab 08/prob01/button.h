#ifndef BUTTON_H
#define BUTTON_H

#include <string>

#include "rect.h"

// Button class here
class Button : public Rect {
 private:
  bool value_active = false;
  std::string value_name;

 public:
  Button();
  Button(std::string, Rect);
  bool GetActive();
  void SetActive(bool);
  Rect GetRect();
  std::string GetName();
  void Click();
};

#endif  // BUTTON_H
