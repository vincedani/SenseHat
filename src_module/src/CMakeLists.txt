
project(src CXX)

add_library(src_binding STATIC
    src_js_binding.cpp
)
target_include_directories(src_binding PRIVATE ${JERRY_INCLUDE_DIR})
target_link_libraries(src_binding PUBLIC stdc++)
