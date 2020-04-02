#include "core/NodeImpl.h"

using namespace maverick::core;

NodeImpl::NodeImpl()
  : m_modified(false)
{
}

bool NodeImpl::IsModified() const
{
  return m_modified;
}

void NodeImpl::Modified(bool modified)
{
  m_modified = modified;
  if (m_modified)
    emit Modified();
}
