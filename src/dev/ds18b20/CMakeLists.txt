set(DS18B20_SRCS
    ds18b20.cpp
)

add_library(bard_ds18b20 SHARED ${DS18B20_SRCS})

install(TARGETS bard_ds18b20 DESTINATION lib)
install(FILES ds18b20.h DESTINATION include/bard)
