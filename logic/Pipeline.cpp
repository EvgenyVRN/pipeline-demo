#include "Pipeline.h"

#include <glog/logging.h>

// using namespace maverick::core;
using namespace maverick::logic;

Pipeline::Pipeline() {}

void Pipeline::AddNode(std::unique_ptr<INode> node)
{
  m_nodes.push_back(std::move(node));
}

bool Pipeline::AddConnection(NodeInfo from, NodeInfo to)
{
  // TODO: check that pointers to INode are correct
  auto it = m_adjList.find(from);
  if (it == m_adjList.end())
  {
    LOG(ERROR) << "Can't add connection";
    return false;
  }
  it->second.push_back(to);
  return true;
}

void Pipeline::Apply()
{
  for (const auto& node : m_nodes)
  {
    node->IsModified();
  }
}
