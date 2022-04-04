#include <iostream>

int main() {
  std::string text;
  std::cout << "Please enter header text: ";
  std::getline(std::cin, text);

  if (WithinWidth(text, 80)) {
    // Call the DisplayHeader function and pass in the text
    // inputted by the user
  } else {
    std::cout << text;
  }
  return 0;
}
