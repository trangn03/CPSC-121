#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "../../cpputils/graphics/test/test_event_generator.h"
#include "../../raindrop.h"
#include "../../rainstorm.h"
#include "../cppaudit/gtest_ext.h"
#include "../../cpputils/graphics/test/image_test_utils.h"

namespace {
graphics::Color kWhite(255, 255, 255);
}

TEST(RaindropTest, ConstructorAndGetter) {
  graphics::Image image(50, 50);
  Raindrop drop(&image, 15, 25, 0);
  ASSERT_EQ(25, drop.GetY())
      << "    Raindrop::GetY() should return the y coordinate passed as the "
         "third paramter to the constructor.";
}

TEST(RaindropTest, FallAddsRate) {
  graphics::Image image(50, 50);
  Raindrop drop(&image, 15, 24, 1);
  ASSERT_EQ(24, drop.GetY())
      << "    Raindrop::GetY() should return the y coordinate passed as the "
         "third paramter to the constructor.";
  drop.Fall();
  ASSERT_EQ(25, drop.GetY())
      << "    Raindrop::Fall() should increment the y coordinate by adding the "
         "rate, which was passed as the fourth parameter to the constructor.";

  Raindrop fast_drop(&image, 10, 15, 3);
  ASSERT_EQ(15, fast_drop.GetY())
      << "    Raindrop::GetY() should return the y coordinate passed as the "
         "third paramter to the constructor.";
  fast_drop.Fall();
  ASSERT_EQ(18, fast_drop.GetY())
      << "    Raindrop::Fall() should increment the y coordinate by adding the "
         "rate, which was passed as the fourth parameter to the constructor.";
}

TEST(RaindropTest, Draw) {
  std::string diff_image = "raindrop_draw_expected_v_actual.bmp";
  remove(diff_image.c_str());

  graphics::Image image(50, 50);
  Raindrop drop(&image, 25, 15, 0);
  drop.Draw();

  graphics::Color drop_color = kWhite;
  for (int i = 0; i < 50; i++) {
    for (int j = 0; j < 50; j++) {
      if (image.GetColor(i, j) != kWhite) {
        if (drop_color == kWhite) {
          drop_color = image.GetColor(i, j);
        } else if (drop_color != image.GetColor(i, j)) {
          FAIL() << "    Found more than one color after calling "
                    "Raindrop::Draw. You must draw only a solid colored circle "
                    "with 10 px diameter.";
        }
      }
    }
  }

  graphics::Image expected(50, 50);
  expected.DrawCircle(25, 15, 10, drop_color);
  bool match =
      ImagesMatch(&expected, &image, diff_image, DiffType::kTypeSideBySide);
  ASSERT_TRUE(match) << "    Your Raindrop::Draw function isn't quite right. "
                        "See expected vs actual output at "
                     << diff_image;
}

// Gets the color of the raindrop.
class RainstormTest : public testing::Test {
 public:
  void SetUp() override {
    srand(0);
    image_.Initialize(50, 50);
    Raindrop drop(&image_, 25, 25, 1);
    drop.Draw();
    color_ = image_.GetColor(25, 25);
  }

  const graphics::Color& GetDropColor() { return color_; }

 private:
  graphics::Image image_;
  graphics::Color color_;
};

TEST_F(RainstormTest, StarterCodeAsExpected) {
  // Check image size.
  Rainstorm storm;
  storm.Initialize(1);
  graphics::Image* image = storm.GetImageForTesting();
  ASSERT_EQ(image->GetWidth(), 300)
      << "    Image width must be set to 300 after initialize.";
  ASSERT_EQ(image->GetHeight(), 300)
      << "    Image height must be set to 300 after initialize.";

  // Check it's an AnimationEventListener.
  bool is_listener =
      std::is_base_of<graphics::AnimationEventListener, Rainstorm>::value;
  ASSERT_TRUE(is_listener)
      << "    Rainstorm should inherit from graphics::AnimationEventListener";
}

TEST_F(RainstormTest, InitializeOneDrop) {
  std::string diff_image = "one_drop_expected_v_actual.bmp";
  remove(diff_image.c_str());

  Rainstorm storm;
  storm.Initialize(1);
  graphics::Image* image = storm.GetImageForTesting();

  srand(0);
  graphics::Image expected(300, 300);
  int x = rand() % 300;
  int y = rand() % 300;
  expected.DrawCircle(x, y, 10, GetDropColor());
  bool match =
      ImagesMatch(&expected, image, diff_image, DiffType::kTypeSideBySide);
  ASSERT_TRUE(match)
      << "    Your Rainstorm::Initialize function doesn't place your drops in "
         "the right place. Use the given code to initialize the x, y and rate "
         "for each raindrop, then Draw each raindrop. See expected vs actual "
         "output for 1 raindrop at "
      << diff_image;
}

