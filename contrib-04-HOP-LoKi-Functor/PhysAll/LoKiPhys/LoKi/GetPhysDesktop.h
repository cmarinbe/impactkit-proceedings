// $Id: GetPhysDesktop.h 95471 2010-11-01 22:39:01Z ibelyaev $
// ============================================================================
#ifndef LOKI_GETPHYSDESKTOP_H 
#define LOKI_GETPHYSDESKTOP_H 1
// ============================================================================
// Include files
// ============================================================================
// forward declarations
// ============================================================================
class IDVAlgorithm    ;
class IAlgContextSvc ;
namespace LoKi { class ILoKiSvc ; }
// ============================================================================
namespace LoKi
{
  // ==========================================================================
  /** get the desktop from Algorithm Context Service 
   *  @param  svc pointer to Algorithm Context Service  
   *  @return the pointer to desktop
   *  @author Vanya BELYAEV Ivan.Belyaev@itep.ru
   *  date 2008-01-16
   */
  GAUDI_API 
  IDVAlgorithm* getPhysDesktop ( const IAlgContextSvc* svc ) ;
  // ==========================================================================
  /** get the desktop from LoKi Service 
   *  @param  pointer to LoKi Service   
   *  @return the pointer to desktop
   *  @author Vanya BELYAEV Ivan.Belyaev@itep.ru
   *  date 2008-01-16
   */
  GAUDI_API 
  IDVAlgorithm* getPhysDesktop ( const LoKi::ILoKiSvc* svc  ) ;
  // ==========================================================================
  /** get the desktop using the chain LoKi -> Algorithm Context -> DVAlgorithm
   *  @return the pointer to desktop
   *  @author Vanya BELYAEV Ivan.Belyaev@itep.ru
   *  date 2008-01-16
   */
  GAUDI_API 
  IDVAlgorithm* getPhysDesktop () ;
  // ==========================================================================
} //                                                      end of namespace LoKi
// ============================================================================
// The END 
// ============================================================================
#endif // LOKI_GETPHYSDESKTOP_H
// ============================================================================
