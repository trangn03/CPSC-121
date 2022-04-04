#include "cpputils/graphics/image.h"

#ifndef PROGRESS_BAR_H
#define PROGRESS_BAR_H

const graphics::Color kProgressBackground(224, 224, 224);
const graphics::Color kProgressForeground(30, 136, 229);

// TODO: Inherit from AnimationEventListener.
class ProgressBar : public graphics::AnimationEventListener {
 public:
  // TODO: Add your constructor, destructor, and member functions.
  ProgressBar();
  ~ProgressBar();
  void OnAnimationStep() override;
  void Initialize(int);
  void Start();

  // Used by unit tests. Do not modify.
  graphics::Image* GetImageForTesting() { return &image_; }

 private:
  // The image onto which you can draw the ProgressBar.
  graphics::Image image_;

  // TODO: Add other data members here.
  int speed;
  int track = 0;
};
#endif  // PROGRESS_BAR_H
