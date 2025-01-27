//
// Created by david on 24/01/2025.
//

#include "Pieces.h"

#include <iostream>
#include <utility>
#include "Effect_List.h"
Pieces::Pieces(string name) : name(std::move(name)) {}
Pieces::~Pieces() = default;

string Pieces::getName() const {
    return name;
}

bool Pieces::getIsWhite() const {
    return isWhite;
}
/*void Pieces::EvolvedForm() {
    if (!evolved) {
        evolved = true;
    }
}*/

int Pieces::getCoordX() const {
    return coordX;
}
int Pieces::getCoordY() const {
    return coordY;
}
void Pieces::setPosition(int newX, int newY) {
    coordX = newX;
    coordY = newY;
}

void Pieces::addEffectStatus(Effect_List effect, int effect_duration, int effect_amount) {
    activeEffects.emplace_back(effect,effect_duration,effect_amount);
}

bool Pieces::hasEffectStatus(Effect_List effect) const {
    for (const auto& e : activeEffects) {
        if (e.effect == effect && !e.isExpired()) {
            return true;
        }
    }
    return false;

}

void Pieces::updateEffectStatus() {
    for (auto effect=activeEffects.begin(); effect!=activeEffects.end();) {
        effect->decrement_duration();
        if (effect->isExpired()) {
            effect= activeEffects.erase(effect);
        } else {
            ++effect;
        }
    }
}
void Pieces::activateEffect(Effect_List effect) {
    for ( auto& e : activeEffects) {
        if (e.effect == effect && !e.isExpired()) {
            e.activation();
            std::cout << "Effect " << Effect_List_to_string[e.effect] << " activated on piece!" << std::endl;

        }
    }
}

void Pieces::displayEffect() {
    for (const auto& e : activeEffects) {
        std::cout << "Effect: " << Effect_List_to_string[e.effect]
                  << ", Duration: " << (e.effect_duration == -1 ? "Infinite" : std::to_string(e.effect_duration))
                  << ", Activations: " << (e.effect_amount == -1 ? "Infinite" : std::to_string(e.effect_amount))
                  << std::endl;
    }
}

    const vector<EffectInstance> &Pieces::getActive_effects() const {
    return activeEffects;
}


