#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "../../abstract_bubble.h"
#include "../../bubble_jar.h"
#include "../../bubbles.h"
#include "../../cpputils/graphics/test/test_event_generator.h"
#include "../cppaudit/gtest_ext.h"
#include "../../cpputils/graphics/test/image_test_utils.h"

const graphics::Color kWhite(255, 255, 255);
const int kRange = 11;
const int kMaxPixelValue = 256;

TEST(BigBubbleTest, GetBubbleSize) {
  graphics::Image image(100, 100);
  BigBubble bb(50, 30, &image);
  ASSERT_EQ(20, bb.GetBubbleSize())
      << "    BigBubble::GetBubbleSize should return 20.";
}

TEST(BigBubbleTest, InheritsFromAbstractBubble) {
  bool is_abstract_bubble = std::is_base_of<AbstractBubble, BigBubble>::value;
  EXPECT_TRUE(is_abstract_bubble)
      << "    BigBubble should inherit from AbstractBubble";
}

TEST(SmallBubbleTest, GetBubbleSize) {
  graphics::Image image(100, 100);
  SmallBubble sb(50, 30, &image);
  ASSERT_EQ(10, sb.GetBubbleSize())
      << "    SmallBubble::GetBubbleSize should return 10.";
}

TEST(SmallBubbleTest, InheritsFromAbstractBubble) {
  bool is_abstract_bubble = std::is_base_of<AbstractBubble, SmallBubble>::value;
  EXPECT_TRUE(is_abstract_bubble)
      << "    SmallBubble should inherit from AbstractBubble";
}

class BubbleJarTest : public testing::Test {
 public:
  void SetUp() override {
    // Calculate random members of AbstractBubble.
    srand(0);
    for (int i = 0; i < 50; i++) {
      x_rates_.push_back(rand() % kRange - kRange / 2);
      y_rates_.push_back(rand() % kRange - kRange / 2);
      colors_.push_back(graphics::Color(rand() % kMaxPixelValue,
                                        rand() % kMaxPixelValue,
                                        rand() % kMaxPixelValue));
    }
    // Reset random.
    srand(0);
  }

  const graphics::Color& GetColorForIndex(int i) { return colors_[i]; }

  int GetXRateForIndex(int i) { return x_rates_[i]; }

  int GetYRateForIndex(int i) { return y_rates_[i]; }

 private:
  std::vector<graphics::Color> colors_;
  std::vector<int> x_rates_;
  std::vector<int> y_rates_;
};

TEST_F(BubbleJarTest, MousePressedCreatesBigBubble) {
  std::string diff_image = "MousePressedCreatesBigBubble_expected_v_actual.bmp";
  remove(diff_image.c_str());

  BubbleJar jar;
  jar.Initialize(1);
  graphics::Image* image = jar.GetImageForTesting();
  ASSERT_EQ(300, image->GetWidth()) << "Image must be 300 by 300 px.";
  ASSERT_EQ(300, image->GetHeight()) << "Image must be 300 by 300 px.";
  image->Show();
  graphics::TestEventGenerator generator(image);
  generator.SendAnimationEvent();

  for (int i = 0; i < 300; i++) {
    for (int j = 0; j < 300; j++) {
      ASSERT_EQ(kWhite, image->GetColor(i, j))
          << "    Before any mouse presses or releases, the image should be "
             "white even after an animation event.";
    }
  }

  generator.MoveMouseTo(100, 50);
  for (int i = 0; i < 300; i++) {
    for (int j = 0; j < 300; j++) {
      ASSERT_EQ(kWhite, image->GetColor(i, j))
          << "    Before any mouse presses or releases, the image should be "
             "white even after an mouse moved event.";
    }
  }

  generator.MouseDown(100, 50);
  graphics::Image expected(300, 300);
  expected.DrawCircle(100, 50, 20, GetColorForIndex(0));

  bool match =
      ImagesMatch(&expected, image, diff_image, DiffType::kTypeSideBySide);
  ASSERT_TRUE(match)
      << "    Your BubbleJar::OnMouseEvent function isn't quite right, the "
         "big bubble is either missing or in the wrong place after a pressed "
         "event at (100, 50). See expected vs actual output at "
      << diff_image;
}

TEST_F(BubbleJarTest, MouseReleasedCreatesSmallBubble) {
  std::string diff_image =
      "MouseReleasedCreatesSmallBubble_expected_v_actual.bmp";
  remove(diff_image.c_str());

  BubbleJar jar;
  jar.Initialize(1);
  graphics::Image* image = jar.GetImageForTesting();
  image->Show();
  graphics::TestEventGenerator generator(image);

  generator.MouseDown(100, 50);
  generator.MoveMouseTo(200, 60);
  generator.MouseUp();

  graphics::Image expected(300, 300);
  expected.DrawCircle(100, 50, 20, GetColorForIndex(0));
  expected.DrawCircle(200, 60, 10, GetColorForIndex(1));

  bool match =
      ImagesMatch(&expected, image, diff_image, DiffType::kTypeSideBySide);
  ASSERT_TRUE(match)
      << "    Your BubbleJar::OnMouseEvent function isn't quite right, the "
         "small bubble is either missing or in the wrong place after a pressed "
         "event at (100, 50) and released event at (200, 60). We should see a "
         "big "
         "bubble at (100, 50) and a small one at (200, 60). See expected vs "
         "actual output at "
      << diff_image;
}

