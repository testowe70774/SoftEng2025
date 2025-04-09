#ifndef _INSERT_H
#define _INSERT_H


#include "SortTech.h"
#include "SortError.h"
#include "SortData.h"

template<class T, template<typename...> class Container>
class Insert : public SortTech<T, Container> {
  public:
    inline SortError sort(SortData<T> & data) override;

};
template<class T, template<typename...> class Container>
inline SortError Insert<T, Container>::sort(SortData<T> & data) {
  return SE_SUCCESS;
}

#endif
