/*!
 * \file
 * mfront/include/MFront/FiniteStrainBehaviourTangentOperatorConversion.hxx
 * \brief
 * \author Helfer Thomas
 * \brief 18 juin 2014
 * \copyright Copyright (C) 2006-2018 CEA/DEN, EDF R&D. All rights
 * reserved.
 * This project is publicly released under either the GNU GPL Licence
 * or the CECILL-A licence. A copy of thoses licences are delivered
 * with the sources of TFEL. CEA or EDF may also distribute this
 * project under specific licensing conditions.
 */

#ifndef LIB_MFRONT_FINITESTRAINBEHAVIOURTANGENTOPERATORCONVERSION_H_
#define LIB_MFRONT_FINITESTRAINBEHAVIOURTANGENTOPERATORCONVERSION_H_

#include <vector>
#include <string>
#include "TFEL/Material/FiniteStrainBehaviourTangentOperator.hxx"

namespace mfront {

  /*!
   * structure describing a conversion between two tangent operator
   */
  struct FiniteStrainBehaviourTangentOperatorConversion {
    //! a simple alias
    typedef tfel::material::FiniteStrainBehaviourTangentOperatorBase::Flag
        TangentOperatorFlag;
    //! \return : the list of all available conversions
    static std::vector<FiniteStrainBehaviourTangentOperatorConversion>
    getAvailableFiniteStrainBehaviourTangentOperatorConversions(void);
    /* copy and move constructors/assignement operators */
    FiniteStrainBehaviourTangentOperatorConversion(
        const FiniteStrainBehaviourTangentOperatorConversion&) = default;
    FiniteStrainBehaviourTangentOperatorConversion(
        FiniteStrainBehaviourTangentOperatorConversion&&) = default;
    FiniteStrainBehaviourTangentOperatorConversion& operator=(
        const FiniteStrainBehaviourTangentOperatorConversion&) = default;
    FiniteStrainBehaviourTangentOperatorConversion& operator=(
        FiniteStrainBehaviourTangentOperatorConversion&&) = default;
    //! \return the conversion starting point
    TangentOperatorFlag from(void) const;
    //! \return the conversion result point
    TangentOperatorFlag to(void) const;
    //! \return ther intermediate conversion code
    const std::string& getIntermediateConversion(void) const;
    //! \return ther intermediate conversion code
    const std::string& getFinalConversion(void) const;
    //! destrutor
    ~FiniteStrainBehaviourTangentOperatorConversion() noexcept;

   protected:
    /*!
     * \param[in] f  : conversion starting point
     * \param[in] t  : conversion result
     * \param[in] s  : intermediate conversion code
     * \param[in] s2 : final conversion code
     */
    FiniteStrainBehaviourTangentOperatorConversion(const TangentOperatorFlag,
                                                   const TangentOperatorFlag,
                                                   const std::string&,
                                                   const std::string&);
    //! starting point
    TangentOperatorFlag b;
    //! result
    TangentOperatorFlag e;
    //! code associated with the intermediate conversion
    std::string c;
    //! code associated with the final conversion
    std::string cf;
  };

}  // end of namespace mfront

#endif /* LIB_MFRONT_FINITESTRAINBEHAVIOURTANGENTOPERATORCONVERSION_H_ */
