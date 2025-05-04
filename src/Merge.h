#ifndef _MERGE_H
#define _MERGE_H

#include "SortTech.h"
#include "SortError.h"
#include "SortSeparateData.h"

template<class T, template<typename...> class Container>
class Merge : public SortTech<T, Container> {
  public:
    inline SortError sort(SortData<T> & data) override;

    void mergeSort(SortSeparateData<T>& data, size_t left, size_t right) {
      if (left < right) {
        size_t mid = left + (right - left) / 2;
        mergeSort(data, left, mid);
        mergeSort(data, mid + 1, right);
        merge(data, left, mid, right);
      }
    }

    void merge(SortSeparateData<T>& data, size_t left, size_t mid, size_t right) {
      size_t i = left;
      size_t j = mid + 1;
      size_t k = left;

      Container<T> temp(data.size());
      auto & output = data.output();

      for (size_t index = left; index <= right; ++index) {
        temp[index] = output[index];
      }

      while (i <= mid && j <= right) {
        if (temp[i] <= temp[j]) {
          output[k++] = temp[i++];
        }
        else {
          output[k++] = temp[j++];
        }
      }
      while (i <= mid) {
        output[k++] = temp[i++];
      }
    }
};
template<class T, template<typename...> class Container>
inline SortError Merge<T, Container>::sort(SortData<T> & data) {

  SortData<T>* pdata = &data;

  if (dynamic_cast<SortSeparateData<T>*>(pdata) != nullptr)
  {
    SortSeparateData<T>& sep_data = dynamic_cast<SortSeparateData<T>&>(data);
    auto & output = sep_data.output();
    auto & input = data.data();

    output = input;

    mergeSort(sep_data, 0, data.size() - 1);
  }


  return SE_SUCCESS;
}

#endif
