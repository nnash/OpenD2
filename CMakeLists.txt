cmake_minimum_required(VERSION 3.20)
project(OpenD2 CXX)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
option(BUILD_GAME "Build Executable" ON)
option(BUILD_D2CLIENT "Build D2Client" ON)
option(BUILD_D2SERVER "Build D2Server" ON)

set(SHARED_SRC "" CACHE INTERNAL "")

# Add shared files
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Shared")

# Build D2Common.dll
if(BUILD_D2CLIENT OR BUILD_D2SERVER)
	message(STATUS "Including D2Common.dll files")

	add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Modcode/Common")
endif()

# Build D2Client.dll
if(BUILD_D2CLIENT)
	message(STATUS "Including D2Client.dll files")

	add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Modcode/Client")
endif()

# Build D2Server.dll
if(BUILD_D2SERVER)
	message(STATUS "Including D2Server.dll files")

  add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Modcode/Server")
endif()

# Build game.exe
if(BUILD_GAME)
	add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Engine")
endif()
