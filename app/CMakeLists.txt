#main
add_executable(pipeline main.cpp)
target_link_libraries(pipeline PRIVATE pipeline-logic)
target_link_libraries(pipeline PRIVATE pipeline-core)
target_link_libraries(pipeline PRIVATE ${Boost_LIBRARIES}) # Boost::filesystem
target_link_libraries(pipeline PRIVATE glog::glog)
target_link_libraries(pipeline PRIVATE Qt5::Core Qt5::Widgets)
