#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../cppaudit/gtest_ext.h"
#include "../../shapes.h"

using ::testing::HasSubstr;

TEST(RectangleTest, Getters) {
  Rectangle r(5, 10);
  ASSERT_EQ(r.GetWidth(), 5) << "    The first thing passed to the rectangle "
      "constructor should be the width. Pass this to the Shape constructor.";
  ASSERT_EQ(r.GetHeight(), 10) << "    The second thing passed to the rectangle "
      "constructor should be the height. Pass this to the Shape constructor.";
}

TEST(RectangleTest, GetType) {
  Rectangle r(7, 14);
  ASSERT_EQ("rectangle", r.GetType()) << "    Rectangle::GetType should return \"rectangle\"";
}

TEST(RectangleTest, GetArea) {
  Rectangle r(6, 7);
  ASSERT_EQ(42, r.GetArea()) << "    Rectangle::GetArea should return width * height which is 42 for width 6, height 7.";
}

TEST(TriangleTest, Getters) {
  Triangle r(10, 39);
  ASSERT_EQ(r.GetWidth(), 10) << "    The first thing passed to the triangle "
      "constructor should be the width. Pass this to the Shape constructor.";
  ASSERT_EQ(r.GetHeight(), 39) << "    The second thing passed to the triangle "
      "constructor should be the height. Pass this to the Shape constructor.";
}

TEST(TriangleTest, GetType) {
  Triangle r(21, 28);
  ASSERT_EQ("triangle", r.GetType()) << "    Triangle::GetType should return \"triangle\"";
}

TEST(TriangleTest, GetArea) {
  Triangle r(6, 7);
  ASSERT_EQ(21, r.GetArea()) << "    Triangle::GetArea should return 1/2 * width * height which is 21 for width 6, height 7.";
}

TEST(EllipseTest, Getters) {
  Ellipse r(5, 6);
  ASSERT_EQ(r.GetWidth(), 5) << "    The first thing passed to the ellipse "
      "constructor should be the width. Pass this to the Shape constructor.";
  ASSERT_EQ(r.GetHeight(), 6) << "    The second thing passed to the ellipse "
      "constructor should be the height. Pass this to the Shape constructor.";
}

TEST(EllipseTest, GetType) {
  Ellipse r(21, 28);
  ASSERT_EQ("ellipse", r.GetType()) << "    Ellipse::GetType should return \"ellipse\"";
}

TEST(EllipseTest, GetArea) {
  Ellipse r(6, 7);
  ASSERT_EQ(32, r.GetArea()) << "    Ellipse::GetArea should return 1/2 * width * 1/2 * height * 3.14159 which is 32 for width 6, height 7.";
}

TEST(PrintShapeInfoTest, Rectangle) {
  Rectangle r(8, 9);
  Shape& shape = r;
  std::streambuf* original_out = std::cout.rdbuf();
  std::stringstream stream_out;
  std::cout.rdbuf(stream_out.rdbuf());
  PrintShapeInfo(shape);
  std::cout.rdbuf(original_out);
  EXPECT_THAT(stream_out.str(), testing::HasSubstr("rectangle with area 72"))
      << "    PrintShapeInfo should cout the name of the Shape and its area. In "
      "the case of a Rectangle with width 8 and height 9, it should print \"rectangle with area 72\".";
}

TEST(PrintShapeInfoTest, Triangle) {
  Triangle r(4, 7);
  Shape& shape = r;
  std::streambuf* original_out = std::cout.rdbuf();
  std::stringstream stream_out;
  std::cout.rdbuf(stream_out.rdbuf());
  PrintShapeInfo(shape);
  std::cout.rdbuf(original_out);
  EXPECT_THAT(stream_out.str(), testing::HasSubstr("triangle with area 14"))
      << "    PrintShapeInfo should cout the name of the Shape and its area. In "
      "the case of a Triangle with width 4 and height 7, it should print \"triangle with area 14\".";
}

TEST(PrintShapeInfoTest, Ellipse) {
  Ellipse r(5, 8);
  Shape& shape = r;
  std::streambuf* original_out = std::cout.rdbuf();
  std::stringstream stream_out;
  std::cout.rdbuf(stream_out.rdbuf());
  PrintShapeInfo(shape);
  std::cout.rdbuf(original_out);
  EXPECT_THAT(stream_out.str(), testing::HasSubstr("ellipse with area 31"))
      << "    PrintShapeInfo should cout the name of the Shape and its area. In "
      "the case of a Ellipse with width 5 and height 8, it should print \"ellipse with area 31\".";
}

TEST(MainTest, ExecutesAndExits) {
  // Note: ASSERT_EXECEXIT does not fail when it passes *more* inputs
  // than the program asked for.
  // This will pass even with just the starter code (i.e. if the radius
  // is unused.)
  std::string user_input = "5\n10\n";
  ASSERT_EXECEXIT("main", user_input, 3)
      << "      Your program should ask for the width and height";
}

TEST(MainTest, OutputRectangle) {
  std::string user_input = "10\n10\n";
  ASSERT_DURATION_LE(3, {
      ASSERT_EXECTHAT(
          "main", user_input,
          HasSubstr("rectangle with area 100")) <<
          "    Should print rectangle name and area using PrintShapeInfo.";
    });
}

TEST(MainTest, OutputTriangle) {
  std::string user_input = "20\n20\n";
  ASSERT_DURATION_LE(3, {
      ASSERT_EXECTHAT(
          "main", user_input,
          HasSubstr("triangle with area 200")) <<
          "    Should print ellipse name and area using PrintShapeInfo.";
    });
}

TEST(MainTest, OutputEllipse) {
  std::string user_input = "10\n20\n";
  ASSERT_DURATION_LE(3, {
      ASSERT_EXECTHAT(
          "main", user_input,
          HasSubstr("ellipse with area 157")) <<
          "    Should print ellipse name and area using PrintShapeInfo.";
    });
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
