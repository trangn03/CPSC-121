#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../cppaudit/gtest_ext.h"
#include "../../print_vector_reverse.h"

using ::testing::HasSubstr;

TEST(PrintVectorReverse, EmptyVector) {
  std::vector<int> unittest_vector;
  ASSERT_DURATION_LE(3, {
    SIMULATE_SIO("", PrintVectorReverse(&unittest_vector), {
      ASSERT_THAT(your_output, HasSubstr("no contents"))
        << "Hint: The member function should tell the user that the vector does not have any contents.";
    })
  })
}

TEST(PrintVectorReverse, OneElement) {
  std::vector<int> unittest_vector{4};
  ASSERT_DURATION_LE(3, {
    SIMULATE_SIO("", PrintVectorReverse(&unittest_vector), {
      ASSERT_THAT(your_output, HasSubstr("4"))
        << "Hint: The member function should display 4 as the reverse of the vector.";
    })
  })
}

TEST(PrintVectorReverse, MultipleElements) {
  std::vector<int> unittest_vector{4, 1, 6, 2, 3};
  ASSERT_DURATION_LE(3, {
    SIMULATE_SIO("", PrintVectorReverse(&unittest_vector), {
      ASSERT_THAT(your_output, HasSubstr("3 2 6 1 4"))
        << "Hint: The member function should display 3 2 6 1 4 as the reversed vector when given 4 1 6 2 3.";
    })
  })
}

TEST(UserInput, AskInput) {
  std::string user_input = "3\n3\n2\n4\n";
  ASSERT_EXECEXIT("main", user_input, 3)
    << "      Your program should ask for the number of elements, in this case 3, and then the 3 values.";
}

TEST(Driver, NoContents) {
  std::string user_input = "0\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("no contents"))
    << "      Your program should show an error message when the user sets the number of elements to 0.";
}

TEST(Driver, PrintVectorReverse) {
  std::string user_input = "5\n3\n2\n4\n1\n8\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("8 1 4 2 3"))
    << "      Your program should display the vector in reverse, namely 8 1 4 2 3 5.";
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
