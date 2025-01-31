//
// Created by david on 24/01/2025.
//

#include "Pieces.h"
#include <iostream>
#include <utility>
#include "Effect_List.h"
//Pieces::Pieces(string name) : name(std::move(name)) {}
Pieces::~Pieces() = default;

string Pieces::getName() const {
    return name;
}

bool Pieces::getIsWhite() const {
    return isWhite;
}

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

void Pieces::addEffectStatus(EffectInstance effect_instance) {
    activeEffects.emplace_back(effect_instance.getEffect(),effect_instance.getEffectDuration(),effect_instance.getEffectDuration());
}

Characters_List Pieces::getCharacters() const {
    return characters;
}
Pieces_List Pieces::getPiecesOrigin() const {
    return pieces_origin;
}
//void Pieces::affectCharacter(const Character_Instance& character_instance) {
//    characters.emplace_back(character_instance);
//}


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
    std::cout << "Yaharo0000"<<std::endl;
    for ( auto& e : activeEffects) {
        std::cout << Effect_List_to_string[e.effect] << "Yaharo"<<std::endl;
        if (e.effect == effect && !e.isExpired()) {
            std::cout << Effect_List_to_string[e.effect] << std::endl;
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

vector<EffectInstance> Pieces::getActive_effects() const {
    return activeEffects;
}


bool Pieces::isPawn(Pieces_List piece) {
    if (piece == PAWN_BLACK_1 || piece == PAWN_BLACK_2 || piece == PAWN_BLACK_3 || piece == PAWN_BLACK_4
        || piece == PAWN_BLACK_5 || piece == PAWN_BLACK_6 || piece == PAWN_BLACK_7 || piece == PAWN_BLACK_8
        || piece == PAWN_WHITE_1 || piece == PAWN_WHITE_2 || piece == PAWN_WHITE_3 || piece == PAWN_WHITE_4
        || piece == PAWN_WHITE_5 || piece == PAWN_WHITE_6 || piece == PAWN_WHITE_7 || piece == PAWN_WHITE_8) {
        return true;
        }
    return false;
}

bool Pieces::isKnight(Pieces_List piece) {
    if (piece == KNIGHT_BLACK_1 || piece == KNIGHT_BLACK_2 || piece == KNIGHT_WHITE_1 || piece == KNIGHT_WHITE_2) {
        return true;
    }
    return false;
}

bool Pieces::isBishop(Pieces_List piece) {
    if (piece == BISHOP_BLACK_1 || piece == BISHOP_BLACK_2 || piece == BISHOP_WHITE_1 || piece == BISHOP_WHITE_2) {
        return true;
    }
    return false;
}

bool Pieces::isRook(Pieces_List piece) {
    if (piece == ROOK_BLACK_1 || piece == ROOK_BLACK_2 || piece == ROOK_WHITE_1 || piece == ROOK_WHITE_2) {
        return true;
    }
    return false;
}

bool Pieces::isQueen(Pieces_List piece) {
    if (piece == QUEEN_BLACK || piece == QUEEN_WHITE) {
        return true;
    }
    return false;
}

bool Pieces::isKing(Pieces_List piece) {
    if (piece == KING_BLACK || piece == KING_WHITE) {
        return true;
    }
    return false;
}

