#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "figure.h"
#include <vector>

class Rhombus : public Figure {
public:
    Rhombus() : Figure(4) {} 
    Rhombus(std::vector<std::pair<double, double>>& coords); 

    const std::string who_am_i() const override;
    bool is_valid() const override; 
    ~Rhombus() override = default;
};


#endif