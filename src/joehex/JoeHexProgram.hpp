//----------------------------------------------------------------------------
/** @file JoeHexProgram.hpp */
//----------------------------------------------------------------------------

#ifndef JOEHEXPROGRAM_HPP
#define JOEHEXPROGRAM_HPP

#include "CommonProgram.hpp"

_BEGIN_BENZENE_NAMESPACE_

//----------------------------------------------------------------------------

/** Starts up a JoeHex-player program. */
class JoeHexProgram : public CommonProgram
{
public:
    JoeHexProgram(std::string version, std::string buildDate);

    virtual ~JoeHexProgram();

    //-----------------------------------------------------------------------

    virtual void RegisterCmdLineArguments();

    virtual void HandleCmdLineArguments();

    virtual void InitializeSystem();

    virtual void ShutdownSystem();

    //-----------------------------------------------------------------------

private:
};

//----------------------------------------------------------------------------

_END_BENZENE_NAMESPACE_

#endif // JOEHEXPROGRAM_HPP
