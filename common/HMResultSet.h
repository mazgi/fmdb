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

class HMEnumerator
{
    //TODO: STLあたりから型探してくる
public:
    void *nextObject()
    {
#warning Not implemented.
        return NULL;
    }
};

class HMData
{
    //TODO: STLあたりから型探してくる
public:
    unsigned long length()
    {
        return 0ul;
    }
};

class HMDictionary
{
    //TODO: STLあたりから型探してくる
public:
    void *objectForKey(const char *aKey)
    {
#warning Not implemented.
        return NULL;
    }
    HMEnumerator *objectEnumerator()
    {
#warning Not implemented.
        return NULL;
    }
};

class HMDate
{
public:
    static HMDate *date()
    {
#warning Not implemented.
        //TODO: STLあたりから型探してくる
        return NULL;
    }
    static HMDate *dateWithTimeIntervalSince1970(double secs)
    {
#warning Not implemented.
        //TODO: STLあたりから型探してくる
        return NULL;
    }
    double timeIntervalSinceDate(HMDate *anotherDate)
    {
#warning Not implemented.
        //TODO: STLあたりから型探してくる
        return 0.0;
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
    bool columnIndexIsNull(int columnIdx);
    bool columnIsNull(const char *columnName);
    bool hasAnotherRow();
    const unsigned char *UTF8StringForColumnIndex(int columnIdx);
    const unsigned char *UTF8StringForColumnName(const char *columnName);
};

#endif /* defined(__fmdb__HMResultSet__) */
