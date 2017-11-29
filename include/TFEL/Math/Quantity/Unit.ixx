/*!
 * \file   include/TFEL/Math/Quantity/Unit.ixx
 * \brief  This file implements the classes declared in Unit.hxx
 * \author Helfer Thomas
 * \date   17 Jul 2006
 * \copyright Copyright (C) 2006-2018 CEA/DEN, EDF R&D. All rights 
 * reserved. 
 * This project is publicly released under either the GNU GPL Licence 
 * or the CECILL-A licence. A copy of thoses licences are delivered 
 * with the sources of TFEL. CEA or EDF may also distribute this 
 * project under specific licensing conditions. 
 */

#ifndef LIB_TFEL_UNIT_I_
#define LIB_TFEL_UNIT_I_ 

namespace tfel{

  namespace math{
    
    template<int N1,int N2,int N3,int N4,int N5,int N6,int N7,
	     unsigned int D1,unsigned int D2,unsigned int D3,
	     unsigned int D4,unsigned int D5,unsigned int D6,
	     unsigned int D7,int O1,int O2,int O3,int O4,int O5,
	     int O6,int O7,unsigned int AP1,unsigned int AP2,
	     unsigned int AP3,unsigned int AP4,unsigned int AP5,
	     unsigned int AP6,unsigned int AP7>
    struct AddUnit_<Unit<std::integral_constant<int,N1>,
			 std::integral_constant<int,N2>,
			 std::integral_constant<int,N3>,
			 std::integral_constant<int,N4>,
			 std::integral_constant<int,N5>,
			 std::integral_constant<int,N6>,
			 std::integral_constant<int,N7> ,
			 std::integral_constant<unsigned int,D1>,
			 std::integral_constant<unsigned int,D2>,
			 std::integral_constant<unsigned int,D3>,
			 std::integral_constant<unsigned int,D4>,
			 std::integral_constant<unsigned int,D5>,
			 std::integral_constant<unsigned int,D6>,
			 std::integral_constant<unsigned int,D7> >,
		    Unit<std::integral_constant<int,O1>,
			 std::integral_constant<int,O2>,
			 std::integral_constant<int,O3>,
			 std::integral_constant<int,O4>,
			 std::integral_constant<int,O5>,
			 std::integral_constant<int,O6>,
			 std::integral_constant<int,O7>,
			 std::integral_constant<unsigned int,AP1>,
			 std::integral_constant<unsigned int,AP2>,
			 std::integral_constant<unsigned int,AP3>,
			 std::integral_constant<unsigned int,AP4>,
			 std::integral_constant<unsigned int,AP5>,
			 std::integral_constant<unsigned int,AP6>,
			 std::integral_constant<unsigned int,AP7> > >
    {
      typedef typename GenerateUnit<std::ratio<N1*AP1+O1*D1,D1*AP1>::num,
				    std::ratio<N2*AP2+O2*D2,D2*AP2>::num,
				    std::ratio<N3*AP3+O3*D3,D3*AP3>::num,
				    std::ratio<N4*AP4+O4*D4,D4*AP4>::num,
				    std::ratio<N5*AP5+O5*D5,D5*AP5>::num,
				    std::ratio<N6*AP6+O6*D6,D6*AP6>::num,
				    std::ratio<N7*AP7+O7*D7,D7*AP7>::num,
				    std::ratio<N1*AP1+O1*D1,D1*AP1>::den,
				    std::ratio<N2*AP2+O2*D2,D2*AP2>::den,
				    std::ratio<N3*AP3+O3*D3,D3*AP3>::den,
				    std::ratio<N4*AP4+O4*D4,D4*AP4>::den,
				    std::ratio<N5*AP5+O5*D5,D5*AP5>::den,
				    std::ratio<N6*AP6+O6*D6,D6*AP6>::den,
				    std::ratio<N7*AP7+O7*D7,D7*AP7>::den>::type type;
    };

