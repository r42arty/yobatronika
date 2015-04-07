//
//  TextureManager.cpp
//  yobatronika
//
//  Created by Maxim Fedorenko on 07.04.15.
//
//

#include "TextureManager.h"
#include <SDL_image.h>

using namespace Yoba;

std::shared_ptr<TextureManager> TextureManager::m_spInstance = nullptr;

bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer *pRenderer)
{
    SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());
    if(pTempSurface == nullptr) {
        return false;
    }
    
    SDL_Texture *pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
    
    SDL_FreeSurface(pTempSurface);
    
    if(pTexture != nullptr) {
        m_textureMap[id] = pTexture;
        return true;
    }
    
    return false;
}

void TextureManager::draw(std::string id, int x, int y, int width, int height,
                          SDL_Renderer *pRenderer, SDL_RendererFlip flip)
{
    SDL_Rect srcRect;
    SDL_Rect destRect;
    
    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    
    destRect.x = x;
    destRect.y = y;
    
    SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame,
                               SDL_Renderer *pRenderer, SDL_RendererFlip flip)
{
    SDL_Rect srcRect;
    SDL_Rect destRect;
    
    srcRect.x = width * (currentFrame - 1);
    srcRect.y = height * (currentRow - 1);
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    
    destRect.x = x;
    destRect.y = y;
    
    SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

std::shared_ptr<TextureManager> TextureManager::Instance()
{
    if(m_spInstance == nullptr)
    {
        m_spInstance = std::shared_ptr<TextureManager>(new TextureManager());
    }
    return m_spInstance;
}

void TextureManager::DeleteInstance() {
    m_spInstance.reset();
}
