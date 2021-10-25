/*!
 * \file   mfront/include/MFront/InitDSLs.hxx
 * \brief
 *
 * \author Helfer Thomas
 * \date   13 sep 2008
 * \copyright Copyright (C) 2006-2018 CEA/DEN, EDF R&D. All rights
 * reserved.
 * This project is publicly released under either the GNU GPL Licence
 * or the CECILL-A licence. A copy of thoses licences are delivered
 * with the sources of TFEL. CEA or EDF may also distribute this
 * project under specific licensing conditions.
 */

#ifndef LIB_MFRONT_INITPARSERS_HXX_
#define LIB_MFRONT_INITPARSERS_HXX_

#include "MFront/MFrontConfig.hxx"

namespace mfront {

  /*!
   * \brief declare dls's delivered with mfront
   *
   * Users can use the MFRONT_ADDITIONAL_LIBRARIES environment to load
   * their own libraries. See the DSLProxy class for details.
   */
  MFRONT_VISIBILITY_EXPORT void initDSLs(void);

}  // end of namespace mfront

#endif /* LIB_MFRONT_INITPARSERS_HXX_ */
