cmake_minimum_required(VERSION 3.22)

project(ArenaSurvival LANGUAGES C CXX)

set(BUILD_EXAMPLES OFF CACHE BOOL "Build raylib examples" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build shared libraries" FORCE)
add_subdirectory(libs/raylib)

add_subdirectory(libs/entt)

file(GLOB_RECURSE GAME_SOURCES CONFIGURE_DEPENDS
	"${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
	"${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp"
)

add_executable(ArenaSurvival ${GAME_SOURCES})

target_link_libraries(ArenaSurvival PRIVATE raylib EnTT::EnTT)

set_target_properties(ArenaSurvival PROPERTIES
	CXX_STANDARD 20
	CXX_STANDARD_REQUIRED ON
	CXX_EXTENSIONS OFF
)

include(CTest)
if(BUILD_TESTING)
	add_subdirectory(tests)
endif()
