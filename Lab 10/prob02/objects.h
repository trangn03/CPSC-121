#include "cpputils/graphics/image.h"

#ifndef OBJECTS_H
#define OBJECTS_H

// Define your object classes here.
class SolidObject {
 private:
  int width_;
  int height_;
  graphics::Image* image_;
  int x_;
  int y_;

 public:
  SolidObject(int width, int height, graphics::Image* image);
  int GetX() const;
  void SetX(int x);
  int GetY() const;
  void SetY(int y);
  int GetWidth() const;
  int GetHeight() const;
  virtual void Draw() const = 0;
  bool CollidesWith(const SolidObject* object);

 protected:
  graphics::Image* GetImage() const;
};
class Brick : public SolidObject {
 private:
  graphics::Color color_;

 public:
  Brick(int width, int height, graphics::Color color, graphics::Image* image);
  void Draw() const;
};
class Paddle : public Brick {
 public:
  Paddle(int width, int height, graphics::Image* image);
};
class Ball : public SolidObject {
 public:
  Ball(int diameter, graphics::Image* image);
  void Draw() const;
};

#endif  // OBJECTS_H
