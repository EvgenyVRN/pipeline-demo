#ifndef PlusSolver_h
#define PlusSolver_h

#include "ISolver.h"

class PlusSolver : public ISolver
{
public:
    ~PlusSolver() override = default;
    std::vector<double> Solve(const std::vector<double>& data) const override;
};


#endif
