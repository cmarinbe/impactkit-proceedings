// $Id: Particles18.cpp 182966 2015-01-20 14:57:52Z ibelyaev $
// ============================================================================
// Include files 
// ============================================================================
// LoKi
// ============================================================================
#include "LoKi/Particles18.h"
// ============================================================================
/** @file 
 *  Implementation file for class from file LoKi/Particles18.h
 *  @author Vanya BELYAEV ibelyaev@physics.syr.edu
 *  @date 2007-07-17 
 */
// ============================================================================
/*  constructor from "info"
 *  @param key info index/mark/key
 */
// ============================================================================
// constructor from the key 
// ============================================================================
LoKi::Particles::HasInfo:: HasInfo 
( const int key ) 
  : LoKi::AuxFunBase ( std::tie ( key ) ) 
  , LoKi::ExtraInfo::CheckInfo<const LHCb::Particle*> ( key ) 
{}
// ============================================================================
// copy constructor 
// ============================================================================
LoKi::Particles::HasInfo::HasInfo
( const LoKi::Particles::HasInfo& right ) 
  : LoKi::AuxFunBase                     ( right ) 
  , LoKi::ExtraInfo::CheckInfo<const LHCb::Particle*> ( right ) 
{}
// ============================================================================
// the specific printout 
// ============================================================================
std::ostream& LoKi::Particles::HasInfo::fillStream( std::ostream& s ) const 
{ return s << "HASINFO(" << index() << ")" ; }
// ============================================================================
/* constructor from "info"
 *  @param key info index/mark/key
 *  @param def default value for missing key/invalid object 
 */
LoKi::Particles::Info::Info
( const int    key , const double def )
  : LoKi::AuxFunBase ( std::tie ( key , def ) ) 
  , LoKi::ExtraInfo::GetInfo<const LHCb::Particle*> ( key , def ) 
{}
// ============================================================================
// copy constructor 
// ============================================================================
LoKi::Particles::Info::Info
( const LoKi::Particles::Info& right ) 
  : LoKi::AuxFunBase                        ( right ) 
  , LoKi::ExtraInfo::GetInfo<const LHCb::Particle*> ( right ) 
{}
// ============================================================================
// the specific printout 
// ============================================================================
std::ostream& LoKi::Particles::Info::fillStream( std::ostream& s ) const 
{ return s << "INFO(" << index() << "," << value() << ")" ; }
// ============================================================================


// ============================================================================
// The END
// ============================================================================
