#include "button.h"
#include "cpputils/graphics/image.h"
#include "rect.h"
#include "toggle_button.h"

const graphics::Color kActiveColor(52, 85, 235);
const graphics::Color kInactiveColor(167, 172, 196);
const graphics::Color kWhite(255, 255, 255);
const graphics::Color kBlack(0, 0, 0);
const int kFontSize = 20;
const int kBorderSize = 4;

const int kButtonWidth = 200;
const int kButtonHeight = kFontSize * 3;

// ButtonManager has an image, handles mouse events and owns the Button and
// ToggleButton.
class ButtonManager : public graphics::MouseEventListener {
 public:
  ButtonManager() = default;

  ~ButtonManager() {
    // Destructor removes event listener.
    image_.RemoveMouseEventListener(*this);
  }

  // Set up and begin showing the image.
  void Start() {
    // Get user input.
    std::string button_text;
    std::string toggle_button_text;
    std::cout << "Enter the name for your button: ";
    std::getline(std::cin, button_text);
    std::cout << "Enter the name for your toggle button: ";
    std::getline(std::cin, toggle_button_text);

    // Create the buttons.
    button_ = Button(button_text,
                     Rect(kFontSize, kFontSize, kButtonWidth, kButtonHeight));
    toggle_button_ = ToggleButton(toggle_button_text,
                                  Rect(kFontSize, 3 * kFontSize + kButtonHeight,
                                       kButtonWidth, kButtonHeight));

    // Draw the image.
    image_.Initialize(kButtonWidth * 2, kButtonHeight * 4);
    DrawButtons();

    // Add this class as an event listener on the image: This allows it to
    // get mouse events.
    image_.AddMouseEventListener(*this);

    // Display.
    image_.ShowUntilClosed();
  }

  // Handle mouse events on the image.
  void OnMouseEvent(const graphics::MouseEvent& event) override {
    if (event.GetMouseAction() == graphics::MouseAction::kPressed) {
      // If the mouse event was a press, see if it happened on a button.
      // If it did happen on a button then set that button to active.
      if (button_.GetRect().Contains(event.GetX(), event.GetY())) {
        button_.SetActive(true);
      } else if (toggle_button_.GetRect().Contains(event.GetX(),
                                                   event.GetY())) {
        toggle_button_.SetActive(true);
      }
    } else if (event.GetMouseAction() == graphics::MouseAction::kReleased) {
      // If the mouse event was released, if a button was already active, then
      // send that button a click.
      if (button_.GetRect().Contains(event.GetX(), event.GetY()) &&
          button_.GetActive()) {
        button_.Click();
      } else if (toggle_button_.GetRect().Contains(event.GetX(),
                                                   event.GetY()) &&
                 toggle_button_.GetActive()) {
        toggle_button_.Click();
      }
      // All buttons are inactive after a mouse release.
      button_.SetActive(false);
      toggle_button_.SetActive(false);
    }
    DrawButtons();
    image_.Flush();
  }

 private:
  // Draw the buttons on the image.
  void DrawButtons() {
    // Draw the normal button outline.
    Rect rect1 = button_.GetRect();
    image_.DrawRectangle(rect1.GetX(), rect1.GetY(), rect1.GetWidth(),
                         rect1.GetHeight(),
                         button_.GetActive() ? kActiveColor : kInactiveColor);
    image_.DrawRectangle(rect1.GetX() + kBorderSize, rect1.GetY() + kBorderSize,
                         rect1.GetWidth() - 2 * kBorderSize,
                         rect1.GetHeight() - 2 * kBorderSize, kWhite);
    // Draw the normal button text.
    image_.DrawText(rect1.GetX(), rect1.GetY() + kFontSize, button_.GetName(),
                    kFontSize, kBlack);

    // Draw the toggle button outline.
    Rect rect2 = toggle_button_.GetRect();
    image_.DrawRectangle(
        rect2.GetX(), rect2.GetY(), rect2.GetWidth(), rect2.GetHeight(),
        toggle_button_.GetActive() ? kActiveColor : kInactiveColor);
    image_.DrawRectangle(rect2.GetX() + kBorderSize, rect2.GetY() + kBorderSize,
                         rect2.GetWidth() - 2 * kBorderSize,
                         rect2.GetHeight() - 2 * kBorderSize, kWhite);

    // Draw the slider in the toggle button depending on toggle state.
    if (toggle_button_.GetEnabled()) {
      image_.DrawRectangle(rect2.GetX() + rect2.GetWidth() / 2,
                           rect2.GetY() + kBorderSize,
                           rect2.GetWidth() / 2 - kBorderSize,
                           rect2.GetHeight() - 2 * kBorderSize, kActiveColor);
    } else {
      image_.DrawRectangle(rect2.GetX() + kBorderSize,
                           rect2.GetY() + kBorderSize,
                           rect2.GetWidth() / 2 - kBorderSize,
                           rect2.GetHeight() - 2 * kBorderSize, kInactiveColor);
    }

    // Draw the toggle button text.
    image_.DrawText(rect2.GetX(), rect2.GetY() + kFontSize,
                    toggle_button_.GetName(), kFontSize, kBlack);
  }

  Button button_;
  ToggleButton toggle_button_;
  graphics::Image image_;
};

int main() {
  ButtonManager button_manager;
  button_manager.Start();
  return 0;
}
