include_directories(${PROJECT_SOURCE_DIR}/src/lib/)

add_executable(test_ds18b20 ds18b20.cpp)
add_test(test_ds18b20 test_ds18b20)
target_link_libraries(test_ds18b20 bard)

add_executable(test_gpio gpio.cpp)
add_test(test_gpio test_gpio)
target_link_libraries(test_gpio bard)
