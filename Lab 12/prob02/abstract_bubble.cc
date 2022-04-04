#include "abstract_bubble.h"

#include <random>

// Implementation of AbstractBubble methods.
// YOU DO NOT NEED TO EDIT THIS FILE.

const int kRange = 11;
const int kMaxPixelValue = 256;

AbstractBubble::AbstractBubble(int x, int y, graphics::Image* image_ptr)
    : x_(x), y_(y), image_ptr_(image_ptr), age_(0) {
  x_rate_ = rand() % kRange - kRange / 2;
  y_rate_ = rand() % kRange - kRange / 2;
  color_ = graphics::Color(rand() % kMaxPixelValue, rand() % kMaxPixelValue,
                           rand() % kMaxPixelValue);
}

AbstractBubble::~AbstractBubble() = default;

int AbstractBubble::GetAge() const { return age_; }

void AbstractBubble::Move() {
  x_ += x_rate_;
  y_ += y_rate_;
  // Check for bounce conditions.
  if (x_ < 0) {
    x_rate_ *= -1;
    x_ = 0;
  } else if (x_ >= image_ptr_->GetWidth()) {
    x_rate_ *= -1;
    x_ = image_ptr_->GetWidth() - 1;
  }
  if (y_ < 0) {
    y_rate_ *= -1;
    y_ = 0;
  } else if (y_ >= image_ptr_->GetHeight()) {
    y_rate_ *= -1;
    y_ = image_ptr_->GetHeight() - 1;
  }

  // Increment the age.
  age_++;
}

void AbstractBubble::Draw() {
  // Draw this bubble on the image using the method GetBubbleSize to determine
  // the radius of the circle.
  image_ptr_->DrawCircle(x_, y_, GetBubbleSize(), color_);
}
