#include <gtest/gtest.h>
#include "figure.h"
#include "five_side.h"
#include <vector>
#include <sstream>

// Тесты для базового класса Figure
TEST(FigureTest, DefaultConstructor) {
    Figure fig;
    EXPECT_EQ(fig.who_am_i(), "Default figure");
}

TEST(FigureTest, GeometricCentre) {
    // Создаем через ввод, так как конструктор с координатами protected
    Figure fig;
    std::istringstream input("4\n0 0\n4 0\n4 4\n0 4\n");
    input >> fig;
    
    auto centre = fig.geom_centre();
    EXPECT_DOUBLE_EQ(centre.first, 2.0);
    EXPECT_DOUBLE_EQ(centre.second, 2.0);
}

TEST(FigureTest, GeometricCentreEmptyFigure) {
    Figure fig;
    EXPECT_THROW(fig.geom_centre(), std::runtime_error);
}

TEST(FigureTest, AreaCalculationSquare) {
    Figure fig;
    std::istringstream input("4\n0 0\n2 0\n2 2\n0 2\n");
    input >> fig;
    
    double area = static_cast<double>(fig);
    EXPECT_DOUBLE_EQ(area, 4.0);
}

TEST(FigureTest, AreaCalculationTriangle) {
    Figure fig;
    std::istringstream input("3\n0 0\n4 0\n0 3\n");
    input >> fig;
    
    double area = static_cast<double>(fig);
    EXPECT_DOUBLE_EQ(area, 6.0);
}

TEST(FigureTest, InputOperatorValidData) {
    Figure fig;
    std::istringstream input("3\n0 0\n1 0\n0 1\n");
    
    EXPECT_NO_THROW(input >> fig);
    EXPECT_EQ(fig.who_am_i(), "Default figure");
}

TEST(FigureTest, InputOperatorInvalidNumberOfPoints) {
    Figure fig;
    std::istringstream input("abc\n");
    
    EXPECT_THROW(input >> fig, std::invalid_argument);
}

TEST(FigureTest, InputOperatorInvalidCoordinates) {
    Figure fig;
    std::istringstream input("2\n0 0\nabc def\n");
    
    EXPECT_THROW(input >> fig, std::invalid_argument);
}

TEST(FigureTest, OutputOperator) {
    Figure fig;
    std::istringstream input("2\n1.5 2.5\n3.0 4.0\n");
    input >> fig;
    
    std::ostringstream output;
    output << fig;
    
    std::string expected = "(1.5, 2.5)\n(3, 4)\n";
    EXPECT_EQ(output.str(), expected);
}

TEST(FigureTest, CopyConstructor) {
    Figure fig1;
    std::istringstream input("3\n0 0\n1 0\n1 1\n");
    input >> fig1;
    
    Figure fig2(fig1);
    EXPECT_TRUE(fig1 == fig2);
    EXPECT_EQ(fig1.who_am_i(), fig2.who_am_i());
}

TEST(FigureTest, AssignmentOperator) {
    Figure fig1;
    std::istringstream input1("3\n0 0\n1 0\n1 1\n");
    input1 >> fig1;
    
    Figure fig2;
    std::istringstream input2("2\n2 2\n3 3\n");
    input2 >> fig2;
    
    fig2 = fig1;
    EXPECT_TRUE(fig1 == fig2);
}

TEST(FigureTest, MoveConstructor) {
    Figure fig1;
    std::istringstream input("3\n0 0\n1 0\n1 1\n");
    input >> fig1;
    
    Figure fig2(std::move(fig1));
    // После перемещения можем проверить только что объект создался
    EXPECT_EQ(fig2.who_am_i(), "Default figure");
}

TEST(FigureTest, MoveAssignmentOperator) {
    Figure fig1;
    std::istringstream input1("3\n0 0\n1 0\n1 1\n");
    input1 >> fig1;
    
    Figure fig2;
    std::istringstream input2("2\n2 2\n3 3\n");
    input2 >> fig2;
    
    fig2 = std::move(fig1);
    EXPECT_EQ(fig2.who_am_i(), "Default figure");
}

TEST(FigureTest, EqualityOperator) {
    Figure fig1;
    std::istringstream input1("2\n0 0\n1 1\n");
    input1 >> fig1;
    
    Figure fig2;
    std::istringstream input2("2\n0 0\n1 1\n");
    input2 >> fig2;
    
    Figure fig3;
    std::istringstream input3("2\n0 0\n2 2\n");
    input3 >> fig3;
    
    EXPECT_TRUE(fig1 == fig2);
    EXPECT_FALSE(fig1 == fig3);
}

// Тесты для класса-наследника Five_Side
TEST(FiveSideTest, ConstructorWithValidCoords) {
    // Используем фабричный метод через ввод
    Five_Side five;
    std::istringstream input("5\n0 0\n1 0\n1.5 0.5\n1 1\n0 1\n");
    
    EXPECT_NO_THROW(input >> five);
    EXPECT_EQ(five.who_am_i(), "Five_Side");
}

TEST(FiveSideTest, ConstructorWithInvalidCoords) {
    Five_Side five;
    std::istringstream input("3\n0 0\n1 0\n1 1\n"); // Всего 3 точки вместо 5
    
    EXPECT_THROW(input >> five, std::invalid_argument);
}

TEST(FiveSideTest, GeometricCentreFiveSide) {
    Five_Side five;
    std::istringstream input("5\n0 0\n4 0\n4 4\n2 6\n0 4\n");
    input >> five;
    
    auto centre = five.geom_centre();
    // Центр масс пяти точек
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
    // Площадь должна быть положительной
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
    std::istringstream input("4\n0 0\n1 0\n1 1\n0 1\n"); // Только 4 точки
    
    EXPECT_THROW(input >> five, std::invalid_argument);
}

// Тест полиморфного поведения
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

// Тест для демонстрации работы с разными фигурами через базовый класс
TEST(MultipleFiguresTest, MixedFigures) {
    Figure triangle;
    std::istringstream triangle_input("3\n0 0\n3 0\n0 4\n");
    triangle_input >> triangle;
    
    Five_Side five;
    std::istringstream five_input("5\n0 0\n2 0\n3 1\n2 2\n0 2\n");
    five_input >> five;
    
    EXPECT_EQ(triangle.who_am_i(), "Default figure");
    EXPECT_EQ(five.who_am_i(), "Five_Side");
    
    double triangle_area = static_cast<double>(triangle);
    double five_area = static_cast<double>(five);
    
    EXPECT_DOUBLE_EQ(triangle_area, 6.0); // 3*4/2 = 6
    EXPECT_GT(five_area, 0.0);
}

// Тесты на особые случаи
TEST(EdgeCasesTest, EmptyFigureArea) {
    Figure fig;
    double area = static_cast<double>(fig);
    EXPECT_DOUBLE_EQ(area, 0.0);
}

TEST(EdgeCasesTest, TwoPointsFigureArea) {
    Figure fig;
    std::istringstream input("2\n0 0\n1 1\n");
    input >> fig;
    
    double area = static_cast<double>(fig);
    EXPECT_DOUBLE_EQ(area, 0.0);
}

TEST(EdgeCasesTest, SelfAssignment) {
    Figure fig;
    std::istringstream input("3\n0 0\n1 0\n0 1\n");
    input >> fig;
    
    Figure& ref = fig;
    fig = ref; // self-assignment
    
    EXPECT_EQ(fig.who_am_i(), "Default figure");
}
