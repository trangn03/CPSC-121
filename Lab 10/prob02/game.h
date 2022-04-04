#include <set>

#include "cpputils/graphics/image.h"
#include "objects.h"

// Runs a Breakout game.
// You do not need to modify this code.
class Game : public graphics::MouseEventListener,
             public graphics::AnimationEventListener {
 public:
  // Represents the state of the game.
  enum GameState {
    kNotStarted = 1,
    kInProgress = 2,
    kLost = 3,
    kWon = 4,
  };

  Game();
  ~Game();

  // Get ready to play.
  void Initialize();

  // Begin the event loop by showing the image.
  void Start();

  // Gets mouse events from the image.
  void OnMouseEvent(const graphics::MouseEvent& event) override;

  // Gets animation events from the image.
  void OnAnimationStep() override;

 private:
  // Helper methods.
  void Draw();
  void DrawGameState();

  Ball* ball_ = nullptr;
  Paddle* paddle_ = nullptr;
  std::set<Brick*> bricks_;
  graphics::Image image_;
  int speed_x_;
  int speed_y_;
  GameState state_ = GameState::kNotStarted;
};
