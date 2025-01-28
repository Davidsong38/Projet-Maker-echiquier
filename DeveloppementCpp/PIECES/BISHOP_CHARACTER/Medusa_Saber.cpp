//
// Created by david on 24/01/2025.
//

#include "Medusa_Saber.h"

#include "../../Context.h"


vector<Effect_List> Medusa_Saber::getCasterEffects() const {
    if (evolved==true) {
        return {STUN,AOE};
    }
    return {STUN};
}



vector<pair<int, int> > Medusa_Saber::getEffectRange(Effect_List effect, int x, int y) const {

    vector<std::pair<int, int>> effect_range;

    if (effect == STUN) {
        if (x + 1 < 8 && y + 1 < 8) effect_range.emplace_back(x + 1, y + 1);
        if (x - 1 >= 0 && y + 1 < 8) effect_range.emplace_back(x - 1, y + 1);
        if (x + 1 < 8 && y - 1 >= 0) effect_range.emplace_back(x + 1, y - 1);
        if (x - 1 >= 0 && y - 1 >= 0) effect_range.emplace_back(x - 1, y - 1);
    }
    if (evolved==true) {
        if (effect == STUN) {
            if (x + 1 < 8) effect_range.emplace_back(x + 1, y);
            if (x - 1 >= 0) effect_range.emplace_back(x - 1, y);
            if (y - 1 >= 0) effect_range.emplace_back(x, y - 1);
            if (y + 1 >= 0) effect_range.emplace_back(x, y + 1);

        }
        if (effect == AOE) {
            if (x + 1 < 8 && y + 1 < 8) effect_range.emplace_back(x + 1, y + 1);
            if (x - 1 >= 0 && y + 1 < 8) effect_range.emplace_back(x - 1, y + 1);
            if (x + 1 < 8 && y - 1 >= 0) effect_range.emplace_back(x + 1, y - 1);
            if (x - 1 >= 0 && y - 1 >= 0) effect_range.emplace_back(x - 1, y - 1);
        }
    }
    return effect_range;
}


void Medusa_Saber::passive(void* arg) {
    auto * context = static_cast<context_type *>(arg);
    if (context->chessboard->KillCheck(context->piece,context->target_piece)) {
        EffectHandler::applyEffectToTargets(context->piece,STUN,*context->chessboard);
        CNT_StunEffect++;

    }
}

bool Medusa_Saber::canEvolve(void *arg) {
    if (evolved == false && CNT_StunEffect>1) {
        return true;
    }
    return false;

}

void Medusa_Saber::evolvedForm(void *arg) {
    evolved = true;

}
