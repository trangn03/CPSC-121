#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <vector>

#include "../cppaudit/gtest_ext.h"
#include "../../tic_tac_toe.h"

using std::vector;

std::string PrintGrid(vector<vector<int>> grid) {
  std::string result;
  for (int i = 0; i < grid.size(); i++) {
    result += "    ";
    for (int j = 0; j < grid[i].size(); j++) {
      result += std::to_string(grid[i][j]) + " ";
    }
    result += "\n";
  }
  return result;
}

TEST(CheckGameTest, EmptyGridReturnsZero) {
  std::vector<std::vector<int>> game(3, std::vector<int>(3));
  EXPECT_EQ(CheckGame(game), 0) << "    CheckGame should return 0 for: \n"
      << PrintGrid(game);
}

TEST(CheckGameTest, GameWithSomeMovesReturnsZero) {
  srand(time(NULL));
  // Try random things ten times.
  for (int i = 0; i < 10; i++) {
    std::vector<std::vector<int>> game(3, std::vector<int>(3));
    // Add four moves, two from each player. No one can win yet. It's ok if they
    // overlap.
    for (int i = 0; i < 2; i++) {
      game[rand() % 3][rand() % 3] = 1;
      game[rand() % 3][rand() % 3] = 2;
    }
    EXPECT_EQ(CheckGame(game), 0)
        << "    CheckGame should return 0 for a game with no winner yet: \n"
        << PrintGrid(game);
  }
}

TEST(CheckGameTest, FullGridReturnsNegOne) {
  std::vector<std::vector<int>> game(3, std::vector<int>(3));
  game[0][0] = 1;
  game[0][1] = 2;
  game[0][2] = 1;
  game[1][0] = 2;
  game[1][1] = 1;
  game[1][2] = 2;
  game[2][0] = 2;
  game[2][1] = 1;
  game[2][2] = 2;
  EXPECT_EQ(CheckGame(game), -1)
      << "    CheckGame should return -1 for a draw: \n" << PrintGrid(game);
}

TEST(CheckGameTest, ChecksHorizontals) {
  for (int player = 1; player <= 2; player++) {
    for (int i = 0; i < 3; i++) {
      std::vector<std::vector<int>> game(3, std::vector<int>(3));
      game[i][0] = player;
      game[i][1] = player;
      game[i][2] = player;
      game[(i + 2) % 3][0] = player % 2 + 1;
      game[(i + 1) % 3][1] = player % 2 + 1;
      game[(i + 2) % 3][2] = player % 2 + 1;
      EXPECT_EQ(CheckGame(game), player) << "    CheckGame should return "
          << player << " when that player has won on the horizontal: \n"
          << PrintGrid(game);
    }
  }
}

TEST(CheckGameTest, ChecksVerticals) {
  for (int player = 1; player <= 2; player++) {
    for (int i = 0; i < 3; i++) {
      std::vector<std::vector<int>> game(3, std::vector<int>(3));
      game[0][i] = player;
      game[1][i] = player;
      game[2][i] = player;
      game[0][(i + 2) % 3] = player % 2 + 1;
      game[1][(i + 1) % 3] = player % 2 + 1;
      game[2][(i + 2) % 3] = player % 2 + 1;
      EXPECT_EQ(CheckGame(game), player) << "    CheckGame should return "
          << player << " when that player has won on the vertical: \n"
          << PrintGrid(game);
    }
  }
}

TEST(CheckGameTest, ChecksDiagonals) {
  for (int player = 1; player <= 2; player++) {
    std::vector<std::vector<int>> game(3, std::vector<int>(3));
    game[0][0] = player;
    game[1][1] = player;
    game[2][2] = player;
    game[0][1] = player % 2 + 1;
    game[2][0] = player % 2 + 1;
    EXPECT_EQ(CheckGame(game), player) << "    CheckGame should return "
        << player << " when that player has won on the diagonal: \n"
        << PrintGrid(game);
  }
  for (int player = 1; player <= 2; player++) {
    std::vector<std::vector<int>> game(3, std::vector<int>(3));
    game[2][0] = player;
    game[1][1] = player;
    game[0][2] = player;
    game[0][1] = player % 2 + 1;
    game[2][1] = player % 2 + 1;
    EXPECT_EQ(CheckGame(game), player) << "    CheckGame should return "
        << player << " when that player has won on the diagonal: \n"
        << PrintGrid(game);
  }
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  bool skip = true;
  for (int i = 0; i < argc; i++)
  {
    if (std::string(argv[i]) == "--noskip")
    {
      skip = false;
    }
  }
  if (skip)
  {
    ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  }
  return RUN_ALL_TESTS();
}
