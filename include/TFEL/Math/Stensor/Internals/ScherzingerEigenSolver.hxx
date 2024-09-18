/*!
 * \file   ScherzingerEigenSolver.hxx
 * \brief
 * \author Maxence Wangermez/Thomas Helfer
 * \date   13/02/2023
 * \copyright Copyright (C) 2006-2023 CEA/DEN, EDF R&D. All rights
 * reserved.
 *
 * This project is publicly released under either the GNU GPL Licence
 * or the CECILL-A licence. A copy of thoses licences are delivered
 * with the sources of TFEL. CEA or EDF may also distribute this
 * project under specific licensing conditions.
 *
 * This file was adapted from Numerical diagonalization of 3x3
 * matrices of Scherzinger, W. M. and Dohrmann, C. R., see
 * [1] A robust algorithm for finding the eigenvalues and eigenvectors of 3×3
 * symmetric matrices for details.
 *
 */

#ifndef LIB_TFEL_MATH_SCHERZINGEREIGENSOLVER_HXX
#define LIB_TFEL_MATH_SCHERZINGEREIGENSOLVER_HXX

#include <iostream>
#include <cmath>
#include <vector>
#include "TFEL/Math/tvector.hxx"
#include "TFEL/Math/tmatrix.hxx"

namespace tfel::math::internals {

  template <typename t>
  int sign(t val);

  template <typename T, typename A>
  int argmax(std::vector<T, A> const&);

  template <typename T, typename A>
  int argmin(std::vector<T, A> const&);

  template <typename real>
  struct ScherzingerEigensolver3x3 {
    /*!
     * \brief calculates the eigenvalues of a real symmetric 3x3 matrix
     *    [ A  D  E ]
     *    [ D  B  F ]
     *    [ E  F  C ]
     * \param[out] vp: eigen values
     * \param[in]  A:  component of the matrix
     * \param[in]  B:  component of the matrix
     * \param[in]  C:  component of the matrix
     */
    static void computeEigenValues(tvector<3u, real>&,
                                   tmatrix<3u, 3u, real>&,
                                   const real,
                                   const real,
                                   const real,
                                   const real,
                                   const real,
                                   const real);
    /*!
     * \brief calculates the eigensystem of a real symmetric 3x3 matrix
     *    [ A  D  E ]
     *    [ D  B  F ]
     *    [ E  F  C ]
     * \param[out] vp: eigen values
     * \param[out] m:  eigen vectors
     * \param[in]  A:  component of the matrix
     * \param[in]  B:  component of the matrix
     * \param[in]  C:  component of the matrix
     * \param[in]  D:  component of the matrix
     * \param[in]  E:  component of the matrix
     * \param[in]  F:  component of the matrix
     */
    static void computeEigenVectors(tvector<3u, real>&,
                                    tmatrix<3u, 3u, real>&,
                                    const real,
                                    const real,
                                    const real,
                                    const real,
                                    const real,
                                    const real);

   private:
    /*!
     * \brief computes the first eigen value of a real symmetric 3x3 matrix
     *    [ A  D  E ]
     *    [ D  B  F ]
     *    [ E  F  C ]
     * \param[out] vp: eigen values
     * \param[in] devM: deviatoric matrix
     * \param[in] tr: trace of the matrix
     */
    static void computeFirstEigenValue(tvector<3u, real>&,
                                       const tmatrix<3u, 3u, real>&,
                                       const real);

    /*!
     * \brief computes the first eigen vector
     * of a real symmetric 3x3 matrix A, associated
     * with the eigen value stored in vp[0] and
     * stores in the first column of m
     *     [ A  D  E ]
     * A = [ D  B  F ]
     *     [ E  F  C ]
     * The vectors s1 and s2 of [1] are also stored
     * in columns two and three of m
     * \param[out] vp: eigen values
     * \param[out] m:  m[0]: first ev, m[1] and m[2]: orthogonal subspace
     * \param[in] devM: deviatoric matrix
     * \param[in] tr: trace of the matrix
     */
    static void computeProjectionBasis(tvector<3u, real>&,
                                       tmatrix<3u, 3u, real>&,
                                       const tmatrix<3u, 3u, real>&,
                                       const real);
  };

}  // end of namespace tfel::math::internals

#include "TFEL/Math/Stensor/Internals/ScherzingerEigenSolver.ixx"

#endif /* LIB_TFEL_MATH_SCHERZINGEREIGENSOLVER_HXX */
