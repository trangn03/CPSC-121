#include <string>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../cppaudit/gtest_ext.h"
#include "../../cpputils/graphics/test/image_test_utils.h"
#include "../../desaturate.h"
#include "../../cpputils/graphics/image.h"

bool ChannelsAreEqual(int x, int y, int value, graphics::Image& image) {
  int red = image.GetRed(x, y);
  int green = image.GetGreen(x, y);
  int blue = image.GetBlue(x, y);
  EXPECT_EQ(red, value) << "    The red channel should become the "
      "average of the Red, Green and Blue channels.";
  EXPECT_EQ(green, value) << "    The green channel should become the "
      "average of the Red, Green and Blue channels.";
  EXPECT_EQ(blue, value) << "    The blue channel should become the "
      "average of the Red, Green and Blue channels.";
  return red == green && green == blue;
}

TEST(DesaturateTest, Desaturates1x1ImageRed) {
  graphics::Image image(1, 1);
  image.SetRed(0, 0, 255);
  image.SetGreen(0, 0, 0);
  image.SetBlue(0, 0, 0);
  Desaturate(image);
  EXPECT_TRUE(ChannelsAreEqual(0, 0, 85, image))
      << "    Should change a pixel from (255, 0, 0) to (85, 85, 85)";
}

TEST(DesaturateTest, Desaturates1x1ImageGreen) {
  graphics::Image image(1, 1);
  image.SetRed(0, 0, 0);
  image.SetGreen(0, 0, 255);
  image.SetBlue(0, 0, 0);
  Desaturate(image);
  EXPECT_TRUE(ChannelsAreEqual(0, 0, 85, image))
      << "    Should change a pixel from (0, 255, 0) to (85, 85, 85)";
}

TEST(DesaturateTest, Desaturates1x1ImageBlue) {
  graphics::Image image(1, 1);
  image.SetRed(0, 0, 0);
  image.SetGreen(0, 0, 0);
  image.SetBlue(0, 0, 255);
  Desaturate(image);
  EXPECT_TRUE(ChannelsAreEqual(0, 0, 85, image))
      << "    Should change a pixel from (0, 0, 255) to (85, 85, 85)";
}

TEST(DesaturateTest, DesaturatesColoredImage) {
  remove("expected_vs_actual.bmp");
  graphics::Image actual(100, 100);
  // Some colored shapes.
  actual.DrawCircle(50, 50, 30, 30, 60, 90);
  actual.DrawRectangle(70, 70, 20, 20, 30, 90, 150);
  actual.DrawCircle(75, 25, 10, 150, 90, 30);
  // black line for good measure.
  actual.DrawLine(2, 2, 90, 2, 0, 0, 0);

  graphics::Image expected(100, 100);
  expected.DrawCircle(50, 50, 30, 60, 60, 60);
  expected.DrawRectangle(70, 70, 20, 20, 90, 90, 90);
  expected.DrawCircle(75, 25, 10, 90, 90, 90);
  expected.DrawLine(2, 2, 90, 2, 0, 0, 0);

  Desaturate(actual);
  EXPECT_TRUE(ImagesMatch(&expected, &actual, "expected_vs_actual.bmp",
      DiffType::kTypeSideBySide)) << "   Should desaturate an image of colored "
          "shapes. See expected_vs_actual.bmp to see what went wrong.";
}

TEST(DesaturateTest, DoesNotGoOutOfBounds) {
  graphics::Image image(10, 10);
  image.DrawCircle(5, 5, 5, graphics::Color(25, 76, 234));

  // https://stackoverflow.com/questions/3803465/how-to-capture-stdout-stderr-with-googletest
  std::streambuf* original = std::cout.rdbuf();
  std::stringstream stream;
  std::cout.rdbuf(stream.rdbuf());

  Desaturate(image);

  std::cout.rdbuf(original);
  EXPECT_THAT(stream.str(), Not(testing::HasSubstr("is out of bounds.")))
      << "    You should not access pixels out of the image bounds.";
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
