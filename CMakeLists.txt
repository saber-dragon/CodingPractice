cmake_minimum_required(VERSION 3.0)

project(leetcode)

set(CMAKE_CXX_STANDARD 11)
enable_testing()
# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
                 ${CMAKE_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()

include_directories("${PROJECT_SOURCE_DIR}/utils")
# add executables
set(FOLDER_NAME "divide_and_conquer")
file(GLOB HEADERs "${FOLDER_NAME}/*.h" "${FOLDER_NAME}/*.hpp")
file(GLOB SRCs "${FOLDER_NAME}/*.cc" "${FOLDER_NAME}/*.cpp")
foreach(SRC ${SRCs})
    get_filename_component(SRC_FILENAME_WE ${SRC} NAME_WE)
    set(BIN_NAME "${PROJECT_NAME}_${FOLDER_NAME}_${SRC_FILENAME_WE}")
    message(STATUS "Compiling for ${BIN_NAME} ...")
    add_executable(${BIN_NAME} ${HEADERs} ${SRC})
    target_link_libraries(${BIN_NAME} gtest_main)
    if (SRC_FILENAME_WE MATCHES "^test_")
        message(STATUS "Add a test for ${SRC} ...")
        add_test(
            NAME "${BIN_NAME}_test"
            COMMAND $<TARGET_FILE:${BIN_NAME}>
            )
    endif()
endforeach()

set(FOLDER_NAME "dynamic_program")
file(GLOB HEADERs "${FOLDER_NAME}/*.h" "${FOLDER_NAME}/*.hpp")
file(GLOB SRCs "${FOLDER_NAME}/*.cc" "${FOLDER_NAME}/*.cpp")
foreach(SRC ${SRCs})
    get_filename_component(SRC_FILENAME_WE ${SRC} NAME_WE)
    set(BIN_NAME "${PROJECT_NAME}_${FOLDER_NAME}_${SRC_FILENAME_WE}")
    message(STATUS "Compiling for ${BIN_NAME} ...")
    add_executable(${BIN_NAME} ${HEADERs} ${SRC})
    target_link_libraries(${BIN_NAME} gtest_main)
    if (SRC_FILENAME_WE MATCHES "^test_")
        message(STATUS "Add a test for ${SRC} ...")
        add_test(
            NAME "${BIN_NAME}_test"
            COMMAND $<TARGET_FILE:${BIN_NAME}>
            )
    endif()
endforeach()

set(FOLDER_NAME "search")
file(GLOB HEADERs "${FOLDER_NAME}/*.h" "${FOLDER_NAME}/*.hpp")
file(GLOB SRCs "${FOLDER_NAME}/*.cc" "${FOLDER_NAME}/*.cpp")
foreach(SRC ${SRCs})
    get_filename_component(SRC_FILENAME_WE ${SRC} NAME_WE)
    set(BIN_NAME "${PROJECT_NAME}_${FOLDER_NAME}_${SRC_FILENAME_WE}")
    message(STATUS "Compiling for ${BIN_NAME} ...")
    add_executable(${BIN_NAME} ${HEADERs} ${SRC})
    target_link_libraries(${BIN_NAME} gtest_main)
    if (SRC_FILENAME_WE MATCHES "^test_")
        message(STATUS "Add a test for ${SRC} ...")
        add_test(
            NAME "${BIN_NAME}_test"
            COMMAND $<TARGET_FILE:${BIN_NAME}>
            )
    endif()
endforeach()

