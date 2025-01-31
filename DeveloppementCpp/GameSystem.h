//
// Created by david on 25/01/2025.
//

#ifndef GAMESYSTEM_H
#define GAMESYSTEM_H
#include <functional>
#include <unordered_map>

#include "Characters_List.h"
#include "Pieces.h"


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

        unordered_map<GameState, function<void()>> state_handlers;
    public:

        explicit GameSystem(void * arg) : current_state(INITIALISATION) {
            state_handlers[INITIALISATION] = [this, arg]() {handleInitialisation(arg);};
            state_handlers[START_WHITE_PHASE] = [this, arg]() {handleStartWhitePhase(arg);};
            state_handlers[MOVING_WHITE_PHASE] = [this, arg]() {handleMovingWhitePhase(arg);};
            state_handlers[CHECKING_WHITE_PHASE] = [this, arg]() {handleCheckingWhitePhase(arg);};
            state_handlers[END_WHITE_PHASE] = [this, arg]() {handleEndWhitePhase(arg);};
            state_handlers[START_BLACK_PHASE] = [this, arg]() {handleStartBlackPhase(arg);};
            state_handlers[MOVING_BLACK_PHASE] = [this, arg]() {handleMovingBlackPhase(arg);};
            state_handlers[CHECKING_BLACK_PHASE] = [this, arg]() {handleCheckingBlackPhase(arg);};
            state_handlers[END_BLACK_PHASE] = [this, arg]() {handleEndBlackPhase(arg);};
            state_handlers[END_GAME] = [this, arg]() {handleEndGame(arg);};
        }


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





};







    void pieceInitialisation(Characters_List characters_list);
    void chooseWhiteRook1(Pieces* piece);
    void chooseWhiteRook2(Pieces* piece);
    void chooseBlackRook1(Pieces* piece);
    void chooseBlackRook2(Pieces* piece);
    void chooseWhitePawn(Pieces* piece);
    void chooseBlackPawn(Pieces* piece);
    void chooseWhiteKnight1(Pieces* piece);
    void chooseWhiteKnight2(Pieces* piece);
    void chooseBlackKnight1(Pieces* piece);
    void chooseBlackKnight2(Pieces* piece);
    void chooseWhiteBishop1(Pieces* piece);
    void chooseWhiteBishop2(Pieces* piece);
    void chooseBlackBishop1(Pieces* piece);
    void chooseBlackBishop2(Pieces* piece);
    void chooseWhiteQueen(Pieces* piece);
    void chooseBlackQueen(Pieces* piece);
    void chooseWhiteKing(Pieces* piece);
    void chooseBlackKing(Pieces* piece);
    void CheckEffect();
    void CheckKill();







#endif //GAMESYSTEM_H
