#include <string>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../cppaudit/gtest_ext.h"

using std::string;
using ::testing::HasSubstr;
using ::testing::MatchesRegex;

TEST(PizzaMakerTest, RunsWithInput) {
  string user_input = "1\n1\n1\n";
  ASSERT_EXECEXIT("main", user_input, 3)
    << "      Your program should ask the user for how many of three types of toppings to add to "
    << "their pizza.";
}

TEST(PizzaMakerTest, AsksUserForToppings) {
  string user_input = "1\n1\n1\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, MatchesRegex(
      ".*How many pepperoni do you want?.*How many onions do you want?.*How many jalapenos do you want?.*"))
        << "      Your program should ask the user for pepperoni, then onions, then jalapenos. "
        << "Ensure your output matches the examples in README.md.";
  })
}

TEST(PizzaMakerTest, CreatesSimplePizza) {
  string user_input = "1\n1\n1\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, MatchesRegex(
      ".*pepperoni onion jalapeno[ \n]*$"))
        << "      Your program should create \"pepperoni onion jalapeno\" when the user enters "
        << "1, 1 and 1.";
  })
}

TEST(PizzaMakerTest, PizzaWithOnlyPepperoni) {
  string user_input = "3\n0\n0\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, MatchesRegex(
      ".*pepperoni pepperoni pepperoni[ \n]*$"))
        << "      Your program should create \"pepperoni pepperoni pepperoni\" when the user enters "
        << "3, 0 and 0.";
  })
}

TEST(PizzaMakerTest, PizzaWithOnlyOnion) {
  string user_input = "0\n4\n0\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, MatchesRegex(
      ".*onion onion onion onion[ \n]*$"))
        << "      Your program should create \"onion onion onion onion\" when the user enters "
        << "0, 4 and 0.";
  })
}

TEST(PizzaMakerTest, PizzaWithOnlyJalapeno) {
  string user_input = "0\n0\n2\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, MatchesRegex(
      ".*jalapeno jalapeno[ \n]*$"))
        << "      Your program should create \"jalapeno jalapeno\" when the user enters "
        << "0, 0 and 2.";
  })
}

TEST(PizzaMakerTest, NoPizza) {
  string user_input = "0\n0\n0\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, HasSubstr(
      "Looks like you weren't hungry. Maybe next time?"))
        << "      Your program should print, \"Looks like you weren't hungry. Maybe next time?\" "
        << "when the user enters all zeros.";
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
