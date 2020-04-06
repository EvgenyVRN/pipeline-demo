set(SRC
      NodeFactory.cpp
      NodeFactorySingleton.cpp
      Pipeline.cpp
      nodes/SimpleDataGenerator.cpp
    )

add_library(pipeline-logic SHARED ${SRC})
#target_link_libraries(pipeline-logic PRIVATE pipeline-core)
target_link_libraries(pipeline-logic PRIVATE Qt5::Core)

