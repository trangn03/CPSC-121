
#ifndef BUTTON_H
#define BUTTON_H

#include <string>
#include <vector>

#include "cpputils/graphics/image.h"

using namespace graphics;

class Button {
 private:
  Color value_fore;
  Color value_back;

 public:
  Button(Color value_fore, Color value_back);
  Color GetTextColor() const;
  Color GetBackgroundColor() const;
  double GetContrastRatio() const;
  bool IsAccessible();
};

int ButtonWithMostContrast(const std::vector<Button>& buttons);

#endif
