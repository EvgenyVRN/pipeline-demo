#pragma once

#include <map>

#include "core/INodeFactory.h"

namespace maverick {
namespace logic {

class NodeFactory : public maverick::core::INodeFactory
{
public:
    ~NodeFactory() override = default;
    bool Register(const std::string& name, TCreateMethod funcCreate) override;
    std::unique_ptr<maverick::core::INode> Create(const std::string& name) const override;
    std::vector<std::string> GetAllNodeNames() const override;
private:
    std::map<std::string, TCreateMethod> m_methods;
};
}
}
