#include <string>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../cppaudit/gtest_ext.h"

using std::string;
using ::testing::MatchesRegex;

TEST(MadLibsTest, ExecutesAndExitsWithInput) {
  string user_input = "Vega\nsleepy\ncat\n42\nX\n1.618\nRadish\n";
  ASSERT_EXECEXIT("main", user_input, 3)
    << "      Your program should ask the user for a name, emotion, animal, number, character, "
    << "percentage, and another name.";
}

TEST(MadLibsTest, UsesNameWithComma) {
  string user_input = "Vega\nsleepy\ncat\n42\nX\n1.618\nRadish\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, MatchesRegex(
      ".*Dear Vega,.*"))
      << "Story should start with \"Dear Vega,\", when the first input from the user is \"Vega\", "
      << "check your spacing and commas.";
  })
}

TEST(MadLibsTest, UsesEmotionWithSpaces) {
  string user_input = "Vega\nhappy\ncat\n42\nX\n1.618\nRadish\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, MatchesRegex(
      ".*I am happy that I was not able to complete my homework on time.*"))
      << "Story should include \"I am happy that I was not able to complete my homework on time\" "
      << "when the second string from the user is \"happy\".";
  })
}

TEST(MadLibsTest, UsesAnimalWithSpaces) {
  string user_input = "Vega\nhappy\ndolphin\n42\nX\n1.618\nRadish\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, MatchesRegex(
      ".*My pet dolphin ate my textbook.*"))
      << "Story should include \"My pet dolphin ate my textbook\" "
      << "when the third input from the user is \"dolphin\".";
  })
}

TEST(MadLibsTest, UsesIntegerWithSpaces) {
  string user_input = "Vega\nhappy\ndolphin\n34\nY\n1.618\nRadish\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, MatchesRegex(
      ".*able to retrieve 34 pages from its jaws.*"))
      << "Story should include \"able to retrieve 34 pages from its jaws\" "
      << "when the integer input from the user is \"34\".";
  })
}

TEST(MadLibsTest, UsesCharacterWithSpaces) {
  string user_input = "Vega\nhappy\ndolphin\n42\nY\n1.618\nRadish\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, MatchesRegex(
      ".*at least a Y grade because.*"))
      << "Story should include \"at least a Y grade because\" "
      << "when the character input from the user is \"Y\".";
  })
}

TEST(MadLibsTest, UsesDoubleWithSpaceandPercentage) {
  string user_input = "Vega\nhappy\ndolphin\n34\nY\n76.54\nRadish\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, MatchesRegex(
      ".*because I've done 76.54% of.*"))
      << "Story should include \"because I've done 76.54% of\" "
      << "when the double input from the user is \"76.54\". Make sure there is no space after the "
      << "double and before the percentage sign.";
  })
}

TEST(MadLibsTest, UsesSecondName) {
  string user_input = "Vega\nhappy\ndolphin\n34\nY\n76.54\nSuki\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, MatchesRegex(
      ".*Sincerely,[ ]*\nSuki.*$"))
      << "Story should conclude with \"Sincerely,\\nSuki\" "
      << "when the second name from the user is \"Suki\". Note the newline character, \\n, "
      <<"after \"Sincerely,\".";
  })
}

TEST(MadLibsTest, BuildsFullMadLib) {
  string user_input = "Vega\nsleepy\ncat\n42\nX\n1.618\nRadish\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, MatchesRegex(
      ".*Dear Vega,[ \n]+I am[ \n]+sleepy[ \n]+that I was not able to complete my homework on time. "
      "My pet[ \n]+cat[ \n]+ate my textbook, and I was only able to retrieve[ \n]+42[ \n]+pages "
      "from its jaws. I hope I can get at least a[ \n]+X[ \n]+grade because I've done[ \n]+1.618% "
      "of the work.[ \n]+Sincerely,[ \n]+Radish[ \n]*$"))
      << "Creates the full story from README.md.";
  })
}

/**/

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
