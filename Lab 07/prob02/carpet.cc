#include "carpet.h"

void DrawCarpet(int x, int y, int size, int order, graphics::Image& image) {
  // Your code here to draw a carpet with top left corner at (x, y), recursive
  // order |order|, and size |size|, onto the graphics::Image provided.
  // base case
  image.DrawRectangle(x, y, size, size, graphics::Color(0, 0, 0));
  if (order == 0) {
    return;
  }
  size = size / 3;
  // recursive case
  for (int i = 0; i < 9; i++) {
    if (i == 4) {
      image.DrawRectangle(x + size, y + size, size, size,
                          graphics::Color(255, 255, 255));
    } else {
      DrawCarpet(x + (i % 3) * size, y + (i / 3) * size, size, order - 1,
                 image);
    }
  }
}
