#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "../../person.h"
#include "../cppaudit/gtest_ext.h"

using ::testing::HasSubstr;

class PersonTest : public testing::Test {
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

TEST_F(PersonTest, ConstructorAndGetName) {
  Person person("Bart");
  ASSERT_EQ("Bart", person.GetName()) << "    Person::GetName should return "
                                         "the name passed in the constructor.";
}

TEST_F(PersonTest, SetAndGetChild) {
  Person child("Maggie");
  Person parent("Marge");
  parent.SetChild(&child);
  ASSERT_EQ(&child, parent.GetChild())
      << "    Person::GetChild should return whatever pointer was passed in "
         "Person::SetChild (store it as a member variable).";
}

TEST_F(PersonTest, ChildStartsAsNullptr) {
  Person person("Lisa");
  ASSERT_EQ(nullptr, person.GetChild())
      << "    Person::GetChild should return nullptr before SetChild has been "
         "called (the default value of the child variable should be nullpltr).";
}

TEST_F(PersonTest, PrintsPersonWithNoChildren) {
  Person person("Ling");
  person.Print();
  EXPECT_EQ(stream.str(), "Ling\n")
      << "    Person::Print should print the person's own name followed by the "
         "newline character if their child pointer is nullptr.";
}

TEST_F(PersonTest, PrintsPersonWithOneChild) {
  Person child("Bart");
  Person parent("Homer");
  parent.SetChild(&child);
  parent.Print();
  EXPECT_THAT(stream.str(), testing::HasSubstr("Homer, parent of Bart"))
      << "    Person::Print should print the person's own name followed by \", "
         "parent of \" followed by the child's Print() function.";
}

TEST_F(PersonTest, MultiGenerational) {
  std::vector<std::unique_ptr<Person>> people;
  people.push_back(std::make_unique<Person>("ancestor"));
  std::string expected = "ncestor, parent of ";
  int count = 10;
  for (int i = 1; i < count; i++) {
    std::string name = "person " + std::to_string(i);
    people.push_back(std::make_unique<Person>(name));
    people[i - 1]->SetChild(people[i].get());
    expected += name;
    if (i < count - 1) {
      expected += ", parent of ";
    }
  }
  people[0]->Print();
  EXPECT_THAT(stream.str(), testing::HasSubstr(expected))
      << "    Person::Print should print the person's own name followed by \", "
         "parent of \" followed by the child's Print() function.";
}

TEST(MainTest, ProgramRunsAsExpected) {
  std::string input = "Ursula\nJose\nArcadio\nRemedios\n";
  ASSERT_EXECTHAT(
      "main", input,
      HasSubstr(
          "Ursula, parent of Jose, parent of Arcadio, parent of Remedios"))
      << "      Your program should ask for the great-grandparent, "
         "grandparent, parent and kid's names, then call \"Person::Print\" on "
         "the great-grandparent";
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
