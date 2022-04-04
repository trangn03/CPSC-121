#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <vector>
#include "../../linear_search.h"
#include "../cppaudit/gtest_ext.h"

using ::testing::HasSubstr;

TEST(LinearSearchTest, InvalidIndex) {
  std::vector<int> number_array{3, 16, 22, 8, 11, 0, 55, 34, 27, 31};
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(LinearSearch(number_array, 5, 10), -1)
      << "   The function should return -1 if the index to search into the "
      << "array is invalid (in this case, larger than the biggest index in the array).";
  })
}

TEST(LinearSearchTest, EmptyArray) {
  std::vector<int> number_array;
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(LinearSearch(number_array, 5, 0), -1)
      << "   The function should return -1 if the index to search into the "
      << "array is invalid (in this case, the array is empty).";
  })
}

TEST(LinearSearchTest, OneElementPresent) {
  std::vector<int> number_array{3};
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(LinearSearch(number_array, 3, 0), 0)
      << "   The function should return 0 as the index of 3 given the array "
      << "with only one element, [3].";
  })
}

TEST(LinearSearchTest, OneElementNotPresent) {
  std::vector<int> number_array{3};
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(LinearSearch(number_array, 2, 0), -1)
      << "   The function should return -1 because 2 is not in the vector given the vector [3].";
  })
}

TEST(LinearSearchTest, MultiElementArrayPresent) {
  std::vector<int> number_array{3, 16, 22, 8, 11, 0, 55, 34, 27, 31};
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(LinearSearch(number_array, 8, 0), 3)
      << "   The function should return 3 as the index of 8 given the array [3, 16, 22, 8, 11, 0, 55, 34, 27, 31].";
  })
}

TEST(LinearSearchTest, MultiElementArrayFirstElement) {
  std::vector<int> number_array{3, 16, 22, 8, 11, 0, 55, 34, 27, 31};
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(LinearSearch(number_array, 3, 0), 0)
      << "   The function should return 0 as the index of 3 given the array [3, 16, 22, 8, 11, 0, 55, 34, 27, 31].";
  })
}

TEST(LinearSearchTest, MultiElementArraySecondElement) {
  std::vector<int> number_array{3, 16, 22, 8, 11, 0, 55, 34, 27, 31};
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(LinearSearch(number_array, 16, 0), 1)
      << "   The function should return 1 as the index of 16 given the array [3, 16, 22, 8, 11, 0, 55, 34, 27, 31].";
  })
}

TEST(LinearSearchTest, MultiElementArrayMiddleElement) {
  std::vector<int> number_array{3, 16, 22, 8, 11, 0, 55, 34, 27, 31};
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(LinearSearch(number_array, 11, 0), 4)
      << "   The function should return 4 as the index of 11 given the array [3, 16, 22, 8, 11, 0, 55, 34, 27, 31].";
  })
}

TEST(LinearSearchTest, MultiElementArrayLastElement) {
  std::vector<int> number_array{3, 16, 22, 8, 11, 0, 55, 34, 27, 31};
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(LinearSearch(number_array, 31, 0), 9)
      << "   The function should return 9 as the index of 31 given the array [3, 16, 22, 8, 11, 0, 55, 34, 27, 31].";
  })
}

TEST(LinearSearchTest, MultiElementArrayNotPresent) {
  std::vector<int> number_array{0, 55, 34, 27, 31, 3, 16, 22, 8, 11};
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(LinearSearch(number_array, 6, 0), -1)
      << "   The function should return -1 because 6 is not in the array given the array [0, 55, 34, 27, 31, 3, 16, 22, 8, 11].";
  })
}

TEST(UserInput, AskSearchNumber) {
  std::string user_input = "5\n";
  ASSERT_EXECEXIT("main", user_input, 3)
    << "      Your program should ask for the number to search.";
}

TEST(Driver, NumberFound) {
  std::string user_input = "11\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("The index of 11 in the array is: 4"))
    << "      Your program should tell the user that the 11 is in index 4.";
}

TEST(Driver, NumberNotFound) {
  std::string user_input = "6\n";
  ASSERT_EXECTHAT("main", user_input, HasSubstr("is not in the array"))
    << "      Your program should tell the user that the number they are looking for is not in the array.";
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
