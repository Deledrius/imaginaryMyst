add_subdirectory(anim)
add_subdirectory(scene)
add_subdirectory(sound)
add_subdirectory(surface)
add_subdirectory(vfs)

set(iMyst_HEADERS
    imCommon.h
    imGeometry3.h
    imKeyList.h
    imRef.h
    imString.h
    imThread.h
)

set(iMyst_SOURCES
    imGeometry3.cpp
    imKeyList.cpp
    imLog.cpp
    imString.cpp
    Main.cpp
)
source_group("Header Files" FILES ${iMyst_HEADERS})
source_group("Source Files" FILES ${iMyst_SOURCES})

include_directories(${SDL2_INCLUDE_DIR} ${GLM_INCLUDE_DIRS})

add_executable(imaginaryMyst WIN32 ${iMyst_HEADERS} ${iMyst_SOURCES})

target_link_libraries(imaginaryMyst Anim)
target_link_libraries(imaginaryMyst Scene)
target_link_libraries(imaginaryMyst Sound)
target_link_libraries(imaginaryMyst Surface)
target_link_libraries(imaginaryMyst VFS)
target_link_libraries(imaginaryMyst ${SDL2_LIBRARY} ${OPENGL_glu_LIBRARY} ${OPENGL_gl_LIBRARY} ${ZLIB_LIBRARIES})
