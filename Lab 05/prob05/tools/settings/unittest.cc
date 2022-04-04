#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../cppaudit/gtest_ext.h"
#include "../../rectangle.h"
using ::testing::HasSubstr;

TEST(Rectangle, PublicMethodsPresent) {
  Rectangle r;
  ASSERT_NO_THROW({
    r.Length();
    r.Width();
    r.SetLength(5);
    r.SetWidth(5);
    r.Area();
  });
}

TEST(Rectangle, MutatorsAndAccessors) {
  Rectangle your_rectangle;
  int length = 10, width = 5;
  ASSERT_NO_THROW({
    your_rectangle.SetLength(length);
    your_rectangle.SetWidth(width);
  });
  ASSERT_EQ(your_rectangle.Length(), 10);
  ASSERT_EQ(your_rectangle.Width(), 5);
}

TEST(Rectangle, Area1) {
    Rectangle your_rectangle;
    your_rectangle.SetLength(3);
    your_rectangle.SetWidth(6);
    ASSERT_EQ(your_rectangle.Area(), 18);
}

TEST(Rectangle, Area2) {
    Rectangle your_rectangle;
    your_rectangle.SetLength(17);
    your_rectangle.SetWidth(12);
    ASSERT_EQ(your_rectangle.Area(), 204);
}

TEST(Rectangle, FirstArgumentBigger) {
  Rectangle bigger_rectangle, smaller_rectangle;
  bigger_rectangle.SetLength(36);
  bigger_rectangle.SetWidth(5);
  smaller_rectangle.SetLength(5);
  smaller_rectangle.SetWidth(4);
  ASSERT_TRUE(LongestRectangle(bigger_rectangle, smaller_rectangle).Length() == bigger_rectangle.Length());
}

TEST(Rectangle, SecondArgumentBigger) {
  Rectangle bigger_rectangle, smaller_rectangle;
  bigger_rectangle.SetLength(28);
  bigger_rectangle.SetWidth(9);
  smaller_rectangle.SetLength(3);
  smaller_rectangle.SetWidth(9);
  ASSERT_TRUE(LongestRectangle(smaller_rectangle, bigger_rectangle).Length() == bigger_rectangle.Length());
}

TEST(UserInput, AskRectangleInput) {
  std::string user_input = "2\n3\n4\n5\n";
  ASSERT_EXECEXIT("main", user_input, 3)
    << "      Your program should ask for the length and width values for two rectangles.";
}

TEST(Driver, ShowAreaFirstRectangle) {
  std::string user_input = "2\n3\n4\n5\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("The area of Rectangle 1 is: 6"))
      << "      Your program should show the area of the first rectangle, 6.";
}

TEST(Driver, ShowAreaSecondRectangle) {
  std::string user_input = "2\n3\n4\n5\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("The area of Rectangle 2 is: 20"))
      << "      Your program should show the area of the second rectangle, 20.";
}

TEST(Driver, ShowLongestRectangle) {
  std::string user_input = "2\n3\n4\n5\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("The longest rectangle has a length of 4, a width of 5, and an area of 20."))
      << "      Your program should show the length, width, and area of the longest rectangle.";
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
