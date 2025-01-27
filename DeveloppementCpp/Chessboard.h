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
        void movePiece(int coordX, int coordY,int to_coordX,int to_coordY);
        bool KillCheck(Pieces* piece,Pieces* target_piece,int coordX1, int coordY1,int coordX2, int coordY2);
        void displayBoard() const;
        static bool isKillable(Pieces* piece) ; // vérifie si la pièce peut être tué
        static bool isMoveable(Pieces* piece) ; // vérifie si la pièce peut être déplacer
        bool isKilled(Pieces* piece) const; // vérifie si la pièce est morte

        [[nodiscard]] vector<vector<Pieces *>> getGrid() const;
};



#endif //CHESSBOARD_H
