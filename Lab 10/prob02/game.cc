#include "game.h"

#include <iostream>
#include <set>
#include <vector>

// Constants for the Breakout game.
const int kSize = 500;
const int kBrickHeight = 20;
const int kPaddleWidth = 80;
const int kBrickWidth = 48;
const int kBrickSpacing = 2;
const int kBallDiameter = 18;
const int kInitialSpeed = 5;
const int kNumRows = 5;
const graphics::Color red(255, 0, 0);
const graphics::Color orange(255, 125, 0);
const graphics::Color green(0, 200, 100);
const graphics::Color teal(0, 125, 255);
const graphics::Color blue(0, 0, 255);
const graphics::Color white(255, 255, 255);

Game::Game() : speed_x_(kInitialSpeed), speed_y_(kInitialSpeed) {}

Game::~Game() {
  image_.RemoveMouseEventListener(*this);
  image_.RemoveAnimationEventListener(*this);
  delete ball_;
  delete paddle_;
  for (auto brick : bricks_) {
    delete brick;
  }
  bricks_.clear();
}

void Game::Initialize() {
  image_.Initialize(kSize, kSize);
  paddle_ = new Paddle(kPaddleWidth, kBrickHeight, &image_);
  paddle_->SetY(kSize - kBrickHeight * 3);
  paddle_->SetX(kSize / 2);
  ball_ = new Ball(kBallDiameter, &image_);
  ball_->SetX(kSize / 2);
  ball_->SetY(kSize / 2);
  std::vector<graphics::Color> colors;
  colors.push_back(red);
  colors.push_back(orange);
  colors.push_back(green);
  colors.push_back(teal);
  colors.push_back(blue);
  for (int i = 0; i < kSize / (kBrickWidth + kBrickSpacing); i++) {
    for (int j = 0; j < kNumRows; j++) {
      Brick* brick =
          new Brick(kBrickWidth, kBrickHeight, colors[j % kNumRows], &image_);
      brick->SetX(i * (kBrickWidth + kBrickSpacing));
      brick->SetY(j * (kBrickHeight + kBrickSpacing));
      bricks_.insert(brick);
    }
  }
  Draw();
  DrawGameState();
  image_.AddMouseEventListener(*this);
  image_.AddAnimationEventListener(*this);
}

void Game::Start() { image_.ShowUntilClosed("Breakout"); }

void Game::OnMouseEvent(const graphics::MouseEvent& event) {
  if (state_ == GameState::kNotStarted &&
      event.GetMouseAction() == graphics::MouseAction::kReleased) {
    state_ = GameState::kInProgress;
  }
  paddle_->SetX(event.GetX());
}

void Game::OnAnimationStep() {
  if (state_ != GameState::kInProgress) {
    return;
  }
  if (ball_->GetX() < 0 || ball_->GetX() + ball_->GetWidth() >= kSize) {
    speed_x_ *= -1;
  }
  if (ball_->GetY() <= 0) {
    speed_y_ *= -1;
  } else if (ball_->GetY() + ball_->GetHeight() >= kSize) {
    // End.
    state_ = GameState::kLost;
    DrawGameState();
    return;
  }
  if (ball_->CollidesWith(paddle_)) {
    speed_y_ *= -1;
  }
  // Iterate thru set and change it using an iterator.
  for (auto it = bricks_.begin(); it != bricks_.end();) {
    if (ball_->CollidesWith(*it)) {
      it = bricks_.erase(it);
      speed_y_ *= -1;
    } else {
      it++;
    }
  }
  if (bricks_.size() == 0) {
    state_ = GameState::kWon;
    DrawGameState();
    return;
  }
  ball_->SetX(ball_->GetX() + speed_x_);
  ball_->SetY(ball_->GetY() + speed_y_);
  // Check walls and ceiling
  Draw();
}

void Game::Draw() {
  // Erase everything.
  image_.DrawRectangle(0, 0, kSize, kSize, white);
  ball_->Draw();
  paddle_->Draw();
  for (auto brick : bricks_) {
    brick->Draw();
  }
  image_.Flush();
}

void Game::DrawGameState() {
  if (state_ == GameState::kInProgress) {
    return;
  }
  std::string message;
  if (state_ == GameState::kNotStarted) {
    message = "CLICK TO START";
  } else if (state_ == GameState::kLost) {
    message = "GAME OVER";
  } else if (state_ == GameState::kWon) {
    message = "YOU WON";
  }
  image_.DrawText(kSize / 2 / 2, kSize / 2 - kBrickWidth, message,
                  kBrickHeight * 2, red);
  image_.Flush();
}
