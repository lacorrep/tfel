/*!
 * \file   include/TFEL/Math/RungeKutta4.hxx
 * \brief  This file declares the RungeKutta4 class.
 * \author Helfer Thomas
 * \date   01 Sep 2006
 * \copyright Copyright (C) 2006-2018 CEA/DEN, EDF R&D. All rights 
 * reserved. 
 * This project is publicly released under either the GNU GPL Licence 
 * or the CECILL-A licence. A copy of thoses licences are delivered 
 * with the sources of TFEL. CEA or EDF may also distribute this 
 * project under specific licensing conditions. 
 */

#ifndef LIB_TFEL_RUNGEKUTTA4_H_
#define LIB_TFEL_RUNGEKUTTA4_H_ 

namespace tfel{
  
  namespace math{

    template<unsigned int N,typename T, typename Func>
    class RungeKutta4;

  } // end of namespace math

} // end of namespace tfel


#include"TFEL/Math/RungeKutta/RungeKutta4.ixx"

#endif /* LIB_TFEL_RUNGEKUTTA4_H_ */

