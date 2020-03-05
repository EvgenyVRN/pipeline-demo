#include "PlusSolver.h"

#include <algorithm>

std::vector<double> PlusSolver::Solve(const std::vector<double> &data) const
{
    std::vector<double> result(data);
    const double add_val = 1.0;
    std::for_each(result.begin(), result.end(), [add_val](double& val) { val += add_val; } );
    return result;
}
