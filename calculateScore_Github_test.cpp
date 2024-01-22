// write 5 unit test cases below for calculateScore_Github.cpp using Google Test

#include "calculateScore_Github.cpp"
#include <gtest/gtest.h>

TEST(BowlingGame, allZeros) {
    BowlingGame game;
    for (int i = 0; i < 20; i++) {
        game.roll(0);
    }
    EXPECT_EQ(0, game.score());
}

TEST(BowlingGame, allOnes) {
    BowlingGame game;
    for (int i = 0; i < 20; i++) {
        game.roll(1);
    }
    EXPECT_EQ(20, game.score());
}

TEST(BowlingGame, oneSpare) {
    BowlingGame game;
    game.roll(5);
    game.roll(5);
    game.roll(3);
    for (int i = 0; i < 17; i++) {
        game.roll(0);
    }
    EXPECT_EQ(16, game.score());
}

TEST(BowlingGame, oneStrike) {
    BowlingGame game;
    game.roll(10);
    game.roll(3);
    game.roll(4);
    for (int i = 0; i < 16; i++) {
        game.roll(0);
    }
    EXPECT_EQ(24, game.score());
}

TEST(BowlingGame, perfectGame) {
    BowlingGame game;
    for (int i = 0; i < 12; i++) {
        game.roll(10);
    }
    EXPECT_EQ(300, game.score());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}