message(STATUS "Setting up shared sources")

set(SHARED_SRC
    D2Common_DataTables.hpp
    D2Common_Shared.hpp
    D2DataTables.hpp
    D2HashMap.hpp
    D2Packets.cpp
    D2Packets.hpp
    D2Shared.cpp
    D2Shared.hpp
    D2World.hpp
    IgnoreWarnings.h
)

source_group("Shared" FILES ${SHARED_SRC})