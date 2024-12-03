/*!
 * \file   include/TFEL/Material/EshelbyAnisotropic.ixx
 * \author Antoine Martin
 * \date   18 November 2024
 * \brief  This file defines the Eshelby tensor for an ellipsoidal inclusion embedded in an anisotropic matrix.
 * \copyright Copyright (C) 2006-2018 CEA/DEN, EDF R&D. All rights
 * reserved.
 * This project is publicly released under either the GNU GPL Licence
 * or the CECILL-A licence. A copy of thoses licences are delivered
 * with the sources of TFEL. CEA or EDF may also distribute this
 * project under specific licensing conditions.
 */

#ifndef LIB_TFEL_MATERIAL_ESHELBYANISOTROPIC_IXX
#define LIB_TFEL_MATERIAL_ESHELBYANISOTROPIC_IXX

#include <cmath>
#include <numbers>
#include <stdexcept>
#include<typeinfo>
#include <boost/math/quadrature/trapezoidal.hpp>

namespace tfel::material
{

namespace homogenization{
     namespace elasticity{
     
	namespace internals{
	
		template<typename real>
		TFEL_HOST_DEVICE auto dblintegrate(const std::function<real(const real&,const real&)> f, const real a, const real b, const real c, const real d){
			const auto f_ = [f,c,d](const real& x){return boost::math::quadrature::trapezoidal<std::function<real(real)>,real>([x,f](const real& y){return f(x,y);},c,d);};
			//const auto f_ = [f,c,d](const real& x){return integrate_on_y<real,F,f,c,d>(x);};
			return boost::math::quadrature::trapezoidal<std::function<real(real)>,real>(f_,a,b);
		};
	
		
		TFEL_HOST_DEVICE int vi(int i, int j){
				if ((i==0) and (j==0)){return 0;}
				else if ((i==1) and (j==1)){return 1;}
				else if ((i==2) and (j==2)){return 2;}
				else if (((i==0) and (j==1))||((i==1) and (j==0))){return 3;}
				else if (((i==0) and (j==2))||((i==2) and (j==0))){return 4;}
				else if (((i==1) and (j==2))||((i==2) and (j==1))){return 5;}
			};
		
		template<typename Type,typename real>
		TFEL_HOST_DEVICE Type getSt4(const tfel::math::st2tost2<3u,Type>& A, int i, int j, int k, int l){
				const int I = vi(i,j);
				const int J = vi(k,l);
				real fac = real(1);
				if (I > 2){fac/=std::sqrt(2);};
				if (J > 2){fac/=std::sqrt(2);};
				return fac*A(I,J);
			};
			
		template<typename Type,typename real>
		TFEL_HOST_DEVICE void setSt4(tfel::math::st2tost2<3u,Type>& A, int i, int j, int k, int l,Type Aijkl){
				const int I = vi(i,j);
				const int J = vi(k,l);
				real fac = real(1);
				if (I > 2){fac*=std::sqrt(2);};
				if (J > 2){fac*=std::sqrt(2);};
				A(I,J)=fac*Aijkl;
				if (I!=J){A(J,I)=A(I,J);};
			};
			
		template<typename Type,typename real>
		TFEL_HOST_DEVICE void setStensor(tfel::math::stensor<3u,Type>& A, int i, int j,Type Aij){
				const int I = vi(i,j);
				real fac = real(1);
				if (I > 2){fac*=std::sqrt(2);};
				A(I)=fac*Aij;
			};
			
		template<typename Type,typename real>
		TFEL_HOST_DEVICE Type getStensor(const tfel::math::stensor<3u,Type>& A, int i, int j){
				const int I = vi(i,j);
				real fac = real(1);
				if (I > 2){fac/=std::sqrt(2);};
				return fac*A(I);
		};
				
		template<typename real,typename StressType>
		TFEL_HOST_DEVICE tfel::math::stensor<3u,real> Acoustic(const tfel::math::st2tost2<3u,StressType>& C, const tfel::math::tvector<3u,real>& X){
			tfel::math::stensor<3u,real> A;
			for(int i=0;i<3;i++)
			for(int k=i;k<3;k++){
				real A_ik = real(0);
				for(int j=0;j<3;j++)
				for(int l=0;l<3;l++){
				A_ik+= real((getSt4<StressType,real>(C,i,j,k,l))/StressType(1)*X[j]*X[l]);
				}
				setStensor<real,real>(A,i,k,A_ik);
			}
			return A;
		};
		
		template<typename real,typename StressType, typename LengthType>
		TFEL_HOST_DEVICE real p_ijkl(const tfel::math::st2tost2<3u,StressType>& C, const real theta, const real phi, const LengthType& a, const LengthType& b, const LengthType& c, const int& i, const int& j, const int& k, const int& l){
			const real pi = std::numbers::pi_v<real>;
			const tfel::math::tvector<3u,real> X={std::sin(theta)*std::cos(phi)/a*LengthType(1),std::sin(theta)*std::sin(phi)/b*LengthType(1),std::cos(theta)/c*LengthType(1)};
			const auto A_inv=tfel::math::invert(Acoustic<real,StressType>(C,X));
			const auto Mijkl=(getStensor<real,real>(A_inv,j,k)*X[i]*X[l]+getStensor<real,real>(A_inv,i,k)*X[j]*X[l]+getStensor<real,real>(A_inv,j,l)*X[i]*X[k]+getStensor<real,real>(A_inv,i,l)*X[j]*X[k])/4;
			return Mijkl*std::sin(theta)/4/pi;	
		};
		
		
	};//end of namespace internals


