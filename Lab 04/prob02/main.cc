#include <stdlib.h>

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "bubble.h"
#include "cpputils/graphics/image.h"

int main() {
  // Get the number of bubbles from the user.
  int num_bubbles;
  std::cout << "How many bubbles do you want to draw? ";
  std::cin >> num_bubbles;
  const int kMaxChannel = 255;
  const int kHalfChannel = 125;
  // Create a map from strings to graphics::Color.
  std::map<std::string, graphics::Color> colors;
  colors["red"] = graphics::Color(kMaxChannel, 0, 0);
  colors["orange"] = graphics::Color(kMaxChannel, kHalfChannel, 0);
  colors["yellow"] = graphics::Color(kMaxChannel, kMaxChannel, 0);
  colors["green"] = graphics::Color(0, kMaxChannel, 0);
  colors["teal"] = graphics::Color(0, kMaxChannel, kMaxChannel);
  colors["blue"] = graphics::Color(0, 0, kMaxChannel);
  colors["purple"] = graphics::Color(kHalfChannel, 0, kMaxChannel);
  // Create a vector to store the bubbles.
  std::vector<Bubble> bubbles;
  std::cout << "Tell me about your bubbles.\n Valid x, y and size are between "
            << "0 and 500.\n Valid colors are red, orange, yellow, green, "
            << "teal, blue, and purple." << std::endl;
  for (int i = 0; i < num_bubbles; i++) {
    std::cout << "Bubble " << i << std::endl;
    std::string color;
    std::cout << "What color? ";
    std::cin >> color;
    int size;
    std::cout << "What size? ";
    std::cin >> size;
    int x;
    std::cout << "What x? ";
    std::cin >> x;
    int y;
    std::cout << "What y? ";
    std::cin >> y;
    // 1. Create a bubble and set the size, x and y from user input above.
    // 2. Determine the graphics::Color from the colors map and set that too.
    // 3. Add the bubble to the bubbles vector.
    Bubble curr;
    curr.setX(x);
    curr.setY(y);
    curr.setRadius(size);
    graphics::Color a = colors[color];
    curr.setColor(a);
    bubbles.push_back(curr);
  }
  const int kImageSize = 500;
  graphics::Image image(kImageSize, kImageSize);
  bool DrawCircle(int x, int y, int radius, graphics::Color);
  for (int i = 0; i < num_bubbles; i++) {
    // 1. Draw the Bubble at index i in the vector to the graphic::Image image.
    //    Use the Image::DrawCircle method.
    // 2. Print the Bubble to the terminal using the ToString() method.
    //
    image.DrawCircle(bubbles[i].getX(), bubbles[i].getY(),
                     bubbles[i].getRadius(), bubbles[i].getColor());
    std::cout << bubbles[i].ans() << std::endl;
  }
  image.SaveImageBmp("bubbles.bmp");
  std::cout << "Your bubbles were saved to bubbles.bmp" << std::endl;
  return 0;
}
