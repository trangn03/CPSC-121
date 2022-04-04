#include "recursion.h"

#include <algorithm>
#include <iostream>
#include <map>

// In recursion it's normal to have a helper function call the recursive
// function, passing in the appropriate parameters to start the recursion.
// In this case, the Unscramble function should create a helper function which
// is recursive.
void Unsc(std::string letters, std::map<std::string, bool>& words, int arr[],
          std::string w) {
  if (w.size() == letters.size()) {
    if (words[w]) {
      std::cout << w << " ";
      return;
    }
  }
  for (int i = 0; i < letters.size(); i++) {
    if (arr[i] != 1) {
      arr[i] = 1;
      Unsc(letters, words, arr, w + letters[i]);
      arr[i] = 0;
    }
  }
  return;
}
void Unscramble(std::string letters, std::map<std::string, bool>& words) {
  // array to track the already added characters to new string
  int arr[letters.size()];
  for (int i = 0; i < letters.size(); i++) {
    arr[i] = 0;
  }
  std::string w;
  for (int j = 0; j < letters.size(); j++) {
    arr[j] = 1;
    w = letters[j];
    Unsc(letters, words, arr, w);
    arr[j] = 0;
  }
}
// Like Unscramble, ScrabbleSolver should create a helper function which is
// is recursive.
void Scr(std::string letters, std::map<std::string, bool>& words, int arr[],
         std::string w) {
  if (words[w]) {
    std::cout << w << " ";
    return;
  }
  for (int i = 0; i <= letters.size(); i++) {
    if (arr[i] != 1) {
      arr[i] = 1;
      Scr(letters, words, arr, w + letters[i]);
      arr[i] = 0;
    }
  }
  return;
}
void ScrabbleSolver(std::string letters, std::map<std::string, bool>& words) {
  int arr[letters.size()];
  for (int i = 0; i < letters.size(); i++) {
    arr[i] = 0;
  }
  std::string w;
  for (int j = 0; j < letters.size(); j++) {
    arr[j] = 1;
    w = letters[j];
    Scr(letters, words, arr, w);
    arr[j] = 0;
  }
  return;
}
// ScrabbleSolverNoDupes needs to keep track of the previous words which were
// found in order not to print them again. Create a recursive helper function to
// recursively unscramble without duplications.
void Nd(std::string letters, std::map<std::string, bool>& words,
        std::map<std::string, bool>& used_words, std::string w, int arr[]) {
  if (w.size() <= letters.size()) {
    if (words[w]) {
      auto j = used_words.find(w);
      if (j == used_words.end()) {
        std::cout << w << " ";
        used_words.insert(std::make_pair(w, true));
        return;
      }
    }
  }
  for (int i = 0; i < letters.size(); i++) {
    if (arr[i] != 1) {
      arr[i] = 1;
      Nd(letters, words, used_words, w + letters[i], arr);
      arr[i] = 0;
    }
  }
  return;
}
void ScrabbleSolverNoDupes(std::string letters,
                           std::map<std::string, bool>& words) {
  std::map<std::string, bool> used_words;
  int arr[letters.size()];
  for (int i = 0; i < letters.size(); i++) {
    arr[i] = 0;
  }
  std::string w;
  for (int k = 0; k < letters.size(); k++) {
    arr[k] = 1;
    w = letters[k];
    Nd(letters, words, used_words, w, arr);
    arr[k] = 0;
  }
  return;
}
