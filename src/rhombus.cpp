#include "rhombus.h"

Rhombus::Rhombus(){
    this->number_of_coords = 4;
    this->coords = {};
}

Rhombus::Rhombus(std::vector<std::pair<double, double>>& coords): Figure(coords) {
    if (!this->is_valid()){
        throw std::invalid_argument("Некорректные координаты для фигуры.");
    }
}

const std::string Rhombus::who_am_i() const {
    return "Rhombus";
}

bool Rhombus::is_valid() const {
    const size_t REQUIRED_POINTS = 4;

    return this->number_of_coords == REQUIRED_POINTS; 
}
