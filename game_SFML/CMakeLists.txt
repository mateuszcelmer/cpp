cmake_minimum_required ( VERSION 3.0 )

project( the_game )
SET(THE_TARGET  "game" )

#flags
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -O3 " )

#files

#include
include_directories( ./include ./src)

# target
set_target_properties(${THE_TARGET} PROPERTIES COMPILE_FLAGS ${CMAKE_CXX_FLAGS})
add_executable(${THE_TARGET} ./src/game.cpp ./src/actors/ball.cpp ./src/actors/obstacles.cpp ./src/actors/player.cpp)

# external libs - shared
# add_subdirectory( ./libs/Logger )
# target_link_libraries(${THE_TARGET} logger )

# external libs - static
# add_library(randomize STATIC IMPORTED)
# set_property(TARGET randomize PROPERTY IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/lib/Randomize/librandomize.a)
# target_link_libraries(${THE_TARGET} randomize )

#end of the CMakeLists.txt