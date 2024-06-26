/*!
 * \file   BehaviourCodeGeneratorBase-IntegrationDataFile.cxx
 * \brief  This file implements the methods of the BehaviourCodeGeneratorBase
 * associated with the generation of the IntegrationData class
 * \author Thomas Helfer
 * \date   22/02/2024
 */

#include <ostream>
#include "TFEL/Raise.hxx"
#include "TFEL/UnicodeSupport/UnicodeSupport.hxx"
#include "TFEL/Utilities/CxxTokenizer.hxx"
#include "MFront/MFrontHeader.hxx"
#include "MFront/DSLUtilities.hxx"
#include "MFront/MFrontUtilities.hxx"
#include "MFront/MFrontDebugMode.hxx"
#include "MFront/PedanticMode.hxx"
#include "MFront/SupportedTypes.hxx"
#include "MFront/MFrontLogStream.hxx"
#include "MFront/FileDescription.hxx"
#include "MFront/BehaviourDescription.hxx"
#include "MFront/AbstractBehaviourInterface.hxx"
#include "MFront/BehaviourCodeGeneratorBase.hxx"

namespace mfront {

  std::string BehaviourCodeGeneratorBase::getIntegrationDataFileName() const {
    return "TFEL/Material/" + this->bd.getClassName() + "IntegrationData.hxx";
  }  // end of getIntegrationDataFileName

  void BehaviourCodeGeneratorBase::writeIntegrationDataMainVariablesSetters(
      std::ostream& os) const {
    this->checkIntegrationDataFile(os);
    for (const auto& i : this->interfaces) {
      i.second->writeIntegrationDataMainVariablesSetters(os, this->bd);
      os << '\n';
    }
  }  // end of writeIntegrationDataMainVariablesSetters

  void BehaviourCodeGeneratorBase::checkIntegrationDataFile(
      std::ostream& os) const {
    if ((!os) || (!os.good())) {
      this->throwRuntimeError(
          "BehaviourCodeGeneratorBase::checkIntegrationDataOutputFile",
          "output file is not valid");
    }
  }

  void BehaviourCodeGeneratorBase::writeIntegrationDataFileHeader(
      std::ostream& os) const {
    this->checkIntegrationDataFile(os);
    os << "/*!\n";
    os << "* \\file   " << this->getIntegrationDataFileName() << '\n';
    os << "* \\brief  "
       << "this file implements the " << this->bd.getClassName()
       << "IntegrationData"
       << " class.\n";
    os << "*         File generated by ";
    os << MFrontHeader::getVersionName() << " ";
    os << "version " << MFrontHeader::getVersionNumber();
    os << '\n';
    if (!this->fd.authorName.empty()) {
      os << "* \\author " << this->fd.authorName << '\n';
    }
    if (!this->fd.date.empty()) {
      os << "* \\date   " << this->fd.date << '\n';
    }
    os << " */\n\n";
  }

  void BehaviourCodeGeneratorBase::writeIntegrationDataFileHeaderBegin(
      std::ostream& os) const {
    this->checkIntegrationDataFile(os);
    os << "#ifndef LIB_TFELMATERIAL_" << makeUpperCase(this->bd.getClassName())
       << "_INTEGRATION_DATA_HXX\n"
       << "#define LIB_TFELMATERIAL_" << makeUpperCase(this->bd.getClassName())
       << "_INTEGRATION_DATA_HXX\n\n";
  }

  void BehaviourCodeGeneratorBase::writeIntegrationDataFileHeaderEnd(
      std::ostream& os) const {
    this->checkIntegrationDataFile(os);
    os << "#endif /* LIB_TFELMATERIAL_"
       << makeUpperCase(this->bd.getClassName())
       << "_INTEGRATION_DATA_HXX */\n";
  }

