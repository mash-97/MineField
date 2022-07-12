#include <stdio.h>
#include <sqlite3.h>

int main()
{
	sqlite3 *db;

	int rc;
	
	rc = sqlite3_open("test", &db);
	
	if(rc != SQLITE_OK)
	{
		printf("Error occured to open the database in memory: %s\n", sqlite3_errmsg(db));
		goto OUT;
	}
	
	printf("Suucces to open the database\n");
	OUT:
	sqlite3_close(db);
	printf("Database closed");
	return 0;
}
