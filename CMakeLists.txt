cmake_minimum_required(VERSION 3.22)

project(ArenaSurvival LANGUAGES C CXX)

set(BUILD_EXAMPLES OFF CACHE BOOL "Build raylib examples" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build shared libraries" FORCE)
add_subdirectory(libs/raylib)

add_executable(ArenaSurvival src/main.cpp)

target_link_libraries(ArenaSurvival PRIVATE raylib)

set_target_properties(ArenaSurvival PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
	CXX_EXTENSIONS OFF
)
