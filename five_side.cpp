#include "five_side.h"

Five_Side::Five_Side(std::vector<std::pair<double, double>>& coords): Figure(coords) {
    if (!this->is_valid()){
        throw std::invalid_argument("Некорректные координаты для пятиугольника: фигура не является пятиугольником или имеет не 5 точек.");
    }
}


const std::string Five_Side::who_am_i() const {
    return "Five_Side";
}

bool Five_Side::is_valid() const {
    const size_t REQUIRED_POINTS = 5;

    return this->number_of_coords == REQUIRED_POINTS; 
}