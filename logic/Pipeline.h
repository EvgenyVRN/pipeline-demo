#pragma once

#include <memory>
#include <vector>

#include "core/INode.h"
#include "core/NodeImpl.h"

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
  void Apply();

private:
  std::vector<std::unique_ptr<INode> > m_nodes;
};
}
}
