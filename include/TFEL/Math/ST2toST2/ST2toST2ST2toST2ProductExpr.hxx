/*!
 * \file  include/TFEL/Math/ST2toST2/ST2toST2ST2toST2ProductExpr.hxx
 * \brief
 * \author Helfer Thomas
 * \date 16 juin 2014
 * \copyright Copyright (C) 2006-2018 CEA/DEN, EDF R&D. All rights
 * reserved.
 * This project is publicly released under either the GNU GPL Licence
 * or the CECILL-A licence. A copy of thoses licences are delivered
 * with the sources of TFEL. CEA or EDF may also distribute this
 * project under specific licensing conditions.
 */

#ifndef LIB_TFEL_MATH_ST2TOST2ST2TOST2PRODUCTEXPR_H_
#define LIB_TFEL_MATH_ST2TOST2ST2TOST2PRODUCTEXPR_H_

#include "TFEL/Config/TFELConfig.hxx"

#include "TFEL/Math/General/EmptyRunTimeProperties.hxx"
#include "TFEL/Math/ST2toST2/ST2toST2Concept.hxx"

namespace tfel {

  namespace math {

    //! Empty structure used for partial specialisation of the
    //! Expr class
    template <unsigned short N>
    struct TFEL_VISIBILITY_LOCAL ST2toST2ST2toST2ProductExpr {
    };  // end of struct ST2toST2ST2toST2ProductExpr

    /*!
     * Partial specialisation
     */
    template <typename ST2toST2ResultType>
    struct TFEL_VISIBILITY_LOCAL
        Expr<ST2toST2ResultType, ST2toST2ST2toST2ProductExpr<1u>>
        : public ST2toST2Concept<
              Expr<ST2toST2ResultType, ST2toST2ST2toST2ProductExpr<1u>>>,
          public fsarray<StensorDimeToSize<
                             ST2toST2Traits<ST2toST2ResultType>::dime>::value *
                             StensorDimeToSize<ST2toST2Traits<
                                 ST2toST2ResultType>::dime>::value,
                         typename ST2toST2Traits<ST2toST2ResultType>::NumType> {
      //! a simple alias
      typedef EmptyRunTimeProperties RunTimeProperties;
      //! a simple alias
      typedef typename ST2toST2Traits<ST2toST2ResultType>::NumType value_type;
      //! a simple check
      TFEL_STATIC_ASSERT((ST2toST2Traits<ST2toST2ResultType>::dime == 1u));
      /*!
       * \param[in] a : first term of the product
       * \param[in] b : second term of the product
       */
      template <typename ST2toST2Type, typename ST2toST2Type2>
      TFEL_MATH_INLINE Expr(const ST2toST2Type& a, const ST2toST2Type2& b) {
        //! a simple check
        TFEL_STATIC_ASSERT(
            (tfel::meta::Implements<ST2toST2Type,
                                    tfel::math::ST2toST2Concept>::cond));
        //! a simple check
        TFEL_STATIC_ASSERT(
            (tfel::meta::Implements<ST2toST2Type2,
                                    tfel::math::ST2toST2Concept>::cond));
        //! a simple check
        TFEL_STATIC_ASSERT((ST2toST2Traits<ST2toST2Type>::dime == 1u));
        //! a simple check
        TFEL_STATIC_ASSERT((ST2toST2Traits<ST2toST2Type2>::dime == 1u));
        this->v[0] = a(0, 0) * b(0, 0) + a(0, 1) * b(1, 0) + a(0, 2) * b(2, 0);
        this->v[1] = a(0, 0) * b(0, 1) + a(0, 1) * b(1, 1) + a(0, 2) * b(2, 1);
        this->v[2] = a(0, 0) * b(0, 2) + a(0, 1) * b(1, 2) + a(0, 2) * b(2, 2);
        this->v[3] = a(1, 0) * b(0, 0) + a(1, 1) * b(1, 0) + a(1, 2) * b(2, 0);
        this->v[4] = a(1, 0) * b(0, 1) + a(1, 1) * b(1, 1) + a(1, 2) * b(2, 1);
        this->v[5] = a(1, 0) * b(0, 2) + a(1, 1) * b(1, 2) + a(1, 2) * b(2, 2);
        this->v[6] = a(2, 0) * b(0, 0) + a(2, 1) * b(1, 0) + a(2, 2) * b(2, 0);
        this->v[7] = a(2, 0) * b(0, 1) + a(2, 1) * b(1, 1) + a(2, 2) * b(2, 1);
        this->v[8] = a(2, 0) * b(0, 2) + a(2, 1) * b(1, 2) + a(2, 2) * b(2, 2);
      }  // end of Expr
      /*!
       * \brief access operator
       * \param[in] i : line index
       * \param[in] j : column index
       */
      TFEL_MATH_INLINE const value_type& operator()(
          const unsigned short i, const unsigned short j) const {
        return this->v[i * 3 + j];
      }  // end of operator()
      /*!
       * \return the runtime properties
       */
      TFEL_MATH_INLINE RunTimeProperties getRunTimeProperties() const {
        return RunTimeProperties();
      }
    };  // end of struct Expr<ST2toST2ResultType,ST2toST2ST2toST2ProductExpr>

