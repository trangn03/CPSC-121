#include <iostream>
#include <string>

#include "mirror.h"

int main() {
  // You do not need to edit this file.
  std::cout << "Enter the filename of an image to mirror: ";
  std::string filename;
  std::cin >> filename;
  graphics::Image image;
  if (!image.Load(filename)) {
    std::cout << "Could not load the image " << filename << std::endl;
    return 1;
  }

  Mirror(image);

  image.ShowUntilClosed();
  image.SaveImageBmp("output.bmp");
  return 0;
}
