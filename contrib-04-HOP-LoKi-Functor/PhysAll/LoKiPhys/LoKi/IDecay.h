// $Id: IDecay.h 95471 2010-11-01 22:39:01Z ibelyaev $
// ============================================================================
#ifndef LOKI_IDECAY_H 
#define LOKI_IDECAY_H 1
// ============================================================================
// Include files
// ============================================================================
// LoKi
// ============================================================================
#include "LoKi/iTree.h"
#include "LoKi/DecayFinder.h"
#include "LoKi/IDecayNode.h"
// ============================================================================
// forward declaration
// ============================================================================
namespace LHCb { class Particle ; }
// ============================================================================
namespace Decays 
{
  // ==========================================================================
  /** @class IDecay LoKi/IDecay.h
   *  New "Decay Finder"
   *  @author Ivan BELYAEV
   *  @date   2009-05-22
   */
  class GAUDI_API IDecay : public virtual IDecayNode
  {
    // ========================================================================
  public:
    // ========================================================================
    /// the actual type of the tree 
    typedef Decays::Tree_<const LHCb::Particle*>                         Tree ;
    /// the actual type of the tree 
    typedef Decays::iTree_<const LHCb::Particle*>                       iTree ;
    /// the actual type of finder 
    typedef Decays::Finder_<const LHCb::Particle*>                     Finder ;
    // ========================================================================
  public:
    // ========================================================================
    /** create the decay tree from the descriptor
     *  @param descriptor (INPUT)  the decay descriptor 
     *  @param tree       (OUTPUT) the decay tree 
     */
    virtual Tree tree ( const std::string& decay = "" ) const = 0 ;
    // ========================================================================
  public:
    // ========================================================================
    /// the unique interface ID 
    static const InterfaceID& interfaceID() ;        // the unique interface ID 
    // ========================================================================
  protected:
    // ========================================================================
    /// virtual & protected destructor 
    virtual ~IDecay () ;                      // virtual & protected destructor 
    // ========================================================================
  } ;
  // ==========================================================================
} // end of namespace Decays 
// ============================================================================
// The END 
// ============================================================================
#endif // LOKI_IDECAY_H
// ============================================================================
