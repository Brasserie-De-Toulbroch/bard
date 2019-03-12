set(BARD_DS18B20_APP_SRCS
    main.cpp
)

add_executable(bard-ds18b20 ${BARD_DS18B20_APP_SRCS})
include_directories(${PROJECT_SOURCE_DIR}/src/lib/)
target_link_libraries(bard-ds18b20 bard)

install(TARGETS bard-ds18b20 DESTINATION bin)
