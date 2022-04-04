#include <string>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../cppaudit/gtest_ext.h"
#include "../cppaudit/image_test_utils.h"
#include "../../mirror.h"
#include "../../cpputils/graphics/image.h"

const graphics::Color white(255, 255, 255);
const graphics::Color red(255, 0, 0);

TEST(MirrorTest, Mirror1x1Image) {
  graphics::Image image(1, 1);
  image.SetColor(0, 0, red);
  Mirror(image);
  EXPECT_EQ(image.GetColor(0, 0), red)
      << "    Mirror should not modify a 1x1 pixel image.";
}

TEST(MirrorTest, Mirror3x1Image) {
  remove("mirror_3px.bmp");
  graphics::Image image(3, 1);
  image.SetColor(0, 0, red);
  Mirror(image);
  bool correct = image.GetColor(2, 0) == red && image.GetColor(0, 0) == white &&
      image.GetColor(1, 0) == white;
  EXPECT_TRUE(correct)
      << "    On a 3x1 image, mirror should move the color of the pixel at "
      << "(0, 0) to (2, 0) and the color at (2, 0) to (0, 0). See "
      << "mirror_3px.bmp which is the result after running Mirror on an image "
      << "where the left pixel was red and the center and right pixels were "
      << "white.";
  if (!correct) image.SaveImageBmp("mirror_3px.bmp");
}

TEST(MirrorTest, MirrorsInterestingImageOddWidth) {
  remove("odd_expected_vs_actual.bmp");
  graphics::Image image(101, 101);
  graphics::Color color1(66, 135, 245);
  graphics::Color color2(235, 64, 52);
  graphics::Color color3(50, 168, 82);
  image.DrawRectangle(5, 5, 10, 60, color1);
  image.DrawCircle(60, 60, 30, color2);
  image.DrawLine(50, 10, 50, 90, color3);
  Mirror(image);

  graphics::Image expected(101, 101);
  expected.DrawRectangle(85, 5, 10, 60, color1);
  expected.DrawCircle(40, 60, 30, color2);
  expected.DrawLine(50, 10, 50, 90, color3);

  EXPECT_TRUE(ImagesMatch(&expected, &image,
      "odd_expected_vs_actual.bmp", DiffType::kTypeSideBySide))
      << "    Should mirror an image with odd width. See "
      << "odd_expected_vs_actual.bmp to see what went wrong. There's a "
      << "vertial line at the center of the image.";
}

TEST(MirrorTest, Mirror2x1Image) {
  remove("mirror_2px.bmp");
  graphics::Image image(2, 1);
  image.SetColor(0, 0, red);
  Mirror(image);
  bool correct = image.GetColor(1, 0) == red && image.GetColor(0, 0) == white;
  EXPECT_TRUE(correct)
      << "    On a 2x1 image, mirror should move the color of the pixel at "
      << "(0, 0) to (1, 0), and the color of the pixel at (1, 0) to (0, 0). "
      << "See mirror_2px.bmp which is the result after running Mirror on an "
      << "image where the left pixel was red and the right pixel was white.";
  if (!correct) image.SaveImageBmp("mirror_2px.bmp");
}

TEST(MirrorTest, MirrorsInterestingImageEvenWidth) {
  remove("even_expected_vs_actual.bmp");
  graphics::Image image(100, 100);
  graphics::Color color1(66, 135, 245);
  graphics::Color color2(235, 64, 52);
  graphics::Color color3(50, 168, 82);
  image.DrawRectangle(5, 5, 10, 60, color1);
  image.DrawCircle(60, 60, 30, color2);
  image.DrawLine(50, 10, 50, 90, color3);
  Mirror(image);

  graphics::Image expected(100, 100);
  expected.DrawRectangle(84, 5, 10, 60, color1);
  expected.DrawCircle(39, 60, 30, color2);
  expected.DrawLine(49, 10, 49, 90, color3);

  EXPECT_TRUE(ImagesMatch(&expected, &image,
      "even_expected_vs_actual.bmp", DiffType::kTypeSideBySide))
      << "    Should mirror an image with even width. See "
      << "odd_expected_vs_actual.bmp to see what went wrong. There's a "
      << "vertial line on the right side of the center of the image.";
}

TEST(MirrorTest, DoesNotGoOutOfBounds) {
  graphics::Image image(10, 10);
  image.DrawLine(0, 0, 9, 9, graphics::Color(25, 76, 234));

  // https://stackoverflow.com/questions/3803465/how-to-capture-stdout-stderr-with-googletest
  std::streambuf* original = std::cout.rdbuf();
  std::stringstream stream;
  std::cout.rdbuf(stream.rdbuf());

  Mirror(image);

  std::cout.rdbuf(original);
  EXPECT_THAT(stream.str(), Not(testing::HasSubstr("is out of bounds.")))
      << "    You should not try to access pixels out of the image bounds.";
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
