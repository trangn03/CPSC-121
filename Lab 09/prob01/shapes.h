#ifndef SHAPES_H
#define SHAPES_H

#include <string>

// Define your Shape and subclasses here.
class Shape {
 private:
  int width_;
  int height_;

 public:
  Shape(int w, int h);
  int GetWidth();
  int GetHeight();
  virtual int GetArea() = 0;
  virtual std::string GetType() = 0;
};

class Rectangle : public Shape {
 public:
  Rectangle(int w, int h);
  int GetArea() override;
  std::string GetType() override;
};

class Triangle : public Shape {
 public:
  Triangle(int w, int h);
  int GetArea() override;
  std::string GetType() override;
};

class Ellipse : public Shape {
 public:
  Ellipse(int w, int h);
  int GetArea() override;
  std::string GetType() override;
};
void PrintShapeInfo(Shape& s);
#endif  // SHAPES_H
