#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "button.h"
#include "cpputils/graphics/image.h"

//                                    //
//                                    //
// You do not need to edit this file. //
//                                    //
//                                    //

graphics::Color ColorFromHex(int hex_value) {
  int b = hex_value % 256;
  int g = (hex_value / 256) % 256;
  int r = hex_value / (256 * 256);
  return graphics::Color(r, g, b);
}

void DisplayButtons(const std::vector<Button> buttons,
                    int most_contrast_index) {
  if (buttons.size() == 0) return;
  const int height = 40;
  const int width = 150;
  graphics::Image image(width, height * buttons.size());
  for (int i = 0; i < buttons.size(); i++) {
    std::ostringstream out;
    out.precision(2);
    out << std::fixed << buttons[i].GetContrastRatio();
    std::string text = out.str() + ":1";
    if (most_contrast_index == i) {
      text += " (best!)";
    }
    image.DrawRectangle(0, i * height, width, height,
                        buttons[i].GetBackgroundColor());
    image.DrawText(0, i * height + height * .3333, text, height / 2,
                   buttons[i].GetTextColor());
  }
  image.ShowUntilClosed();
}

int main() {
  // Create a vector to hold Button objects.
  std::vector<Button> buttons;
  int count;
  std::cout << "How many buttons? ";
  std::cin >> count;
  std::cout << "For each button please provide the hex code of the text color "
            << "and background color, for example \"00ffcc\"" << std::endl;
  for (int i = 0; i < count; i++) {
    int text_hex;
    int background_hex;
    std::cout << "Text color, button " << (i + 1) << ": ";
    std::cin >> std::hex >> text_hex;
    std::cout << "Background color, button " << (i + 1) << ": ";
    std::cin >> std::hex >> background_hex;
    graphics::Color text_color = ColorFromHex(text_hex);
    graphics::Color background_color = ColorFromHex(background_hex);

    // Create a Button using |text_color| and |background_color|,
    // and add it to the vector of buttons.
    Button button(text_color, background_color);
    buttons.push_back(button);

    // Print out "That IS an accessible button!" if the button is accessible,
    // and "That is NOT an accessible button!" if the button is not.
    if (button.IsAccessible()) {
      std::cout << "That IS an accessible button!" << std::endl;
    } else {
      std::cout << "That is NOT an accessible button." << std::endl;
    }
  }

  // Call the DisplayButtons function passing in the vector of buttons and the
  // index of the button with the highest contrast.
  int most_contrast_index = ButtonWithMostContrast(buttons);
  DisplayButtons(buttons, most_contrast_index);

  return 0;
}
