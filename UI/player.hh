#ifndef PLAYER_HH
#define PLAYER_HH

#include "iplayer.hh"

namespace Student{

class Player : public Common::IPlayer
{
public:
    Player(int id);
    ~Player();
    virtual int getPlayerId() const;
    virtual void setActionsLeft(unsigned int actionsLeft);
    virtual unsigned int getActionsLeft() const;

private:
    int _playerId;
    int _actionsLeft;
    int _pawnLeft;
    int _totalPawnCount;

};

#endif // PLAYER_HH

}
