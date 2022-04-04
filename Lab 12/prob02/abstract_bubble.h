#include "cpputils/graphics/image.h"

#ifndef ABSTRACT_BUBBLE_H
#define ABSTRACT_BUBBLE_H

// AbstractBubble class has a virtual method so it cannot be instantiated. You
// must create subclasses and override GetBubbleSize.
// YOU DO NOT NEED TO EDIT THIS FILE.
class AbstractBubble {
 public:
  // AbstractBubble constructor takes an x and y coordinate for the center of
  // the bubble as well as a pointer to a graphics::Image on which to draw.
  // The bubble will have a random rate at which it traverses the image and
  // will begin at the given (x, y) point.
  AbstractBubble(int x, int y, graphics::Image* image_ptr);

  // Destructor.
  virtual ~AbstractBubble();

  // Abstract method GetBubbleSize should return the radius of the bubble.
  virtual int GetBubbleSize() = 0;

  // Gets the age of the bubble, i.e. the count of the number of times
  // Move has been called.
  int GetAge() const;

  // Updates the bubble's location on the image. Bounces the bubble off the
  // edges of the image so that it does not go out of bounds.
  // Each time this is called, the age of the bubble increases by one.
  void Move();

  // Draws the bubble on the image.
  void Draw();

 private:
  int x_;
  int y_;
  int x_rate_;
  int y_rate_;
  int age_;
  graphics::Color color_;
  graphics::Image* image_ptr_;
};

#endif  // ABSTRACT_BUBBLE_H
