cmake_minimum_required(VERSION 3.0.0)
project(wechat_qrcode VERSION 0.1.0 LANGUAGES C CXX)

# set(OpenCV_DIR "/home/lyxichigoichie/3rdparty/opencv3/build")  #directory of OpenCVConfig.cmake
find_package(OpenCV REQUIRED QUIET)
# message(${OpenCV_LIBS})

add_subdirectory(wechat_qrcode)

# include directories
include_directories(
	include
	wechat_qrcode/include
)

# message(${sourcelist})
add_definitions(-DROOT_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}/\")
add_executable(main main.cpp)
target_link_libraries(main ${OpenCV_LIBS} wechat_qrcode)

add_definitions(-DROOT_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}/\")
add_executable(video_detect video_detect.cpp)
target_link_libraries(video_detect ${OpenCV_LIBS} wechat_qrcode)