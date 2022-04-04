#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../cppaudit/gtest_ext.h"
#include "../../header.h"

// Text generated from: https://pirateipsum.me/

using ::testing::HasSubstr;

TEST(UserInput, AskHeaderText) {
  std::string unittest_input = "Hello World!\n";
  ASSERT_EXECEXIT("main", unittest_input, 3)
    << "      Your program should ask for the header and display it.";
}

TEST(DisplayHeader, HeaderTest1) {
  std::string unittest_input = "Dance the hempen";
  std::string unittest_output = "********************\n"
                                "* Dance the hempen *\n"
                                "********************\n";
  SIMULATE_SIO("", DisplayHeader(unittest_input), {
    ASSERT_EQ(your_output, unittest_output) << "      Your function should display a rectangle surrounding the given text, Dance the hempen.";
  })
}


TEST(DisplayHeader, HeaderTest2) {
  std::string unittest_input = "Quarter spike take a caulk";
  std::string unittest_output = "******************************\n"
                                "* Quarter spike take a caulk *\n"
                                "******************************\n";
  SIMULATE_SIO("", DisplayHeader(unittest_input), {
    ASSERT_EQ(your_output, unittest_output) << "      Your function should display a rectangle surrounding the given text, uarter spike take a caulk.";
  })
}

TEST(WithinWidth, TextWithinWidth) {
  std::string unittest_input = "Doubloon red ensign Sail";
  ASSERT_TRUE(WithinWidth(unittest_input, 30))
      << "      Input: " << unittest_input << "\n      Your function should return true because the text is within the given length, 30.";
}

TEST(WithinWidth, TextExactlyTheWidth) {
  std::string unittest_input = "Blimey gaff spyglass";
  ASSERT_TRUE(WithinWidth(unittest_input, 24))
      << "      Input: " << unittest_input << "\n      Your function should return true because the text is within the given length, 24.";
}

TEST(WithinWidth, TextOverWidth) {
  std::string unittest_input = "Rum reef maroon jolly boat schooner spirits gangway gangplank Davy Jones' Locker Privateer.";
  ASSERT_FALSE(WithinWidth(unittest_input, 80))
      << "      Input: " << unittest_input << "\n      Your function should return false because the text is over the given length, 80.";
}

TEST(Driver, ShowHeader) {
  std::string unittest_input = "Hello World!\n";
  std::string unittest_output = "****************\n"
                                "* Hello World! *\n"
                                "****************\n";
  ASSERT_EXECTHAT("main", unittest_input, HasSubstr(unittest_output))
      << "      Your program should display a rectangle surrounding the given text.";
}

TEST(Driver, DontShowHeader) {
  std::string unittest_input = "Doubloon Admiral of the Black loaded to the gunwalls coffer lugger parrel scourge of the seven seas lass fire in the hole blow the man down";
  std::string unittest_output = "Doubloon Admiral of the Black loaded to the gunwalls coffer lugger parrel scourge of the seven seas lass fire in the hole blow the man down";
  ASSERT_EXECTHAT("main", unittest_input, Not(HasSubstr("****************")))
      << "      Your program should not display a rectangle surrounding the given text because it exceeds the specified text length, 80.";
  ASSERT_EXECTHAT("main", unittest_input, HasSubstr(unittest_output))
      << "      Your program should display only the text because it exceeds specified text length, 80.";

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
