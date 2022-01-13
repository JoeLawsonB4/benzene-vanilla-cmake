//----------------------------------------------------------------------------
/** @file JoeHexPlayer.hpp */
//----------------------------------------------------------------------------

#ifndef JoeHexPLAYER_HPP
#define JoeHexPLAYER_HPP

#include "HexPlayer.hpp"

_BEGIN_BENZENE_NAMESPACE_

//----------------------------------------------------------------------------

/** Player using UCT to generate moves. */
class JoeHexPlayer : public HexPlayer
{
public:
    JoeHexPlayer();

    virtual ~JoeHexPlayer();

    /** Returns "JoeHex". */
    std::string Name() const;

   /** Generates a move from this board position. If the game is
        already over (somebody has won), returns RESIGN.

        Derived Benzene players that use different search algorithms
        should not extend this method, but the protected virtual
        method Search() below.

        If state is terminal (game over, vc/fill-in win/loss),
        returns "appropriate" move. Otherwise, calls Search().
    */
    HexPoint GenMove(const HexState& state, const Game& game,
                     HexBoard& brd, double maxTime, double& score);

protected:

    /** Generates a move in the given gamestate using uct. */
    HexPoint Search(const HexState& state, const Game& game,
                    HexBoard& brd, const bitset_t& consider,
                    double maxTime, double& score);
};

inline std::string JoeHexPlayer::Name() const
{
    return "JoeHex";
}


//----------------------------------------------------------------------------

_END_BENZENE_NAMESPACE_

#endif // JoeHexPLAYER_HPP
