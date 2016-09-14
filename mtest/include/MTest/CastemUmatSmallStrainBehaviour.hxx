/*! 
 * \file  mtest/include/MTest/CastemUmatSmallStrainBehaviour.hxx
 * \brief
 * \author Helfer Thomas
 * \brief 07 avril 2013
 * \copyright Copyright (C) 2006-2014 CEA/DEN, EDF R&D. All rights 
 * reserved. 
 * This project is publicly released under either the GNU GPL Licence 
 * or the CECILL-A licence. A copy of thoses licences are delivered 
 * with the sources of TFEL. CEA or EDF may also distribute this 
 * project under specific licensing conditions. 
 */

#ifndef LIB_MTEST_CASTEMUMATSMALLSTRAINBEHAVIOUR_H_
#define LIB_MTEST_CASTEMUMATSMALLSTRAINBEHAVIOUR_H_ 

#include<memory>
#include"TFEL/Utilities/Data.hxx"
#include"TFEL/System/ExternalFunctionsPrototypes.hxx"
#include"MTest/CastemSmallStrainBehaviour.hxx"

namespace mtest
{

  /*!
   * A class to handle mechanical beheaviours written using the umat
   * interface
   */
  struct TFEL_VISIBILITY_LOCAL CastemUmatSmallStrainBehaviour
    : public CastemSmallStrainBehaviour
  {
    //! a simple alias
    using Parameters = tfel::utilities::Data;
    /*!
     * \param[in] l: library
     * \param[in] f: function
     * \param[in] parameters: parameters file
     * \param[in] h: modelling hypothesis
     */
    static std::shared_ptr<Behaviour>
    buildCastemUmatSmallStrainBehaviour(const std::string&,
					const std::string&,
					const Parameters&,
					const Hypothesis);
    /*!
     * \brief This method solves two issues:
     * 
     * - Some interface requires dummy material properties to be
     *   declared. For example, the Cast3M finite element solver
     *   requires the mass density and some extra material properties
     *   describing orthotropic axes to be declared.  This method is
     *   meant to automatically declare those if they are not defined
     *   by the user.
     * - Some interface (CastemUmatSmallStrain) uses an external files which gives
     *   the values of some material properties. This method is used
     *   to pass thoses values to MTest.
     *
     * \param[out] mp  : evolution manager 
     * \param[in]  evm : evolution manager
     */
    virtual void
    setOptionalMaterialPropertiesDefaultValues(EvolutionManager&,
					       const EvolutionManager&) const override;
    /*!
     * \return the string passed to the UMAT function through the
     * CMNAME parameter.
     */
    virtual const char*
    getBehaviourNameForUMATFunctionCall(void) const override;
    //! destructor
    virtual ~CastemUmatSmallStrainBehaviour();
  protected:
    /*!
     * \param[in] bd: umat behaviour description
     * \param[in] mp: behaviour parameters (defined through material
     *                properties)
     * \param[in] yg: Young modulus
     * \param[in] nu: Poisson ratio
     * \param[in] SENSIP1: 
     * \param[in] SENSIP2: 
     * \param[in] ICBASE: 
     * \param[in] h:  modelling hypothesis
     */
    CastemUmatSmallStrainBehaviour(const UmatBehaviourDescription&,
				   const std::vector<double>&,
				   const std::pair<double,double>&,
				   const std::pair<double,double>&,
				   const int,const int,const int,
				   const Hypothesis);
  }; // end of struct Behaviour
  
} // end of namespace mtest

#endif /* LIB_MTEST_CASTEMUMATSMALLSTRAINBEHAVIOUR_H_ */
