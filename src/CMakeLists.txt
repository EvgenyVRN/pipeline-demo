set(SRC
      MinusSolver.cpp
      Pipeline.cpp
      PlusSolver.cpp
  )

add_library(pipeline-lib STATIC ${SRC})
target_link_libraries(pipeline-lib PRIVATE glog::glog)