    /*!
     * Partial specialisation
     */
    template <typename ST2toST2ResultType>
    struct TFEL_VISIBILITY_LOCAL
        Expr<ST2toST2ResultType, ST2toST2ST2toST2ProductExpr<2u>>
        : public ST2toST2Concept<
              Expr<ST2toST2ResultType, ST2toST2ST2toST2ProductExpr<2u>>>,
          public fsarray<StensorDimeToSize<
                             ST2toST2Traits<ST2toST2ResultType>::dime>::value *
                             StensorDimeToSize<ST2toST2Traits<
                                 ST2toST2ResultType>::dime>::value,
                         typename ST2toST2Traits<ST2toST2ResultType>::NumType> {
      //! a simple alias
      typedef EmptyRunTimeProperties RunTimeProperties;
      //! a simple alias
      typedef typename ST2toST2Traits<ST2toST2ResultType>::NumType value_type;
      //! a simple check
      TFEL_STATIC_ASSERT((ST2toST2Traits<ST2toST2ResultType>::dime == 2u));
      /*!
       * \param[in] a : first term of the product
       * \param[in] b : second term of the product
       */
      template <typename ST2toST2Type, typename ST2toST2Type2>
      TFEL_MATH_INLINE Expr(const ST2toST2Type& a, const ST2toST2Type2& b) {
        //! a simple check
        TFEL_STATIC_ASSERT(
            (tfel::meta::Implements<ST2toST2Type,
                                    tfel::math::ST2toST2Concept>::cond));
        //! a simple check
        TFEL_STATIC_ASSERT(
            (tfel::meta::Implements<ST2toST2Type2,
                                    tfel::math::ST2toST2Concept>::cond));
        //! a simple check
        TFEL_STATIC_ASSERT((ST2toST2Traits<ST2toST2Type>::dime == 2u));
        //! a simple check
        TFEL_STATIC_ASSERT((ST2toST2Traits<ST2toST2Type2>::dime == 2u));
        this->v[0] = a(0, 0) * b(0, 0) + a(0, 1) * b(1, 0) + a(0, 2) * b(2, 0) +
                     a(0, 3) * b(3, 0);
        this->v[1] = a(0, 0) * b(0, 1) + a(0, 1) * b(1, 1) + a(0, 2) * b(2, 1) +
                     a(0, 3) * b(3, 1);
        this->v[2] = a(0, 0) * b(0, 2) + a(0, 1) * b(1, 2) + a(0, 2) * b(2, 2) +
                     a(0, 3) * b(3, 2);
        this->v[3] = a(0, 0) * b(0, 3) + a(0, 1) * b(1, 3) + a(0, 2) * b(2, 3) +
                     a(0, 3) * b(3, 3);
        this->v[4] = a(1, 0) * b(0, 0) + a(1, 1) * b(1, 0) + a(1, 2) * b(2, 0) +
                     a(1, 3) * b(3, 0);
        this->v[5] = a(1, 0) * b(0, 1) + a(1, 1) * b(1, 1) + a(1, 2) * b(2, 1) +
                     a(1, 3) * b(3, 1);
        this->v[6] = a(1, 0) * b(0, 2) + a(1, 1) * b(1, 2) + a(1, 2) * b(2, 2) +
                     a(1, 3) * b(3, 2);
        this->v[7] = a(1, 0) * b(0, 3) + a(1, 1) * b(1, 3) + a(1, 2) * b(2, 3) +
                     a(1, 3) * b(3, 3);
        this->v[8] = a(2, 0) * b(0, 0) + a(2, 1) * b(1, 0) + a(2, 2) * b(2, 0) +
                     a(2, 3) * b(3, 0);
        this->v[9] = a(2, 0) * b(0, 1) + a(2, 1) * b(1, 1) + a(2, 2) * b(2, 1) +
                     a(2, 3) * b(3, 1);
        this->v[10] = a(2, 0) * b(0, 2) + a(2, 1) * b(1, 2) +
                      a(2, 2) * b(2, 2) + a(2, 3) * b(3, 2);
        this->v[11] = a(2, 0) * b(0, 3) + a(2, 1) * b(1, 3) +
                      a(2, 2) * b(2, 3) + a(2, 3) * b(3, 3);
        this->v[12] = a(3, 0) * b(0, 0) + a(3, 1) * b(1, 0) +
                      a(3, 2) * b(2, 0) + a(3, 3) * b(3, 0);
        this->v[13] = a(3, 0) * b(0, 1) + a(3, 1) * b(1, 1) +
                      a(3, 2) * b(2, 1) + a(3, 3) * b(3, 1);
        this->v[14] = a(3, 0) * b(0, 2) + a(3, 1) * b(1, 2) +
                      a(3, 2) * b(2, 2) + a(3, 3) * b(3, 2);
        this->v[15] = a(3, 0) * b(0, 3) + a(3, 1) * b(1, 3) +
                      a(3, 2) * b(2, 3) + a(3, 3) * b(3, 3);
      }  // end of Expr
      /*!
       * \brief access operator
       * \param[in] i : line index
       * \param[in] j : column index
       */
      TFEL_MATH_INLINE const value_type& operator()(
          const unsigned short i, const unsigned short j) const {
        return this->v[i * 4 + j];
      }  // end of operator()
      /*!
       * \return the runtime properties
       */
      TFEL_MATH_INLINE RunTimeProperties getRunTimeProperties() const {
        return RunTimeProperties();
      }
    };  // end of struct Expr<ST2toST2ResultType,ST2toST2ST2toST2ProductExpr>

