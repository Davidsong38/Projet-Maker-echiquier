//
// Created by david on 24/01/2025.
//

#include "Bishop.h"

vector<pair<int, int> > Bishop::getMoves(int x, int y) const {
    vector<std::pair<int, int>> moves;

    for (int i = 1; i < 8; ++i) {
        if (x + i < 8 && y + i < 8) moves.emplace_back(x + i, y + i); // Diagonale haut-droite
        if (x - i >= 0 && y + i < 8) moves.emplace_back(x - i, y + i); // Diagonale haut-gauche
        if (x + i < 8 && y - i >= 0) moves.emplace_back(x + i, y - i); // Diagonale bas-droite
        if (x - i >= 0 && y - i >= 0) moves.emplace_back(x - i, y - i); // Diagonale bas-gauche
    }

    return moves;
}


