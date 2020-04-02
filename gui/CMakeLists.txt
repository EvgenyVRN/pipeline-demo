set(SRC
      PipelineScene.cpp
    )

add_library(pipeline-gui STATIC ${SRC})
target_link_libraries(pipeline-gui PRIVATE pipeline-core)
target_link_libraries(pipeline-gui PRIVATE Qt5::Widgets Qt5::Core)

