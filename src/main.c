#include "header.h"

int main(int argc, char *argv[]) {
	if (argc != 6) {
		write(2, "usage: ./race03 [card1] [card2] [card3] [card4] [card5]\n", 56);
		return 0;
	}
	int len[6];
	for (int i = 1; i < 6; i++) {
		len[i] = mx_strlen(argv[i]);
		if ((len[i] > 3 || len[i] < 2) || 
			(!issuit(argv[i][len[i]-1]) && 
				!isrank(argv[i], (len[i] == 3) ? 1 : 0))) {
			write(2, "Invalid card: ", 14);
			write(2, argv[i], len[i]);
			write(2, "\n", 1);
			return 0;
		}
		if (!issuit(argv[i][len[i]-1])) {
			write(2, "Invalid card suit: ", 19);
			write(2, &(argv[i][len[i]-1]), 1);
			write(2, "\n", 1);
			return 0;
		}
		if (!isrank(argv[i], (len[i] == 3) ? 1 : 0)) {
			write(2, "Invalid card rank: ", 19);
			write(2, argv[i], len[i] - 1);
			write(2, "\n", 1);
			return 0;
		}
	}
	for (int i = 1; i < 5; i++) {
		for (int j = i+1; j < 6; j++) {
			if ((argv[i][0] == argv[j][0]) && 
				(argv[i][len[i]-1] == argv[j][len[i]-1])) {
				write(2, "Duplicate cards: ", 17);
				write(2, argv[i], len[i]);
				write(2, "\n", 1);
				return 0;
			}
		}
	}
	for (int i = 1; i < 6; i++) {
		if (len[i] == 3) {
			argv[i][0] = ':';
			argv[i][1] = argv[i][2];
			argv[i][2] = '\0';
		}
		else {
			if (argv[i][0] == 'J')
				argv[i][0] = ';';
			else if (argv[i][0] == 'Q')
				argv[i][0] = '<';
			else if (argv[i][0] == 'K')
				argv[i][0] = '=';
			else if (argv[i][0] == 'A')
				argv[i][0] = '>';
		}
	}
	if (!one_pair(argv))
		nopair(argv);
	else
		pair(argv);
	return 0;
}
