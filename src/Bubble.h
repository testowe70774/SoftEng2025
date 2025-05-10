#ifndef _BUBBLE_H
#define _BUBBLE_H

#include "SortTech.h"
#include "SortError.h"
#include "SortData.h"

template<class T, template<typename...> class Container>
class Bubble : public SortTech<T, Container> {
  public:
    inline SortError sort(SortData<T> & data) override;

};

template<class T, template<typename...> class Container>
inline SortError Bubble<T, Container>::sort(SortData<T, Container> & data) {

  SortError error = SE_SUCCESS;

  if (data.begin(error) == data.end(error)) {
    return SE_SUCCESS; // Empty container, nothing to sort
  }

  if (data.size() <= 0) {
    return SE_SUCCESS;
  }

  size_t n = static_cast<size_t>(data.size());
  bool swapped;

  for (size_t i = 0; i < n - 1; ++i) {
    swapped = false;
    for (size_t j = 0; j < n - i - 1; ++j) {
      if (data[j] > data[j + 1]) {
        data.swap(j, j + 1);
        swapped = true;
      }
    }
    if (!swapped) {
      break;
    }
  }

  return error;
}

#endif
