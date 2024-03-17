# set(OpenCV_DIR "/home/lyxichigoichie/3rdparty/opencv3/build")  #directory of OpenCVConfig.cmake
# find_package(OpenCV REQUIRED QUIET)
# message(${OpenCV_LIBS})

# include directories
include_directories(
	include
    ${OpenCV_INCLUDE_DIRS}
)

# link directories
link_directories(
	include
    ${OpenCV_LIBRARY_DIRS}
)

file(GLOB_RECURSE sourcelist src/*.cpp)
# message(${sourcelist})

add_library(wechat_qrcode SHARED ${sourcelist})
target_link_libraries(wechat_qrcode ${OpenCV_LIBS})