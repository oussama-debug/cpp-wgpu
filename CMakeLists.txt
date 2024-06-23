cmake_minimum_required(VERSION 3.0...3.25)
project(
    myengine # name of the project, which will also be the name of the visual studio solution if you use it
    VERSION 0.0.1 # any version number
    LANGUAGES CXX C # programming languages used by the project
)

add_executable(myengine main.cpp)

set_target_properties(myengine PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
    COMPILE_WARNING_AS_ERROR ON
)

if (MSVC)
    target_compile_options(myengine PRIVATE /W4)
else()
    target_compile_options(myengine PRIVATE -Wall -Wextra -pedantic)
endif()

if (XCODE)
    set_target_properties(myengine PROPERTIES
        XCODE_GENERATE_SCHEME ON
        XCODE_SCHEME_ENABLE_GPU_FRAME_CAPTURE_MODE "Metal"
    )
endif()

add_subdirectory(webgpu)

target_link_libraries(myengine PRIVATE webgpu)
target_copy_webgpu_binaries(myengine)