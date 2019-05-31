################################
# Unit Tests
################################

set(EXECUTABLE_NAME "Tests")

# Add test cpp file
add_executable(${EXECUTABLE_NAME}
    "concurrent_dictionary_tests.cpp"
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