    /*!
     * Partial specialisation
     */
    template <typename ST2toST2ResultType>
    struct TFEL_VISIBILITY_LOCAL
        Expr<ST2toST2ResultType, ST2toST2ST2toST2ProductExpr<3u>>
        : public ST2toST2Concept<
              Expr<ST2toST2ResultType, ST2toST2ST2toST2ProductExpr<3u>>>,
          public fsarray<StensorDimeToSize<
                             ST2toST2Traits<ST2toST2ResultType>::dime>::value *
                             StensorDimeToSize<ST2toST2Traits<
                                 ST2toST2ResultType>::dime>::value,
                         typename ST2toST2Traits<ST2toST2ResultType>::NumType> {
      //! a simple alias
      typedef EmptyRunTimeProperties RunTimeProperties;
      //! a simple alias
      typedef typename ST2toST2Traits<ST2toST2ResultType>::NumType value_type;
      //! a simple check
      TFEL_STATIC_ASSERT((ST2toST2Traits<ST2toST2ResultType>::dime == 3u));
      /*!
       * \param[in] a : first term of the product
       * \param[in] b : second term of the product
       */
      template <typename ST2toST2Type, typename ST2toST2Type2>
      TFEL_MATH_INLINE Expr(const ST2toST2Type& a, const ST2toST2Type2& b) {
        //! a simple check
        TFEL_STATIC_ASSERT(
            (tfel::meta::Implements<ST2toST2Type,
                                    tfel::math::ST2toST2Concept>::cond));
        //! a simple check
        TFEL_STATIC_ASSERT(
            (tfel::meta::Implements<ST2toST2Type2,
                                    tfel::math::ST2toST2Concept>::cond));
        //! a simple check
        TFEL_STATIC_ASSERT((ST2toST2Traits<ST2toST2Type>::dime == 3u));
        //! a simple check
        TFEL_STATIC_ASSERT((ST2toST2Traits<ST2toST2Type2>::dime == 3u));
        this->v[0] = a(0, 0) * b(0, 0) + a(0, 1) * b(1, 0) + a(0, 2) * b(2, 0) +
                     a(0, 3) * b(3, 0) + a(0, 4) * b(4, 0) + a(0, 5) * b(5, 0);
        this->v[1] = a(0, 0) * b(0, 1) + a(0, 1) * b(1, 1) + a(0, 2) * b(2, 1) +
                     a(0, 3) * b(3, 1) + a(0, 4) * b(4, 1) + a(0, 5) * b(5, 1);
        this->v[2] = a(0, 0) * b(0, 2) + a(0, 1) * b(1, 2) + a(0, 2) * b(2, 2) +
                     a(0, 3) * b(3, 2) + a(0, 4) * b(4, 2) + a(0, 5) * b(5, 2);
        this->v[3] = a(0, 0) * b(0, 3) + a(0, 1) * b(1, 3) + a(0, 2) * b(2, 3) +
                     a(0, 3) * b(3, 3) + a(0, 4) * b(4, 3) + a(0, 5) * b(5, 3);
        this->v[4] = a(0, 0) * b(0, 4) + a(0, 1) * b(1, 4) + a(0, 2) * b(2, 4) +
                     a(0, 3) * b(3, 4) + a(0, 4) * b(4, 4) + a(0, 5) * b(5, 4);
        this->v[5] = a(0, 0) * b(0, 5) + a(0, 1) * b(1, 5) + a(0, 2) * b(2, 5) +
                     a(0, 3) * b(3, 5) + a(0, 4) * b(4, 5) + a(0, 5) * b(5, 5);
        this->v[6] = a(1, 0) * b(0, 0) + a(1, 1) * b(1, 0) + a(1, 2) * b(2, 0) +
                     a(1, 3) * b(3, 0) + a(1, 4) * b(4, 0) + a(1, 5) * b(5, 0);
        this->v[7] = a(1, 0) * b(0, 1) + a(1, 1) * b(1, 1) + a(1, 2) * b(2, 1) +
                     a(1, 3) * b(3, 1) + a(1, 4) * b(4, 1) + a(1, 5) * b(5, 1);
        this->v[8] = a(1, 0) * b(0, 2) + a(1, 1) * b(1, 2) + a(1, 2) * b(2, 2) +
                     a(1, 3) * b(3, 2) + a(1, 4) * b(4, 2) + a(1, 5) * b(5, 2);
        this->v[9] = a(1, 0) * b(0, 3) + a(1, 1) * b(1, 3) + a(1, 2) * b(2, 3) +
                     a(1, 3) * b(3, 3) + a(1, 4) * b(4, 3) + a(1, 5) * b(5, 3);
        this->v[10] = a(1, 0) * b(0, 4) + a(1, 1) * b(1, 4) +
                      a(1, 2) * b(2, 4) + a(1, 3) * b(3, 4) +
                      a(1, 4) * b(4, 4) + a(1, 5) * b(5, 4);
        this->v[11] = a(1, 0) * b(0, 5) + a(1, 1) * b(1, 5) +
                      a(1, 2) * b(2, 5) + a(1, 3) * b(3, 5) +
                      a(1, 4) * b(4, 5) + a(1, 5) * b(5, 5);
        this->v[12] = a(2, 0) * b(0, 0) + a(2, 1) * b(1, 0) +
                      a(2, 2) * b(2, 0) + a(2, 3) * b(3, 0) +
                      a(2, 4) * b(4, 0) + a(2, 5) * b(5, 0);
        this->v[13] = a(2, 0) * b(0, 1) + a(2, 1) * b(1, 1) +
                      a(2, 2) * b(2, 1) + a(2, 3) * b(3, 1) +
                      a(2, 4) * b(4, 1) + a(2, 5) * b(5, 1);
        this->v[14] = a(2, 0) * b(0, 2) + a(2, 1) * b(1, 2) +
                      a(2, 2) * b(2, 2) + a(2, 3) * b(3, 2) +
                      a(2, 4) * b(4, 2) + a(2, 5) * b(5, 2);
        this->v[15] = a(2, 0) * b(0, 3) + a(2, 1) * b(1, 3) +
                      a(2, 2) * b(2, 3) + a(2, 3) * b(3, 3) +
                      a(2, 4) * b(4, 3) + a(2, 5) * b(5, 3);
        this->v[16] = a(2, 0) * b(0, 4) + a(2, 1) * b(1, 4) +
                      a(2, 2) * b(2, 4) + a(2, 3) * b(3, 4) +
                      a(2, 4) * b(4, 4) + a(2, 5) * b(5, 4);
        this->v[17] = a(2, 0) * b(0, 5) + a(2, 1) * b(1, 5) +
                      a(2, 2) * b(2, 5) + a(2, 3) * b(3, 5) +
                      a(2, 4) * b(4, 5) + a(2, 5) * b(5, 5);
        this->v[18] = a(3, 0) * b(0, 0) + a(3, 1) * b(1, 0) +
                      a(3, 2) * b(2, 0) + a(3, 3) * b(3, 0) +
                      a(3, 4) * b(4, 0) + a(3, 5) * b(5, 0);
        this->v[19] = a(3, 0) * b(0, 1) + a(3, 1) * b(1, 1) +
                      a(3, 2) * b(2, 1) + a(3, 3) * b(3, 1) +
                      a(3, 4) * b(4, 1) + a(3, 5) * b(5, 1);
        this->v[20] = a(3, 0) * b(0, 2) + a(3, 1) * b(1, 2) +
                      a(3, 2) * b(2, 2) + a(3, 3) * b(3, 2) +
                      a(3, 4) * b(4, 2) + a(3, 5) * b(5, 2);
        this->v[21] = a(3, 0) * b(0, 3) + a(3, 1) * b(1, 3) +
                      a(3, 2) * b(2, 3) + a(3, 3) * b(3, 3) +
                      a(3, 4) * b(4, 3) + a(3, 5) * b(5, 3);
        this->v[22] = a(3, 0) * b(0, 4) + a(3, 1) * b(1, 4) +
                      a(3, 2) * b(2, 4) + a(3, 3) * b(3, 4) +
                      a(3, 4) * b(4, 4) + a(3, 5) * b(5, 4);
        this->v[23] = a(3, 0) * b(0, 5) + a(3, 1) * b(1, 5) +
                      a(3, 2) * b(2, 5) + a(3, 3) * b(3, 5) +
                      a(3, 4) * b(4, 5) + a(3, 5) * b(5, 5);
        this->v[24] = a(4, 0) * b(0, 0) + a(4, 1) * b(1, 0) +
                      a(4, 2) * b(2, 0) + a(4, 3) * b(3, 0) +
                      a(4, 4) * b(4, 0) + a(4, 5) * b(5, 0);
        this->v[25] = a(4, 0) * b(0, 1) + a(4, 1) * b(1, 1) +
                      a(4, 2) * b(2, 1) + a(4, 3) * b(3, 1) +
                      a(4, 4) * b(4, 1) + a(4, 5) * b(5, 1);
        this->v[26] = a(4, 0) * b(0, 2) + a(4, 1) * b(1, 2) +
                      a(4, 2) * b(2, 2) + a(4, 3) * b(3, 2) +
                      a(4, 4) * b(4, 2) + a(4, 5) * b(5, 2);
        this->v[27] = a(4, 0) * b(0, 3) + a(4, 1) * b(1, 3) +
                      a(4, 2) * b(2, 3) + a(4, 3) * b(3, 3) +
                      a(4, 4) * b(4, 3) + a(4, 5) * b(5, 3);
        this->v[28] = a(4, 0) * b(0, 4) + a(4, 1) * b(1, 4) +
                      a(4, 2) * b(2, 4) + a(4, 3) * b(3, 4) +
                      a(4, 4) * b(4, 4) + a(4, 5) * b(5, 4);
        this->v[29] = a(4, 0) * b(0, 5) + a(4, 1) * b(1, 5) +
                      a(4, 2) * b(2, 5) + a(4, 3) * b(3, 5) +
                      a(4, 4) * b(4, 5) + a(4, 5) * b(5, 5);
        this->v[30] = a(5, 0) * b(0, 0) + a(5, 1) * b(1, 0) +
                      a(5, 2) * b(2, 0) + a(5, 3) * b(3, 0) +
                      a(5, 4) * b(4, 0) + a(5, 5) * b(5, 0);
        this->v[31] = a(5, 0) * b(0, 1) + a(5, 1) * b(1, 1) +
                      a(5, 2) * b(2, 1) + a(5, 3) * b(3, 1) +
                      a(5, 4) * b(4, 1) + a(5, 5) * b(5, 1);
        this->v[32] = a(5, 0) * b(0, 2) + a(5, 1) * b(1, 2) +
                      a(5, 2) * b(2, 2) + a(5, 3) * b(3, 2) +
                      a(5, 4) * b(4, 2) + a(5, 5) * b(5, 2);
        this->v[33] = a(5, 0) * b(0, 3) + a(5, 1) * b(1, 3) +
                      a(5, 2) * b(2, 3) + a(5, 3) * b(3, 3) +
                      a(5, 4) * b(4, 3) + a(5, 5) * b(5, 3);
        this->v[34] = a(5, 0) * b(0, 4) + a(5, 1) * b(1, 4) +
                      a(5, 2) * b(2, 4) + a(5, 3) * b(3, 4) +
                      a(5, 4) * b(4, 4) + a(5, 5) * b(5, 4);
        this->v[35] = a(5, 0) * b(0, 5) + a(5, 1) * b(1, 5) +
                      a(5, 2) * b(2, 5) + a(5, 3) * b(3, 5) +
                      a(5, 4) * b(4, 5) + a(5, 5) * b(5, 5);
      }  // end of Expr
      /*!
       * \brief access operator
       * \param[in] i : line index
       * \param[in] j : column index
       */
      TFEL_MATH_INLINE const value_type& operator()(
          const unsigned short i, const unsigned short j) const {
        return this->v[i * 6 + j];
      }  // end of operator()
      /*!
       * \return the runtime properties
       */
      TFEL_MATH_INLINE RunTimeProperties getRunTimeProperties() const {
        return RunTimeProperties();
      }
    };  // end of struct Expr<ST2toST2ResultType,ST2toST2ST2toST2ProductExpr>

  }  // end of namespace math

}  // end of namespace tfel

#endif /* LIB_TFEL_MATH_ST2TOST2ST2TOST2PRODUCTEXPR_H_ */
