#include <gtest/gtest.h>
#include "queen.h"

TEST(QueenTest, GetName) {
    Point initialPosition = {0, 3};
    Queen queen("Queen", true, initialPosition);
    EXPECT_EQ(queen.getName(), "Queen");
}

TEST(QueenTest, GetPosition) {
    Point initialPosition = {0, 3};
    Queen queen("Queen", true, initialPosition);
    EXPECT_EQ(queen.getPosition(), initialPosition);
}

TEST(QueenTest, SetPosition) {
    Point initialPosition = {0, 3};
    Queen queen("Queen", true, initialPosition);
    Point newPosition = {4, 4};
    queen.setPosition(newPosition);
    EXPECT_EQ(queen.getPosition(), newPosition);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}