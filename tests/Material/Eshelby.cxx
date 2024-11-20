/*!
 * \file   tests/Material/Eshelby.cxx
 * \brief
 * \author Thomas Helfer
 * \date   22/06/2021
 * \copyright Copyright (C) 2006-2018 CEA/DEN, EDF R&D. All rights
 * reserved.
 * This project is publicly released under either the GNU GPL Licence with
 * linking exception or the CECILL-A licence. A copy of thoses licences are
 * delivered with the sources of TFEL. CEA or EDF may also distribute this
 * project under specific licensing conditions.
 */

#ifdef NDEBUG
#undef NDEBUG
#endif NDEBUG

#include <limits>
#include <cstdlib>
#include <iostream>
#include "TFEL/Config/TFELTypes.hxx"
#include "TFEL/Math/qt.hxx"
#include "TFEL/Material/Eshelby.hxx"
#include "TFEL/Tests/TestCase.hxx"
#include "TFEL/Tests/TestProxy.hxx"
#include "TFEL/Tests/TestManager.hxx"
#include "TFEL/Material/StiffnessTensor.hxx"

template <typename T>
static constexpr T my_abs(const T& v) noexcept {
  return v < T(0) ? -v : v;
}

struct EshelbyTest final : public tfel::tests::TestCase {
  EshelbyTest()
      : tfel::tests::TestCase("TFEL/Material", "Eshelby") {}  // end of EshelbyTest
  
  tfel::tests::TestResult execute() override {
    this->template test_Eshelby_2d<double, true>();
    this->template compile_Eshelby_tensors<double, true>();
    this->template errors_Eshelby_tensors<double, true>();
    this->template test_Eshelby_tensors<double, true>();
    this->template test_Eshelby_limits<float, true>();
    this->template test_Eshelby_limits<double, true>();
    this->template test_Eshelby_limits<long double, true>();
    this->template compile_localisation_tensors<double, true>();
    this->template errors_localisation_tensors<double, true>();
    this->template test_localisation_tensors<double, true>();
    //this->template test1<long double, false>();
    //this->template test1<float, true>();
    //this->template test1<double, true>();
    //this->template test1<long double, true>();
    return this->result;
  }


