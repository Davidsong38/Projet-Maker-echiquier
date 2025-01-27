//
// Created by david on 25/01/2025.
//

#ifndef EFFECTHANDLER_H
#define EFFECTHANDLER_H
#include <functional>
#include<unordered_map>
#include "Chessboard.h"
#include "Effect_List.h"
using namespace std;


class EffectHandler {
    private:
        unordered_map<Effect_List, function<void()>> effectBehaviors;
    public:
        void executeEffect(Effect_List Effect,Pieces* pieces);
        void addEffectBehavior(Effect_List effect, function<void()> behavior);
        static void configureEffectHandler(EffectHandler& handler, Chessboard& board, Pieces* piece);


        explicit EffectHandler() = default;
};



#endif //EFFECTHANDLER_H
