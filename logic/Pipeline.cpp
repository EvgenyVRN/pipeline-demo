#include "Pipeline.h"

// using namespace maverick::core;
using namespace maverick::logic;

Pipeline::Pipeline() {}

void Pipeline::AddNode(std::unique_ptr<INode> node)
{
  m_nodes.push_back(std::move(node));
}

void Pipeline::Apply()
{
  for (const auto& node : m_nodes)
  {
    node->IsModified();
  }
}
