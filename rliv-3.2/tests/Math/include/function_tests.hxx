/*!
 * \file   tests/Math/include/function_tests.hxx
 * \brief  
 * 
 * \author Thomas Helfer
 * \date   28 Jun 2006
 * \copyright Copyright (C) 2006-2018 CEA/DEN, EDF R&D. All rights 
 * reserved. 
 * This project is publicly released under either the GNU GPL Licence 
 * or the CECILL-A licence. A copy of thoses licences are delivered 
 * with the sources of TFEL. CEA or EDF may also distribute this 
 * project under specific licensing conditions. 
 */

#ifndef LIB_TFEL_FUNCTION_HXX
#define LIB_TFEL_FUNCTION_HXX 

#include"TFEL/Math/Vector/VectorConcept.hxx"

template<class T>
void function(const tfel::math::VectorConcept<T>&,
	      typename tfel::math::VectorTraits<T>::NumType,
	      typename tfel::math::VectorTraits<T>::NumType,
	      typename tfel::math::VectorTraits<T>::NumType,
	      typename tfel::math::VectorTraits<T>::NumType,
	      unsigned int);

#include "function_tests.ixx"

#endif /* LIB_TFEL_FUNCTION_HXX */

