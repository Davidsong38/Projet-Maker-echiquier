//
// Created by david on 25/01/2025.
//

#include "GameSystem.h"

#include "Chessboard.h"
#include "Context.h"
#include "PIECES.h"
#include "PIECES/King.h"
#include "PIECES/BISHOP_CHARACTER/Medusa_Saber.h"
#include "PIECES/PAWN_CHARACTER/Nemo_Marine.h"
#include "PIECES/ROOK_CHARACTER/Arceuid.h"


void GameSystem::setState(GameState state) {
    current_state = state;
}

void GameSystem::handleInitialisation(void * arg) {
    auto * context = static_cast<context_type *>(arg);
    setState(START_WHITE_PHASE);
}

void GameSystem::handleStartWhitePhase(void * arg) {
    auto * context = static_cast<context_type *>(arg);
    setState(MOVING_WHITE_PHASE);


}
void GameSystem::handleMovingWhitePhase(void * arg) {
    auto * context = static_cast<context_type *>(arg);

        setState(CHECKING_WHITE_PHASE);
}

void GameSystem::handleCheckingWhitePhase(void * arg) {
    auto * context = static_cast<context_type *>(arg);
    setState(END_WHITE_PHASE);
}

void GameSystem::handleEndWhitePhase(void * arg) {
    auto * context = static_cast<context_type *>(arg);
    if (context->chessboard->isKilled(context->target_piece) && context->target_piece->isKing(context->target_piece) ) {
        setState(END_GAME);
    } else {
        setState(START_BLACK_PHASE);
    }
}

void GameSystem::handleStartBlackPhase(void * arg) {
    auto * context = static_cast<context_type *>(arg);
    setState(MOVING_BLACK_PHASE);
}

void GameSystem::handleMovingBlackPhase(void * arg) {
    auto * context = static_cast<context_type *>(arg);
    setState(CHECKING_BLACK_PHASE);
}

void GameSystem::handleCheckingBlackPhase(void * arg) {
    auto * context = static_cast<context_type *>(arg);
    setState(END_BLACK_PHASE);
}


void GameSystem::handleEndBlackPhase(void * arg) {
    auto * context = static_cast<context_type *>(arg);
    if (context->chessboard->isKilled(context->target_piece) && context->target_piece->isKing(context->target_piece) ) {
        setState(END_GAME);
    } else {
        setState(START_WHITE_PHASE);
    }
}

void GameSystem::handleEndGame(void* arg) {
    auto * context = static_cast<context_type *>(arg);
    cout << "END GAME" << endl;
}



void chooseBlackPawn(Pieces * character_piece, Chessboard * board,int to_coordX, int to_coordY) {
    int ID_character;
    cout << "Choose Black Pawns" << endl;
    cin >> ID_character;
    if (ID_character == 20) {
        Nemo_Marine black_nemo_marine(to_coordX,to_coordY,Characters_List_to_string[NEMO_MARINE],true,NEMO_MARINE,PAWN_BLACK_1);
        board->placePiece(character_piece->getCoordX(),character_piece->getCoordY(),character_piece);
    }
}

void chooseBlackBishop1(Pieces * character_piece, Chessboard * board,int to_coordX, int to_coordY) {
    int ID_character;
    cout << "Choose Black Bishop1" << endl;
    cin >> ID_character;
    if (ID_character == 0) {
        Medusa_Saber black_medusa_saber(to_coordX,to_coordY,Characters_List_to_string[MEDUSA_SABER],true,MEDUSA_SABER,BISHOP_BLACK_1);
        board->placePiece(character_piece->getCoordX(),character_piece->getCoordY(),character_piece);
    }
}

void chooseBlackBishop2(Pieces * character_piece, Chessboard * board,int to_coordX, int to_coordY) {
    int ID_character;
    cout << "Choose Black Bishop2" << endl;
    cin >> ID_character;
    if (ID_character == 0) {
        Medusa_Saber black_medusa_saber(to_coordX,to_coordY,Characters_List_to_string[MEDUSA_SABER],true,MEDUSA_SABER,BISHOP_BLACK_2);
        board->placePiece(character_piece->getCoordX(),character_piece->getCoordY(),character_piece);
    }
}

void chooseBlackRook1(Pieces * character_piece, Chessboard * board,int to_coordX, int to_coordY) {
    int ID_character;
    cout << "Choose Black Rook1" << endl;
    cin >> ID_character;
    if (ID_character == 0) {
        Arceuid black_arceuid(to_coordX,to_coordY,Characters_List_to_string[ARCEUID],true,ARCEUID,ROOK_BLACK_1);
        board->placePiece(character_piece->getCoordX(),character_piece->getCoordY(),character_piece);
    }
}





void pieceInitialisation(string character_name,Pieces* character_piece) {
    chooseBlackPawn(character_piece);
    chooseWhitePawn(character_piece);


}
