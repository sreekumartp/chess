#ifndef TEST_PAWN_H
#define TEST_PAWN_H

#include <gtest/gtest.h>
#include "pawn.h"



TEST(PawnTest, GetName) {
    Point pt;
    pt.x = 0;
    pt.y = 1;
    Pawn pawn("Pawn1", true, pt);
    EXPECT_EQ(pawn.getName(), "Pawn1");
}

TEST(PawnTest, GetPosition) {
    Point pt;
    pt.x = 0;
    pt.y = 1;
    Pawn pawn("Pawn1", true, pt);
    Point pos = pawn.getPosition();
    EXPECT_EQ(pos.x, 0);
    EXPECT_EQ(pos.y, 1);
}

TEST(PawnTest, SetPosition) {
    Point pt;
    pt.x = 0;
    pt.y = 1;
    Point newpt;
    newpt.x = 1;
    newpt.y = 2;
    Pawn pawn("Pawn1", true, pt);
    pawn.setPosition(newpt);
    Point pos = pawn.getPosition();
    EXPECT_EQ(pos.x, 1);
    EXPECT_EQ(pos.y, 2);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


#endif // TEST_PAWN_H