#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../cppaudit/gtest_ext.h"
#include "../../recursion.h"
#include <cmath>

// 1/3 of tests for each.
TEST(IsEvenTest, ZeroIsEven) {
  ASSERT_TRUE(IsEven(0)) << "    IsEven should return `true` for input 0. "
        "Hint: Maybe 0 should be the base case.";
}

TEST(IsEvenTest, OneIsOddAndTwoIsEven) {
  ASSERT_FALSE(IsEven(1)) << "    IsEven should return `false` for input 1.";
  ASSERT_TRUE(IsEven(2)) << "    IsEven should return `true` for input 2. ";
}

TEST(IsEvenTest, RandomIntegers) {
  for (int i = 0; i < 50; i++) {
    int value = rand() % 100;
    if (value % 2 == 0) {
      ASSERT_TRUE(IsEven(value)) << "    IsEven should return `true` for input " << value;
    } else {
      ASSERT_FALSE(IsEven(value)) << "    IsEven should return `false` for input " << value;
    }
  }
}

TEST(RaiseIntToPowerTest, ZeroToAnyPowerIsAlwaysZero) {
  ASSERT_EQ(0, RaiseIntToPower(0, 1)) << "   Zero raised to any power is zero. Check your base case.";
  ASSERT_EQ(0, RaiseIntToPower(0, 5))  << "   Zero raised to any power is zero. Check your base case.";
}

TEST(RaiseIntToPowerTest, AnythingToZeroPowerIsOne) {
  ASSERT_EQ(1, RaiseIntToPower(1, 0)) << "   1 ^ 0 is 1. Check your base case.";
  ASSERT_EQ(1, RaiseIntToPower(5, 0))  << "   5 ^ 0 is 1. Check your base case.";
}

TEST(RaiseIntToPowerTest, AnythingRaisedToOneIsItself) {
  for (int i = 0; i < 10; i++) {
    int value = rand() % 100 + 1;
    ASSERT_EQ(value, RaiseIntToPower(value, 1)) << value << " ^ 1 is " << value;
  }
}

TEST(RaiseIntToPowerTest, RandomIntegers) {
  for (int i = 0; i < 10; i++) {
    // Use some random numbers, but nothing way too large.
    int value = rand() % 10 + 1;
    int power = rand() % 7 + 1;
    ASSERT_EQ(pow(value, power), RaiseIntToPower(value, power))
        << value << " ^ " << power << " is " << pow(value, power);
  }
}

TEST(SumArrayTest, EmptyArrayIsZero) {
  std::vector<int> array;
  ASSERT_EQ(0, SumArray(array, 0)) << "    For an empty array, SumArray should return 0. Check your base case.";
}

TEST(SumArrayTest, ArrayWithOneElementReturnsThatValue) {
  for (int i = 0; i < 10; i++) {
    std::vector<int> array;
    int value = rand() % 100;
    array.push_back(value);
    ASSERT_EQ(value, SumArray(array, 0)) << "    For an array with one element, SumArray should return the value of that single element.";
  }
}

TEST(SumArrayTest, ArrayWithSeveralElements) {
  for (int i = 0; i < 10; i++) {
    std::vector<int> array;
    int sum = 0;
    for (int i = 0; i < 10; i++) {
      int value = rand() % 20;
      sum += value;
      array.push_back(value);
    }
    ASSERT_EQ(sum, SumArray(array, 0)) << "    For an array with 10 elements, ["
        << array[0] << "," << array[1] << "," << array[2] << "," << array[3] << ","
        << array[4] << "," << array[5] << "," << array[6] << "," << array[7] << ","
        << array[8] << "," << array[9] << "], SumArray should add them all together and return the total.";
  }
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
