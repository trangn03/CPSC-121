#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "../../pogil.h"
#include "../cppaudit/gtest_ext.h"

using ::testing::HasSubstr;

TEST(StudentTest, ConstructorAndGetter) {
  Student student("Ozzy Osbourne", 5);
  ASSERT_EQ("Ozzy Osbourne", student.GetName())
      << "    Student::GetName should return the name from the constructor.";
  ASSERT_EQ(5, student.GetPoints())
      << "    Student::GetPoints should return the number of points passed in "
         "the constructor before Student::AddPoints is called.";
}

TEST(StudentTest, AddPoints) {
  Student student("Freddie Mercury", 3);
  ASSERT_EQ(3, student.GetPoints())
      << "    Student::GetPoints should return the number of points passed in "
         "the constructor before Student::AddPoints is called.";
  student.AddPoints(5);
  ASSERT_EQ(8, student.GetPoints())
      << "    Student::AddPoints should add the input parameter to a private "
         "member variable in the Student class which is returned with "
         "GetPoints.";
  student.AddPoints(14);
  ASSERT_EQ(22, student.GetPoints())
      << "    Student::AddPoints should add to a private member variable in "
         "the Student class which is returned with GetPoints.";
}

TEST(PogilGroupTest, ConstructorAndGetters) {
  Student manager("Kermit", 0);
  Student presenter("Piggy", 2);
  Student recorder("Gonzo", 9);
  Student reflector("Fozzie", 8);
  PogilGroup group(&manager, &presenter, &recorder, &reflector);
  ASSERT_EQ(&manager, group.GetManager())
      << "    PogilGroup::GetManager should return the same pointer passed as "
         "the first parameter to the constructor.";
  ASSERT_EQ(&presenter, group.GetPresenter())
      << "    PogilGroup::GetPresenter should return the same pointer passed "
         "as the second parameter to the constructor.";
  ASSERT_EQ(&recorder, group.GetRecorder())
      << "    PogilGroup::GetRecorder should return the same pointer passed as "
         "the third parameter to the constructor.";
  ASSERT_EQ(&reflector, group.GetReflector())
      << "    PogilGroup::GetReflector should return the same pointer passed "
         "as the fourth parameter to the constructor.";
}

TEST(PogilGroupTest, Grade) {
  Student manager("Kermit", 3);
  Student presenter("Piggy", 6);
  Student recorder("Gonzo", 9);
  Student reflector("Fozzie", 12);
  PogilGroup group(&manager, &presenter, &recorder, &reflector);
  group.Grade(10);
  ASSERT_EQ(13, manager.GetPoints())
      << "    PogilGroup::Grade should call AddPoints on the pointer to the "
         "manager.";
  ASSERT_EQ(16, presenter.GetPoints())
      << "    PogilGroup::Grade should call AddPoints on the pointer to the "
         "presenter.";
  ASSERT_EQ(19, recorder.GetPoints())
      << "    PogilGroup::Grade should call AddPoints on the pointer to the "
         "recorder.";
  ASSERT_EQ(22, reflector.GetPoints())
      << "    PogilGroup::Grade should call AddPoints on the pointer to the "
         "reflector.";

  group.Grade(20);
  EXPECT_EQ(33, manager.GetPoints())
      << "    PogilGroup::Grade should call AddPoints on the pointer to the "
         "manager.";
  EXPECT_EQ(36, presenter.GetPoints())
      << "    PogilGroup::Grade should call AddPoints on the pointer to the "
         "presenter.";
  EXPECT_EQ(39, recorder.GetPoints())
      << "    PogilGroup::Grade should call AddPoints on the pointer to the "
         "recorder.";
  EXPECT_EQ(42, reflector.GetPoints())
      << "    PogilGroup::Grade should call AddPoints on the pointer to the "
         "reflector.";
}

