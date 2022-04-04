#include <iostream>
#include <memory>
#include <string>

#include "cpputils/graphics/image.h"
#include "robot.h"

const int size = 500;
const graphics::Color white(graphics::Color(255, 255, 255));
const double kAnimationRatio = 8;
const int kAnimationMs = 60;

using std::cin;
using std::cout;
using std::string;

//
// You do not need to edit this file.
//

class RobotClickListener : public graphics::MouseEventListener,
                           public graphics::AnimationEventListener {
 public:
  // Tear down.
  ~RobotClickListener() {
    image.RemoveMouseEventListener(*this);
    image.RemoveAnimationEventListener(*this);
  }

  // Set up
  void Start() {
    string filename1;
    string filename2;
    cout << "Enter a filename for the robot icon: ";
    cin >> filename1;
    cout << "Enter another filename for the robot icon: ";
    cin >> filename2;
    robot_ = std::make_unique<Robot>(filename1, filename2);

    image.Initialize(size, size);
    image.AddMouseEventListener(*this);
    image.AddAnimationEventListener(*this);

    robot_->SetPosition(last_x_, last_y_);
    robot_->Draw(image);
    image.ShowUntilClosed("Robot friend", kAnimationMs);
  }

  void OnMouseEvent(const graphics::MouseEvent& event) override {
    // When the mouse moves or drags, update the mouse coordinates.
    if (event.GetMouseAction() == graphics::MouseAction::kMoved ||
        event.GetMouseAction() == graphics::MouseAction::kDragged) {
      last_x_ = event.GetX();
      last_y_ = event.GetY();
    }
  }

  void OnAnimationStep() override {
    // Erase the image.
    // Maybe not the most efficient solution but works fine on this scale.
    image.DrawRectangle(0, 0, image.GetWidth(), image.GetHeight(), white);
    // Find the next robot point.
    int x =
        (last_x_ + robot_->GetX() * (kAnimationRatio - 1)) / kAnimationRatio;
    int y =
        (last_y_ + robot_->GetY() * (kAnimationRatio - 1)) / kAnimationRatio;
    // Move the robot.
    robot_->SetPosition(x, y);
    // Draw the robot.
    robot_->Draw(image);
    // Ensure the image is updated.
    image.Flush();
  }

 private:
  std::unique_ptr<Robot> robot_;
  graphics::Image image;
  int last_x_ = size / 2;
  int last_y_ = size / 2;
};

// Helper function to create robot*.bmp. Feel free to make your own
// icons and use this for inspiration.
/*
void CreateRobotIcon() {
  graphics::Image image(31, 31);
  // Arms
  image.DrawLine(0, 10, 10, 15, 109, 131, 161, 6);
  image.DrawLine(30, 10, 10, 15, 109, 131, 161, 6);
  // Legs
  image.DrawLine(10, 15, 10, 30, 109, 131, 161, 6);
  image.DrawLine(20, 15, 20, 30, 109, 131, 161, 6);
  // Body
  image.DrawRectangle(5, 0, 20, 22, 130, 151, 179);
  // Eyes
  image.DrawCircle(10, 8, 2, 255, 255, 255);
  image.DrawCircle(20, 8, 2, 255, 255, 255);
  image.DrawCircle(9, 8, 2, 62, 66, 71);
  image.DrawCircle(19, 8, 2, 62, 66, 71);
  image.SaveImageBmp("robot.bmp");
}
*/

int main() {
  RobotClickListener listener;
  listener.Start();
  return 0;
}
