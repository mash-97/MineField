#define _GNU_SOURCE
#include <stdio.h>
#include <sqlite3.h>
#include <stdlib.h>
#include <strings.h>
/*
int asprintf(char **strp, const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	int r = vasprintf(strp, fmt, ap);
	va_end(ap);
	return r;
}
*/
int main()
{
	sqlite3 * db;
	sqlite3_stmt * stmt;
	
	char * db_name = "wassen.test.db";
	//char * errmsg;
	char * sql_command;
	int rc;
	
	rc = sqlite3_open(db_name, &db);
	if(rc != SQLITE_OK)
	{
		fprintf(stderr, "ERROR: opening %s: %s		#rc: %d\n", db_name, sqlite3_errmsg(db), rc);
		goto out;
	}
	printf("%s is open successfully. return code: %d\n", db_name, rc);
	
	/*
	sqlite3_prepare_v2(db, "CREATE TABLE demo (Name TEXT, Age INTEGER);", -1, &stmt, NULL);
	rc = sqlite3_step(stmt);
	if(rc != SQLITE_DONE)
	{
		fprintf(stderr, "Error: Creating the table in the %s: %s		#rc: %d\n", db_name, sqlite3_errmsg(db), rc);
		goto out;
	}
	printf("The table is created successfully in %s. return code: %d\n", db_name, rc);
	sqlite3_finalize(stmt);
	*/
	
	// inserting data to the demo table
	asprintf(&sql_command, "INSERT INTO demo(Name, Age) VALUES('%s', '%d');", "Mashiur Rahman", 21);
	
	sqlite3_prepare_v2(db, sql_command, -1, &stmt, NULL);
	rc = sqlite3_step(stmt);
	
	if(rc != SQLITE_DONE)
	{
		printf("ERROR inserting data: %s\n", sqlite3_errmsg(db));
		goto out;
	}
	sqlite3_finalize(stmt);
	free(sql_command);
	
	
	out:
	sqlite3_close(db);
	printf("Database closed successfully.\n");
	
	return 0;
}
	
