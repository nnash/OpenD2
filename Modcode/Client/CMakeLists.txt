if (NOT SHARED_SRC)
  message(FATAL_ERROR "SHARED_SRC must be set")
endif()

message(STATUS "Setting up D2Client library")

set(D2Client_SRC
    D2Client_Helpers.cpp
    D2Client_Packets.cpp
    D2Client.cpp
    D2Client.hpp
    D2ClientDebug.cpp
    D2ClientDebug.hpp
)

source_group("Client" FILES ${D2Client_SRC})

add_library(D2Client SHARED ${D2Client_SRC} ${SHARED_SRC})
set_target_properties(D2Client PROPERTIES OUTPUT_NAME D2Client)
set_target_properties(D2Client PROPERTIES LINKER_LANGUAGE CXX)

set_target_properties(D2Client 
    PROPERTIES 
    OUTPUT_NAME D2Client
    ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/Debug"
    LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/Debug"
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/Debug"
    ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/Release"
    LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/Release"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/Release"
)

target_link_libraries(D2Client ${STATIC_LIBRARIES} D2Common)
target_compile_definitions(D2Client PUBLIC D2Client)