//
// Created by david on 25/01/2025.
//

#ifndef PIECES_LIST_H
#define PIECES_LIST_H
#include <string>

using namespace std;


enum Pieces_List {
    PAWN_WHITE,
    ROOK_WHITE,
    KNIGHT_WHITE,
    BISHOP_WHITE,
    QUEEN_WHITE,
    KING_WHITE,
    EMPTY,
    PAWN_BLACK,
    ROOK_BLACK,
    KNIGHT_BLACK,
    BISHOP_BLACK,
    QUEEN_BLACK,
    KING_BLACK,
    PIECE_COUNT,

};
extern string Pieces_List_to_string[PIECE_COUNT];
void loadPiecesList();


bool segregation_W(Pieces_List piece);
bool segregation_B(Pieces_List piece);
bool isPawn(Pieces_List piece);
bool isRook(Pieces_List piece);
bool isKnight(Pieces_List piece);
bool isBishop(Pieces_List piece);
bool isKing(Pieces_List piece);
bool isQueen(Pieces_List piece);




#endif //PIECES_LIST_H
