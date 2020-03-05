#ifndef solver_h
#define solver_h

#include <vector>

class ISolver
{
public:
    virtual ~ISolver() = 0;
    virtual std::vector<double> Solve(const std::vector<double>& data) const = 0;
};

#endif
