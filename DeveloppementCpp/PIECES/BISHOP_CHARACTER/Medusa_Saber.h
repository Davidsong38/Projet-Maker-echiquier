//
// Created by david on 24/01/2025.
//

#ifndef MEDUSA_SABER_H
#define MEDUSA_SABER_H
#include "../Bishop.h"


class Medusa_Saber final : public Bishop{
    protected :
        int CNT_StunEffect = 0;
    public:
        Medusa_Saber(int startX, int startY, bool white, Characters_List hero,
             Pieces_List pieces_root)
            : Bishop(startX, startY, white, hero, pieces_root) {
        }

        [[nodiscard]] vector<Effect_List> getCasterEffects() const override;
        [[nodiscard]] vector<pair<int, int>> getEffectRange(Effect_List effect) const override;
        void passive(void* arg) override;
        bool canEvolve(void* arg) override;
        void evolvedForm(void* arg) override;



};



#endif //MEDUSA_SABER_H
