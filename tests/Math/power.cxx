/*!
 * \file   tests/Math/Functions/power.cxx
 *
 * \brief
 * \author Helfer Thomas
 * \date   04 Jan 2007
 * \copyright Copyright (C) 2006-2018 CEA/DEN, EDF R&D. All rights
 * reserved.
 * This project is publicly released under either the GNU GPL Licence
 * or the CECILL-A licence. A copy of thoses licences are delivered
 * with the sources of TFEL. CEA or EDF may also distribute this
 * project under specific licensing conditions.
 */

#ifdef NDEBUG
#undef NDEBUG
#endif /* NDEBUG */

#include <cassert>
#include <cstdlib>

#include "TFEL/Math/power.hxx"

/* coverity [UNCAUGHT_EXCEPT]*/
int main() {
  using namespace std;
  using namespace tfel::math;
  using tfel::math::stdfunctions::power;
  double epsilon = 1.e-10;
  // We choose 1.12 as value so that power of it don't grow too much...
  assert(abs(power<-49>(1.12) - std::pow(1.12, -49.)) < epsilon);
  assert(abs(power<-48>(1.12) - std::pow(1.12, -48.)) < epsilon);
  assert(abs(power<-47>(1.12) - std::pow(1.12, -47.)) < epsilon);
  assert(abs(power<-46>(1.12) - std::pow(1.12, -46.)) < epsilon);
  assert(abs(power<-45>(1.12) - std::pow(1.12, -45.)) < epsilon);
  assert(abs(power<-44>(1.12) - std::pow(1.12, -44.)) < epsilon);
  assert(abs(power<-43>(1.12) - std::pow(1.12, -43.)) < epsilon);
  assert(abs(power<-42>(1.12) - std::pow(1.12, -42.)) < epsilon);
  assert(abs(power<-41>(1.12) - std::pow(1.12, -41.)) < epsilon);
  assert(abs(power<-40>(1.12) - std::pow(1.12, -40.)) < epsilon);
  assert(abs(power<-39>(1.12) - std::pow(1.12, -39.)) < epsilon);
  assert(abs(power<-38>(1.12) - std::pow(1.12, -38.)) < epsilon);
  assert(abs(power<-37>(1.12) - std::pow(1.12, -37.)) < epsilon);
  assert(abs(power<-36>(1.12) - std::pow(1.12, -36.)) < epsilon);
  assert(abs(power<-35>(1.12) - std::pow(1.12, -35.)) < epsilon);
  assert(abs(power<-34>(1.12) - std::pow(1.12, -34.)) < epsilon);
  assert(abs(power<-33>(1.12) - std::pow(1.12, -33.)) < epsilon);
  assert(abs(power<-32>(1.12) - std::pow(1.12, -32.)) < epsilon);
  assert(abs(power<-31>(1.12) - std::pow(1.12, -31.)) < epsilon);
  assert(abs(power<-30>(1.12) - std::pow(1.12, -30.)) < epsilon);
  assert(abs(power<-29>(1.12) - std::pow(1.12, -29.)) < epsilon);
  assert(abs(power<-28>(1.12) - std::pow(1.12, -28.)) < epsilon);
  assert(abs(power<-27>(1.12) - std::pow(1.12, -27.)) < epsilon);
  assert(abs(power<-26>(1.12) - std::pow(1.12, -26.)) < epsilon);
  assert(abs(power<-25>(1.12) - std::pow(1.12, -25.)) < epsilon);
  assert(abs(power<-24>(1.12) - std::pow(1.12, -24.)) < epsilon);
  assert(abs(power<-23>(1.12) - std::pow(1.12, -23.)) < epsilon);
  assert(abs(power<-22>(1.12) - std::pow(1.12, -22.)) < epsilon);
  assert(abs(power<-21>(1.12) - std::pow(1.12, -21.)) < epsilon);
  assert(abs(power<-20>(1.12) - std::pow(1.12, -20.)) < epsilon);
  assert(abs(power<-19>(1.12) - std::pow(1.12, -19.)) < epsilon);
  assert(abs(power<-18>(1.12) - std::pow(1.12, -18.)) < epsilon);
  assert(abs(power<-17>(1.12) - std::pow(1.12, -17.)) < epsilon);
  assert(abs(power<-16>(1.12) - std::pow(1.12, -16.)) < epsilon);
  assert(abs(power<-15>(1.12) - std::pow(1.12, -15.)) < epsilon);
  assert(abs(power<-14>(1.12) - std::pow(1.12, -14.)) < epsilon);
  assert(abs(power<-13>(1.12) - std::pow(1.12, -13.)) < epsilon);
  assert(abs(power<-12>(1.12) - std::pow(1.12, -12.)) < epsilon);
  assert(abs(power<-11>(1.12) - std::pow(1.12, -11.)) < epsilon);
  assert(abs(power<-10>(1.12) - std::pow(1.12, -10.)) < epsilon);
  assert(abs(power<-9>(1.12) - std::pow(1.12, -9.)) < epsilon);
  assert(abs(power<-8>(1.12) - std::pow(1.12, -8.)) < epsilon);
  assert(abs(power<-7>(1.12) - std::pow(1.12, -7.)) < epsilon);
  assert(abs(power<-6>(1.12) - std::pow(1.12, -6.)) < epsilon);
  assert(abs(power<-5>(1.12) - std::pow(1.12, -5.)) < epsilon);
  assert(abs(power<-4>(1.12) - std::pow(1.12, -4.)) < epsilon);
  assert(abs(power<-3>(1.12) - std::pow(1.12, -3.)) < epsilon);
  assert(abs(power<-2>(1.12) - std::pow(1.12, -2.)) < epsilon);
  assert(abs(power<-1>(1.12) - std::pow(1.12, -1.)) < epsilon);
  assert(abs(power<0>(1.12) - std::pow(1.12, 0.)) < epsilon);
  assert(abs(power<1>(1.12) - std::pow(1.12, 1.)) < epsilon);
  assert(abs(power<2>(1.12) - std::pow(1.12, 2.)) < epsilon);
  assert(abs(power<3>(1.12) - std::pow(1.12, 3.)) < epsilon);
  assert(abs(power<4>(1.12) - std::pow(1.12, 4.)) < epsilon);
  assert(abs(power<5>(1.12) - std::pow(1.12, 5.)) < epsilon);
  assert(abs(power<6>(1.12) - std::pow(1.12, 6.)) < epsilon);
  assert(abs(power<7>(1.12) - std::pow(1.12, 7.)) < epsilon);
  assert(abs(power<8>(1.12) - std::pow(1.12, 8.)) < epsilon);
  assert(abs(power<9>(1.12) - std::pow(1.12, 9.)) < epsilon);
  assert(abs(power<10>(1.12) - std::pow(1.12, 10.)) < epsilon);
  assert(abs(power<11>(1.12) - std::pow(1.12, 11.)) < epsilon);
  assert(abs(power<12>(1.12) - std::pow(1.12, 12.)) < epsilon);
  assert(abs(power<13>(1.12) - std::pow(1.12, 13.)) < epsilon);
  assert(abs(power<14>(1.12) - std::pow(1.12, 14.)) < epsilon);
  assert(abs(power<15>(1.12) - std::pow(1.12, 15.)) < epsilon);
  assert(abs(power<16>(1.12) - std::pow(1.12, 16.)) < epsilon);
  assert(abs(power<17>(1.12) - std::pow(1.12, 17.)) < epsilon);
  assert(abs(power<18>(1.12) - std::pow(1.12, 18.)) < epsilon);
  assert(abs(power<19>(1.12) - std::pow(1.12, 19.)) < epsilon);
  assert(abs(power<20>(1.12) - std::pow(1.12, 20.)) < epsilon);
  assert(abs(power<21>(1.12) - std::pow(1.12, 21.)) < epsilon);
  assert(abs(power<22>(1.12) - std::pow(1.12, 22.)) < epsilon);
  assert(abs(power<23>(1.12) - std::pow(1.12, 23.)) < epsilon);
  assert(abs(power<24>(1.12) - std::pow(1.12, 24.)) < epsilon);
  assert(abs(power<25>(1.12) - std::pow(1.12, 25.)) < epsilon);
  assert(abs(power<26>(1.12) - std::pow(1.12, 26.)) < epsilon);
  assert(abs(power<27>(1.12) - std::pow(1.12, 27.)) < epsilon);
  assert(abs(power<28>(1.12) - std::pow(1.12, 28.)) < epsilon);
  assert(abs(power<29>(1.12) - std::pow(1.12, 29.)) < epsilon);
  assert(abs(power<30>(1.12) - std::pow(1.12, 30.)) < epsilon);
  assert(abs(power<31>(1.12) - std::pow(1.12, 31.)) < epsilon);
  assert(abs(power<32>(1.12) - std::pow(1.12, 32.)) < epsilon);
  assert(abs(power<33>(1.12) - std::pow(1.12, 33.)) < epsilon);
  assert(abs(power<34>(1.12) - std::pow(1.12, 34.)) < epsilon);
  assert(abs(power<35>(1.12) - std::pow(1.12, 35.)) < epsilon);
  assert(abs(power<36>(1.12) - std::pow(1.12, 36.)) < epsilon);
  assert(abs(power<37>(1.12) - std::pow(1.12, 37.)) < epsilon);
  assert(abs(power<38>(1.12) - std::pow(1.12, 38.)) < epsilon);
  assert(abs(power<39>(1.12) - std::pow(1.12, 39.)) < epsilon);
  assert(abs(power<40>(1.12) - std::pow(1.12, 40.)) < epsilon);
  assert(abs(power<41>(1.12) - std::pow(1.12, 41.)) < epsilon);
  assert(abs(power<42>(1.12) - std::pow(1.12, 42.)) < epsilon);
  assert(abs(power<43>(1.12) - std::pow(1.12, 43.)) < epsilon);
  assert(abs(power<44>(1.12) - std::pow(1.12, 44.)) < epsilon);
  assert(abs(power<45>(1.12) - std::pow(1.12, 45.)) < epsilon);
  assert(abs(power<46>(1.12) - std::pow(1.12, 46.)) < epsilon);
  assert(abs(power<47>(1.12) - std::pow(1.12, 47.)) < epsilon);
  assert(abs(power<48>(1.12) - std::pow(1.12, 48.)) < epsilon);
  assert(abs(power<49>(1.12) - std::pow(1.12, 49.)) < epsilon);

  assert(abs(power<-49>(1.12) - std::pow(1.12, -49.)) < epsilon);
  assert(abs(power<-48>(1.12) - std::pow(1.12, -48.)) < epsilon);
  assert(abs(power<-47>(1.12) - std::pow(1.12, -47.)) < epsilon);
  assert(abs(power<-46>(1.12) - std::pow(1.12, -46.)) < epsilon);
  assert(abs(power<-45>(1.12) - std::pow(1.12, -45.)) < epsilon);
  assert(abs(power<-44>(1.12) - std::pow(1.12, -44.)) < epsilon);
  assert(abs(power<-43>(1.12) - std::pow(1.12, -43.)) < epsilon);
  assert(abs(power<-42>(1.12) - std::pow(1.12, -42.)) < epsilon);
  assert(abs(power<-41>(1.12) - std::pow(1.12, -41.)) < epsilon);
  assert(abs(power<-40>(1.12) - std::pow(1.12, -40.)) < epsilon);
  assert(abs(power<-39>(1.12) - std::pow(1.12, -39.)) < epsilon);
  assert(abs(power<-38>(1.12) - std::pow(1.12, -38.)) < epsilon);
  assert(abs(power<-37>(1.12) - std::pow(1.12, -37.)) < epsilon);
  assert(abs(power<-36>(1.12) - std::pow(1.12, -36.)) < epsilon);
  assert(abs(power<-35>(1.12) - std::pow(1.12, -35.)) < epsilon);
  assert(abs(power<-34>(1.12) - std::pow(1.12, -34.)) < epsilon);
  assert(abs(power<-33>(1.12) - std::pow(1.12, -33.)) < epsilon);
  assert(abs(power<-32>(1.12) - std::pow(1.12, -32.)) < epsilon);
  assert(abs(power<-31>(1.12) - std::pow(1.12, -31.)) < epsilon);
  assert(abs(power<-30>(1.12) - std::pow(1.12, -30.)) < epsilon);
  assert(abs(power<-29>(1.12) - std::pow(1.12, -29.)) < epsilon);
  assert(abs(power<-28>(1.12) - std::pow(1.12, -28.)) < epsilon);
  assert(abs(power<-27>(1.12) - std::pow(1.12, -27.)) < epsilon);
  assert(abs(power<-26>(1.12) - std::pow(1.12, -26.)) < epsilon);
  assert(abs(power<-25>(1.12) - std::pow(1.12, -25.)) < epsilon);
  assert(abs(power<-24>(1.12) - std::pow(1.12, -24.)) < epsilon);
  assert(abs(power<-23>(1.12) - std::pow(1.12, -23.)) < epsilon);
  assert(abs(power<-22>(1.12) - std::pow(1.12, -22.)) < epsilon);
  assert(abs(power<-21>(1.12) - std::pow(1.12, -21.)) < epsilon);
  assert(abs(power<-20>(1.12) - std::pow(1.12, -20.)) < epsilon);
  assert(abs(power<-19>(1.12) - std::pow(1.12, -19.)) < epsilon);
  assert(abs(power<-18>(1.12) - std::pow(1.12, -18.)) < epsilon);
  assert(abs(power<-17>(1.12) - std::pow(1.12, -17.)) < epsilon);
  assert(abs(power<-16>(1.12) - std::pow(1.12, -16.)) < epsilon);
  assert(abs(power<-15>(1.12) - std::pow(1.12, -15.)) < epsilon);
  assert(abs(power<-14>(1.12) - std::pow(1.12, -14.)) < epsilon);
  assert(abs(power<-13>(1.12) - std::pow(1.12, -13.)) < epsilon);
  assert(abs(power<-12>(1.12) - std::pow(1.12, -12.)) < epsilon);
  assert(abs(power<-11>(1.12) - std::pow(1.12, -11.)) < epsilon);
  assert(abs(power<-10>(1.12) - std::pow(1.12, -10.)) < epsilon);
  assert(abs(power<-9>(1.12) - std::pow(1.12, -9.)) < epsilon);
  assert(abs(power<-8>(1.12) - std::pow(1.12, -8.)) < epsilon);
  assert(abs(power<-7>(1.12) - std::pow(1.12, -7.)) < epsilon);
  assert(abs(power<-6>(1.12) - std::pow(1.12, -6.)) < epsilon);
  assert(abs(power<-5>(1.12) - std::pow(1.12, -5.)) < epsilon);
  assert(abs(power<-4>(1.12) - std::pow(1.12, -4.)) < epsilon);
  assert(abs(power<-3>(1.12) - std::pow(1.12, -3.)) < epsilon);
  assert(abs(power<-2>(1.12) - std::pow(1.12, -2.)) < epsilon);
  assert(abs(power<-1>(1.12) - std::pow(1.12, -1.)) < epsilon);
  assert(abs(power<0>(1.12) - std::pow(1.12, 0.)) < epsilon);
  assert(abs(power<1>(1.12) - std::pow(1.12, 1.)) < epsilon);
  assert(abs(power<2>(1.12) - std::pow(1.12, 2.)) < epsilon);
  assert(abs(power<3>(1.12) - std::pow(1.12, 3.)) < epsilon);
  assert(abs(power<4>(1.12) - std::pow(1.12, 4.)) < epsilon);
  assert(abs(power<5>(1.12) - std::pow(1.12, 5.)) < epsilon);
  assert(abs(power<6>(1.12) - std::pow(1.12, 6.)) < epsilon);
  assert(abs(power<7>(1.12) - std::pow(1.12, 7.)) < epsilon);
  assert(abs(power<8>(1.12) - std::pow(1.12, 8.)) < epsilon);
  assert(abs(power<9>(1.12) - std::pow(1.12, 9.)) < epsilon);
  assert(abs(power<10>(1.12) - std::pow(1.12, 10.)) < epsilon);
  assert(abs(power<11>(1.12) - std::pow(1.12, 11.)) < epsilon);
  assert(abs(power<12>(1.12) - std::pow(1.12, 12.)) < epsilon);
  assert(abs(power<13>(1.12) - std::pow(1.12, 13.)) < epsilon);
  assert(abs(power<14>(1.12) - std::pow(1.12, 14.)) < epsilon);
  assert(abs(power<15>(1.12) - std::pow(1.12, 15.)) < epsilon);
  assert(abs(power<16>(1.12) - std::pow(1.12, 16.)) < epsilon);
  assert(abs(power<17>(1.12) - std::pow(1.12, 17.)) < epsilon);
  assert(abs(power<18>(1.12) - std::pow(1.12, 18.)) < epsilon);
  assert(abs(power<19>(1.12) - std::pow(1.12, 19.)) < epsilon);
  assert(abs(power<20>(1.12) - std::pow(1.12, 20.)) < epsilon);
  assert(abs(power<21>(1.12) - std::pow(1.12, 21.)) < epsilon);
  assert(abs(power<22>(1.12) - std::pow(1.12, 22.)) < epsilon);
  assert(abs(power<23>(1.12) - std::pow(1.12, 23.)) < epsilon);
  assert(abs(power<24>(1.12) - std::pow(1.12, 24.)) < epsilon);
  assert(abs(power<25>(1.12) - std::pow(1.12, 25.)) < epsilon);
  assert(abs(power<26>(1.12) - std::pow(1.12, 26.)) < epsilon);
  assert(abs(power<27>(1.12) - std::pow(1.12, 27.)) < epsilon);
  assert(abs(power<28>(1.12) - std::pow(1.12, 28.)) < epsilon);
  assert(abs(power<29>(1.12) - std::pow(1.12, 29.)) < epsilon);
  assert(abs(power<30>(1.12) - std::pow(1.12, 30.)) < epsilon);
  assert(abs(power<31>(1.12) - std::pow(1.12, 31.)) < epsilon);
  assert(abs(power<32>(1.12) - std::pow(1.12, 32.)) < epsilon);
  assert(abs(power<33>(1.12) - std::pow(1.12, 33.)) < epsilon);
  assert(abs(power<34>(1.12) - std::pow(1.12, 34.)) < epsilon);
  assert(abs(power<35>(1.12) - std::pow(1.12, 35.)) < epsilon);
  assert(abs(power<36>(1.12) - std::pow(1.12, 36.)) < epsilon);
  assert(abs(power<37>(1.12) - std::pow(1.12, 37.)) < epsilon);
  assert(abs(power<38>(1.12) - std::pow(1.12, 38.)) < epsilon);
  assert(abs(power<39>(1.12) - std::pow(1.12, 39.)) < epsilon);
  assert(abs(power<40>(1.12) - std::pow(1.12, 40.)) < epsilon);
  assert(abs(power<41>(1.12) - std::pow(1.12, 41.)) < epsilon);
  assert(abs(power<42>(1.12) - std::pow(1.12, 42.)) < epsilon);
  assert(abs(power<43>(1.12) - std::pow(1.12, 43.)) < epsilon);
  assert(abs(power<44>(1.12) - std::pow(1.12, 44.)) < epsilon);
  assert(abs(power<45>(1.12) - std::pow(1.12, 45.)) < epsilon);
  assert(abs(power<46>(1.12) - std::pow(1.12, 46.)) < epsilon);
  assert(abs(power<47>(1.12) - std::pow(1.12, 47.)) < epsilon);
  assert(abs(power<48>(1.12) - std::pow(1.12, 48.)) < epsilon);
  assert(abs(power<49>(1.12) - std::pow(1.12, 49.)) < epsilon);

  // We choose 1.12 as value so that power of it don't grow too much...
  assert(abs(power<-49, 2>(1.12) - std::pow(1.12, -49. / 2.)) < epsilon);
  assert(abs(power<-48, 2>(1.12) - std::pow(1.12, -48. / 2.)) < epsilon);
  assert(abs(power<-47, 2>(1.12) - std::pow(1.12, -47. / 2.)) < epsilon);
  assert(abs(power<-46, 2>(1.12) - std::pow(1.12, -46. / 2.)) < epsilon);
  assert(abs(power<-45, 2>(1.12) - std::pow(1.12, -45. / 2.)) < epsilon);
  assert(abs(power<-44, 2>(1.12) - std::pow(1.12, -44. / 2.)) < epsilon);
  assert(abs(power<-43, 2>(1.12) - std::pow(1.12, -43. / 2.)) < epsilon);
  assert(abs(power<-42, 2>(1.12) - std::pow(1.12, -42. / 2.)) < epsilon);
  assert(abs(power<-41, 2>(1.12) - std::pow(1.12, -41. / 2.)) < epsilon);
  assert(abs(power<-40, 2>(1.12) - std::pow(1.12, -40. / 2.)) < epsilon);
  assert(abs(power<-39, 2>(1.12) - std::pow(1.12, -39. / 2.)) < epsilon);
  assert(abs(power<-38, 2>(1.12) - std::pow(1.12, -38. / 2.)) < epsilon);
  assert(abs(power<-37, 2>(1.12) - std::pow(1.12, -37. / 2.)) < epsilon);
  assert(abs(power<-36, 2>(1.12) - std::pow(1.12, -36. / 2.)) < epsilon);
  assert(abs(power<-35, 2>(1.12) - std::pow(1.12, -35. / 2.)) < epsilon);
  assert(abs(power<-34, 2>(1.12) - std::pow(1.12, -34. / 2.)) < epsilon);
  assert(abs(power<-33, 2>(1.12) - std::pow(1.12, -33. / 2.)) < epsilon);
  assert(abs(power<-32, 2>(1.12) - std::pow(1.12, -32. / 2.)) < epsilon);
  assert(abs(power<-31, 2>(1.12) - std::pow(1.12, -31. / 2.)) < epsilon);
  assert(abs(power<-30, 2>(1.12) - std::pow(1.12, -30. / 2.)) < epsilon);
  assert(abs(power<-29, 2>(1.12) - std::pow(1.12, -29. / 2.)) < epsilon);
  assert(abs(power<-28, 2>(1.12) - std::pow(1.12, -28. / 2.)) < epsilon);
  assert(abs(power<-27, 2>(1.12) - std::pow(1.12, -27. / 2.)) < epsilon);
  assert(abs(power<-26, 2>(1.12) - std::pow(1.12, -26. / 2.)) < epsilon);
  assert(abs(power<-25, 2>(1.12) - std::pow(1.12, -25. / 2.)) < epsilon);
  assert(abs(power<-24, 2>(1.12) - std::pow(1.12, -24. / 2.)) < epsilon);
  assert(abs(power<-23, 2>(1.12) - std::pow(1.12, -23. / 2.)) < epsilon);
  assert(abs(power<-22, 2>(1.12) - std::pow(1.12, -22. / 2.)) < epsilon);
  assert(abs(power<-21, 2>(1.12) - std::pow(1.12, -21. / 2.)) < epsilon);
  assert(abs(power<-20, 2>(1.12) - std::pow(1.12, -20. / 2.)) < epsilon);
  assert(abs(power<-19, 2>(1.12) - std::pow(1.12, -19. / 2.)) < epsilon);
  assert(abs(power<-18, 2>(1.12) - std::pow(1.12, -18. / 2.)) < epsilon);
  assert(abs(power<-17, 2>(1.12) - std::pow(1.12, -17. / 2.)) < epsilon);
  assert(abs(power<-16, 2>(1.12) - std::pow(1.12, -16. / 2.)) < epsilon);
  assert(abs(power<-15, 2>(1.12) - std::pow(1.12, -15. / 2.)) < epsilon);
  assert(abs(power<-14, 2>(1.12) - std::pow(1.12, -14. / 2.)) < epsilon);
  assert(abs(power<-13, 2>(1.12) - std::pow(1.12, -13. / 2.)) < epsilon);
  assert(abs(power<-12, 2>(1.12) - std::pow(1.12, -12. / 2.)) < epsilon);
  assert(abs(power<-11, 2>(1.12) - std::pow(1.12, -11. / 2.)) < epsilon);
  assert(abs(power<-10, 2>(1.12) - std::pow(1.12, -10. / 2.)) < epsilon);
  assert(abs(power<-9, 2>(1.12) - std::pow(1.12, -9. / 2.)) < epsilon);
  assert(abs(power<-8, 2>(1.12) - std::pow(1.12, -8. / 2.)) < epsilon);
  assert(abs(power<-7, 2>(1.12) - std::pow(1.12, -7. / 2.)) < epsilon);
  assert(abs(power<-6, 2>(1.12) - std::pow(1.12, -6. / 2.)) < epsilon);
  assert(abs(power<-5, 2>(1.12) - std::pow(1.12, -5. / 2.)) < epsilon);
  assert(abs(power<-4, 2>(1.12) - std::pow(1.12, -4. / 2.)) < epsilon);
  assert(abs(power<-3, 2>(1.12) - std::pow(1.12, -3. / 2.)) < epsilon);
  assert(abs(power<-2, 2>(1.12) - std::pow(1.12, -2. / 2.)) < epsilon);
  assert(abs(power<-1, 2>(1.12) - std::pow(1.12, -1. / 2.)) < epsilon);
  assert(abs(power<0, 2>(1.12) - std::pow(1.12, 0. / 2.)) < epsilon);
  assert(abs(power<1, 2>(1.12) - std::pow(1.12, 1. / 2.)) < epsilon);
  assert(abs(power<2, 2>(1.12) - std::pow(1.12, 2. / 2.)) < epsilon);
  assert(abs(power<3, 2>(1.12) - std::pow(1.12, 3. / 2.)) < epsilon);
  assert(abs(power<4, 2>(1.12) - std::pow(1.12, 4. / 2.)) < epsilon);
  assert(abs(power<5, 2>(1.12) - std::pow(1.12, 5. / 2.)) < epsilon);
  assert(abs(power<6, 2>(1.12) - std::pow(1.12, 6. / 2.)) < epsilon);
  assert(abs(power<7, 2>(1.12) - std::pow(1.12, 7. / 2.)) < epsilon);
  assert(abs(power<8, 2>(1.12) - std::pow(1.12, 8. / 2.)) < epsilon);
  assert(abs(power<9, 2>(1.12) - std::pow(1.12, 9. / 2.)) < epsilon);
  assert(abs(power<10, 2>(1.12) - std::pow(1.12, 10. / 2.)) < epsilon);
  assert(abs(power<11, 2>(1.12) - std::pow(1.12, 11. / 2.)) < epsilon);
  assert(abs(power<12, 2>(1.12) - std::pow(1.12, 12. / 2.)) < epsilon);
  assert(abs(power<13, 2>(1.12) - std::pow(1.12, 13. / 2.)) < epsilon);
  assert(abs(power<14, 2>(1.12) - std::pow(1.12, 14. / 2.)) < epsilon);
  assert(abs(power<15, 2>(1.12) - std::pow(1.12, 15. / 2.)) < epsilon);
  assert(abs(power<16, 2>(1.12) - std::pow(1.12, 16. / 2.)) < epsilon);
  assert(abs(power<17, 2>(1.12) - std::pow(1.12, 17. / 2.)) < epsilon);
  assert(abs(power<18, 2>(1.12) - std::pow(1.12, 18. / 2.)) < epsilon);
  assert(abs(power<19, 2>(1.12) - std::pow(1.12, 19. / 2.)) < epsilon);
  assert(abs(power<20, 2>(1.12) - std::pow(1.12, 20. / 2.)) < epsilon);
  assert(abs(power<21, 2>(1.12) - std::pow(1.12, 21. / 2.)) < epsilon);
  assert(abs(power<22, 2>(1.12) - std::pow(1.12, 22. / 2.)) < epsilon);
  assert(abs(power<23, 2>(1.12) - std::pow(1.12, 23. / 2.)) < epsilon);
  assert(abs(power<24, 2>(1.12) - std::pow(1.12, 24. / 2.)) < epsilon);
  assert(abs(power<25, 2>(1.12) - std::pow(1.12, 25. / 2.)) < epsilon);
  assert(abs(power<26, 2>(1.12) - std::pow(1.12, 26. / 2.)) < epsilon);
  assert(abs(power<27, 2>(1.12) - std::pow(1.12, 27. / 2.)) < epsilon);
  assert(abs(power<28, 2>(1.12) - std::pow(1.12, 28. / 2.)) < epsilon);
  assert(abs(power<29, 2>(1.12) - std::pow(1.12, 29. / 2.)) < epsilon);
  assert(abs(power<30, 2>(1.12) - std::pow(1.12, 30. / 2.)) < epsilon);
  assert(abs(power<31, 2>(1.12) - std::pow(1.12, 31. / 2.)) < epsilon);
  assert(abs(power<32, 2>(1.12) - std::pow(1.12, 32. / 2.)) < epsilon);
  assert(abs(power<33, 2>(1.12) - std::pow(1.12, 33. / 2.)) < epsilon);
  assert(abs(power<34, 2>(1.12) - std::pow(1.12, 34. / 2.)) < epsilon);
  assert(abs(power<35, 2>(1.12) - std::pow(1.12, 35. / 2.)) < epsilon);
  assert(abs(power<36, 2>(1.12) - std::pow(1.12, 36. / 2.)) < epsilon);
  assert(abs(power<37, 2>(1.12) - std::pow(1.12, 37. / 2.)) < epsilon);
  assert(abs(power<38, 2>(1.12) - std::pow(1.12, 38. / 2.)) < epsilon);
  assert(abs(power<39, 2>(1.12) - std::pow(1.12, 39. / 2.)) < epsilon);
  assert(abs(power<40, 2>(1.12) - std::pow(1.12, 40. / 2.)) < epsilon);
  assert(abs(power<41, 2>(1.12) - std::pow(1.12, 41. / 2.)) < epsilon);
  assert(abs(power<42, 2>(1.12) - std::pow(1.12, 42. / 2.)) < epsilon);
  assert(abs(power<43, 2>(1.12) - std::pow(1.12, 43. / 2.)) < epsilon);
  assert(abs(power<44, 2>(1.12) - std::pow(1.12, 44. / 2.)) < epsilon);
  assert(abs(power<45, 2>(1.12) - std::pow(1.12, 45. / 2.)) < epsilon);
  assert(abs(power<46, 2>(1.12) - std::pow(1.12, 46. / 2.)) < epsilon);
  assert(abs(power<47, 2>(1.12) - std::pow(1.12, 47. / 2.)) < epsilon);
  assert(abs(power<48, 2>(1.12) - std::pow(1.12, 48. / 2.)) < epsilon);
  assert(abs(power<49, 2>(1.12) - std::pow(1.12, 49. / 2.)) < epsilon);

  assert(abs(power<-49, 2>(1.12) - std::pow(1.12, -49. / 2.)) < epsilon);
  assert(abs(power<-48, 2>(1.12) - std::pow(1.12, -48. / 2.)) < epsilon);
  assert(abs(power<-47, 2>(1.12) - std::pow(1.12, -47. / 2.)) < epsilon);
  assert(abs(power<-46, 2>(1.12) - std::pow(1.12, -46. / 2.)) < epsilon);
  assert(abs(power<-45, 2>(1.12) - std::pow(1.12, -45. / 2.)) < epsilon);
  assert(abs(power<-44, 2>(1.12) - std::pow(1.12, -44. / 2.)) < epsilon);
  assert(abs(power<-43, 2>(1.12) - std::pow(1.12, -43. / 2.)) < epsilon);
  assert(abs(power<-42, 2>(1.12) - std::pow(1.12, -42. / 2.)) < epsilon);
  assert(abs(power<-41, 2>(1.12) - std::pow(1.12, -41. / 2.)) < epsilon);
  assert(abs(power<-40, 2>(1.12) - std::pow(1.12, -40. / 2.)) < epsilon);
  assert(abs(power<-39, 2>(1.12) - std::pow(1.12, -39. / 2.)) < epsilon);
  assert(abs(power<-38, 2>(1.12) - std::pow(1.12, -38. / 2.)) < epsilon);
  assert(abs(power<-37, 2>(1.12) - std::pow(1.12, -37. / 2.)) < epsilon);
  assert(abs(power<-36, 2>(1.12) - std::pow(1.12, -36. / 2.)) < epsilon);
  assert(abs(power<-35, 2>(1.12) - std::pow(1.12, -35. / 2.)) < epsilon);
  assert(abs(power<-34, 2>(1.12) - std::pow(1.12, -34. / 2.)) < epsilon);
  assert(abs(power<-33, 2>(1.12) - std::pow(1.12, -33. / 2.)) < epsilon);
  assert(abs(power<-32, 2>(1.12) - std::pow(1.12, -32. / 2.)) < epsilon);
  assert(abs(power<-31, 2>(1.12) - std::pow(1.12, -31. / 2.)) < epsilon);
  assert(abs(power<-30, 2>(1.12) - std::pow(1.12, -30. / 2.)) < epsilon);
  assert(abs(power<-29, 2>(1.12) - std::pow(1.12, -29. / 2.)) < epsilon);
  assert(abs(power<-28, 2>(1.12) - std::pow(1.12, -28. / 2.)) < epsilon);
  assert(abs(power<-27, 2>(1.12) - std::pow(1.12, -27. / 2.)) < epsilon);
  assert(abs(power<-26, 2>(1.12) - std::pow(1.12, -26. / 2.)) < epsilon);
  assert(abs(power<-25, 2>(1.12) - std::pow(1.12, -25. / 2.)) < epsilon);
  assert(abs(power<-24, 2>(1.12) - std::pow(1.12, -24. / 2.)) < epsilon);
  assert(abs(power<-23, 2>(1.12) - std::pow(1.12, -23. / 2.)) < epsilon);
  assert(abs(power<-22, 2>(1.12) - std::pow(1.12, -22. / 2.)) < epsilon);
  assert(abs(power<-21, 2>(1.12) - std::pow(1.12, -21. / 2.)) < epsilon);
  assert(abs(power<-20, 2>(1.12) - std::pow(1.12, -20. / 2.)) < epsilon);
  assert(abs(power<-19, 2>(1.12) - std::pow(1.12, -19. / 2.)) < epsilon);
  assert(abs(power<-18, 2>(1.12) - std::pow(1.12, -18. / 2.)) < epsilon);
  assert(abs(power<-17, 2>(1.12) - std::pow(1.12, -17. / 2.)) < epsilon);
  assert(abs(power<-16, 2>(1.12) - std::pow(1.12, -16. / 2.)) < epsilon);
  assert(abs(power<-15, 2>(1.12) - std::pow(1.12, -15. / 2.)) < epsilon);
  assert(abs(power<-14, 2>(1.12) - std::pow(1.12, -14. / 2.)) < epsilon);
  assert(abs(power<-13, 2>(1.12) - std::pow(1.12, -13. / 2.)) < epsilon);
  assert(abs(power<-12, 2>(1.12) - std::pow(1.12, -12. / 2.)) < epsilon);
  assert(abs(power<-11, 2>(1.12) - std::pow(1.12, -11. / 2.)) < epsilon);
  assert(abs(power<-10, 2>(1.12) - std::pow(1.12, -10. / 2.)) < epsilon);
  assert(abs(power<-9, 2>(1.12) - std::pow(1.12, -9. / 2.)) < epsilon);
  assert(abs(power<-8, 2>(1.12) - std::pow(1.12, -8. / 2.)) < epsilon);
  assert(abs(power<-7, 2>(1.12) - std::pow(1.12, -7. / 2.)) < epsilon);
  assert(abs(power<-6, 2>(1.12) - std::pow(1.12, -6. / 2.)) < epsilon);
  assert(abs(power<-5, 2>(1.12) - std::pow(1.12, -5. / 2.)) < epsilon);
  assert(abs(power<-4, 2>(1.12) - std::pow(1.12, -4. / 2.)) < epsilon);
  assert(abs(power<-3, 2>(1.12) - std::pow(1.12, -3. / 2.)) < epsilon);
  assert(abs(power<-2, 2>(1.12) - std::pow(1.12, -2. / 2.)) < epsilon);
  assert(abs(power<-1, 2>(1.12) - std::pow(1.12, -1. / 2.)) < epsilon);
  assert(abs(power<0, 2>(1.12) - std::pow(1.12, 0. / 2.)) < epsilon);
  assert(abs(power<1, 2>(1.12) - std::pow(1.12, 1. / 2.)) < epsilon);
  assert(abs(power<2, 2>(1.12) - std::pow(1.12, 2. / 2.)) < epsilon);
  assert(abs(power<3, 2>(1.12) - std::pow(1.12, 3. / 2.)) < epsilon);
  assert(abs(power<4, 2>(1.12) - std::pow(1.12, 4. / 2.)) < epsilon);
  assert(abs(power<5, 2>(1.12) - std::pow(1.12, 5. / 2.)) < epsilon);
  assert(abs(power<6, 2>(1.12) - std::pow(1.12, 6. / 2.)) < epsilon);
  assert(abs(power<7, 2>(1.12) - std::pow(1.12, 7. / 2.)) < epsilon);
  assert(abs(power<8, 2>(1.12) - std::pow(1.12, 8. / 2.)) < epsilon);
  assert(abs(power<9, 2>(1.12) - std::pow(1.12, 9. / 2.)) < epsilon);
  assert(abs(power<10, 2>(1.12) - std::pow(1.12, 10. / 2.)) < epsilon);
  assert(abs(power<11, 2>(1.12) - std::pow(1.12, 11. / 2.)) < epsilon);
  assert(abs(power<12, 2>(1.12) - std::pow(1.12, 12. / 2.)) < epsilon);
  assert(abs(power<13, 2>(1.12) - std::pow(1.12, 13. / 2.)) < epsilon);
  assert(abs(power<14, 2>(1.12) - std::pow(1.12, 14. / 2.)) < epsilon);
  assert(abs(power<15, 2>(1.12) - std::pow(1.12, 15. / 2.)) < epsilon);
  assert(abs(power<16, 2>(1.12) - std::pow(1.12, 16. / 2.)) < epsilon);
  assert(abs(power<17, 2>(1.12) - std::pow(1.12, 17. / 2.)) < epsilon);
  assert(abs(power<18, 2>(1.12) - std::pow(1.12, 18. / 2.)) < epsilon);
  assert(abs(power<19, 2>(1.12) - std::pow(1.12, 19. / 2.)) < epsilon);
  assert(abs(power<20, 2>(1.12) - std::pow(1.12, 20. / 2.)) < epsilon);
  assert(abs(power<21, 2>(1.12) - std::pow(1.12, 21. / 2.)) < epsilon);
  assert(abs(power<22, 2>(1.12) - std::pow(1.12, 22. / 2.)) < epsilon);
  assert(abs(power<23, 2>(1.12) - std::pow(1.12, 23. / 2.)) < epsilon);
  assert(abs(power<24, 2>(1.12) - std::pow(1.12, 24. / 2.)) < epsilon);
  assert(abs(power<25, 2>(1.12) - std::pow(1.12, 25. / 2.)) < epsilon);
  assert(abs(power<26, 2>(1.12) - std::pow(1.12, 26. / 2.)) < epsilon);
  assert(abs(power<27, 2>(1.12) - std::pow(1.12, 27. / 2.)) < epsilon);
  assert(abs(power<28, 2>(1.12) - std::pow(1.12, 28. / 2.)) < epsilon);
  assert(abs(power<29, 2>(1.12) - std::pow(1.12, 29. / 2.)) < epsilon);
  assert(abs(power<30, 2>(1.12) - std::pow(1.12, 30. / 2.)) < epsilon);
  assert(abs(power<31, 2>(1.12) - std::pow(1.12, 31. / 2.)) < epsilon);
  assert(abs(power<32, 2>(1.12) - std::pow(1.12, 32. / 2.)) < epsilon);
  assert(abs(power<33, 2>(1.12) - std::pow(1.12, 33. / 2.)) < epsilon);
  assert(abs(power<34, 2>(1.12) - std::pow(1.12, 34. / 2.)) < epsilon);
  assert(abs(power<35, 2>(1.12) - std::pow(1.12, 35. / 2.)) < epsilon);
  assert(abs(power<36, 2>(1.12) - std::pow(1.12, 36. / 2.)) < epsilon);
  assert(abs(power<37, 2>(1.12) - std::pow(1.12, 37. / 2.)) < epsilon);
  assert(abs(power<38, 2>(1.12) - std::pow(1.12, 38. / 2.)) < epsilon);
  assert(abs(power<39, 2>(1.12) - std::pow(1.12, 39. / 2.)) < epsilon);
  assert(abs(power<40, 2>(1.12) - std::pow(1.12, 40. / 2.)) < epsilon);
  assert(abs(power<41, 2>(1.12) - std::pow(1.12, 41. / 2.)) < epsilon);
  assert(abs(power<42, 2>(1.12) - std::pow(1.12, 42. / 2.)) < epsilon);
  assert(abs(power<43, 2>(1.12) - std::pow(1.12, 43. / 2.)) < epsilon);
  assert(abs(power<44, 2>(1.12) - std::pow(1.12, 44. / 2.)) < epsilon);
  assert(abs(power<45, 2>(1.12) - std::pow(1.12, 45. / 2.)) < epsilon);
  assert(abs(power<46, 2>(1.12) - std::pow(1.12, 46. / 2.)) < epsilon);
  assert(abs(power<47, 2>(1.12) - std::pow(1.12, 47. / 2.)) < epsilon);
  assert(abs(power<48, 2>(1.12) - std::pow(1.12, 48. / 2.)) < epsilon);
  assert(abs(power<49, 2>(1.12) - std::pow(1.12, 49. / 2.)) < epsilon);

  assert(abs(power<-49, 7>(1.12) - std::pow(1.12, -49. / 7.)) < epsilon);
  assert(abs(power<-48, 7>(1.12) - std::pow(1.12, -48. / 7.)) < epsilon);
  assert(abs(power<-47, 7>(1.12) - std::pow(1.12, -47. / 7.)) < epsilon);
  assert(abs(power<-46, 7>(1.12) - std::pow(1.12, -46. / 7.)) < epsilon);
  assert(abs(power<-45, 7>(1.12) - std::pow(1.12, -45. / 7.)) < epsilon);
  assert(abs(power<-44, 7>(1.12) - std::pow(1.12, -44. / 7.)) < epsilon);
  assert(abs(power<-43, 7>(1.12) - std::pow(1.12, -43. / 7.)) < epsilon);
  assert(abs(power<-42, 7>(1.12) - std::pow(1.12, -42. / 7.)) < epsilon);
  assert(abs(power<-41, 7>(1.12) - std::pow(1.12, -41. / 7.)) < epsilon);
  assert(abs(power<-40, 7>(1.12) - std::pow(1.12, -40. / 7.)) < epsilon);
  assert(abs(power<-39, 7>(1.12) - std::pow(1.12, -39. / 7.)) < epsilon);
  assert(abs(power<-38, 7>(1.12) - std::pow(1.12, -38. / 7.)) < epsilon);
  assert(abs(power<-37, 7>(1.12) - std::pow(1.12, -37. / 7.)) < epsilon);
  assert(abs(power<-36, 7>(1.12) - std::pow(1.12, -36. / 7.)) < epsilon);
  assert(abs(power<-35, 7>(1.12) - std::pow(1.12, -35. / 7.)) < epsilon);
  assert(abs(power<-34, 7>(1.12) - std::pow(1.12, -34. / 7.)) < epsilon);
  assert(abs(power<-33, 7>(1.12) - std::pow(1.12, -33. / 7.)) < epsilon);
  assert(abs(power<-32, 7>(1.12) - std::pow(1.12, -32. / 7.)) < epsilon);
  assert(abs(power<-31, 7>(1.12) - std::pow(1.12, -31. / 7.)) < epsilon);
  assert(abs(power<-30, 7>(1.12) - std::pow(1.12, -30. / 7.)) < epsilon);
  assert(abs(power<-29, 7>(1.12) - std::pow(1.12, -29. / 7.)) < epsilon);
  assert(abs(power<-28, 7>(1.12) - std::pow(1.12, -28. / 7.)) < epsilon);
  assert(abs(power<-27, 7>(1.12) - std::pow(1.12, -27. / 7.)) < epsilon);
  assert(abs(power<-26, 7>(1.12) - std::pow(1.12, -26. / 7.)) < epsilon);
  assert(abs(power<-25, 7>(1.12) - std::pow(1.12, -25. / 7.)) < epsilon);
  assert(abs(power<-24, 7>(1.12) - std::pow(1.12, -24. / 7.)) < epsilon);
  assert(abs(power<-23, 7>(1.12) - std::pow(1.12, -23. / 7.)) < epsilon);
  assert(abs(power<-22, 7>(1.12) - std::pow(1.12, -22. / 7.)) < epsilon);
  assert(abs(power<-21, 7>(1.12) - std::pow(1.12, -21. / 7.)) < epsilon);
  assert(abs(power<-20, 7>(1.12) - std::pow(1.12, -20. / 7.)) < epsilon);
  assert(abs(power<-19, 7>(1.12) - std::pow(1.12, -19. / 7.)) < epsilon);
  assert(abs(power<-18, 7>(1.12) - std::pow(1.12, -18. / 7.)) < epsilon);
  assert(abs(power<-17, 7>(1.12) - std::pow(1.12, -17. / 7.)) < epsilon);
  assert(abs(power<-16, 7>(1.12) - std::pow(1.12, -16. / 7.)) < epsilon);
  assert(abs(power<-15, 7>(1.12) - std::pow(1.12, -15. / 7.)) < epsilon);
  assert(abs(power<-14, 7>(1.12) - std::pow(1.12, -14. / 7.)) < epsilon);
  assert(abs(power<-13, 7>(1.12) - std::pow(1.12, -13. / 7.)) < epsilon);
  assert(abs(power<-12, 7>(1.12) - std::pow(1.12, -12. / 7.)) < epsilon);
  assert(abs(power<-11, 7>(1.12) - std::pow(1.12, -11. / 7.)) < epsilon);
  assert(abs(power<-10, 7>(1.12) - std::pow(1.12, -10. / 7.)) < epsilon);
  assert(abs(power<-9, 7>(1.12) - std::pow(1.12, -9. / 7.)) < epsilon);
  assert(abs(power<-8, 7>(1.12) - std::pow(1.12, -8. / 7.)) < epsilon);
  assert(abs(power<-7, 7>(1.12) - std::pow(1.12, -7. / 7.)) < epsilon);
  assert(abs(power<-6, 7>(1.12) - std::pow(1.12, -6. / 7.)) < epsilon);
  assert(abs(power<-5, 7>(1.12) - std::pow(1.12, -5. / 7.)) < epsilon);
  assert(abs(power<-4, 7>(1.12) - std::pow(1.12, -4. / 7.)) < epsilon);
  assert(abs(power<-3, 7>(1.12) - std::pow(1.12, -3. / 7.)) < epsilon);
  assert(abs(power<-2, 7>(1.12) - std::pow(1.12, -2. / 7.)) < epsilon);
  assert(abs(power<-1, 7>(1.12) - std::pow(1.12, -1. / 7.)) < epsilon);
  assert(abs(power<0, 7>(1.12) - std::pow(1.12, 0. / 7.)) < epsilon);
  assert(abs(power<1, 7>(1.12) - std::pow(1.12, 1. / 7.)) < epsilon);
  assert(abs(power<2, 7>(1.12) - std::pow(1.12, 2. / 7.)) < epsilon);
  assert(abs(power<3, 7>(1.12) - std::pow(1.12, 3. / 7.)) < epsilon);
  assert(abs(power<4, 7>(1.12) - std::pow(1.12, 4. / 7.)) < epsilon);
  assert(abs(power<5, 7>(1.12) - std::pow(1.12, 5. / 7.)) < epsilon);
  assert(abs(power<6, 7>(1.12) - std::pow(1.12, 6. / 7.)) < epsilon);
  assert(abs(power<7, 7>(1.12) - std::pow(1.12, 7. / 7.)) < epsilon);
  assert(abs(power<8, 7>(1.12) - std::pow(1.12, 8. / 7.)) < epsilon);
  assert(abs(power<9, 7>(1.12) - std::pow(1.12, 9. / 7.)) < epsilon);
  assert(abs(power<10, 7>(1.12) - std::pow(1.12, 10. / 7.)) < epsilon);
  assert(abs(power<11, 7>(1.12) - std::pow(1.12, 11. / 7.)) < epsilon);
  assert(abs(power<12, 7>(1.12) - std::pow(1.12, 12. / 7.)) < epsilon);
  assert(abs(power<13, 7>(1.12) - std::pow(1.12, 13. / 7.)) < epsilon);
  assert(abs(power<14, 7>(1.12) - std::pow(1.12, 14. / 7.)) < epsilon);
  assert(abs(power<15, 7>(1.12) - std::pow(1.12, 15. / 7.)) < epsilon);
  assert(abs(power<16, 7>(1.12) - std::pow(1.12, 16. / 7.)) < epsilon);
  assert(abs(power<17, 7>(1.12) - std::pow(1.12, 17. / 7.)) < epsilon);
  assert(abs(power<18, 7>(1.12) - std::pow(1.12, 18. / 7.)) < epsilon);
  assert(abs(power<19, 7>(1.12) - std::pow(1.12, 19. / 7.)) < epsilon);
  assert(abs(power<20, 7>(1.12) - std::pow(1.12, 20. / 7.)) < epsilon);
  assert(abs(power<21, 7>(1.12) - std::pow(1.12, 21. / 7.)) < epsilon);
  assert(abs(power<22, 7>(1.12) - std::pow(1.12, 22. / 7.)) < epsilon);
  assert(abs(power<23, 7>(1.12) - std::pow(1.12, 23. / 7.)) < epsilon);
  assert(abs(power<24, 7>(1.12) - std::pow(1.12, 24. / 7.)) < epsilon);
  assert(abs(power<25, 7>(1.12) - std::pow(1.12, 25. / 7.)) < epsilon);
  assert(abs(power<26, 7>(1.12) - std::pow(1.12, 26. / 7.)) < epsilon);
  assert(abs(power<27, 7>(1.12) - std::pow(1.12, 27. / 7.)) < epsilon);
  assert(abs(power<28, 7>(1.12) - std::pow(1.12, 28. / 7.)) < epsilon);
  assert(abs(power<29, 7>(1.12) - std::pow(1.12, 29. / 7.)) < epsilon);
  assert(abs(power<30, 7>(1.12) - std::pow(1.12, 30. / 7.)) < epsilon);
  assert(abs(power<31, 7>(1.12) - std::pow(1.12, 31. / 7.)) < epsilon);
  assert(abs(power<32, 7>(1.12) - std::pow(1.12, 32. / 7.)) < epsilon);
  assert(abs(power<33, 7>(1.12) - std::pow(1.12, 33. / 7.)) < epsilon);
  assert(abs(power<34, 7>(1.12) - std::pow(1.12, 34. / 7.)) < epsilon);
  assert(abs(power<35, 7>(1.12) - std::pow(1.12, 35. / 7.)) < epsilon);
  assert(abs(power<36, 7>(1.12) - std::pow(1.12, 36. / 7.)) < epsilon);
  assert(abs(power<37, 7>(1.12) - std::pow(1.12, 37. / 7.)) < epsilon);
  assert(abs(power<38, 7>(1.12) - std::pow(1.12, 38. / 7.)) < epsilon);
  assert(abs(power<39, 7>(1.12) - std::pow(1.12, 39. / 7.)) < epsilon);
  assert(abs(power<40, 7>(1.12) - std::pow(1.12, 40. / 7.)) < epsilon);
  assert(abs(power<41, 7>(1.12) - std::pow(1.12, 41. / 7.)) < epsilon);
  assert(abs(power<42, 7>(1.12) - std::pow(1.12, 42. / 7.)) < epsilon);
  assert(abs(power<43, 7>(1.12) - std::pow(1.12, 43. / 7.)) < epsilon);
  assert(abs(power<44, 7>(1.12) - std::pow(1.12, 44. / 7.)) < epsilon);
  assert(abs(power<45, 7>(1.12) - std::pow(1.12, 45. / 7.)) < epsilon);
  assert(abs(power<46, 7>(1.12) - std::pow(1.12, 46. / 7.)) < epsilon);
  assert(abs(power<47, 7>(1.12) - std::pow(1.12, 47. / 7.)) < epsilon);
  assert(abs(power<48, 7>(1.12) - std::pow(1.12, 48. / 7.)) < epsilon);
  assert(abs(power<49, 7>(1.12) - std::pow(1.12, 49. / 7.)) < epsilon);
  return EXIT_SUCCESS;
}