	template<typename real,typename StressType, typename LengthType>
	TFEL_HOST_DEVICE tfel::math::st2tost2<3u,typename tfel::math::invert_type<StressType>> computeAnisotropicHillTensor(const tfel::math::st2tost2<3u,StressType>& C,
											       const LengthType& a, const LengthType& b, const LengthType& c){
		if (not((a>LengthType{0}) and (b>LengthType{0}) and (c>LengthType{0}))){
			tfel::reportContractViolation("a<=0 or b<=0 or c<=0");
		};
		const std::array<LengthType,3> abc_={a,b,c};
		const auto sig=internals::sortEllipsoidLengths<LengthType>(a,b,c);
		const auto a_=abc_[sig[0]];
		const auto b_=abc_[sig[1]];
		const auto c_=abc_[sig[2]];
		const real pi = std::numbers::pi_v<real>;
		const real zero = real(0);
		using compliance = typename tfel::math::invert_type<StressType>;
		tfel::math::st2tost2<3u,compliance> P;
		for (int i=0;i<3;i++)
		for (int j=i;j<3;j++)
		for (int k=0;k<3;k++)
		for (int l=k;l<3;l++){
			const int I = internals::vi(i,j);
			const int J = internals::vi(k,l);
			if (I<=J){
				const auto p_ = [C,a_,b_,c_,i,j,k,l] (const real& theta, const real& phi){return internals::p_ijkl<real,StressType,LengthType>(C,theta,phi,a_,b_,c_,i,j,k,l);};
				const auto int_p = compliance(internals::dblintegrate<real>(p_,zero,pi,zero,2*pi));
				internals::setSt4<compliance,real>(P,i,j,k,l,int_p);
			}
		}
		return P;
	};
	
	
	template<typename real,typename StressType, typename LengthType>
	TFEL_HOST_DEVICE tfel::math::st2tost2<3u,real> computeAnisotropicEshelbyTensor(const tfel::math::st2tost2<3u,StressType>& C,
											       const LengthType& a, const LengthType& b, const LengthType& c){
		return computeAnisotropicHillTensor<real,StressType,LengthType>(C,a,b,c)*C;
	};
	
	
	template <typename real, typename StressType, typename LengthType>
	TFEL_HOST_DEVICE tfel::math::st2tost2<3u,real> computeAnisotropicLocalisationTensor(const tfel::math::st2tost2<3u,StressType>& C_0_glob, const tfel::math::st2tost2<3u,StressType>& C_i_loc,
											const tfel::math::tvector<3u,real>& n_a,const LengthType& a, const tfel::math::tvector<3u,real>& n_b,
											const LengthType& b, const LengthType& c){
		
		if (not((a>LengthType{0}) and (b>LengthType{0}) and (c>LengthType{0}))){
			tfel::reportContractViolation("a<=0 or b<=0 or c<=0");
		};
		if (not(tfel::math::ieee754::fpclassify(tfel::math::VectorVectorDotProduct::exe<real,tfel::math::tvector<3u,real>,tfel::math::tvector<3u,real>>(n_a,n_b)) == FP_ZERO)){
			tfel::reportContractViolation("n_a and n_b not normals");
		};
		if (tfel::math::ieee754::fpclassify(norm(n_a)) == FP_ZERO){
			tfel::reportContractViolation("n_a is null");
		};
		if (tfel::math::ieee754::fpclassify(norm(n_b)) == FP_ZERO){
			tfel::reportContractViolation("n_b is null");
		};
		const auto n_a_=n_a/norm(n_a);
    		const auto n_b_=n_b/norm(n_b);
		const auto n_c_=tfel::math::cross_product<real>(n_a_,n_b_);
		const std::array<LengthType,3> abc_={a,b,c};
		const auto sig=internals::sortEllipsoidLengths<LengthType>(a,b,c);
		using namespace tfel::math;
		const std::array<tfel::math::tvector<3u,real>,3> nabc_={n_a_,n_b_,n_c_};
		const auto n_1=nabc_[sig[0]];
		const auto n_2=nabc_[sig[1]];
		const auto n_3=cross_product<real>(n_1,n_2);
		const rotation_matrix<real> r_glob_sorted={n_1[0],n_2[0],n_3[0],
					       n_1[1],n_2[1],n_3[1],
					       n_1[2],n_2[2],n_3[2]};
		const rotation_matrix<real> r_glob_loc={n_a_[0],n_b_[0],n_c_[0],
					       n_a_[1],n_b_[1],n_c_[1],
					       n_a_[2],n_b_[2],n_c_[2]};
		const rotation_matrix<real> r_sorted_glob = transpose(r_glob_sorted);
		const rotation_matrix<real> r_loc_glob = transpose(r_glob_loc);
		const auto C_0_sorted=StressType(1)*change_basis(C_0_glob/StressType(1),r_glob_sorted);
		const auto P_0_sorted = computeAnisotropicHillTensor<real,StressType,LengthType>(C_0_sorted,abc_[sig[0]],abc_[sig[1]],abc_[sig[2]]);
		const auto P_0_glob = change_basis(P_0_sorted*StressType(1),r_sorted_glob)/StressType(1);
		const auto C_i_glob=change_basis(C_i_loc/StressType(1),r_loc_glob)*StressType(1);
		const st2tost2<3u,StressType> C = C_i_glob-C_0_glob;
		const auto Pr = P_0_glob*C;
		const auto A = invert(st2tost2<3u,real>::Id()+Pr);
		return A;
	};
	
	
	
        }//end of namespace elasticity
   }//end of namespace homogenization

}//end of tfel::material

#endif /* LIB_TFEL_MATERIAL_ESHELBYANISOTROPIC_IXX */
  	
