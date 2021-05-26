cmake_minimum_required(VERSION 3.17)
project(search_engine)

set(CMAKE_CXX_STANDARD 14)

add_executable(search_engine
        main.cpp
        avl.cpp
        avl.h
        utils.cpp
        utils.h
        DocumentProcessor.cpp
        DocumentProcessor.h
        fort.hpp
        HashTable.cpp
        HashTable.h
        )


# Disable building tests and examples in libfort project
set(FORT_ENABLE_TESTING OFF CACHE INTERNAL "")

add_subdirectory(third_party/libfort)
target_link_libraries(search_engine fort_dev)

