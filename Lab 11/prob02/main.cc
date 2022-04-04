#include <iostream>

#include "cpputils/graphics/image.h"
#include "raindrop.h"
#include "rainstorm.h"

int main() {
  Rainstorm r;
  r.Initialize(7);
  r.Start();
}
