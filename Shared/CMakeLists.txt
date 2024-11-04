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

add_library(D2Shared SHARED ${SHARED_SRC})
set_target_properties(D2Shared PROPERTIES OUTPUT_NAME D2Shared)
set_target_properties(D2Shared PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(D2Shared ${STATIC_LIBRARIES})
target_compile_definitions(D2Shared PUBLIC D2Shared)

link_directories(${PROJECT_BINARY_DIR})
