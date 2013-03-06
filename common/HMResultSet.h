//
//  HMResultSet.h
//  fmdb
//
//  Created by matsuki hidenori on 3/6/13.
//
//

#ifndef __fmdb__HMResultSet__
#define __fmdb__HMResultSet__

#include <iostream>

//TODO: create classes and impl.
typedef void HMData; //TODO: STLあたりから型探してくる
typedef void HMDate; //TODO: STLあたりから型探してくる

class HMDictionary
{
public:
    void *objectForKey(const char *aKey)
    {
#warning Not implemented.
        //TODO: STLあたりから型探してくる
        return NULL;
    }
};

class HMResultSet
{
public:
    void close();
    bool next();
    int intForColumn(const char *columnName);
    int intForColumnIndex(int columnIdx);
    long longForColumn(const char *columnName);
    long longForColumnIndex(int columnIdx);
    long long int longLongIntForColumn(const char *columnName);
    long long int longLongIntForColumnIndex(int columnIdx);
    unsigned long long int unsignedLongLongIntForColumn(const char *columnName);
    unsigned long long int unsignedLongLongIntForColumnIndex(int columnIdx);
    bool boolForColumn(const char *columnName);
    bool boolForColumnIndex(int columnIdx);
    double doubleForColumn(const char *columnName);
    double doubleForColumnIndex(int columnIdx);
    char *stringForColumn(const char *columnName);
    char *stringForColumnIndex(int columnIdx);
    HMData *dataForColumn(const char *columnName);
    HMData *dataForColumnIndex(int columnIdx);
    HMDate *dateForColumn(const char *columnName);
    HMDate *dateForColumnIndex(int columnIdx);
    int columnIndexForName(const char *columnName);
    char *columnNameForIndex(int columnIdx);
    char *operator[](int idx);
    char *operator[](const char *key);
    HMDictionary *resultDictionary();
};

#endif /* defined(__fmdb__HMResultSet__) */
