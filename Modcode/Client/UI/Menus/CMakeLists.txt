message(STATUS "Setting up D2Client UI Menu source files")

source_group("UI/Menus" "${CMAKE_CURRENT_SOURCE_DIR}")

set(D2CLIENT_UI_MENUS_FILES
    CharCreate.cpp
    CharCreate.hpp
    CharSelect.cpp
    CharSelect.hpp
    Debug.cpp
    Debug.hpp
    Ingame.cpp
    Ingame.hpp
    LoadError.cpp
    LoadError.hpp
    Loading.cpp
    Loading.hpp
    Main.cpp
    Main.hpp
    OtherMultiplayer.cpp
    OtherMultiplayer.hpp
    TCPIP.cpp
    TCPIP.hpp
    Trademark.cpp
    Trademark.hpp
)


set(D2Client_SRC
    "${D2Client_SRC}"
    "${D2CLIENT_UI_MENUS_FILES}"
)