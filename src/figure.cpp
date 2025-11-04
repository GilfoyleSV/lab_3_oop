#include "figure.h"
#include <stdexcept>
#include <math.h>

Figure::Figure(){
    this->number_of_coords = 0;
    this->coords = {};
}

Figure::Figure(size_t number_of_coords){
    this->number_of_coords = number_of_coords;
}

Figure::Figure(std::vector<std::pair<double, double>>& coords){
    this->number_of_coords = coords.size();
    this->coords = coords;
}

Figure::Figure(const Figure& other){
    this->number_of_coords = other.number_of_coords;
    this->coords = other.coords;
}

Figure::Figure(Figure&& other) noexcept{
    this->number_of_coords = other.number_of_coords;
    this->coords = std::move(other.coords);
    other.number_of_coords = 0;
}

std::istream& operator>>(std::istream& is, Figure& figure){
    size_t num_of_points;

    is >> num_of_points;

    if (!is){
        throw std::invalid_argument("Неправильный ввод: не удалось считать количество точек.");
    }
    figure.coords.clear();
    figure.number_of_coords = num_of_points;
    
    for (size_t i = 0; i != num_of_points; i++){
        double x, y;
        is >> x >> y;
        if (!is){
            throw std::invalid_argument("Неправильный ввод: не удалось считать координаты.");
        }
        figure.coords.push_back({x, y});
    }

    if (!is){
        throw std::invalid_argument("Неправильный ввод: ошибка после считывания данных.");
    }
    
    if (!figure.is_valid()){
        throw std::invalid_argument("Введенные данные не соответствуют требованиям фигуры.");
    }

    return is;
}

std::ostream& operator<<(std::ostream& os, const Figure& figure){
    for (size_t i = 0; i != figure.number_of_coords; i++){
        os << "(" << figure.coords[i].first << ", " << figure.coords[i].second << ")" << std::endl;
    }
    return os;
}

std::pair<double, double> Figure::geom_centre() const{
    if (this->number_of_coords == 0){
        throw std::runtime_error("Фигура не имеет точек, невозможно вычислить геометрический центр.");
    }

    double x_sum = 0;
    double y_sum = 0;

    for (const auto& point: this->coords){
        x_sum += point.first;
        y_sum += point.second;
    }

    x_sum /= this->number_of_coords;
    y_sum /= this->number_of_coords;

    return {x_sum, y_sum};
}

Figure::operator double() const {
    double s = 0;
    if (this->number_of_coords < 3){
        return 0.0;
    }
    double x, y, x1, y1;
    for (size_t i=0; i != this->number_of_coords; i++){
        x = this->coords[i].first;
        y = this->coords[i].second;
        double x2 = this->coords[(i + 1) % this->number_of_coords].first;
        double y2 = this->coords[(i + 1) % this->number_of_coords].second;
        s += std::abs(x * y1 - y * x1);
    }
    
    return std::abs(s) / 2.0;
}

Figure& Figure::operator=(const Figure& other){
    if (this != &other){
        this->coords = other.coords;
        this->number_of_coords = other.number_of_coords;
    }
    return *this;
}

Figure& Figure::operator=(Figure&& other) noexcept{
    if (this != &other){
        this->coords = std::move(other.coords);
        this->number_of_coords = other.number_of_coords;
        other.number_of_coords = 0; 
    }
    return *this;
}

const std::string Figure::who_am_i() const{
    return "Default figure";
}

bool Figure::operator==(const Figure& other) const{
    return this->coords == other.coords;
}

bool Figure::is_valid() const{
    return this->number_of_coords >= 0;
}