#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../cppaudit/gtest_ext.h"
#include "../../cpputils/graphics/test/image_test_utils.h"

using ::testing::HasSubstr;

void CheckImageColor(std::string image, graphics::Color color) {
  graphics::Image actual;
  ASSERT_TRUE(actual.Load(image)) << "    Could not load the image you saved.";
  EXPECT_TRUE(actual.GetWidth() > 0) << "    Image width should be bigger than 0.";
  EXPECT_TRUE(actual.GetHeight() > 0) << "    Image height should be bigger than 0.";
  for (int i = 0; i < actual.GetWidth(); i++) {
    for (int j = 0; j < actual.GetHeight(); j++) {
      ASSERT_EQ(actual.GetColor(i, j), color)
        << "    Found a pixel of the wrong color at (" << i << ", " << j << ")";
    }
  }
}
class HexImageTest : public ::testing::Test {
public:
  HexImageTest() {}

  bool FileCreated() {
    std::ifstream stream;
    stream.open(filename_);
    bool created = stream.good();
    stream.close();
    return created;
  }

protected:
  void SetUp(std::string filename) {
    filename_ = filename;
    std::ifstream my_empty_file;
    my_empty_file.open(filename_);
    if (my_empty_file.good()) {
      rename(filename_.c_str(), (PREFIX + filename_).c_str());
      file_exists = true;
    }
    my_empty_file.close();
  }

  void TearDown() override {
    if (file_exists) {
      rename((PREFIX + filename_).c_str(), filename_.c_str());
    } else {
      remove(filename_.c_str());
    }
  }
  const std::string PREFIX{"u_test"};
  bool file_exists = false;
  std::string filename_ = "";
};

TEST_F(HexImageTest, ExecutesAndExits) {
  SetUp("32a852.bmp");
  std::string user_input = "32a852\n";
  ASSERT_EXECEXIT("main", user_input, 3)
      << "      Your program should ask for a hex color.";
  EXPECT_TRUE(FileCreated()) << "Your program should save a file based on user input.";
}

TEST_F(HexImageTest, TellsUserAboutOutputImage) {
  SetUp("32a851.bmp");
  std::string user_input = "32a851\n";
  ASSERT_DURATION_LE(3, {
      ASSERT_EXECTHAT(
          "main", user_input,
          HasSubstr("32a851.bmp")) <<
          "Hint: Ensure you tell the user the filename at which you will save "
          "their image. For input 32a852 it should be 32a852.bmp.";
    });
}

TEST_F(HexImageTest, ImageContainsCorrectColorWithWhite) {
  SetUp("ffffff.bmp");
  std::string user_input = "ffffff\n";
  ASSERT_EXECEXIT("main", user_input, 3)
      << "      Your program should ask for a hex color.";
  CheckImageColor("ffffff.bmp", graphics::Color(255, 255, 255));
}

TEST_F(HexImageTest, ImageContainsCorrectColorWithBlack) {
  SetUp("000000.bmp");
  std::string user_input = "000000\n";
  ASSERT_EXECEXIT("main", user_input, 3)
      << "      Your program should ask for a hex color.";
  CheckImageColor("000000.bmp", graphics::Color(0, 0, 0));
}

TEST_F(HexImageTest, ImageContainsOnlyCorrectColor) {
  SetUp("31a852.bmp");
  std::string user_input = "31a852\n";
  ASSERT_EXECEXIT("main", user_input, 3)
      << "      Your program should ask for a hex color.";
  ASSERT_TRUE(FileCreated()) << "Your program should save a file based on user input.";
  graphics::Color color(49, 168, 82);
  CheckImageColor("31a852.bmp", color);
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
