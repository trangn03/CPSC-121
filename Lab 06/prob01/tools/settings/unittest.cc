#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "../cppaudit/gtest_ext.h"
#include "../../radio_button.h"

using ::testing::HasSubstr;

TEST(RadioButtonTest, SetAndGetText) {
  RadioButton button;
  button.SetText("Hello world");
  ASSERT_EQ("Hello world", button.GetText())
      << "    GetText should return the text value passed to SetText";
}

TEST(RadioButtonTest, SetAndGetSelected) {
  RadioButton button;
  button.SetSelected(true);
  ASSERT_TRUE(button.IsSelected())
      << "    IsSelected should return the bool passed to SetSelected.";
  button.SetSelected(false);
  ASSERT_FALSE(button.IsSelected())
      << "    IsSelected should return the bool passed to SetSelected.";
}

TEST(RadioButtonTest, SetsSelectedWithOneSelectedButton) {
  RadioButton button;
  button.SetSelected(true);
  std::vector<RadioButton> buttons;
  buttons.push_back(button);
  SelectRadioButton(buttons, 0);
  ASSERT_TRUE(buttons[0].IsSelected()) << "    Your SelectRadioButton should "
      "call SetSelected(true) on the radio button at the index passed in. In "
      "this test, the vector was size 1 and the RadioButton was selected.";
}

TEST(RadioButtonTest, SetsSelectedWithOneButton) {
  RadioButton button;
  button.SetSelected(false);
  std::vector<RadioButton> buttons;
  buttons.push_back(button);
  SelectRadioButton(buttons, 0);
  ASSERT_TRUE(buttons[0].IsSelected()) << "    Your SelectRadioButton should "
      "call SetSelected(true) on the radio button at the index passed in. In "
      "this test, the vector was size 1 and the RadioButton was deselected. "
      "Ensure your std::vector<RadioButtons> is passed by reference.";
}

TEST(RadioButtonTest, SetsSelectedWithThreeButtons) {
  std::vector<RadioButton> buttons;
  for (int i = 0; i < 3; i++) {
    RadioButton button;
    button.SetSelected(false);
    buttons.push_back(button);
  }
  for (int i = 2; i >= 0; i--) {
    SelectRadioButton(buttons, i);
    ASSERT_TRUE(buttons[i].IsSelected()) << "    SelectRadioButton should set "
        "the button at index " << i << " selected in a vector of 3 buttons when"
        "the index passed is " << i;
  }
}

TEST(RadioButtonTest, DeselectsOtherRadioButtonsOnSelection) {
  std::vector<RadioButton> buttons;
  int size = 10;
  for (int i = 0; i < size; i++) {
    RadioButton button;
    button.SetSelected(true);
    buttons.push_back(button);
  }
  for (int i = size - 1; i >= 0; i--) {
    SelectRadioButton(buttons, i);
    ASSERT_TRUE(buttons[i].IsSelected()) << "    SelectRadioButton should set "
        "the button at index " << i << " selected in a vector of " << size
        << " buttons when the index passed is " << i;
    for (int j = 0; j < size; j++) {
      if (i == j) {
        continue;
      }
      ASSERT_FALSE(buttons[j].IsSelected())
          << "   SelectRadioButton should set the button at index " << j <<
          " to deselected when selecting the button at index " << i;
    }
  }
}

TEST(RadioButtonTest, PrintOneDeselectedButton) {
  std::vector<RadioButton> buttons;
  RadioButton button;
  button.SetSelected(false);
  button.SetText("Bagel");
  buttons.push_back(button);

  std::streambuf* original_out = std::cout.rdbuf();
  std::stringstream stream_out;
  std::cout.rdbuf(stream_out.rdbuf());

  const std::vector<RadioButton>& copy = buttons;
  PrintRadioButtons(buttons);

  std::cout.rdbuf(original_out);
  ASSERT_THAT(stream_out.str(), testing::HasSubstr("( ) Bagel"))
      << "    For one radio button with text \"Bagel\" which is unselected, "
      << "the PrintRadioButtons function should print out exactly \"( ) Bagel\"";

  ASSERT_THAT(stream_out.str(), testing::HasSubstr("No button selected"))
      << "    For one radio button which is unselected, the PrintRadioButtons "
      << " function should print \"No button selected yet\"";

  ASSERT_THAT(stream_out.str(), testing::MatchesRegex(
      ".*Bagel.*No button selected.*")) << "    PrintRadioButtons should "
      "print the individual radio buttons before the summary.";
}

