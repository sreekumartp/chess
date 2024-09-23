#include <gtest/gtest.h>
#include "bishop.h"

// Test fixture for Bishop class
class BishopTest : public ::testing::Test {
protected:
    Bishop* whiteBishop;
    Bishop* blackBishop;
    Point initialPosition;

    void SetUp() override {
        Point pt;
        pt.x = 0;
        pt.y = 1;
        initialPosition = pt; // Example initial position
        whiteBishop = new Bishop("White Bishop", true, initialPosition);
        blackBishop = new Bishop("Black Bishop", false, initialPosition);
    }

    void TearDown() override {
        delete whiteBishop;
        delete blackBishop;
    }
};

// Test case for getName method
TEST_F(BishopTest, GetName) {
    EXPECT_EQ(whiteBishop->getName(), "White Bishop");
    EXPECT_EQ(blackBishop->getName(), "Black Bishop");
}

// Test case for getPosition method
TEST_F(BishopTest, GetPosition) {
    EXPECT_EQ(whiteBishop->getPosition(), initialPosition);
    EXPECT_EQ(blackBishop->getPosition(), initialPosition);
}

// Test case for setPosition method
TEST_F(BishopTest, SetPosition) {
 
    Point newPosition;
    newPosition.x = 4;
    newPosition.y = 4;

    whiteBishop->setPosition(newPosition);
    EXPECT_EQ(whiteBishop->getPosition(), newPosition);

    blackBishop->setPosition(newPosition);
    EXPECT_EQ(blackBishop->getPosition(), newPosition);
}

// Add more tests as needed, for example, to test movement logic if implemented

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}