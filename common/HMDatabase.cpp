//
//  HMDatabase.cpp
//  fmdb
//
//  Created by matsuki hidenori on 3/5/13.
//
//

#include "HMDatabase.h"
#include "HMResultSet.h"
#include "HMStatement.h"
#include <unistd.h>

#pragma mark - initialize/constract

HMDatabase::HMDatabase(const char *path)
:path_(path)
{
    HMLog("init(%p)", this);
    db_ = NULL;
}

HMDatabase::~HMDatabase()
{
    HMLog("delete(%p)", this);
}

bool HMDatabase::open()
{
    HMLog("open(%p)", this);
    if (db_) {
        return true;
    }
    int result = sqlite3_open(path_.c_str(), &db_);
    if (result != SQLITE_OK) {
        HMLog("open falied!(%p)", this);
        return false;
    }
    return true;
}

#if SQLITE_VERSION_NUMBER >= 3005000
bool HMDatabase::open(const int flags, const char *vfs)
{
    HMLog("open(%p)", this);
    if (db_) {
        return true;
    }
    int result = sqlite3_open_v2(path_.c_str(), &db_, flags, vfs);
    if (result != SQLITE_OK) {
        HMLog("open falied!(%p)", this);
        return false;
    }
    return true;
}
#endif

bool HMDatabase::close()
{
    clearCachedStatements();
    closeOpenResultSets();

    if (!db_) {
        return true;
    }

    int  rc = SQLITE_OK;
    bool retry = false;
    int numberOfRetries = 0;
    bool triedFinalizingOpenStatements = false;

    do {
        retry   = false;
        rc      = sqlite3_close(db_);
        if (rc == SQLITE_BUSY || rc == SQLITE_LOCKED) {
            retry = true;
            usleep(20);

            if (busyRetryTimeout_ && (numberOfRetries++ > busyRetryTimeout_)) {
                HMLog("Database (%p) busy, unable to close.", db_);
                return false;
            }

            if (!triedFinalizingOpenStatements) {
                triedFinalizingOpenStatements = true;
                sqlite3_stmt *pStmt = NULL;
                while ((pStmt = sqlite3_next_stmt(db_, NULL)) != 0) {
                    HMLog("Closing leaked statement (%p).", pStmt);
                    sqlite3_finalize(pStmt);
                }
            }
        } else if (rc != SQLITE_OK) {
            HMLog("error closing!: %d", rc);
        }
    } while (retry);
    db_ = NULL;
    return true;
}

void HMDatabase::clearCachedStatements()
{
    for (auto it = cachedStatements_.begin(); it != cachedStatements_.end(); it++) {
        it->second.close();
    }
    cachedStatements_.clear();
}

void HMDatabase::closeOpenResultSets()
{
    for (auto it = openedResultSets_.begin(); it != openedResultSets_.end(); it++) {
        it->setParentDB(nullptr);
        it->close();
    }
    openedResultSets_.clear();
}

#pragma mark - status

bool HMDatabase::goodConnection()
{
    if (!db_) {
        return false;
    }

    HMResultSet *rs = executeQuery("select name from sqlite_master where type='table'");
    if (rs) {
        rs->close();
        return true;
    }

    return false;
}

void HMDatabase::setCachedStatements(HMDictionary *value)
{
#warning Not implemented.
}

#pragma mark -

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
    bool success = executeUpdate("rollback transaction");
    if (success) {
        inTransaction_ = false;
    }
    return success;
}

bool HMDatabase::commit()
{
    bool success = executeUpdate("commit transaction");
    if (success) {
        inTransaction_ = false;
    }
    return success;
}

bool HMDatabase::beginTransaction()
{
    bool success = executeUpdate("begin exclusive transaction");
    if (success) {
        inTransaction_ = true;
    }
    return success;
}

HMResultSet *HMDatabase::getTableSchema(const char *tableName)
{
#warning Not implemented.
    return NULL;
}

bool HMDatabase::updateWithErrorAndBindings(const char *sql, HMError **outErr, ...)
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

int HMDatabase::changes()
{
#warning Not implemented.
    return 0;
}

bool HMDatabase::columnExistsInTableWithName(const char *columnName, const char *tableName)
{
#warning Not implemented.
    return false;
}

bool HMDatabase::tableExists(const char *tableName)
{
#warning Not implemented.
    return false;
}

HMResultSet *HMDatabase::getSchema()
{
    //result colums: type[STRING], name[STRING],tbl_name[STRING],rootpage[INTEGER],sql[STRING]
    HMResultSet *rs = this->executeQuery("SELECT type, name, tbl_name, rootpage, sql FROM (SELECT * FROM sqlite_master UNION ALL SELECT * FROM sqlite_temp_master) WHERE type != 'meta' AND name NOT LIKE 'sqlite_%' ORDER BY tbl_name, type DESC, name");

    return rs;
}

HMDictionary *HMDatabase::cachedStatements()
{
#warning Not implemented.
    return NULL;
}
