include_directories(${CMAKE_SOURCE_DIR}/lib)
link_directories(${CMAKE_SOURCE_DIR}/lib)
add_executable(main main.cpp)

target_link_libraries(main PRIVATE ${OpenCV_LIBS})