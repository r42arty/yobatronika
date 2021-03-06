//
//  SDLGameObject.h
//  yobatronika
//
//  Created by Maxim Fedorenko on 08.04.15.
//
//

#ifndef yobatronika_SDLGameObject_h
#define yobatronika_SDLGameObject_h

#include <string>

#include "GameObject.h"
#include "Vector2D.h"

namespace Yoba {
    
    class SDLGameObject : public GameObject {
    public:
        SDLGameObject(const LoaderParams &params);
        virtual ~SDLGameObject();
        
        virtual void draw() override;
        virtual void update() override;
        virtual void clean() override;
        
        Vector2D getPosition() { return m_position; }
        int getWidth() { return m_width; }
        int getHeight() { return m_height; }
        
    protected:
        Vector2D m_position;
        Vector2D m_velocity;
        Vector2D m_acceleration;
        
        int m_width;
        int m_height;
        
        int m_currentRow;
        int m_currentFrame;
        
        int m_numFrames;
        
        std::string m_textureID;
        
        SDL_RendererFlip m_renderFlip = SDL_FLIP_NONE;
    };
}

#endif
