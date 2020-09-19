#ifndef GAMEBOARD_HH
#define GAMEBOARD_HH

#include <map>
#include <unordered_map>

#include "igameboard.hh"

namespace Student{

class GameBoard : public Common::IGameBoard
{
public:
    GameBoard();
    ~GameBoard();
    virtual int checkTileOccupation(Common::CubeCoordinate tileCoord) const;
    virtual bool isWaterTile(Common::CubeCoordinate tileCoord) const;
    virtual std::shared_ptr<Common::Hex>
        getHex(Common::CubeCoordinate hexCoord) const ;
    virtual void addPawn(int playerId, int amount);
    virtual void movePawn(int pawnId, Common::CubeCoordinate pawnCoord);
    virtual void removePawn(int pawnId);
    virtual void moveActor(int actorId, Common::CubeCoordinate actorCoord);
    virtual void removeActor(int actorId);
    virtual void addHex(std::shared_ptr<Common::Hex> newHex);
    void initializeBoard();
    void initializeGoalHexes();

private:
    //std::string getPieceType(Common::CubeCoordinate,
    //                         Common::CubeCoordinate) const;

    std::unordered_map<int, std::shared_ptr<Common::Pawn> >_pawnMap;
    std::map<Common::CubeCoordinate, std::shared_ptr<Common::Hex> > _hexMap;
    std::map< int, Common::CubeCoordinate> _actorMap;

};
#endif // GAMEBOARD_HH

}
