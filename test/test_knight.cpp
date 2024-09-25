#include <gtest/gtest.h>
#include "knight.hpp"

TEST(KnightTest, Initialization) {
    Point initialPosition = {0, 1};
    Knight knight("Knight", true, initialPosition);

    EXPECT_EQ(knight.getName(), "Knight");
    EXPECT_TRUE(knight.getIsWhite());
    EXPECT_EQ(knight.getPosition().x, 0);
    EXPECT_EQ(knight.getPosition().y, 1);
}

TEST(KnightTest, SetPosition) {
    Point initialPosition = {0, 1};
    Knight knight("Knight", true, initialPosition);

    Point newPosition = {2, 2};
    knight.setPosition(newPosition);

    EXPECT_EQ(knight.getPosition().x, 2);
    EXPECT_EQ(knight.getPosition().y, 2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}