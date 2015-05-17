//
//  ActionDelay.cpp
//  OpenGL_2D_Framework
//
//  Created by Seung Youp Baek on 12/7/14.
//  Copyright (c) 2014-2015 Seung Youp Baek. All rights reserved.
//

#include "ActionDelay.h"

ActionDelay::ActionDelay():
ActionObject()
{
    cout << "Creating ACTION_DELAY" << endl;
}

ActionDelay::~ActionDelay(){
    cout << "Deleting ACTION_DELAY" << endl;
}

void ActionDelay::initDelay(double duration){
    this->duration = duration;
    this->actionID = ACTION_DELAY;
    
    this->totalDelayed = 0;
    this->delayTick = 0;
}

void ActionDelay::instantUpdate(){
    //Finish action
    totalDelayed = duration;
    alive = false;
}

void ActionDelay::intervalUpdate(){
    
}

void ActionDelay::update(double elapsedTime, double unusedtime){
    //cast to float
    float dur = (float)duration;
    float currentTime = (float)(totalElapsedTime + unusedtime);
    
    if(totalDelayed == dur){
        delayTick = dur - totalDelayed;
        totalDelayed = dur;
        
    }
    else{
        delayTick = (currentTime - previousTime);
        totalDelayed += delayTick;
    }
}

double ActionDelay::getDelayTick(){
    return delayTick;
}

void ActionDelay::updateAction(){
    if(!alive)
        return;
    
    if(!running)
        running = true;
    
    //delay doesn't need any update for initial state of action
    
    if(duration == 0){
        instantUpdate();
    }
    else{
        intervalUpdate();
    }
}

void ActionDelay::revive(){
    //revive. original and previous will be updated
    this->delayTick = 0;
    this->totalDelayed = 0;
    
    this->alive = false;
    this->running = false;
    
    ActionObject::revive();
}