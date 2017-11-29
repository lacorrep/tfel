/*! 
 * \file  include/TFEL/Math/TinyMatrixInvert.hxx
 * \brief
 * \author Helfer Thomas
 * \brief 08 mars 2013
 * \copyright Copyright (C) 2006-2018 CEA/DEN, EDF R&D. All rights 
 * reserved. 
 * This project is publicly released under either the GNU GPL Licence 
 * or the CECILL-A licence. A copy of thoses licences are delivered 
 * with the sources of TFEL. CEA or EDF may also distribute this 
 * project under specific licensing conditions. 
 */

#ifndef LIB_TFEL_MATH_TINYMATRIXINVERT_H_
#define LIB_TFEL_MATH_TINYMATRIXINVERT_H_ 

#include<limits>

#include"TFEL/Math/tvector.hxx"
#include"TFEL/Math/tmatrix.hxx"
#include"TFEL/Math/TinyMatrixSolve.hxx"

namespace tfel{
  
  namespace math{

    template<unsigned short N,
	     typename T>
    struct TinyMatrixInvert
    {
      
      static void
      exe(tfel::math::tmatrix<N,N,T>&,
	  const T = 100*std::numeric_limits<T>::min());
    }; // end of struct TinyMatrixInvert

  } // end of namespace math

} // end of namespace tfel

#include"TFEL/Math/Matrix/TinyMatrixInvert.ixx"

#endif /* LIB_TFEL_MATH_TINYMATRIXINVERT_H_ */

