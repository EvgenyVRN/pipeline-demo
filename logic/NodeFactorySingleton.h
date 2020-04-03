#pragma once

#include "core/INodeFactory.h"

namespace maverick
{
namespace logic
{

class NodeFactorySingleton
{
public:
  static maverick::core::INodeFactory& Instance();

  NodeFactorySingleton(NodeFactorySingleton const&) = delete;
  NodeFactorySingleton(NodeFactorySingleton&&) = delete;
  NodeFactorySingleton& operator=(NodeFactorySingleton const&) = delete;
  NodeFactorySingleton& operator=(NodeFactorySingleton&&) = delete;

protected:
  NodeFactorySingleton() = default;
  ~NodeFactorySingleton() = default;
};
}
}
