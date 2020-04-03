#include "NodeFactorySingleton.h"

#include "logic/NodeFactory.h"

using namespace maverick::core;
using namespace maverick::logic;

INodeFactory& NodeFactorySingleton::Instance()
{
  // Since it's a static variable, if the class has already been created,
  // it won't be created again.
  // And it **is** thread-safe in C++11.
  static NodeFactory instance;
  // Return a reference to our instance.
  return instance;
}
