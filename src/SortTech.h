#ifndef _SORTTECH_H
#define _SORTTECH_H


#include "SortError.h"
#include "SortData.h"

//Interface class for sorting techniques.
template<class T, template<typename...> class Container>
class SortTech {
  public:
    inline virtual SortError sort(SortData<T, Container> & data);

};
template<class T, template<typename...> class Container>
inline SortError SortTech<T, Container>::sort(SortData<T, Container> & data) {
  return SE_SUCCESS;
}

#endif
