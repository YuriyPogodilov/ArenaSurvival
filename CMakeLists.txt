cmake_minimum_required(VERSION 3.16)

project(ArenaSurvival LANGUAGES CXX)

add_library(raylib STATIC IMPORTED GLOBAL)
set_target_properties(raylib PROPERTIES 
	IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/libs/raylib-6.2/lib/raylib.lib
)
set_property(TARGET raylib APPEND PROPERTY INTERFACE_LINK_LIBRARIES winmm)

add_executable(ArenaSurvival src/main.cpp)

target_include_directories(ArenaSurvival PRIVATE 
	${CMAKE_CURRENT_SOURCE_DIR}/libs/raylib-6.2/include
)

target_link_libraries(ArenaSurvival PRIVATE raylib)

set_target_properties(ArenaSurvival PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
	CXX_EXTENSIONS OFF
)
