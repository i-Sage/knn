set(SOURCES src/format.cc src/os.cc src/format.cc)

add_library(fmt STATIC ${SOURCES})
target_include_directories(fmt PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include/)