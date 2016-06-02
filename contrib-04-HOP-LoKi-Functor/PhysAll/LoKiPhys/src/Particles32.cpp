// $Id: Particles32.cpp 183091 2015-01-22 13:43:28Z ibelyaev $
// ============================================================================
// Include files 
// ============================================================================
// LoKi
// ============================================================================
#include "LoKi/Constants.h"
#include "LoKi/Particles32.h"
// ============================================================================
/** @file
 *  Implementation file for classese from file  LoKi/Particles32.h
 * 
 *  @author Vanya Belyaev Ivan.Belyaev@itep.ru
 *  @date 20100219
 */
// ============================================================================
// constructor from vertex-function 
// ============================================================================
LoKi::Particles::BestPrimaryVertexAdaptor::BestPrimaryVertexAdaptor 
( const LoKi::PhysTypes::VFunc& vfun  )
  : LoKi::AuxFunBase ( std::tie ( vfun ) ) 
  , LoKi::AuxDesktopBase () 
  , LoKi::BasicFunctors<const LHCb::Particle*>::Function() 
  , m_vfun ( vfun  )
{}
// ============================================================================
// MANDATORY: virtual destructor 
// ============================================================================
LoKi::Particles::BestPrimaryVertexAdaptor::~BestPrimaryVertexAdaptor(){}
// ============================================================================
// MANDATORY: clone method ("virtual constructor")
// ============================================================================
LoKi::Particles::BestPrimaryVertexAdaptor*
LoKi::Particles::BestPrimaryVertexAdaptor::clone() const 
{ return  new BestPrimaryVertexAdaptor ( *this ) ; }
// ============================================================================
// MANDATORY: the only one essential method 
// ============================================================================
LoKi::Particles::BestPrimaryVertexAdaptor::result_type 
LoKi::Particles::BestPrimaryVertexAdaptor::operator() 
  ( LoKi::Particles::BestPrimaryVertexAdaptor::argument p ) const 
{
  if ( 0 == p ) 
  {
    Error ( "LHCb::Particle* point to NULL, return 'NegativeInfinity' ") ;
    return LoKi::Constants::NegativeInfinity ;
  }
  // get the best vertex from desktop
  const LHCb::VertexBase* vertex = bestVertex( p ) ;
  //
  return m_vfun ( vertex ) ;
}
// ============================================================================
// OPTIONAL: the nice string representation
// ============================================================================
std::ostream& 
LoKi::Particles::BestPrimaryVertexAdaptor::fillStream ( std::ostream& s ) const
{ return s << " BPV( " << m_vfun << " ) " ; }
// ============================================================================
  
  
// ============================================================================
// The END 
// ============================================================================
