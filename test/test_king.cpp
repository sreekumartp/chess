#include <gtest/gtest.h>
#include "king.h"

TEST(KingTest, GetName) {
    Point initialPosition = {0, 0};
    King king("King", true, initialPosition);
    EXPECT_EQ(king.getName(), "King");
}

TEST(KingTest, GetPosition) {
    Point initialPosition = {0, 0};
    King king("King", true, initialPosition);
    EXPECT_EQ(king.getPosition(), initialPosition);
}

TEST(KingTest, SetPosition) {
    Point initialPosition = {0, 0};
    King king("King", true, initialPosition);
    Point newPosition = {1, 1};
    king.setPosition(newPosition);
    EXPECT_EQ(king.getPosition(), newPosition);
}

TEST(KingTest, IsWhite) {
    Point initialPosition = {0, 0};
    King king("King", true, initialPosition);
    EXPECT_TRUE(king.getIsWhite());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}