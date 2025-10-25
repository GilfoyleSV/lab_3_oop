#ifndef ARRAY_H
#define ARRAY_H
#include "figure.h"
#include <string>

class Array{
    public:
    Array();
    Array(const std::initializer_list<Figure*>& lst);
    Array(const Array& other);
    Array(Array&& other) noexcept;

    Array& operator=(const Array& other);
    Array& operator=(Array&& other) noexcept;

    void print_info() const;
    double total_area() const;
    void remove_figure(size_t i);
    void add_figure(Figure* fig);
    ~Array() noexcept;

    private:
    size_t length;
    Figure** array_of_figures;
    size_t capacity;

    void grow();
};

#endif