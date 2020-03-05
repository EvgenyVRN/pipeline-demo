#ifndef pipeline_h
#define pipeline_h

#include <memory>
#include <vector>

#include "ISolver.h"

class Pipeline
{
public:
    Pipeline();

private:
    std::vector<std::unique_ptr<ISolver>> m_solvrs;
};

#endif
