set(BARD_SRCS
    ds18b20/ds18b20.cpp
    gpio/gpio.cpp
)

add_library(bard SHARED ${BARD_SRCS})

install(TARGETS bard DESTINATION lib)
install(FILES ds18b20/ds18b20.h DESTINATION include/bard)
install(FILES gpio/gpio.h DESTINATION include/bard)
