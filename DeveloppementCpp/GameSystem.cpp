//
// Created by david on 25/01/2025.
//

#include "GameSystem.h"

#include "Chessboard.h"
#include "Context.h"
#include "PIECES.h"
#include "PIECES/King.h"
#include "PIECES/BISHOP_CHARACTER/Medusa_Saber.h"
#include "PIECES/KING_CHARACTER/Artoria.h"
#include "PIECES/KNIGHT_CHARACTER/Ushiwakamaru.h"
#include "PIECES/PAWN_CHARACTER/Nemo_Marine.h"
#include "PIECES/QUEEN_CHARACTER/Sesshoin_Kiara.h"
#include "PIECES/ROOK_CHARACTER/Arceuid.h"


void GameSystem::setState(GameState state) {
    current_state = state;
}

void GameSystem::handleInitialisation(void * arg) {
    auto * context = static_cast<context_type *>(arg);
    context->chessboard = &chessboard;
    loadEffectList();
    loadCharactersList();
    loadPiecesList();
    chessboard.displayBoard();
    pieceInitialisation(&chessboard);
    chessboard.displayBoard();
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
    //if (chessboard.isKilled(context->target_piece) && context->target_piece->isKing() ) {
        setState(END_GAME);
    //} else {
    //    setState(START_BLACK_PHASE);
    //}
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
    if (context->chessboard->isKilled(context->target_piece) && context->target_piece->isKing() ) {
        setState(END_GAME);
    } else {
        setState(START_WHITE_PHASE);
    }
}

void GameSystem::handleEndGame(void* arg) {
    auto * context = static_cast<context_type *>(arg);
    cout << "END GAME" << endl;
}



void GameSystem::choosePawn(Chessboard * chessboard,int to_coordX, int to_coordY, bool isWhite) {
    int ID_character;
    cin >> ID_character;
    if (ID_character == 20) {
        auto* nemo_marine = new Nemo_Marine(to_coordX,to_coordY,isWhite,NEMO_MARINE,PAWN);
        EffectHandler::configureEffectHandler(*chessboard,nemo_marine);
        chessboard->placePiece(nemo_marine->getCoordX(),nemo_marine->getCoordY(),nemo_marine);

    }
}

void GameSystem::chooseBishop(Chessboard * chessboard,int to_coordX, int to_coordY,bool isWhite) {
    int ID_character;
    cin >> ID_character;
    if (ID_character == 0) {
        auto *medusa_saber = new Medusa_Saber(to_coordX,to_coordY,isWhite,MEDUSA_SABER,BISHOP);
        EffectHandler::configureEffectHandler(*chessboard,medusa_saber);
        chessboard->placePiece(medusa_saber->getCoordX(),medusa_saber->getCoordY(),medusa_saber);
    }
}


void GameSystem::chooseRook(Chessboard * chessboard,int to_coordX, int to_coordY,bool isWhite) {
    int ID_character;
    cin >> ID_character;
    if (ID_character == 8) {
        auto* arceuid = new Arceuid(to_coordX,to_coordY,isWhite,ARCEUID,ROOK);
        EffectHandler::configureEffectHandler(*chessboard,arceuid);
        chessboard->placePiece(arceuid->getCoordX(),arceuid->getCoordY(),arceuid);
    }
}

void GameSystem::chooseKnight(Chessboard * chessboard,int to_coordX, int to_coordY,bool isWhite) {
    int ID_character;
    cin >> ID_character;
    if (ID_character == 4) {
        auto* ushiwakamaru = new Ushiwakamaru(to_coordX,to_coordY,isWhite,USHIWAKAMARU,KNIGHT);
        EffectHandler::configureEffectHandler(*chessboard,ushiwakamaru);
        chessboard->placePiece(ushiwakamaru->getCoordX(),ushiwakamaru->getCoordY(),ushiwakamaru);
    }
}

void GameSystem::chooseQueen(Chessboard * chessboard,int to_coordX, int to_coordY,bool isWhite) {
    int ID_character;
    cin >> ID_character;
    if (ID_character == 12) {
        auto* sesshoin_kiara =new Sesshoin_Kiara(to_coordX,to_coordY,isWhite,SESSHOIN_KIARA,QUEEN);
        EffectHandler::configureEffectHandler(*chessboard,sesshoin_kiara);
        chessboard->placePiece(sesshoin_kiara->getCoordX(),sesshoin_kiara->getCoordY(),sesshoin_kiara);
    }
}

void GameSystem::chooseKing(Chessboard * chessboard,int to_coordX, int to_coordY,bool isWhite) {
    int ID_character;
    cin >> ID_character;
    if (ID_character == 16) {
        auto* artoria = new Artoria(to_coordX,to_coordY,isWhite,ARTORIA,KING);
        EffectHandler::configureEffectHandler(*chessboard,artoria);
        chessboard->placePiece(artoria->getCoordX(),artoria->getCoordY(),artoria);
    }
}


void GameSystem::pieceInitialisation(Chessboard* chessboard) {
    cout << "Choose Black Pawns" << endl;
    for (int i = 0; i <= 7; i++) {
        choosePawn(chessboard,1,i,false);
        chessboard->displayBoard();
    }
    cout << "Choose White Pawns" << endl;
    for (int i = 0; i <= 7; i++) {
        choosePawn(chessboard,6,i,true);
    }
    cout << "Choose Black Rook1" << endl;
    chooseRook(chessboard,0,0,false);
    cout << "Choose White Rook1" << endl;
    chooseRook(chessboard,7,0,true);
    cout << "Choose Black Rook2" << endl;
    chooseRook(chessboard,0,7,false);
    cout << "Choose White Rook2" << endl;
    chooseRook(chessboard,7,7,true);
    cout << "Choose Black Knight1" << endl;
    chooseKnight(chessboard,0,1,false);
    cout << "Choose White Knight1" << endl;
    chooseKnight(chessboard,7,1,true);
    cout << "Choose Black Knight2" << endl;
    chooseKnight(chessboard,0,6,false);
    cout << "Choose White Knight2" << endl;
    chooseKnight(chessboard,7,6,true);
    cout << "Choose Black Bishop1" << endl;
    chooseBishop(chessboard,0,2,false);
    cout << "Choose White Bishop1" << endl;
    chooseBishop(chessboard,7,2,true);
    cout << "Choose Black Bishop2" << endl;
    chooseBishop(chessboard,0,5,false);
    cout << "Choose White Bishop2" << endl;
    chooseBishop(chessboard,7,5,true);
    cout << "Choose Black Queen" << endl;
    chooseQueen(chessboard,0,3,false);
    cout << "Choose White Queen" << endl;
    chooseQueen(chessboard,7,3,true);
    cout << "Choose Black King" << endl;
    chooseKing(chessboard,0,4,false);
    cout << "Choose White King" << endl;
    chooseKing(chessboard,7,4,true);

}

void GameSystem::run(void * arg) {
    while (current_state != END_GAME) {
        state_handlers[current_state]();
    }
}