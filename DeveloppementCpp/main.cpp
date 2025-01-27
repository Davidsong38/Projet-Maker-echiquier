#include <iostream>

#include "Chessboard.h"
#include "EffectHandler.h"
#include "Pieces.h"
#include "PIECES/Bishop.h"
#include "PIECES/BISHOP_CHARACTER/Medusa_Saber.h"

int main() {
    Chessboard chessboard(8);
    loadEffectList();
    EffectHandler effect_handler;
    Medusa_Saber rook(0,0,"rook");
    EffectHandler::configureEffectHandler(effect_handler, chessboard, &rook);
    std::cout << rook.getCoordX() << " " << rook.getCoordY() << std::endl;
    rook.addEffectStatus(TELEPORT,3,2);
    rook.addEffectStatus(CHANGE_CONTROL,4,2);
    effect_handler.executeEffect(TELEPORT,&rook);
    rook.updateEffectStatus();
    rook.displayEffect();
    std::cout << rook.getCoordX() << " " << rook.getCoordY() << std::endl;
    auto moves = rook.getMoves(rook.getCoordX(), rook.getCoordY());

    for (const auto& move : moves) {
        std::cout << "(" << move.first << ", " << move.second << ")\n";
    }
    return 0;

}
