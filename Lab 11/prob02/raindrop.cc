#include "raindrop.h"

// TODO: Implement your Raindrop class here.

Raindrop::Raindrop(graphics::Image* image, int x, int y, int rate) {
  image_ = image;
  x_ = x;
  y_ = y;
  rate_ = rate;
}

int Raindrop::GetY() const { return y_; }

void Raindrop::Fall() { y_ += rate_; }

void Raindrop::Draw() { image_->DrawCircle(x_, y_, 10, 99, 154, 242); }
