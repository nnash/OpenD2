message(STATUS "Including game.exe files")

set(ENGINE_SRC
    Audio_SDL.cpp
    Audio_SDL.hpp
    Audio.cpp
    Audio.hpp
    Bitmap.cpp
    Bitmap.hpp
    Bitstream.cpp
    Bitstream.hpp
    COF.cpp
    COF.hpp
    DC6.cpp
    DC6.hpp
    DCC.cpp
    DCC.hpp
    diablo2.cpp
    Diablo2.hpp
    DS1.cpp
    DS1.hpp
    DT1.cpp
    DT1.hpp
    FileSystem_MPQ.cpp
    FileSystem_MPQ.hpp
    FileSystem.cpp
    FileSystem.hpp
    GraphicsManager.cpp
    GraphicsManager.hpp
    INI.cpp
    INI.hpp
    Input.cpp
    Input.hpp
    Logging.cpp
    Logging.hpp
    LRUQueue.hpp
    MPQ.cpp
    MPQ.hpp
    Network.cpp
    Network.hpp
    Palette.cpp
    Palette.hpp
    Platform.hpp
    Renderer_GL.cpp
    Renderer_GL.hpp
    Renderer_SDL.hpp
    Renderer.cpp
    Renderer.hpp
    TBL_Font.cpp
    TBL_Font.hpp
    TBL_Text.cpp
    TBL_Text.hpp
    Threadpool.cpp
    Threadpool.hpp
    Window.cpp
    Window.hpp
)

# TODO figure this out
if(WIN32)
  set(STATIC_LIBRARIES dbghelp.lib psapi.lib)
endif()


file(GLOB_RECURSE ADPCM_SRC ../Libraries/adpcm/*)
file(GLOB_RECURSE HUFFMAN_SRC ../Libraries/huffman/*)
file(GLOB_RECURSE PKWARE_SRC ../Libraries/pkware/*)

source_group("Libraries\\adpcm" FILES ${ADPCM_SRC})
source_group("Libraries\\huffman" FILES ${HUFFMAN_SRC})
source_group("Libraries\\pkware" FILES ${PKWARE_SRC})

set(LIBRARY_SRC ${ADPCM_SRC} ${HUFFMAN_SRC} ${PKWARE_SRC})

message(STATUS "Library SRC ${LIBRARY_SRC}")
if(WIN32)
  set(ENGINE_SRC
      "${ENGINE_SRC}"
      Platform_Windows.cpp
  )
else()
  set(ENGINE_SRC
      "${ENGINE_SRC}"
      Platform_Linux.cpp
  )
endif()

source_group("Engine" FILES ${ENGINE_SRC})

find_package(SDL2_mixer REQUIRED)
find_package(SDL2_net REQUIRED)
find_package(SDL2 REQUIRED)
find_package(glew REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)

add_executable(game ${LIBRARY_SRC} ${ENGINE_SRC} )

set_target_properties(game PROPERTIES OUTPUT_NAME game)
set_target_properties(game PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(game 
                      PRIVATE
                      SDL2_mixer::SDL2_mixer
                      SDL2_net::SDL2_net
                      SDL2::SDL2
                      GLEW::GLEW
                      glfw
                      glm::glm
)

target_link_libraries(game
                      PRIVATE
                      D2Shared
)

if(WIN32)
  set_target_properties(game PROPERTIES LINK_FLAGS /SUBSYSTEM:WINDOWS)
else()
  target_link_libraries(game PRIVATE m dl)
endif()

target_compile_definitions(game PUBLIC D2EXE)
