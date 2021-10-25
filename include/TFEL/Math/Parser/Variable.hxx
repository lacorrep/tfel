/*!
 * \file   include/TFEL/Math/Parser/Variable.hxx
 * \brief
 *
 * \author Helfer Thomas
 * \date   02 oct 2007
 * \copyright Copyright (C) 2006-2018 CEA/DEN, EDF R&D. All rights
 * reserved.
 * This project is publicly released under either the GNU GPL Licence
 * or the CECILL-A licence. A copy of thoses licences are delivered
 * with the sources of TFEL. CEA or EDF may also distribute this
 * project under specific licensing conditions.
 */

#ifndef LIB_TFEL_VARIABLE_HXX_
#define LIB_TFEL_VARIABLE_HXX_

#include <vector>

#include "TFEL/Math/Parser/Expr.hxx"

namespace tfel {
  namespace math {

    namespace parser {

      struct Variable final : public Expr {
        Variable(const std::vector<double>&,
                 const std::vector<double>::size_type);
        virtual double getValue(void) const override;
        virtual void checkCyclicDependency(
            std::vector<std::string>&) const override;
        virtual std::shared_ptr<Expr> differentiate(
            const std::vector<double>::size_type,
            const std::vector<double>&) const override;
        virtual std::shared_ptr<Expr> clone(
            const std::vector<double>&) const override;
        virtual void getParametersNames(std::set<std::string>&) const override;
        virtual std::shared_ptr<Expr>
        createFunctionByChangingParametersIntoVariables(
            const std::vector<double>&,
            const std::vector<std::string>&,
            const std::map<std::string, std::vector<double>::size_type>&)
            const override;
        virtual std::shared_ptr<Expr> resolveDependencies(
            const std::vector<double>&) const override;

       private:
        Variable& operator=(const Variable&) = delete;
        Variable& operator=(Variable&&) = delete;
        const std::vector<double>& v;
        const std::vector<double>::size_type pos;
      };  // end of struct Variable

    }  // end of namespace parser

  }  // end of namespace math

}  // end of namespace tfel

#endif /* LIB_TFEL_VARIABLE_HXX_ */
