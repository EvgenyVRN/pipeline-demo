#pragma once

#include <functional>
#include <memory>
#include <string>
#include <vector>

namespace maverick
{
namespace core
{

class INode;

// TODO: maybe should split into INodeFactoryRegistrator and INodeFactoryCreator
class INodeFactory
{
public:
    // using TCreateMethod = std::unique_ptr<INode>(*)();
    using TCreateMethod = std::function<std::unique_ptr<INode>()>;
public:
  virtual ~INodeFactory() = default;
  virtual bool Register(const std::string& name, TCreateMethod funcCreate) = 0;
  virtual std::unique_ptr<INode> Create(const std::string& name) const = 0;
  virtual std::vector<std::string> GetAllNodeNames() const = 0;

};
}
}
