#include "SimpleDataGenerator.h"

#include "logic/NodeFactorySingleton.h"

#include <glog/logging.h>

using namespace maverick::logic;
using namespace maverick::core;

bool SimpleDataGenerator::m_registered = NodeFactorySingleton::Instance().Register(
  SimpleDataGenerator::GetFactoryName(), SimpleDataGenerator::CreateMethod);

maverick::logic::SimpleDataGenerator::SimpleDataGenerator()
  : INode()
{
  m_inCount = 0;
}

void SimpleDataGenerator::SetInput([[maybe_unused]] MaverickData data, [[maybe_unused]] uint port)
{
  // TODO: add to INode::SetInput
  // and call INode::SetInput(data, port)
  //  if (port > m_inCount)
  //    LOG(ERROR) << "Incorrect port = " << port;
}

MaverickData SimpleDataGenerator::GetOutput(uint port)
{
  // TODO: add the same check as input port check
  if (port == 0)
    return { 1, 2, 3, 4, 5 };
  else
    return MaverickData();
}

std::unique_ptr<INode> SimpleDataGenerator::CreateMethod()
{
  return std::make_unique<SimpleDataGenerator>();
}

std::string SimpleDataGenerator::GetFactoryName()
{
  return "SimpleDataGenerator";
}
