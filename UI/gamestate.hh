#ifndef GAMESTATE_HH
#define GAMESTATE_HH

#include "igamestate.hh"
#include "vector"

namespace Student{

class GameState : public Common::IGameState
{
public:
    GameState();
    ~GameState();
    virtual Common::GamePhase currentGamePhase() const;
    virtual int currentPlayer() const;
    virtual void changeGamePhase(Common::GamePhase nextPhase);
    virtual void changePlayerTurn(int nextPlayer);
    int getPawnPerPlayer() const;
    void addPointsToPlayer(int player, int points);
    void deletePawn(int pawnId);
    int playerPawnsLeft(int playerId) const;

private:
    Common::GamePhase _gamePhaseId;
    int _playerInTurn;
    int _pawnPerPlayer;
    std::vector<std::pair<int, int>> _playerPointVector;
    std::vector<std::pair<int, int>> _playerPawnVector;

};

#endif // GAMESTATE_HH

}
