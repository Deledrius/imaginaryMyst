set(Anim_HEADERS
    imAnimBehavior.h
    imController.h
    imKeyFrame.h
    imLeafController.h
)

set(Anim_SOURCES
    imAnimBehavior.cpp
    imController.cpp
    imKeyFrame.cpp
    imLeafController.cpp
)
source_group("Header Files" FILES ${Anim_HEADERS})
source_group("Source Files" FILES ${Anim_SOURCES})

include_directories(${SDL_INCLUDE_DIR})

add_library(Anim STATIC ${Anim_HEADERS} ${Anim_SOURCES})
