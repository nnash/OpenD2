
message(STATUS "Setting up D2Server library")

set(D2SERVER_SRC
    D2Server.hpp
    D2Server.cpp
)

source_group("Server" FILES ${D2SERVER_SRC})

add_library(D2Server SHARED ${D2SERVER_SRC})
set_target_properties(D2Server PROPERTIES OUTPUT_NAME D2Server)
set_target_properties(D2Server PROPERTIES LINKER_LANGUAGE CXX)

set_target_properties(D2Server 
    PROPERTIES 
    OUTPUT_NAME D2Server
    ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/Debug"
    LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/Debug"
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/Debug"
    ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/Release"
    LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/Release"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/Release"
)

target_link_libraries(D2Server ${STATIC_LIBRARIES} D2Common D2Shared)
target_compile_definitions(D2Server PUBLIC D2SERVER)