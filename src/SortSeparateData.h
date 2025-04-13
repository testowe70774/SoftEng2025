#ifndef _SORTSEPARATEDATA_H
#define _SORTSEPARATEDATA_H


#include "SortData.h"
#include "SortError.h"

#ifdef _WIN32
#ifdef BUILDING_CLIENT_DLL
#define CLIENT_API __declspec(dllexport)
#else
#define CLIENT_API __declspec(dllimport)
#endif
#else
// -fvisibility=hidden
#define CLIENT_API __attribute__((visibility("default")))
#endif

//Wrapper around input container to be sorted with one of SortTech child classes. Result of the sorting will be stored in separate container.
template<class T, template<typename...> class Container = std::vector>
class CLIENT_API SortSeparateData : public SortData<T, Container> {
  private:
    Container<T> m_output;


  public:
    inline SortError swap(typename Container<T> & sorted);

};
template<class T, template<typename...> class Container>
inline SortError SortSeparateData<T, Container>::swap(typename Container<T> & sorted) {
  return SE_SUCCESS;
}

#endif
