/*! 
 * \file  mfront/include/MFront/Europlexus/EuroplexusConfig.hxx
 * \brief
 * \author Helfer Thomas
 * \brief 10 janv. 2013
 * \copyright Copyright (C) 2006-2018 CEA/DEN, EDF R&D. All rights 
 * reserved. 
 * This project is publicly released under either the GNU GPL Licence 
 * or the CECILL-A licence. A copy of thoses licences are delivered 
 * with the sources of TFEL. CEA or EDF may also distribute this 
 * project under specific licensing conditions. 
 */

#ifndef LIB_MFRONT_EPX_EPXCONFIG_H_
#define LIB_MFRONT_EPX_EPXCONFIG_H_ 

#include"MFront/MFrontConfig.hxx"

#if defined _WIN32 || defined _WIN64 ||defined __CYGWIN__
#  if defined EuroplexusInterface_EXPORTS
#    define MFRONT_EPX_VISIBILITY_EXPORT TFEL_VISIBILITY_EXPORT
#  else
#  ifndef TFEL_STATIC_BUILD
#    define MFRONT_EPX_VISIBILITY_EXPORT TFEL_VISIBILITY_IMPORT
#  else 
#    define MFRONT_EPX_VISIBILITY_EXPORT 
#  endif
#  endif
#else
#  define MFRONT_EPX_VISIBILITY_EXPORT TFEL_VISIBILITY_EXPORT
#endif /* LIB_MFRONT_EPX_EPXCONFIG_H_ */

#endif /* LIB_MFRONT_EPX_EPXCONFIG_H_ */

