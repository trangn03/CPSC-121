#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../cppaudit/gtest_ext.h"
#include "../../array_double.h"

using ::testing::HasSubstr;
using ::testing::ContainsRegex;

TEST(Exception, constructor)
{
  Exception your_ex("My exception message");
  ASSERT_EQ(your_ex.GetMessage(), "My exception message") << "Either your accessor message() was not working correctly, or your constructor did not set the message correctly";
}

TEST(Exception, mutator)
{
  Exception your_ex("Default message");
  your_ex.SetMessage("Mutator exception message");
  ASSERT_EQ(your_ex.GetMessage(), "Mutator exception message") << "Either your accessor message() was not working correctly, or your mutator set_message() did not set the message correctly";
}

TEST(IndexOutOfRangeException, constructor)
{
  IndexOutOfRangeException your_ex(77, 44);
  ASSERT_THAT(your_ex.GetMessage(), HasSubstr("77")) << "Your constructor did not set the index correctly";
  ASSERT_THAT(your_ex.GetMessage(), HasSubstr("44")) << "Your constructor did not set the array size correctly";
  ASSERT_THAT(your_ex.GetMessage(), HasSubstr("0 and 43")) << "Your constructor did not set the correct value range.";
}

TEST(InvalidArrayLengthException, constructor)
{
  InvalidArrayLengthException your_ex(-22);
  ASSERT_THAT(your_ex.GetMessage(), HasSubstr("-22)")) << "Your constructor did not show the invalid index value";
  ASSERT_THAT(your_ex.GetMessage(), HasSubstr("positive integer")) << "Your constructor did not emphasize positive integers";
}

TEST(ArrayDouble, InvalidArrayLengthException1)
{
  ASSERT_THROW(ArrayDouble(-3), InvalidArrayLengthException) << "Passing a negative size to the constructor should throw an InvalidArrayLengthException";
}

TEST(ArrayDouble, ConstructorZeroes1)
{
	ArrayDouble your_array(3);
	ASSERT_EQ(your_array[0], 0) << "The constructor should set all elements to 0";
	ASSERT_EQ(your_array[1], 0) << "The constructor should set all elements to 0";
	ASSERT_EQ(your_array[2], 0) << "The constructor should set all elements to 0";

}

TEST(ArrayDouble, ConstructorZeroes2)
{
	ArrayDouble your_array(8);
	ASSERT_EQ(your_array[0], 0) << "The constructor should set all elements to 0";
	ASSERT_EQ(your_array[1], 0) << "The constructor should set all elements to 0";
	ASSERT_EQ(your_array[2], 0) << "The constructor should set all elements to 0";
	ASSERT_EQ(your_array[3], 0) << "The constructor should set all elements to 0";
	ASSERT_EQ(your_array[4], 0) << "The constructor should set all elements to 0";
	ASSERT_EQ(your_array[5], 0) << "The constructor should set all elements to 0";
	ASSERT_EQ(your_array[6], 0) << "The constructor should set all elements to 0";
	ASSERT_EQ(your_array[7], 0) << "The constructor should set all elements to 0";
}

TEST(ArrayDouble, IndexOutOfRangeException)
{
	ArrayDouble your_array(5);
	ASSERT_THROW(your_array[7], IndexOutOfRangeException) << "Providing an invalid index to the array should throw an IndexOutOfRangeException. In this case, index 7 in an array with 5 elements";
}

TEST(ArrayDouble, IndexOutOfRangeExceptionOffByOne)
{
	ArrayDouble your_array(5);
	ASSERT_THROW(your_array[5], IndexOutOfRangeException) << "Providing an invalid index to the array should throw an IndexOutOfRangeException. In this case, index 5 in an array with 5 elements";
}

TEST(ArrayDouble, IndexOutOfRangeExceptionNegative)
{
	ArrayDouble your_array(5);
	ASSERT_THROW(your_array[-1], IndexOutOfRangeException) << "Providing an invalid index to the array should throw an IndexOutOfRangeException. In this case, index -1 in an array with 5 elements";
}

TEST(ArrayDouble, OpOverload1)
{
	ArrayDouble your_array(4);
	your_array[2] = 3;
	ASSERT_EQ(your_array[2], 3) << "The operator overload did not assign the value correctly.";
}

TEST(ArrayDouble, OpOverload2)
{
	ArrayDouble your_array(8);
	your_array[7] = 6;
	ASSERT_EQ(your_array[7], 6) << "The operator overload did not assign the value correctly.";
}

TEST(ArrayDouble, DisplayEmpty)
{
	ArrayDouble your_array(0);
	SIMULATE_SIO("", your_array.Display(), {
		ASSERT_THAT(your_output, HasSubstr("empty")) << "The function should say the array is empty if the array's size is 0";
	})
}

TEST(ArrayDouble, Display)
{
	ArrayDouble your_array(3);
	your_array[0] = 1.0;
	your_array[1] = 2.0;
	your_array[2] = 0.6;
        SIMULATE_SIO("", your_array.Display(), {
          ASSERT_THAT(your_output, ContainsRegex("1\\.00.*2\\.00.*0\\.6"))
              << "The function should display all elements of the array: 1.0, "
                 "2.0, 0.6";
        })
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
