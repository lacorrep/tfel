/*! 
 * \file  mfront/include/MFront/Aster/AsterIsotropicBehaviourHandler.hxx
 * \brief
 * \author Helfer Thomas
 * \brief 30 janv. 2013
 * \copyright Copyright (C) 2006-2018 CEA/DEN, EDF R&D. All rights 
 * reserved. 
 * This project is publicly released under either the GNU GPL Licence 
 * or the CECILL-A licence. A copy of thoses licences are delivered 
 * with the sources of TFEL. CEA or EDF may also distribute this 
 * project under specific licensing conditions. 
 */

#ifndef LIB_MFRONT_ASTER_ASTERISOTROPICBEHAVIOURHANDLER_H_
#define LIB_MFRONT_ASTER_ASTERISOTROPICBEHAVIOURHANDLER_H_ 

#ifndef LIB_MFRONT_ASTER_ASTERBEHAVIOURHANDLER_H_
#error "This header shall not be called directly"
#endif /* LIB_MFRONT_ASTER_ASTERBEHAVIOURHANDLER_H_ */

namespace aster
{

  template<AsterBehaviourType btype,
	   tfel::material::ModellingHypothesis::Hypothesis H,
	   template<tfel::material::ModellingHypothesis::Hypothesis,typename,bool> class Behaviour>
  struct TFEL_VISIBILITY_LOCAL AsterIsotropicBehaviourHandler
    : public AsterBehaviourHandler<H,Behaviour>
  {
    TFEL_ASTER_INLINE static
      void exe(const AsterReal *const DTIME ,
	       const AsterReal *const,
	       AsterReal *const DDSOE,
	       const AsterReal *const STRAN ,
	       const AsterReal *const DSTRAN,
	       const AsterReal *const TEMP  ,
	       const AsterReal *const DTEMP,
	       const AsterReal *const PROPS ,
	       const AsterInt  *const NPROPS,
	       const AsterReal *const PREDEF,
	       const AsterReal *const DPRED,
	       AsterReal *const STATEV,
	       const AsterInt  *const NSTATV,
	       AsterReal *const STRESS,
	       const tfel::material::OutOfBoundsPolicy op,
	       const StressFreeExpansionHandler& sfeh) 
    {
      using namespace tfel::meta;
      using namespace tfel::material;
      typedef Behaviour<H,AsterReal,false> BV;
      typedef MechanicalBehaviourTraits<BV> MTraits;
      typedef AsterTraits<BV> Traits;
      typedef AsterBehaviourHandler<H,Behaviour> AsterBehaviourHandler;
      const bool is_defined_ = MTraits::is_defined;
      const bool bs = Traits::requiresStiffnessTensor;
      const bool ba = Traits::requiresThermalExpansionCoefficientTensor;
      typedef typename std::conditional<
	is_defined_,
	typename AsterBehaviourHandler::template Integrator<bs,ba>,
	typename AsterBehaviourHandler::Error>::type Handler;
      AsterBehaviourHandler::checkNPROPS(*NPROPS);
      AsterBehaviourHandler::checkNSTATV(*NSTATV);
      Handler handler(DTIME,STRAN,DSTRAN,TEMP,DTEMP,PROPS,
		      PREDEF,DPRED,STATEV,STRESS,op,sfeh);
      handler.exe(DDSOE,STRESS,STATEV);
    } // end of AsterIsotropicBehaviourHandler::exe
    
  }; // end of struct AsterIsotropicBehaviourHandler
  
} // end of namespace aster

#endif /* LIB_MFRONT_ASTER_ASTERISOTROPICBEHAVIOURHANDLER_H_ */

