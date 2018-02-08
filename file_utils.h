/*************************************************************
* Provides simple file utilities:
* reading files
* writing to files
*
* Author: Marc Chesebro
*************************************************************/

//include guards
#ifndef file_utils
#define file_utils

/*
*function that reads a file
*char* filename: path of file relative to exe
*char** buffer: pointer to the pointer that hold the files data
*returns the size of the file read, or -1 if the file could not be read
*/
int read_file( char* filename, char **buffer );

/*
*Function that writes to a file
*char* filename: path to write to/create
*char* buffer: data to be written
*int size: size of data
*returns 0 on success, or -1 on failure
*/
int write_file( char* filename, char *buffer, int size);

#endif
