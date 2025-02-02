//
// Created by david on 31/01/2025.
//

#ifndef SESSHOIN_KIARA_H
#define SESSHOIN_KIARA_H
#include "../Queen.h"


class Sesshoin_Kiara final : public Queen{
    protected :
        int CNT_StunEffect = 0;
    public:
        Sesshoin_Kiara(int startX, int startY, bool white, Characters_List hero,
            Pieces_List pieces_root)
            : Queen(startX, startY, white, hero, pieces_root) {
        }

        [[nodiscard]] vector<Effect_List> getCasterEffects() const override;
        [[nodiscard]] vector<pair<int, int>> getEffectRange(Effect_List effect) const override;
        void passive(void* arg) override;
        bool canEvolve(void* arg) override;
        void evolvedForm(void* arg) override;


};



#endif //SESSHOIN_KIARA_H
