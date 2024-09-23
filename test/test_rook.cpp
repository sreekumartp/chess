#include <gtest/gtest.h>
#include "rook.h"

TEST(RookTest, GetName) {
    Point initialPosition = {0, 0};
    Rook rook("Rook", true, initialPosition);
    EXPECT_EQ(rook.getName(), "Rook");
}

TEST(RookTest, GetPosition) {
    Point initialPosition = {0, 0};
    Rook rook("Rook", true, initialPosition);
    EXPECT_EQ(rook.getPosition().x, 0);
    EXPECT_EQ(rook.getPosition().y, 0);
}

TEST(RookTest, SetPosition) {
    Point initialPosition = {0, 0};
    Rook rook("Rook", true, initialPosition);
    Point newPosition = {3, 3};
    rook.setPosition(newPosition);
    EXPECT_EQ(rook.getPosition().x, 3);
    EXPECT_EQ(rook.getPosition().y, 3);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}