  void BehaviourCodeGeneratorBase::writeIntegrationDataStandardTFELIncludes(
      std::ostream& os) const {
    bool b1 = false;
    bool b2 = false;
    this->checkIntegrationDataFile(os);
    os << "#include<string>\n"
       << "#include<iostream>\n"
       << "#include<limits>\n"
       << "#include<stdexcept>\n"
       << "#include<algorithm>\n\n"
       << "#include\"TFEL/Raise.hxx\"\n"
       << "#include\"TFEL/PhysicalConstants.hxx\"\n"
       << "#include\"TFEL/Config/TFELConfig.hxx\"\n"
       << "#include\"TFEL/Config/TFELTypes.hxx\"\n"
       << "#include\"TFEL/TypeTraits/IsFundamentalNumericType.hxx\"\n"
       << "#include\"TFEL/TypeTraits/IsScalar.hxx\"\n"
       << "#include\"TFEL/TypeTraits/IsReal.hxx\"\n"
       << "#include\"TFEL/TypeTraits/Promote.hxx\"\n"
       << "#include\"TFEL/Math/General/IEEE754.hxx\"\n";
    this->bd.requiresTVectorOrVectorIncludes(b1, b2);
    if (b1) {
      os << "#include\"TFEL/Math/tvector.hxx\"\n"
         << "#include\"TFEL/Math/Vector/tvectorIO.hxx\"\n";
    }
    if (b2) {
      os << "#include\"TFEL/Math/vector.hxx\"\n";
    }
    os << "#include\"TFEL/Math/stensor.hxx\"\n"
       << "#include\"TFEL/Math/st2tost2.hxx\"\n";
    if (this->bd.getBehaviourType() ==
        BehaviourDescription::STANDARDFINITESTRAINBEHAVIOUR) {
      os << "#include\"TFEL/Math/tensor.hxx\"\n"
         << "#include\"TFEL/Math/t2tot2.hxx\"\n"
         << "#include\"TFEL/Math/t2tost2.hxx\"\n"
         << "#include\"TFEL/Math/st2tot2.hxx\"\n";
    }
  }

  void BehaviourCodeGeneratorBase::writeIntegrationDataDefaultMembers(
      std::ostream& os) const {
    this->checkIntegrationDataFile(os);
    os << "protected: \n\n";
    for (const auto& v : this->bd.getMainVariables()) {
      checkArraySizeOfMainVariables(
          "BehaviourCodeGeneratorBase::writeIntegrationDataDefaultMembers", v);
      if (Gradient::isIncrementKnown(v.first)) {
        os << "/*!\n"
           << " * \\brief " << v.first.name << " increment\n"
           << " */\n";
        if (v.first.arraySize == 1) {
          os << v.first.type << " d" << v.first.name << ";\n\n";
        } else {
          os << v.first.type << " d" << v.first.name << "[" << v.first.arraySize
             << "];\n\n";
        }
      } else {
        os << "/*!\n"
           << " * \\brief " << v.first.name << " at the end of the time step\n"
           << " */\n";
        if (v.first.arraySize == 1) {
          os << v.first.type << " " << v.first.name << "1;\n\n";
        } else {
          os << v.first.type << " " << v.first.name << "1[" << v.first.arraySize
             << "];\n\n";
        }
      }
    }
    os << "/*!\n"
       << " * \\brief time increment\n"
       << " */\n"
       << "time dt;\n\n";
  }

  void BehaviourCodeGeneratorBase::writeIntegrationDataTypeAliases(
      std::ostream& os) const {
    this->checkIntegrationDataFile(os);
    os << "static constexpr unsigned short TVectorSize = N;\n"
       << "typedef tfel::math::StensorDimeToSize<N> StensorDimeToSize;\n"
       << "static constexpr unsigned short StensorSize = "
       << "StensorDimeToSize::value;\n"
       << "typedef tfel::math::TensorDimeToSize<N> TensorDimeToSize;\n"
       << "static constexpr unsigned short TensorSize = "
       << "TensorDimeToSize::value;\n\n";
    this->writeTypeAliases(os);
    os << '\n';
  }

  void BehaviourCodeGeneratorBase::writeIntegrationDataDisabledConstructors(
      std::ostream& os) const {
    this->checkIntegrationDataFile(os);
  }

