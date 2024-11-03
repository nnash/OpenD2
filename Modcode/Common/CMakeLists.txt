if (NOT SHARED_SRC)
  add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/../../Shared")
endif()

message(STATUS "Setting up D2Common library")

set(D2COMMON_SRC
    D2Common_Math.cpp
    D2Common.cpp
    D2Common.hpp
    DataTables.cpp
    DRLG_DS1.cpp
    DRLG_Main.cpp
    DRLG.hpp
    Random.cpp
    TileCache.cpp
)

source_group("Common" FILES ${D2COMMON_SRC})

add_library(D2Common SHARED ${D2COMMON_SRC} ${SHARED_SRC})
set_target_properties(D2Common PROPERTIES OUTPUT_NAME D2Common)
set_target_properties(D2Common PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(D2Common ${STATIC_LIBRARIES})
target_compile_definitions(D2Common PUBLIC D2COMMON)

link_directories(${PROJECT_BINARY_DIR})