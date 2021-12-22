add_executable(${PROJECT_NAME}_Test test.cpp 
    singleton_test.hpp singleton_test.cpp
)

target_link_libraries(${PROJECT_NAME}_Test
    gtest
    pthread
    singleton
    prototype
    builder
)
