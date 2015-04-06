cmake_minimum_required(VERSION 2.8)

project(yobatronika)

if( CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR )
    message( FATAL_ERROR "Please select another Build Directory!" )
endif()

find_package(PkgConfig REQUIRED)
if(NOT PKGCONFIG_FOUND)
    message(SEND_ERROR "Failed to find PkgConfig")
    return()
else()
    pkg_check_modules (SDL2 REQUIRED sdl2)
    include_directories(${SDL2_INCLUDE_DIRS})
    message(STATUS "include: ${SDL2_INCLUDE_DIRS}")
    link_directories( ${SDL2_LIBRARY_DIRS} )
endif()

set(ALL_LIBS ${SDL2_LIBRARIES})

set(SOURCES "src/main.cpp" )

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)

target_link_libraries(${PROJECT_NAME} ${ALL_LIBS})

# Xcode 
set_target_properties(${PROJECT_NAME} PROPERTIES 
                      XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/")

