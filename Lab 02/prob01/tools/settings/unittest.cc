#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <string>

#include "../cppaudit/gtest_ext.h"
#include "../../cpputils/graphics/test/image_test_utils.h"
#include "../../cpputils/graphics/image.h"
#include "../../pizza.h"

using ::testing::MatchesRegex;

// Use UnitTestFileManager which renames any existing files
// during the test so they are not clobbered.
class PizzaTest : public UnitTestFileManager {
 public:
  PizzaTest() : UnitTestFileManager("pizza.bmp") {};

  bool FileCreated() {
    std::ifstream stream;
    stream.open(filename_);
    bool created = stream.good();
    stream.close();
    return created;
  }

  void CreatePizza(std::string user_input) {
    ASSERT_EXECEXIT("main", user_input, /* seconds */ 3)
        << "      Your program should ask the user if they want pizza, and whether it should "
        << "come with tomato sauce, cheese, pepperoni, jalapeno and onion.";
    EXPECT_TRUE(FileCreated()) << "Your program should save pizza.bmp based on user input.";
  }

  void GetPizza(std::string user_input, graphics::Image& actual) {
    CreatePizza(user_input);
    ASSERT_TRUE(actual.Load("pizza.bmp"));
    ASSERT_EQ(500, actual.GetWidth()) << "Pizza width should be 500px";
    ASSERT_EQ(500, actual.GetHeight()) << "Pizza height should be 500px";
  }
};

TEST_F(PizzaTest, ExecutesAndExits) {
  std::string user_input = "y\ny\ny\ny\ny\ny\n";
  CreatePizza(user_input);
}

TEST_F(PizzaTest, DoesNotWantPizza) {
  std::string user_input = "n\n";
  ASSERT_EXECEXIT("main", user_input, /* seconds */ 3)
      << " Your program should ask the user if they want pizza, and if not, exit.";
  EXPECT_FALSE(FileCreated())
      << "Your program should not create pizza.bmp if the user does not want pizza.";
}

TEST_F(PizzaTest, AsksAboutToppings) {
  std::string user_input = "y\nn\nn\nn\nn\nn\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, MatchesRegex(
      ".*[Tt]omato sauce.*[Cc]heese.*[Pp]epperoni.*[Jj]alapeno.*[Oo]nion.*pizza[.]bmp.*"))
      << "Ask about tomato sauce, cheese, pepperoni, jalapeno, and onion in that order, "
      << "and tell the user the filename at which their pizza was saved, pizza.bmp.";
  })
}

TEST_F(PizzaTest, PlainPizza) {
  // Remove diff image before starting, so that if the test runs successfully
  // it isn't left behind as an artifact from last time.
  std::string diff_image = "expected_v_actual_crust.bmp";
  remove(diff_image.c_str());
  graphics::Image actual;
  GetPizza("y\nn\nn\nn\nn\nn\n", actual);

  graphics::Image expected(500, 500);
  AddCrust(expected);

  bool match = ImagesMatch(&expected, &actual, diff_image,
      DiffType::kTypeSideBySide);
  EXPECT_TRUE(match) << "Your plain pizza is not quite right. See " << diff_image;
}

TEST_F(PizzaTest, SaucePizza) {
  std::string diff_image = "expected_v_actual_sauce.bmp";
  remove(diff_image.c_str());
  graphics::Image actual;
  GetPizza("y\ny\nn\nn\nn\nn\n", actual);

  graphics::Image expected(500, 500);
  AddCrust(expected);
  AddSauce(expected);

  bool match = ImagesMatch(&expected, &actual, diff_image,
      DiffType::kTypeSideBySide);
  EXPECT_TRUE(match) << "Your sauce-only pizza is not quite right. See " << diff_image;
}

TEST_F(PizzaTest, CheesePizza) {
  std::string diff_image = "expected_v_actual_cheese.bmp";
  remove(diff_image.c_str());
  graphics::Image actual;
  GetPizza("y\nn\ny\nn\nn\nn\n", actual);

  graphics::Image expected(500, 500);
  AddCrust(expected);
  AddCheese(expected);

  bool match = ImagesMatch(&expected, &actual, diff_image,
      DiffType::kTypeSideBySide);
  EXPECT_TRUE(match) << "Your cheese-only pizza is not quite right. See " << diff_image;
}

TEST_F(PizzaTest, PepperoniPizza) {
  std::string diff_image = "expected_v_actual_pepperoni.bmp";
  remove(diff_image.c_str());
  graphics::Image actual;
  GetPizza("y\nn\nn\ny\nn\nn\n", actual);

  graphics::Image expected(500, 500);
  AddCrust(expected);
  AddPepperoni(expected);

  bool match = ImagesMatch(&expected, &actual, diff_image,
      DiffType::kTypeSideBySide);
  EXPECT_TRUE(match) << "Your pepperoni pizza is not quite right. See " << diff_image;
}

TEST_F(PizzaTest, JalapenoPizza) {
  std::string diff_image = "expected_v_actual_jalapeno.bmp";
  remove(diff_image.c_str());
  graphics::Image actual;
  GetPizza("y\nn\nn\nn\ny\nn\n", actual);

  graphics::Image expected(500, 500);
  AddCrust(expected);
  AddJalapeno(expected);

  bool match = ImagesMatch(&expected, &actual, diff_image,
      DiffType::kTypeSideBySide);
  EXPECT_TRUE(match) << "Your jalapeno pizza is not quite right. See " << diff_image;
}

TEST_F(PizzaTest, OnionPizza) {
  std::string diff_image = "expected_v_actual_onion.bmp";
  remove(diff_image.c_str());
  graphics::Image actual;
  GetPizza("y\nn\nn\nn\nn\ny\n", actual);

  graphics::Image expected(500, 500);
  AddCrust(expected);
  AddOnion(expected);

  bool match = ImagesMatch(&expected, &actual, diff_image,
      DiffType::kTypeSideBySide);
  EXPECT_TRUE(match) << "Your onion pizza is not quite right. See " << diff_image;
}

TEST_F(PizzaTest, EverythingPizza) {
  std::string diff_image = "expected_v_actual_all_toppings.bmp";
  remove(diff_image.c_str());

  graphics::Image actual;
  GetPizza("y\ny\ny\ny\ny\ny\n", actual);
  graphics::Image expected(500, 500);
  AddCrust(expected);
  AddSauce(expected);
  AddCheese(expected);
  AddPepperoni(expected);
  AddJalapeno(expected);
  AddOnion(expected);

  bool match = ImagesMatch(&expected, &actual, diff_image,
      DiffType::kTypeSideBySide);
  EXPECT_TRUE(match) << "Your pizza is not quite right. "
      << "Did you add the toppings in the right order? See "
      << diff_image;
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
