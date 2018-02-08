/*************************************************************
* Provides simple file utilities:
* reading files
* writing to files
*
* Author: Marc Chesebro
*************************************************************/

#include "file_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

/*
*function that reads a file
*char* filename: path of file relative to exe
*char** buffer: pointer to the pointer that hold the files data
*returns the size of the file read, or -1 if the file could not be read
*/
int read_file( char* filename, char **buffer ){
	
	//calculate size of file using stat
	struct stat st;
	stat(filename, &st);
	int size = st.st_size;

	//allocate memory for the data in the file
	*buffer = (char*)malloc(size);
	
	//open file
	FILE* file = fopen(filename, "r");
	
	//check if we successfully grabed the file
	if(file == NULL){
		//print error to error stream
		fprintf(stderr, "Could not open file");
		//return fail
		return -1;
	}	
	
	//determine the number of characters in the file
	int numElements = size / (int)sizeof(char);
	//load the characters into the buffer with fread
	fread(*buffer, sizeof(char), numElements, file);
	
	//return size of the file read
	return size;
}
/*
*Function that writes to a file
*char* filename: path to write to/create
*char* buffer: data to be written
*int size: size of data
*returns 0 on success, or -1 on failure
*/
int write_file( char* filename, char *buffer, int size){
	
	//open the file
	FILE* file = fopen(filename, "w");
	
	//try to write to the file 
	int rSize = fwrite(buffer, sizeof(char), size, file);
	
	//if the size that was written was different than the
	//size we were trying to write return -1 and print an error
	if(rSize != size){
		fprintf(stderr, "Could not write to the file");
		return -1;
	}
	return 0;
}
