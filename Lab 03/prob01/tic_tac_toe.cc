#include <iostream>
#include <vector>

int CheckGame(std::vector<std::vector<int>>& game) {
  // Determine if there was a winner, a draw, or if the game can continue.
  int result = 0;
  // Vertical #1
  if (game[0][0] == game[0][1] && game[0][1] == game[0][2]) {
    if (game[0][2] == 1) {
      result = 1;
    } else if (game[0][2] == 2) {
      result = 2;
    }
  }
  // Vertical #2
  if (game[1][0] == game[1][1] && game[1][1] == game[1][2]) {
    if (game[1][2] == 1) {
      result = 1;
    } else if (game[1][2] == 2) {
      result = 2;
    }
  }
  // Vertical #3
  if (game[2][0] == game[2][1] && game[2][1] == game[2][2]) {
    if (game[2][2] == 1) {
      result = 1;
    } else if (game[2][2] == 2) {
      result = 2;
    }
  }
  // Horizontal #1
  if (game[0][0] == game[1][0] && game[1][0] == game[2][0]) {
    if (game[2][0] == 1) {
      result = 1;
    } else if (game[2][0] == 2) {
      result = 2;
    }
  }
  // Horizontal #2
  if (game[0][1] == game[1][1] && game[1][1] == game[2][1]) {
    if (game[2][1] == 1) {
      result = 1;
    } else if (game[2][1] == 2) {
      result = 2;
    }
  }
  // Horizontal #3
  if (game[0][2] == game[1][2] && game[1][2] == game[2][2]) {
    if (game[2][2] == 1) {
      result = 1;
    } else if (game[2][2] == 2) {
      result = 2;
    }
  }
  // Diagonal #1
  if (game[0][0] == game[1][1] && game[1][1] == game[2][2]) {
    if (game[2][2] == 1) {
      result = 1;
    } else if (game[2][2] == 2) {
      result = 2;
    }
  }
  // Diagonal #2
  if (game[0][2] == game[1][1] && game[1][1] == game[2][0]) {
    if (game[2][0] == 1) {
      result = 1;
    } else if (game[2][0] == 2) {
      result = 2;
    }
  }
  if (result == 0) {  // Check for no one win
    for (int i = 0; i < game.size(); i++) {
      for (int j = 0; j < game[i].size(); j++) {
        if (game[i][j] == 0) {
          return 0;
        }
      }
    }
    result = -1;
  }
  return result;
}
