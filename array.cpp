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
        Figure new_fig = *other.array_of_figures[i];
        this->array_of_figures[i] = &new_fig;
    }
}

Array::Array(Array&& other) noexcept{
    this->capacity = other.capacity;
    this->array_of_figures = new Figure*[this->capacity];
    this->length = other.length;
    for (size_t i=0; i != other.length; i++){
        this->array_of_figures[i] = other.array_of_figures[i];
    }

    other.length = 0;
    other.array_of_figures = nullptr;

}

Array::~Array() noexcept{
    for (size_t i = 0; i < this->length; i++){
        delete this->array_of_figures[i];
    }
    delete[] this->array_of_figures;
}