#ifndef FIGURE_H
#define FIGURE_H

#include <initializer_list>
#include <utility>
#include <iostream>
#include <vector>

class Figure{
    public:
    Figure();
    Figure(std::vector<std::pair<double, double>>& coords);
    Figure(const Figure& other);
    Figure(Figure&& other) noexcept;
    virtual ~Figure() = default;

    std::pair<double, double> geom_centre() const;
    friend std::ostream& operator<<(std::ostream& os, const Figure& fig);
    friend std::istream& operator>>(std::istream& is, Figure& figure);
    operator double() const;

    virtual const std::string who_am_i() const;

    Figure& operator =(const Figure& other);
    Figure& operator =(Figure&& other) noexcept;
    bool operator==(const Figure& other) const;

    protected:
    virtual bool is_valid() const;
    Figure(size_t number_of_coords);
    size_t number_of_coords;
    std::vector<std::pair<double, double>> coords;
};

#endif