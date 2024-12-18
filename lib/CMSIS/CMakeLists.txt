# lib/mavlink/CMakeLists.txt
add_library(CMSIS INTERFACE)

target_include_directories(CMSIS INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/Include
)
