# cmake版本最低要求
cmake_minimum_required(VERSION 3.8)
# 工程名，会产生"${PROJECT_NAME}"变量，需要与项目文件夹名相同
project(OPENCV_MSYS2)
# set用来定义变量，变量使用时用"${变量名}"的形式
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_COMPILER "g++.exe")
# 用find_package寻找OpenCV，找到后会有"${OpenCV_INCLUDE_DIRS}"，"${OpenCV_LIBRARIES}"两个变量可供使用，第一个是头文件位置，第二个是库文件
find_package(OpenCV REQUIRED)
# message用来打印信息，这里打印下找到的OpenCV的头文件和库文件的信息，可以不做
message(STATUS "OpenCV Include: ${OpenCV_INCLUDE_DIRS}")
message(STATUS "OpenCV Libs: ${OpenCV_LIBRARIES}")
# 找到在当前目录下的所有代码文件，存储到"SOURCE_FILES"变量中
aux_source_directory(. SOURCE_FILES)
# 打印下刚才的"SOURCE_FILES"，同样可不做
message(STATUS "src: ${SOURCE_FILES}")

# 定义需要include的头文件的位置
include_directories(${OpenCV_INCLUDE_DIRS})

# 添加个可执行的输出，第一个参数是输出名，必须唯一，第二个源文件
add_executable(signal 1.cpp)
# 用来链接库，注意这个函数要在"add_executable"之后使用
target_link_libraries(signal  ${OpenCV_LIBRARIES})
add_executable(continuous Inout.cpp)
target_link_libraries(continuous  ${OpenCV_LIBRARIES})