TEST_F(BubbleJarTest, MovesBubblesWithAnimationEvent) {
  std::string diff_image =
      "MovesBubblesWithAnimationEvent_expected_v_actual.bmp";
  remove(diff_image.c_str());

  BubbleJar jar;
  jar.Initialize(2);
  graphics::Image* image = jar.GetImageForTesting();
  image->Show();
  graphics::TestEventGenerator generator(image);

  generator.MouseDown(75, 90);
  generator.SendAnimationEvent();

  graphics::Image expected(300, 300);
  expected.DrawCircle(75 + GetXRateForIndex(0), 90 + GetYRateForIndex(0), 20,
                      GetColorForIndex(0));

  bool match =
      ImagesMatch(&expected, image, diff_image, DiffType::kTypeSideBySide);
  ASSERT_TRUE(match)
      << "    Your BubbleJar::OnAnimationStep function isn't quite right, the "
         "big bubble is either missing or in the wrong place after a pressed "
         "event at (75, 90) and a single animation step. Each animation step "
         "you "
         "should call Move on each bubble and then Draw. See expected vs "
         "actual output at "
      << diff_image;
}

TEST_F(BubbleJarTest, MovesTwoBubblesWithAnimationEvents) {
  std::string diff_image =
      "MovesTwoBubblesWithAnimationEvents_expected_v_actual.bmp";
  remove(diff_image.c_str());

  BubbleJar jar;
  jar.Initialize(10);
  graphics::Image* image = jar.GetImageForTesting();
  image->Show();
  graphics::TestEventGenerator generator(image);

  generator.MouseDown(75, 90);
  generator.MoveMouseTo(75, 200);
  generator.MouseUp();

  int count = 5;
  for (int i = 0; i < count; i++) {
    generator.SendAnimationEvent();
  }

  graphics::Image expected(300, 300);
  expected.DrawCircle(75 + GetXRateForIndex(0) * count,
                      90 + GetYRateForIndex(0) * count, 20,
                      GetColorForIndex(0));
  expected.DrawCircle(75 + GetXRateForIndex(1) * count,
                      200 + GetYRateForIndex(1) * count, 10,
                      GetColorForIndex(1));

  bool match =
      ImagesMatch(&expected, image, diff_image, DiffType::kTypeSideBySide);
  ASSERT_TRUE(match)
      << "    Your BubbleJar::OnAnimationStep function isn't quite right, the "
         "big bubble is either missing or in the wrong place after a pressed "
         "event at (75, 90) and a single animation step. Each animation step "
         "you "
         "should call Move on each bubble and then Draw. See expected vs "
         "actual output at "
      << diff_image;
}

TEST_F(BubbleJarTest, RemovesBubbleAfterMaxAnimationEvents) {
  BubbleJar jar;
  jar.Initialize(2);
  graphics::Image* image = jar.GetImageForTesting();
  image->Show();
  graphics::TestEventGenerator generator(image);

  generator.MouseDown(42, 57);
  generator.SendAnimationEvent();
  generator.SendAnimationEvent();
  // Check it's not empty.
  bool empty = true;
  for (int i = 0; i < 300; i++) {
    for (int j = 0; j < 300; j++) {
      if (kWhite != image->GetColor(i, j)) {
        empty = false;
        break;
      }
    }
    if (!empty) {
      break;
    }
  }
  ASSERT_FALSE(empty)
      << "    Image should not be empty after a mouse pressed and two "
         "animation events when the max age is 2, because the bubble's age is "
         "not yet bigger than the max age.";

  generator.SendAnimationEvent();
  // Now it should be empty.
  for (int i = 0; i < 300; i++) {
    for (int j = 0; j < 300; j++) {
      ASSERT_EQ(kWhite, image->GetColor(i, j))
          << "    After a Bubble reaches the max age it should be removed from "
             "the vector and not drawn any more. In this case the max age was "
             "2 and OnAnimationStep has been called three times.";
    }
  }
}

TEST_F(BubbleJarTest, RemovesAllTheOldestBubbles) {
  std::string diff_image =
      "RemovesAllTheOldestBubbles_expected_v_actual.bmp";

  remove(diff_image.c_str());
  BubbleJar jar;
  jar.Initialize(2);
  graphics::Image* image = jar.GetImageForTesting();
  image->Show();
  graphics::TestEventGenerator generator(image);

  // Two events at the same moment: bubbles 1-3 go at the same time.
  generator.MouseDown(40, 60);
  generator.MoveMouseTo(100, 80);
  generator.MouseUp();
  generator.MouseDown(120, 200);
  generator.SendAnimationEvent();

  // The fourth bubble comes later.
  generator.MoveMouseTo(150, 200);
  generator.MouseUp();
  generator.SendAnimationEvent();
  generator.SendAnimationEvent();

  // Now only the fourth bubble should be drawn.
  graphics::Image expected(300, 300);
  expected.DrawCircle(150 + GetXRateForIndex(3) * 2,
                      200 + GetYRateForIndex(3) * 2, 10,
                      GetColorForIndex(3));

  bool match =
      ImagesMatch(&expected, image, diff_image, DiffType::kTypeSideBySide);
  ASSERT_TRUE(match)
      << "    Your BubbleJar::OnAnimationStep function isn't quite right. In "
      "this case: max age is 2. Three bubbles were generated and then "
      "OnAnimationStep was called once. A fourth bubble was generated with a "
      "kReleased and OnAnimationStep was called twice more. Only the fourth "
      "bubble should remain: the first two should have been removed. Make sure "
      "you remove all bubbles with age >= maximum age before calling Move and "
      "Draw on the bubbles in OnAnimationStep. See expected vs actual output "
      "at " << diff_image;
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  bool skip = true;
  for (int i = 0; i < argc; i++) {
    if (std::string(argv[i]) == "--noskip") {
      skip = false;
    }
  }
  if (skip) {
    ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  }
  return RUN_ALL_TESTS();
}
