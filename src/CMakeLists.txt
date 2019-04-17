add_subdirectory(cuda)
add_subdirectory(cpp/seq)

target_include_directories(cu-smallpt PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(seq-smallpt PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})