TEST_F(RainstormTest, AnimateOneDrop) {
  std::string diff_image = "one_drop_animated_expected_v_actual.bmp";
  remove(diff_image.c_str());

  Rainstorm storm;
  storm.Initialize(1);
  graphics::Image* image = storm.GetImageForTesting();
  image->Show();
  graphics::TestEventGenerator generator(image);
  generator.SendAnimationEvent();

  srand(0);
  graphics::Image expected(300, 300);
  int x = rand() % 300;
  int y = rand() % 300;
  int rate = rand() % 2 ? 3 : 5;
  expected.DrawCircle(x, y + rate, 10, GetDropColor());
  bool match =
      ImagesMatch(&expected, image, diff_image, DiffType::kTypeSideBySide);
  ASSERT_TRUE(match)
      << "    Your Rainstorm::OnAnimationEvent function isn't quite right or "
         "your raindrops were not in the right place. You should call "
         "Raindrop::Fall() before Raindrop::Draw(). See expected vs actual "
         "output for 1 raindrop at "
      << diff_image;
}

TEST_F(RainstormTest, AnimateOneDropOffTheBottomEdge) {
  std::string diff_image = "one_drop_animated_off_edge_expected_v_actual.bmp";
  remove(diff_image.c_str());

  srand(0);
  graphics::Image expected(300, 300);
  int x = rand() % 300;
  int y = rand() % 300;
  int rate = rand() % 2 ? 3 : 5;
  int x2 = rand() % 300;
  int y2_unused = rand() % 300;
  int rate2 = rand() % 2 ? 3 : 5;
  expected.DrawCircle(x2, 0, 10, GetDropColor());
  int count = (300 - y + 1) / rate;

  srand(0);
  Rainstorm storm;
  storm.Initialize(1);
  graphics::Image* image = storm.GetImageForTesting();
  image->Show();
  graphics::TestEventGenerator generator(image);
  for (int i = 0; i < count; i++) {
    generator.SendAnimationEvent();
  }

  bool match =
      ImagesMatch(&expected, image, diff_image, DiffType::kTypeSideBySide);
  ASSERT_TRUE(match)
      << "    Your Rainstorm::OnAnimationEvent function isn't quite right or "
         "your raindrops were not in the right place. You should call "
         "Raindrop::Fall() before Raindrop::Draw(). See expected vs actual "
         "output for 1 raindrop at "
      << diff_image;
}

// TODO: AnimateManyDrops is not passing, and probably would be ncie
// to have helper functions called RandomTo300 or RandomRate??

TEST_F(RainstormTest, AnimateManyDrops) {
  std::string diff_image = "many_drops_animated_expected_v_actual.bmp";
  remove(diff_image.c_str());

  Rainstorm storm;
  const int num_drops = 20;
  storm.Initialize(num_drops);
  graphics::Image* image = storm.GetImageForTesting();
  image->Show();
  graphics::TestEventGenerator generator(image);
  const int num_animations = 1;
  for (int i = 0; i < num_animations; i++) {
    generator.SendAnimationEvent();
  }

  struct Drop {
    int x;
    int y;
    int rate;
  };

  srand(0);
  graphics::Image expected(300, 300);
  std::vector<Drop> drops;
  for (int i = 0; i < num_drops; i++) {
    Drop drop;
    drop.x = rand() % 300;
    drop.y = rand() % 300;
    drop.rate = rand() % 2 ? 3 : 5;
    drops.push_back(drop);
  }
  for (int i = 0; i < num_animations; i++) {
    for (Drop& drop : drops) {
      drop.y += drop.rate;
      if (drop.y >= 300) {
        drop.x = rand() % 300;
        drop.y =
            rand() % 300;  // Unused rand for CalculateRandomRaindropParams.
        drop.y = 0;
        drop.rate = rand() % 2 ? 3 : 5;
      }
    }
  }
  for (Drop drop : drops) {
    expected.DrawCircle(drop.x, drop.y, 10, GetDropColor());
  }

  bool match =
      ImagesMatch(&expected, image, diff_image, DiffType::kTypeSideBySide);
  ASSERT_TRUE(match)
      << "    Your Rainstorm::OnAnimationEvent function isn't quite right or "
         "your raindrops were not in the right place. You should call "
         "Raindrop::Fall() before Raindrop::Draw(). See expected vs actual "
         "output for 20 raindrops after 50 cycles at "
      << diff_image;
}

TEST(MainTest, StartShowsImage) {
  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  system("timeout 1s ./main");
  end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end - start;
  std::chrono::milliseconds ms =
      std::chrono::duration_cast<std::chrono::milliseconds>(elapsed_seconds);
  if (ms.count() <= 900) {
    FAIL() << "    main() should call Rainstorm::Start() which calls "
              "Image::ShowUntilClosed().";
  }
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
