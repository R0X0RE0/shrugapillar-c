#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define COLOR_RED	"\x1b[31m"
#define COLOR_GREEN	"\x1b[32m"
#define COLOR_YELLOW	"\x1b[33m"
#define COLOR_BLUE	"\x1b[34m"
#define COLOR_RESET	"\x1b[0m"

#define ANTENNAE	"   ᕙ ᕗ\n"
#define HEAD		"¯\\_(ツ)_/¯\n"
#define BODY		"¯\\_(  )_/¯"
#define BOTTOM		"¯\\_(__)_/¯\n"

#define NUM_COLORS	4

int main(int argc, char** argv) {
	
	//Variables
	char* color_options[NUM_COLORS] = {"red", "green", "yellow", "blue"};
	char* colors[NUM_COLORS] = {COLOR_RED, COLOR_GREEN, COLOR_YELLOW, COLOR_BLUE};
	
	int length = 1;
	char* prompt = BODY;
	bool ignore = false;

	for (int i = 0; i < argc; ++i) {
		if (argv[i] != NULL && i > 0) {
			if (strcmp(argv[i], "-c") == 0) {
				if (argv[i + 1] != NULL) {
					for (int j=0; j < NUM_COLORS; ++j) {
						if (strcmp(argv[i+1], color_options[j]) == 0 && color_options[j] != NULL && colors[i] != NULL && argv[i] != NULL) {
							printf("%s", colors[j]); // forced to do this bad practice with conditions for strings in C. LOL
						}
					}
				}
			}
			else if (strcmp(argv[i], "-l") == 0) {
				if (argv[i + 1] != NULL) {
					length = atoi(argv[i + 1]);
				}
			}
			else if (strcmp(argv[i], "-p") == 0) {
				if (argv[i + 1] != NULL) {
					prompt = argv[i + 1];
				}
			}
			else if (strcmp(argv[i], "-i") == 0) {
				ignore = true;
			}
		}
	}
	if (ignore == false) {
		printf(ANTENNAE);
		printf(HEAD);
	}
	for (int i = 0; i < length; i++) {
		printf("%s\n", prompt);
	}
	if (ignore == false) {
		printf(BOTTOM);
	}

	//End
	printf(COLOR_RESET);
	return 0;

}
