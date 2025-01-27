//
// Created by david on 24/01/2025.
//

#ifndef BISHOP_H
#define BISHOP_H
#include "../Pieces.h"


class Bishop : public Pieces{
    public:
    Bishop(int startX, int startY, const string &pieceName)
        : Pieces(startX, startY, pieceName) {
    }

    [[nodiscard]] vector<pair<int, int>> getMoves(int x, int y) const override;

};



#endif //BISHOP_H
