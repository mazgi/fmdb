//
//  HMDatabase.h
//  fmdb
//
//  Created by matsuki hidenori on 3/5/13.
//
//

#ifndef __fmdb__HMDatabase__
#define __fmdb__HMDatabase__

#include <iostream>
#include <sqlite3.h>
#include "HMResultSet.h"

//TODO: create classes and impl.
typedef void HMError; //TODO: STLあたりから型探してくる

class HMDatabase
{
    sqlite3 *db_;
    int busyRetryTimeout_;
    bool shouldCacheStatements_;
public:
    static HMDatabase *databaseWithPath(const char *path);
    static bool isSQLiteThreadSafe();
    int lastErrorCode();
    const char *lastErrorMessage();
    bool hadError();
    bool open();
    void setShouldCacheStatements(bool value);
    int intForQuery(void *objs, ...);
    long longForQuery(void *objs, ...);
    bool boolForQuery(void *objs, ...);
    double doubleForQuery(void *objs, ...);
    const char *stringForQuery(void *objs, ...);
    HMData *dataForQuery(void *objs, ...);
    HMDate *dateForQuery(void *objs, ...);
    bool rollback();
    bool commit();
    bool beginTransaction();
    bool hasOpenResultSets();
    HMResultSet *getTableSchema(const char *tableName);
    bool updateWithErrorAndBindings(const char *sql, HMError **outErr, ...);
    bool executeUpdate(const char *sql, ...);
    bool executeUpdateWithFormat(const char *format, ...);
    bool executeUpdateWithArgumentsInArray(const char *sql, ...);
    bool executeUpdateWithParameterDictionary(const char *sql, ...);
    HMResultSet *executeQuery(const char *sql, ...);
    HMResultSet *executeQueryWithFormat(const char *format, ...);
    HMResultSet *executeQueryWithArgumentsInArray(const char *sql, ...);
    HMResultSet *executeQueryWithParameterDictionary(const char *sql, ...);
    int changes();
    void setBusyRetryTimeout(int value);
    int getBusyRetryTimeout();
    bool close();
    bool columnExistsInTableWithName(const char *columnName, const char *tableName);
    bool tableExists(const char *tableName);
    HMResultSet *getSchema();
    bool shouldCacheStatements()
    {
        return shouldCacheStatements_;
    }
    HMDictionary *cachedStatements();
    void setCachedStatements(HMDictionary *value);
    static const char *sqliteLibVersion()
    {
        return sqlite3_libversion();
    }
};

#endif /* defined(__fmdb__HMDatabase__) */
