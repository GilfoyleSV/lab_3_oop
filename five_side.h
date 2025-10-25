#include "figure.h"

class Five_Side : public Figure {
    public:
    Five_Side() : Figure(5) {} 
    Five_Side(std::vector<std::pair<double, double>>& coords); 

    const std::string who_am_i() const override;
    bool is_valid() const override; 
    ~Five_Side() override = default;
};