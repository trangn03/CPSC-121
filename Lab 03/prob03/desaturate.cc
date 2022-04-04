#include "desaturate.h"

void Desaturate(graphics::Image& image) {
  // Returns the width and height of the image
  int GetWidth;
  int GetHeight;
  // Gets the width of the image
  int width = image.GetWidth();
  // Gets the red, green or blue pixel value at an (x,y) pixel location
  int GetRed(int x, int y);
  int GetGreen(int x, int y);
  int GetBlue(int x, int y);
  // Sets the red, green, or blue pixel value at an (x,y) pixel location
  bool SetRed(int x, int y, int red);
  bool SetGreen(int x, int y, int green);
  bool SetBlue(int x, int y, int blue);
  // for loop over every pixel in the image and desaturate them one by one
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < width; j++) {
      int red = image.GetRed(i, j);
      int green = image.GetGreen(i, j);
      int blue = image.GetBlue(i, j);
      int result = (red + green + blue) / 3;
      image.SetRed(i, j, result);
      image.SetGreen(i, j, result);
      image.SetBlue(i, j, result);
    }
  }
}
