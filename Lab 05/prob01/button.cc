// cmath is used for GetScaledChannel.
#include "button.h"

#include <cmath>
#include <string>

#include "cpputils/graphics/image.h"

// Don't forget to include button.h and cpputils/graphics/image.h.

// Use this to scale a color channel from the range (0, 255)
// to the range (0, 1).
double GetScaledChannel(int channel) {
  double scaled = channel / 255.;
  const double min = 0.03928;
  if (scaled <= min) {
    return scaled / 12.92;
  } else {
    return pow((scaled + .055) / 1.055, 2.4);
  }
}

int ButtonWithMostContrast(const std::vector<Button>& buttons) {
  int mostContrast = 0;
  double currentRatio = 0;
  double highestRatio = 0;
  for (int i = 0; i < buttons.size(); i++) {
    double currentRatio = buttons[i].GetContrastRatio();
    if (currentRatio > highestRatio) {
      mostContrast = i;
      highestRatio = currentRatio;
    }
  }

  return mostContrast;
}

Button::Button(Color value_fore, Color value_back) {
  this->value_fore = value_fore;
  this->value_back = value_back;
}

graphics::Color Button::GetTextColor() const { return value_fore; }

graphics::Color Button::GetBackgroundColor() const { return value_back; }

double GetLuminance(int red, int green, int blue) {
  double redD = GetScaledChannel(red);
  double greenD = GetScaledChannel(green);
  double blueD = GetScaledChannel(blue);
  double luminance = 0.2126 * redD + 0.7152 * greenD + 0.0722 * blueD;
  return luminance;
}

double Button::GetContrastRatio() const {
  int red1 = value_fore.Red();
  int red2 = value_back.Red();
  int green1 = value_fore.Green();
  int green2 = value_back.Green();
  int blue1 = value_fore.Blue();
  int blue2 = value_back.Blue();

  double brightness1 = GetLuminance(red1, green1, blue1);
  double brightness2 = GetLuminance(red2, green2, blue2);

  double brighterValue;
  double darkerValue;
  if (brightness1 > brightness2) {
    brighterValue = brightness1;
    darkerValue = brightness2;
  } else {
    brighterValue = brightness2;
    darkerValue = brightness1;
  }

  return ((brighterValue + 0.05) / (darkerValue + 0.05));
}

bool Button::IsAccessible() {
  if (GetContrastRatio() >= 4.5) {
    return true;
  }
  return false;
}
