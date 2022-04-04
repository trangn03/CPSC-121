#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../cppaudit/gtest_ext.h"
#include "../../pointer_utils.h"

using ::testing::HasSubstr;

TEST(NegateTest, NegatesTrue) {
  bool value = true;
  Negate(&value);
  EXPECT_FALSE(value) << "    The Negate function should make a true into a false.";
}

TEST(NegateTest, NegatesFalse) {
  bool value = false;
  Negate(&value);
  EXPECT_TRUE(value) << "    The Negate function should make a false into a true.";
}

TEST(IncrementTest, IncrementsZero) {
  int value = 0;
  Increment(&value);
  ASSERT_EQ(1, value) << "    The Increment function should add one to the number pointed at in the input parameter.";
}

TEST(IncrementTest, IncrementManyNumbers) {
  int value = -15;
  for (int i = 0; i < 50; i+= 3) {
    int value = i;
    Increment(&value);
    ASSERT_EQ(i + 1, value) << "    The Increment function should add one to the number pointed at in the input parameter.";
  }
}

TEST(ComputeSumTest, OneAndOneIsTwo) {
  double v1 = 1;
  double v2 = 1;
  ASSERT_EQ(2, ComputeSum(&v1, &v2)) << "    The ComputeSum function should add the doubles pointed to in the input parameters and return that sum.";
}

TEST(ComputeSumTest, SumMultipleNumbers) {
  for (int i = -5; i < 10; i++) {
    for (double j = 20.2; j < 25; j+= .1) {
      double v1 = i;
      double v2 = j;
      double expected = i + j;
      ASSERT_EQ(expected, ComputeSum(&v1, &v2)) << "    The ComputeSum function should add the doubles pointed to in the input parameters and return that sum.";
    }
  }
}

TEST(SwapTest, SwapsTwoNumbers) {
  int v1 = 2;
  int v2 = 7;
  Swap(&v1, &v2);
  ASSERT_EQ(2, v2) << "    The Swap function should swap the values being pointed to in the first and second parameter. "
      "In this case the first parameter points to 2 and the second to 7, so Swap should cause the first parameter to point "
      "to 7 and the second one to point to 2.";
  ASSERT_EQ(7, v1) << "    The Swap function should swap the values being pointed to in the first and second parameter. "
      "In this case the first parameter points to 2 and the second to 7, so Swap should cause the first parameter to point "
      "to 7 and the second one to point to 2.";
}

TEST(SwapTest, SwapsManyNumbers) {
  for (int i = -5; i < 10; i++) {
    for (int j = 15; j < 20; j++) {
      int v1 = i;
      int v2 = j;
      Swap(&v1, &v2);
      ASSERT_EQ(i, v2) << "    The Swap function should swap the values being pointed to in the first and second parameter.";
      ASSERT_EQ(j, v1) << "    The Swap function should swap the values being pointed to in the first and second parameter.";
    }
  }
}

TEST(MakeSusTest, EmptyStringGetsSuffix) {
  std::string str = "";
  MakeSus(&str);
  ASSERT_EQ(" is sus", str) << "   The MakeSus function should append \" is sus\" to the value of the string pointed to in the parameter.";
}

TEST(MakeSusTest, NameGetsSuffix) {
  std::string red = "red";
  MakeSus(&red);
  ASSERT_EQ("red is sus", red) << "   The MakeSus function should append \" is sus\" to the value of the string pointed to in the parameter.";
  std::string pie = "pie";
  MakeSus(&pie);
  ASSERT_EQ("pie is sus", pie) << "   The MakeSus function should append \" is sus\" to the value of the string pointed to in the parameter.";
}

TEST(GetLongestStringTest, EmptyVectorReturnsNullptr) {
  std::vector<std::string> strings;
  ASSERT_EQ(nullptr, GetLongestString(&strings)) << "    When passed an empty vector, your GetLongestString function should return nullptr.";
}

TEST(GetLongestStringTest, ReturnsLongestOfSeveralUnsortedStrings) {
  std::vector<std::string> strings;
  strings.push_back("When in the Course of human events");
  strings.push_back("That whenever any Form of Government becomes destructive of these ends, it is the Right of the People to alter or to abolish it, and to institute new Government");
  strings.push_back("That to secure these rights, Governments are instituted among Men, deriving their just powers from the consent of the governed");
  ASSERT_EQ(&(strings[1]), GetLongestString(&strings)) << "   GetLongestString should return a pointer to the longest string in the std::vector.";

}

TEST(MainTest, Negate) {
   std::string user_input = "1\ntrue\nquit\n";
   ASSERT_DURATION_LE(3, {
         ASSERT_EXECTHAT(
             "main", user_input,
             HasSubstr("value is now false")) <<
             "    Ensure you call Negate with the address of the boolean variable called value.";
       });
}

TEST(MainTest, Increment) {
   std::string user_input = "2\n41\nquit\n";
   ASSERT_DURATION_LE(3, {
         ASSERT_EXECTHAT(
             "main", user_input,
             HasSubstr("the incremented number is 42")) <<
             "    Ensure you call Increment with the address of the integer variable called number.";
       });
}

TEST(MainTest, ComputeSum) {
   std::string user_input = "3\n3.14\n1.618\nquit\n";
   ASSERT_DURATION_LE(3, {
         ASSERT_EXECTHAT(
             "main", user_input,
             HasSubstr("the sum is 4.758")) <<
             "    Ensure you call ComputeSum with the address of the double variable first and the address of the double variable second.";
       });
}

TEST(MainTest, Swap) {
  std::string user_input = "4\n8\n12\nquit\n";
  ASSERT_DURATION_LE(3, {
        ASSERT_EXECTHAT(
            "main", user_input,
            HasSubstr("first: 12, second: 8")) <<
            "    Ensure you call Swap with the address of the integer variable first and the address of the integer variable second.";
      });
}

TEST(MainTest, MakeSus) {
   std::string user_input = "5\nlyka\nquit\n";
   ASSERT_DURATION_LE(3, {
         ASSERT_EXECTHAT(
             "main", user_input,
             HasSubstr("lyka is sus")) <<
             "    Ensure you call MakeSus with the address of the string variable name.";
       });
}

TEST(MainTest, GetLongestString) {
  std::string user_input = "6\n4\nlyka\nlyra\nkatie\npaul\nquit\n";
  ASSERT_DURATION_LE(3, {
        ASSERT_EXECTHAT(
            "main", user_input,
            HasSubstr("the longest is katie")) <<
            "    Ensure you call GetLongestString with the address of the vector variable named strings.";
      });
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
