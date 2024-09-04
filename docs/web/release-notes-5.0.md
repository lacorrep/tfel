---
title: Release notes of the 5.0 version of `TFEL`, `MFront` and `MTest`
author: Thomas Helfer, Maxence Wangermez
date: 2024
lang: en-EN
numbersections: true
documentclass: article
from: markdown+tex_math_single_backslash
geometry:
  - margin=2cm
papersize: a4
link-citations: true
colorlinks: true
figPrefixTemplate: "$$i$$"
tblPrefixTemplate: "$$i$$"
secPrefixTemplate: "$$i$$"
eqnPrefixTemplate: "($$i$$)"
---

\newcommand{\tenseur}[1]{\underline{#1}}

# New `TFEL/Utilities` features

## Support for `C++` digit separator in `CxxTokenizer`

The `CxxTokenizer` class now supports `C++` digit separators in numbers,
(integer of floatting point numbers), as illustrated in the following
example:

~~~~{.cxx}
@DSL IsotropicMisesCreep;
@Behaviour DigitSeparatorTest;

@UseQt true;
@Epsilon 0.000'000'000'1;
@IterMax 1'000;

@ElasticMaterialProperties{150'000'000'000, 0.3};
@Parameter stress s0 = 10'000'000;
@Parameter strainrate de0 = 8.230'512e-67;
@Parameter strainrate E = 8.2;

@FlowRule{
  f = de0 * pow(seq / s0, E);
}
~~~~

# New `TFEL/Math` features

## Tiny matrices product

The product of two tiny matrices has been implemented:

~~~~{.cxx}
const auto m1 = tmatrix<2u, 2u, int>{0, 1,  //
                                     2, 3};
const auto m2 = tmatrix<2u, 2u, int>{4, -1,  //
                                     5, 2};
const auto m3 = m1 * m2;
~~~~

## Symmetric tensor eigen values and eigen vectors

- New eigen solvers have been introduced.

### New eigen solvers{#sec:tfel-5.0.0:tfel-math:eigensolvers}

New eigen solver based on Harari analytical solution have been introduced for symmetric tensors. The
computation of eigen values is done with Harari's algorithm [@harari_computation_2023] and the
computation of eigen vectors is done with the default eigen solver for symmetric tensors of `TFEL`. Such
computations are more efficient and more accurate than the default `TFEL` algorithm.

Those algorithms are available in 3D. For 2D symmetric tensors, we
fall back to some default algorithm as described below.

|            Name             |     Algorithm  in 3D      | Algorithm  in 2D  |
| :-------------------------: | :-----------------------: | :---------------: |
|      `TFELEIGENSOLVER`      |     Analytical (TFEL)     | Analytical (TFEL) |
|   `FSESJACOBIEIGENSOLVER`   |          Jacobi           | Analytical (FSES) |
|     `FSESQLEIGENSOLVER`     |  QL with implicit shifts  | Analytical (FSES) |
|   `FSESCUPPENEIGENSOLVER`   | Cuppen's Divide & Conquer | Analytical (FSES) |
| `FSESANALYTICALEIGENSOLVER` |        Analytical         | Analytical (FSES) |
|   `FSESHYBRIDEIGENSOLVER`   |          Hybrid           | Analytical (FSES) |
| `GTESYMMETRICQREIGENSOLVER` |       Symmetric QR        | Analytical (TFEL) |
|     `HARARIEIGENSOLVER`     |    Analytical (Harari)    | Analytical (TFEL) |
: List of available eigen solvers. {#tbl:eigensolvers}

The various eigen solvers available are enumerated in Table
@tbl:eigensolvers.

The eigen solver is passed as a template argument of the
`computeEigenValues` or the `computeEigenVectors` methods as
illustrated in the code below:

~~~~~{.cpp}
tmatrix<3u,3u,real> m2;
tvector<3u,real>    vp2;
std::tie(vp,m)=s.computeEigenVectors<stensor::HARARIEIGENSOLVER>();
~~~~~

#### Some benchmarks

|          Algorithm          | Failure ratio | \(\Delta_{\infty}\) | Times (ns) | Time ratio |
| :-------------------------: | :-----------: | :-----------------: | :--------: | :--------: |
|      `TFELEIGENSOLVER`      |   0.000557    |      2.37e-05       | 129452335  |     1      |
| `GTESYMMETRICQREIGENSOLVER` |       0       |      9.57e-07       | 236544828  |    1.83    |
|   `FSESJACOBIEIGENSOLVER`   |       0       |      4.61e-07       | 241131631  |    1.86    |
|     `FSESQLEIGENSOLVER`     |   0.000173    |      1.67e-06       | 155435496  |    1.20    |
|   `FSESCUPPENEIGENSOLVER`   |   0.018223    |      2.87e-06       | 151727321  |    1.17    |
|   `FSESHYBRIDEIGENSOLVER`   |   0.068411    |      3.90e-03       |  80039266  |    0.62    |
| `FSESANALYTICALEIGENSOLVER` |   0.102626    |      6.21e-02       |  76865961  |    0.59    |
|     `HARARIEIGENSOLVER`     |   0.000018    |      2.46e-06       | 110028802  |    0.85    |
: Test on \(10^{6}\) random symmetric tensors in single precision (`float`). {#tbl:comp_eigensolvers_float}

|          Algorithm          | Failure ratio | \(\Delta_{\infty}\) | Times (ns) | Time ratio |
| :-------------------------: | :-----------: | :-----------------: | :--------: | :--------: |
|      `TFELEIGENSOLVER`      |    0.00058    |      6.94e-14       | 137752068  |     1      |
| `GTESYMMETRICQREIGENSOLVER` |     1e-06     |      2.30e-15       | 315593552  |    2.29    |
|   `FSESJACOBIEIGENSOLVER`   |       0       |      9.08e-16       | 256285090  |    1.86    |
|     `FSESQLEIGENSOLVER`     |   0.000202    |      3.04e-15       | 214537012  |    1.56    |
|   `FSESCUPPENEIGENSOLVER`   |   0.019251    |      5.58e-15       | 219113965  |    1.59    |
|   `FSESHYBRIDEIGENSOLVER`   |   0.081586    |      1.29e-10       |  81861668  |    0.59    |
| `FSESANALYTICALEIGENSOLVER` |   0.103935    |      4.11e-10       |  79701256  |    0.58    |
|     `HARARIEIGENSOLVER`     |   0.000037    |      2.27e-14       | 116977683  |    0.85    |
: Test on \(10^{6}\) random symmetric tensors in double precision (`double`). {#tbl:comp_eigensolvers_double}

|          Algorithm          | Failure ratio | \(\Delta_{\infty}\) | Times (ns) | Time ratio |
| :-------------------------: | :-----------: | :-----------------: | :--------: | :--------: |
|      `TFELEIGENSOLVER`      |   0.000578    |      1.76e-17       | 304165023  |     1      |
| `GTESYMMETRICQREIGENSOLVER` |       0       |      1.01e-18       | 558605772  |    1.84    |
|   `FSESJACOBIEIGENSOLVER`   |       0       |      5.11e-19       | 408584703  |    1.34    |
|     `FSESQLEIGENSOLVER`     |    0.00045    |      1.83e-18       | 311028180  |    1.02    |
|   `FSESCUPPENEIGENSOLVER`   |   0.009134    |      3.23e-18       | 485590150  |    1.60    |
|   `FSESHYBRIDEIGENSOLVER`   |    0.99959    |      4.01e-10       | 187308886  |    0.62    |
| `FSESANALYTICALEIGENSOLVER` |   0.999669    |      1.36e-11       | 211710377  |    0.70    |
|     `HARARIEIGENSOLVER`     |   0.000046    |      4.62e-18       | 338589049  |    1.11    |
: Test on \(10^{6}\) random symmetric tensors in extended precision (`long double`). {#tbl:comp_eigensolvers_long_double}


We have compared the available algorithm on \(10^{6}\) random
symmetric tensors whose components are in \([-1:1]\).

For a given symmetric tensor, we consider that the computation of the
eigenvalues and eigenvectors failed if:
\[
\Delta_{\infty}=\max_{i\in[1,2,3]}\left\|\tenseur{s}\,\cdot\,\vec{v}_{i}-\lambda_{i}\,\vec{v}_{i}\right\|>10\,\varepsilon
\]
where \(\varepsilon\) is the accuracy of the floatting point considered.

The results of those tests are reported on Tables
@tbl:comp_eigensolvers_float, @tbl:comp_eigensolvers_double and
@tbl:comp_eigensolvers_long_double. The Harari eigen solver offers a
better compromise between accuracy and numerical efficiency than the
default `TFEL` solver.

# MFront

## Improvements to the `MaterialProperty` DSL

### The `@Data` keyword

The `@Data` keyword allow the definition of a material properties using
the interpolation of a set of values.

The `@Data` keyword is followed by a set of options defining:

- the interpolation option,
- the set of values,
- the extrapolation option.

The precise syntax depends on the number of inputs of the material
property.

#### Material properties without input

The only option accepted is `value`.

#### Material properties with only one input

The `values` option is required. It must be a map associating values of
the input and values of the output.

The `interpolation` option is optional. It must be a string. The values
`linear` and `cubic_spline` are accepted.

The `extrapolation` option is optional. It must be a boolean or a
string:

- The boolean value `true` means that a linear extrapolation will be performed.
- The boolean value `false` or the string value `bound_to_last_value` or
  the string value `constant` means that a constant value will be used
  for extrapolation.

#### Example of usage

~~~~{.cpp}
@DSL MaterialProperty;
@Law LinearDataInterpolation;

@UseQt true;
@UnitSystem SI;

@Output stress E;
E.setGlossaryName("YoungModulus");

@StateVariable temperature T;
T.setGlossaryName("Temperature");

@Data {
  values: { 293.15 : 240e9, 693.15 : 180e9, 893.15 : 170e9 },
  interpolation : "linear"
};
~~~~

## New DSL options

### The `disable_runtime_checks` option

If this option is set to `true`, interfaces may disable as much runtime
checks as possible. Those runtime checks include checking standard
bounds and physical bounds for instance.

## `generic` interface improvements

### The `@SelectedModellingHypothesis` and `@SelectedModellingHypotheses` keywords

The `@SelectedModellingHypothesis` and `@SelectedModellingHypotheses`
keywords allows to select which modelling hypotheses will be
generated.

Their syntaxes are similar to the keywords
`@ModellingHypothesis` and `@ModellingHypotheses`, respectively.

The selected modelling hypotheses must be a sub-set of the modelling
hypotheses supported by the behaviour.

#### Example of usage

~~~~{.cxx}
$ mfront --obuild --interface=generic --@SelectedModellingHypothesis=PlaneStrain Plasticity.mfront
Treating target : all
The following library has been built :
- libBehaviour.so :  Plasticity_PlaneStrain
~~~~

# Documentation

The page [Libaries usage in C++](libraries_usage.html) describe how to
use the `TFEL` libraries in `C++` projects, using either the
`tfel-config` utility or `cmake` packages.

# Issues fixed

## Issue 535: [mfront-doc] add support for material properties

Allows mfront-doc to be used with the `MaterialLaw` DSL. Example of use:

~~~~{.bash}
$ mfront-doc T91MartensiticSteel_gamma1_ROUX2007.mfront
~~~~

For more details, see <https://github.com/thelfer/tfel/issues/535>

## Issue 582: [cast3m interface] add explicit names and 4-letter mapping of internal variables to the castem file

Adds the correspondence between variable names and the 4-letter
names used in castem to the example `.dgibi` file, generated by `MFront`
with castem interfaces. The mapping is written in the file as a comment,
for example in the form :

```
** List of material properties:
**
** - YOUN: YoungModulus
** - NU: PoissonRatio
** - RHO: MassDensity
** - H: HardeningSlope
** - SO: Yield strength
```

For more details, see <https://github.com/thelfer/tfel/issues/582>

## Issue 585: [mfront] Allow to override inputs in material properties

~~~{.bash}
$ mfront-query --state-variables Inconel600_YoungModulus.mfront 
- Temperature (TK): the temperature
$ mfront-query --parameters Inconel600_YoungModulus.mfront
~~~~

~~~~{.bash}
$ mfront-query --state-variables --dsl-option='overriding_parameters:{"TK": 400}}' Inconel600_YoungModulus.mfront
$ mfront-query --parameters --dsl-option='overriding_parameters:{"TK": 400}}' Inconel600_YoungModulus.mfront
- Temperature (TK): the temperature
~~~~

For more details, see <https://github.com/thelfer/tfel/issues/585>

## Issue 567: `MTestCurrentState.copy()` produces a shallow copy in python bindings

This behaviour is consistent with the copy constructor of the
`StudyCurrentState` class.

To make a deep copy of this object, the `makeDeepCopy` method has been
introduced.

For more details, see <https://github.com/thelfer/tfel/issues/567>

## Issue 557: `[mfront]` allow to specify dsl options in `MFrontBase::getDSL`

For more details, see <https://github.com/thelfer/tfel/issues/557>

## Issue 556: `[cmake]` export compile flags in dedicated variables

For more details, see <https://github.com/thelfer/tfel/issues/556>

## Issue 555: `[cmake]` better handling of dependencies in exported `cmake` files

For more details, see <https://github.com/thelfer/tfel/issues/556>

## Issue 526: The `@UseQt` keyword is not mentioned in the `MaterialLaw`'s keywords help page

For more details, see <https://github.com/thelfer/tfel/issues/526>

## Issue 476: [generic interface] Add support for arrays of thermodynamic forces

For more details, see <https://github.com/thelfer/tfel/issues/476>

## Issue 370: [tfel-utilities] Support for `C++` digit separator

For more details, see <https://github.com/thelfer/tfel/issues/370>