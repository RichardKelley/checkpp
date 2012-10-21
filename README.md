Checkpp
=======

Checkpp is a library for random testing in C++11. It is inspired by
and aims to reproduce the functionality of the Haskell QuickCheck
library, using support for functional programming that has been
recently added to C++.

Current Features
================

At present, the library aims to support the core functionality
provided by QuickCheck: property-based specifications (via lambda
expressions) and random generation of (basic, non-function) built-in
and user-defined data.

TODO
====

The library is in its infancy, and there's a lot of work left to
do. In particular, we need to implement the following:

1. C++ implementations of the collect and classify combinators.
2. C++ implementation corresponding to the Coarbitrary class.
3. Test data generation for the entire STL.