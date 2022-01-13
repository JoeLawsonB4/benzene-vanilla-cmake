//----------------------------------------------------------------------------
/** @file JoeHexProgram.cpp */
//----------------------------------------------------------------------------

#include "JoeHexProgram.hpp"

#include <boost/program_options/cmdline.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/program_options/parsers.hpp>

namespace po = boost::program_options;

using namespace benzene;

//----------------------------------------------------------------------------

JoeHexProgram::JoeHexProgram(std::string version,
                           std::string buildDate)
{
    SetInfo("JoeHex", version, buildDate);
    RegisterCmdLineArguments();
}

JoeHexProgram::~JoeHexProgram()
{
}

//----------------------------------------------------------------------------

void JoeHexProgram::RegisterCmdLineArguments()
{
    CommonProgram::RegisterCmdLineArguments();
}

void JoeHexProgram::HandleCmdLineArguments()
{
    CommonProgram::HandleCmdLineArguments();
}

void JoeHexProgram::InitializeSystem()
{
    LogConfig() << "JoeHexProgram:: InitializeSystem()\n";
    CommonProgram::InitializeSystem();
}

void JoeHexProgram::ShutdownSystem()
{ 
    LogConfig() << "JoeHexProgram:: ShutdownSystem()\n";
    CommonProgram::ShutdownSystem();
}

//----------------------------------------------------------------------------