class PrintGroupInformationTest : public testing::Test {
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

TEST_F(PrintGroupInformationTest, PrintsWithExpectedFormat) {
  Student manager("tuffy", 0);
  Student presenter("tuffy", 0);
  Student recorder("tuffy", 0);
  Student reflector("tuffy", 0);
  PogilGroup group(&manager, &presenter, &recorder, &reflector);
  PrintGroupInformation(&group);
  ASSERT_THAT(stream.str(), testing::HasSubstr("Manager tuffy has 0 points"))
      << "    PrintGroupInformation should print the group members using the "
         "format [RoleName] has [number] points, in this case \"Manager tuffy "
         "has 0 points\".";
  ASSERT_THAT(stream.str(), testing::HasSubstr("Presenter tuffy has 0 points"))
      << "    PrintGroupInformation should print the group members using the "
         "format [RoleName] has [number] points, in this case \"Presenter "
         "tuffy "
         "has 0 points\".";
  ASSERT_THAT(stream.str(), testing::HasSubstr("Recorder tuffy has 0 points"))
      << "    PrintGroupInformation should print the group members using the "
         "format [RoleName] has [number] points, in this case \"Recorder tuffy "
         "has 0 points\".";
  ASSERT_THAT(stream.str(), testing::HasSubstr("Reflector tuffy has 0 points"))
      << "    PrintGroupInformation should print the group members using the "
         "format [RoleName] has [number] points, in this case \"Reflector "
         "tuffy "
         "has 0 points\".";
}

TEST_F(PrintGroupInformationTest, CorrectlyAssociatesRolesWithNames) {
  Student manager("harry", 10);
  Student presenter("sally", 20);
  Student recorder("darcy", 30);
  Student reflector("elizabeth", 40);
  PogilGroup group(&manager, &presenter, &recorder, &reflector);
  PrintGroupInformation(&group);
  ASSERT_THAT(stream.str(), testing::HasSubstr("Manager harry has 10 points"))
      << "    PrintGroupInformation should print the group members using the "
         "format [RoleName] has [number] points, in this case \"Manager harry "
         "has 0 points\".";
  ASSERT_THAT(stream.str(), testing::HasSubstr("Presenter sally has 20 points"))
      << "    PrintGroupInformation should print the group members using the "
         "format [RoleName] has [number] points, in this case \"Presenter "
         "sally has 0 points\".";
  ASSERT_THAT(stream.str(), testing::HasSubstr("Recorder darcy has 30 points"))
      << "    PrintGroupInformation should print the group members using the "
         "format [RoleName] has [number] points, in this case \"Recorder darcy "
         "has 0 points\".";
  ASSERT_THAT(stream.str(),
              testing::HasSubstr("Reflector elizabeth has 40 points"))
      << "    PrintGroupInformation should print the group members using the "
         "format [RoleName] has [number] points, in this case \"Reflector "
         "elizabeth has 0 points\".";
}

TEST(MainTest, ProgramRunsAsExpected) {
  std::string input = "Katie\n3\nPaul\n6\nAlison\n4\nDerrick\n8\n8\n";
  ASSERT_EXECTHAT("main", input, HasSubstr("Manager Katie has 11 points"))
      << "      Your program should construct four Students and a PogilGroup,"
         "Grade() the PogilGroup, and call PrintGroupInformation on that "
         "group.";
  ASSERT_EXECTHAT("main", input, HasSubstr("Presenter Paul has 14 points"))
      << "      Your program should construct four Students and a PogilGroup,"
         "Grade() the PogilGroup, and call PrintGroupInformation on that "
         "group.";
  ASSERT_EXECTHAT("main", input, HasSubstr("Recorder Alison has 12 points"))
      << "      Your program should construct four Students and a PogilGroup,"
         "Grade() the PogilGroup, and call PrintGroupInformation on that "
         "group.";
  ASSERT_EXECTHAT("main", input, HasSubstr("Reflector Derrick has 16 points"))
      << "      Your program should construct four Students and a PogilGroup,"
         "Grade() the PogilGroup, and call PrintGroupInformation on that "
         "group.";
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
