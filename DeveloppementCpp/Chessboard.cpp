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


bool Chessboard::isMovePossible(Pieces* piece,int to_coordX, int to_coordY) {
    int coordX = piece->getCoordX();
    int coordY = piece->getCoordY();
    if (coordX >= 0 && coordX < grid.size() && coordY >= 0 && coordY < grid.size() &&
        to_coordX >= 0 && to_coordX < grid.size() && to_coordY >= 0 && to_coordY < grid.size()) {
        return true;
    }
    return false;
}

void Chessboard::movePiece(Pieces* piece, int to_coordX, int to_coordY) {
    int coordX = piece->getCoordX();
    int coordY = piece->getCoordY();
    if (isMovePossible(piece,to_coordX,to_coordY) && grid[coordX][coordY] != nullptr) {

        grid[to_coordX][to_coordY] = grid[coordX][coordY] ;      // Place la pièce dans la nouvelle case
        grid[coordX][coordY] = nullptr; // Libère l'ancienne case
        piece->setPosition(to_coordX, to_coordY);

        std::cout << "Piece moved from (" << coordX << ", " << coordY
                  << ") to (" << to_coordX << ", " << to_coordY << ")." << std::endl;
        } else {
            std::cout << "Move out of bounds!" << std::endl;
        }
}

void Chessboard::displayBoard() const {
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] != nullptr) {
                cout << grid[i][j]->getName() << " ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
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
    if (coordX1 == coordX2 && coordY1 == coordY2 && isKillable(target_piece)&& piece->getIsWhite() != target_piece->getIsWhite()) {
        grid[coordX2][coordY2] = nullptr;
        grid[coordX1][coordY1] = nullptr;
        grid[coordX2][coordY2] = piece;
        std::cout << piece->getName() << " killed" << target_piece->getName() << std::endl;
        return true;
    }
    return false;
}

bool Chessboard::isKilled(Pieces *piece) const {
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] != piece) {
                return false;
            }
        }
    }
    return true;
}

bool Chessboard::isMoveable( Pieces* piece) {
    for (const auto& e : piece->getActive_effects()) {
        if (e.effect == STUN) {
            return true;
        }
    }
    return false;
}






