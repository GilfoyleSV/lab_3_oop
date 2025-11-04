#include "six_side.h"

Six_Side::Six_Side(std::vector<std::pair<double, double>>& coords): Figure(coords) {
    if (!this->is_valid()){
        throw std::invalid_argument("Некорректные координаты для шестиугольника: фигура не является шестиугольником или имеет не 6 точек.");
    }
}


const std::string Six_Side::who_am_i() const {
    return "Six_Side";
}

bool Six_Side::is_valid() const {
    const size_t REQUIRED_POINTS = 6;

    return this->number_of_coords == REQUIRED_POINTS; 
}