#ifndef _SELECT_H
#define _SELECT_H


#include "SortTech.h"
#include "SortError.h"
#include "SortData.h"

template<class T, template<typename...> class Container>
class Select : public SortTech<T, Container> {
  public:
    inline SortError sort(SortData<T> & data) override;

};
template<class T, template<typename...> class Container>
inline SortError Select<T, Container>::sort(SortData<T> & data) {
  return SE_SUCCESS;
}

#endif
