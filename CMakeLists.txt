cmake_minimum_required(VERSION 3.5)
project(new_ppt)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Model.cpp Model.h Solver.cpp Solver.h Configuration.cpp Configuration.h Driver.cpp Driver.h Line.cpp Line.h Task.cpp Task.h)
add_executable(new_ppt ${SOURCE_FILES})

include_directories(/usr/local/include)

link_directories(/usr/local/lib)

target_link_libraries(new_ppt -lgecodeint -lgecodekernel -lgecodesupport -lgecodesearch -lgecodegist -lgecodeminimodel -lgecodeset pthread)