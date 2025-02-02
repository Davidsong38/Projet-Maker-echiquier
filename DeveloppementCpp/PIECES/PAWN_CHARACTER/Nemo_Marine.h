//
// Created by david on 31/01/2025.
//

#ifndef NEMO_MARINE_H
#define NEMO_MARINE_H
#include "../Pawn.h"


class Nemo_Marine final: public Pawn  {
    protected :
        int CNT_StunEffect = 0;
    public:
        Nemo_Marine(int startX, int startY, bool white, Characters_List hero,
            Pieces_List pieces_root)
            : Pawn(startX, startY, white, hero, pieces_root) {
        }

        [[nodiscard]] vector<Effect_List> getCasterEffects() const override;
        [[nodiscard]] vector<pair<int, int>> getEffectRange(Effect_List effect) const override;
        void passive(void* arg) override;
        bool canEvolve(void* arg) override;
        void evolvedForm(void* arg) override;



};



#endif //NEMO_MARINE_H
