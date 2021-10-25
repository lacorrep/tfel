/*!
 * \file  mfront/include/MFront/ModelDSL.hxx
 * \brief
 * \author Helfer Thomas
 * \brief 11 jun 2010
 * \copyright Copyright (C) 2006-2018 CEA/DEN, EDF R&D. All rights
 * reserved.
 * This project is publicly released under either the GNU GPL Licence
 * or the CECILL-A licence. A copy of thoses licences are delivered
 * with the sources of TFEL. CEA or EDF may also distribute this
 * project under specific licensing conditions.
 */

#ifndef LIB_MFRONTMODELPARSER_H_
#define LIB_MFRONTMODELPARSER_H_

#include "MFront/MFrontConfig.hxx"
#include "MFront/ModelDSLBase.hxx"
#include "MFront/ModelDescription.hxx"

namespace mfront {

  /*!
   * \brief default class for analysing models
   */
  struct MFRONT_VISIBILITY_EXPORT ModelDSL : public ModelDSLBase<ModelDSL> {
    //! \return the name of the dsl
    static std::string getName(void);
    //! \return the description of the dsl
    static std::string getDescription(void);
    /*!
     * \brief add interfaces used for generating output files
     * \param[in] i: list of interfaces
     */
    virtual void setInterfaces(const std::set<std::string>&) override;
    /*!
     * \return a copy of the description of the model treated by the
     * dsl.
     * \note This method shall be called after the `analyseFile`
     * method.
     */
    virtual ModelDescription getModelDescription(void) const;
  };  // end of ModelDSL

}  // end of namespace mfront

#endif /* LIB_MFRONTMODELPARSER_H_ */
