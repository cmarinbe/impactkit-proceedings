// $Id: PhysDump.h 134320 2012-01-29 17:47:53Z ibelyaev $
// =======================================================================
#ifndef LOKI_PHYSDUMP_H 
#define LOKI_PHYSDUMP_H 1
// ============================================================================
// Include files
// ============================================================================
// LoKi
// ============================================================================
#include "LoKi/Filters.h"
#include "LoKi/PhysTypes.h"
#include "LoKi/Dumper.h"
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
 *  By usage of this code one clearly states the disagreement 
 *  with the smear campaign of Dr.O.Callot et al.: 
 *  ``No Vanya's lines are allowed in LHCb/Gaudi software.''
 *
 *  @author Vanya Belyaev Ivan.Belyaev@cern.ch
 *  @date   2011-06-03
 * 
 *                    $Revision: 134320 $
 *  Last modification $Date: 2012-01-29 18:47:53 +0100 (Sun, 29 Jan 2012) $
 *                 by $Author: ibelyaev $
 */
// ============================================================================
namespace LoKi 
{
  // ==========================================================================  
  namespace Functors 
  {
    // ========================================================================
    /** template specialization of ``dumper''
     *  @see LoKi::Fuctors::Dump_
     *  @author Vanya Belyaev Ivan.Belyaev@cern.ch
     *  @date   2011-06-03
     */  
    template <>
    Dump_<const LHCb::Particle*>::result_type 
    Dump_<const LHCb::Particle*>::operator() 
      ( Dump_<const LHCb::Particle*>::argument a ) const ;
    // ========================================================================
    /** template specialization of ``dumper''
     *  @see LoKi::Fuctors::Dump1_
     *  @author Vanya Belyaev Ivan.Belyaev@itep.ru
     *  @date   2012-01-28
     */  
    template <>
    Dump1_<const LHCb::Particle*,bool>::result_type 
    Dump1_<const LHCb::Particle*,bool>::operator() 
      ( Dump1_<const LHCb::Particle*,bool>::argument a ) const ;
    // ========================================================================
    /** template specialization of ``dumper''
     *  @see LoKi::Fuctors::Dump1_
     *  @author Vanya Belyaev Ivan.Belyaev@itep.ru
     *  @date   2012-01-28
     */  
    template <>
    Dump1_<const LHCb::Particle*,double>::result_type 
    Dump1_<const LHCb::Particle*,double>::operator() 
      ( Dump1_<const LHCb::Particle*,double>::argument a ) const ;
    // ========================================================================
  } //                                          end of namespace LoKi::Functors 
  // ==========================================================================
} //                                                      end of namespace LoKi
// ============================================================================
//                                                                      The END 
// ============================================================================
#endif // LOKI_PHYSDUMP_H
// ============================================================================
