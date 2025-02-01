//
// Created by david on 25/01/2025.
//

#ifndef GAMESYSTEM_H
#define GAMESYSTEM_H
#include <functional>
#include <unordered_map>

#include "Characters_List.h"
#include "Chessboard.h"
#include "EffectHandler.h"
#include "Pieces.h"
using namespace std;

enum GameState{
    INITIALISATION,
    START_WHITE_PHASE,
    MOVING_WHITE_PHASE,
    CHECKING_WHITE_PHASE,
    END_WHITE_PHASE,
    START_BLACK_PHASE,
    MOVING_BLACK_PHASE,
    CHECKING_BLACK_PHASE,
    END_BLACK_PHASE,
    END_GAME,
};

class GameSystem {

    private:
        int NB_Turn = 0;
        GameState current_state;
        Chessboard chessboard;
        EffectHandler effect_handler;

        unordered_map<GameState, function<void()>> state_handlers;
    public:

        explicit GameSystem(void * arg) : current_state(INITIALISATION), chessboard(8) {
            state_handlers[INITIALISATION] = [this, arg]() { handleInitialisation(arg); };
            state_handlers[START_WHITE_PHASE] = [this, arg]() { handleStartWhitePhase(arg); };
            state_handlers[MOVING_WHITE_PHASE] = [this, arg]() { handleMovingWhitePhase(arg); };
            state_handlers[CHECKING_WHITE_PHASE] = [this, arg]() { handleCheckingWhitePhase(arg); };
            state_handlers[END_WHITE_PHASE] = [this, arg]() { handleEndWhitePhase(arg); };
            state_handlers[START_BLACK_PHASE] = [this, arg]() { handleStartBlackPhase(arg); };
            state_handlers[MOVING_BLACK_PHASE] = [this, arg]() { handleMovingBlackPhase(arg); };
            state_handlers[CHECKING_BLACK_PHASE] = [this, arg]() { handleCheckingBlackPhase(arg); };
            state_handlers[END_BLACK_PHASE] = [this, arg]() { handleEndBlackPhase(arg); };
            state_handlers[END_GAME] = [this, arg]() { handleEndGame(arg); };
        }

        void run(void * arg);


        void setState(GameState state);
        void handleInitialisation(void * arg);
        void handleStartWhitePhase(void * arg);
        void handleMovingWhitePhase(void * arg);
        void handleCheckingWhitePhase(void * arg);
        void handleEndWhitePhase(void * arg);
        void handleStartBlackPhase(void * arg);
        void handleMovingBlackPhase(void * arg);
        void handleCheckingBlackPhase(void * arg);
        void handleEndBlackPhase(void * arg);
        static void handleEndGame(void * arg);


        static void pieceInitialisation(Chessboard * chessboard);
        static void chooseRook(Chessboard * chessboard, int coordX, int coordY, bool isWhite);
        static void choosePawn(Chessboard * chessboard, int coordX, int coordY, bool isWhite);
        static void chooseKnight(Chessboard * chessboard, int coordX, int coordY, bool isWhite);
        static void chooseBishop(Chessboard * chessboard, int coordX, int coordY, bool isWhite);
        static void chooseQueen(Chessboard * chessboard, int coordX, int coordY, bool isWhite);
        static void chooseKing(Chessboard * chessboard, int coordX, int coordY, bool isWhite);
        void CheckEffect();
        void CheckKill();


};















#endif //GAMESYSTEM_H
