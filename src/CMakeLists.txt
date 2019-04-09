add_executable(cu-smallpt
    ${CMAKE_CURRENT_SOURCE_DIR}/kernel.cu)

target_include_directories(cu-smallpt PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(cu-smallpt PUBLIC cxx_std_14)