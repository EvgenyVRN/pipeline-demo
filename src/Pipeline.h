#ifndef pipeline_h
#define pipeline_h

#include <memory>
#include <vector>

#include "ISolver.h"

class Pipeline : public ISolver
{
public:
    Pipeline();
    ~Pipeline() override;
    std::vector<double> Solve(const std::vector<double>& data) const override;

    void AddSolver(std::unique_ptr<ISolver> solver);
    void SetInput(const std::vector<double>& data);
    const std::vector<double>& GetOutput() const;

private:
    std::vector<std::unique_ptr<ISolver>> m_solvrs;
    std::vector<double> m_input;
    std::vector<double> m_output;
};

#endif
