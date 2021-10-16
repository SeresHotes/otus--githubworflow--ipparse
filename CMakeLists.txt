cmake_minimum_required(VERSION 3.20)

if(NOT DEFINED PATCH_VERSION)
    set(PATCH_VERSION "1" )
endif()

set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(helloworld VERSION ${PROJECT_VESRION})

add_executable(ip_filter main.cpp)

set_target_properties(ip_filter PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
) 

if (MSVC)
    target_compile_options(ip_filter PRIVATE
        /W4 
    )
else ()
    target_compile_options(ip_filter PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

find_program (BASH_PROGRAM bash)
list(APPEND CMAKE_CTEST_ARGUMENTS "--output-on-failure")
include(CTest)
enable_testing()
add_test(IntegratedTest ${BASH_PROGRAM} ${CMAKE_SOURCE_DIR}/test.sh 
    ${CMAKE_CURRENT_BINARY_DIR}/ip_filter.exe ${CMAKE_SOURCE_DIR}/ip_filter.tsv)

install(TARGETS ip_filter RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)
