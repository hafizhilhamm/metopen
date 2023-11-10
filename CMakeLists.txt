cmake_minimum_required(VERSION 2.8)
project( metopen )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( metopen main.cpp )
target_link_libraries( metopen ${OpenCV_LIBS} )

