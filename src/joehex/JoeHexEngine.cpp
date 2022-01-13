//----------------------------------------------------------------------------
/** @file JoeHexEngine.cpp */
//----------------------------------------------------------------------------


#include "BoardUtil.hpp"
#include "JoeHexEngine.hpp"
#include "JoeHexPlayer.hpp"
#include "PlayAndSolve.hpp"

using namespace benzene;

//----------------------------------------------------------------------------

namespace {

//----------------------------------------------------------------------------

//----------------------------------------------------------------------------

} // namespace

//----------------------------------------------------------------------------

JoeHexEngine::JoeHexEngine(int boardsize, JoeHexPlayer& player)
    : CommonHtpEngine(boardsize),
      m_player(player),
      m_timeControlOverride(-1.0f)
{
}

JoeHexEngine::~JoeHexEngine()
{
}

//----------------------------------------------------------------------------

void JoeHexEngine::RegisterCmd(const std::string& name,
                              GtpCallback<JoeHexEngine>::Method method)
{
    Register(name, new GtpCallback<JoeHexEngine>(this, method));
}


HexPoint JoeHexEngine::GenMove(HexColor color, bool useGameClock)
{
//    if (SwapCheck::PlaySwap(m_game, color))
//        return SWAP_PIECES;
//    HexPoint bookMove = m_bookCheck.BestMove(HexState(m_game.Board(), color));
//    if (bookMove != INVALID_POINT)
//        return bookMove;
//    double maxTime = TimeForMove(color);
    return DoSearch(color, 0);
}

HexPoint JoeHexEngine::DoSearch(HexColor color, double maxTime)
{
    HexState state(m_game.Board(), color);
//    if (m_useParallelSolver)
//    {
//        PlayAndSolve ps(*m_pe.brd, *m_se.brd, m_player, m_dfpnSolver,
//                        m_dfpnPositions, m_game);
//        return ps.GenMove(state, maxTime);
//    }
//    else
//    {
        double score;
        return m_player.GenMove(state, m_game, m_pe.SyncBoard(m_game.Board()),
                               0, score);
//    }
}


//----------------------------------------------------------------------------

void JoeHexEngine::CmdAnalyzeCommands(HtpCommand& cmd)
{
    CommonHtpEngine::CmdAnalyzeCommands(cmd);
}


//----------------------------------------------------------------------------
// Pondering



//----------------------------------------------------------------------------

