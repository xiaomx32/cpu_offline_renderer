file(GLOB_RECURSE srcs CONFIGURE_DEPENDS ./*.h ./*.cpp)
add_library(raytracing STATIC ${srcs})
target_link_libraries(raytracing PUBLIC basic)
target_include_directories(raytracing PUBLIC ${CMAKE_SOURCE_DIR}/src)