    template<int N1,int N2,int N3,int N4,int N5,int N6,int N7,
	     int O1,int O2,int O3,int O4,int O5,int O6,int O7>
    struct AddUnit_<Unit<std::integral_constant<int,N1>,
			 std::integral_constant<int,N2>,
			 std::integral_constant<int,N3>,
			 std::integral_constant<int,N4>,
			 std::integral_constant<int,N5>,
			 std::integral_constant<int,N6>,
			 std::integral_constant<int,N7> ,
			 std::integral_constant<unsigned int,1u>,
			 std::integral_constant<unsigned int,1u>,
			 std::integral_constant<unsigned int,1u>,
			 std::integral_constant<unsigned int,1u>,
			 std::integral_constant<unsigned int,1u>,
			 std::integral_constant<unsigned int,1u>,
			 std::integral_constant<unsigned int,1u> >,
		    Unit<std::integral_constant<int,O1>,
			 std::integral_constant<int,O2>,
			 std::integral_constant<int,O3>,
			 std::integral_constant<int,O4>,
			 std::integral_constant<int,O5>,
			 std::integral_constant<int,O6>,
			 std::integral_constant<int,O7>,
			 std::integral_constant<unsigned int,1u>,
			 std::integral_constant<unsigned int,1u>,
			 std::integral_constant<unsigned int,1u>,
			 std::integral_constant<unsigned int,1u>,
			 std::integral_constant<unsigned int,1u>,
			 std::integral_constant<unsigned int,1u>,
			 std::integral_constant<unsigned int,1u> > >
    {
      typedef typename GenerateUnit<N1+O1,N2+O2,N3+O3,N4+O4,N5+O5,N6+O6,N7+O7>::type type;
    };

    
    template<int N1,int N2,int N3,int N4,int N5,int N6,int N7,
	     unsigned int D1,unsigned int D2,unsigned int D3,
	     unsigned int D4,unsigned int D5,unsigned int D6,
	     unsigned int D7,int O1,int O2,int O3,
	     int O4,int O5,int O6,int O7,unsigned int AP1,
	     unsigned int AP2,unsigned int AP3,unsigned int AP4,
	     unsigned int AP5,unsigned int AP6,unsigned int AP7>
    struct SubUnit_<Unit<std::integral_constant<int,N1>,
			 std::integral_constant<int,N2>,
			 std::integral_constant<int,N3>,
			 std::integral_constant<int,N4>,
			 std::integral_constant<int,N5>,
			 std::integral_constant<int,N6>,
			 std::integral_constant<int,N7>,
			 std::integral_constant<unsigned int,D1>,
			 std::integral_constant<unsigned int,D2>,
			 std::integral_constant<unsigned int,D3>,
			 std::integral_constant<unsigned int,D4>,
			 std::integral_constant<unsigned int,D5>,
			 std::integral_constant<unsigned int,D6>,
			 std::integral_constant<unsigned int,D7> >,
		    Unit<std::integral_constant<int,O1>,
			 std::integral_constant<int,O2>,
			 std::integral_constant<int,O3>,
			 std::integral_constant<int,O4>,
			 std::integral_constant<int,O5>,
			 std::integral_constant<int,O6>,
			 std::integral_constant<int,O7>,
			 std::integral_constant<unsigned int,AP1>,
			 std::integral_constant<unsigned int,AP2>,
			 std::integral_constant<unsigned int,AP3>,
			 std::integral_constant<unsigned int,AP4>,
			 std::integral_constant<unsigned int,AP5>,
			 std::integral_constant<unsigned int,AP6>,
			 std::integral_constant<unsigned int,AP7> > >
    {
      typedef typename GenerateUnit<std::ratio<N1*AP1-O1*D1,D1*AP1>::num,
				    std::ratio<N2*AP2-O2*D2,D2*AP2>::num,
				    std::ratio<N3*AP3-O3*D3,D3*AP3>::num,
				    std::ratio<N4*AP4-O4*D4,D4*AP4>::num,
				    std::ratio<N5*AP5-O5*D5,D5*AP5>::num,
				    std::ratio<N6*AP6-O6*D6,D6*AP6>::num,
				    std::ratio<N7*AP7-O7*D7,D7*AP7>::num,
				    std::ratio<N1*AP1-O1*D1,D1*AP1>::den,
				    std::ratio<N2*AP2-O2*D2,D2*AP2>::den,
				    std::ratio<N3*AP3-O3*D3,D3*AP3>::den,
				    std::ratio<N4*AP4-O4*D4,D4*AP4>::den,
				    std::ratio<N5*AP5-O5*D5,D5*AP5>::den,
				    std::ratio<N6*AP6-O6*D6,D6*AP6>::den,
				    std::ratio<N7*AP7-O7*D7,D7*AP7>::den>::type type;
    };

