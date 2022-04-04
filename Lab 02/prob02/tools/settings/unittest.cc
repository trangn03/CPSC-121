#include <string>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../cppaudit/gtest_ext.h"
#include "../../input.h"

TEST(GetYesOrNoInputTest, ReturnsFalseWhenNoIsEntered) {
  std::streambuf* original = std::cin.rdbuf();
  std::istringstream stream("no\n");
  std::cin.rdbuf(stream.rdbuf());
  EXPECT_FALSE(GetYesOrNoInput()) << "    Should return false when \"no\" is entered.";
  std::cin.rdbuf(original);
}

TEST(GetYesOrNoInputTest, ReturnsTrueWhenYesIsEntered) {
  std::streambuf* original = std::cin.rdbuf();
  std::istringstream stream("yes\n");
  std::cin.rdbuf(stream.rdbuf());
  EXPECT_TRUE(GetYesOrNoInput()) << "    Should return true when \"yes\" is entered.";
  std::cin.rdbuf(original);
}

TEST(GetYesOrNoInputTest, AsksWhenUnrecognizedInputIsEnteredYes) {
  std::streambuf* original = std::cin.rdbuf();
  std::istringstream stream("cats\n3\n\nyes\n");
  std::cin.rdbuf(stream.rdbuf());

  std::streambuf* original_out = std::cout.rdbuf();
  std::stringstream stream_out;
  std::cout.rdbuf(stream_out.rdbuf());

  EXPECT_TRUE(GetYesOrNoInput()) << "    Should return true when \"yes\" is "
      << "entered even after some invalid entries.";

  std::cin.rdbuf(original);
  std::cout.rdbuf(original_out);
  EXPECT_THAT(stream_out.str(), testing::HasSubstr("I didn't understand. Try again"))
      << "    You should let the user know they need to try again exactly as "
      << "defined in the README.";
}

TEST(GetYesOrNoInputTest, AsksWhenUnrecognizedInputIsEnteredNo) {
  std::streambuf* original = std::cin.rdbuf();
  std::istringstream stream("3.1415\npuppies\nYES\nno\n");
  std::cin.rdbuf(stream.rdbuf());

  std::streambuf* original_out = std::cout.rdbuf();
  std::stringstream stream_out;
  std::cout.rdbuf(stream_out.rdbuf());

  EXPECT_FALSE(GetYesOrNoInput()) << "    Should return false when \"no\" is "
      << "entered even after some invalid entries.";

  std::cin.rdbuf(original);
  std::cout.rdbuf(original_out);
  EXPECT_THAT(stream_out.str(), testing::HasSubstr("I didn't understand. Try again"))
      << "    You should let the user know they need to try again exactly as "
      << "defined in the README.";
}

TEST(IntegrationTest, LikesCookies) {
  std::string user_input = "Vega\nRadish\nI love cookies\nyes\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, testing::MatchesRegex(
      ".*Do you like chocolate chip cookies?.*I didn't understand.*I didn't understand.*I didn't understand.*Yummy.*"))
      << "Your program should ask the user for yes/no input and print \"I "
      << "didn't understand\" until it gets a \"yes\", then it should update "
      << "the boolean and print the appropriate message.";
  })
}

TEST(IntegrationTest, DoesNotLikeCookies) {
  std::string user_input = "no\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, testing::MatchesRegex(
      ".*Do you like chocolate chip cookies?.*To each their own.*"))
      << "Your program should ask the user for yes/no input and when it gets "
      << "a \"no\" then it should update the boolean and print the appropriate message.";
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
