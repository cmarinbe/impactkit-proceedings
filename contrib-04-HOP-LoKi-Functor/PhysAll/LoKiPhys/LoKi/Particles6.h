// $Id: Particles6.h 95471 2010-11-01 22:39:01Z ibelyaev $
// ============================================================================
#ifndef LOKI_PARTICLES6_H 
#define LOKI_PARTICLES6_H 1
// ============================================================================
// Include files
// ============================================================================
// LoKiPhys 
// ============================================================================
#include "LoKi/PhysTypes.h"
#include "LoKi/Child.h"
#include "LoKi/ChildSelector.h"
// ============================================================================
/** @file
 *
 *  This file is a part of LoKi project - 
 *    "C++ ToolKit  for Smart and Friendly Physics Analysis"
 *
 *  The package has been designed with the kind help from
 *  Galina PAKHLOVA and Sergey BARSUK.  Many bright ideas, 
 *  contributions and advices from G.Raven, J.van Tilburg, 
 *  A.Golutvin, P.Koppenburg have been used in the design.
 *
 *  @author Vanya BELYAEV ibelyaev@physics.syr.edu
 *  @date 2006-02-21
 */
// ============================================================================
namespace LoKi
{
  // ==========================================================================
  namespace Particles 
  {
    // ========================================================================
    /** @class ChildFunction
     *  Simple adapter function which 
     *  apply the function to a daughter  particle
     * 
     *  @code
     *
     *  const LHCb::Particle* B = ... ;
     *
     *  // the transverse momentum of the first daughter particle:
     *  Fun fun = CHILD( PT , 1 ) ;
     *  const double pt1 = fun( B ) ;
     *
     *  @endcode 
     *
     *  @see LoKi::Cuts::CHILD 
     *  @see LoKi::Cuts::CHILDFUN
     *  @see LoKi::Child::child 
     *
     *  @author Vanya BELYAEV ibelyaev@physics.syr.edu
     *  @date 2006-02-21
     */
    class GAUDI_API ChildFunction
      : public LoKi::BasicFunctors<const LHCb::Particle*>::Function
    {
    public:
      // ======================================================================
      /** constructor from the function and daughter index 
       *  @param fun    the function to be used 
       *  @param index  the index of daughter particle
       */
      ChildFunction 
      ( const LoKi::PhysTypes::Func& fun   , 
        const unsigned int           index ) ;
      /** constructor from the function and daughter index 
       *  @param fun    the function to be used 
       *  @param index  the index of daughter particle
       */
      ChildFunction 
      ( const LoKi::PhysTypes::Func& fun    , 
        const unsigned int           index1 , 
        const unsigned int           index2 ) ;
      /** constructor from the function and daughter index 
       *  @param fun    the function to be used 
       *  @param index  the index of daughter particle
       */
      ChildFunction 
      ( const LoKi::PhysTypes::Func& fun    , 
        const unsigned int           index1 , 
        const unsigned int           index2 ,
        const unsigned int           index3 ) ;
      /** constructor from the function and daughter index 
       *  @param fun    the function to be used 
       *  @param index  the index of daughter particle
       */
      ChildFunction 
      ( const LoKi::PhysTypes::Func& fun    , 
        const unsigned int           index1 , 
        const unsigned int           index2 ,
        const unsigned int           index3 ,
        const unsigned int           index4 ) ;
      /** constructor from the function and daughter index 
       *  @param fun    the function to be used 
       *  @param index  the index of daughter particle
       */
      ChildFunction 
      ( const LoKi::PhysTypes::Func& fun         , 
        const std::vector<unsigned int>& indices ) ;
      /** constructor from the function and child selector 
       *  @param fun      the function to be used 
       *  @param selector the child selector 
       */
      ChildFunction 
      ( const LoKi::PhysTypes::Func& fun       , 
        const LoKi::Child::Selector& selector  ) ;
      /** constructor from the function and child selector 
       *  @param fun      the function to be used 
       *  @param selector the child selector
       */
      ChildFunction 
      ( const LoKi::PhysTypes::Func& fun       , 
        const std::string&           selector  ) ;
      /** constructor from the function and child selector 
       *  @param fun      the function to be used 
       *  @param selector the child selector
       */
      ChildFunction 
      ( const LoKi::PhysTypes::Func&  fun      , 
        const Decays::IDecay::iTree&  selector ) ;
      /** constructor from the function and child selector 
       *  @param fun      the function to be used 
       *  @param selector the child selector
       */
      ChildFunction 
      ( const LoKi::PhysTypes::Func&  fun      , 
        const Decays::iNode&          selector ) ;
      /** constructor from the function and child selector 
       *  @param fun      the function to be used 
       *  @param selector the child selector
       */
      ChildFunction 
      ( const LoKi::PhysTypes::Func& fun      , 
        const LoKi::PhysTypes::Cuts& selector ) ;
      // ======================================================================
      /** constructor from the function and daughter index 
       *  @param index  the index of daughter particle
       *  @param fun    the function to be used 
       */
      ChildFunction
      ( const unsigned int           index ,
        const LoKi::PhysTypes::Func& fun   ) ;
      /** constructor from the function and child selector 
       *  @param selector the child selector
       *  @param fun      the function to be used 
       */
      ChildFunction 
      ( const LoKi::Child::Selector& selector  , 
        const LoKi::PhysTypes::Func& fun       ) ;
      /** constructor from the function and child selector 
       *  @param selector the child selector
       *  @param fun      the function to be used 
       */
      ChildFunction 
      ( const Decays::IDecay::iTree& selector  , 
        const LoKi::PhysTypes::Func& fun       ) ;
      /** constructor from the function and child selector 
       *  @param selector the child selector
       *  @param fun      the function to be used 
       */
      ChildFunction 
      ( const Decays::iNode&         selector  , 
        const LoKi::PhysTypes::Func& fun       ) ;
      /** constructor from the function and child selector 
       *  @param selector the child selector
       *  @param fun      the function to be used 
       */
      ChildFunction 
      ( const std::string&           selector  , 
        const LoKi::PhysTypes::Func& fun       ) ;
      // ======================================================================
      /// MANDATORY: virtual destructor
      virtual ~ChildFunction(){};
      /// MANDATORY: clone method ("virtual constructor")
      virtual  ChildFunction*  clone() const 
      { return new ChildFunction(*this); }
      /// MANDATORY: the only one essential method 
      virtual result_type operator() ( argument p ) const ;
      /// OPTIONAL:  specific printout 
      virtual std::ostream& fillStream( std::ostream& s ) const ;
      // ======================================================================
    private:
      // ======================================================================
      /// the function itself 
      LoKi::PhysTypes::Fun  m_fun   ;                    // the function itself 
      /// the child selector 
      LoKi::Child::Selector m_child ;                     // the child selector 
      // ======================================================================
    };
    // ========================================================================    
    /** @class ChildPredicate
     *  Simple adapter predicate  which 
     *  apply the predicate to a daughter  particle
     * 
     *  @code
     *
     *  const LHCb::Particle* B = ... ;
     *
     *  // ask if the first daughter is pi+
     *  Cut cut = CHILDCUT( "pi+" == ID  , 1 ) ;
     *  const bool pion = cut ( B ) ;
     *
     *  @endcode 
     *
     *  @see LoKi::Cuts::CHILDCUT
     *  @see LoKi::Child::child 
     *
     *  @author Vanya BELYAEV ibelyaev@physics.syr.edu
     *  @date 2006-02-21
     */
    class GAUDI_API ChildPredicate 
      : public LoKi::BasicFunctors<const LHCb::Particle*>::Predicate
    {
    public:
      // ======================================================================
      /** constructor from the function and daughter index 
       *  @param cut    the function to be used 
       *  @param index  the index of daughter particle
       */
      ChildPredicate 
      ( const LoKi::PhysTypes::Cuts& cut   , 
        const unsigned int           index ) ;
      /** constructor from the function and daughter index 
       *  @param cut    the function to be used 
       *  @param index  the index of daughter particle
       */
      ChildPredicate 
      ( const LoKi::PhysTypes::Cuts& cut    , 
        const unsigned int           index1 ,
        const unsigned int           index2 ) ;
      /** constructor from the function and daughter index 
       *  @param cut    the function to be used 
       *  @param index  the index of daughter particle
       */
      ChildPredicate 
      ( const LoKi::PhysTypes::Cuts& cut    , 
        const unsigned int           index1 ,
        const unsigned int           index2 ,
        const unsigned int           index3 ) ;
      /** constructor from the function and daughter index 
       *  @param cut    the function to be used 
       *  @param index  the index of daughter particle
       */
      ChildPredicate 
      ( const LoKi::PhysTypes::Cuts& cut    , 
        const unsigned int           index1 ,
        const unsigned int           index2 ,
        const unsigned int           index3 ,
        const unsigned int           index4 ) ;
      /** constructor from the function and daughter index 
       *  @param cut     the function to be used 
       *  @param indices the index of daughter particle
       */
      ChildPredicate 
      ( const LoKi::PhysTypes::Cuts&     cut     , 
        const std::vector<unsigned int>& indices ) ;
      /** constructor from the function and child selector 
       *  @param cut      the function to be used 
       *  @param selector the child selector 
       */
      ChildPredicate 
      ( const LoKi::PhysTypes::Cuts& cut      , 
        const LoKi::Child::Selector& selector ) ;
      /** constructor from the function and child selector 
       *  @param cut      the function to be used 
       *  @param selector the child selector 
       */
      ChildPredicate 
      ( const LoKi::PhysTypes::Cuts& cut      , 
        const Decays::IDecay::iTree& selector ) ;
      /** constructor from the function and child selector 
       *  @param cut      the function to be used 
       *  @param selector the child selector 
       */
      ChildPredicate 
      ( const LoKi::PhysTypes::Cuts& cut      , 
        const Decays::iNode&         selector ) ;
      /** constructor from the function and child selector 
       *  @param cut      the function to be used 
       *  @param selector the child selector 
       */
      ChildPredicate 
      ( const LoKi::PhysTypes::Cuts& cut      , 
        const std::string&           selector ) ;
      // ======================================================================
      /** constructor from the function and daughter index 
       *  @param index  the index of daughter particle
       *  @param cut    the function to be used 
       */
      ChildPredicate
      ( const unsigned int           index ,
        const LoKi::PhysTypes::Cuts& cut   ) ;
      /** constructor from the function and child selector 
       *  @param cut      the function to be used 
       *  @param selector the child selector 
       */
      ChildPredicate 
      ( const LoKi::Child::Selector& selector , 
        const LoKi::PhysTypes::Cuts& cut      ) ;
      /** constructor from the function and child selector 
       *  @param cut      the function to be used 
       *  @param selector the child selector 
       */
      ChildPredicate 
      ( const Decays::IDecay::iTree& selector , 
        const LoKi::PhysTypes::Cuts& cut      ) ;
      /** constructor from the function and child selector 
       *  @param cut      the function to be used 
       *  @param selector the child selector 
       */
      ChildPredicate 
      ( const Decays::iNode&         selector , 
        const LoKi::PhysTypes::Cuts& cut      ) ;
      /** constructor from the function and child selector 
       *  @param cut      the function to be used 
       *  @param selector the child selector 
       */
      ChildPredicate 
      ( const std::string&           selector , 
        const LoKi::PhysTypes::Cuts& cut      ) ;
      // ======================================================================
      /// MANDATORY: virtual destructor
      virtual ~ChildPredicate(){};
      /// MANDATORY: clone method ("virtual constructor")
      virtual  ChildPredicate*  clone() const 
      { return new ChildPredicate(*this); }
      /// MANDATORY: the only one essential method 
      virtual result_type operator() ( argument p ) const ;
      /// OPTIONAL:  specific printout 
      virtual std::ostream& fillStream( std::ostream& s ) const ;
      // ======================================================================
    private:
      // ======================================================================
      /// the function itself 
      LoKi::PhysTypes::Cut m_cut ;                       // the function itself 
      /// the child selector 
      LoKi::Child::Selector m_child ;                     // the child selector 
      // ======================================================================
    };
    // ========================================================================
  } //                                         end of namespace LoKi::Particles
  // ==========================================================================
} //                                                      end of namespace LoKi
// ============================================================================
// The END 
// ============================================================================
#endif // LOKI_PARTICLES6_H
// ============================================================================
