#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <vector>

#include "../cppaudit/gtest_ext.h"
#include "../../cpputils/graphics/image.h"
#include "../../button.h"


const graphics::Color kWhite(255, 255, 255);
const graphics::Color kBlack(0, 0, 0);
const graphics::Color kRed(255, 0, 0);
const graphics::Color kGreen(0, 255, 0);
const graphics::Color kBlue(0, 0, 255);

TEST(ButtonTest, GetColors) {
  Button button(kWhite, kBlack);
  EXPECT_EQ(kWhite, button.GetTextColor())
      << "    Text color should be the first color passed to the constructor.";
  EXPECT_EQ(kBlack, button.GetBackgroundColor())
      << "    Text color should be the first color passed to the constructor.";
}

// Contrast ratios from https://webaim.org/resources/contrastchecker/.

TEST(ButtonTest, GetContrastRatioWhiteOnBlack) {
  Button button(kWhite, kBlack);
  ASSERT_NEAR(21.0, button.GetContrastRatio(), .01)
      << "    White text on a black background would have a contrast ratio of 21.0.";
  EXPECT_TRUE(button.IsAccessible())
      << "    Contrast ratio of 21.0 is greater than 4.5, so it should be accessible.";
}

TEST(ButtonTest, GetContrastRatioWhiteOnWhite) {
  Button button(kWhite, kWhite);
  ASSERT_NEAR(1.0, button.GetContrastRatio(), .01)
      << "    White text on a white background would have a contrast ratio of 1.0.";
  EXPECT_FALSE(button.IsAccessible())
      << "    Contrast ratio of 1.0 is less than 4.5, so it should not be accessible.";
}

TEST(ButtonTest, GetContrastRatioBlackOnBlack) {
  Button button(kWhite, kWhite);
  ASSERT_NEAR(1.0, button.GetContrastRatio(), .01)
      << "    Black text on a black background would have a contrast ratio of 1.0.";
  EXPECT_FALSE(button.IsAccessible())
      << "    Contrast ratio of 1.0 is less than 4.5, so it should not be accessible.";
}

TEST(ButtonTest, GetContrastRatioRedOnBlack) {
  Button button(kRed, kBlack);
  ASSERT_NEAR(5.25, button.GetContrastRatio(), .01)
      << "    Red text on a black background would have a contrast ratio of 5.25.";
  EXPECT_TRUE(button.IsAccessible())
      << "    Contrast ratio of 5.25 is greater than 4.5, so it should be accessible.";
}

TEST(ButtonTest, GetContrastRatioGreenOnBlack) {
  Button button(kGreen, kBlack);
  ASSERT_NEAR(15.3, button.GetContrastRatio(), .01)
      << "    Green text on a black background would have a contrast ratio of 15.3.";
  EXPECT_TRUE(button.IsAccessible())
      << "    Contrast ratio of 15.3 is greater than 4.5, so it should be accessible.";
}

TEST(ButtonTest, GetContrastRatioBlueOnBlack) {
  Button button(kBlue, kBlack);
  ASSERT_NEAR(2.44, button.GetContrastRatio(), .01)
      << "    Red text on a black background would have a contrast ratio of 2.44.";
  EXPECT_FALSE(button.IsAccessible())
      << "    Contrast ratio of 2.44 is less than 4.5, so it should not be accessible.";
}

TEST(ButtonTest, GetContrastRatioBlackOnWhite) {
  Button button(kBlack, kWhite);
  ASSERT_NEAR(21.0, button.GetContrastRatio(), .01)
      << "    Black text on a white background would have a contrast ratio of 21.0. "
      << "Make sure you use the higher luminance in the numerator.";
  EXPECT_TRUE(button.IsAccessible())
      << "    Contrast ratio of 21.0 is greater than 4.5, so it should be accessible.";
}

TEST(ButtonTest, GetContrastRatioRedOnWhite) {
  Button button(kRed, kWhite);
  ASSERT_NEAR(3.99, button.GetContrastRatio(), .01)
      << "    Red text on a white background would have a contrast ratio of 3.99. "
      << "Make sure you use the higher luminance in the numerator.";
  EXPECT_FALSE(button.IsAccessible())
      << "    Contrast ratio of 3.99 is less than 4.5, so it should not be accessible.";
}

TEST(ButtonTest, GetContrastRatioGreenOnWhite) {
  Button button(kGreen, kWhite);
  ASSERT_NEAR(1.37, button.GetContrastRatio(), .01)
      << "    Green text on a white background would have a contrast ratio of 1.37. "
      << "Make sure you use the higher luminance in the numerator.";
  EXPECT_FALSE(button.IsAccessible())
      << "    Contrast ratio of 1.37 is less than 4.5, so it should not be accessible.";
}

TEST(ButtonTest, GetContrastRatioBlueOnWhite) {
  Button button(kBlue, kWhite);
  ASSERT_NEAR(8.59, button.GetContrastRatio(), .01)
      << "    Blue text on a white background would have a contrast ratio of 8.59. "
      << "Make sure you use the higher luminance in the numerator.";
  EXPECT_TRUE(button.IsAccessible())
      << "    Contrast ratio of 8.59 is greater than 4.5, so it should be accessible.";
}

TEST(ButtonTest, ComplexColorContrastRatio) {
  Button button(graphics::Color(232, 232, 232), graphics::Color(209, 0, 52));
  ASSERT_NEAR(4.55, button.GetContrastRatio(), .01)
      << "    #e8e8e8 text on a #d10034 background would have a contrast ratio of 4.55. "
      << "Make sure you use the higher luminance in the numerator.";
  EXPECT_TRUE(button.IsAccessible())
      << "    Contrast ratio of 4.55 is greater than 4.5, so it should be accessible.";
}

TEST(ButtonWithMostContrastTest, OneButton) {
  std::vector<Button> buttons;
  buttons.push_back(Button(kWhite, kBlack));
  EXPECT_EQ(ButtonWithMostContrast(buttons), 0)
      << "    In a vector length 1, the first button (at index 0) always has "
      << "the most contrast.";
}

TEST(ButtonWithMostContrastTest, TwoButtonsFirstOneBetter) {
  std::vector<Button> buttons;
  buttons.push_back(Button(kWhite, kBlack));
  buttons.push_back(Button(kWhite, kWhite));
  EXPECT_EQ(ButtonWithMostContrast(buttons), 0)
      << "    In a vector where the first button is white on black, and the "
      << "second is white on white, the first (index 0) has the most contrast.";
}

TEST(ButtonWithMostContrastTest, TwoButtonsSecondOneBetter) {
  std::vector<Button> buttons;
  buttons.push_back(Button(kBlack, kBlack));
  buttons.push_back(Button(kBlack, kWhite));
  EXPECT_EQ(ButtonWithMostContrast(buttons), 1)
      << "    In a vector where the first button is black on black, and the "
      << "second is black on white, the second (index 1) has the most contrast.";
}

TEST(ButtonWithMostContrastTest, ManyButtonsMiddleOneIsBest) {
  std::vector<Button> buttons;
  for (int i = 0; i < 250; i++) {
    buttons.push_back(Button(graphics::Color(i, i, i), kBlack));
  }
  buttons.insert(buttons.begin() + 30, Button(graphics::Color(252, 252, 253), kBlack));
  EXPECT_EQ(ButtonWithMostContrast(buttons), 30)
      << "The index of the button with the highest contrast ratio should be returned.";
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
