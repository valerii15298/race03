#include "header.h"

void nopair(char **argv) {
	if (straight(argv)){
			if (flush(argv)){
				if (argv[1][0] == ';'){
					write(1, "Royal flush\n", 12);
				} else {
				write(1, "Straight flush\n", 15);
				}
			} else {
			write(1, "Straight\n", 9);
			}
		} else
		if (flush(argv)) {
			write(1, "Flush\n", 6);
		} else
		write(1, "No pair\n", 8);
}

void pair(char **argv) {
	if (three(argv) == 4) {
			write(1, "Four of a kind\n", 15);
		} else {
			if (three(argv) == 3) {
				if (twopairs(argv)) {
					write(1, "Full house\n", 11);
				} else {
					write(1, "Three of a kind\n", 16);
				}
			} else {
				if (twopairs(argv)) {
					write(1, "Two pair\n", 9);
				} else {
					write(1, "One pair\n", 9);
				}
			}
		}
}
