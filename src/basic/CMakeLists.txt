file(GLOB_RECURSE basic_srcs CONFIGURE_DEPENDS ./*.h ./*.cpp)
add_library(basic STATIC ${basic_srcs})
target_include_directories(basic PUBLIC ${CMAKE_SOURCE_DIR}/src)