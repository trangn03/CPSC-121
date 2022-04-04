// TODO: Provide implementation of methods from bubbles.h if necessary.
#include "bubbles.h"

#include <vector>

#include "abstract_bubble.h"

int BigBubble::GetBubbleSize() { return size; }
BigBubble::BigBubble(int x, int y, graphics::Image* image)
    : AbstractBubble{x, y, image} {}

int SmallBubble::GetBubbleSize() { return size; }
SmallBubble::SmallBubble(int x, int y, graphics::Image* image)
    : AbstractBubble{x, y, image} {}
