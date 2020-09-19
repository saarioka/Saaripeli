#include "gameboard.hh"
#include "pawn.hh"
#include "actor.hh"

namespace Student{

GameBoard::GameBoard()
{

}

GameBoard::~GameBoard()
{

}

int GameBoard::checkTileOccupation(Common::CubeCoordinate tileCoord) const
{
    return getHex(tileCoord)->getPawns();
}

bool GameBoard::isWaterTile(Common::CubeCoordinate tileCoord) const
{
    return getHex(tileCoord)->isWaterTile();
}

std::shared_ptr<Common::Hex> GameBoard::getHex(Common::CubeCoordinate hexCoord) const
{
    return _hexMap.at(hexCoord);
}

void GameBoard::addPawn(int playerId, int amount)
{
    for(int i=0; i<amount; i++){
        std::shared_ptr<Common::Pawn> newPawn;
        _pawnMap.insert({playerId, newPawn});
    }
}

void GameBoard::movePawn(int pawnId, Common::CubeCoordinate pawnCoord)
{
    _pawnMap.at(pawnId)->setCoordinates(pawnCoord);
}

void GameBoard::removePawn(int pawnId)
{
    _pawnMap.erase(pawnId);
}

void GameBoard::moveActor(int actorId, Common::CubeCoordinate actorCoord)
{
    // actor-luokka ei ole valmis...
    (void)actorId;
    (void)actorCoord;
}

void GameBoard::removeActor(int actorId)
{
    // actor-luokka ei ole valmis...
    (void)actorId;
}

void GameBoard::addHex(std::shared_ptr<Common::Hex> newHex)
{
    _hexMap.insert({newHex->getCoordinates(), newHex});
}

void GameBoard::initializeBoard()
{
    for(int x=0; x<2; x++){
        for(int y=0; y<2; y++){
            for(int z=0; z<2; z++){
                std::shared_ptr<Common::Hex> newHex = std::make_shared<Common::Hex>();
                newHex->setCoordinates(Common::CubeCoordinate(x,y,z));
                this->addHex(newHex);
            }
        }
    }
}

void GameBoard::initializeGoalHexes()
{
}

}
