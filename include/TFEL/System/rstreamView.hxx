/*!
 * \file   include/TFEL/System/rstreamView.hxx
 * \brief
 *
 * \author Helfer Thomas
 * \date   18 nov 2007
 * \copyright Copyright (C) 2006-2018 CEA/DEN, EDF R&D. All rights
 * reserved.
 * This project is publicly released under either the GNU GPL Licence
 * or the CECILL-A licence. A copy of thoses licences are delivered
 * with the sources of TFEL. CEA or EDF may also distribute this
 * project under specific licensing conditions.
 */

#ifndef LIB_TFEL_RSTREAMVIEW_HXX_
#define LIB_TFEL_RSTREAMVIEW_HXX_

#include "TFEL/Config/TFELConfig.hxx"
#include "TFEL/System/stream_traits.hxx"
#include "TFEL/System/basic_rstream.hxx"

namespace tfel {

  namespace system {

    template <bool isBlocking>
    struct rstreamView;

    template <bool is>
    struct stream_traits<rstreamView<is>> {
      static constexpr bool isBlocking = is;
    };  // end of struct stream_traits<rstreamView<isBlocking> >

    template <bool isBlocking>
    struct rstreamView
        : public basic_rstream<rstreamView<isBlocking>,
                               stream_traits<rstreamView<isBlocking>>> {
      rstreamView(const int);

      int getFileDescriptor(void) const;

     private:
      const int fd;

    };  // end of struct rstreamView

  }  // end of namespace system

}  // end of namespace tfel

#include "TFEL/System/rstreamView.ixx"

#endif /* LIB_TFEL_RSTREAMVIEW_HXX_ */
