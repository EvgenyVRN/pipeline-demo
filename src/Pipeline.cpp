#include "Pipeline.h"

#include <glog/logging.h>

Pipeline::Pipeline()
{

}

Pipeline::~Pipeline()
{
    DLOG(INFO) << "~Pipeline";
}

std::vector<double> Pipeline::Solve(const std::vector<double> &data) const
{
    if(m_solvrs.empty())
    {
        LOG(WARNING) << "Pipeline hasn't solvers";
        return data;
    }

    std::vector<double> result(data);
    for(auto it = m_solvrs.begin(); it != m_solvrs.end(); ++it)
        result = (*it)->Solve(result);

    return result;
}

void Pipeline::AddSolver(std::unique_ptr<ISolver> solver)
{
    m_solvrs.push_back(std::move(solver));
}

void Pipeline::SetInput(const std::vector<double> &data)
{
    m_input = data;
}

const std::vector<double> &Pipeline::GetOutput() const
{
    return m_output;
}
