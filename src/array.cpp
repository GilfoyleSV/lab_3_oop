#include "array.h"
#include "figure.h"
#define START_CAPACITY 10

Array::Array(){
    this->length = 0;
    this->capacity = START_CAPACITY;
    this->array_of_figures = new Figure*[START_CAPACITY];
}

void Array::grow(){
    Figure** new_array = new Figure*[this->capacity * 2];
    for (size_t i = 0; i < this->length; i++) {
        new_array[i] = this->array_of_figures[i];
    }

    delete[] this->array_of_figures;
    this->array_of_figures = new_array;
    this->capacity *= 2;
}

Array::Array(const std::initializer_list<Figure*>& lst){
    this->capacity = START_CAPACITY;
    this->array_of_figures = new Figure*[this->capacity > lst.size() ? this->capacity : lst.size()];
    this->length = lst.size();
    size_t i = 0;

    for (auto fig: lst){
        this->array_of_figures[i] = fig;
        i++;
    }
}

Array::Array(const Array& other){
    this->capacity = other.capacity;
    this->array_of_figures = new Figure*[this->capacity > other.length ? this->capacity : other.length];
    this->length = other.length;
    for (size_t i=0; i != other.length; i++){
        this->array_of_figures[i] = other.array_of_figures[i];
    }
}

Array::Array(Array&& other) noexcept{
    this->capacity = other.capacity;
    this->length = other.length;
    this->array_of_figures = other.array_of_figures;
    other.array_of_figures = nullptr;
}

Array& Array::operator=(const Array& other){
    if (this != &other){
        delete[] this->array_of_figures;
        this->capacity = other.capacity;
        this->length = other.length;
        this->array_of_figures = new Figure*[this->capacity];
        for (size_t i=0; i != other.length; i++){
            this->array_of_figures[i] = other.array_of_figures[i];
        }
    }
    return *this;
}

Array& Array::operator=(Array&& other) noexcept{
    if (this != &other){
        delete[] this->array_of_figures;
        this->capacity = other.capacity;
        this->length = other.length;
        this->array_of_figures = other.array_of_figures;
        other.array_of_figures = nullptr;
    }
    return *this;
}

void Array::remove_figure(size_t i){
    if (i >= this->length){
        throw std::out_of_range("Индекс вне диапазона");
    }

    for (size_t j = i; j < this->length - 1; j++){
        this->array_of_figures[j] = this->array_of_figures[j + 1];
    }
    this->length--;
}

void Array::add_figure(Figure* fig){
    if (this->length >= this->capacity){
        this->grow();
    }
    this->array_of_figures[this->length] = fig;
    this->length++;
}

void Array::print_info() const{
    for (size_t i=0; i != this->length; i++){
        std::cout << "Figure " << i + 1 << ":" << std::endl;
        std::cout << this->array_of_figures[i]->who_am_i() << std::endl;
        std::pair<double, double> centre = this->array_of_figures[i]->geom_centre();
        std::cout << "Geom centre: (" << centre.first << ", " << centre.second << ")" << std::endl;
        std::cout << "Square: " << double(*(this->array_of_figures[i])) << std::endl;
        std::cout << std::endl;
    }
}

double Array::total_area() const{
    double total = 0;
    for (size_t i=0; i != this->length; i++){
        total += double(*(this->array_of_figures[i]));
    }
    return total;
}

Array::~Array() noexcept{
    delete[] this->array_of_figures;
}