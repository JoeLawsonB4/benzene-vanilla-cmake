//----------------------------------------------------------------------------
/** @file JoeHexMain.cpp */
//----------------------------------------------------------------------------

#include "SgSystem.h"

#include "config.h"
#include "Misc.hpp"
#include "JoeHexEngine.hpp"
#include "JoeHexPlayer.hpp"
#include "JoeHexProgram.hpp"

using namespace benzene;

//----------------------------------------------------------------------------

/** @page JoeHexmainpage JoeHex

    @section overview Overview

    JoeHex is Hex player that uses monte-carlo tree search with
    knowledge computation. It links with the UCT search classes from
    the Fuego library.
    
    JoeHex uses HexBoard to compute VCs/fillin for nodes in the search
    tree that have been visited more than a certain threshold number
    of times.

    @section classes Classes
    - JoeHexEngine
    - JoeHexPlayer
    - JoeHexSearch

    @section htpcommands HTP Commands
    - @ref hexhtpenginecommands
    - @ref benzenehtpenginecommands

    @todo Add more documentation about JoeHex!
*/

//----------------------------------------------------------------------------

namespace {

const char* build_date = __DATE__;

}

//----------------------------------------------------------------------------

int main(int argc, char** argv)
{
    MiscUtil::FindProgramDir(argc, argv);
    JoeHexProgram program(VERSION, build_date);
    BenzeneEnvironment::Get().RegisterProgram(program);
    program.Initialize(argc, argv);
    JoeHexPlayer player;
    try
    {
        JoeHexEngine gh(program.BoardSize(), player);
            std::string config = program.ConfigFileToExecute();
        if (config != "")
            gh.ExecuteFile(config);
        GtpInputStream gin(std::cin);
        GtpOutputStream gout(std::cout);
        gh.MainLoop(gin, gout);
        program.Shutdown();
    }
    catch (const GtpFailure& f)
    {
        std::cerr << f.Response() << std::endl;
        return 1;
    }
    return 0;
}

//----------------------------------------------------------------------------
