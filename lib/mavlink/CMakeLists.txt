# lib/mavlink/CMakeLists.txt
add_library(MAVLink INTERFACE)

target_include_directories(MAVLink INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
