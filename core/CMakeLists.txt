set(SRC
      INode.cpp
      NodeImpl.cpp
    )

add_library(pipeline-core STATIC ${SRC})
target_link_libraries(pipeline-core PRIVATE Qt5::Core)
