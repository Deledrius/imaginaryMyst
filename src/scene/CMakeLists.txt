set(Scene_HEADERS
    imEnvironment.h
    imSceneDatabase.h
    imSceneIndex.h
)

set(Scene_SOURCES
    imEnvironment.cpp
    imSceneDatabase.cpp
    imSceneIndex.cpp
)
source_group("Header Files" FILES ${Scene_HEADERS})
source_group("Source Files" FILES ${Scene_SOURCES})

include_directories(${SDL_INCLUDE_DIR})

add_library(Scene STATIC ${Scene_HEADERS} ${Scene_SOURCES})
