#include "bubble.h"

#include <iomanip>
#include <iostream>

int Bubble::GetRadius() { return radius_; } 
void Bubble::SetRadius(double radius) { radius_ = radius; }

double Bubble::radius() { return radius_; }

double Bubble::CalculateVolume() {
  double constants = 4.0 * 3.1415 / 3.0;
  return constants * radius_ * radius_ * radius_;
}

Bubble CombineBubble(Bubble x, Bubble y) {
  Bubble combine;
  double combine_radius = x.radius() + y.radius();
  combine.SetRadius(combine_radius);
  return combine;
}
