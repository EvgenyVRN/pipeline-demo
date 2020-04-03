set(SRC
      NodeFactory.cpp
      NodeFactorySingleton.cpp
      Pipeline.cpp
    )

add_library(pipeline-logic STATIC ${SRC})
target_link_libraries(pipeline-logic PRIVATE pipeline-core)
target_link_libraries(pipeline-logic PRIVATE Qt5::Core)

