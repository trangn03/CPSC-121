#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../cppaudit/gtest_ext.h"
#include "../../cpputils/graphics/test/image_test_utils.h"
#include "../../progress_bar.h"
#include "../../cpputils/graphics/test/test_event_generator.h"

class ProgressBarTest : public testing::Test {
public:
  void SetUp() override {
    // https://stackoverflow.com/questions/3803465/how-to-capture-stdout-stderr-with-googletest
    original = std::cout.rdbuf();
    std::cout.rdbuf(stream.rdbuf());
  }

  void TearDown() override {
    std::cout.rdbuf(original);
  }

protected:
  std::streambuf* original;
  std::stringstream stream;
};


TEST_F(ProgressBarTest, ImageSizeAfterInitialize) {
  ProgressBar pb;
  pb.Initialize(1);
  graphics::Image* image = pb.GetImageForTesting();
  ASSERT_EQ(image->GetWidth(), 500) << "    Image width must be set to 500 after initialize.";
  ASSERT_EQ(image->GetHeight(), 30) << "    Image height must be set to 30 after initialize.";
}

TEST_F(ProgressBarTest, ImageBackgroundAfterInitialize) {
  ASSERT_NE(kProgressBackground, kProgressForeground) << "    foreground and background colors cannot be equal. Check kProgressBackground and kProgressForeground.";
  ProgressBar pb;
  pb.Initialize(1);
  graphics::Image* image = pb.GetImageForTesting();
  for (int i = 0; i < image->GetWidth(); i++) {
    for (int j = 0; j < image->GetHeight(); j++) {
      ASSERT_EQ(kProgressBackground, image->GetColor(i, j)) << "    Image must be all kProgressBackground color after Initialize, before Start.";
    }
  }
}

TEST_F(ProgressBarTest, StartShowsImage) {
  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  system("timeout 1s ./main");
  end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end - start;
  std::chrono::milliseconds ms =
      std::chrono::duration_cast<std::chrono::milliseconds>(elapsed_seconds);
  if (ms.count() <= 900) {
    FAIL() << "    ProgressBar::Start() should call image_.ShowUntilClosed().";
  }
}

TEST_F(ProgressBarTest, IsAnimationEventListener) {
  bool is_listener = std::is_base_of<graphics::AnimationEventListener, ProgressBar>::value;
  ASSERT_TRUE(is_listener) << "    ProgressBar should inherit from graphics::AnimationEventListener";
}

void CheckAnimationEvent(int speed, int count, std::string message_prefix, std::string filename) {
  remove(filename.c_str());
  ASSERT_NE(kProgressBackground, kProgressForeground)
      << "    foreground and background colors cannot be equal. Check kProgressBackground and kProgressForeground.";
  ProgressBar pb;
  pb.Initialize(speed);
  graphics::Image* image = pb.GetImageForTesting();
  image->Show();
  ASSERT_EQ(image->GetWidth(), 500) << "    Image width must be set to 500 after initialize.";
  ASSERT_EQ(image->GetHeight(), 30) << "    Image height must be set to 500 after initialize.";

  graphics::TestEventGenerator generator(image);
  for (int i = 0; i < count; i++) {
    generator.SendAnimationEvent();
  }

  int start = speed * (count - 1);
  for (int i = 0; i < start; i++) {
    for (int j = 0; j < 30; j++) {
      bool match = kProgressBackground == image->GetColor(i, j);
      if (!match) {
        image->SaveImageBmp(filename);
      }
      ASSERT_TRUE(match) << message_prefix
      << "(" << start << ", 0) with width 200 and height 30. Found a "
      "pixel that wasn't background color at (" << i << ", " << j << "). See your progress bar at " << filename;
    }
  }

  for (int i = start; i < start + 200; i++) {
    for (int j = 0; j < 30; j++) {
      bool match = kProgressForeground == image->GetColor(i, j);
      if (!match) {
        image->SaveImageBmp(filename);
      }
      ASSERT_TRUE(match) << message_prefix
      << "(" << start << ", 0) with width 200 and height 30. Found a "
      "pixel that wasn't foreground color at (" << i << ", " << j << "). See your progress bar at " << filename;
    }
  }

  for (int i = start + 200; i < 500; i++) {
    for (int j = 0; j < 30; j++) {
      bool match = kProgressBackground == image->GetColor(i, j);
      if (!match) {
        image->SaveImageBmp(filename);
      }
      ASSERT_TRUE(match) << message_prefix
      << "(" << start << ", 0) with width 200 and height 30. Found a "
      "pixel that wasn't background color at (" << i << ", " << j << "). See your progress bar at " << filename;
    }
  }
  image->Hide();
}

