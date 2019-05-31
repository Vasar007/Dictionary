################################
# GTest
################################

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(gtest-1.8.1)
enable_testing()

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

################################
# Unit Tests
################################

set(EXECUTABLE_NAME "Tests")

# Add test cpp file
add_executable(${EXECUTABLE_NAME}
    "my_dictionary_tests.cpp"
)

# Link test executable against gtest & gtest_main
target_link_libraries(${EXECUTABLE_NAME} gtest gtest_main)

##################################
# Just make the test runnable with
#   $ make test

add_test(
    NAME    ${EXECUTABLE_NAME} 
    COMMAND ${EXECUTABLE_NAME}
)
