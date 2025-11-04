#include "figure.h"
#include "array.h"
#include "rhombus.h"
#include "five_side.h"
#include "six_side.h"
#include <iostream>

int main(){

    std::vector<std::pair<double, double>> rhombus_coords = {{2, 2}, {4, 0},{2, -2}, {0, 0} };

    Rhombus rhombus(rhombus_coords);
    std::cout << rhombus.who_am_i() << " area: " << double(rhombus) << std::endl;
    std::cout << rhombus;
    // Rhombus rhombus2;
    // std::cin >> rhombus2;
    // std::cout << rhombus2.who_am_i() << " area: " << double(rhombus2) << std::endl;
    // std::cout << rhombus2;

    std::vector<std::pair<double, double>> pentagon_coords = {{0, 4}, {-3, 1}, {-2, -3}, {2, -3}, {3, 1}};
    Five_Side pentagon(pentagon_coords);

    std::cout << pentagon.who_am_i() << " area: " << double(pentagon) << std::endl;

    std::vector<std::pair<double, double>> hexagon_coords = {{0, 2}, {-2, 1}, {-2, -1}, {0, -2}, {2, -1}, {2, 1}};
    Six_Side hexagon(hexagon_coords);

    std::cout << hexagon.who_am_i() << " area: " << double(hexagon) << std::endl;

    Array my_array{&rhombus, &pentagon, &hexagon};

    my_array.print_info(); 
    my_array.remove_figure(1);
    my_array.print_info();

    std::vector<std::pair<double, double>> rhombus_coords3 = {{0, 2}, {1, 0}, {0, -2}, {-1, 0}};
    std::vector<std::pair<double, double>> rhombus_coords4 = {{0, 3}, {2, 0}, {0, -3}, {-2, 0}};

    Rhombus romb3(rhombus_coords3);
    Rhombus romb4(rhombus_coords4);
    std::cout << my_array.total_area() << std::endl;
    my_array.add_figure(&romb3);
    my_array.add_figure(&romb4);
    std::cout << "------------------" << std::endl;
    my_array.print_info();
    std::cout << my_array.total_area() << std::endl;
    return 0;
}