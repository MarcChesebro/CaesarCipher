#include <stdio.h>
#include "file_utils.h"
#include <string.h>
#include <stdbool.h>

bool isIn(char ch, char* str){

	int size = strlen(str);
	for(int i = 0; i < size; i++){
		if(str[i] == ch){
			return true;
		}
	}	
	return false;
}

void removeKey(char* key, char* cipher){
	//remove any char in key from cipher
	int cipherSize = strlen(cipher);
	char final[] = "abcdefghijklmnopqrstuvwxyz";
	int j = 0;

	for(int i = 0; i <= cipherSize; i++){
		if(!isIn(cipher[i], key)){
			final[j] = cipher[i];
			j++;	
		}
	}	
	strcpy(cipher, final);
}

void generateCipher(char* key, char* cipher){
	char alph[] = "abcdefghijklmnopqrstuvwxyz";
	removeKey(key, alph);
	strcpy(cipher, key);
	strcat(cipher, alph);
}

int main(int argc, char** argv){
	
	// Check inputs
	if(argc == 5){
		if(strcmp(argv[4], "d") != 0 && strcmp(argv[4], "e") != 0){
			printf("last argument must be \'e\' or \'d\'.");
			return 1;
		}
	}else{
		printf("Incorrect number of arguments\n");
		return 1;
	}
	char cipher[26];

	// Encryption
	if(strcmp(argv[4], "e") == 0){
	generateCipher(argv[2], cipher);
	printf("final cipher: %s\n", cipher);
	
	// Dycryption
	}else if(strcmp(argv[4], "d") == 0){

	}
}
