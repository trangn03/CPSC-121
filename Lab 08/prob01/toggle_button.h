#ifndef TOGGLE_BUTTON_H
#define TOGGLE_BUTTON_H

#include <string>

#include "button.h"
#include "rect.h"

// ToggleButton class here.
class ToggleButton : public Button {
 private:
  std::string value_name;
  bool value_track = false;

 public:
  ToggleButton();
  ToggleButton(std::string, Rect);
  bool GetEnabled();
  void Click();
};

#endif  // TOGGLE_BUTTON_H
