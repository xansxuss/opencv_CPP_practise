PROJECT (cv_test)
if (CMAKE_BULID_TYPE STREQUAL Debug)
    MESSAGE(status "$CMAKE_BULID_TYPE)")
    ADD_DEFINITIONS(-DDEBUG)
ENDIF()
find_package(OpenCV REQUIRED)
include_directories(${opencv_INCLUDE_DIRS})
# add_subdirectory(lib)
add_subdirectory(src)