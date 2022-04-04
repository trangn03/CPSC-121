#ifndef BUBBLE_H
#define BUBBLE_H
#include <string>

#include "cpputils/graphics/image.h"
class Bubble {
  // Create private variable
 private:
  int value_x;
  int value_y;
  int value_rad;
  graphics::Color value_color;
  int value_answer;
  // Create public variable
 public:
  int getX();
  void setX(int x);
  int getY();
  void setY(int y);
  graphics::Color getColor();
  void setColor(graphics::Color col);
  int getRadius();
  void setRadius(int rad);
  int getAnswer();
  void setAnswer(int ans);
  std::string ans();
};
#endif
