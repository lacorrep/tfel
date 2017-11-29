/*! 
 * \file  mfront/include/MFront/Cyrano/CyranoInterfaceExceptions.hxx
 * \brief
 * \author Helfer Thomas
 * \date   21 fév 2014
 * \copyright Copyright (C) 2006-2018 CEA/DEN, EDF R&D. All rights 
 * reserved. 
 * This project is publicly released under either the GNU GPL Licence 
 * or the CECILL-A licence. A copy of thoses licences are delivered 
 * with the sources of TFEL. CEA or EDF may also distribute this 
 * project under specific licensing conditions. 
 */

#ifndef LIB_MFRONT_CYRANO_CYRANOINTERFACEEXCEPTIONS_H_
#define LIB_MFRONT_CYRANO_CYRANOINTERFACEEXCEPTIONS_H_ 

#include<string>

#include"TFEL/Exception/TFELException.hxx"
#include"TFEL/Material/MaterialException.hxx"

#include"MFront/Cyrano/Cyrano.hxx"
#include"MFront/Cyrano/CyranoTraits.hxx"
#include"MFront/Cyrano/CyranoConfig.hxx"
#include"MFront/Cyrano/CyranoException.hxx"

namespace cyrano{

  /*!
   * This structure is called when we fall in a case that the cyrano
   * interface is not able to handle. Normally, this case shall have
   * been handled during the code generation (see the
   * CyranoInterface class).
   */
  struct MFRONT_CYRANO_VISIBILITY_EXPORT CyranoUnSupportedCaseHandler
  {
    /*!
     * \brief throw an exception
     */
    TFEL_NORETURN static void
    exe(const CyranoReal *const ,
	const CyranoReal *const,
	const CyranoReal *const,
	const CyranoReal *const,
	const CyranoReal *const,
	const CyranoReal *const,
	const CyranoReal *const,
	const CyranoReal *const,
	const CyranoInt  *const,
	const CyranoReal *const,
	const CyranoReal *const,
	CyranoReal *const,
	const CyranoInt  *const,
	CyranoReal *const); // end of exe
  }; // end of struct CyranoUnSupportedCaseHandler

  /*!
   * \class  CyranoInterfaceExceptions
   * \brief  Base class for cyrano interfaces
   * \author Helfer Thomas
   * \date   12/12/2011
   */
  struct MFRONT_CYRANO_VISIBILITY_EXPORT CyranoInterfaceExceptions
  {
    /*!
     * \brief throw an CyranoException. This method shall be called when
     * the number of materials properties declared by the beahviour and the
     * number of  materials properties declared by the interface does not
     * match.
     * \param[in] b  : behaviour name
     * \param[in] n1 : number of material properties declared by the behaviour
     * \param[in] n2 : number of material properties declared by the interface
     */
    TFEL_NORETURN static void
    throwUnMatchedNumberOfMaterialProperties(const std::string&,
					     const unsigned short n1,
					     const CyranoInt n2);
    
    /*!
     * \brief throw an CyranoException. This method shall be called when
     * the number of state variables declared by the beahviour and the
     * number of state variables declared by the interface does not
     * match.
     * \param[in] b  : behaviour name
     * \param[in] n1 : number of state variables declared by the behaviour
     * \param[in] n2 : number of state variables declared by the interface
     */
    TFEL_NORETURN static void
    throwUnMatchedNumberOfStateVariables(const std::string&,
					 const unsigned short n1,
					 const CyranoInt n2);

    /*!
     * \brief display the error message out of an CyranoException to the
     * standard output.
     * \param[in] b : behaviour name
     * \param[in] e : the CyranoException to be treated
     */
    static void
    treatCyranoException(const std::string&,
			 const CyranoException&);

    /*!
     * \brief display the error message out of a material exception to the
     * standard output.
     * \param[in] b : behaviour name
     * \param[in] e : the material exception to be treated
     */
    static void
    treatMaterialException(const std::string&,
			   const tfel::material::MaterialException&);
    
