#include <iostream>
#include <string>

#include "desaturate.h"

int main() {
  // You do not need to edit this file.
  std::cout << "Enter the filename of an image to desaturate: ";
  std::string filename;
  std::cin >> filename;
  graphics::Image image;
  if (!image.Load(filename)) {
    std::cout << "Could not load the image " << filename << std::endl;
    return 1;
  }

  Desaturate(image);

  image.ShowUntilClosed();
  image.SaveImageBmp("output.bmp");
  return 0;
}
