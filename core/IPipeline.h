#pragma once

#include <memory>

#include "core/NodeInfo.h"

namespace maverick {
namespace core {

class IPipeline
{
public:
    virtual ~IPipeline() = default;

    virtual void AddNode(std::unique_ptr<INode> node) = 0;
    virtual bool AddConnection(NodeInfo from, NodeInfo to) = 0;
};
}
}
