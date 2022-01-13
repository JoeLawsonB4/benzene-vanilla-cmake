//----------------------------------------------------------------------------
/** @file JoeHexEngine.hpp */
//----------------------------------------------------------------------------

#ifndef JOEHEXENGINE_HPP
#define JOEHEXENGINE_HPP

#include "Hex.hpp"
#include "CommonHtpEngine.hpp"
#include "JoeHexPlayer.hpp"

_BEGIN_BENZENE_NAMESPACE_

//----------------------------------------------------------------------------

/** Htp engine for JoeHex. */
class JoeHexEngine : public CommonHtpEngine
{
public:

    JoeHexEngine(int boardsize, JoeHexPlayer& player);
    
    ~JoeHexEngine();

    /** @name Command Callbacks */
    // @{

    void CmdAnalyzeCommands(HtpCommand& cmd);
    // @} // @name


private:

    JoeHexPlayer& m_player;

    float m_timeControlOverride;

    HexPoint GenMove(HexColor color, bool useGameClock);

    HexPoint DoSearch(HexColor color, double maxTime);

    void RegisterCmd(const std::string& name,
                     GtpCallback<JoeHexEngine>::Method method);
};

//----------------------------------------------------------------------------

_END_BENZENE_NAMESPACE_

#endif // JOEHEXENGINE_HPP
