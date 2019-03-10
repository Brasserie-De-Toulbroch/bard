set(BARD_SRCS
    ds18b20/ds18b20.cpp
)

add_library(bard SHARED ${BARD_SRCS})

install(TARGETS bard DESTINATION lib)
install(FILES ds18b20.h DESTINATION include/bard)
