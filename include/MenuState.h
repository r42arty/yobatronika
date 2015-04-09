//
//  MenuState.h
//  yobatronika
//
//  Created by Maxim Fedorenko on 10.04.15.
//
//

#ifndef yobatronika_MenuState_h
#define yobatronika_MenuState_h

#include "GameState.h"

namespace Yoba {
    
    class MenuState : public GameState {
    public:
        virtual void update() override;
        virtual void render() override;
        
        virtual bool onEnter() override;
        virtual bool onExit() override;
        
        virtual std::string getStateID() const { return s_menuID; }
    private:
        static const std::string s_menuID;
    };
    
}

#endif
