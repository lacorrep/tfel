/*!
 * \file  include/TFEL/Math/Discretization1D.hxx
 * \brief
 * \author Helfer Thomas
 * \brief 05 déc. 2011
 * \copyright Copyright (C) 2006-2018 CEA/DEN, EDF R&D. All rights
 * reserved.
 * This project is publicly released under either the GNU GPL Licence
 * or the CECILL-A licence. A copy of thoses licences are delivered
 * with the sources of TFEL. CEA or EDF may also distribute this
 * project under specific licensing conditions.
 */

#ifndef LIB_TFEL_MATH_DISCRETIZATION1D_H_
#define LIB_TFEL_MATH_DISCRETIZATION1D_H_

#include "TFEL/Config/TFELConfig.hxx"
#include "TFEL/Math/MathException.hxx"

namespace tfel {

  namespace math {

    /*!
     * Exception thrown when the density given to the
     * geometricDiscretization function is invalid
     */
    struct TFELMATH_VISIBILITY_EXPORT GeometricDiscretizationInvalidDensity
        : public MathRunTimeException {
      GeometricDiscretizationInvalidDensity() = default;
      GeometricDiscretizationInvalidDensity(
          GeometricDiscretizationInvalidDensity&&) = default;
      GeometricDiscretizationInvalidDensity(
          const GeometricDiscretizationInvalidDensity&) = default;
      //! \return a string describing the error
      virtual const char* what() const noexcept override final;
      //! destructor
      virtual ~GeometricDiscretizationInvalidDensity() noexcept;
    };  // end of struct GeometricDiscretizationInvalidDensity

    /*!
     * Exception thrown when the length given to the
     * geometricDiscretization function is invalid
     */
    struct TFELMATH_VISIBILITY_EXPORT GeometricDiscretizationInvalidLength
        : public MathRunTimeException {
      GeometricDiscretizationInvalidLength() = default;
      GeometricDiscretizationInvalidLength(
          GeometricDiscretizationInvalidLength&&) = default;
      GeometricDiscretizationInvalidLength(
          const GeometricDiscretizationInvalidLength&) = default;
      //! \return a string describing the error
      virtual const char* what() const noexcept override final;
      //! destructor
      virtual ~GeometricDiscretizationInvalidLength() noexcept;
    };  // end of struct GeometricDiscretizationInvalidLength

    /*!
     * Exception thrown when the number of elements given to the
     * geometricDiscretization function is invalid
     */
    struct TFELMATH_VISIBILITY_EXPORT
        GeometricDiscretizationInvalidNumberOfElements
        : public MathRunTimeException {
      GeometricDiscretizationInvalidNumberOfElements() = default;
      GeometricDiscretizationInvalidNumberOfElements(
          GeometricDiscretizationInvalidNumberOfElements&&) = default;
      GeometricDiscretizationInvalidNumberOfElements(
          const GeometricDiscretizationInvalidNumberOfElements&) = default;
      //! \return a string describing the error
      virtual const char* what() const noexcept override final;
      //! destructor
      virtual ~GeometricDiscretizationInvalidNumberOfElements() noexcept;
    };  // end of struct GeometricDiscretizationInvalidNumberOfElements

    /*!
     * \brief discretize a segment into a fixed number of elements
     * trying to satisfy as much as possible given discretization
     * densities at the beginning and the end of the segment. Elements
     * size grows according to a geometric progression.
     *
     * \param T  : a "stl vector like" container
     * \param xb : starting point
     * \param xe : last point
     * \param db : density of the discretization at the starting point
     * \param db : density of the discretization at the last point
     * \param n  : number of elements
     */
    template <typename T>
    void geometricDiscretization(T& v,
                                 const typename T::value_type,
                                 const typename T::value_type,
                                 const typename T::value_type,
                                 const typename T::value_type,
                                 const typename T::size_type);

  }  // end of namespace math

}  // end of namespace tfel

#include "TFEL/Math/Discretization1D.ixx"

#endif /* LIB_TFEL_MATH_DISCRETIZATION1D_H_ */
