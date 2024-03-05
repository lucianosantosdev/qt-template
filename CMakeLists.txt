cmake_minimum_required(VERSION 3.16)

project(qtTemplate VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(ROOT_PROJECT_DIR ${CMAKE_SOURCE_DIR} CACHE INTERNAL "Root project directory")

add_subdirectory(app)
add_subdirectory(tests)
