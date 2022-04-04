#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../cppaudit/gtest_ext.h"
#include "../../cpputils/graphics/test/image_test_utils.h"
#include "../../objects.h"

graphics::Color red(255, 0, 0);
graphics::Color green(0, 255, 0);
graphics::Color blue(0, 0, 255);
graphics::Color white(255, 255, 255);
graphics::Color paddle_color(50, 50, 50);
graphics::Color ball_color(210, 25, 25);


TEST(BrickTest, IsSolidObject) {
  bool is_solid_object = std::is_base_of<SolidObject, Brick>::value;
  ASSERT_TRUE(is_solid_object) << "    Brick should inherit from SolidObject";
}

TEST(BrickTest, WidthAndHeight) {
  graphics::Image image(100, 100);
  Brick b(10, 20, red, &image);
  ASSERT_EQ(10, b.GetWidth()) << "    First parameter to Brick constructor is "
      "width, which should be passed first to SolidObject constructor and stored as a "
      "member variable.";
  ASSERT_EQ(20, b.GetHeight()) << "    Second parameter to Brick constructor is "
      "height, which should be passed second to SolidObject constructor and stored as a "
      "member variable.";
}

TEST(BrickTest, SetAndGetXAndY) {
  graphics::Image image(100, 100);
  Brick b(20, 30, green, &image);
  b.SetX(30);
  ASSERT_EQ(30, b.GetX()) << "    SolidObject::SetX should save the x coordinate "
      "in a member variable, returned with SolidObject::GetX. Brick should not "
      "override these methods.";
  b.SetY(40);
  ASSERT_EQ(40, b.GetY()) << "    SolidObject::SetY should save the y coordinate "
      "in a member variable, returned with SolidObject::GetY. Brick should not "
      "override these methods.";
}

TEST(BrickTest, Draw) {
  std::string filename = "BrickTestDraw_expected_v_actual.bmp";
  remove(filename.c_str());
  graphics::Image image(100, 100);
  Brick b(70, 50, blue, &image);
  b.SetX(10);
  b.SetY(20);
  b.Draw();
  graphics::Image expected(100, 100);
  expected.DrawRectangle(10, 20, 70, 50, blue);
  bool match = ImagesMatch(&expected, &image, filename, DiffType::kTypeSideBySide);
  EXPECT_TRUE(match) << "Your Brick::Draw function is not quite right. You should "
  "call DrawRectangle(GetX(), GetY(), GetWidth(), GetHeight(), color_) where "
  "color_ was passed in the Brick constructor. See a side-by-side comparison at " << filename;
}

TEST(PaddleTest, IsSolidObject) {
  bool is_solid_object = std::is_base_of<SolidObject, Paddle>::value;
  ASSERT_TRUE(is_solid_object) << "    Paddle should inherit from SolidObject";
  bool is_brick = std::is_base_of<Brick, Paddle>::value;
  ASSERT_TRUE(is_brick) << "    Paddle should inherit from Brick";
}


TEST(PaddleTest, WidthAndHeight) {
  graphics::Image image(100, 100);
  Paddle p(5, 10, &image);
  ASSERT_EQ(5, p.GetWidth()) << "    First parameter to Paddle constructor is "
      "width, which should be passed first to Brick constructor and stored as a "
      "member variable.";
  ASSERT_EQ(10, p.GetHeight()) << "    Second parameter to Paddle constructor is "
      "height, which should be passed second to Brick constructor and stored as a "
      "member variable.";
}

TEST(PaddleTest, SetAndGetXAndY) {
  graphics::Image image(100, 100);
  Paddle p(15, 10, &image);
  p.SetX(42);
  ASSERT_EQ(42, p.GetX()) << "    SolidObject::SetX should save the x coordinate "
      "in a member variable, returned with SolidObject::GetX. Paddle should not "
      "override these methods.";
  p.SetY(49);
  ASSERT_EQ(49, p.GetY()) << "    SolidObject::SetY should save the y coordinate "
      "in a member variable, returned with SolidObject::GetY. Paddle should not "
      "override these methods.";
}

TEST(PaddleTest, Draw) {
  std::string filename = "PaddleTestDraw_expected_v_actual.bmp";
  remove(filename.c_str());
  graphics::Image image(100, 100);
  Paddle b(50, 30, &image);
  b.SetX(20);
  b.SetY(10);
  b.Draw();
  graphics::Image expected(100, 100);
  expected.DrawRectangle(20, 10, 50, 30, paddle_color);
  bool match = ImagesMatch(&expected, &image, filename, DiffType::kTypeSideBySide);
  EXPECT_TRUE(match) << "Paddle did not draw correctly. Make sure to use the "
    "graphics::Color(50, 50, 50) when initializing the Paddle as a Brick. "
    "See a side-by-side comparison at " << filename;
}

TEST(BallTest, IsSolidObject) {
  bool is_solid_object = std::is_base_of<SolidObject, Ball>::value;
  ASSERT_TRUE(is_solid_object) << "    Ball should inherit from SolidObject";
}

TEST(BallTest, WidthAndHeight) {
  graphics::Image image(100, 100);
  Ball b(15, &image);
  ASSERT_EQ(15, b.GetWidth()) << "    First parameter to Paddle constructor is "
      "diameter, which should be passed as width and height to the SolidObject "
      "constructor and stored as a member variable.";
  ASSERT_EQ(15, b.GetHeight()) << "    First parameter to Paddle constructor is "
      "diameter, which should be passed as width and height to the SolidObject "
      "constructor and stored as a member variable.";
}

