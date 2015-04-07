//
//  Player.h
//  yobatronika
//
//  Created by Maxim Fedorenko on 07.04.15.
//
//

#ifndef yobatronika_Player_h
#define yobatronika_Player_h

#include "GameObject.h"

namespace Yoba {
    
    class Player : public GameObject {
    public:
        Player(std::string name, int x, int y, int width, int height, std::string textureID);
        
    private:
        
        std::string m_sName;
    };
    
}

#endif