 private:
  template <typename NumericType, bool use_qt>
  void test_Eshelby_2d() {
    using lg =
        typename tfel::config::Types<1u, NumericType, use_qt>::length;
    using real = NumericType;
    static constexpr auto eps = std::numeric_limits<real>::epsilon();
    const auto nu = real{0.3};
    
    //These functions must return the same thing
    using namespace tfel::material;
    {const auto S1 = computeCircularCylinderEshelbyTensor(nu);
    const auto S2 = computeEllipticCylinderEshelbyTensor(nu,real{1});
    bool value = true;
    for (int i :{0,1,2,3}){
    	for (int j:{0,1,2,3}){
    		value = value and (std::abs(S1(i,j)-S2(i,j))<eps);
    		//std::cout << S1(i,j) << " " << S2(i,j) << " " << value << '\n';
    	};
    };
    if (value){
    std::cout << "Eshelby 2d ok" << '\n';
    }
    else{std::cout << "Eshelby 2d does not work" << '\n';};
    }
 };
 
//tests compilation of the Eshelby tensor functions
private:
  template <typename NumericType, bool use_qt>
  void compile_Eshelby_tensors() {
    using lg =
        typename tfel::config::Types<1u, NumericType, use_qt>::length;
    using real = NumericType;
    const auto nu = real{0.3};

    using namespace tfel::material;
    {const auto S = computeSphereEshelbyTensor(nu);}
    
    {const auto S1 = computeAxisymmetricalEshelbyTensor(nu,real{0.5});
    const auto S2 = computeAxisymmetricalEshelbyTensor(nu,real{10});
    const auto S3 = computeAxisymmetricalEshelbyTensor(nu,real{1});
    }
    
    {const auto S1 = computeEshelbyTensor(nu,lg{1},lg{3},lg{2});
    const auto S2 = computeEshelbyTensor(nu,lg{1},lg{1},lg{2});
    const auto S3 = computeEshelbyTensor(nu,lg{1},lg{1},lg{1});
    }
 };
    
//must return an error
private:
  template <typename NumericType, bool use_qt>
  void errors_Eshelby_tensors() {
    using lg =
        typename tfel::config::Types<1u, NumericType, use_qt>::length;
    using real = NumericType;
    const auto nu = real{0.3};
    
    using namespace tfel::material;
    {//const auto S1 = computeSphereEshelbyTensor(real{1});
    //const auto S2 = computeAxisymmetricalEshelbyTensor(nu,real{0});
    //const auto S3 = computeAxisymmetricalEshelbyTensor(nu,real{-10});
    //const auto S4 = computeEshelbyTensor<real,lg>(nu,lg{-1},lg{3},lg{2});
    //const auto S5 = computeEshelbyTensor<real,lg>(nu,lg{-1},lg{-1},lg{1});
    }
  };
    
 
  private:
  template <typename NumericType, bool use_qt>
  void test_Eshelby_tensors() {
    using lg =
        typename tfel::config::Types<1u, NumericType, use_qt>::length;
    using real = NumericType;
    static constexpr auto eps = std::numeric_limits<real>::epsilon();
    const auto nu = real{0.3};
    
    
    using namespace tfel::material;
     //AxisymmetricalEshelbyTensor with e=1 is equal to SphereEshelbyTensor and also equal to EshelbyTensor(2,2,2)
    {const auto S1 = computeSphereEshelbyTensor(nu);
    const auto S2 = computeAxisymmetricalEshelbyTensor(nu,real{1});
    const auto S3 = computeEshelbyTensor(nu,lg{2},lg{2},lg{2});
    bool value = true;
    for (int i :{0,1,2,3,4,5}){
    	for (int j:{0,1,2,3,4,5}){
    		value = value and (std::abs(S1(i,j)-S2(i,j))<eps);
    		//std::cout << S1(i,j) << " " << S2(i,j) << " " << value << '\n';
    		value = value and (std::abs(S1(i,j)-S3(i,j))<eps);
    		//std::cout << "13" << value << '\n';
    	};
    };
   if (value){
    std::cout << "Eshelby 3d ok" << '\n';
    }
    else{std::cout << "Eshelby 3d does not work" << '\n';};
    }
    
    //AxisymmetricalEshelbyTensor with e=10 is equal to EshelbyTensor(30,3,3) or EshelbyTensor(3,3,30)
    {const auto S1 = computeAxisymmetricalEshelbyTensor(nu,real{10});
    const auto S2 = computeEshelbyTensor(nu,lg{30},lg{3},lg{3});
    const auto S3 = computeEshelbyTensor(nu,lg{3},lg{3},lg{30});
    bool value = true;
    for (int i :{0,1,2,3,4,5}){
    	for (int j:{0,1,2,3,4,5}){
    		value = value and (std::abs(S1(i,j)-S2(i,j))<eps);
    		value = value and (std::abs(S1(i,j)-S3(i,j))<eps);
    	};
    };
    if (value){
    std::cout << "Eshelby 3d bis ok" << '\n';
    }
    else{std::cout << "Eshelby 3d bis does not work" << '\n';};
    }
    };
    
    
     private:
  template <typename NumericType, bool use_qt>
  void test_Eshelby_limits() {
    using lg =
        typename tfel::config::Types<1u, NumericType, use_qt>::length;
    using real = NumericType;
    static constexpr auto eps = std::numeric_limits<real>::epsilon();
    const auto nu = real{0.3};
    
    
    using namespace tfel::material;    
     //AxisymmetricalEshelbyTensor when e is near 1 must be near SphereEshelbyTensor (there is a numerical instability that we propose to manage)
    {const auto S1 = computeSphereEshelbyTensor(nu);
    tfel::math::st2tost2<3u,real> S2;
    if (std::numeric_limits<float>::epsilon()==eps){
    	S2 = computeAxisymmetricalEshelbyTensor(nu,real{1.001});
    }
    else if (std::numeric_limits<double>::epsilon()==eps){
    	S2 = computeAxisymmetricalEshelbyTensor(nu,real{1.000001});
    }
    else if (std::numeric_limits<long double>::epsilon()==eps){
    	S2= computeAxisymmetricalEshelbyTensor(nu,real{1.0000001});
    };
    bool value = true;
    for (int i :{0,1,2,3,4,5}){
    	for (int j:{0,1,2,3,4,5}){
    		value = value and (std::abs(S1(i,j)-S2(i,j))<eps);
    		//std::cout << S1(i,j) << " " << S2(i,j) << " " << value << '\n';
    	};
    };
    if (value){
    std::cout << "Eshelby 3d near sphere ok" << '\n';
    }
    else{std::cout << "Eshelby 3d near sphere does not work" << '\n';};
    }
    
    
    //EshelbyTensor when a is near b must be near AxisymmetricalEshelbyTensor (there is a numerical instability that we propose to manage)
    {const auto S1 = computeAxisymmetricalEshelbyTensor(nu,real{10});
    tfel::math::st2tost2<3u,real> S2;
    if (std::numeric_limits<float>::epsilon()==eps){
    	S2 = computeEshelbyTensor(nu,lg{1.05},lg{1},lg{10});
    }
    else if (std::numeric_limits<double>::epsilon()==eps){
    	S2 = computeEshelbyTensor(nu,lg{1.0005},lg{1},lg{10});
    }
    else if (std::numeric_limits<long double>::epsilon()==eps){
    	S2= computeEshelbyTensor(nu,lg{1.00005},lg{1},lg{10});
    };

    bool value = true;
    for (int i :{0,1,2,3,4,5}){
    	for (int j:{0,1,2,3,4,5}){
    		value = value and (std::abs(S1(i,j)-S2(i,j))<eps);
    		//std::cout << S1(i,j) << " " << S2(i,j) << " " << value << '\n';
    	};
    };
    if (value){
    std::cout << "Eshelby 3d near axisymmetry ok" << '\n';
    }
    else{std::cout << "Eshelby 3d near axisymmetry does not work" << '\n';};
    }
    
 };
 
 
 //tests compilation of localisation tensor functions
 private:
  template <typename NumericType, bool use_qt>
  void compile_localisation_tensors() {
    using stress =
        typename tfel::config::Types<1u, NumericType, use_qt>::stress;
    using lg =
        typename tfel::config::Types<1u, NumericType, use_qt>::length;
    using real = NumericType;
    const auto young = stress{1e9};
    const auto nu = real{0.3};
    const auto young_i = stress{150e9};
    const auto nu_i = real{0.3};
    
    using namespace tfel::material;
    const tfel::math::tvector<3u,real> n_a = {0.,0.,1.};
    const tfel::math::tvector<3u,real> n_b = {1.,0.,0.};
    const auto a =lg{1};
    const auto b =lg{3};
    const auto c =lg{0.2};
    
    {const auto A1 = computeSphereLocalisationTensor<real,stress>(young,nu,young_i,nu_i);
    const auto A2 = computeAxisymmetricalEllipsoidLocalisationTensor<real,stress>(young,nu,young_i,nu_i,n_a,a/b);
    const auto A3 = computeEllipsoidLocalisationTensor<real,stress,lg>(young,nu,young_i,nu_i,n_a,a,n_b,b,c);
    } 
  };
  
  
 //must return a warning
 private:
  template <typename NumericType, bool use_qt>
  void errors_localisation_tensors() {
    using stress =
        typename tfel::config::Types<1u, NumericType, use_qt>::stress;
    using lg =
        typename tfel::config::Types<1u, NumericType, use_qt>::length;
    using real = NumericType;
    const auto young = stress{1e9};
    const auto nu = real{0.3};
    const auto young_i = stress{150e9};
    const auto nu_i = real{0.3};
    
    const tfel::math::tvector<3u,real> n_a = {0.,0.,1.};
    const tfel::math::tvector<3u,real> n_b = {1.,0.,0.};
    const tfel::math::tvector<3u,real> n_0 = {0.,0.,0.};
    const tfel::math::tvector<3u,real> n_ = {0.,std::sqrt(2)/2,std::sqrt(2)/2};
    const tfel::math::tvector<3u,real> n__ = {0.,0.,0.};

    const auto a =lg{1};
    const auto b =lg{3};
    const auto c =lg{0.2};
    
    using namespace tfel::material;
    {//const auto A1 = computeSphereLocalisationTensor<real,stress>(young,real{1},young_i,nu_i);
    //const auto A2 = computeAxisymmetricalEllipsoidLocalisationTensor<real,stress>(young,nu,young_i,nu_i,n_a,real{0});
    //const auto A3 = computeAxisymmetricalEllipsoidLocalisationTensor<real,stress>(young,nu,young_i,nu_i,n_0,real{1});
    //const auto A4 = computeAxisymmetricalEllipsoidLocalisationTensor<real,stress>(stress{-1},nu,young_i,nu_i,n_a,real{1});
    //const auto A5 = computeEllipsoidLocalisationTensor<real,stress,lg>(young,nu,young_i,nu_i,n_a,a,n_b,lg{0},c);
    //const auto A6 = computeEllipsoidLocalisationTensor<real,stress,lg>(young,nu,young_i,nu_i,n_a,a,n_,b,c);
    //const auto A7 = computeEllipsoidLocalisationTensor<real,stress,lg>(young,nu,young_i,nu_i,n_a,a,n__,b,c);
    }
  };
  
  
//These functions must return the same thing
  private:
  template <typename NumericType, bool use_qt>
  void test_localisation_tensors() {
    using stress =
        typename tfel::config::Types<1u, NumericType, use_qt>::stress;
    using lg =
        typename tfel::config::Types<1u, NumericType, use_qt>::length;
    using real = NumericType;
    static constexpr auto eps = std::numeric_limits<real>::epsilon();
    const auto young = stress{1e9};
    const auto nu = real{0.3};
    const auto young_i = stress{150e9};
    const auto nu_i = real{0.3};
    
    const tfel::math::tvector<3u,real> n_a = {0.,0.,1.};
    const tfel::math::tvector<3u,real> n_b = {1.,0.,0.};
    
    using namespace tfel::material;
    {const auto A1 = computeSphereLocalisationTensor<real,stress>(young,nu,young_i,nu_i);
    const auto A2 = computeAxisymmetricalEllipsoidLocalisationTensor<real,stress>(young,nu,young_i,nu_i,n_a,1);
    const auto A3 = computeEllipsoidLocalisationTensor<real,stress,lg>(young,nu,young_i,nu_i,n_a,lg{2},n_b,lg{2.00000001},lg{2.00001});
    bool value = true;
    for (int i :{0,1,2,3,4,5}){
    	for (int j:{0,1,2,3,4,5}){
    		value = value and (std::abs(A1(i,j)-A2(i,j))<eps);
    		value = value and (std::abs(A1(i,j)-A3(i,j))<eps);
    	};
    };
    
    if (value){
    std::cout << "Localisation 3d ok" << '\n';
    }
    else{std::cout << "Localisation 3d does not work" << '\n';};
    }
    {const auto A1 = computeAxisymmetricalEllipsoidLocalisationTensor<real,stress>(young,nu,young_i,nu_i,n_a,lg{20}/lg{2.0001});
    const auto A2 = computeEllipsoidLocalisationTensor<real,stress,lg>(young,nu,young_i,nu_i,n_a,lg{20},n_b,lg{2},lg{2.0001});
    bool value = true;
    for (int i :{0,1,2,3,4,5}){
    	for (int j:{0,1,2,3,4,5}){
    		value = value and (std::abs(A1(i,j)-A2(i,j))<eps);
    		//std::cout << A1(i,j) <<" " << i<< " " << j<< " " << A2(i,j) << value << '\n';
    	};
    };
    if (value){
    std::cout <<"Localisation 3d bis ok"<<'\n';
    }
    else{std::cout << "Localisation 3d bis does not work" << '\n';};
    }

  };
  
  
};  // end of struct EshelbyTest

TFEL_TESTS_GENERATE_PROXY(EshelbyTest, "Eshelby");

/* coverity [UNCAUGHT_EXCEPT]*/
int main() {
  auto& m = tfel::tests::TestManager::getTestManager();
  m.addTestOutput(std::cout);
  m.addXMLTestOutput("Eshelby.xml");
  return m.execute().success() ? EXIT_SUCCESS : EXIT_FAILURE;
}  // end of main
