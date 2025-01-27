//
// Created by david on 25/01/2025.
//

#include "Pieces_List.h"

#include "Pieces.h"
string Pieces_List_to_string[PIECE_COUNT];
void loadPiecesList() {
    Pieces_List_to_string[PAWN_WHITE] = "PAWN_WHITE";
    Pieces_List_to_string[ROOK_WHITE] = "ROOK_WHITE";
    Pieces_List_to_string[KNIGHT_WHITE] = "KNIGHT_WHITE";
    Pieces_List_to_string[BISHOP_WHITE] = "BISHOP_WHITE";
    Pieces_List_to_string[QUEEN_WHITE] = "QUEEN_WHITE";
    Pieces_List_to_string[KING_WHITE] = "KING_WHITE";
    Pieces_List_to_string[EMPTY] = "EMPTY";
    Pieces_List_to_string[PAWN_BLACK] = "PAWN_BLACK";
    Pieces_List_to_string[ROOK_BLACK] = "ROOK_BLACK";
    Pieces_List_to_string[KNIGHT_BLACK] = "KNIGHT_BLACK";
    Pieces_List_to_string[BISHOP_BLACK] = "BISHOP_BLACK";
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

bool isPawn(Pieces_List piece) {
    if (piece == PAWN_BLACK || piece == PAWN_WHITE) {
        return true;
    }
    return false;
}

bool isKnight(Pieces_List piece) {
    if (piece == KNIGHT_BLACK || piece == KNIGHT_WHITE) {
        return true;
    }
    return false;
}

bool isBishop(Pieces_List piece) {
    if (piece == BISHOP_BLACK || piece == BISHOP_WHITE) {
        return true;
    }
    return false;
}

bool isRook(Pieces_List piece) {
    if (piece == ROOK_BLACK || piece == ROOK_WHITE) {
        return true;
    }
    return false;
}

bool isQueen(Pieces_List piece) {
    if (piece == QUEEN_BLACK || piece == QUEEN_WHITE) {
        return true;
    }
    return false;
}

bool isKing(Pieces_List piece) {
    if (piece == KING_BLACK || piece == KING_WHITE) {
        return true;
    }
    return false;
}

