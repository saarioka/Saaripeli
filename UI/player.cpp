#include "player.hh"

namespace Student{

Player::Player(int id):_playerId(id)
{

}

Player::~Player()
{

}

int Player::getPlayerId() const
{
    return _playerId;
}

void Player::setActionsLeft(unsigned int actionsLeft)
{
}

unsigned int Player::getActionsLeft() const
{
    return _actionsLeft;
}

}
