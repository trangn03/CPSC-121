#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../cppaudit/gtest_ext.h"

TEST(Operations, ExecutesAndExitsWithInput) {
  ASSERT_EXECEXIT("main", "* 6 7", 3);
}

TEST(Operations, OutputFormat) {
  std::string unittest_output =
      "Please enter in the operation (+, -, *, /): Please "
      "input the first number: Please input the second "
      "number: You chose to multiply: 5 * 6 = 30\n";
  ASSERT_EXECTHAT("main", "* 5 6", ::testing::HasSubstr(unittest_output));
}

TEST(Operations, Addition) {
  srand(time(NULL));
  for (int i = 0; i < 10; i++) {
    std::string operation_input = "+";
    int num_one = rand();
    int num_two = rand();
    std::string output_string;
    std::string input = operation_input + " " + std::to_string(num_one) + " " +
                        std::to_string(num_two);

    std::string str_one = std::to_string(num_one);
    std::string str_two = std::to_string(num_two);
    int sum = num_one + num_two;
    std::string unittest_output =
        "Please enter in the operation (+, -, *, /): Please "
        "input the first number: Please input the second "
        "number: You chose to add: ";
    unittest_output +=
        str_one + " + " + str_two + " = " + std::to_string(sum) + "\n";

    ASSERT_EXECTHAT("main", input, ::testing::HasSubstr(unittest_output));
  }
}

TEST(Operations, Subtraction) {
  for (int i = 0; i < 10; i++) {
    std::string operation_input = "-";
    int num_one = rand();
    int num_two = rand();
    std::string output_string;
    std::string input = operation_input + " " + std::to_string(num_one) + " " +
                        std::to_string(num_two);

    std::string str_one = std::to_string(num_one);
    std::string str_two = std::to_string(num_two);

    int dif = num_one - num_two;
    std::string unittest_output =
        "Please enter in the operation (+, -, *, /): Please "
        "input the first number: Please input the second "
        "number: You chose to subtract: ";
    unittest_output +=
        str_one + " - " + str_two + " = " + std::to_string(dif) + "\n";

    ASSERT_EXECTHAT("main", input, ::testing::HasSubstr(unittest_output));
  }
}

TEST(Operations, Multiplication) {
  for (int i = 0; i < 10; i++) {
    std::string operation_input = "*";
    int num_one = rand();
    int num_two = rand();
    std::string output_string;
    std::string input = operation_input + " " + std::to_string(num_one) + " " +
                        std::to_string(num_two);

    std::string str_one = std::to_string(num_one);
    std::string str_two = std::to_string(num_two);

    int multiply = num_one * num_two;
    std::string unittest_output =
        "Please enter in the operation (+, -, *, /): Please "
        "input the first number: Please input the second "
        "number: You chose to multiply: ";
    unittest_output +=
        str_one + " * " + str_two + " = " + std::to_string(multiply) + "\n";

    ASSERT_EXECTHAT("main", input, ::testing::HasSubstr(unittest_output));
  }
}

TEST(Operations, Division) {
  for (int i = 0; i < 10; i++) {
    std::string operation_input = "/";
    int num_one = rand();
    int num_two = rand();
    std::string output_string;
    std::string input = operation_input + " " + std::to_string(num_one) + " " +
                        std::to_string(num_two);

    std::string str_one = std::to_string(num_one);
    std::string str_two = std::to_string(num_two);

    int divide = num_one / num_two;
    std::string unittest_output =
        "Please enter in the operation (+, -, *, /): Please "
        "input the first number: Please input the second "
        "number: You chose to divide: ";
    unittest_output +=
        str_one + " / " + str_two + " = " + std::to_string(divide) + "\n";

    ASSERT_EXECTHAT("main", input, ::testing::HasSubstr(unittest_output));
  }
}

TEST(Operations, FailCase) {
  for (int i = 0; i < 10; i++) {
    int fail_input = rand() % 10;
    int num_one = rand();
    int num_two = rand();
    std::string output_string;
    std::string input = std::to_string(fail_input) + " " +
                        std::to_string(num_one) + " " + std::to_string(num_two);
    std::string unittest_output =
        "Please enter in the operation (+, -, *, /): Please "
        "input the first number: Please input the second "
        "number: Invalid operation type.\n";

    ASSERT_EXECTHAT("main", input, ::testing::HasSubstr(unittest_output));
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
