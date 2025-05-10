#ifndef _QUICK_H
#define _QUICK_H


#include "SortTech.h"
#include "SortError.h"
#include "SortData.h"

template<class T, template<typename...> class Container>
class Quick : public SortTech<T, Container> {
  public:
    inline SortError sort(SortData<T, Container> & data) override;

};
template<class T, template<typename...> class Container>
inline SortError Quick<T, Container>::sort(SortData<T, Container> & data) {
  return SE_SUCCESS;
}

#endif
