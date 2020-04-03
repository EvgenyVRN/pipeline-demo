#include "NodeFactory.h"

#include "core/INode.h"
#include "core/NodeImpl.h"

using namespace std;
using namespace maverick::core;
using namespace maverick::logic;

bool NodeFactory::Register(const string& name, INodeFactory::TCreateMethod funcCreate)
{
  if (auto it = m_methods.find(name); it == m_methods.end())
  {
    m_methods[name] = funcCreate;
    return true;
  }
  return false;
}

unique_ptr<INode> NodeFactory::Create(const string& name) const
{
  if (auto it = m_methods.find(name); it != m_methods.end())
    return it->second(); // call the createFunc

  return nullptr;
}

vector<string> NodeFactory::GetAllNodeNames() const
{
  vector<string> result;
  transform(m_methods.begin(), m_methods.end(), back_inserter(result),
    [](auto pair) { return pair.first; });

  return result;
}
