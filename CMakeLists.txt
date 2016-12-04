cmake_minimum_required(VERSION 2.8.4)
project(findkey)

set(CMAKE_C_FLAGS "-Wall")

set(CURSES_NEED_NCURSES TRUE)
find_package(Curses)

include_directories(${CURSES_INCLUDE_DIRS})

set(SNAKE_SOURCE_PATH ${PROJECT_SOURCE_DIR}/src)
file(GLOB_RECURSE SNAKE_SOURCE_FILES ${SNAKE_SOURCE_PATH}/*.c)
add_executable(findkey ${SNAKE_SOURCE_FILES})
target_link_libraries(msnake ${CURSES_LIBRARIES})

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    target_link_libraries(findkey rt)
endif()

install(TARGETS findkey DESTINATION /usr/local/bin)
