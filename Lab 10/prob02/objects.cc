#include "objects.h"

#include "cpputils/graphics/image.h"

// SolidObject class
int SolidObject::GetX() const { return x_; }
void SolidObject::SetX(int x) { x_ = x; }
int SolidObject::GetY() const { return y_; }
void SolidObject::SetY(int y) { y_ = y; }
int SolidObject::GetWidth() const { return width_; }
int SolidObject::GetHeight() const { return height_; }
void SolidObject::Draw() const {}
graphics::Image* SolidObject::GetImage() const { return image_; }
SolidObject::SolidObject(int width, int height, graphics::Image* image) {
  width_ = width;
  height_ = height;
  image_ = image;
}

bool SolidObject::CollidesWith(const SolidObject* object) {
  if (GetWidth() == 0 || GetHeight() == 0) {
    return false;
  }
  if (object->GetWidth() == 0 || object->GetHeight() == 0) {
    return false;
  }
  if (((GetX() + GetWidth()) < object->GetX()) ||
      ((GetY() + GetHeight()) < object->GetY())) {
    return false;
  } else if (((object->GetX() + object->GetWidth()) < GetX()) ||
             ((object->GetY() + object->GetHeight()) < GetY())) {
    return false;
  } else {
    return true;
  }
}

// Brick class
Brick::Brick(int width, int height, graphics::Color color,
             graphics::Image* image)
    : SolidObject(width, height, image) {
  color_ = color;
}

void Brick::Draw() const {
  GetImage()->DrawRectangle(GetX(), GetY(), GetWidth(), GetHeight(), color_);
}

// Paddle class
Paddle::Paddle(int width, int height, graphics::Image* image)
    : Brick(width, height, graphics::Color(50, 50, 50), image) {}

// Ball class
Ball::Ball(int diameter, graphics::Image* image)
    : SolidObject(diameter, diameter, image) {}

void Ball::Draw() const {
  GetImage()->DrawCircle(GetX() + (GetWidth() / 2), GetY() + (GetWidth() / 2),
                         GetWidth() / 2, graphics::Color(210, 25, 25));
}
