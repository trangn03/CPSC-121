#include "bubble.h"

#include <iostream>
#include <string>

int Bubble::getX() { return value_x; }
void Bubble::setX(int x) { this->value_x = x; }
int Bubble::getY() { return value_y; }
void Bubble::setY(int y) { this->value_y = y; }
graphics::Color Bubble::getColor() { return value_color; }
void Bubble::setColor(graphics::Color col) { this->value_color = col; }
int Bubble::getRadius() { return value_rad; }
void Bubble::setRadius(int rad) { this->value_rad = rad; }
int Bubble::getAnswer() { return value_answer; }
void Bubble::setAnswer(int ans) { this->value_answer = ans; }
// Return string representing the bubbles
std::string Bubble::ans() {
  return ("Bubble at (" + std::to_string(value_x) + ", " +
          std::to_string(value_y) + ") with size " + std::to_string(value_rad));
}
