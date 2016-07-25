cmake_minimum_required(VERSION 2.8)
project( DisplayImage )
find_package( OpenCV REQUIRED )
 set(SOURCES    Circles.cpp Image.h Image.cpp Density.h Density.cpp)

add_executable( DisplayImage ${SOURCES} )
target_link_libraries( DisplayImage ${OpenCV_LIBS} )


