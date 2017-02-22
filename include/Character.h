//
// Created by marcin on 15.01.17.
//

#pragma once

#include "../include/shared.h"

class Character : public sf::Drawable {
public:
    /////////////////////////////////////////////////////////////////////////////
    // Default constructor
    Character(const sf::Texture& texture, float x, float y, float speed);

    /////////////////////////////////////////////////////////////////////////////
    // Movement interface
    enum Dir {
        right, left, up, down
    };

    /////////////////////////////////////////////////////////////////////////////
    // sf::Drawable interface implementation
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    /////////////////////////////////////////////////////////////////////////////
    // set Character's pos
    void setPosition(float x, float y);

    /////////////////////////////////////////////////////////////////////////////
    // get current Character's pos
    sf::Vector2f getPosition();

    /////////////////////////////////////////////////////////////////////////////
    // set moving direction and isMoving to true/false
    void setMoveFlag(Dir dir, bool value);

    /////////////////////////////////////////////////////////////////////////////
    // get current move direction flag
    bool getMoveFlag(Dir dir);

    /////////////////////////////////////////////////////////////////////////////
    // get access to character's sprite commands
    sf::Sprite getSprite();

    /////////////////////////////////////////////////////////////////////////////
    // return globals bounds of character's sprite
    sf::FloatRect getBounds();

    /////////////////////////////////////////////////////////////////////////////
    // update position on the screen
    void updatePos(float& delta);
protected:
    /////////////////////////////////////////////////////////////////////////////
    // check bounds of the screen
    bool canMove(Dir dir);

    /////////////////////////////////////////////////////////////////////////////
    // confirm current move after setting movement flag
    void confirmMove();

private:
    sf::Sprite sprite;
    bool isMovingLeft = false;
    bool isMovingRight = false;
    bool isMovingUp = false;
    bool isMovingDown = false;
    float speed;

    float matchSpeed();
};
