//
//  HMDatabase.h
//  fmdb
//
//  Created by matsuki hidenori on 3/5/13.
//
//

#ifndef __fmdb__HMDatabase__
#define __fmdb__HMDatabase__

#ifndef HMLog
#define HMLog(fmt, ...)
#endif

#include <sqlite3.h>
#include <iostream>
#include <map>
#include <list>

//TODO: create classes and impl.
typedef void HMError; //TODO: STLあたりから型探してくる

class HMResultSet;
class HMStatement;
class HMData;
class HMDate;
class HMDictionary;

class HMDatabase
{
    std::string path_;
    sqlite3 *db_;
    int busyRetryTimeout_;
    bool shouldCacheStatements_;
    std::map<std::string, HMStatement> cachedStatements_;
    std::list<HMResultSet> openedResultSets_;
    std::list<void *> openedFunctions_; //TODO: lambda
public:
#pragma mark - initialize/constract
    HMDatabase(const char *path);
    ~HMDatabase();
    bool open();
#if SQLITE_VERSION_NUMBER >= 3005000
    bool open(const int flags, const char *vfs);
#endif
    bool close();
    void setShouldCacheStatements(bool value);
#pragma mark - status
    inline static bool isSQLiteThreadSafe()
    {
        return sqlite3_threadsafe() != 0;
    }
    inline int lastErrorCode()
    {
        return sqlite3_errcode(db_);
    }
    inline const char *lastErrorMessage()
    {
        return sqlite3_errmsg(db_);
    }
    inline bool hadError()
    {
        return (lastErrorCode() > SQLITE_OK && lastErrorCode() < SQLITE_ROW);
    }
    inline bool hasOpenResultSets()
    {
        return openedResultSets_.size() > 0;
    }
    bool columnExistsInTableWithName(const char *columnName, const char *tableName);
    bool tableExists(const char *tableName);
    HMResultSet *getTableSchema(const char *tableName);
    HMResultSet *getSchema();
    inline static const char *sqliteLibVersion()
    {
        return sqlite3_libversion();
    }
#pragma mark - query
    int intForQuery(void *objs, ...);
    long longForQuery(void *objs, ...);
    bool boolForQuery(void *objs, ...);
    double doubleForQuery(void *objs, ...);
    const char *stringForQuery(void *objs, ...);
    HMData *dataForQuery(void *objs, ...);
    HMDate *dateForQuery(void *objs, ...);
#pragma mark - execute
    bool beginTransaction();
    bool rollback();
    bool commit();

#pragma mark -
    static HMDatabase *databaseWithPath(const char *path);
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
    void setBusyRetryTimeout(int value)
    {
        busyRetryTimeout_ = value;
    }
    int getBusyRetryTimeout()
    {
        return busyRetryTimeout_;
    }
    bool shouldCacheStatements()
    {
        return shouldCacheStatements_;
    }
    HMDictionary *cachedStatements();
    void setCachedStatements(HMDictionary *value);
};

#endif /* defined(__fmdb__HMDatabase__) */
