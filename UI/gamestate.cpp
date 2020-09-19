#include "gamestate.hh"

namespace Student{

GameState::GameState()
{

}

GameState::~GameState()
{

}

Common::GamePhase GameState::currentGamePhase() const
{
    return _gamePhaseId;
}

int GameState::currentPlayer() const
{
    return _playerInTurn;
}

void GameState::changeGamePhase(Common::GamePhase nextPhase)
{
    _gamePhaseId = nextPhase;
}

void GameState::changePlayerTurn(int nextPlayer)
{
}

int GameState::getPawnPerPlayer() const
{
    return _pawnPerPlayer;
}

void GameState::addPointsToPlayer(int player, int points)
{

}

void GameState::deletePawn(int pawnId)
{

}

int GameState::playerPawnsLeft(int playerId) const
{
    return 0;
}

}
