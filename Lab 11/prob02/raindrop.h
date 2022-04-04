#include "cpputils/graphics/image.h"

#ifndef RAINDROP_H
#define RAINDROP_H

// TODO: Define your Raindrop class here.
class Raindrop {
 private:
  graphics::Image* image_;
  int x_;
  int y_;
  int rate_;

 public:
  Raindrop(graphics::Image* image, int x, int y, int rate);
  int GetY() const;
  void Fall();
  void Draw();
};

#endif  // RAINDROP_H
