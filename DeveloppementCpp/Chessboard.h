//
// Created by david on 24/01/2025.
//

#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include <iostream>
#include <vector>

#include "Effect_List.h"
#include "Pieces.h"
using namespace std;




class Chessboard {
    private:
        vector<vector<Pieces*>> grid;
    protected:
        vector<EffectInstance> EffectOnPieces;
    public:
        explicit Chessboard(int size) : grid(size, vector<Pieces*>(size, nullptr)) {};
        void placePiece(int coordX, int coordY, Pieces* piece);
        bool isMovePossible(Pieces* piece,int to_coordX, int to_coordY); // vérifie si le movement est dans le plateau, qu'il n'est pas sur un allié et que la pièce possède ce movement
        void movePiece(Pieces* piece,int to_coordX,int to_coordY);
        bool KillCheck(Pieces* piece,Pieces* target_piece);
        void displayBoard() const;
        static bool isKillable(Pieces* piece) ; // vérifie si la pièce peut être tué ( ne possède pas d'effet qui la protège)
        static bool isMoveable(Pieces* piece) ; // vérifie si la pièce n'est pas affecté par des effets d'immobilisation
        bool isKilled(Pieces* piece) const; // vérifie si la pièce est morte

        [[nodiscard]] vector<vector<Pieces *>> getGrid() const;
};



#endif //CHESSBOARD_H
