#include <vector>

#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

// Return 1 if player 1 wins, 2 if player 2 wins, 0 if no one has won but
// there's still space, and -1 if the board is full.
int CheckGame(std::vector<std::vector<int>>& game);

#endif  // TIC_TAC_TOE_H