TEST(RadioButtonTest, PrintOneSelectedButton) {
  std::vector<RadioButton> buttons;
  RadioButton button;
  button.SetSelected(true);
  button.SetText("Toast");
  buttons.push_back(button);

  std::streambuf* original_out = std::cout.rdbuf();
  std::stringstream stream_out;
  std::cout.rdbuf(stream_out.rdbuf());

  PrintRadioButtons(buttons);

  std::cout.rdbuf(original_out);
  ASSERT_THAT(stream_out.str(), testing::HasSubstr("(*) Toast"))
      << "    For one radio button with text \"Toast\" which is selected, "
      << "the PrintRadioButtons function should print out exactly \"( ) Toast\"";

  ASSERT_THAT(stream_out.str(), testing::HasSubstr("he button at index 0 is selected"))
      << "    For one radio button which is selected, the PrintRadioButtons "
      << " function should print \"The button at index 0 is selected\"";

  ASSERT_THAT(stream_out.str(), testing::MatchesRegex(
      ".* Toast.*[tT]+he button at index 0 is selected.*"))
      << "    PrintRadioButtons should print the individual radio buttons before the summary.";
}

TEST(RadioButtonTest, PrintsManyButtonsSomeSelected) {
  std::vector<RadioButton> buttons;
  int size = 10;
  for (int i = 0; i < size; i++) {
    RadioButton button;
    button.SetText("button " + std::to_string(i));
    button.SetSelected(false);
    buttons.push_back(button);
  }
  int index = rand() % 10;
  buttons[index].SetSelected(true);

  std::streambuf* original_out = std::cout.rdbuf();
  std::stringstream stream_out;
  std::cout.rdbuf(stream_out.rdbuf());

  PrintRadioButtons(buttons);

  std::cout.rdbuf(original_out);
  ASSERT_THAT(stream_out.str(), testing::HasSubstr("(*) button " + std::to_string(index)))
      << "    For a vector of many radio buttons, the selected one with name \""
      << "button " << index << "\" should be printed as \"(*) button " << index
      << "\"";

  for (int i = 0; i < size; i++) {
    if (i == index) {
      continue;
    }
    ASSERT_THAT(stream_out.str(), testing::HasSubstr("( ) button " + std::to_string(i)))
        << "    For a vector of many radio buttons, a deselected one with name \""
        << "button " << i << "\" at index " << i << " should be printed as \"( ) button " << i
        << "\" when index " << index << " is selected instead.";
  }
}

TEST(MainTest, ExecutesAndExits) {
  ASSERT_EXECEXIT("main", "0\n", 3) << "    Your program should exit if the user "
      "asks for 0 radio buttons (the starter code should already do this.)";
}

TEST(MainTest, OneButton) {
  std::string user_input = "1\ncandycane\n0\nquit\n";
  ASSERT_DURATION_LE(3, {
        ASSERT_EXECTHAT(
            "main", user_input,
            testing::MatchesRegex(".*\\( \\) candycane.*No button selected.*\\(\\*\\) candycane.*The button at index 0 is selected.*")) <<
            "Hint: Check that you print the buttons before entering the do/while loop, and print them again after setting a new selected button in the do/while loop.";
  });
}

TEST(MainTest, SeveralButtons) {
  std::string user_input = "3\nicecream\nsoda\npoprocks\n2\n0\n1\nquit\n";
  ASSERT_DURATION_LE(3, {
        ASSERT_EXECTHAT(
            "main", user_input,
            testing::MatchesRegex(".*No button selected.*\\( \\) icecream.*"
            "\\(\\*\\) soda.*\\( \\) poprocks.*The button at index 1 is selected.*")) <<
            "Hint: Check that you print the buttons before entering the do/while loop, and print them again after setting a new selected button in the do/while loop.";
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
