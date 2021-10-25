/*!
 * \file   include/TFEL/TypeTraits/IsReal.hxx
 * \brief  This file declares the IsReal traits class
 * and specialises it for standard numeric types.
 * \author Helfer Thomas
 * \date   04 Jul 2006
 * \copyright Copyright (C) 2006-2018 CEA/DEN, EDF R&D. All rights
 * reserved.
 * This project is publicly released under either the GNU GPL Licence
 * or the CECILL-A licence. A copy of thoses licences are delivered
 * with the sources of TFEL. CEA or EDF may also distribute this
 * project under specific licensing conditions.
 */

#ifndef LIB_TFEL_ISREAL_HXX_
#define LIB_TFEL_ISREAL_HXX_

/*!
 * \def    TFEL_META_IS_REAL
 * \brief An helper macro to specialise IsReal for each standard
 * "real" numeric types.
 * \author Helfer Thomas
 * \date   28 jun 2006
 */
#define TFEL_META_IS_REAL(X)             \
  /*!                                    \
   * \brief Partial specialisation for X \
   * \see   IsReal                       \
   */                                    \
  template <>                            \
  struct IsReal<X> {                     \
    /*!                                  \
     *  Result                           \
     */                                  \
    static constexpr bool cond = true;   \
  };                                     \
  /*!                                    \
   * \brief Partial specialisation for X \
   * \see   IsReal                       \
   */                                    \
  template <>                            \
  struct IsReal<const X> {               \
    /*!                                  \
     *  Result                           \
     */                                  \
    static constexpr bool cond = true;   \
  }

namespace tfel {

  namespace typetraits {

    /*!
     * \brief Traits class which says it a given type stands for a
     * real numerical type.
     *
     * \param  T, type to be tested.
     * \return bool cond, true if T stands for a real numerical type,
     * false otherwise.
     *
     * \see IsScalar, IsComplex
     *
     * \author Helfer Thomas
     * \date   04 Jul 2006
     */
    template <typename T>
    struct IsReal {
      /*!
       *  Result
       */
      static constexpr bool cond = false;
    };

    TFEL_META_IS_REAL(float);
    TFEL_META_IS_REAL(double);
    TFEL_META_IS_REAL(long double);

  }  // end of namespace typetraits

}  // end of namespace tfel

#endif /* LIB_TFEL_ISREAL_HXX_ */
