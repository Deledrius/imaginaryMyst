set(Surface_HEADERS
    imAnimLayer.h
    imLayer.h
    imMaterial.h
    imMipmap.h
    imTexture.h
)

set(Surface_SOURCES
    imAnimLayer.cpp
    imLayer.cpp
    imMaterial.cpp
    imMipmap.cpp
    imTexture.cpp
)
source_group("Header Files" FILES ${Surface_HEADERS})
source_group("Source Files" FILES ${Surface_SOURCES})

include_directories(${SDL_INCLUDE_DIR})
include_directories(${LIBSQUISH_INCLUDE_DIR})

add_library(Surface STATIC ${Surface_HEADERS} ${Surface_SOURCES})
target_link_libraries(Surface ${LIBSQUISH_LIBRARIES})
