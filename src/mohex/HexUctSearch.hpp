//----------------------------------------------------------------------------
/** @file HexUctSearch.hpp */
//----------------------------------------------------------------------------

#ifndef HEXUCTSEARCH_H
#define HEXUCTSEARCH_H

#include "SgBlackWhite.h"
#include "SgPoint.h"
#include "SgNode.h"
#include "SgUctSearch.h"

#include "HexUctState.hpp"
#include "PatternState.hpp"

_BEGIN_BENZENE_NAMESPACE_

//----------------------------------------------------------------------------

class HexUctSharedPolicy;

/** Creates threads. */
class HexThreadStateFactory : public SgUctThreadStateFactory
{
public:
    HexThreadStateFactory(HexUctSharedPolicy* shared_policy);

    ~HexThreadStateFactory();

    SgUctThreadState* Create(unsigned int threadId, const SgUctSearch& search);
private:

    HexUctSharedPolicy* m_shared_policy;
};

//----------------------------------------------------------------------------

/** Monte-Carlo search using UCT for Hex. */
class HexUctSearch : public SgUctSearch
{
public:
    /** Constructor.
        @param factory Creates HexUctState instances for each thread.
        @param maxMoves Maximum move number.
    */
    HexUctSearch(SgUctThreadStateFactory* factory,
                 int maxMoves = 0);
    
    ~HexUctSearch();    

    //-----------------------------------------------------------------------
    
    /** @name Pure virtual functions of SgUctSearch */
    // @{

    std::string MoveString(SgMove move) const;

    SgUctValue UnknownEval() const;

    SgUctValue InverseEval(SgUctValue eval) const;

    // @}

    //-----------------------------------------------------------------------

    /** @name Virtual functions of SgUctSearch */
    // @{

    void OnSearchIteration(SgUctValue gameNumber, const unsigned int threadId,
                           const SgUctGameInfo& info);

    void OnStartSearch();

    // @}

    //-----------------------------------------------------------------------

    /** @name Hex-specific functions */
    // @{

    void SetBoard(HexBoard& board);

    HexBoard& Board();

    const HexBoard& Board() const;

    void SetSharedData(HexUctSharedData& data);

    HexUctSharedData& SharedData();

    const HexUctSharedData& SharedData() const;

    /** @see SetKeepGames()
        @throws SgException if KeepGames() was false at last invocation of
        StartSearch() */
    void SaveGames(const std::string& fileName) const;

    void AppendGame(const std::vector<SgMove>& sequence);

    /** @see HexUctUtil::SaveTree() */
    void SaveTree(std::ostream& out, int maxDepth) const;

    // @}

    //-----------------------------------------------------------------------

    /** @name Hex-specific parameters */
    // @{

    /** Keeps a SGF tree of all games.
        Games are cleared in each OnStartSearch(). Games can be saved
        with SaveGames(). */
    void SetKeepGames(bool enable);

    /** See SetKeepGames(). */
    bool KeepGames() const;

    /** Enables output of live graphics commands for HexGui.
        See GoGuiGfx() and SetLiveGfxInterval() */
    void SetLiveGfx(bool enable);

    /** See SetLiveGfx(). */
    bool LiveGfx() const;

    /** Sets interval for outputting of live graphics commands for HexGui.
        See SetLiveGfx(). */
    void SetLiveGfxInterval(int interval);

    /** See SetLiveGfxInterval(). */
    int LiveGfxInterval() const;

    /** Pattern-check radius to use during in-tree phase. */
    int TreeUpdateRadius() const;

    /** See TreeUpdateRadius(). */
    void SetTreeUpdateRadius(int radius);
    
    /** Pattern-check radius to use during playout phase. */
    int PlayoutUpdateRadius() const;
    
    /** See PlayoutUpdateRadius(). */
    void SetPlayoutUpdateRadius(int radius);

    // @} 

private:
    /** See SetKeepGames() */
    bool m_keepGames;

    /** See SetLiveGfx() */
    bool m_liveGfx;

    /** See SetLiveGfxInterval() */
    int m_liveGfxInterval;

    /** See TreeUpdateRadius() */
    int m_treeUpdateRadius;

    /** See PlayoutUpdateRadius() */
    int m_playoutUpdateRadius;

    /** Nothing is done to this board. 
        We do not own this pointer. Threads will create their own
        HexBoards, but the settings (ICE and VCs) will be copied from
        this board. */
    HexBoard* m_brd;
   
    /** Data among threads. */
    HexUctSharedData m_shared_data;

    StoneBoard m_lastPositionSearched;

    /** See SetKeepGames().
        Should be non-null only if KeepGames() is true. */
    SgNode* m_root;

    SgUctValue m_nextLiveGfx;

    /** Not implemented */
    HexUctSearch(const HexUctSearch& search);

    /** Not implemented */
    HexUctSearch& operator=(const HexUctSearch& search);
};

inline void HexUctSearch::SetBoard(HexBoard& board)
{
    m_brd = &board;
}

inline HexBoard& HexUctSearch::Board()
{
    return *m_brd;
}

inline const HexBoard& HexUctSearch::Board() const
{
    return *m_brd;
}

inline bool HexUctSearch::KeepGames() const
{
    return m_keepGames;
}

inline bool HexUctSearch::LiveGfx() const
{
    return m_liveGfx;
}

inline int HexUctSearch::LiveGfxInterval() const
{
    return m_liveGfxInterval;
}

inline void HexUctSearch::SetKeepGames(bool enable)
{
    m_keepGames = enable;
}

inline void HexUctSearch::SetLiveGfx(bool enable)
{
    m_liveGfx = enable;
}

inline void HexUctSearch::SetLiveGfxInterval(int interval)
{
    SG_ASSERT(interval > 0);
    m_liveGfxInterval = interval;
}

inline int HexUctSearch::TreeUpdateRadius() const
{
    return m_treeUpdateRadius;
}

inline void HexUctSearch::SetTreeUpdateRadius(int radius)
{
    m_treeUpdateRadius = radius;
}
    
inline int HexUctSearch::PlayoutUpdateRadius() const
{
    return m_playoutUpdateRadius;
}
    
inline void HexUctSearch::SetPlayoutUpdateRadius(int radius)
{
    m_playoutUpdateRadius = radius;
}

inline void HexUctSearch::SetSharedData(HexUctSharedData& data)
{
    m_shared_data = data;
}

inline HexUctSharedData& HexUctSearch::SharedData()
{
    return m_shared_data;
}

inline const HexUctSharedData& HexUctSearch::SharedData() const
{
    return m_shared_data;
}

//----------------------------------------------------------------------------

_END_BENZENE_NAMESPACE_

#endif // HEXUCTSEARCH_H
