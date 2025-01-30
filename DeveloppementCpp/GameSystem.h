//
// Created by david on 25/01/2025.
//

#ifndef GAMESYSTEM_H
#define GAMESYSTEM_H
#include "Characters_List.h"
#include "Pieces.h"


enum GameSystem {
    INITIALISATION,
    START_TURN,
    MOVING_PHASE,
    CHECKING_PHASE,
    END_TURN,
    END_GAME,
};

class GameSystemFunction {

    private:
        int NB_Turn = 0;
    public:
        void pieceInitialisation(Characters_List characters_list);
        void chooseWhiteRook(Pieces* piece);
        void chooseBlackRook(Pieces* piece);
        void chooseWhitePawn(Pieces* piece);
        void chooseBlackPawn(Pieces* piece);
        void chooseWhiteKnight(Pieces* piece);
        void chooseBlackKnight(Pieces* piece);
        void chooseWhiteBishop(Pieces* piece);
        void chooseBlackBishop(Pieces* piece);
        void chooseWhiteQueen(Pieces* piece);
        void chooseBlackQueen(Pieces* piece);
        void chooseWhiteKing(Pieces* piece);
        void chooseBlackKing(Pieces* piece);
        void Initialisation();
        void CheckEffect();

};





#endif //GAMESYSTEM_H
