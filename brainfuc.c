/* ************************************************************************** **
                
// date: Sat Aug 12 12:46:12 AM EEST 2023
// name: 
// file: brainfuc.c
                
** ************************************************************************** */

#include<string.h>
#include<stdio.h>

int	number_list[30000];
char	string_list[30000];
int	currentpos = 0;

void	clear_arrays() {
	for (int i = 0; i<30000; i++) {
		number_list[i] = 0;
		string_list[i] = ' ';
	}
}

//TODO: implement [
//TODO: implement ]
//TODO: implement (
//TODO: implement )
void increment_the_byte() {
	number_list[currentpos] += 1;
}
void decrement_the_byte() {
	number_list[currentpos] -= 1;
}
void increment_the_pointer() {
	currentpos++;
}
void decrement_the_pointer() {
	currentpos--;
}
//TODO: implement fn brainfuck(list instruction)
void brainfuck(char *instructions) {
	clear_arrays();
	int instructionlen = strlen(instructions);	
	if (instructionlen > 0) {
		for(int i = 0; i < instructionlen; i++) {
			if (instructions[i] == '>') {
				increment_the_pointer();
			} else if (instructions[i] == '<') {
				decrement_the_pointer();
			} else if (instructions[i] == ']') {
			} else if (instructions[i] == '[') {
			} else if (instructions[i] == '-') {
				decrement_the_byte();
			} else if (instructions[i] == '+') {
				increment_the_byte();
			} else if (instructions[i] == ',') {
				number_list[currentpos] = getchar();
			} else if (instructions[i] == '.') {
				printf("%c",number_list[currentpos]);
			} else if (instructions[i] == '(') {
			} else if (instructions[i] == ')') {
			}
		}
	}	
}