    template<int N1,int N2,int N3,int N4,int N5,int N6,int N7,
	     int O1,int O2,int O3,int O4,int O5,int O6,int O7>
    struct SubUnit_<Unit<std::integral_constant<int,N1>,
			 std::integral_constant<int,N2>,
			 std::integral_constant<int,N3>,
			 std::integral_constant<int,N4>,
			 std::integral_constant<int,N5>,
			 std::integral_constant<int,N6>,
			 std::integral_constant<int,N7>,
			 std::integral_constant<unsigned int,1u>,
			 std::integral_constant<unsigned int,1u>,
			 std::integral_constant<unsigned int,1u>,
			 std::integral_constant<unsigned int,1u>,
			 std::integral_constant<unsigned int,1u>,
			 std::integral_constant<unsigned int,1u>,
			 std::integral_constant<unsigned int,1u> >,
		    Unit<std::integral_constant<int,O1>,
			 std::integral_constant<int,O2>,
			 std::integral_constant<int,O3>,
			 std::integral_constant<int,O4>,
			 std::integral_constant<int,O5>,
			 std::integral_constant<int,O6>,
			 std::integral_constant<int,O7>,
			 std::integral_constant<unsigned int,1u>,
			 std::integral_constant<unsigned int,1u>,
			 std::integral_constant<unsigned int,1u>,
			 std::integral_constant<unsigned int,1u>,
			 std::integral_constant<unsigned int,1u>,
			 std::integral_constant<unsigned int,1u>,
			 std::integral_constant<unsigned int,1u> > >
    {
      typedef typename GenerateUnit<N1-O1,N2-O2,N3-O3,N4-O4,N5-O5,N6-O6,N7-O7>::type type;
    };

    template<int N, unsigned int D,int N1,int N2,int N3,int N4,int N5,int N6,int N7,
	     unsigned int D1,unsigned int D2,unsigned int D3,unsigned int D4,
	     unsigned int D5,unsigned int D6,unsigned int D7>
    struct PowUnit_<N,D,Unit<std::integral_constant<int,N1>,
			     std::integral_constant<int,N2>,
			     std::integral_constant<int,N3>,
			     std::integral_constant<int,N4>,
			     std::integral_constant<int,N5>,
			     std::integral_constant<int,N6>,
			     std::integral_constant<int,N7> ,
			     std::integral_constant<unsigned int,D1>,
			     std::integral_constant<unsigned int,D2>,
			     std::integral_constant<unsigned int,D3>,
			     std::integral_constant<unsigned int,D4>,
			     std::integral_constant<unsigned int,D5>,
			     std::integral_constant<unsigned int,D6>,
			     std::integral_constant<unsigned int,D7> > >
    {
      typedef typename GenerateUnit<std::ratio<N1*N,D1*D>::num,
				    std::ratio<N2*N,D2*D>::num,
				    std::ratio<N3*N,D3*D>::num,
				    std::ratio<N4*N,D4*D>::num,
				    std::ratio<N5*N,D5*D>::num,
				    std::ratio<N6*N,D6*D>::num,
				    std::ratio<N7*N,D7*D>::num,
				    std::ratio<N1*N,D1*D>::den,
				    std::ratio<N2*N,D2*D>::den,
				    std::ratio<N3*N,D3*D>::den,
				    std::ratio<N4*N,D4*D>::den,
				    std::ratio<N5*N,D5*D>::den,
				    std::ratio<N6*N,D6*D>::den,
				    std::ratio<N7*N,D7*D>::den>::type type;
    };

  } // end of Namesapce math

} // end of namespace tfel

#endif /* LIB_TFEL_UNIT_I_ */

