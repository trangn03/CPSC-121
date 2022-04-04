#include <memory>
#include <vector>

#include "cpputils/graphics/image.h"
#include "robot.h"

const graphics::Color red_(255, 0, 0);
const graphics::Color white_(255, 255, 255);
const graphics::Color gray_(128, 128, 128);
const graphics::Color green_(0, 255, 0);

enum MapObjectType { kWall, kGround, kGoal, kStart };
enum Direction { kUp, kDown, kLeft, kRight };

// TODO: Create the MazeData class here.

class MazeData {
 private:
  std::string s;
  int width;
  int height;
  int start_row_ = 0;
  int start_col_ = 0;
  int goal_row_;
  int goal_col_;
  bool is_valid_;
  void LoadMap();
  std::vector<std::vector<char>> map_data_;

 public:
  MazeData(std::string m);
  int GetWidth() const;
  int GetHeight() const;
  int GetStartRow() const;
  int GetStartCol() const;
  int GetGoalRow() const;
  int GetGoalCol() const;
  bool IsValid() const;
  MapObjectType GetElement(int a, int b);
};

class Maze : public graphics::AnimationEventListener,
             public graphics::MouseEventListener {
 public:
  Maze(const std::string& filename) : Maze(filename, 40) {}
  Maze(const std::string& filename, int size_multiplier)
      : maze_data_(std::make_unique<MazeData>(filename)),
        character_(std::make_unique<Robot>("robot1.bmp", "robot2.bmp")),
        char_row_(0),
        char_col_(0),
        is_solved_(false),
        kSizeMultiplier_(size_multiplier) {}
  void Start();
  void OnAnimationStep() override;
  void OnMouseEvent(const graphics::MouseEvent& event) override;

 private:
  void DrawMap() const;
  void DrawCharacter() const;
  void MoveCharacter(Direction dir);

  int kSizeMultiplier_;
  int char_row_;
  int char_col_;
  bool is_solved_;
  std::unique_ptr<Robot> character_;
  std::unique_ptr<MazeData> maze_data_;
  std::unique_ptr<graphics::Image> map_;
};
