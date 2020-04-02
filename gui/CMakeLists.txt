set(SRC
      ConnectionItem.cpp
      NodeItem.cpp
      PipelineScene.cpp
      PipelineWidget.cpp
    )

add_library(pipeline-gui STATIC ${SRC})
target_link_libraries(pipeline-gui PRIVATE pipeline-core)
target_link_libraries(pipeline-gui PRIVATE Qt5::Widgets Qt5::Core Qt5::OpenGL)

