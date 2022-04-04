#include <iostream>
#include <string>
#include <vector>

#include "radio_button.h"

int main() {
  int num_buttons;
  std::cout << "How many radio buttons? ";
  std::cin >> num_buttons;
  std::cin.ignore();
  if (num_buttons <= 0) {
    // Return early.
    return 0;
  }
  std::vector<RadioButton> buttons;
  for (int i = 0; i < num_buttons; i++) {
    std::string text;
    std::cout << "Text for button at index " << i << "? ";
    std::getline(std::cin, text);
    RadioButton rb;
    rb.SetText(text);
    buttons.push_back(rb);
  }
  PrintRadioButtons(buttons);

  std::string input;
  do {
    int index;
    std::cout << "\nWhat button index would you like to select? ";
    std::cin >> index;
    SelectRadioButton(buttons, index);
    PrintRadioButtons(buttons);
    std::cout << "Enter anything to select again (or \"quit\" to exit) ";
    std::cin >> input;
  } while (input != "quit");
  return 0;
}
