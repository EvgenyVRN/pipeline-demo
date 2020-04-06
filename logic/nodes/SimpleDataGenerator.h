#pragma once

#include <memory>

#include "core/INode.h"
#include "core/NodeImpl.h"

namespace maverick {
namespace logic {

class SimpleDataGenerator : public core::INode
{
public:
    SimpleDataGenerator();
    ~SimpleDataGenerator() override = default;
    void SetInput(core::MaverickData data, uint port = 0) override;
    core::MaverickData GetOutput(uint port = 0) override;

    static std::unique_ptr<INode> CreateMethod();
    static std::string GetFactoryName();
private:
    static bool m_registered;
};
}

}
