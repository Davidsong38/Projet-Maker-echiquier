//
// Created by david on 31/01/2025.
//

#ifndef ARTORIA_H
#define ARTORIA_H
#include "../King.h"


class Artoria final: public King{
    protected :
        int CNT_StunEffect = 0;
    public:
        Artoria(int startX, int startY, bool white, Characters_List hero,
            Pieces_List pieces_root)
            : King(startX, startY, white, hero, pieces_root) {
        }

        [[nodiscard]] vector<Effect_List> getCasterEffects() const override;
        [[nodiscard]] vector<pair<int, int>> getEffectRange(Effect_List effect) const override;
        void passive(void* arg) override;
        bool canEvolve(void* arg) override;
        void evolvedForm(void* arg) override;


};



#endif //ARTORIA_H
