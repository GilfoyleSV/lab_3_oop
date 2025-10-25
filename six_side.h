#include "figure.h"

class Six_Side : public Figure {
    public:
    Six_Side() : Figure(6) {} 
    Six_Side(std::vector<std::pair<double, double>>& coords); 

    const std::string who_am_i() const override;
    bool is_valid() const override; 
    ~Six_Side() override = default;
};