/*!
 * \file   include/TFEL/Math/LU/Permutation.hxx
 *
 * \brief
 * \author Helfer Thomas
 * \date   01 Aug 2006
 * \copyright Copyright (C) 2006-2018 CEA/DEN, EDF R&D. All rights
 * reserved.
 * This project is publicly released under either the GNU GPL Licence
 * or the CECILL-A licence. A copy of thoses licences are delivered
 * with the sources of TFEL. CEA or EDF may also distribute this
 * project under specific licensing conditions.
 */

#ifndef LIB_TFEL_MATH_PERMUTATION_H_
#define LIB_TFEL_MATH_PERMUTATION_H_

#include <cstdlib>

#include "TFEL/Math/vector.hxx"

namespace tfel {

  namespace math {

    template <typename T>
    struct Permutation : protected vector<T> {
      Permutation() = default;
      Permutation(const Permutation&) = delete;
      Permutation(Permutation&&) = delete;
      Permutation& operator=(Permutation&&) = delete;
      Permutation& operator=(const Permutation&) = delete;
      //! default constructor
      TFEL_MATH_INLINE
      Permutation(const typename vector<T>::size_type);
      /*!
       * \brief set this permutation vector to be equal to the
       * identity
       */
      TFEL_MATH_INLINE
      void reset(void);

      using vector<T>::operator[];
      using vector<T>::operator();
      using vector<T>::size;
      using vector<T>::clear;

      TFEL_MATH_INLINE void swap(const typename vector<T>::size_type,
                                 const typename vector<T>::size_type);
      //! \return true is the permutation is the identity
      TFEL_MATH_INLINE bool isIdentity() const;
      /*!
       * \brief resize the permutation
       * This automatically calls the reset method
       */
      void resize(const typename vector<T>::size_type);
      //! destructor
      ~Permutation();

     private:
      bool is_identity;
    };

  }  // end of namespace math

}  // end of namespace tfel

#include "TFEL/Math/LU/Permutation.ixx"

#endif /* LIB_TFEL_MATH_PERMUTATION_H_ */
