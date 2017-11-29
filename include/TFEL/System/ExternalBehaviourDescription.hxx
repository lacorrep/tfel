/*!
 * \file   include/TFEL/System/ExternalBehaviourDescription.hxx
 * \brief    
 * \author Helfer Thomas
 * \date   15 June 2015
 * \copyright Copyright (C) 2006-2018 CEA/DEN, EDF R&D. All rights 
 * reserved. 
 * This project is publicly released under either the GNU GPL Licence 
 * or the CECILL-A licence. A copy of thoses licences are delivered 
 * with the sources of TFEL. CEA or EDF may also distribute this 
 * project under specific licensing conditions. 
 */

#ifndef LIB_TFEL_SYSTEM_EXTERNALBEHAVIOURDESCRIPTION_H_
#define LIB_TFEL_SYSTEM_EXTERNALBEHAVIOURDESCRIPTION_H_

#include<string>
#include<vector>

#include"TFEL/Config/TFELConfig.hxx"

namespace tfel
{

  namespace system
  {
    
    /*!
     * A structure containing the information  a given behaviour 
     */
    struct TFELSYSTEM_VISIBILITY_EXPORT ExternalBehaviourData
    {
      ExternalBehaviourData();
      ExternalBehaviourData(ExternalBehaviourData&&);
      ExternalBehaviourData(const ExternalBehaviourData&);
      ExternalBehaviourData& operator=(ExternalBehaviourData&&);
      ExternalBehaviourData& operator=(const ExternalBehaviourData&);
      //! names of the material properties
      std::vector<std::string> mpnames;
      //! names of the internal state variables
      std::vector<std::string> ivnames;
      //! types of the internal state variables
      std::vector<int> ivtypes;
      //! names of the external state variables
      std::vector<std::string> evnames;
      //! source file
      std::string source;
      /*!
       * \brief behaviour type
       * 0 : general behaviour
       * 1 : small strain behaviour
       * 2 : finite strain behaviour
       * 3 : cohesive zone model
       */
      unsigned short btype = 0;
      /*!
       * \brief behaviour kinematic
       * 0 : undefined kinematic
       * 1 : small strain kinematic
       * 2 : cohesive zone model kinematic
       * 3 : standard finite strain kinematic (F-Cauchy)
       * 4 : PTest,Alcyone, Cyrano 1D finite strain kinematic (eto-PK1)
       */
      unsigned short kinematic = 0;
      /*!
       * symmetry type:
       * - If stype is equal to 0, the behaviour is isotropic.
       * - If stype is equal to 1, the behaviour is orthotropic.
       */
      unsigned short stype = 0;
      /*!
       * elastic symmetry type:
       * - If etype is equal to 0, the behaviour elastic behaviour is isotropic.
       * - If etype is equal to 1, the behaviour elastic behaviour is orthotropic.
       */
      unsigned short etype = 0;
      //! If isUPUIR is true, the behaviour is usable in purely implicit resolution
      bool isUPUIR = false;
      //! If requiresStiffnessTensor is true, the caller must provide the stiffness tensor
      bool requiresStiffnessTensor = false;
      /*!
       * If requiresThermalExpansionCoefficientTensor is true, the
       * caller must provide the thermal expansion coefficients tensor
       */
      bool requiresThermalExpansionCoefficientTensor = false;
    };
    
    /*!
     * A structure containing the information that could be retrieved
     * by the ExternalLibraryManger class about a given behaviour for
     * a given hypothesis.
     */
    struct TFELSYSTEM_VISIBILITY_EXPORT ExternalBehaviourDescription
      : public ExternalBehaviourData
    {
      /*!
       * \param[in] l : library
       * \param[in] f : function
       * \param[in] h : hypothesis
       */
      ExternalBehaviourDescription(const std::string&,
				   const std::string&,
				   const std::string&);
      //! default constructor
      ExternalBehaviourDescription();
      //! copy constructor
      ExternalBehaviourDescription(const ExternalBehaviourDescription&);
      //! move constructor
      ExternalBehaviourDescription(ExternalBehaviourDescription&&);
      //! assignement
      ExternalBehaviourDescription&
      operator=(const ExternalBehaviourDescription&);
      //! move assignement
      ExternalBehaviourDescription&
      operator=(ExternalBehaviourDescription&&);
      //! destructor
      ~ExternalBehaviourDescription();
    };
    
  } // end of namespace system

} // end of namespace tfel

extern "C"{

  /*!
   * \author DeltaCAD
   * \brief build a new behaviour data
   * \note the behaviour data must be freed using
   * `freeExternalBehaviourData`
   */
  TFELSYSTEM_VISIBILITY_EXPORT tfel::system::ExternalBehaviourData*
  newExternalBehaviourData();
  /*!
   * \author DeltaCAD
   * \brief build a new behaviour data
   * \note  the behaviour data 
   */
  TFELSYSTEM_VISIBILITY_EXPORT void
  freeExternalBehaviourData(tfel::system::ExternalBehaviourData*);
  /*!
   * \author DeltaCAD
   * \brief retrieving the information from a behaviour
   * \param[in] d: data to be fetched
   * \param[in] l: library
   * \param[in] b: behaviour
   * \param[in] h: modelling hypothesis
   *
   * \return nullptr on success, an error message otherwise.\n
   * If an error message is set, it must be freed  using std::free
   * If the allocation of the error message fails, std::exit is called
   */
  TFELSYSTEM_VISIBILITY_EXPORT char*
  getExternalBehaviourData(tfel::system::ExternalBehaviourData *const,
			   const char* const,
			   const char* const,
			   const char* const);
  
} // end of extern "C"

#endif /* LIB_TFEL_SYSTEM_EXTERNALBEHAVIOURDESCRIPTION_H_ */
