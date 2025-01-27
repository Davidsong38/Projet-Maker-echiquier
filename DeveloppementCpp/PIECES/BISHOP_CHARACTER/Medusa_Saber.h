//
// Created by david on 24/01/2025.
//

#ifndef MEDUSA_SABER_H
#define MEDUSA_SABER_H
#include "../Bishop.h"


class Medusa_Saber final : public Bishop{
public:
    Medusa_Saber(int startX, int startY, const string &pieceName)
        : Bishop(startX, startY, pieceName) {
    }
    [[nodiscard]] static vector<pair<int, int>> getMovesMedusa_SaberStunEffect(int x, int y) ;
    void passive();
    void CanEvolved() ;
    void EvolvedForm() ;


};



#endif //MEDUSA_SABER_H
