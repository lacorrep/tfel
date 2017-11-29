/*!
 * \file   include/TFEL/Math/Tensor/TensorFromTinyMatrixColumnView2.hxx
 * \brief This class provides a view of an tensor provided a given
 * runtime offset. This class is used by the behaviours class
 * generated by the MFrontImplicitParser.
 * Tensor From Matric Column
 * View \author Helfer Thomas \date 16 oct 2008
 * \copyright Copyright (C) 2006-2018 CEA/DEN, EDF R&D. All rights 
 * reserved. 
 * This project is publicly released under either the GNU GPL Licence 
 * or the CECILL-A licence. A copy of thoses licences are delivered 
 * with the sources of TFEL. CEA or EDF may also distribute this 
 * project under specific licensing conditions. 
 */

#ifndef LIB_TFEL_MATH_TENSORFROMTINYMATRIXCOLUMNVIEW2_HXX_
#define LIB_TFEL_MATH_TENSORFROMTINYMATRIXCOLUMNVIEW2_HXX_ 

#include"TFEL/Metaprogramming/StaticAssert.hxx"
#include"TFEL/Math/General/EmptyRunTimeProperties.hxx"

#include"TFEL/Math/Vector/VectorUtilities.hxx"
#include"TFEL/Math/Tensor/TensorConcept.hxx"
#include"TFEL/Math/tensor.hxx"
#include"TFEL/Math/tmatrix.hxx"

namespace tfel
{
  
  namespace math
  {

    template<unsigned short N, unsigned short Mn,
	     unsigned short Mm,unsigned short In,
	     unsigned short Im,typename T>
    struct TensorFromTinyMatrixColumnView2Expr
    {}; // end of struct TensorFromTinyMatrixColumnView2Expr

    template<unsigned short N, unsigned short Mn,
	     unsigned short Mm,unsigned short In,
	     unsigned short Im,typename T>
    struct Expr<tensor<N,T>,TensorFromTinyMatrixColumnView2Expr<N,Mn,Mm,In,Im,T> >
      : public TensorConcept<Expr<tensor<N,T>,TensorFromTinyMatrixColumnView2Expr<N,Mn,Mm,In,Im,T> > >,
	public tensor_base<Expr<tensor<N,T>,TensorFromTinyMatrixColumnView2Expr<N,Mn,Mm,In,Im,T> > >
    {

      typedef EmptyRunTimeProperties RunTimeProperties;

      RunTimeProperties
      getRunTimeProperties() const
      {
	return RunTimeProperties();
      }

      Expr(tmatrix<Mn,Mm,T>& m_,
		  const unsigned short i_,
		  const unsigned short j_)
	: m(m_),
	  oi(i_),
	  oj(j_)
      {} // end of Expr

      const T&
      operator()(const unsigned short i) const
      {
	return this->m(In+(this->oi)*TensorDimeToSize<N>::value+i,Im+this->oj);
      } // end of operator() const

      T&
      operator()(const unsigned short i)
      {
	return this->m(In+(this->oi)*TensorDimeToSize<N>::value+i,Im+this->oj);
      } // end of operator()

      const T&
      operator[](const unsigned short i) const
      {
	return this->m(In+(this->oi)*TensorDimeToSize<N>::value+i,Im+this->oj);
      } // end of operator[] const

      T&
      operator[](const unsigned short i)
      {
	return this->m(In+(this->oi)*TensorDimeToSize<N>::value+i,Im+this->oj);
      } // end of operator[]

      using tensor_base<Expr>::operator =;
    
    protected:

      tmatrix<Mn,Mm,T>& m;
      const unsigned short oi;
      const unsigned short oj;
      
    private:
      
      //! simple checks
      TFEL_STATIC_ASSERT((N==1u)||(N==2u)||(N==3u));
      //! simple checks
      TFEL_STATIC_ASSERT((Im<Mm));
      //! simple checks
      TFEL_STATIC_ASSERT((TensorDimeToSize<N>::value<=Mn-In));

    }; // end of struct Expr

    template<unsigned short N, unsigned short Mn,
	     unsigned short Mm,unsigned short In,
	     unsigned short Im,typename T = double>
    struct TensorFromTinyMatrixColumnView2
    {
      typedef Expr<tensor<N,T>,TensorFromTinyMatrixColumnView2Expr<N,Mn,Mm,In,Im,T> > type;
    }; // end of struct TensorFromTinyMatrixColumnView2
    
  } // end of namespace math

} // end of namespace tfel

#endif /* LIB_TFEL_MATH_TENSORFROMTINYMATRIXCOLUMNVIEW2_HXX_ */

