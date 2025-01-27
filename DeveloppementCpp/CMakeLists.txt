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
)
