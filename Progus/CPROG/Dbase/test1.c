#include <stdio.h>
#include <sqlite3.h>

int main()
{
	sqlite3 *db;
	sqlite3_stmt *res;
	
	char *sql_command;
	char *err_msg = 0;
	
	int rc;
	rc = sqlite3_open("test.db", &db);
	
	if(rc!=SQLITE_OK)
	{
		fprintf(stderr, "Failed to open test.db database. ERROR: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		return 1;
	}
	
	//sql_command = "DROP TABLE IF EXISTS IDB;"
		//		  "CREATE TABLE IDB(ID INT PRIMARY KEY, Name_of_the_things TEXT(6), Price INT);"
			//	  "INSERT INTO IDB(Name_of_the_things) VALUES('processor');";
	sql_command = "INSERT INTO IDB(Name) VALUES('proc');";
	rc = sqlite3_prepare_v2(db, sql_command, -1, &res, NULL);
	
	if(rc != SQLITE_OK)
	{
		fprintf(stderr, "Failed to insert data into IDB. ERROR: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		return 3;
	}
	
	rc = sqlite3_step(res);
	if(rc != SQLITE_OK)
	{
		fprintf(stderr, "Failed to execute the sql commands '%s'. ERROR!", sql_command);
		return 3;
	}
	printf("Execute complete\n");
	sqlite3_finalize(res);
	sqlite3_free(err_msg);
	sqlite3_close(db);
	
	return 0;
}
