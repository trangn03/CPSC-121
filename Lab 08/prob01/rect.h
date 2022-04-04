#ifndef RECT_H
#define RECT_H

// Rect class here.
class Rect {
 private:
  int value_x;
  int value_y;
  int value_width;
  int value_height;

 public:
  Rect(int x, int y, int w, int h);
  int GetX();
  void SetX(int x);
  int GetY();
  void SetY(int y);
  int GetWidth();
  void SetWidth(int w);
  int GetHeight();
  void SetHeight(int h);
  bool Contains(int x, int y);
};

#endif  // RECT_H
