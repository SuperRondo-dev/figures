cmake_minimum_required(VERSION 3.14)

project(figures LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED On)
set(CMAKE_CXX_EXTENSIONS Off)

set(GLFW_DIR ${CMAKE_CURRENT_LIST_DIR}/glfw)
list(APPEND CMAKE_PREFIX_PATH ${GLFW_DIR})
find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

file(GLOB LIB_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp")
add_library(figures STATIC ${LIB_FILES})
target_include_directories(figures PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
    ${CMAKE_CURRENT_LIST_DIR}/include/figures
    ${CMAKE_CURRENT_LIST_DIR}/include/screens
    ${OPENGL_INCLUDE_DIR}
    ${GLFW_DIR}/include
)
target_link_directories(figures PUBLIC ${GLFW_DIR}/lib)
target_link_libraries(figures PUBLIC ${OPENGL_LIBRARIES} glfw3)

add_executable(main main.cpp)
target_link_libraries(main PUBLIC figures)