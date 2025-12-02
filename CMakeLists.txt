cmake_minimum_required(VERSION 3.10)
project(greetapp VERSION 0.1 LANGUAGES C)

include(GNUInstallDirs)

option(USE_BUNDLED_GREETLIB "Use bundled greetlib instead of system" ON)

if(USE_BUNDLED_GREETLIB)
    message(STATUS "Using bundled greetlib")
    add_subdirectory(external/greetlib)
else()
    message(STATUS "Using system greetlib")
    find_library(GREET_LIBRARY greet REQUIRED)
    find_path(GREET_INCLUDE_DIR greetlib.h REQUIRED)
    add_library(greet SHARED IMPORTED)
    set_target_properties(greet PROPERTIES
        IMPORTED_LOCATION ${GREET_LIBRARY}
        INTERFACE_INCLUDE_DIRECTORIES ${GREET_INCLUDE_DIR}
    )
endif()

add_executable(greetapp src/main.c)
target_link_libraries(greetapp greet)

install(TARGETS greetapp RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

