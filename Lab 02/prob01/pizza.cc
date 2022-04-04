#include "pizza.h"

#include <math.h>
#include <stdlib.h>

#include "cpputils/graphics/image.h"

// You do not need to edit this file, but feel free to look around!

constexpr double pi = 3.141592;

const graphics::Color crust(237, 244, 173);
const graphics::Color sauce(217, 71, 39);
const graphics::Color cheese(255, 250, 235);
const graphics::Color pepperoni(150, 47, 47);
const graphics::Color onion(227, 227, 222);
const graphics::Color jalapeno(100, 145, 36);

const int kSauceOuterRadius = 20;
const int kCheeseOuterRadius = 30;
const int kPepperoniRadius = 30;
const int kOnionRadius = 10;
const int kJalapenoRadius = 15;

const int kNumPepperoni = 15;
const int kNumOnion = 30;
const int kNumJalapeno = 20;

const int kDegrees = 360;

int GetMinimumDimension(graphics::Image& image) {
  return std::min(image.GetWidth(), image.GetHeight());
}

void AddTopping(graphics::Image& pizza, const graphics::Color& color,
                int topping_radius, int num_topping) {
  int size = GetMinimumDimension(pizza);
  for (int i = 0; i < num_topping; i++) {
    int radius = rand() % (size / 2 - kCheeseOuterRadius - 3 * topping_radius) +
                 2 * topping_radius;
    int theta = i * kDegrees / num_topping;
    int x = size / 2 + radius * cos(theta * pi / (kDegrees / 2));
    int y = size / 2 + radius * sin(theta * pi / (kDegrees / 2));
    pizza.DrawCircle(x, y, topping_radius, color);
  }
}

void AddCrust(graphics::Image& pizza) {
  int size = GetMinimumDimension(pizza);
  // The crust fills the whole minimum dimension.
  pizza.DrawCircle(size / 2, size / 2, size / 2, crust);
}

void AddSauce(graphics::Image& pizza) {
  int size = GetMinimumDimension(pizza);
  // The sauce is almost as large as the crust, minus the outer radius.
  pizza.DrawCircle(size / 2, size / 2, size / 2 - kSauceOuterRadius, sauce);
}

void AddCheese(graphics::Image& pizza) {
  int size = GetMinimumDimension(pizza);
  // The cheese is almost as large as the crust, minus the outer radius.
  pizza.DrawCircle(size / 2, size / 2, size / 2 - kCheeseOuterRadius, cheese);
}

void AddPepperoni(graphics::Image& pizza) {
  // Initialize random seed so we can have predictable unit tests. The pepperoni
  // looks better when intialized with kPepperoniRadius * 2.
  srand(2 * kPepperoniRadius);
  AddTopping(pizza, pepperoni, kPepperoniRadius, kNumPepperoni);
}

void AddOnion(graphics::Image& pizza) {
  srand(kOnionRadius);
  AddTopping(pizza, onion, kOnionRadius, kNumOnion);
}

void AddJalapeno(graphics::Image& pizza) {
  srand(kJalapenoRadius);
  AddTopping(pizza, jalapeno, kJalapenoRadius, kNumJalapeno);
}
