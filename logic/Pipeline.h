#pragma once

#include <memory>
#include <unordered_map>
#include <vector>

#include "core/INode.h"
#include "core/NodeImpl.h"
#include "core/NodeInfo.h"

namespace maverick
{
namespace logic
{

using namespace maverick::core;

class Pipeline
{
public:
  Pipeline();
  ~Pipeline() = default;
  void AddNode(std::unique_ptr<INode> node);
  bool AddConnection(NodeInfo from, NodeInfo to);
  void Apply();

private:
  std::vector<std::unique_ptr<INode> > m_nodes;
  std::unordered_map<NodeInfo, std::vector<NodeInfo> > m_adjList;
};
}
}
