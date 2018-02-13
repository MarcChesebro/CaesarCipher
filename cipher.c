#include <stdio.h>
#include "file_utils.h"
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

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

	for(int i = 0; i < strlen(key); i++){
		key[i] = tolower(key[i]);
	}
	removeKey(key, alph);
	strcpy(cipher, key);
	strcat(cipher, alph);
}

void encrypt(char* cipher, char* text){
	int index;
	//iterate over the text
	for(int i = 0; i < strlen(text); i++){
		
		if(isalpha(text[i])){
			
			if(isupper(text[i])){

				index = (text[i] - 'A'); //should get number of alphabet

				text[i] = toupper(cipher[index]);
			}else{
				//find the index
				index = (text[i] - 'a'); //should get number of alphabet
				//encript data
				text[i] = cipher[index];
			}
		}
	}
}

void decrypt(char* cipher, char* text){
	int temp;
	char* alphabet = "abcdefghijklmnopqrstuvwxyz";
	//iterates through the given text
	for(int i = 0; i < strlen(text); i++){
		//iterates through the cipher
		for(int j = 0; j < strlen(cipher); j++){
			//checks if the letter at the cipher == letter at text
			if(cipher[j] == tolower(text[i])){
				//if it does change the letter in text to
				//corresponding letter of alphabet
				if(isupper(text[i])){
					
					text[i] = toupper(alphabet[j]);
				}else{
					text[i] = alphabet[j];
				}
				break;
			}
		}
	}
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
	//char* temp;
	//FILE *fin, *fout;
	//fin = fopen(argv[1], "r");
	//fout = fopen(argv[3], "w");

	// Encryption
	if(strcmp(argv[4], "e") == 0){
		generateCipher(argv[2], cipher);
		printf("final cipher: %s\n", cipher);
		char* text;
		int fileSize = read_file(argv[1], &text);
		encrypt(cipher, text);
		write_file(argv[3], text, fileSize);
		//printf("\n%s\n", encrypt(cipher, text));	
	// Dycryption
	}else if(strcmp(argv[4], "d") == 0){
		generateCipher(argv[2], cipher);
		printf("final cipher: %s\n", cipher);
		char* text;
		int fileSize = read_file(argv[1], &text);
		decrypt(cipher, text);
		write_file(argv[3], text, fileSize);
	}
}
