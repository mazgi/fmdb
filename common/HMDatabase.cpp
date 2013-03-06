//
//  HMDatabase.cpp
//  fmdb
//
//  Created by matsuki hidenori on 3/5/13.
//
//

#include "HMDatabase.h"

HMDatabase *HMDatabase::databaseWithPath(const char *path)
{
#warning Not implemented.
    return new HMDatabase();
    return NULL;
}

bool HMDatabase::isSQLiteThreadSafe()
{
    return sqlite3_threadsafe() != 0;
}

int HMDatabase::lastErrorCode()
{
    return sqlite3_errcode(db_);
}

const char *HMDatabase::lastErrorMessage()
{
    return sqlite3_errmsg(db_);
}

bool HMDatabase::hadError()
{
    int lastErrCode = this->lastErrorCode();
    return (lastErrCode > SQLITE_OK && lastErrCode < SQLITE_ROW);
}

bool HMDatabase::open()
{
#warning Not implemented.
    return false;
}

void HMDatabase::setShouldCacheStatements(bool value)
{
#warning Not implemented.
}

int HMDatabase::intForQuery(void *objs, ...)
{
#warning Not implemented.
    return 0;
}

long HMDatabase::longForQuery(void *objs, ...)
{
#warning Not implemented.
    return 0l;
}

bool HMDatabase::boolForQuery(void *objs, ...)
{
#warning Not implemented.
    return false;
}

double HMDatabase::doubleForQuery(void *objs, ...)
{
#warning Not implemented.
    return 0.0;
}

const char *HMDatabase::stringForQuery(void *objs, ...)
{
#warning Not implemented.
    return NULL;
}

HMData *HMDatabase::dataForQuery(void *objs, ...)
{
#warning Not implemented.
    return NULL;
}

HMDate *HMDatabase::dateForQuery(void *objs, ...)
{
#warning Not implemented.
    return NULL;
}

bool HMDatabase::rollback()
{
#warning Not implemented.
    return false;
}

bool HMDatabase::commit()
{
#warning Not implemented.
    return false;
}

bool HMDatabase::beginTransaction()
{
#warning Not implemented.
    return false;
}

bool HMDatabase::hasOpenResultSets()
{
#warning Not implemented.
    return false;
}

HMResultSet *HMDatabase::getTableSchema(const char *tableName)
{
#warning Not implemented.
    return NULL;
}

bool HMDatabase::updateWithErrorAndBindgings(const char *sql, HMError **outErr, ...)
{
#warning Not implemented.
    return false;
}

bool HMDatabase::executeUpdate(const char *sql, ...)
{
#warning Not implemented.
    return false;
}

bool HMDatabase::executeUpdateWithFormat(const char *format, ...)
{
#warning Not implemented.
    return false;
}

bool HMDatabase::executeUpdateWithArgumentsInArray(const char *sql, ...)
{
#warning Not implemented.
    return false;
}

bool HMDatabase::executeUpdateWithParameterDictionary(const char *sql, ...)
{
#warning Not implemented.
    return false;
}

HMResultSet *HMDatabase::executeQuery(const char *sql, ...)
{
#warning Not implemented.
    return NULL;
}

HMResultSet *HMDatabase::executeQueryWithFormat(const char *format, ...)
{
#warning Not implemented.
    return NULL;
}

HMResultSet *HMDatabase::executeQueryWithArgumentsInArray(const char *sql, ...)
{
#warning Not implemented.
    return NULL;
}

HMResultSet *HMDatabase::executeQueryWithParameterDictionary(const char *sql, ...)
{
#warning Not implemented.
    return NULL;
}
