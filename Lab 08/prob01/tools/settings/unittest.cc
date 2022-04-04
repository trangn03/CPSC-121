#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../cppaudit/gtest_ext.h"
#include "../../rect.h"
#include "../../button.h"
#include "../../toggle_button.h"

using ::testing::HasSubstr;

TEST(RectTest, Getters) {
  Rect rect(10, 20, 30, 40);
  ASSERT_EQ(rect.GetX(), 10)  << "    The first parameter passed to Rect constructor is the x coordinate. Store it in a member variable.";
  ASSERT_EQ(rect.GetY(), 20)  << "    The second parameter passed to Rect constructor is the y coordinate. Store it in a member variable.";
  ASSERT_EQ(rect.GetWidth(), 30) << "    The third parameter passed to Rect constructor is the width. Store it in a member variable.";
  ASSERT_EQ(rect.GetHeight(), 40) << "    The fourth parameter passed to Rect constructor is the height. Store it in a member variable.";
}

TEST(RectTest, ContainsPoint) {
  // Rect from x = 40 to 60, and y = 50 to 80.
  Rect rect(40, 50, 20, 30);
  ASSERT_FALSE(rect.Contains(30, 30)) << "    A rect with top left corner at (40, 50), width 20 and height 30 does not contain a point at (30, 30). x and y are too small.";
  ASSERT_FALSE(rect.Contains(90, 90)) << "    A rect with top left corner at (40, 50), width 20 and height 30 does not contain a point at (90, 90). x and y are too big.";
  ASSERT_FALSE(rect.Contains(0, 55)) << "    A rect with top left corner at (40, 50), width 20 and height 30 does not contain a point at (0, 55). x is too small.";
  ASSERT_FALSE(rect.Contains(65, 55)) << "    A rect with top left corner at (40, 50), width 20 and height 30 does not contain a point at (65, 55). x is too big.";
  ASSERT_TRUE(rect.Contains(55, 55)) << "    A rect with top left corner at (40, 50), width 20 and height 30 contains the point at (55, 55).";
  ASSERT_TRUE(rect.Contains(45, 75)) << "    A rect with top left corner at (40, 50), width 20 and height 30 contains the point at (45, 75).";
}

TEST(RectTest, ContainsPointOnEdge) {
  Rect rect(10, 20, 10, 10);
  ASSERT_TRUE(rect.Contains(10, 20)) << "    A rect with top left corner at (10, 20) should contain the point at (10, 20).";
  ASSERT_TRUE(rect.Contains(20, 30)) << "    A rect with top left corner at (10, 20), width 10 and height 10 should contain the point at (20, 30).";
}

TEST(ButtonTest, ConstructorsDefaultInactive) {
  Button button1;
  ASSERT_FALSE(button1.GetActive()) << "    Buttons should be inactive by default.";
  Button button2("my button", Rect(5, 10, 20, 10));
  ASSERT_FALSE(button2.GetActive()) << "    Buttons should be inactive by default.";
}

TEST(ButtonTest, Getters) {
  Button button("belly button", Rect(5, 10, 20, 30));
  ASSERT_EQ(button.GetName(), "belly button") << "    GetName should return the name passed in the constructor.";
  Rect rect = button.GetRect();
  ASSERT_EQ(rect.GetX(), 5) << "    GetRect should return the rect passed in the constructor.";
  ASSERT_EQ(rect.GetY(), 10) << "    GetRect should return the rect passed in the constructor.";
  ASSERT_EQ(rect.GetWidth(), 20) << "    GetRect should return the rect passed in the constructor.";
  ASSERT_EQ(rect.GetHeight(), 30) << "    GetRect should return the rect passed in the constructor.";
}

TEST(ButtonTest, GetAndSetActive) {
  Button button("cute as a", Rect(0, 0, 10, 10));
  button.SetActive(true);
  ASSERT_TRUE(button.GetActive()) << "    Button SetActive should change a member variable.";
  button.SetActive(false);
  ASSERT_FALSE(button.GetActive()) << "    Button SetActive should change a member variable.";
}

TEST(ButtonTest, Click) {
  Button button("cute as a button", Rect(0, 0, 10, 10));
  std::streambuf* original_out = std::cout.rdbuf();
  std::stringstream stream_out;
  std::cout.rdbuf(stream_out.rdbuf());
  button.Click();
  std::cout.rdbuf(original_out);
  EXPECT_THAT(stream_out.str(), testing::HasSubstr("Clicked cute as a button"))
      << "    Button::Click should cout \"Clicked \" plus the name of the button.";
}

TEST(ToggleButtonTest, ConstructorDefaults) {
  ToggleButton button1;
  ASSERT_FALSE(button1.GetActive()) << "    Buttons should be inactive by default.";
  ASSERT_FALSE(button1.GetEnabled()) << "    Toggle buttons should not be enabled by default.";
  ToggleButton button2("my button", Rect(5, 10, 20, 10));
  ASSERT_FALSE(button2.GetActive()) << "    Buttons should be inactive by default.";
  ASSERT_FALSE(button2.GetEnabled()) << "    Toggle buttons should not be enabled by default.";
}

TEST(ToggleButtonTest, HasGetNameAndActiveFunctionFromBaseClass) {
  ToggleButton button("toggly", Rect(3, 6, 9, 12));
  Button* b_ptr = &button;
  ASSERT_EQ(b_ptr->GetName(), "toggly") << "    Toggle buttons should inherit their GetName from the Button class.";
  ASSERT_FALSE(b_ptr->GetActive()) << "    Toggle buttons should inherit their Get/SetActive from the Button class.";
}

TEST(ToggleButtonTest, ClickToggles) {
  ToggleButton button;
  ASSERT_FALSE(button.GetEnabled()) << "    The ToggleButton should be not enabled at construction.";
  button.Click();
  ASSERT_TRUE(button.GetEnabled()) << "    The ToggleButton::Click function should change the ToggleButton's member variable tracking the 'enabled' state.";
  button.Click();
  ASSERT_FALSE(button.GetEnabled()) << "    The ToggleButton::Click function should change the ToggleButton's member variable tracking the 'enabled' state.";
}

TEST(ToggleButtonTest, ClickOutputEnabled) {
  ToggleButton button("sandwich", Rect(4, 8, 12, 16));
  ASSERT_FALSE(button.GetEnabled()) << "    The ToggleButton should be not enabled at construction.";
  std::streambuf* original_out = std::cout.rdbuf();
  std::stringstream stream_out;
  std::cout.rdbuf(stream_out.rdbuf());
  button.Click();
  std::cout.rdbuf(original_out);
  EXPECT_THAT(stream_out.str(), testing::HasSubstr("Clicked sandwich (enabled)"))
      << "    ToggleButton::Click should cout \"Clicked \", the name of the button, and the enabled state. Make sure to match formatting from the README.";
}

TEST(ToggleButtonTest, ClickOutputNotEnabled) {
  ToggleButton button("sandwich", Rect(4, 8, 12, 16));
  ASSERT_FALSE(button.GetEnabled()) << "    The ToggleButton should be not enabled at construction.";
  button.Click();
  std::streambuf* original_out = std::cout.rdbuf();
  std::stringstream stream_out;
  std::cout.rdbuf(stream_out.rdbuf());
  button.Click();
  std::cout.rdbuf(original_out);
  EXPECT_THAT(stream_out.str(), testing::HasSubstr("Clicked sandwich (disabled)"))
      << "    ToggleButton::Click should cout \"Clicked \", the name of the button, and the enabled state. Make sure to match formatting from the README.";
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