  void BehaviourCodeGeneratorBase::writeIntegrationDataConstructors(
      std::ostream& os, const Hypothesis h) const {
    const auto& md = this->bd.getBehaviourData(h);
    this->checkIntegrationDataFile(os);
    os << "/*!\n"
       << "* \\brief Default constructor\n"
       << "*/\n"
       << this->bd.getClassName() << "IntegrationData()\n"
       << "{}\n\n"
       << "/*!\n"
       << "* \\brief Copy constructor\n"
       << "*/\n"
       << this->bd.getClassName() << "IntegrationData(const "
       << this->bd.getClassName() << "IntegrationData& src)\n"
       << ": ";
    for (const auto& v : this->bd.getMainVariables()) {
      if (Gradient::isIncrementKnown(v.first)) {
        os << "d" << v.first.name << "(src.d" << v.first.name << "),\n";
      } else {
        os << v.first.name << "1(src." << v.first.name << "1),\n";
      }
    }
    os << "dt(src.dt)";
    for (const auto& v : md.getExternalStateVariables()) {
      os << ",\nd" << v.name << "(src.d" << v.name << ")";
    }
    os << "\n{}\n\n";
    // Creating constructor for external interfaces
    for (const auto& i : this->interfaces) {
      if (i.second->isBehaviourConstructorRequired(h, this->bd)) {
        i.second->writeIntegrationDataConstructor(os, h, this->bd);
      }
    }
  }

  void BehaviourCodeGeneratorBase::writeIntegrationDataScaleOperators(
      std::ostream& os, const Hypothesis h) const {
    const auto& md = this->bd.getBehaviourData(h);
    bool iknown = true;
    for (const auto& v : this->bd.getMainVariables()) {
      iknown = Gradient::isIncrementKnown(v.first);
    }
    this->checkIntegrationDataFile(os);
    os << "/*\n"
       << "* \\brief scale the integration data by a scalar.\n"
       << "*/\n"
       << "template<typename Scal>\n"
       << "TFEL_HOST_DEVICE " << this->bd.getClassName()
       << "IntegrationData&\n";
    if (!iknown) {
      if (this->bd.useQt()) {
        os << "scale(const " << this->bd.getClassName()
           << "BehaviourData<hypothesis, NumericType, use_qt>& behaviourData, "
              "const "
              "Scal time_scaling_factor)\n";
      } else {
        os << "scale(const " << this->bd.getClassName()
           << "BehaviourData<hypothesis, NumericType, false>& behaviourData, "
              "const Scal "
              "time_scaling_factor)\n";
      }
    } else {
      if (this->bd.useQt()) {
        os << "scale(const " << this->bd.getClassName()
           << "BehaviourData<hypothesis, NumericType, use_qt>&, const Scal "
              "time_scaling_factor)\n";
      } else {
        os << "scale(const " << this->bd.getClassName()
           << "BehaviourData<hypothesis, NumericType, false>&, const Scal "
              "time_scaling_factor)\n";
      }
    }
    os << "requires(tfel::typetraits::IsFundamentalNumericType<Scal>::cond&&\n"
       << "tfel::typetraits::IsScalar<Scal>::cond&&\n"
       << "tfel::typetraits::IsReal<Scal>::cond&&\n"
       << "std::is_same<NumericType,"
       << "typename tfel::typetraits::Promote"
       << "<NumericType,Scal>::type>::value){\n"
       << "this->dt   *= time_scaling_factor;\n";
    for (const auto& v : this->bd.getMainVariables()) {
      if (Gradient::isIncrementKnown(v.first)) {
        os << "this->d" << v.first.name << " *= time_scaling_factor;\n";
      } else {
        os << "this->" << v.first.name
           << "1 = (1-time_scaling_factor)*(behaviourData." << v.first.name
           << "0)+time_scaling_factor*(this->" << v.first.name << "1);\n";
      }
    }
    for (const auto& v : md.getExternalStateVariables()) {
      os << "this->d" << v.name << " *= time_scaling_factor;\n";
    }
    os << "return *this;\n"
       << "}\n\n";
  }  // end of writeIntegrationDataScaleOpeartors

