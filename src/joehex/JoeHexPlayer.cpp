//----------------------------------------------------------------------------
/** @file JoeHexPlayer.cpp */
//----------------------------------------------------------------------------


#include "BoardUtil.hpp"
#include "JoeHexPlayer.hpp"

using namespace benzene;

//----------------------------------------------------------------------------

namespace {


}

//----------------------------------------------------------------------------

JoeHexPlayer::JoeHexPlayer()
    : HexPlayer()
{
}

JoeHexPlayer::~JoeHexPlayer()
{
}



//----------------------------------------------------------------------------

HexPoint JoeHexPlayer::Search(const HexState& state, const Game& game,
                             HexBoard& brd, const bitset_t& given_to_consider,
                             double maxTime, double& score)
{
    LogWarning() << "**** JoeHexSearch returned empty sequence!\n"
		 << "**** Returning random move!\n";
    return BoardUtil::RandomEmptyCell(brd.GetPosition());
}

HexPoint JoeHexPlayer::GenMove(const HexState& state, const Game& game,
                                HexBoard& brd, double maxTime,
                                double& score)
{
//    HexPoint move = INVALID_POINT;
//
//    move = InitSearch(brd, state.ToPlay(), score);
//    // Calls brd.ComputeAll(state.ToPlay())
//    if (move != INVALID_POINT)
//        return move;
//
    bitset_t consider;
//
//    move = CheckEndgame(brd, state.ToPlay(), consider, score);
//    // Have been removed from consider :
//    // - the cells not in the vc-mustplay ;
//    // - the cells inferior according to ComputeAll() ;
//    // - the cells losing by strategy stealing argument ;
//    // - the cells symetrical by rotation (if symetrical).
//    if (move != INVALID_POINT)
//        return move;

    LogInfo() << "Best move cannot be determined, must search state.\n";
    return Search(state, game, brd, consider, maxTime, score);
}




//----------------------------------------------------------------------------


//----------------------------------------------------------------------------
