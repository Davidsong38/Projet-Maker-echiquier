cmake_minimum_required(VERSION 3.30)
project(Chess)

set(CMAKE_CXX_STANDARD 20)

add_executable(Chess main.cpp
        Pieces.cpp
        Pieces.h
        Displayable.cpp
        Displayable.h
        PIECES/Pawn.cpp
        PIECES/Pawn.h
        PIECES/Bishop.cpp
        PIECES/Bishop.h
        PIECES/Rook.cpp
        PIECES/Rook.h
        PIECES/Queen.cpp
        PIECES/Queen.h
        PIECES/King.cpp
        PIECES/King.h
        PIECES/Knight.cpp
        PIECES/Knight.h
        PIECES/BISHOP_CHARACTER/Medusa_Saber.cpp
        PIECES/BISHOP_CHARACTER/Medusa_Saber.h
        Chessboard.cpp
        Chessboard.h
        Pieces_List.cpp
        Pieces_List.h
        GameSystem.cpp
        GameSystem.h
        Effect_List.cpp
        Effect_List.h
        EffectHandler.cpp
        EffectHandler.h
        Context.h
        Characters_List.cpp
        Characters_List.h
        PIECES/ROOK_CHARACTER/Arceuid.cpp
        PIECES/ROOK_CHARACTER/Arceuid.h
        PIECES/PAWN_CHARACTER/Nemo_Marine.cpp
        PIECES/PAWN_CHARACTER/Nemo_Marine.h
        PIECES/KNIGHT_CHARACTER/Ushiwakamaru.cpp
        PIECES/KNIGHT_CHARACTER/Ushiwakamaru.h
        PIECES/QUEEN_CHARACTER/Sesshoin_Kiara.cpp
        PIECES/QUEEN_CHARACTER/Sesshoin_Kiara.h
        PIECES/KING_CHARACTER/Artoria.cpp
        PIECES/KING_CHARACTER/Artoria.h
)
