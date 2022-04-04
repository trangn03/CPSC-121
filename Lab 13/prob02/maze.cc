#include "maze.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "robot.h"

// TODO: Implement LoadMap and GetElement
int MazeData::GetWidth() const { return width; }
int MazeData::GetHeight() const { return height; }
int MazeData::GetStartRow() const { return start_row_; }
int MazeData::GetStartCol() const { return start_col_; }
int MazeData::GetGoalRow() const { return goal_row_; }
int MazeData::GetGoalCol() const { return goal_col_; }
bool MazeData::IsValid() const { return is_valid_; }
MazeData::MazeData(std::string m) {
  this->s = m;
  LoadMap();
}

void MazeData::LoadMap() {
  std::string temp;
  std::ifstream m(s);
  if (m.is_open()) {
    is_valid_ = true;
    m >> width;
    m >> height;
    for (int i = 0; i < map_data_.size(); i++) {
      for (int j = 0; j < map_data_.size(); j++) {
        map_data_[i][j] = temp[j];
        std::cout << map_data_[i][j];
        if (map_data_[i][j] == 'S') {
          start_row_ = i;
          start_col_ = j;
        }
        if (map_data_[i][i] == 'X') {
          goal_row_ = i;
          goal_col_ = j;
        }
        if (map_data_[i][j] == 'S' || map_data_[i][j] == 'X') {
          is_valid_ = true;
        } else {
          is_valid_ = false;
        }
      }
    }
  } else {
    is_valid_ = false;
  }
  m.close();
}

MapObjectType MazeData::GetElement(int a, int b) {
  if (map_data_[a][b] == 'W') {
    return MapObjectType::kWall;
  } else if (map_data_[a][b] == 'G') {
    return MapObjectType::kGround;
  } else if (map_data_[a][b] == 'S') {
    return MapObjectType::kStart;
  } else if (map_data_[a][b] == 'X') {
    return MapObjectType::kGoal;
  } else {
    return MapObjectType::kWall;
  }
}

void Maze::Start() {
  if (maze_data_->IsValid()) {
    map_ = std::move(std::make_unique<graphics::Image>(
        maze_data_->GetWidth() * kSizeMultiplier_,
        maze_data_->GetHeight() * kSizeMultiplier_));

    char_row_ = maze_data_->GetStartRow();
    char_col_ = maze_data_->GetStartCol();

    map_->AddAnimationEventListener(*this);
    map_->AddMouseEventListener(*this);
    map_->ShowUntilClosed("Maze");
  } else {
    std::cout << "Cannot start maze." << std::endl;
  }
}

void Maze::OnAnimationStep() {
  DrawMap();
  DrawCharacter();
  if (is_solved_) {
    map_->DrawText(10, 10, "Solved it!", 20, 255, 0, 0);
  }
  map_->Flush();
}

void Maze::MoveCharacter(Direction dir) {
  int new_row = char_row_;
  int new_col = char_col_;
  switch (dir) {
    case kUp:
      new_row -= 1;
      break;
    case kDown:
      new_row += 1;
      break;
    case kLeft:
      new_col -= 1;
      break;
    case kRight:
      new_col += 1;
  }
  if (new_col < 0 || new_col >= maze_data_->GetWidth() || new_row < 0 ||
      new_row >= maze_data_->GetHeight()) {
    return;
  } else if (maze_data_->GetElement(new_row, new_col) != kWall) {
    char_row_ = new_row;
    char_col_ = new_col;
    if (char_row_ == maze_data_->GetGoalRow() &&
        char_col_ == maze_data_->GetGoalCol()) {
      is_solved_ = true;
    }
  }
}

void Maze::OnMouseEvent(const graphics::MouseEvent& event) {
  if (!is_solved_) {
    if (event.GetMouseAction() == graphics::MouseAction::kPressed) {
      int image_offset = kSizeMultiplier_ / 2;
      if (event.GetX() > character_->GetX() + image_offset) {
        MoveCharacter(kRight);
      } else if (event.GetX() < character_->GetX() - image_offset) {
        MoveCharacter(kLeft);
      } else if (event.GetY() > character_->GetY() + image_offset) {
        MoveCharacter(kDown);
      } else if (event.GetY() < character_->GetY() - image_offset) {
        MoveCharacter(kUp);
      }
    }
  }
}

void Maze::DrawMap() const {
  for (int i = 0; i < maze_data_->GetHeight(); i++) {
    for (int j = 0; j < maze_data_->GetWidth(); j++) {
      graphics::Color color;
      switch (maze_data_->GetElement(i, j)) {
        case kWall:
          color = gray_;
          break;
        case kGround:
          color = white_;
          break;
        case kStart:
          color = green_;
          break;
        case kGoal:
          color = red_;
          break;
      }
      map_->DrawRectangle(j * kSizeMultiplier_, i * kSizeMultiplier_,
                          kSizeMultiplier_, kSizeMultiplier_, color);
    }
  }
}

void Maze::DrawCharacter() const {
  int image_offset = kSizeMultiplier_ / 2;
  character_->SetPosition(char_col_ * kSizeMultiplier_ + image_offset,
                          char_row_ * kSizeMultiplier_ + image_offset);
  character_->Draw(*(map_.get()));
}
