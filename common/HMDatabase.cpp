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
#warning Not implemented.

    if (!db_) {
        return false;
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
