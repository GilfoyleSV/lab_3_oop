#include <gtest/gtest.h>
#include "figure.h"
#include "five_side.h"
#include <vector>
#include <sstream>

TEST(FiveSideTest, ConstructorWithValidCoords) {
    Five_Side five;
    std::istringstream input("5\n0 0\n1 0\n1.5 0.5\n1 1\n0 1\n");
    
    EXPECT_NO_THROW(input >> five);
    EXPECT_EQ(five.who_am_i(), "Five_Side");
}

TEST(FiveSideTest, ConstructorWithInvalidCoords) {
    Five_Side five;
    std::istringstream input("3\n0 0\n1 0\n1 1\n");
    
    EXPECT_THROW(input >> five, std::invalid_argument);
}

TEST(FiveSideTest, GeometricCentreFiveSide) {
    Five_Side five;
    std::istringstream input("5\n0 0\n4 0\n4 4\n2 6\n0 4\n");
    input >> five;
    
    auto centre = five.geom_centre();
    double expected_x = (0 + 4 + 4 + 2 + 0) / 5.0;
    double expected_y = (0 + 0 + 4 + 6 + 4) / 5.0;
    
    EXPECT_DOUBLE_EQ(centre.first, expected_x);
    EXPECT_DOUBLE_EQ(centre.second, expected_y);
}

TEST(FiveSideTest, AreaCalculationFiveSide) {
    Five_Side five;
    std::istringstream input("5\n0 0\n4 0\n4 4\n2 6\n0 4\n");
    input >> five;
    
    double area = static_cast<double>(five);
    EXPECT_GT(area, 0.0);
}

TEST(FiveSideTest, InputOperatorValidFiveSide) {
    Five_Side five;
    std::istringstream input("5\n0 0\n1 0\n1.5 0.5\n1 1\n0 1\n");
    
    EXPECT_NO_THROW(input >> five);
    EXPECT_EQ(five.who_am_i(), "Five_Side");
}

TEST(FiveSideTest, InputOperatorInvalidFiveSide) {
    Five_Side five;
    std::istringstream input("4\n0 0\n1 0\n1 1\n0 1\n");
    
    EXPECT_THROW(input >> five, std::invalid_argument);
}

TEST(PolymorphismTest, WhoAmIThroughBasePointer) {
    Five_Side five;
    std::istringstream input("5\n0 0\n1 0\n1.5 0.5\n1 1\n0 1\n");
    input >> five;
    
    Figure* figurePtr = &five;
    EXPECT_EQ(figurePtr->who_am_i(), "Five_Side");
}

TEST(PolymorphismTest, AreaThroughBasePointer) {
    Five_Side five;
    std::istringstream input("5\n0 0\n4 0\n4 4\n2 6\n0 4\n");
    input >> five;
    
    Figure* figurePtr = &five;
    double area = static_cast<double>(*figurePtr);
    EXPECT_GT(area, 0.0);
}