    /*!
     * \brief display the error message out of a generic tfel
     * exception to the standard output.
     * \param[in] b : behaviour name
     * \param[in] e : the exception to be treated
     */
    static void
    treatTFELException(const std::string&,
		       const tfel::exception::TFELException&);

    /*!
     * \brief display the error message out of a generic standard
     * exception to the standard output.
     * \param[in] b : behaviour name
     * \param[in] e : the exception to be treated
     */
    static void
    treatStandardException(const std::string&,
			   const std::exception&);

    /*!
     * \brief display the error message when an unknown exception is caught
     * \param[in] b : behaviour name
     */
    static void
    treatUnknownException(const std::string&);

    /*!
     * \brief throw an CyranoException if the time step is negative
     * \param[in] b : behaviour name
     */
    TFEL_NORETURN static void
    throwNegativeTimeStepException(const std::string&);

    /*!
     * \brief throw an CyranoException if the behaviour integration
     * failed
     * \param[in] b : behaviour name
     */
    TFEL_NORETURN static void
    throwBehaviourIntegrationFailedException(const std::string&);

    /*!
     * \brief throw an CyranoException if the maximum number of sub
     * stepping has been reached
     * \param[in] b : behaviour name
     */
    TFEL_NORETURN static void
    throwMaximumNumberOfSubSteppingReachedException(const std::string&);

    /*!
     * \brief throw an CyranoException if the maximum number of sub
     * stepping has been reached
     * \param[in] b : behaviour name
     */
    TFEL_NORETURN static void
    throwPlaneStressMaximumNumberOfIterationsReachedException(const std::string&);
    /*!
     * \brief throw an CyranoException if the DDSOE parameter is invalid
     * \param[in] b : behaviour name
     * \param[in] v : DDSOE value
     */
    TFEL_NORETURN static void
    throwInvalidDDSOEException(const std::string&,
			       const CyranoReal);
    /*!
     * \brief throw an CyranoException if the prediction computation
     * failed
     * \param[in] b : behaviour name
     */
    TFEL_NORETURN static void
    throwPredictionComputationFailedException(const std::string&);
    /*!
     * \brief throw an CyranoException if the a consistent tangent
     * operator has to been requested and that the behaviour does not
     * provide one.
     * \param[in] b : behaviour name
     */
    TFEL_NORETURN static void
    throwConsistentTangentOperatorIsNotAvalaible(const std::string&);
    /*!
     * \brief throw an CyranoException if the a prediction operator has
     * to been requested and that the behaviour does not provide one.
     * \param[in] b : behaviour name
     */
    TFEL_NORETURN static void
    throwPredictionOperatorIsNotAvalaible(const std::string&);
    /*!
     * \brief display an error message if the behaviour shall handle
     * stress free expansion and that the cyrano interface can't
     * \param[in] b : behaviour name
     */
    TFEL_NORETURN static void
    throwUnsupportedStressFreeExpansionException(const std::string&);
    /*!
     * \brief display an error message if the thermal expansion is not
     * null
     * \param[in] b : behaviour name
     */
    TFEL_NORETURN static void
    throwThermalExpansionCoefficientShallBeNull(const std::string&);
    /*!
     * \brief throw an error message if the value of the NTENS
     * parameter is not valid
     * \param[in] NTENS : NTENS value
     * \param[in] s     : expected size
     */
    static void
    checkNTENSValue(const CyranoInt,const unsigned short);
    /*!
     * \brief throw an error message if the behaviour type is not supported for the given hypothesis
     * \param[in] H    : hypothesis
     */
    TFEL_NORETURN static void
    throwInvalidBehaviourTypeAndModellingHypothesis(const std::string&);
    /*!
     * \brief display an error message if the value of the NDI
     * parameter is not valid
     */
    static void
    displayInvalidModellingHypothesisErrorMessage(void);

  }; // end of struct CyranoInterfaceExceptions
  
} // end of namespace cyrano

#endif /* LIB_MFRONT_CYRANO_CYRANOINTERFACEEXCEPTIONS_H_ */

