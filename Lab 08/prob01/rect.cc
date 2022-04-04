#include "rect.h"

#include <iostream>
#include <string>

Rect::Rect(int x, int y, int w, int h) {
  value_x = x;
  value_y = y;
  value_width = w;
  value_height = h;
}
int Rect::GetX() { return value_x; }
void Rect::SetX(int x) { this->value_x = x; }
int Rect::GetY() { return value_y; }
void Rect::SetY(int y) { this->value_y = y; }
int Rect::GetWidth() { return value_width; }
void Rect::SetWidth(int w) { this->value_width = w; }
int Rect::GetHeight() { return value_height; }
void Rect::SetHeight(int h) { this->value_height = h; }
bool Rect::Contains(int x, int y) {
  if ((x >= GetX()) && (x <= (GetX() + GetWidth())) && (y >= GetY()) &&
      (y <= (GetY() + GetHeight()))) {
    return true;
  } else {
    return false;
  }
}
