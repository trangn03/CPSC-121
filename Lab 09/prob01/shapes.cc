#include "shapes.h"

#include <iostream>
#include <string>

Shape::Shape(int w, int h) {
  width_ = w;
  height_ = h;
}
int Shape::GetWidth() { return width_; }
int Shape::GetHeight() { return height_; }

Rectangle::Rectangle(int w, int h) : Shape{w, h} {}
int Rectangle::GetArea() { return GetWidth() * GetHeight(); }
std::string Rectangle::GetType() { return "rectangle"; }

Triangle::Triangle(int w, int h) : Shape{w, h} {}
int Triangle::GetArea() {
  const double a = 0.5;
  return a * GetWidth() * GetHeight();
}
std::string Triangle::GetType() { return "triangle"; }

Ellipse::Ellipse(int w, int h) : Shape{w, h} {}
int Ellipse::GetArea() {
  const double b = 0.5;
  const double pi = 3.14159;
  return ((GetWidth() * b) * (GetHeight() * b) * pi);
}
std::string Ellipse::GetType() { return "ellipse"; }

void PrintShapeInfo(Shape& s) {
  std::cout << s.GetType() << " with area " << s.GetArea() << "\n";
}
