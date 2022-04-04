#include <string>

#include "cpputils/graphics/image.h"

#ifndef ROBOT_H
#define ROBOT_H

class Robot {
  std::string first = " ";
  std::string second = " ";

 private:
  int value_x;
  int value_y;
  graphics::Image images[2];
  int images_i;

 public:
  int GetX();
  void SetX(int x);
  int GetY();
  void SetY(int y);
  int SetPosition(int x, int y);
  void Draw(graphics::Image&);
  Robot(const std::string& first, const std::string& second);
};
#endif
