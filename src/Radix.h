#ifndef _RADIX_H
#define _RADIX_H


#include "SortTech.h"
#include "SortError.h"
#include "SortData.h"

template<class T, template<typename...> class Container>
class Radix : public SortTech<T, Container> {
  public:
    inline SortError sort(SortData<T, Container> & data) override;

};
template<class T, template<typename...> class Container>
inline SortError Radix<T, Container>::sort(SortData<T, Container> & data) {
  return SE_SUCCESS;
}

#endif
