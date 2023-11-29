#include<string.h>
#include<stdio.h>
#include<stdlib.h>

int	number_list[30000];
char	string_list[30000];
int	currentpos = 0;
int	noticeposition_command = 0;
int	noticeposition_loop = 0;
int	noticeposition_loopvar = 0;

void	clear_arrays() {
	for (int i = 0; i<30000; i++) {
		number_list[i] = 0;
		string_list[i] = ' ';
	}
}

void brainfuck(char *instructions) {
	clear_arrays();
	int instructionlen = strlen(instructions);	
	if (instructionlen > 0) {
		for(int i = 0; i < instructionlen; i++) {
			if (instructions[i] == '>') {
				currentpos++;
			} else if (instructions[i] == '<') {
				currentpos--;
			} else if (instructions[i] == ']') {
				if (number_list[noticeposition_loopvar] > 0) {
					i = noticeposition_loop;
				}
			} else if (instructions[i] == '[') {
				noticeposition_loop = i;
				noticeposition_loopvar = currentpos;
			} else if (instructions[i] == '-') {
				number_list[currentpos] -= 1;
			} else if (instructions[i] == '+') {
				number_list[currentpos] += 1;
			} else if (instructions[i] == ',') {
				number_list[currentpos] = getchar();
			} else if (instructions[i] == '.') {
				printf("%c",number_list[currentpos]);
			} else if (instructions[i] == '(') {
				noticeposition_command = currentpos;
			} else if (instructions[i] == ')') {
				char commandtoexe[(currentpos-noticeposition_command)+1];
				int currommand = 0;
				for (int i = noticeposition_command; i<currentpos; i++) {
					commandtoexe[currommand] = number_list[i];
					currommand++;
				}
				char *pcte = commandtoexe;
				system(pcte);
			} else if (instructions[i] == '!') {
				if (number_list[currentpos] == number_list[currentpos+1]) {
					int temporaryi = i;
					while(instructions[temporaryi] != ';') {
						temporaryi++;
					}
					i = temporaryi;
				}
			}
		}
	}	
}

