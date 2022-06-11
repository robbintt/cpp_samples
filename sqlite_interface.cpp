/* from: https://www.sqlite.org/quickstart.html
 * c/c++ interface demo
 *
 * functions: sqlite3_open, sqlite3_exec, sqlite3_close, sqlite3_errmsg
 *            sqlite3_free
 *
 * From explanation:
 * > New applications should always invoke sqlite3_prepare_v2()
 * > instead of sqlite3_prepare(). The older sqlite3_prepare()
 * > is retained for backwards compatibility. But sqlite3_prepare_v2()
 * > provides a much better interface.
 *
 *  The sqlite3_exec() interface is a convenience wrapper that carries out all
 *  four of the above steps with a single function call. A callback function
 *  passed into sqlite3_exec() is used to process each row of the result set.
 *  The sqlite3_get_table() is another convenience wrapper that does all four
 *  of the above steps. The sqlite3_get_table() interface differs from
 *  sqlite3_exec() in that it stores the results of queries in heap memory
 *  rather than invoking a callback.

 * It is important to realize that neither sqlite3_exec() nor
 * sqlite3_get_table() do anything that cannot be accomplished
 * using the core routines. In fact, these wrappers are implemented
 * purely in terms of the core routines.
 */

#include <stdio.h>
#include <sqlite3.h>

static int callback(void *NotUsed, int argc, char **argv, char **azColName){
  int i;
  for(i=0; i<argc; i++){
    printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
  }
  printf("\n");
  return 0;
}

int main(int argc, char **argv){
  sqlite3 *db;
  char *zErrMsg = 0;
  int rc;

  if( argc!=3 ){
    fprintf(stderr, "Usage: %s DATABASE SQL-STATEMENT\n", argv[0]);
    return(1);
  }
  rc = sqlite3_open(argv[1], &db);
  if( rc ){
    fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return(1);
  }
  rc = sqlite3_exec(db, argv[2 c/c++ interface demo], callback, 0, &zErrMsg);
  if( rc!=SQLITE_OK ){
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
    sqlite3_free(zErrMsg);
  }
  sqlite3_close(db);
  return 0;
}
