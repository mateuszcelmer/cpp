cmake_minimum_required ( VERSION 3.0 )

set(This game)
set(ThisLib libgame)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -fsanitize=address -g" )
#set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Werror -O3 -g" )

enable_testing()

add_subdirectory(tests/googletest)
add_subdirectory(tests)

include_directories( ./include ./src ./src/objects)

# add source cpp files
FILE(GLOB_RECURSE Sources  ./src/*.cpp)
FILE(GLOB_RECURSE Headers  ./src/*.h)

# target
add_executable(${This} ${Sources})
add_library(${ThisLib} STATIC ${Headers} ${Sources})

# set properties
set_target_properties(${This} PROPERTIES COMPILE_FLAGS ${CMAKE_CXX_FLAGS})
set_target_properties(${ThisLib} PROPERTIES COMPILE_FLAGS ${CMAKE_CXX_FLAGS})

target_link_libraries(${This} -lsfml-graphics -lsfml-window -lsfml-system -lpthread )
target_link_libraries(${ThisLib} -lsfml-graphics -lsfml-window -lsfml-system -lpthread )