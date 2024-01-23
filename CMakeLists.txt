cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(game)

set(SFML_STATIC_LIBRARIES TRUE)

find_package(Freetype REQUIRED)
find_package(JPEG REQUIRED)
find_package(SFML 2 COMPONENTS window graphics system REQUIRED)

add_executable(app
${CMAKE_CURRENT_SOURCE_DIR}/game/gameFile/collisionCheck.cpp
${CMAKE_CURRENT_SOURCE_DIR}/game/gameFile/declaration.hpp
${CMAKE_CURRENT_SOURCE_DIR}/game/gameFile/goCarFunc.cpp
${CMAKE_CURRENT_SOURCE_DIR}/game/gameFile/init.cpp
${CMAKE_CURRENT_SOURCE_DIR}/game/gameFile/main.cpp
${CMAKE_CURRENT_SOURCE_DIR}/game/gameFile/mous.cpp
${CMAKE_CURRENT_SOURCE_DIR}/game/gameFile/pollEvents.cpp
${CMAKE_CURRENT_SOURCE_DIR}/game/gameFile/redRawFrame.cpp
${CMAKE_CURRENT_SOURCE_DIR}/game/gameFile/update.cpp
${CMAKE_CURRENT_SOURCE_DIR}/game/gameFile/upDateCar.cpp
${CMAKE_CURRENT_SOURCE_DIR}/game/gameFile/collisionCheckInitPass.cpp
${CMAKE_CURRENT_SOURCE_DIR}/game/gameFile/updateUserCar.cpp
${CMAKE_CURRENT_SOURCE_DIR}/game/gameFile/updatePassenger.cpp
${CMAKE_CURRENT_SOURCE_DIR}/game/gameFile/updateDestination.cpp
)

target_include_directories(app PRIVATE ${SFML_INCLUDE_DIR})
# target_compile_features(app PUBLIC cxx_std_17)
target_compile_definitions(app PRIVATE SFML_STATIC)

target_link_libraries(app ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})