#include "bubble_jar.h"

#include <iostream>
#include <vector>

#include "abstract_bubble.h"
#include "bubbles.h"

// Some helpful constants.
const int kSize = 300;
const graphics::Color kWhite(255, 255, 255);

BubbleJar::~BubbleJar() {
  // Clean up state. You do not need to make changes.
  image_.RemoveMouseEventListener(*this);
  image_.RemoveAnimationEventListener(*this);
}

void BubbleJar::Initialize(int a) {
  // TODO: Add to this function per the instructions in the README.
  max = a;
  image_.Initialize(kSize, kSize);
  image_.AddAnimationEventListener(*this);
  image_.AddMouseEventListener(*this);
}

void BubbleJar::Start() {
  // Displays the BubbleJar. Feel free to rename the image.
  image_.ShowUntilClosed("Bubble Jar");
}

void BubbleJar::OnMouseEvent(const graphics::MouseEvent& event) {
  std::cout << "BubbleJar got a MouseEvent" << std::endl;
  // TODO: Create a BigBubble on mouse press and a SmallBubble on mouse release
  // and add them to the vector.
  if (event.GetMouseAction() == graphics::MouseAction::kPressed) {
    BigBubble b(event.GetX(), event.GetY(), &image_);
    ab.push_back(std::make_unique<BigBubble>(b));
    b.Draw();
  } else if (event.GetMouseAction() == graphics::MouseAction::kReleased) {
    SmallBubble s(event.GetX(), event.GetY(), &image_);
    ab.push_back(std::make_unique<SmallBubble>(s));
    s.Draw();
  }
  image_.Flush();
}

void BubbleJar::OnAnimationStep() {
  std::cout << "BubbleJar got an animation step" << std::endl;
  // TODO: Update all the bubbles, making sure to remove the old ones
  // from the vector when they get above the maximum age.
  image_.DrawRectangle(0, 0, kSize, kSize, kWhite);
  for (int i = 0; i < ab.size(); i++) {
    if (ab[i]->GetAge() >= max) {
      ab.erase(ab.begin() + i);
      i--;  // minus so that it didn't skip the current vector
    }
  }
  for (int j = 0; j < ab.size(); j++) {
    ab[j]->Move();
    ab[j]->Draw();
  }
  image_.Flush();
}
