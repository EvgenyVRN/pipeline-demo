#include "core/INode.h"

#include "core/NodeImpl.h"

using namespace maverick::core;

INode::INode()
  : m_inCount(1)
  , m_outCount(1)
  , m_impl(std::make_unique<NodeImpl>())
{
}

uint INode::GetInputPortsCount() const
{
  return m_inCount;
}

uint INode::GetOutputPortsCount() const
{
  return m_outCount;
}

bool INode::IsModified() const
{
  return m_impl->IsModified();
}

void INode::Modified(bool modified)
{
  m_impl->Modified(modified);
}
