#include "progress_bar.h"

#include <stdlib.h>

ProgressBar::ProgressBar() = default;

void ProgressBar::OnAnimationStep() {
  int grey_track = 0;
  std::cout << "Animation step!" << std::endl;
  const int a = 500;
  const int blue_width = 200;
  const int grey_width = 300;
  const int height = 30;
  if (track >= a) {
    track = 0;
  }
  // Blue begins
  if (track == 0) {
    image_.DrawRectangle(track, 0, blue_width, height, kProgressForeground);
    image_.DrawRectangle(track + blue_width, 0, grey_width, height,
                         kProgressBackground);
    track += speed;
  }
  // Grey in middle
  else if ((track) > grey_width) {
    int wide = (a - (track + blue_width));
    std::cout << wide << std::endl;
    image_.DrawRectangle(track, 0, blue_width - abs(wide), height,
                         kProgressForeground);
    image_.DrawRectangle(0, 0, abs(wide), height, kProgressForeground);
    image_.DrawRectangle(abs(wide), 0, grey_width, height, kProgressBackground);
    track += speed;
  }
  // Blue ends
  else if ((track) == grey_width) {
    image_.DrawRectangle(track, 0, blue_width, grey_width, kProgressForeground);
    image_.DrawRectangle(0, 0, grey_width, height, kProgressBackground);
    track += speed;
  }
  // Blue in middle
  else if ((track) < grey_width) {
    grey_track = track + blue_width;
    int wide = (a - grey_track);
    image_.DrawRectangle(grey_track, 0, wide, height, kProgressBackground);
    image_.DrawRectangle(0, 0, track, height, kProgressBackground);
    image_.DrawRectangle(track, 0, blue_width, height, kProgressForeground);
    track += speed;
  }
  image_.Flush();
}

// Initialize( Set up state)
void ProgressBar::Initialize(int s) {
  const int a = 500;
  const int b = 30;
  // Save the speed integer into a member variable
  speed = s;
  // Create the image
  image_.Initialize(a, b);
  // Draw the progress bar background
  image_.DrawRectangle(0, 0, a, b, kProgressBackground);
  // Add the ProgressBar as a listener to the image_ by passing the image to the
  // current object
  image_.AddAnimationEventListener(*this);
}

// Destructor
ProgressBar::~ProgressBar() { image_.RemoveAnimationEventListener(*this); }

void ProgressBar::Start() { image_.ShowUntilClosed("Best progress bar ever!"); }
