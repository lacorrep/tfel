/*!
 * \file   include/TFEL/System/SystemError.ixx
 * \brief
 * \author Helfer Thomas
 * \date   06 Nov 2007
 * \copyright Copyright (C) 2006-2018 CEA/DEN, EDF R&D. All rights
 * reserved.
 * This project is publicly released under either the GNU GPL Licence
 * or the CECILL-A licence. A copy of thoses licences are delivered
 * with the sources of TFEL. CEA or EDF may also distribute this
 * project under specific licensing conditions.
 */

#ifndef LIB_TFEL_SYSTEMERROR_IXX_
#define LIB_TFEL_SYSTEMERROR_IXX_

namespace tfel {

  namespace system {

    template <unsigned short N>
    PosixError<N>::PosixError(const std::string& msg_)
        : SystemError(msg_) {}  // end of PosixError::PosixError

  }  // end of namespace system

}  // end of namespace tfel

#endif /* LIB_TFEL_SYSTEMERROR_IXX_ */
