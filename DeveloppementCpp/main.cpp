#include <iostream>
#include <thread>

#include "Chessboard.h"
#include "Context.h"
#include "EffectHandler.h"
#include "Pieces.h"
#include "PIECES/Bishop.h"
#include "PIECES/BISHOP_CHARACTER/Medusa_Saber.h"

int main() {
    Chessboard chessboard(8);
    loadEffectList();
    EffectHandler effect_handler;
    Medusa_Saber rook(0,0,"rook",true);
    Medusa_Saber bishop1 (1,1,"bishop1",false);
    Medusa_Saber bishop2 (2,2,"bishop2",false);
    Medusa_Saber bishop3 (3,3,"bishop2",false);
    chessboard.placePiece(rook.getCoordX(), rook.getCoordY(), &rook);
    chessboard.placePiece(bishop1.getCoordX(), bishop1.getCoordY(), &bishop1);
    chessboard.placePiece(bishop2.getCoordX(), bishop2.getCoordY(), &bishop2);
    chessboard.placePiece(bishop3.getCoordX(), bishop3.getCoordY(), &bishop3);


    EffectHandler::configureEffectHandler(effect_handler, chessboard, &rook);
    EffectHandler::configureEffectHandler(effect_handler, chessboard, &bishop1);
    EffectHandler::configureEffectHandler(effect_handler, chessboard, &bishop2);
    std::cout << rook.getCoordX() << " " << rook.getCoordY() << std::endl;
    context_type context{&rook,&bishop2,&chessboard};
   // rook.addEffectStatus(TELEPORT,3,2);
   // rook.addEffectStatus(CHANGE_CONTROL,4,2);
   // effect_handler.executeEffect(TELEPORT,&rook);

    //chessboard.movePiece(&rook,1,1);
    chessboard.movePiece(&rook,2,2);
    if (chessboard.isKilled(&bishop2)) {
        rook.passive(&context);
    }
    rook.updateEffectStatus();
    rook.displayEffect();
    bishop1.displayEffect();
    bishop2.displayEffect();
    bishop3.displayEffect();
    bishop1.updateEffectStatus();
    bishop2.updateEffectStatus();
    bishop3.updateEffectStatus();
    bishop1.displayEffect();
    bishop2.displayEffect();
    bishop3.displayEffect();
    std::cout << rook.getCoordX() << " " << rook.getCoordY() << std::endl;
    auto moves = rook.getMoves();

    for (const auto& move : moves) {
        std::cout << "(" << move.first << ", " << move.second << ")\n";
    }
    return 0;

}
