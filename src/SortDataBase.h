#ifndef _SORTDATABASE_H
#define _SORTDATABASE_H


#include "OpState.h"


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

//Interface for data wrapper class
class CLIENT_API SortDataBase {
};
#endif
