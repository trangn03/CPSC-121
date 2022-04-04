#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "../../cat.h"
#include "../../human.h"
#include "../cppaudit/gtest_ext.h"

using ::testing::HasSubstr;

class CatTest : public testing::Test {
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

TEST_F(CatTest, GetAndSetName) {
  Cat cat;
  cat.SetName("peanut");
  ASSERT_EQ("peanut", cat.GetName())
      << "    Cat::SetName should set the value of a member variable and "
         "Cat::GetName should return that member variable.";
}

TEST_F(CatTest, Destructor) {
  Cat* cat = new Cat();
  cat->SetName("Ramonda");
  delete cat;
  ASSERT_THAT(stream.str(), testing::HasSubstr("Ramonda stalks away"))
      << "   The Cat destructor should print the cat's name followed by \" "
         "stalks away\"";
}

TEST_F(CatTest, CreateKitty) {
  std::unique_ptr<Cat> cat = CreateKitty("marble");
  ASSERT_TRUE(cat != nullptr) << "    CreateKitty should not return nullptr";
  ASSERT_EQ("marble", cat->GetName())
      << "    CreateKitty should construct a std::unique_ptr<Cat> and set its "
         "name to the string parameter to CreateKitty.";
}

class HumanTest : public testing::Test {
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

TEST_F(HumanTest, GetAndSetName) {
  Human human;
  human.SetName("T'Chaka");
  ASSERT_EQ("T'Chaka", human.GetName())
      << "    Human::SetName should set the value of a member variable and "
         "Human::GetName should return that member variable.";
}

TEST_F(HumanTest, Destructor) {
  Human* human = new Human();
  human->SetName("N'Yami");
  delete human;
  ASSERT_THAT(stream.str(), testing::HasSubstr("N'Yami walks away"))
      << "   The Human destructor should print the human's name followed by \" "
         "walks away\"";
}

TEST_F(HumanTest, PrintWithNoCat) {
  Human human;
  human.SetName("Shuri");
  human.Print();
  ASSERT_THAT(stream.str(), testing::HasSubstr("Shuri is a human with no cat"))
      << "   Human::Print should print the human's name followed by \"is a "
         "human with no cat\" when the Human's cat member pointer is nullptr.";
}

TEST_F(HumanTest, AdoptAndPrintCat) {
  Human human;
  human.SetName("T'Challa");

  std::unique_ptr<Cat> cat = std::make_unique<Cat>();
  cat->SetName("Klaw");

  human.Adopt(std::move(cat));
  ASSERT_TRUE(cat == nullptr) << "    Human::Adopt should take ownership over the "
                             "unique pointer to a Cat using std::move.";

  human.Print();
  ASSERT_THAT(stream.str(),
              testing::HasSubstr("T'Challa is a human with a cat named Klaw"))
      << "   Human::Print should print the human's name followed by \"is a "
         "human with a cat named Klaw\" when the Human's cat member pointer "
         "points to a Cat with name \"Klaw\".";
}

TEST_F(HumanTest, TransferCat) {
  Human human;
  human.SetName("Ngozi");

  Human second;
  second.SetName("Aneka");

  std::unique_ptr<Cat> cat = std::make_unique<Cat>();
  cat->SetName("Zola");

  human.Adopt(std::move(cat));
  human.TransferTo(&second);

  human.Print();
  ASSERT_THAT(stream.str(), testing::HasSubstr("Ngozi is a human with no cat"))
      << "   Human::Print should print the human's name followed by \"is a "
         "human with no cat\" when the Human's cat member pointer is nullptr. "
         "The pointer should become null after transferring the "
         "unique_ptr<Cat> using std::move in Human::TransferTo..";

  second.Print();
  ASSERT_THAT(stream.str(),
              testing::HasSubstr("Aneka is a human with a cat named Zola"))
      << "   Human::Print should print the human's name followed by \"is a "
         "human with a cat named Zola\" when the Human's cat member pointer "
         "points to a Cat with name \"Zola\", after reciving that cat through "
         "Human::TransferTo.";
}

TEST(MainTest, CatIsTransferred) {
  std::string user_input = "Vega\nRadish\nLyka\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input,
                    HasSubstr("Vega is a human with a cat named Lyka"))
        << "Hint: Check that you construct the Humans from name1 and name2, "
           "and the cat from cat_name, then the first human should Adopt the "
           "cat.";
  });

  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input,
                    HasSubstr("Vega is a human with no cat"))
        << "Hint: Check that you construct the Humans from name1 and name2, "
           "and the cat from cat_name, then the first human should Transfer "
           "the cat to the second Human.";
  });

  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input,
                    HasSubstr("Radish is a human with no cat"))
        << "Hint: Check that you construct the Humans from name1 and name2, "
           "and the cat from cat_name, then the first human initially have no "
           "cat the first time Print is called.";
  });

  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input,
                    HasSubstr("Radish is a human with a cat named Lyka"))
        << "Hint: Check that you construct the Humans from name1 and name2, "
           "and the cat from cat_name, then the first human should Transfer "
           "the cat to the second Human.";
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
