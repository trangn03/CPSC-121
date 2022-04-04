#include "rainstorm.h"

#include <stdlib.h>

#include <random>
#include <vector>

#include "raindrop.h"

// Constants you can use in your program.
const int kRaindropSize = 10;
const int kImageSize = 300;
const int kFastRate = 5;
const int kSlowRate = 3;
const graphics::Color kWhite(255, 255, 255);

// Provided function to calculate a raindrop's initial state. Pass pointers to
// a x coordianet, a y coordinate, and a integer rate of fall.
void CalculateRandomRaindropParams(int* x, int* y, int* rate) {
  const int kFastRate = 5;
  const int kSlowRate = 3;
  *x = rand() % kImageSize;
  *y = rand() % kImageSize;
  *rate = rand() % 2 ? kSlowRate : kFastRate;
}

Rainstorm::~Rainstorm() {
  // Remove itself as an animation event listener.
  image_.RemoveAnimationEventListener(*this);

  // TODO:
  // Deallocate all dynamically allocated memory.
  for (int i = 0; i < rain.size(); i++) {
    delete rain[i];
  }
}

// Initializes the Rainstorm class.
void Rainstorm::Initialize(int raindrop_count) {
  // Create the image to be 300x300px. Do not change the size.
  image_.Initialize(kImageSize, kImageSize);
  // Adds itself as an animation event listener to the image.
  image_.AddAnimationEventListener(*this);

  // TODO:
  // Create the integer parameter number of Raindrop* by dynamically
  // allocating memory. Use the provided function,
  // CalculateRandomRaindropParams, to get the initial x, y and rate.
  for (int i = 0; i < raindrop_count; i++) {
    int* x = new int();
    int* y = new int();
    int* rate = new int();
    CalculateRandomRaindropParams(x, y, rate);
    Raindrop* r = new Raindrop(&image_, *x, *y, *rate);
    rain.push_back(r);
    r->Draw();
    delete x;
    delete y;
    delete rate;
  }
}

void Rainstorm::Start() {
  // Feel free to rename the window.
  image_.ShowUntilClosed("Rainy day");
}

void Rainstorm::OnAnimationStep() {
  // TODO:
  // Clear the image by drawing a white rectangle across the whole background.
  image_.DrawRectangle(0, 0, kImageSize, kImageSize, kWhite);

  // TODO:
  // For each Raindrop* in the vector, ask it to Fall(), then check its
  // y coordinate is still within the image bounds. If it is within bounds,
  // Draw() it, otherwise delete it and dynamically allocate memory for a new
  // Raindrop*, replacing the old Raindrop* at that location with the new one,
  // using CalculateRandomRaindropParams and starting y at 0.
  for (int i = 0; i < rain.size(); i++) {
    rain[i]->Fall();
    if (rain[i]->GetY() < kImageSize) {
      rain[i]->Draw();
    } else {
      delete rain[i];
      rain.erase(rain.begin() + i);
      int* x = new int();
      int* y = new int();
      int* rate = new int();
      CalculateRandomRaindropParams(x, y, rate);
      Raindrop* r = new Raindrop(&image_, *x, 0, *rate);
      r->Draw();
      rain.insert(rain.begin() + i, r);
      delete x;
      delete y;
      delete rate;
    }
  }
  // TODO:
  // Refresh the drawing using Image::Flush.
  image_.Flush();
}
