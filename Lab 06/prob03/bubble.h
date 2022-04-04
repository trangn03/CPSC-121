#include <iostream>
#ifndef BUBBLE_H
#define BUBBLE_H
class Bubble {
  double radius_;

 public:
  int GetRadius(); 
  void SetRadius(double radius);
  double radius();
  double CalculateVolume();
};
Bubble CombineBubble(Bubble a, Bubble b);
#endif
