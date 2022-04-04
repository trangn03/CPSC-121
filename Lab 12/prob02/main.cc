#include <iostream>
#include <vector>

#include "abstract_bubble.h"
#include "bubble_jar.h"
#include "bubbles.h"
#include "cpputils/graphics/image.h"

int main() {
  // TODO: Update the creation of the BubbleJar to pass in a maximum age.
  BubbleJar jar;
  jar.Initialize(15);
  jar.Start();
  return 0;
}
