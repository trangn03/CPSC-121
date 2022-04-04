// TODO: Include any necessary headers.
#include <vector>

#include "abstract_bubble.h"
#include "cpputils/graphics/image.h"

#ifndef BUBBLES_H
#define BUBBLES_H

// TODO: Declare your BigBubble and SmallBubble classes here.
class BigBubble : public AbstractBubble {
 private:
  int size = 20;

 public:
  int GetBubbleSize();
  BigBubble(int x, int y, graphics::Image* image);
};

class SmallBubble : public AbstractBubble {
 private:
  int size = 10;

 public:
  int GetBubbleSize();
  SmallBubble(int x, int y, graphics::Image* image);
};
#endif  // BUBBLES_H
