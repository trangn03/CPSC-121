#include <iostream>
#include <vector>

#include "cpputils/graphics/image.h"
#include "tic_tac_toe.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;

/////////////////////////////////////
// Create the Tic Tac Toe game.
// You do not need to edit this code.
/////////////////////////////////////

int main() {
  const graphics::Color black{0, 0, 0};
  const graphics::Color white{255, 255, 255};
  const graphics::Color red{255, 0, 0};
  const graphics::Color blue{0, 0, 255};
  const int size = 600;
  const int board_size = 500;
  const int thickness = 5;
  const int font_size = 16;
  const int game_size = 3;

  const int border = (size - board_size) / 2;

  graphics::Image image(size, size);

  while (true) {
    // Draw the tic tac toe board.
    image.DrawRectangle(0, 0, size, size, white);

    for (int i = 1; i < game_size; i++) {
      int offset = i * board_size / game_size + border;
      image.DrawLine(offset, border, offset, size - border, black, thickness);
      image.DrawLine(border, offset, size - border, offset, black, thickness);
    }

    image.DrawText(border, border - font_size, "Player one's turn!", font_size,
                   red);
    image.Show();

    // Represent the game as a vector of vectors of ints.
    vector<vector<int>> game(game_size, vector<int>(game_size, 0));
    bool player_one_turn = true;

    cout << "Welcome to tic tac toe. Player 1 and player 2 "
            "will enter their moves in the terminal. Pick your "
            "next square using an integer 1 through "
         << game_size * game_size << ", as: " << endl;
    int cell = 1;
    for (int i = 0; i < game_size; i++) {
      for (int j = 0; j < game_size; j++) {
        cout << cell << " ";
        cell++;
      }
      cout << endl;
    }

    int winner = 0;
    while (winner == 0) {
      if (player_one_turn) {
        cout << "Player 1: ";
      } else {
        cout << "Player 2: ";
      }
      cout << "What square do you pick? ";
      int selection;
      int row;
      int col;
      while (true) {
        cin >> selection;
        if (selection < 1 || selection > game_size * game_size) {
          cout << "Invalid choice. Enter a number between 1 and "
               << game_size * game_size << ": ";
          continue;
        }
        // Convert to 0-based indexing.
        selection -= 1;
        // Check if we can play this square.
        row = selection % game_size;
        col = selection / game_size;
        if (game[row][col] == 0) {
          break;
        }
        cout << "That square is taken. Try again: ";
      }
      game[row][col] = player_one_turn ? 1 : 2;

      for (int i = 0; i < game_size; i++) {
        for (int j = 0; j < game_size; j++) {
          cout << game[j][i] << " ";
        }
        cout << endl;
      }

      int cell_size = board_size / game_size;

      if (player_one_turn) {
        // Draw the O.
        int offset = border + cell_size / 2;
        image.DrawCircle(row * cell_size + offset, col * cell_size + offset,
                         cell_size / 3, red);
        image.DrawCircle(row * cell_size + offset, col * cell_size + offset,
                         cell_size / 3 - 4, white);
      } else {
        // Draw the X.
        int offset = cell_size / 2 / 3;
        image.DrawLine(row * cell_size + border + offset,
                       col * cell_size + border + offset,
                       (row + 1) * cell_size + offset,
                       (col + 1) * cell_size + offset, blue, thickness);
        image.DrawLine((row + 1) * cell_size + offset,
                       col * cell_size + border + offset,
                       row * cell_size + border + offset,
                       (col + 1) * cell_size + offset, blue, thickness);
      }

      // Cover up the old text.
      image.DrawRectangle(border, border - font_size, board_size, font_size,
                          white);

      // Update the message.
      player_one_turn = !player_one_turn;
      std::string message = "Player ";
      message += (player_one_turn ? "one's" : "two's");
      message += " turn!";
      image.DrawText(border, border - font_size, message, font_size,
                     player_one_turn ? red : blue);

      // Refresh the image.
      image.Show();
      winner = CheckGame(game);
    }

    if (winner == -1) {
      cout << "Cat's game. A tie!" << endl;
    } else {
      cout << "Player " << winner << " has won!" << endl;
    }

    cout << "Game over. Do you want to play again? (Y/N):";
    std::string response;
    while (response != "Y" && response != "y") {
      cin >> response;
      if (response == "N" || response == "n") {
        return 0;
      } else if (response != "Y" && response != "y") {
        cout << "I didn't understand. Do you want to play again? (Y/N):";
      }
    }
  }
  return 0;
}
