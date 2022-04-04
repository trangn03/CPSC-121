#include "radio_button.h"

#include <iostream>
#include <vector>

// constructor
RadioButton::RadioButton() {
  selected = false;
  text = "";
}

// getters' implementation
std::string RadioButton::GetText() const { return text; }

bool RadioButton::IsSelected() const { return selected; }

// setters' implementation.
void RadioButton::SetText(std::string p_text) { text = p_text; }

void RadioButton::SetSelected(bool p_selected) { selected = p_selected; }

// SelectRadioButton implementation
void SelectRadioButton(std::vector<RadioButton> &v, int idx) {
  for (int i = 0; i < (int)v.size(); i++) {
    if (i == idx) {
      v[i].SetSelected(true);
    } else {
      v[i].SetSelected(false);
    }
  }
}
// PrintRadioButtons implementation
void PrintRadioButtons(const std::vector<RadioButton> v) {
  // store -1 in variable idx, and change it if any button's state is found
  // selected,
  //      keep it -1 otherwise
  int idx = -1;
  // loop over vector and print all the buttons with text
  for (int i = 0; i < (int)v.size(); i++) {
    if (v[i].IsSelected()) {
      std::cout << "(*) " << v[i].GetText() << "\n";
      idx = i;
    } else {
      std::cout << "( ) " << v[i].GetText() << "\n";
    }
  }
  // print which button is selected
  if (idx == -1) {
    std::cout << "No button selected yet\n";
  } else {
    std::cout << "The button at index " << idx << " is selected\n";
  }
}