TEST_F(ProgressBarTest, FirstAnimationEventStartsAtZeroPx) {
  CheckAnimationEvent(1, 1, "    The first time the ProgressBar receives an "
  "OnAnimationEvent, it should draw a rectangle starting at ", "FirstAnimationEventStartsAtZeroPx.bmp");
}

TEST_F(ProgressBarTest, SecondAnimationEventStartsAtSpeedTimes2Px) {
  CheckAnimationEvent(5, 2, "    The second time the ProgressBar receives an "
  "OnAnimationEvent with speed set to 5, it should draw a rectangle starting at ", "SecondAnimationEventStartsAtSpeedTimes2Px.bmp");
}

TEST_F(ProgressBarTest, TenthAnimationEventStartsAtSpeedTimes10Px) {
  CheckAnimationEvent(10, 20, "    The tenth time the ProgressBar receives an "
  "OnAnimationEvent with speed set to 20, it should draw a rectangle starting at ", "TenthAnimationEventStartsAtSpeedTimes10Px.bmp");
}

void CheckClippedAnimationEvent(int speed, int count, std::string message_prefix, std::string filename) {
  remove(filename.c_str());
  ASSERT_NE(kProgressBackground, kProgressForeground)
      << "    foreground and background colors cannot be equal. Check kProgressBackground and kProgressForeground.";
  ProgressBar pb;
  pb.Initialize(speed);
  graphics::Image* image = pb.GetImageForTesting();
  image->Show();
  ASSERT_EQ(image->GetWidth(), 500) << "    Image width must be set to 500 after initialize.";
  ASSERT_EQ(image->GetHeight(), 30) << "    Image height must be set to 500 after initialize.";

  graphics::TestEventGenerator generator(image);
  for (int i = 0; i < count; i++) {
    generator.SendAnimationEvent();
  }

  int start = speed * (count - 1);
  for (int i = start; i < 500; i++) {
    for (int j = 0; j < 30; j++) {
      bool match = kProgressForeground == image->GetColor(i, j);
      if (!match) {
        image->SaveImageBmp(filename);
      }
      ASSERT_TRUE(match) << message_prefix
      << "(" << start << ", 0) with width " << (500 - start) << " and height 30, "
      "and a foreground color rectangle starting at (0, 0) with width " << (start - 300)
      << ". Found a pixel that wasn't foreground color at (" << i << ", " << j
      << "). See your progress bar at " << filename;
    }
  }

  for (int i = start - 300; i < start; i++) {
    for (int j = 0; j < 30; j++) {
      bool match = kProgressBackground == image->GetColor(i, j);
      if (!match) {
        image->SaveImageBmp(filename);
      }
      ASSERT_TRUE(match) << message_prefix
      << "(" << start << ", 0) with width " << (500 - start) << " and height 30, "
      "and a foreground color rectangle starting at (0, 0) with width " << (start - 300)
      << ". Found a pixel that wasn't background color at (" << i << ", " << j
      << "). See your progress bar at " << filename;
    }
  }

  for (int i = 0; i < start - 300; i++) {
    for (int j = 0; j < 30; j++) {
      bool match = kProgressForeground == image->GetColor(i, j);
      if (!match) {
        image->SaveImageBmp(filename);
      }
      ASSERT_TRUE(match) << message_prefix
      << "(" << start << ", 0) with width " << (500 - start) << " and height 30, "
      "and a foreground color rectangle starting at (0, 0) with width " << (start - 300)
      << ". Found a pixel that wasn't foreground color at (" << i << ", " << j
      << "). See your progress bar at " << filename;
    }
  }
  image->Hide();
}

TEST_F(ProgressBarTest, RectIsClippedBy50Px) {
  CheckClippedAnimationEvent(50, 8, "The 8th time the ProgressBar receives "
  "OnAnimationEvent with step 50, it should draw a foreground color rectangle "
  "starting at ", "RectIsClippedBy50Px.bmp");
}

TEST_F(ProgressBarTest, RectIsClippedBy1Px) {
  CheckClippedAnimationEvent(1, 301, "The 301st time the ProgressBar receives "
  "OnAnimationEvent with step 50, it should draw a foreground color rectangle "
  "starting at ", "RectIsClippedBy1Px.bmp");
}

TEST_F(ProgressBarTest, DoesNotDrawOutOfBounds) {
  ProgressBar pb;
  pb.Initialize(50);
  graphics::Image* image = pb.GetImageForTesting();
  image->Show();
  graphics::TestEventGenerator generator(image);
  for (int i = 0; i < 15; i++) {
    generator.SendAnimationEvent();
  }
  EXPECT_THAT(stream.str(), Not(testing::HasSubstr("is out of bounds.")))
      << "    Your ProgressBar should not try to draw rectangles out of the image bounds.";
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
