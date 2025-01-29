//
// Created by david on 24/01/2025.
//

#include "Chessboard.h"


void Chessboard::placePiece(int coordX,int coordY, Pieces* Pieces) {
    grid[coordX][coordY] = Pieces;
}

vector<vector<Pieces *>> Chessboard::getGrid() const {
    return grid;
}

bool Chessboard::isAlly(Pieces *piece, Pieces *target_piece) {
    if (piece->getIsWhite() == target_piece->getIsWhite()) {
        return true;
    }
    return false;
}

bool Chessboard::isPiecePossessMove(Pieces *piece, int to_coordX, int to_coordY) {
    for (const auto& moves : piece->getMoves(piece->getCoordX(),piece->getCoordY())) {
        if (moves.first == to_coordX && moves.second == to_coordY) {
            return true;
        }
    }
    return false;
}

bool Chessboard::isInGrid(Pieces *piece, int to_coordX, int to_coordY) const {
    int coordX = piece->getCoordX();
    int coordY = piece->getCoordY();
    if (coordX >= 0 && coordX < grid.size() && coordY >= 0 && coordY < grid.size() &&
            to_coordX >= 0 && to_coordX < grid.size() && to_coordY >= 0 && to_coordY < grid.size()) {
        return true;
    }
    return false;
}




bool Chessboard::isMovePossible(Pieces* piece,int to_coordX, int to_coordY) const {
    if (isInGrid(piece,to_coordX,to_coordY)
        && isPiecePossessMove(piece,to_coordX,to_coordY)
        && (grid[to_coordX][to_coordY] == nullptr || !isAlly(piece,grid[to_coordX][to_coordY]))) {
        return true;
    }
    return false;
}

void Chessboard::movePiece(Pieces* piece, int to_coordX, int to_coordY) {
    int coordX = piece->getCoordX();
    int coordY = piece->getCoordY();
    if (isMovePossible(piece,to_coordX,to_coordY) && grid[coordX][coordY] != nullptr) {
        Pieces* target_piece = grid[to_coordX][to_coordY];
        if (target_piece == nullptr) {
            grid[to_coordX][to_coordY] = piece ;      // Place la pièce dans la nouvelle case
            grid[coordX][coordY] = nullptr; // Libère l'ancienne case
            piece->setPosition(to_coordX, to_coordY);
        } else {
            KillCheck(piece,target_piece);
        }
        std::cout << "Piece moved from (" << coordX << ", " << coordY
                  << ") to (" << to_coordX << ", " << to_coordY << ")." << std::endl;
    } else {
           std::cout << "Move error!" << std::endl;
       }
}



bool Chessboard::isKillable(Pieces *piece) {
    for (const auto& e : piece->getActive_effects()) {
        if (e.effect == SHIELD || e.effect == IMMORTALITY ) {
            piece->activateEffect(e.effect);
            return false;
        }

    }
    return true;
}

bool Chessboard::KillCheck(Pieces *piece, Pieces *target_piece) {
    int coordX1 = piece->getCoordX();
    int coordY1 = piece->getCoordY();
    int coordX2 = target_piece->getCoordX();
    int coordY2 = target_piece->getCoordY();
    if (isKillable(target_piece)&& !isAlly(piece,target_piece)) {
        grid[coordX2][coordY2] = piece;
        grid[coordX1][coordY1] = nullptr;
        piece->setPosition(coordX2,coordY2);
        std::cout << piece->getName() << " killed " << target_piece->getName() << std::endl;
        return true;
    }
    return false;
}

bool Chessboard::isKilled(Pieces *piece) const {
    for (const auto &row : grid) {
        for (const auto &cell : row) {
            if (cell == piece) {
                return false;
            }
        }
    }
    return true;
}

bool Chessboard::isMoveable( Pieces* piece) {
    for (const auto& e : piece->getActive_effects()) {
        if (e.effect == STUN) {
            return false;
        }
    }
    return true;
}


void Chessboard::displayBoard() const {
    for (const auto &row : grid) {
        for (const auto &cell : row) {
            if (cell != nullptr) {
                cout << cell->getName() << " ";
            } else {
                cout << ". ";
            }

        }
        cout << endl;
    }
}



