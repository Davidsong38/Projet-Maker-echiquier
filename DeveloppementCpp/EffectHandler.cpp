//
// Created by david on 25/01/2025.
//

#include "EffectHandler.h"
#include "Chessboard.h"
#include <utility>




void EffectHandler::executeEffect(Effect_List effect,Pieces* target_piece) {
    if (effectBehaviors.find(effect) != effectBehaviors.end()) {
        effectBehaviors[effect]();
        target_piece->activateEffect(effect);
    }
}

void EffectHandler::addEffectBehavior(Effect_List effect, function<void()> behavior) {
        effectBehaviors[effect] = std::move(behavior);
}

void EffectHandler::configureEffectHandler(EffectHandler &handler, Chessboard &board, Pieces *piece) {
    handler.addEffectBehavior(TELEPORT, [&board,piece]() {
        int toX = 0;
        int toY = 0;
        std::cout << "donnes les coord!!!";
        std::cin >> toX >> toY;
        if (toX >= 0 && toX < board.getGrid().size() && toY >= 0 && toY < board.getGrid().size()) {
            piece->setPosition(toX, toY);
        }


    });

}

void EffectHandler::applyEffectToTargets(Pieces *caster_piece, EffectInstance effect_instance, Chessboard &board) {
    vector<pair<int,int>> effect_range = caster_piece->getEffectRange(effect_instance.getEffect(), caster_piece->getCoordX(), caster_piece->getCoordY());
    for (const auto &range: effect_range) {
        int targetX = range.first;
        int targetY = range.second;
        Pieces* target_piece = board.getGrid()[targetX][targetY];
        if (target_piece != nullptr) {
            //executeEffect(effect_instance.getEffect(), target_piece);
            target_piece->addEffectStatus(effect_instance);
            //target_piece->activateEffect(effect_instance.getEffect());
            std::cout << "Effect " << Effect_List_to_string[effect_instance.getEffect()] << " applied to piece at (" << targetX << ", " << targetY << ")." << std::endl;
        }
    }

}
