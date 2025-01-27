//
// Created by david on 24/01/2025.
//

#ifndef PIECES_H
#define PIECES_H
#include <string>
#include <utility>
#include <vector>
#include <memory>

#include "Effect_List.h"



using namespace std;

class Pieces {
    protected:
        int coordX{};
        int coordY{};
        string name;
        bool isWhite = false;
        bool evolved{};
        vector<EffectInstance> activeEffects ;


    public:


        explicit Pieces(int startX, int startY, string pieceName = "Unknown", bool white = false)
        : coordX(startX), coordY(startY), name(std::move(pieceName)), isWhite(white)  {}

        explicit Pieces(string name);

        virtual ~Pieces();

        [[nodiscard]] string getName() const;
        [[nodiscard]] int getCoordX() const;
        [[nodiscard]] int getCoordY() const;
        void setPosition(int newX,int newY);

        void addEffectStatus (Effect_List effect, int effect_duration = -1, int effect_amount = -1);
        [[nodiscard]] bool hasEffectStatus (Effect_List effect) const;
        void updateEffectStatus ();
        void activateEffect(Effect_List);
        void displayEffect();

        [[nodiscard]] bool getIsWhite() const;

        [[nodiscard]] const vector<EffectInstance>& getActive_effects() const;



        [[nodiscard]] virtual vector<pair<int, int>> getMoves(int x, int y) const = 0;
     //   virtual void passive() = 0;
     //   virtual void CanEvolve() = 0;
      //  virtual void EvolvedForm() = 0;


};



#endif //PIECES_H
