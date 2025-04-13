#ifndef _SORTDATA_H
#define _SORTDATA_H


#include "SortError.h"
#include "OpState.h"
#include "SortDataBase.h"

#include <vector>


//This class acts as a wrapper around an input/output container that will be sorted using one of the child classes of SortTech. Direct access to the container should be provided through public methods.
template<class T, template<typename...> class Container = std::vector>
class SortData : public SortDataBase {
friend class Sorter;
  private:
    Container<T> m_data;


  public:
    inline SortError add(const T & elem);

    inline SortError add(const T* & data, unsigned int length);

    inline typename Container<T>::iterator begin(SortError & error);

    inline typename Container<T>::iterator end(const SortData<T, Container> & error);


  private:
    OpState m_state = OS_IDLE;


  public:
    //Callback method to be called by separate thread at the end of sorting operation.
    inline virtual void notifyDone();

    inline SortError swap(unsigned int ind_a, unsigned int ind_b);

    inline SortError setState(const const OpState & state);

};
template<class T, template<typename...> class Container>
inline SortError SortData<T, Container>::add(const T & elem) {
  return SE_SUCCESS;
}

template<class T, template<typename...> class Container>
inline SortError SortData<T, Container>::add(const T* & data, unsigned int length) {
  return SE_SUCCESS;
}

template<class T, template<typename...> class Container>
inline typename Container<T>::iterator SortData<T, Container>::begin(SortError & error) {
}

template<class T, template<typename...> class Container>
inline typename Container<T>::iterator SortData<T, Container>::end(const SortData<T, Container> & error) {
}

//Callback method to be called by separate thread at the end of sorting operation.
template<class T, template<typename...> class Container>
inline void SortData<T, Container>::notifyDone() {
}

template<class T, template<typename...> class Container>
inline SortError SortData<T, Container>::swap(unsigned int ind_a, unsigned int ind_b) {
  return SE_SUCCESS;
}

template<class T, template<typename...> class Container>
inline SortError SortData<T, Container>::setState(const const OpState & state) {
  m_state=state;
  return SE_SUCCESS;
}

#endif
