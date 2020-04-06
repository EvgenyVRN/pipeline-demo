#pragma once

#include <memory>
#include <vector>

namespace maverick
{
namespace core
{

using MaverickData = std::vector<double>; // TODO: implement MaverickData abstractions

class NodeImpl;

class INode
{
public:
  INode();
  virtual ~INode() = default;
  virtual void SetInput(MaverickData data, uint port = 0) = 0;
  virtual MaverickData GetOutput(uint port = 0) = 0;

  uint GetInputPortsCount() const;
  uint GetOutputPortsCount() const;

  bool IsModified() const;
  void Modified(bool modified);

protected:
  uint m_inCount;
  uint m_outCount;

private:
  std::unique_ptr<NodeImpl> m_impl;
};
}
}
