cmake_minimum_required(VERSION 3.23)
project(Machi_Koro)

set(CMAKE_CXX_STANDARD 14)

add_executable(Machi_Koro ${SOURCE_FILES} ${SOURCES} main.cpp bank/account.h cards/allCards.h cards/allCards.cpp bank/bank.h bank/bank.cpp cards/baseCard.h cards/baseCard.cpp game/board.h game/board.cpp cards/cardColor.h game/dice.h cards/establishmentCard.cpp cards/establishmentCard.h game/game.h cards/icon.cpp cards/icon.h extensions/marinaExtension.h players/player.cpp players/player.h cards/monument.h bank/account.cpp game/game.cpp cards/monument.cpp cards/cardColor.cpp)

