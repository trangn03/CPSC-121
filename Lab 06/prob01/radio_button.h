#include <iostream>
#include <vector>

#ifndef RADIO_BUTTON_H
#define RADIO_BUTTON_H

// prototype of RadioButton class
class RadioButton {
  // private member variables
 private:
  bool selected;
  std::string text;

  // public method prototypes
 public:
  RadioButton();

  // getters
  std::string GetText() const;
  bool IsSelected() const;

  // setters
  void SetText(std::string p_text);
  void SetSelected(bool p_selected);
};
// vector is passed by reference in SelectRadioButtonMethod because its state
// will be changed inside function
void SelectRadioButton(std::vector<RadioButton> &v, int idx);

void PrintRadioButtons(const std::vector<RadioButton> v);
#endif
