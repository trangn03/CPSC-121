#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <random>
#include <cmath>
#include <string>
#include <fstream>
#include "../cppaudit/gtest_ext.h"
#include "../../minmax.h"

TEST(MinMax, OutputFormat)
{
  std::ostringstream s, input;

  s << "The max of 1 and 10 is: 10" << std::endl;
  s << "The min of 8 and 42 is: 8" << std::endl;
  s << "The max of 3.14 and 8.25 is: 8.25" << std::endl;
  s << "The min of -1.11 and 13.37 is: -1.11" << std::endl;
  s << "The max of \"cat\" and \"dog\" is: dog" << std::endl;
  s << "The min of \"abc\" and \"xyz\" is: abc" << std::endl;
  input << "";
  std::string unittest_input = input.str(), unittest_output = s.str();
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", unittest_input, unittest_output);
  });
}

TEST(Min, MinTest) {
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(Minimum(1,10), 1);
  });
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(Minimum(-20.33,3.67), -20.33);
  });
  std::string unittest_output = "abc";
  std::string your_string1 = "abc";
  std::string your_string2 = "xyz";
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(Minimum(your_string1, your_string2), unittest_output) << "   Input: your_string 1 = " << your_string1 << " your_string 2 = " << your_string2;
  });
}

TEST(Max, MaxTest) {
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(Maximum(9000,42), 9000);
  });
  ASSERT_DURATION_LE(3, {
   ASSERT_EQ(Maximum(133.7, 1.23), 133.7);
  });
  std::string unittest_output = "xyz";
  std::string your_string1 = "abc";
  std::string your_string2 = "xyz";
  ASSERT_DURATION_LE(3, {
    ASSERT_EQ(Maximum(your_string1, your_string2), unittest_output) << "   Input: your_string 1 = " << your_string1 << " your_string 2 = " << your_string2;
  });
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  bool skip = true;
  for (int i = 0; i < argc; i++) {
    if (std::string(argv[i]) == "--noskip") {
      skip = false;
    }
  }
  if (skip) {
    ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  }
  return RUN_ALL_TESTS();
}
