//
// Created by david on 25/01/2025.
//

#include "Effect_List.h"

string Effect_List_to_string[EFFECT_COUNT];

void loadEffectList() {
    Effect_List_to_string[STUN] = "stun";
    Effect_List_to_string[CHANGE_CONTROL] = "changeControl";
    Effect_List_to_string[AOE] = "aoe";
    Effect_List_to_string[GIVING_AOE] = "giveAoe";
    Effect_List_to_string[SHIELD] = "shield";
    Effect_List_to_string[IMMUNITY_EFFECT] = "immunityEffect";
    Effect_List_to_string[IMMUNITY_AOE]  = "immunityAoe";
    Effect_List_to_string[SPAWN_PIECES] = "spawnPieces";
    Effect_List_to_string[ONE_MORE_TURN] = "oneMoreTurn";
    Effect_List_to_string[SUPP_MOVE] = "suppMove";
    Effect_List_to_string[SUPP_RANGE] = "suppRange";
    Effect_List_to_string[MOVE_CHANGING] = "moveChanging";
    Effect_List_to_string[SWITCHING_PLACE] = "switchingPlace";
    Effect_List_to_string[IMMORTALITY] = "immortality";
    Effect_List_to_string[SACRIFICE] = "sacrifice";
    Effect_List_to_string[KILLING] = "killing";
    Effect_List_to_string[TELEPORT] = "teleport";
    Effect_List_to_string[EVOLVE] = "evolve";
    Effect_List_to_string[SUPP_LUCK] = "suppLuck";


}

EffectInstance::EffectInstance(const Effect_List effect, int effect_duration, int effect_amount)
    :effect(effect), effect_duration(effect_duration), effect_amount(effect_amount){}


bool EffectInstance::isInfinite() const {
    return effect_amount == -1 && effect_duration == -1;
}

bool EffectInstance::isExpired() const {
    return effect_amount == 0 || effect_duration == 0;
}

void EffectInstance::activation()  {
    if (effect_amount > 0) {
        effect_amount--;
    }
}

void EffectInstance::decrement_duration() {
    if (effect_duration > 0) {
        effect_duration--;
    }
}