  void
  BehaviourCodeGeneratorBase::writeIntegrationDataUpdateDrivingVariablesMethod(
      std::ostream& os) const {
    bool iknown = true;
    for (const auto& v : this->bd.getMainVariables()) {
      iknown = Gradient::isIncrementKnown(v.first);
    }
    this->checkIntegrationDataFile(os);
    os << "/*!\n"
       << "* \\brief update the driving variable in case of substepping.\n"
       << "*/\n"
       << "TFEL_HOST_DEVICE " << this->bd.getClassName()
       << "IntegrationData&\n";
    if (!iknown) {
      if (this->bd.useQt()) {
        os << "updateDrivingVariables(const " << this->bd.getClassName()
           << "BehaviourData<hypothesis, NumericType, use_qt>& "
              "behaviourData){\n";
      } else {
        os << "updateDrivingVariables(const " << this->bd.getClassName()
           << "BehaviourData<hypothesis, NumericType, false>& "
              "behaviourData){\n";
      }
    } else {
      if (this->bd.useQt()) {
        os << "updateDrivingVariables(const " << this->bd.getClassName()
           << "BehaviourData<hypothesis, NumericType, use_qt>&){\n";
      } else {
        os << "updateDrivingVariables(const " << this->bd.getClassName()
           << "BehaviourData<hypothesis, NumericType, false>&){\n";
      }
    }
    for (const auto& v : this->bd.getMainVariables()) {
      if (!Gradient::isIncrementKnown(v.first)) {
        os << "this->" << v.first.name << "1 += "
           << "this->" << v.first.name << "1 - (behaviourData." << v.first.name
           << "0);\n";
      }
    }
    os << "return *this;\n"
       << "}\n\n";
  }  // end of writeIntegrationUpdateDrivingVariablesMethod

  void BehaviourCodeGeneratorBase::writeIntegrationDataClassHeader(
      std::ostream& os) const {
    this->checkIntegrationDataFile(os);
    os << "/*!\n"
       << "* \\class " << this->bd.getClassName() << "IntegrationData\n"
       << "* \\brief This class implements the " << this->bd.getClassName()
       << "IntegrationData"
       << " behaviour.\n"
       << "* \\tparam N: space dimension.\n"
       << "* \\tparam NumericType: numerical type.\n"
       << "* \\tparam use_qt: conditional saying if quantities are use.\n";
    if (!this->fd.authorName.empty()) {
      os << "* \\author " << this->fd.authorName << '\n';
    }
    if (!this->fd.date.empty()) {
      os << "* \\date   " << this->fd.date << '\n';
    }
    os << "*/\n";
  }

  void BehaviourCodeGeneratorBase::writeIntegrationDataForwardDeclarations(
      std::ostream& os) const {
    this->checkIntegrationDataFile(os);
    os << "//! \\brief forward declaration\n"
       << "template<ModellingHypothesis::Hypothesis hypothesis, "
       << "typename NumericType, bool use_qt>\n"
       << "class " << this->bd.getClassName() << "IntegrationData;\n\n";
    if (this->bd.useQt()) {
      os << "//! \\brief forward declaration\n"
         << "template<ModellingHypothesis::Hypothesis hypothesis, "
         << "typename NumericType, bool use_qt>\n"
         << "std::ostream&\n operator <<(std::ostream&,"
         << "const " << this->bd.getClassName()
         << "IntegrationData<hypothesis, NumericType, use_qt>&);\n\n";
    } else {
      os << "//! \\brief forward declaration\n"
         << "template<ModellingHypothesis::Hypothesis hypothesis, "
         << "typename NumericType>\n"
         << "std::ostream&\n operator <<(std::ostream&,"
         << "const " << this->bd.getClassName()
         << "IntegrationData<hypothesis, NumericType, false>&);\n\n";
    }
    // maintenant, il faut déclarer toutes les spécialisations partielles...
    const auto& mh = this->bd.getModellingHypotheses();
    for (const auto& h : mh) {
      if (this->bd.hasSpecialisedMechanicalData(h)) {
        if (this->bd.useQt()) {
          os << "//! \\brief forward declaration\n"
             << "template<typename NumericType,bool use_qt>\n"
             << "std::ostream&\n operator <<(std::ostream&,"
             << "const " << this->bd.getClassName()
             << "IntegrationData<ModellingHypothesis::"
             << ModellingHypothesis::toUpperCaseString(h)
             << ", NumericType, use_qt>&);\n\n";
        } else {
          os << "//! \\brief forward declaration\n"
             << "template<typename NumericType>\n"
             << "std::ostream&\n operator <<(std::ostream&,"
             << "const " << this->bd.getClassName()
             << "IntegrationData<ModellingHypothesis::"
             << ModellingHypothesis::toUpperCaseString(h)
             << ", NumericType, false>&);\n\n";
        }
      }
    }
  }

