//
// Created by david on 24/01/2025.
//

#include "Medusa_Saber.h"

vector<pair<int, int> > Medusa_Saber::getMovesMedusa_SaberStunEffect(int x, int y) const {
    vector<std::pair<int, int>> moves;
    if (x + 1 < 8 && y + 1 < 8) moves.emplace_back(x + 1, y + 1);
    if (x - 1 >= 0 && y + 1 < 8) moves.emplace_back(x - 1, y + 1);
    if (x + 1 < 8 && y - 1 >= 0) moves.emplace_back(x + 1, y - 1);
    if (x - 1 >= 0 && y - 1 >= 0) moves.emplace_back(x - 1, y - 1);
    return moves;
}



void Medusa_Saber::passive() {


}
