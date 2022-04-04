#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../cppaudit/gtest_ext.h"
#include "../../doe.h"
#include "../../joey.h"
#include "../../kangaroo.h"

using ::testing::HasSubstr;

TEST(KangarooTest, Constructors) {
  Kangaroo k1;
  Kangaroo k2("kanga");
}

TEST(KangarooTest, GetAndSetName) {
  Kangaroo k("kanga");
  ASSERT_EQ("kanga", k.GetName()) << "    Kangaroo::GetName() should return the name passed in the constructor";
  k.SetName("batman");
  ASSERT_EQ("batman", k.GetName()) << "    Kangaroo::GetName() should return the name passed in Kangaroo::SetName";
}

TEST(KangarooTest, Bounce) {
  Kangaroo k("Green Lantern");
  std::streambuf* original_out = std::cout.rdbuf();
  std::stringstream stream_out;
  std::cout.rdbuf(stream_out.rdbuf());
  k.Bounce();
  std::cout.rdbuf(original_out);
  EXPECT_THAT(stream_out.str(), testing::HasSubstr("Green Lantern goes boing"))
      << "    Kangaroo::Bounce should cout the name of the Kangaroo and \"goes boing \", in this case \"Green Lantern goes boing\"";
}

TEST(KangarooTest, BounceCount) {
  Kangaroo k("spiderman");
  ASSERT_EQ(0, k.GetBounceCount()) << "    At construction, Kangaroo objects should have a 0 bounce count.";
  k.Bounce();
  ASSERT_EQ(1, k.GetBounceCount()) << "    After Kangaroo::Bounce is called once, Kangaroo objects should have a 1 bounce count.";
  k.Bounce();
  ASSERT_EQ(2, k.GetBounceCount()) << "    After Kangaroo::Bounce is called twice, Kangaroo objects should have a 2 bounce count.";
}

TEST(JoeyTest, ConstructorAndGetAndSetName) {
  Joey j("joseph");
  Kangaroo* k = &j;
  ASSERT_EQ("joseph", k->GetName()) << "    Joey::GetName() should return the name passed in the constructor, using the Kangaroo class method";
  k->SetName("jo");
  ASSERT_EQ("jo", k->GetName()) << "    Joey::GetName() should return the name passed in Joey::SetName, using the Kangaroo class method";
}

TEST(JoeyTest, Bounce) {
  Joey k("Peanut");
  Kangaroo* roo = &k;
  std::streambuf* original_out = std::cout.rdbuf();
  std::stringstream stream_out;
  std::cout.rdbuf(stream_out.rdbuf());
  roo->Bounce();
  std::cout.rdbuf(original_out);
  EXPECT_THAT(stream_out.str(), testing::HasSubstr("Peanut goes boing"))
      << "    Joey::Bounce should cout the name of the Joey and \"goes boing \", in this case \"Peanut goes boing\", using the parent method on Kangaroo";
}

TEST(JoeyTest, BounceCount) {
  Joey j("Josh");
  Kangaroo* roo = &j;
  ASSERT_EQ(0, roo->GetBounceCount()) << "    At construction, Kangaroo objects should have a 0 bounce count.";
  roo->Bounce();
  ASSERT_EQ(1, roo->GetBounceCount()) << "    After Kangaroo::Bounce is called once, Joey should have a 1 bounce count.";
  roo->Bounce();
  ASSERT_EQ(2, roo->GetBounceCount()) << "    After Kangaroo::Bounce is called twice, Joey objects should have a 2 bounce count.";
}

TEST(DoeTest, ConstructorAndGetAndSetName) {
  Doe d("Diane", "Joseph");
  Kangaroo* k = &d;
  ASSERT_EQ("Diane", k->GetName()) << "    Doe::GetName() should return the name passed in the constructor, using the Kangaroo class method";
  k->SetName("Di");
  ASSERT_EQ("Di", k->GetName()) << "    Doe::GetName() should return the name passed in Doe::SetName, using the Kangaroo class method";
}

TEST(DoeTest, Bounce) {
  Doe k("Dana", "James");
  std::streambuf* original_out = std::cout.rdbuf();
  std::stringstream stream_out;
  std::cout.rdbuf(stream_out.rdbuf());
  k.Bounce();
  std::cout.rdbuf(original_out);
  ASSERT_THAT(stream_out.str(), testing::HasSubstr("Dana goes boing"))
      << "    Doe::Bounce should cout the name of the Doe and \"goes boing \", in this case \"Dana goes boing\", using the parent method on Kangaroo";
  ASSERT_THAT(stream_out.str(), testing::HasSubstr("James goes boing"))
      << "    Doe::Bounce should call the Bounce method on its Joey. In this case we should also see \"James goes boing\" for a Doe with Joey \"James\".";
}

TEST(DoeTest, BounceCount) {
  Doe d("Dorthy", "Francis");
  ASSERT_EQ(0, d.GetBounceCount()) << "    At construction, Kangaroo objects should have a 0 bounce count.";
  ASSERT_EQ(0, d.GetJoey().GetBounceCount()) << "    At construction, Doe's Joey should have a 0 bounce count.";
  d.Bounce();
  ASSERT_EQ(1, d.GetBounceCount()) << "    After Doe::Bounce is called once, Doe should have a 1 bounce count.";
  ASSERT_EQ(1, d.GetJoey().GetBounceCount()) << "    After Doe::Bounce is called once, Doe's Joey should have a 1 bounce count.";
  d.Bounce();
  ASSERT_EQ(2, d.GetBounceCount()) << "    After Doe::Bounce is called twice, Doe objects should have a 2 bounce count.";
  ASSERT_EQ(2, d.GetJoey().GetBounceCount()) << "    After Doe::Bounce is called twice, Doe's Joey should have a 2 bounce count.";
}

TEST(DoeTest, ReturnsJoeyByReference) {
  Doe d("Dwitri", "Julio");
  Joey& j = d.GetJoey();
  j.SetName("Javiar");
  ASSERT_EQ("Javiar", d.GetJoey().GetName()) << "    Doe should return its Joey in GetJoey as a reference type.";
}

TEST(MainTest, BounceDoeOnceAndJoeyTwice) {
  std::string user_input = "Kanga\nRoo\nn\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, testing::MatchesRegex(
      ".*Kanga goes boing.*Roo goes boing.*Roo goes boing.*"))
      << "      Your program should ask for the name of the Doe and the name of her Joey, "
      "bounce them each once, and return when the user says \"n\". Because Doe::Bounce "
      "calls Joey::Bounce, we would see \"Roo goes boing\" printed twice.";
  });
}

TEST(MainTest, PrintsBounceCount) {
  std::string user_input = "Kanga\nRoo\nn\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, testing::MatchesRegex(
      ".*Kanga has bounced 1 time.*Roo has bounced 2 time.*"))
      << "      Your program should ask for the name of the Doe and the name of her Joey, "
      "bounce them each once, and return when the user says \"n\". Because Doe::Bounce "
      "calls Joey::Bounce, we would see \"Kanga has bounced 1 time\" and"
      "\"Roo has bounced 2 times\" (don't worry about time vs times grammar).";
  });
}

TEST(MainTest, MultipleRuns) {
  std::string user_input = "Kanga\nRoo\ny\ny\nn\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, testing::MatchesRegex(
      ".*Kanga has bounced 3 time.*Roo has bounced 6 time.*"))
      << "      Your program should ask for the name of the Doe and the name of her Joey, "
      "bounce them each once each time the user doesn't say \"n\". Because Doe::Bounce "
      "calls Joey::Bounce, we would see that when Kanga has bounced 3 times, Roo has bounced 6 times.";
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
