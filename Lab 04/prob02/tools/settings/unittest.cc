#include <string>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../cppaudit/gtest_ext.h"
#include "../../cpputils/graphics/test/image_test_utils.h"

using ::testing::HasSubstr;
using ::testing::MatchesRegex;

// Use UnitTestFileManager which renames any existing files
// during the test so they are not clobbered.
class BubbleImageTest : public UnitTestFileManager {
 public:
  BubbleImageTest() : UnitTestFileManager("bubbles.bmp") {};

  bool FileCreated() {
    std::ifstream stream;
    stream.open(filename_);
    bool created = stream.good();
    stream.close();
    return created;
  }

  void CreateBubblesFromInput(std::string user_input) {
    ASSERT_EXECEXIT("main", user_input, 3)
        << "      Your program should ask the user how many bubbles they want to "
        << "make and then the color, size and location for each bubble. The "
        << "starter code should already do this, so if you see this message you "
        << "may have edited part of `main.cc` which you should revert.";
    EXPECT_TRUE(FileCreated()) << "Your program should save bubbles.bmp. "
        << "``main.cc`` should already do this so if you see this message you "
        << "may have made a change which you need to revert.";
  }
};

TEST_F(BubbleImageTest, ExecutesAndExits) {
  std::string user_input = "1\nblue\n10\n20\n20";
  CreateBubblesFromInput(user_input);
}

TEST_F(BubbleImageTest, CreatesSimpleBubble) {
  std::string diff_image = "expected_v_actual_CreatesSimpleBubble.bmp";
  remove(diff_image.c_str());

  std::string user_input = "1\nblue\n30\n30\n30";
  CreateBubblesFromInput(user_input);
  graphics::Image actual;
  ASSERT_TRUE(actual.Load("bubbles.bmp"));
  ASSERT_EQ(actual.GetWidth(), 500) << "Image should be 500 wide. Do not change kImageSize.";
  ASSERT_EQ(actual.GetWidth(), 500) << "Image should be 500 wide. Do not change kImageSize.";
  graphics::Image expected(500, 500);
  expected.DrawCircle(30, 30, 30, graphics::Color(0, 0, 255));

  bool match = ImagesMatch(&expected, &actual, diff_image,
      DiffType::kTypeSideBySide);
  EXPECT_TRUE(match) << "bubbles.bmp is not quite right for size 30, "
      << "x = 30 and y = 30. See " << diff_image;
}

TEST_F(BubbleImageTest, BubbleWithUnequalInts) {
  std::string diff_image = "expected_v_actual_BubbleWithUnequalInts.bmp";
  remove(diff_image.c_str());

  std::string user_input = "1\nteal\n50\n300\n400";
  CreateBubblesFromInput(user_input);
  graphics::Image actual;
  ASSERT_TRUE(actual.Load("bubbles.bmp"));
  graphics::Image expected(500, 500);
  expected.DrawCircle(300, 400, 50, graphics::Color(0, 255, 255));

  bool match = ImagesMatch(&expected, &actual, diff_image,
      DiffType::kTypeSideBySide);
  EXPECT_TRUE(match) << "bubbles.bmp is not quite right for size 50, "
      << "x = 300, and y = 400. See " << diff_image;
}

TEST_F(BubbleImageTest, MultipleBubbles) {
  std::string diff_image = "expected_v_actual_MultipleBubbles.bmp";
  remove(diff_image.c_str());

  std::string user_input = "3\nyellow\n200\n250\n250\ngreen\n75\n37\n42\nred\n5\n400\n42";
  CreateBubblesFromInput(user_input);
  graphics::Image actual;
  ASSERT_TRUE(actual.Load("bubbles.bmp"));
  graphics::Image expected(500, 500);
  expected.DrawCircle(250, 250, 200, graphics::Color(255, 255, 0));
  expected.DrawCircle(37, 42, 75, graphics::Color(0, 255, 0));
  expected.DrawCircle(400, 42, 5, graphics::Color(255, 0, 0));

  bool match = ImagesMatch(&expected, &actual, diff_image,
      DiffType::kTypeSideBySide);
  EXPECT_TRUE(match) << "bubbles.bmp is not quite right for three bubbles, "
      << "size 200 at (250, 250), size 75 at (37, 42) and size 5 at (400, 42). "
      << "See " << diff_image;
}

TEST(BubbleTest, BubbleToString) {
  std::string user_input = "1\nyellow\n200\n250\n300\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, HasSubstr(
      "Bubble at (250, 300) with size 200"))
      << "    You should cout the bubbles in the vector to the terminal using "
      << "the method which returns a std::string. In this case for a yellow "
      << "bubble with size 200 and x of 250 and y of 300, it should print:\n"
      << "Bubble at (250, 300) with size 200";
  })
}

TEST(BubbleTest, BubblesToString) {
  std::string user_input = "3\nyellow\n200\n300\n250\ngreen\n75\n37\n42\nred\n5\n400\n42";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, HasSubstr(
      "Bubble at (300, 250) with size 200"))
      << "    You should cout the bubbles in the vector to the terminal using "
      << "the method which returns a std::string. For the first bubble it should print\n"
      << "Bubble at (300, 250) with size 200";
  })
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, HasSubstr(
      "Bubble at (37, 42) with size 75"))
      << "    You should cout the bubbles in the vector to the terminal using "
      << "the method which returns a std::string. For the second bubble it should print\n"
      << "Bubble at (37, 42) with size 75";
  })
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, HasSubstr(
      "Bubble at (400, 42) with size 5"))
      << "    You should cout the bubbles in the vector to the terminal using "
      << "the method which returns a std::string. For the third bubble it should print\n"
      << "Bubble at (400, 42) with size 5";
  })
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
