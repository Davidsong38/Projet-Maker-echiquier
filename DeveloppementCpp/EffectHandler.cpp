//
// Created by david on 25/01/2025.
//

#include "EffectHandler.h"
#include "Chessboard.h"
#include <utility>




void EffectHandler::executeEffect(Effect_List effect,Pieces* pieces) {
    if (effectBehaviors.find(effect) != effectBehaviors.end()) {
        effectBehaviors[effect]();
        pieces->activateEffect(effect);
    }
}

void EffectHandler::addEffectBehavior(Effect_List effect, function<void()> behavior) {
        effectBehaviors[effect] = std::move(behavior);
}

void EffectHandler::configureEffectHandler(EffectHandler &handler, Chessboard &board, Pieces *piece) {
    handler.addEffectBehavior(TELEPORT, [&board,piece]() {
        int toX = 0;
        int toY = 0;
        std::cout << "donnes les coord batard!!!";
        std::cin >> toX >> toY;
        if (toX >= 0 && toX < board.getGrid().size() && toY >= 0 && toY < board.getGrid().size()) {
            piece->setPosition(toX, toY);
        }


    });

}