  void BehaviourCodeGeneratorBase::writeIntegrationDataClassBegin(
      std::ostream& os, const Hypothesis h) const {
    this->checkIntegrationDataFile(os);
    if (h == ModellingHypothesis::UNDEFINEDHYPOTHESIS) {
      if (this->bd.useQt()) {
        os << "template<ModellingHypothesis::Hypothesis hypothesis, "
           << "typename NumericType, bool use_qt>\n";
        os << "class " << this->bd.getClassName() << "IntegrationData\n";
      } else {
        os << "template<ModellingHypothesis::Hypothesis hypothesis, "
           << "typename NumericType>\n";
        os << "class " << this->bd.getClassName()
           << "IntegrationData<hypothesis, NumericType, false>\n";
      }
    } else {
      if (this->bd.useQt()) {
        os << "template<typename NumericType,bool use_qt>\n";
        os << "class " << this->bd.getClassName()
           << "IntegrationData<ModellingHypothesis::"
           << ModellingHypothesis::toUpperCaseString(h)
           << ", NumericType, use_qt>\n";
      } else {
        os << "template<typename NumericType>\n";
        os << "class " << this->bd.getClassName()
           << "IntegrationData<ModellingHypothesis::"
           << ModellingHypothesis::toUpperCaseString(h)
           << ", NumericType, false>\n";
      }
    }
    os << "{\n\n";
    if (h != ModellingHypothesis::UNDEFINEDHYPOTHESIS) {
      os << "static constexpr ModellingHypothesis::Hypothesis hypothesis = "
         << "ModellingHypothesis::" << ModellingHypothesis::toUpperCaseString(h)
         << ";\n";
    }
    os << "static constexpr unsigned short N = "
          "ModellingHypothesisToSpaceDimension<hypothesis>::value;\n";
    os << "static_assert(N==1||N==2||N==3);\n";
    os << "static_assert(tfel::typetraits::"
       << "IsFundamentalNumericType<NumericType>::cond);\n";
    os << "static_assert(tfel::typetraits::IsReal<NumericType>::cond);\n\n";
    os << "friend std::ostream& operator<< <>(std::ostream&,const ";
    os << this->bd.getClassName() << "IntegrationData&);\n\n";
  }

  void BehaviourCodeGeneratorBase::writeIntegrationDataOutputOperator(
      std::ostream& os, const Hypothesis h) const {
    const auto& md = this->bd.getBehaviourData(h);
    this->checkBehaviourFile(os);
    if (h == ModellingHypothesis::UNDEFINEDHYPOTHESIS) {
      if (this->bd.useQt()) {
        os << "template<ModellingHypothesis::Hypothesis hypothesis, "
           << "typename NumericType,bool use_qt>\n"
           << "std::ostream&\n"
           << "operator <<(std::ostream& os,"
           << "const " << this->bd.getClassName()
           << "IntegrationData<hypothesis, NumericType, use_qt>& b)\n";
      } else {
        os << "template<ModellingHypothesis::Hypothesis hypothesis, "
           << "typename NumericType>\n"
           << "std::ostream&\n"
           << "operator <<(std::ostream& os,"
           << "const " << this->bd.getClassName()
           << "IntegrationData<hypothesis, NumericType, false>& b)\n";
      }
    } else {
      if (this->bd.useQt()) {
        os << "template<typename NumericType,bool use_qt>\n"
           << "std::ostream&\n"
           << "operator <<(std::ostream& os,"
           << "const " << this->bd.getClassName()
           << "IntegrationData<ModellingHypothesis::"
           << ModellingHypothesis::toUpperCaseString(h)
           << ", NumericType, use_qt>& b)\n";
      } else {
        os << "template<typename NumericType>\n"
           << "std::ostream&\n"
           << "operator <<(std::ostream& os,"
           << "const " << this->bd.getClassName()
           << "IntegrationData<ModellingHypothesis::"
           << ModellingHypothesis::toUpperCaseString(h)
           << ", NumericType, false>& b)\n";
      }
    }
    os << "{\n";
    for (const auto& v : this->bd.getMainVariables()) {
      const auto getArrayIndex = [&v](const auto idx) -> std::string {
        if (v.first.arraySize == 1) {
          return "";
        }
        return '[' + std::to_string(idx) + ']';
      };
      for (unsigned short idx = 0; idx != v.first.arraySize; ++idx) {
        const auto aidx = getArrayIndex(idx);
        if (Gradient::isIncrementKnown(v.first)) {
          if (getUnicodeOutputOption()) {
            os << "os << \"\u0394" << displayName(v.first) << aidx
               << " : \" << b.d" << v.first.name << aidx << " << '\\n';\n";
          } else {
            os << "os << \"d" << displayName(v.first) << aidx << " : \" << b.d"
               << v.first.name << aidx << " << '\\n';\n";
          }
        } else {
          if (getUnicodeOutputOption()) {
            os << "os << \"" << displayName(v.first) << "\u2081" << aidx
               << " : \" << b." << v.first.name << "1" << aidx
               << " << '\\n';\n";
          } else {
            os << "os << \"" << displayName(v.first) << "1" << aidx
               << " : \" << b." << v.first.name << "1" << aidx
               << " << '\\n';\n";
          }
        }
        os << "os << \"" << displayName(v.second) << aidx << " : \" << b."
           << v.second.name << aidx << " << '\\n';\n";
      }
    }
    if (getUnicodeOutputOption()) {
      os << "os << \"\u0394t : \" << b.dt << '\\n';\n";
    } else {
      os << "os << \"dt : \" << b.dt << '\\n';\n";
    }
    for (const auto& ev : md.getExternalStateVariables()) {
      if (getUnicodeOutputOption()) {
        os << "os << \"\u0394" << displayName(ev) << " : \" << b.d" << ev.name
           << " << '\\n';\n";
      } else {
        os << "os << \"d" << displayName(ev) << " : \" << b.d" << ev.name
           << " << '\\n';\n";
      }
    }
    os << "return os;\n";
    os << "}\n\n";
  }  // end of writeIntegrationDataOutputOperator

