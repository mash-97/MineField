#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// POSIX dependencies
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>


int isDirectory(const char * path)
{
	struct stat status;
	stat(path, &status);
	if(S_ISDIR(status.st_mode) == 0)
		return 0;
	return 1;
}

void rmtree(const char *path)
{
	size_t path_len;
	char *full_path;
	DIR *dir;
	
	struct stat stat_path, stat_entry;
	struct dirent * entry;
	
	stat(path, &stat_path);
	// if path does not exists or is not dir -exit with status -1
	if(S_ISDIR(stat_path.st_mode) == 0)
		exit(1);
	
	// if not possible to read the directory for this user
	if((dir = opendir(path)) == NULL)
	{	
		fprintf(stderr, "%s: %s\n", "Can't open directory", path);
		exit(2);
	}
	
	// the length of the path
	path_len = strlen(path);
	
	// iteration through entries in the directory
	while((entry = readdir(dir)) != NULL)
	{
		// skip entries "." and ".."
		if(!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, ".."))
			continue;
		
		// determinate a full path of an entry
		full_path = calloc(path_len + strlen(entry->d_name)+1, sizeof(char));
		strcpy(full_path, path);
		strcat(full_path, "/");
		strcat(full_path, entry->d_name);
		
		// stat for the entry
		stat(full_path, &stat_entry);
		
		// recursively remove a nested directory
		if(S_ISDIR(stat_entry.st_mode) != 0)
		{
			rmtree(full_path);
			continue;
		}
		
		// remove a file object
		if(unlink(full_path) == 0)
			printf("Removed a file: %s\n", full_path);
		else
			printf("Can't remove a file: %s\n", full_path);
	}
	
	// remove the devastated directory and close the object of it
	if(rmdir(path) == 0)
		printf("Removed a direcotry: %s\n", path);
	else
		printf("Can't remove a directory: %s\n", path);
	
	closedir(dir);
}

int main()
{
	printf("Enter the directory name you want to delete: ");
	char directory_name[100];
	scanf(" %s", directory_name);
	if(isDirectory(directory_name)==1)
		printf("Yes! It's a directory\n");
	
	main();
	
	return 0;
}
