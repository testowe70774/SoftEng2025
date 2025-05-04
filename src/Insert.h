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

  SortError error = SE_SUCCESS;

  if (data.begin(error) == data.end(error)) {
    return SE_SUCCESS; // Empty container, nothing to sort
  }

  int n = data.size();

  for (int i = 1; i < n; ++i) {
    auto key = data[i];
    int j = i - 1;

    // Move elements of data[0..i-1] that are greater than key
    // to one position ahead of their current position
    while (j >= 0 && data[j] > key) {
      data[j + 1] = data[j];
      --j;
    }
    data[j + 1] = key;
  }

  return error;
}

#endif
