// shell.cpp
//
// A C++ implementation of a basic shell with a 
// built-in history function similar to the UNIX 
// equivalent.
// (c) 2016 zubernetes

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <vector>

#define MAX_CMD_LEN 130
#define HISTORY_COUNT 10

pid_t wait(int *status);
void exit(int status);

void parse(char* line, char** argv) {
	while (*line != '\0') {
		while (*line == ' '  || 
			   *line == '\t' ||
			   *line == '\n') {
			*line++ = '\0';
		}
		
		*argv++ = line;

		while (*line != '\0' && 
			   *line != ' '  &&
			   *line != '\t' && 
               *line != '\n') {
			line++;
		}
	}
}

void launch_osh(char** argv) {
	pid_t pid;
	int status;

	// create a new process
	pid = fork();

	if (pid < 0) {
		std::cerr << "Fork Failed.\n";
		exit(1);
	} else if (pid == 0) {
		if (execvp(*argv, argv) < 0) {       // executes PATH program
			std::cout << "**Error: exec failed\n";
			exit(1);
		}
	} else {
		while (wait(&status) != pid)
			;
	}
}

int main() {
	// history buffer size
	int history_count = 0;
	std::string history[1024];
	char line[1024];
	char* argv[64];
	bool status = true;

	while(status) {
		std::cout << "osh> ";
		gets(line);             // unsafe, from cstdlib
		parse(line, argv);

		if (strcmp(argv[0], "exit") == 0) {
			// system call exit
			exit(0);
		} else if (strcmp(argv[0], "history") == 0) {
			// display history
			history[history_count] = "history";
			for (int i = 0; i < history_count; i++) {
				std::cout << i << "   " << history[i] << "\n";	
			}
		} else if (strcmp(argv[0], "!!") == 0) {
			// Execute most recent history command
			// argv = history[history_count].c_str();
			launch_osh(argv);
		} else {
			// Execute another library UNIX program
			// found in the PATH.
			std::string s(argv[0]);
			history[history_count] = s;
			history_count++;
			launch_osh(argv);
		}
	}
}
