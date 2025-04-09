#ifndef _SORTTECHFACTORY_H
#define _SORTTECHFACTORY_H


#include "SortTech.h"
#include "SortError.h"
#include "Bubble.h"
#include "Quick.h"
#include "Insert.h"
#include "Merge.h"
#include "Radix.h"
#include "Select.h"

#include <memory>

template<template<typename...> class Container>
struct is_std_vector : std::false_type {};

template <>
struct is_std_vector<std::vector> : std::true_type {};

//This class extends the "factory" design pattern and is responsible for selecting and creating the appropriate sorting technique. The choice of technique should be made at compile time by specializing the SortData class templates.
class SortTechFactory {
  public:
    template<class T, template<typename...> class Container>
    static inline std::unique_ptr<SortTech<T, Container>> createSorter(SortError & error);

};
template<class T, template<typename...> class Container>
inline std::unique_ptr<SortTech<T, Container>> SortTechFactory::createSorter(SortError & error)
{
  error = SE_SUCCESS;

  if (std::is_same<T, float>::value && is_std_vector<Container>::value)
  {
      return std::make_unique<Quick<T, Container>>();
  }

  return nullptr;
}

#endif
