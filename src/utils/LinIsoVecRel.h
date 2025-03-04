/**
 * @file LinIsoVecRel.h
 * @brief This header file contains the declaration of a function that calculates a vector (real or complex) using a linear isotropic relationship with another vector.
 *
 * The function defined in this file takes a vector and a scalar as inputs and returns a new vector that is calculated based on
 * a linear isotropic relationship with the input vector.
 * The vectors can be either real or complex, and the function handles both cases.
*/

#ifndef LINISOVEC_REL_H
#define LINISOVEC_REL_H

#include <vector>
#include <complex>

// Function declaration
template <typename T>
std::vector<T> LinIsoVecRel(const std::vector<T>& vec, const T& scalar);

#endif // LINISOVEC_REL_H