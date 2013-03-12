//
//  HMResultSet.cpp
//  fmdb
//
//  Created by matsuki hidenori on 3/6/13.
//
//

#include "HMResultSet.h"
#include "HMDatabase.h"

void HMResultSet::setParentDB(HMDatabase *newDb)
{
#warning Not implemented.
}

void HMResultSet::close()
{
#warning Not implemented.
}

bool HMResultSet::next()
{
#warning Not implemented.
    return false;
}

int HMResultSet::intForColumn(const char *columnName)
{
#warning Not implemented.
    return 0;
}

int HMResultSet::intForColumnIndex(int columnIdx)
{
#warning Not implemented.
    return 0;
}

long HMResultSet::longForColumn(const char *columnName)
{
#warning Not implemented.
    return 0l;
}

long HMResultSet::longForColumnIndex(int columnIdx)
{
#warning Not implemented.
    return 0l;
}

long long int HMResultSet::longLongIntForColumn(const char *columnName)
{
#warning Not implemented.
    return 0ll;
}

long long int HMResultSet::longLongIntForColumnIndex(int columnIdx)
{
#warning Not implemented.
    return 0ll;
}

unsigned long long int HMResultSet::unsignedLongLongIntForColumn(const char *columnName)
{
#warning Not implemented.
    return 0ull;
}

unsigned long long int HMResultSet::unsignedLongLongIntForColumnIndex(int columnIdx)
{
#warning Not implemented.
    return 0ull;
}

bool HMResultSet::boolForColumn(const char *columnName)
{
#warning Not implemented.
    return false;
}

bool HMResultSet::boolForColumnIndex(int columnIdx)
{
#warning Not implemented.
    return false;
}

double HMResultSet::doubleForColumn(const char *columnName)
{
#warning Not implemented.
    return 0.0;
}

double HMResultSet::doubleForColumnIndex(int columnIdx)
{
#warning Not implemented.
    return 0.0;
}

char *HMResultSet::stringForColumn(const char *columnName)
{
#warning Not implemented.
    return NULL;
}

char *HMResultSet::stringForColumnIndex(int columnIdx)
{
#warning Not implemented.
    return NULL;
}

HMData *HMResultSet::dataForColumn(const char *columnName)
{
#warning Not implemented.
    return NULL;
}

HMData *HMResultSet::dataForColumnIndex(int columnIdx)
{
#warning Not implemented.
    return NULL;
}

HMDate *HMResultSet::dateForColumn(const char *columnName)
{
#warning Not implemented.
    return NULL;
}

HMDate *HMResultSet::dateForColumnIndex(int columnIdx)
{
#warning Not implemented.
    return NULL;
}

int HMResultSet::columnIndexForName(const char *columnName)
{
#warning Not implemented.
    return 0;
}

char *HMResultSet::columnNameForIndex(int columnIdx)
{
#warning Not implemented.
    return NULL;
}

char *HMResultSet::operator[](int idx)
{
#warning Not implemented.
    return NULL;
}

char *HMResultSet::operator[](const char *key)
{
#warning Not implemented.
    return NULL;
}

HMDictionary *HMResultSet::resultDictionary()
{
#warning Not implemented.
    return NULL;
}

bool HMResultSet::columnIndexIsNull(int columnIdx)
{
#warning Not implemented.
    return false;
}

bool HMResultSet::columnIsNull(const char *columnName)
{
#warning Not implemented.
    return false;
}

bool HMResultSet::hasAnotherRow()
{
#warning Not implemented.
    return false;
}

const unsigned char *HMResultSet::UTF8StringForColumnIndex(int columnIdx)
{
#warning Not implemented.
    return NULL;
}

const unsigned char *HMResultSet::UTF8StringForColumnName(const char *columnName)
{
#warning Not implemented.
    return NULL;
}
