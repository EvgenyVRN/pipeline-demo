#ifndef MinusSolver_h
#define MinusSolver_h

#include "ISolver.h"

class MinusSolver : public ISolver
{
public:
    ~MinusSolver() override = default;
    std::vector<double> Solve(const std::vector<double>& data) const override;
};

#endif
