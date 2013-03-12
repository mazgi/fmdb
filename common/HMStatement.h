//
//  HMStatement.h
//  fmdb
//
//  Created by matsuki hidenori on 3/11/13.
//
//

#ifndef __fmdb__HMStatement__
#define __fmdb__HMStatement__

#include <iostream>
#include <sqlite3.h>

class HMStatement
{
    sqlite3_stmt *statement_;
public:
    inline void close()
    {
        if (statement_) {
            sqlite3_finalize(statement_);
            statement_ = NULL;
        }
    }
};

#endif /* defined(__fmdb__HMStatement__) */