  void BehaviourCodeGeneratorBase::writeIntegrationDataClassEnd(
      std::ostream& os) const {
    this->checkIntegrationDataFile(os);
    os << "}; // end of " << this->bd.getClassName() << "IntegrationData"
       << "class\n\n";
  }

  void BehaviourCodeGeneratorBase::writeIntegrationDataExternalStateVariables(
      std::ostream& os, const Hypothesis h) const {
    const auto& md = this->bd.getBehaviourData(h);
    this->checkIntegrationDataFile(os);
    this->writeVariablesDeclarations(os, md.getExternalStateVariables(), "d",
                                     "", this->fd.fileName, false);
  }

  void BehaviourCodeGeneratorBase::writeIntegrationDataFileBegin(
      std::ostream& os) const {
    this->checkIntegrationDataFile(os);
    this->writeIntegrationDataFileHeader(os);
    this->writeIntegrationDataFileHeaderBegin(os);
    this->writeIntegrationDataStandardTFELIncludes(os);
    this->writeIncludes(os);
    // includes specific to interfaces
    for (const auto& i : this->interfaces) {
      i.second->writeInterfaceSpecificIncludes(os, this->bd);
    }
    this->writeNamespaceBegin(os);
    this->writeIntegrationDataForwardDeclarations(os);
  }  // end of writeIntegrationDataFile

  void BehaviourCodeGeneratorBase::writeIntegrationDataClass(
      std::ostream& os, const Hypothesis h) const {
    this->checkIntegrationDataFile(os);
    this->writeIntegrationDataClassBegin(os, h);
    this->writeIntegrationDataTypeAliases(os);
    this->writeIntegrationDataDefaultMembers(os);
    this->writeIntegrationDataExternalStateVariables(os, h);
    this->writeIntegrationDataDisabledConstructors(os);
    os << "public:\n\n";
    this->writeIntegrationDataConstructors(os, h);
    this->writeIntegrationDataMainVariablesSetters(os);
    this->writeIntegrationDataScaleOperators(os, h);
    this->writeIntegrationDataUpdateDrivingVariablesMethod(os);
    this->writeIntegrationDataClassEnd(os);
    this->writeIntegrationDataOutputOperator(os, h);
  }

  void BehaviourCodeGeneratorBase::writeIntegrationDataFileEnd(
      std::ostream& os) const {
    this->checkIntegrationDataFile(os);
    this->writeNamespaceEnd(os);
    this->writeIntegrationDataFileHeaderEnd(os);
  }  // end of writeIntegrationDataFileEnd

}  // end of namespace mfront