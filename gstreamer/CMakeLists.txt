cmake_minimum_required(VERSION 3.10)
project(display_gstreamer)

# 尋找 OpenCV
find_package(OpenCV REQUIRED)

# 設定可執行檔名稱
add_executable(display_gstreamer main.cpp VideoPlayer.cpp)

# 連結 OpenCV
target_link_libraries(display_gstreamer ${OpenCV_LIBS})

# 開啟 GStreamer 支援
target_compile_definitions(display_gstreamer PRIVATE WITH_GSTREAMER)