set(VFS_HEADERS
    imStream.h
    imVfs.h
)

set(VFS_SOURCES
    dnifile.cpp
    imStream.cpp
    imVfs.cpp
)
source_group("Header Files" FILES ${VFS_HEADERS})
source_group("Source Files" FILES ${VFS_SOURCES})

include_directories(${SDL_INCLUDE_DIR} ${ZLIB_INCLUDE_DIR})

add_library(VFS STATIC ${VFS_HEADERS} ${VFS_SOURCES})
