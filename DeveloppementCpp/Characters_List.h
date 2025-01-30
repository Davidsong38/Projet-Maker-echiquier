//
// Created by david on 30/01/2025.
//

#ifndef CHARACTERS_LIST_H
#define CHARACTERS_LIST_H
#include <string>

#include "Pieces.h"
#include "Pieces_List.h"
using namespace std;

enum Characters_List {
    MEDUSA_SABER,
    MERLIN,
    ASTOLFO,
    TAMAMO_NO_MAE,
    USHIWAKAMARU,
    OKITA,
    KINTOKI_RIDER,
    ZHOU_YU,
    ARCEUID,
    XU_FU,
    MELUSINE,
    MASH,
    SESSHOIN_KIARA,
    NITOCRIS_ALTER,
    BB_DUBAI,
    KUKULKAN,
    ARTORIA,
    GILGAMESH,
    OBERON,
    ZHUGE_LIANG,
    NEMO_MARINE,
    NOBU,
    CHARACTERS_COUNT,

};

extern string Characters_List_to_string[CHARACTERS_COUNT];
void loadCharatersList();

struct Character_Instance {
    Characters_List character;
    Pieces_List piece_origin;
    string piece_name;
};

#endif //CHARACTERS_LIST_H
