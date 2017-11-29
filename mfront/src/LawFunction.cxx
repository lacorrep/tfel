/*! 
 * \file  LawFunction.cxx
 * \brief
 * \author Helfer Thomas
 * \date   22 janv. 2015
 * \copyright Copyright (C) 2006-2018 CEA/DEN, EDF R&D. All rights 
 * reserved. 
 * This project is publicly released under either the GNU GPL Licence 
 * or the CECILL-A licence. A copy of thoses licences are delivered 
 * with the sources of TFEL. CEA or EDF may also distribute this 
 * project under specific licensing conditions. 
 */

#include"MFront/LawFunction.hxx"

namespace mfront{

  LawFunction::LawFunction() = default;
  LawFunction::LawFunction(LawFunction&&) = default;
  LawFunction::LawFunction(const LawFunction&) = default;
  LawFunction& LawFunction::operator=(LawFunction&&) = default;
  LawFunction& LawFunction::operator=(const LawFunction&) = default;
  LawFunction::~LawFunction() = default;

} // end of namespace mfront
