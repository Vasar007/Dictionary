################################
# Unit Tests
################################

set(EXECUTABLE_NAME "Tests")

# Add test cpp file
add_executable(${EXECUTABLE_NAME}
    "concurrent_dictionary_tests.cpp"
)

# GTest needs threading support
set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)

if (CMAKE_USE_PTHREADS_INIT)
    set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-lpthread")
endif()

message(STATUS "Got Threads: ${CMAKE_THREAD_LIBS_INIT}")

# Link test executable against gtest & gtest_main
target_link_libraries(${EXECUTABLE_NAME} gtest gtest_main ${CMAKE_THREAD_LIBS_INIT})
set_target_properties(${EXECUTABLE_NAME} PROPERTIES LINKER_LANGUAGE CXX)

##################################
# Just make the test runnable with
#   $ make test

add_test(
    NAME    ${EXECUTABLE_NAME} 
    COMMAND ${EXECUTABLE_NAME}
)
