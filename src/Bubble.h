#ifndef _BUBBLE_H
#define _BUBBLE_H


#include "SortTech.h"
#include "SortError.h"
#include "SortData.h"

template<class T, template<typename...> class Container>
class Bubble : public SortTech<T, Container> {
  public:
    inline SortError sort(SortData<T, Container> & data) override;

};
template<class T, template<typename...> class Container>
inline SortError Bubble<T, Container>::sort(SortData<T, Container> & data) {
  return SE_SUCCESS;
}

#endif
