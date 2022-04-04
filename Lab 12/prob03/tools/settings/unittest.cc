#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "../../cupcake.h"
#include "../../stomach.h"
#include "../cppaudit/gtest_ext.h"

using ::testing::HasSubstr;

TEST(CupcakeTest, GetAndSetFlavor) {
  Cupcake cupcake;
  cupcake.SetFlavor("carrot");
  ASSERT_EQ("carrot", cupcake.GetFlavor())
      << "    Cupcake should have SetFlavor which saves a std::string flavor "
         "in a private member variable, and a GetFlavor getter that returns "
         "that value.";
}

class StomachTest : public testing::Test {
 public:
  void SetUp() override {
    // https://stackoverflow.com/questions/3803465/how-to-capture-stdout-stderr-with-googletest
    original = std::cout.rdbuf();
    std::cout.rdbuf(stream.rdbuf());
  }

  void TearDown() override { std::cout.rdbuf(original); }

 protected:
  std::streambuf* original;
  std::stringstream stream;
};

TEST_F(StomachTest, CountStartsAtZero) {
  Stomach stomach;
  ASSERT_EQ(0, stomach.GetCupcakeCount())
      << "    Stomach cupcake count should start at 0 before eating any "
         "cupcakes.";
}

TEST_F(StomachTest, EatAndDeallocatePtrPtrIncreasesCupcakeCount) {
  Stomach stomach;
  ASSERT_EQ(0, stomach.GetCupcakeCount())
      << "    Stomach cupcake count should start at 0 before eating any "
         "cupcakes.";
  for (int i = 0; i < 10; i++) {
    Cupcake* c = new Cupcake();
    c->SetFlavor("c");
    stomach.EatAndDeallocate(&c);
    ASSERT_EQ(i + 1, stomach.GetCupcakeCount())
        << "    Stomach cupcake count should increment with each call to "
           "EatAndDeallocate (the Cupcake** version).";
  }
}

TEST_F(StomachTest, EatAndDeallocateUnqPtrIncreasesCupcakeCount) {
  Stomach stomach;
  ASSERT_EQ(0, stomach.GetCupcakeCount())
      << "    Stomach cupcake count should start at 0 before eating any "
         "cupcakes.";
  for (int i = 0; i < 10; i++) {
    std::unique_ptr<Cupcake> c(new Cupcake());
    c->SetFlavor("c");
    stomach.EatAndDeallocate(std::move(c));
    ASSERT_EQ(i + 1, stomach.GetCupcakeCount())
        << "    Stomach cupcake count should increment with each call to "
           "EatAndDeallocate (the unique_ptr version).";
  }
}

TEST_F(StomachTest, EatAndDeallocatePtrPtrPrintsCupcakeFlavor) {
  Stomach stomach;
  Cupcake* c = new Cupcake();
  c->SetFlavor("chocolate");
  stomach.EatAndDeallocate(&c);
  EXPECT_THAT(stream.str(), testing::HasSubstr("chocolate"))
      << "    EatAndDeallocate should print a message about the flavor of "
         "cupcake that the pointer's pointer points to.";
}

TEST_F(StomachTest, EatAndDeallocateUnqPtrPrintsCupcakeFlavor) {
  Stomach stomach;
  std::unique_ptr<Cupcake> c(new Cupcake());
  c->SetFlavor("redvelvet");
  stomach.EatAndDeallocate(std::move(c));
  EXPECT_THAT(stream.str(), testing::HasSubstr("redvelvet"))
      << "    EatAndDeallocate should print a message about the flavor of "
         "cupcake that the unique pointer points to.";
}

TEST_F(StomachTest, EatAndDeallocatePtrPtrSetsPtrToNull) {
  Stomach stomach;
  Cupcake* c = new Cupcake();
  c->SetFlavor("vanilla");
  stomach.EatAndDeallocate(&c);
  ASSERT_EQ(nullptr, c)
      << "    EatAndDeallocate should not only deallocate the Cupcake* (using "
         "delete) but also set it to null.";
}

TEST_F(StomachTest, EatAndDeallocatePtrPtrDoesNotIncrementWhenNull) {
  Stomach stomach;
  ASSERT_EQ(0, stomach.GetCupcakeCount())
      << "    Stomach cupcake count should start at 0 before eating any "
         "cupcakes.";
  Cupcake* ptr = nullptr;
  stomach.EatAndDeallocate(&ptr);
  ASSERT_EQ(0, stomach.GetCupcakeCount())
      << "    Stomach cupcake count should not increase when trying to eat a "
         "pointer to a nullptr.";
}

TEST_F(StomachTest, EatAndDeallocateUnqPtrDoesNotIncrementNull) {
  Stomach stomach;
  ASSERT_EQ(0, stomach.GetCupcakeCount())
      << "    Stomach cupcake count should start at 0 before eating any "
         "cupcakes.";
  std::unique_ptr<Cupcake> ptr;
  stomach.EatAndDeallocate(std::move(ptr));
  ASSERT_EQ(0, stomach.GetCupcakeCount())
      << "    Stomach cupcake count should not increase when trying to eat a "
         "null unique_ptr.";
}

TEST_F(StomachTest, EatAndDeallocatePtrPtrPrintsWhenNull) {
  Stomach stomach;
  Cupcake* ptr = nullptr;
  stomach.EatAndDeallocate(&ptr);
  EXPECT_THAT(stream.str(), testing::HasSubstr("no cupcake"))
      << "    EatAndDeallocate should print a message about \"no cupcake\" "
         "when the pointer passed in points to a nullptr.";
}

TEST_F(StomachTest, EatAndDeallocateUnqPtrPrintsWhenNull) {
  Stomach stomach;
  std::unique_ptr<Cupcake> ptr;
  stomach.EatAndDeallocate(std::move(ptr));
  EXPECT_THAT(stream.str(), testing::HasSubstr("no cupcake"))
      << "    EatAndDeallocate should print a message about \"no cupcake\" "
         "when the unique_ptr == nullptr.";
}

TEST(MainTest, EatsTwoCupcakes) {
  std::string user_input = "lemon\nhazelnut\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, HasSubstr("count: 0"))
        << "main should print the stomach's cupcake count before any cupcakes "
           "are eaten.";
  });

  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, HasSubstr("count: 1"))
        << "main should print the stomach's cupcake count after 1 cupcake is "
           "eaten.";
  });

  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, HasSubstr("count: 2"))
        << "main should print the stomach's cupcake count after two cupcakes "
           "are eaten.";
  });
}

TEST(MainTest, PrintsWhileEatingTwoCupcakes) {
  std::string user_input = "mint\norange\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, HasSubstr("mint"))
        << "main should use the user input to set the flavor for two cupcakes, "
           "then call EatAndDeallocate on each (EatAndDeallocate prints the "
           "cupcake flavor).";
  });

  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, HasSubstr("orange"))
        << "main should use the user input to set the flavor for two cupcakes, "
           "then call EatAndDeallocate on each (EatAndDeallocate prints the "
           "cupcake flavor).";
  });
}

int main(int argc, char** argv) {
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
