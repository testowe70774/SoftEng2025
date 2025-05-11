#ifndef _SORTTECHFACTORY_H
#define _SORTTECHFACTORY_H


#include "SortTech.h"
#include "SortError.h"
#include "Bubble.h"
#include "Quick.h"
#include "Insert.h"
#include "Merge.h"
#include "Radix.h"
#include "Select.h"

#include <deque>
#include <memory>

enum SortTechType
{
    STT_NONE = 0,
    STT_BUBBLE,
    STT_INSERT,
    STT_MERGE,
    STT_QUICK,
    STT_RADIX,
    STT_SELECT
};

template <template <typename...> class Container>
struct is_std_vector : std::false_type
{
};

template <> struct is_std_vector<std::vector> : std::true_type
{
};


template <template <typename...> class Container>
struct is_std_list : std::false_type
{
};

template <> struct is_std_list<std::list> : std::true_type
{
};


template <template <typename...> class Container>
struct is_std_deque : std::false_type
{
};

template <> struct is_std_deque<std::deque> : std::true_type
{
};

// This class extends the "factory" design pattern and is responsible for
// selecting and creating the appropriate sorting technique. The choice of
// technique should be made at compile time by specializing the SortData class
// templates.
class SortTechFactory {
public:
    template <class T, template <typename...> class Container>
    static inline std::unique_ptr<SortTech<T, Container>>
    createSorter(SortError& error);
};
template <class T, template <typename...> class Container>
inline std::unique_ptr<SortTech<T, Container>>
SortTechFactory::createSorter(SortError& error)
{
    error = SE_SUCCESS;
    return nullptr;
}

#endif
