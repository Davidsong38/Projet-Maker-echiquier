//
// Created by david on 30/01/2025.
//

#ifndef ARCEUID_H
#define ARCEUID_H
#include "../Rook.h"


class Arceuid final: public Rook{
    protected :
        int CNT_StunEffect = 0;
    public:
        Arceuid(int startX, int startY, bool white, Characters_List hero,
            Pieces_List pieces_root)
            : Rook(startX, startY, white, hero, pieces_root) {
        }

        [[nodiscard]] vector<Effect_List> getCasterEffects() const override;
        [[nodiscard]] vector<pair<int, int>> getEffectRange(Effect_List effect) const override;
        void passive(void* arg) override;
        bool canEvolve(void* arg) override;
        void evolvedForm(void* arg) override;

};



#endif //ARCEUID_H
