#main
add_executable(pipeline main.cpp)
target_link_libraries(pipeline PRIVATE pipeline-gui
                                        pipeline-logic
                                        pipeline-core
                                        ${Boost_LIBRARIES} # Boost::filesystem
                                        glog::glog
                                        Qt5::Core Qt5::Widgets Qt5::OpenGL)
