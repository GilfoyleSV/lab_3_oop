#include "figure.h"
#include <stdexcept>
#include <math.h>

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
}

std::istream& operator>>(std::istream& is, Figure& figure){
    figure.coords.clear();
    size_t num_of_points;

    is >> num_of_points;

    if (!is || num_of_points == 0){
        throw std::invalid_argument("Неправильный ввод");
    }

    figure.number_of_coords = num_of_points;
    
    for (int i=0;i!=num_of_points;i++){
        double x, y;
        is >> x >> y;
        if (!is){
            throw std::invalid_argument("Неправильный ввод");
        }
        figure.coords.push_back({x, y});
    }

    return is;
}

std::ostream& operator<<(std::ostream& os, const Figure& figure){
    for (int i=0; i != figure.number_of_coords; i++){
        os << figure.coords[i].first << figure.coords[i].second << std::endl;
    }
    return os;
}

std::pair<double, double> Figure::geom_centre(){
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

    for (int i=0; i != this->number_of_coords - 1; i++){
        double x, y, x1, y1;
        x = this->coords[i].first;
        y = this->coords[i].second;
        x1 = this->coords[i + 1].first;
        y1 = this->coords[i + 1].second;
        s += std::abs(x * y1 - y * x1);
    }
    return s * 1/2;
}

Figure& Figure::operator=(const Figure& other){
    if (this != &other){
        this->coords = other.coords;
        this->number_of_coords = other.number_of_coords;
    }
    return *this;
}

Figure& Figure::operator=(Figure&& other){
    if (this != &other){
        this->coords = std::move(other.coords);
        this->number_of_coords = std::move(other.number_of_coords);
    }
    return *this;
}

bool Figure::operator==(const Figure& other) const{
    return this->coords == other.coords;
}