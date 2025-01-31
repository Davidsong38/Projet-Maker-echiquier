//
// Created by david on 25/01/2025.
//

#include "Pieces_List.h"

#include "Pieces.h"
string Pieces_List_to_string[PIECE_COUNT];
void loadPiecesList() {
    Pieces_List_to_string[PAWN_WHITE_1] = "PAWN_WHITE_1";
    Pieces_List_to_string[PAWN_WHITE_2] = "PAWN_WHITE_2";
    Pieces_List_to_string[PAWN_WHITE_3] = "PAWN_WHITE_3";
    Pieces_List_to_string[PAWN_WHITE_4] = "PAWN_WHITE_4";
    Pieces_List_to_string[PAWN_WHITE_5] = "PAWN_WHITE_5";
    Pieces_List_to_string[PAWN_WHITE_6] = "PAWN_WHITE_6";
    Pieces_List_to_string[PAWN_WHITE_7] = "PAWN_WHITE_7";
    Pieces_List_to_string[PAWN_WHITE_8] = "PAWN_WHITE_8";
    Pieces_List_to_string[ROOK_WHITE_1] = "ROOK_WHITE_1";
    Pieces_List_to_string[ROOK_WHITE_2] = "ROOK_WHITE_2";
    Pieces_List_to_string[KNIGHT_WHITE_1] = "KNIGHT_WHITE_1";
    Pieces_List_to_string[KNIGHT_WHITE_2] = "KNIGHT_WHITE_2";
    Pieces_List_to_string[BISHOP_WHITE_1] = "BISHOP_WHITE_1";
    Pieces_List_to_string[BISHOP_WHITE_2] = "BISHOP_WHITE_2";
    Pieces_List_to_string[QUEEN_WHITE] = "QUEEN_WHITE";
    Pieces_List_to_string[KING_WHITE] = "KING_WHITE";
    Pieces_List_to_string[EMPTY] = "EMPTY";
    Pieces_List_to_string[PAWN_BLACK_1] = "PAWN_BLACK_1";
    Pieces_List_to_string[PAWN_BLACK_2] = "PAWN_BLACK_2";
    Pieces_List_to_string[PAWN_BLACK_3] = "PAWN_BLACK_3";
    Pieces_List_to_string[PAWN_BLACK_4] = "PAWN_BLACK_4";
    Pieces_List_to_string[PAWN_BLACK_5] = "PAWN_BLACK_5";
    Pieces_List_to_string[PAWN_BLACK_6] = "PAWN_BLACK_6";
    Pieces_List_to_string[PAWN_BLACK_7] = "PAWN_BLACK_7";
    Pieces_List_to_string[PAWN_BLACK_8] = "PAWN_BLACK_8";
    Pieces_List_to_string[ROOK_BLACK_1] = "ROOK_BLACK_1";
    Pieces_List_to_string[ROOK_BLACK_2] = "ROOK_BLACK_2";
    Pieces_List_to_string[KNIGHT_BLACK_1] = "KNIGHT_BLACK_1";
    Pieces_List_to_string[KNIGHT_BLACK_2] = "KNIGHT_BLACK_2";
    Pieces_List_to_string[BISHOP_BLACK_1] = "BISHOP_BLACK_1";
    Pieces_List_to_string[BISHOP_BLACK_2] = "BISHOP_BLACK_2";
    Pieces_List_to_string[QUEEN_BLACK] = "QUEEN_BLACK";
    Pieces_List_to_string[KING_BLACK] = "KING_BLACK";

}


bool segregation_W(Pieces_List piece) {
    if (piece < EMPTY) {
        return true;
    }
    return false;
}

bool segregation_B(Pieces_List piece) {
    if (piece < PIECE_COUNT && piece > EMPTY ) {
        return true;
    }
    return false;
}


