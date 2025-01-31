//
// Created by david on 25/01/2025.
//

#ifndef PIECES_LIST_H
#define PIECES_LIST_H
#include <string>

using namespace std;


enum Pieces_List {
    PAWN_WHITE_1,
    PAWN_WHITE_2,
    PAWN_WHITE_3,
    PAWN_WHITE_4,
    PAWN_WHITE_5,
    PAWN_WHITE_6,
    PAWN_WHITE_7,
    PAWN_WHITE_8,
    ROOK_WHITE_1,
    ROOK_WHITE_2,
    KNIGHT_WHITE_1,
    KNIGHT_WHITE_2,
    BISHOP_WHITE_1,
    BISHOP_WHITE_2,
    QUEEN_WHITE,
    KING_WHITE,
    EMPTY,
    PAWN_BLACK_1,
    PAWN_BLACK_2,
    PAWN_BLACK_3,
    PAWN_BLACK_4,
    PAWN_BLACK_5,
    PAWN_BLACK_6,
    PAWN_BLACK_7,
    PAWN_BLACK_8,
    ROOK_BLACK_1,
    ROOK_BLACK_2,
    KNIGHT_BLACK_1,
    KNIGHT_BLACK_2,
    BISHOP_BLACK_1,
    BISHOP_BLACK_2,
    QUEEN_BLACK,
    KING_BLACK,
    PIECE_COUNT,

};
extern string Pieces_List_to_string[PIECE_COUNT];
void loadPiecesList();


bool segregation_W(Pieces_List piece);
bool segregation_B(Pieces_List piece);





#endif //PIECES_LIST_H