TEST(BallTest, SetAndGetXAndY) {
  graphics::Image image(100, 100);
  Ball b(20, &image);
  b.SetX(35);
  ASSERT_EQ(35, b.GetX()) << "    SolidObject::SetX should save the x coordinate "
      "in a member variable, returned with SolidObject::GetX. Ball should not "
      "override these methods.";
  b.SetY(39);
  ASSERT_EQ(39, b.GetY()) << "    SolidObject::SetX should save the x coordinate "
      "in a member variable, returned with SolidObject::GetX. Ball should not "
      "override these methods.";
}

TEST(BallTest, Draw) {
  std::string filename = "PaddleTestDraw_expected_v_actual.bmp";
  remove(filename.c_str());
  graphics::Image image(100, 100);
  Ball b(50, &image);
  b.SetX(15);
  b.SetY(25);
  b.Draw();
  graphics::Image expected(100, 100);
  expected.DrawCircle(40, 50, 25, ball_color);
  bool match = ImagesMatch(&expected, &image, filename, DiffType::kTypeSideBySide);
  EXPECT_TRUE(match) << "Ball did not draw correctly. Make sure to use the "
    "graphics::Color(210, 25, 25) when drawing the Ball, and offset the (x, y) "
    "by half the width when using the DrawCircle function (which takes the (x, y) "
    "center of a circle as input). See a side-by-side comparison at " << filename;
}

TEST(CollidesWith, EmptySize) {
  graphics::Image image(100, 100);
  Paddle b1(0, 10, &image);
  Paddle b2(10, 10, &image);
  Paddle b3(10, 0, &image);
  b1.SetX(0);
  b1.SetY(0);
  b2.SetX(0);
  b2.SetY(0);
  ASSERT_FALSE(b1.CollidesWith(&b2)) << "    Cannot collide with an object when its own width is 0.";
  ASSERT_FALSE(b2.CollidesWith(&b1)) << "    Cannot collide with an object when the other object's width is 0.";
  ASSERT_FALSE(b3.CollidesWith(&b2)) << "    Cannot collide with an object when its own height is 0.";
  ASSERT_FALSE(b2.CollidesWith(&b3)) << "    Cannot collide with an object when the other object's height is 0.";
}

TEST(CollidesWithTest, DoesNotCollide) {
  graphics::Image image(100, 100);
  Brick b1(20, 30, red, &image);
  Brick b2(5, 5, red, &image);
  b1.SetX(0);
  b1.SetY(0);
  b2.SetX(50);
  b2.SetY(50);
  SolidObject* s1 = &b1;
  SolidObject* s2 = &b2;
  ASSERT_FALSE(s1->CollidesWith(s2)) << "    A 20x30 SolidObject at (0, 0) does not collide with a 5x5 SolidObject at (50, 50) (they would not overlap)";
  ASSERT_FALSE(s2->CollidesWith(s1)) << "    A 5x5 SolidObject at (50, 50) does not collide with a 20x30 SolidObject at (0, 0) (they would not overlap)";
}

TEST(CollidesWithTest, CollidesCompletely) {
  graphics::Image image(100, 100);
  Brick b1(20, 30, red, &image);
  Brick b2(5, 5, red, &image);
  b1.SetX(0);
  b1.SetY(0);
  b2.SetX(10);
  b2.SetY(10);
  SolidObject* s1 = &b1;
  SolidObject* s2 = &b2;
  ASSERT_TRUE(s1->CollidesWith(s2)) << "    A 20x30 SolidObject at (0, 0) does collide with a 5x5 SolidObject at (10, 10) (the second object fits fully within the first)";
  ASSERT_TRUE(s2->CollidesWith(s1)) << "    A 5x5 SolidObject at (10, 10) does collide with a 20x30 SolidObject at (0, 0) (the first object fits fully within the second)";
}

TEST(CollidesWithTest, CollidesOnOneSide) {
  graphics::Image image(100, 100);
  Brick b1(10, 10, red, &image);
  Brick b2(20, 8, red, &image);
  b1.SetX(5);
  b1.SetY(0);
  b2.SetX(10);
  b2.SetY(1);
  SolidObject* s1 = &b1;
  SolidObject* s2 = &b2;
  ASSERT_TRUE(s1->CollidesWith(s2)) << "    A 10x10 SolidObject at (5, 0) does collide with a 20x8 SolidObject at (10, 1) (the second object's left edge intersects with the right edge of the first)";
  ASSERT_TRUE(s2->CollidesWith(s1)) << "    A 20x8 SolidObject at (10, 1) does collide with a 10x10 SolidObject at (5, 0) (the first object's left edge intersects with the right edge of the second)";

  Brick b3(10, 10, red, &image);
  Brick b4(8, 20, red, &image);
  b3.SetX(0);
  b3.SetY(0);
  b4.SetX(1);
  b4.SetY(5);
  SolidObject* s3 = &b3;
  SolidObject* s4 = &b4;
  ASSERT_TRUE(s3->CollidesWith(s4)) << "    A 10x10 SolidObject at (0, 0) does collide with a 8x20 SolidObject at (1, 5) (the second object's top edge intersects with the bottom edge of the first)";
  ASSERT_TRUE(s4->CollidesWith(s3)) << "    A 8x20 SolidObject at (1, 5) does collide with a 10x10 SolidObject at (0, 0) (the first object's top edge intersects with the bottom edge of the second)";
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
