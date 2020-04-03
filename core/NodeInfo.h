#pragma once

#include <functional>

namespace maverick
{
namespace core
{

class INode;

struct NodeInfo
{
  NodeInfo(INode* node, int port = 0)
    : m_node(node)
    , m_port(port)
  {
  }
  INode* m_node = nullptr;
  int m_port = 0;

  constexpr bool operator==(const maverick::core::NodeInfo& info) const
  {
      return m_node == info.m_node && m_port == info.m_port;
  }
};
}
}


namespace std
{
template<>
class hash<maverick::core::NodeInfo>
{
public:
  size_t operator()(const maverick::core::NodeInfo& nodeInfo) const
  {
    size_t h1 = std::hash<maverick::core::INode*>()(nodeInfo.m_node);
    size_t h2 = std::hash<int>()(nodeInfo.m_port);
    return h1 ^ (h2 << 1);
  }
};
}
