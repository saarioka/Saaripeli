#ifndef IGAMEBOARD_HH
#define IGAMEBOARD_HH

#include "cubecoordinate.hh"
#include "hex.hh"

#include <memory>

/**
 * @file
 * @brief Defines the interface for game board.
 */

namespace Common {

/**
 * @brief Interface for game board.
 */
class IGameBoard : public std::enable_shared_from_this<Common::IGameBoard> {

  public:

    /**
     * @brief Default constructor, exists solely for documentation.
     */
    IGameBoard() = default;

    /**
     * @brief Virtual destructor. Does nothing, since this is an interface class.
     */
    virtual ~IGameBoard() = default;


    /**
     * @brief checkTileOccupation Checks the current amount of pawns on the tile
     * @param tileCoord The location of the tile in coordinates.
     * @return The number of the pawns in the tile or -1 if the tile does not exist.
     * @post Exception quarantee: strong
     */
    virtual int checkTileOccupation(Common::CubeCoordinate tileCoord) const = 0;

    /**
     * @brief isWaterTile checks if the tile is a water tile.
     * @param tileCoord The location of the tile in coordinates.
     * @return true, if the tile is a water tile, else (or if the tile does not exist) false.
     * @post Exception quarantee: nothrow
     */
    virtual bool isWaterTile(Common::CubeCoordinate tileCoord) const = 0;


    /**
     * @brief getHex returns the hex gameboard tile
     * @param hexCoord The location of the hex in coordinates.
     * @return Shared pointer to the hex or nullptr, if the hex not exists.
     * @post Exception quarantee: nothrow
     */
    virtual std::shared_ptr<Common::Hex> getHex(Common::CubeCoordinate hexCoord) const = 0;

    /**
     * @brief addPawn adds a new pawn to the game
     * @param playerId. Id of player, whose pawn is added
     * @param pawnId. Id of the pawn
     * @post Pawn is added to the game. Exception quarantee: basic
     */
    virtual void addPawn(int playerId, int pawnId) = 0;

    /**
     * @brief movePawn sets a new location for the pawn.
     * @param pawnId The identifier of the pawn.
     * @param pawnCoord The target location of the pawn in coordinates.
     * @pre Pawn exists
     * @post Pawn is moved to the target location. Exception quarantee: basic
     */
    virtual void movePawn(int pawnId, Common::CubeCoordinate pawnCoord) = 0;

    /**
     * @brief removePawn removes a pawn.
     * @param pawnId The identifier of the pawn.
     * @pre Pawn exists
     * @post pawn matching the id is removed. Exception quarantee: basic
     */
    virtual void removePawn(int pawnId) = 0;

    /**
     * @brief moveActor sets a new location for the actor.
     * @param actorId The identifier of the actor.
     * @param actorCoord The target location of the actor in coordinates.
     * @pre Actor exists
     * @post actor actorId is moved to a new location: Exception quarantee: basic
     */
    virtual void moveActor(int actorId, Common::CubeCoordinate actorCoord) = 0;

    /**
     * @brief removeActor removes an actor.
     * @param actorId The identifier of the actor.
     * @pre Actor exists
     * @post Actor actorId is removed. Exception quarantee: basic
     */
    virtual void removeActor(int actorId) = 0;

    /**
     * @brief addHex adds a new hex tile to the board
     * @param newHex Pointer of a new hex to add
     * @pre newHex is valid
     * @post newHex is added to the board. Any existing hex at the same
     * coordinates is replaced. Exception quarantee: basic
     */
    virtual void addHex(std::shared_ptr<Common::Hex> newHex) = 0;

};

}

#endif
