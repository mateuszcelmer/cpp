cmake_minimum_required(VERSION 3.8)

set(This tests)

set(Sources
  tests.cpp
)

include_directories( ../src/ ../src/objects)

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
  gtest_main
  libgame
)

add_test(
  NAME ${This}
  COMMAND ${This}
)
