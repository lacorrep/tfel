/*!
 * \file  mfront/src/CamClayStressPotential.cxx
 * \brief
 * \author Thomas Helfer
 * \date   20/11/2014
 * \copyright Copyright (C) 2006-2018 CEA/DEN, EDF R&D. All rights
 * reserved.
 * This project is publicly released under either the GNU GPL Licence
 * or the CECILL-A licence. A copy of thoses licences are delivered
 * with the sources of TFEL. CEA or EDF may also distribute this
 * project under specific licensing conditions.
 * \copyright Copyright (C) 2006-2018 CEA/DEN, EDF R&D. All rights
 * reserved.
 * This project is publicly released under either the GNU GPL Licence
 * or the CECILL-A licence. A copy of thoses licences are delivered
 * with the sources of TFEL. CEA or EDF may also distribute this
 * project under specific licensing conditions.
 * <!-- Local IspellDict: english -->
 */

#include <sstream>
#include <stdexcept>
#include "TFEL/Raise.hxx"
#include "TFEL/Glossary/Glossary.hxx"
#include "TFEL/Glossary/GlossaryEntry.hxx"
#include "TFEL/Utilities/Data.hxx"
#include "MFront/MFrontLogStream.hxx"
#include "MFront/AbstractBehaviourDSL.hxx"
#include "MFront/LocalDataStructure.hxx"
#include "MFront/BehaviourDescription.hxx"
#include "MFront/ImplicitDSLBase.hxx"
#include "MFront/NonLinearSystemSolver.hxx"
#include "MFront/BehaviourBrick/BrickUtilities.hxx"
#include "MFront/BehaviourBrick/OptionDescription.hxx"
#include "MFront/BehaviourBrick/CamClayStressPotential.hxx"

namespace mfront::bbrick {

  CamClayStressPotential::CamClayStressPotential() = default;

  std::string CamClayStressPotential::getName() const { return "CamClay"; }

  std::vector<CamClayStressPotential::Hypothesis>
  CamClayStressPotential::getSupportedModellingHypotheses(
      const BehaviourDescription&, const AbstractBehaviourDSL& dsl) const {
    const auto dmh = dsl.getDefaultModellingHypotheses();
    std::vector<Hypothesis> mh(dmh.begin(), dmh.end());
    return mh;
  }  // end of getSupportedModellingHypotheses

  void CamClayStressPotential::initialize(BehaviourDescription& bd,
                                          AbstractBehaviourDSL& dsl,
                                          const DataMap& d) {
  }  // end CamClayStressPotential

  void CamClayStressPotential::completeVariableDeclaration(
      BehaviourDescription& bd, const AbstractBehaviourDSL& dsl) const {
    constexpr auto uh = ModellingHypothesis::UNDEFINEDHYPOTHESIS;
    if (getVerboseMode() >= VERBOSE_DEBUG) {
      getLogStream()
          << "CamClayStressPotential::completeVariableDeclaration: begin\n";
    }
    if (getVerboseMode() >= VERBOSE_DEBUG) {
      getLogStream()
          << "CamClayStressPotential::completeVariableDeclaration: end\n";
    }
  }

  void CamClayStressPotential::endTreatment(BehaviourDescription&,
                                            const AbstractBehaviourDSL&) const {
  }  // end of endTreatment

  std::vector<
      std::tuple<std::string, std::string, mfront::SupportedTypes::TypeFlag>>
  CamClayStressPotential::getStressDerivatives(
      const BehaviourDescription&) const {
    auto r = std::vector<std::tuple<std::string, std::string,
                                    mfront::SupportedTypes::TypeFlag>>{};
    r.push_back(std::make_tuple("theta * dsig_deel", std::string("eel"),
                                SupportedTypes::STENSOR));
    return r;
  }  // end of getStressDerivatives

  std::string CamClayStressPotential::generateImplicitEquationDerivatives(
      const BehaviourDescription& bd,
      const std::string& t,
      const std::string& v,
      const std::string& dfv_ds,
      const bool b) const {
    auto c = std::string{};
    const auto vf = SupportedTypes::getTypeFlag(t);
    c = "df" + v + "_ddeel += ";
    if (vf == SupportedTypes::SCALAR) {
      c += "(this->theta) * ((" + dfv_ds + ") | (this->dsig_deel));\n";
    } else if (vf == SupportedTypes::STENSOR) {
      c += "(this->theta) * (" + dfv_ds + ") * (this->dsig_deel);\n";
    } else {
      tfel::raise(
          "HookeStressPotential::generateImplicitEquationDerivatives: "
          "unsupported variable type");
    }
    return c;
}  // end of generateImplicitEquationDerivatives

  void CamClayStressPotential::computeElasticPrediction(
      BehaviourDescription&) const {}  // end of computeElasticPrediction

  std::string CamClayStressPotential::getStressNormalisationFactor(
      const BehaviourDescription&) const {
  }  // end of getStressNormalisationFactor

  std::string CamClayStressPotential::getEquivalentStressLowerBound(
      const BehaviourDescription&) const {
  }  // end of getEquivalentStressLowerBound

  std::vector<OptionDescription> CamClayStressPotential::getOptions(
      const BehaviourDescription& bd, const bool b) const {
    auto opts = std::vector<OptionDescription>{};
    //     opts.emplace_back(
    //         "fracture_stress", "fracture stress, assumed egal in all
    //         directions", OptionDescription::MATERIALPROPERTY,
    //         std::vector<std::string>{},
    //         std::vector<std::string>{"fracture_stresses"});
    return opts;
  }  // end of getOptions

  CamClayStressPotential::~CamClayStressPotential() = default;

}  // end of namespace mfront::bbrick
