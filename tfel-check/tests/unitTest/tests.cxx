/*!
 * \file   tests.cxx
 * \brief    
 * \author THOMAS HELFER
 * \date   22 janv. 2016
 * \copyright Copyright (C) 2006-2018 CEA/DEN, EDF R&D. All rights 
 * reserved. 
 * This project is publicly released under either the GNU GPL Licence 
 * or the CECILL-A licence. A copy of thoses licences are delivered 
 * with the sources of TFEL. CEA or EDF may also distribute this 
 * project under specific licensing conditions. 
 */

#include<iostream>
#include<cstdlib>
#include"TFEL/Tests/TestCase.hxx"
#include"TFEL/Tests/TestManager.hxx"

/* coverity [UNCAUGHT_EXCEPT]*/
int main()
{
  auto& manager = tfel::tests::TestManager::getTestManager();
  manager.addTestOutput(std::cout);
  manager.addXMLTestOutput("tfel-check.xml");
  const auto r = manager.execute();
  return r.success() ? EXIT_SUCCESS : EXIT_FAILURE;
} // end of main
