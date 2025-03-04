//
//  SpriteSheet.h
//  Volt2D
//
//  Created by Seung Youp Baek on 4/20/15.
//  Copyright (c) 2015 Seung Youp Baek. All rights reserved.
//

#ifndef __Volt2D__SpriteSheet__
#define __Volt2D__SpriteSheet__

#ifdef _WIN32
#include <rapidxml.hpp>
#elif __APPLE__
#include "rapidxml/rapidxml.hpp"
#endif
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "Utility.hpp"
#include "Texture.h"

namespace Volt2D{
struct ImageEntry{
    float x;
    float y;
    float w;
    float h;
    float uvOriginX;
    float uvOriginY;
    float uvEndX;
    float uvEndY;
};

/**
 *  @class SpriteSheet
 *  @breif Custom Sprite Sheet
 *  @note Uses rapid_xml, therefore, only supports xml.
 *  \todo Make SpriteSheet class usable and finish implementing
 */
class SpriteSheet{
private:
    /**
     * A std::string unique name of sprite sheet
     */
    std::string frameName;
    
    /**
     *  Texture file name
     */
    std::string textureName;
    
    /**
     *  Texture loaded
     */
    Volt2D::Texture* texture;
    int w;
    int h;
    
    SpriteSheet();
    
    std::unordered_map<std::string, ImageEntry> entryMap;
    
    bool initSpriteSheetWithXML(const std::string filePath, const std::string fileName);
    
    friend class Sprite;
    friend class ProgressBar;
    friend class ProgressRadian;
    
    const ImageEntry* getImageEntry(std::string imageName);
    Volt2D::Texture* getTexture();
public:
    /**
     *  Create sprite sheet.
     *  Requires texture image and xml data file
     *  @param frameName Sprite sheet name
     *  @param filePath Path to sprite sheet image file and xml
     *  @param fileName Name of file for both image and xml
     */
    static void createSpriteSheet(const std::string frameName, const std::string filePath, const std::string fileName);
    ~SpriteSheet();
};
}

#endif /* defined(__Volt2D__SpriteSheet__) */
