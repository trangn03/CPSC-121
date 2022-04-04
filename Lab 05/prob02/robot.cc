#include "robot.h"

#include <string>

#include "cpputils/graphics/image.h"

// Implement the function
int Robot::GetX() { return value_x; }
void Robot::SetX(int i) { value_x = i; }
int Robot::GetY() { return value_y; }
void Robot::SetY(int j) { value_y = j; }

int Robot::SetPosition(int i, int j) {
  value_x = i;
  value_y = j;
  return 0;
}

Robot::Robot(const std::string& first, const std::string& second) {
  this->first = first;
  this->second = second;

  images_i = 0;
}

void Robot::Draw(graphics::Image& refimg) {
  // if its first draw
  if (images_i == 0) {
    // load the icons to memory
    images[0].Load(first);
    images[1].Load(second);
  }

  // get a pointer to the next image
  const graphics::Image& img = images[images_i];

  int x = value_x - (img.GetWidth() / 2);
  int y = value_y - (img.GetHeight() / 2);

  // update reference image, without pixels
  for (int i = 0; i < img.GetWidth(); i++) {
    // if icon goes out of image area
    if ((x + i) >= refimg.GetWidth()) {
      break;
    }

    for (int j = 0; j < img.GetHeight(); j++) {
      // if icon goes out of image area
      if ((y + j) >= refimg.GetHeight()) {
        break;
      }

      // set the pixel at referenced image
      if ((x + i) >= 0 && (y + j) >= 0) {
        refimg.SetColor(x + i, y + j, img.GetColor(i, j));
      }
    }
  }

  images_i++;     // move to next image
  images_i %= 2;  // limit to 2 images
}
