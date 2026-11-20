include(FetchContent)
FetchContent_Declare(doctest
	GIT_REPOSITORY https://github.com/doctest/doctest.git
	GIT_TAG v2.4.11
	GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(doctest)

add_executable(ArenaSurvivalTests main.cpp)
target_link_libraries(ArenaSurvivalTests PRIVATE doctest::doctest EnTT::EnTT)
target_include_directories(ArenaSurvivalTests PRIVATE "${PROJECT_SOURCE_DIR}/src")
set_target_properties(ArenaSurvivalTests PROPERTIES
	CXX_STANDARD 20
	CXX_STANDARD_REQUIRED ON
	CXX_EXTENSIONS OFF
)

include("${doctest_SOURCE_DIR}/scripts/cmake/doctest.cmake")
doctest_discover_tests(ArenaSurvivalTests)
