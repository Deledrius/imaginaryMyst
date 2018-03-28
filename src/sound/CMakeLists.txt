set(Sound_HEADERS
    imSoundSource.h
)

set(Sound_SOURCES
    imSoundSource.cpp
)
source_group("Header Files" FILES ${Sound_HEADERS})
source_group("Source Files" FILES ${Sound_SOURCES})

include_directories(${SDL_INCLUDE_DIR})

add_library(Sound STATIC ${Sound_HEADERS} ${Sound_SOURCES})
