#include "header.h"

_Bool one_pair(char **arr) {
	for (int i = 1; i < 5; i++)
		for (int j = i+1; j < 6; j++)
			if (arr[i][0] == arr[j][0])
				return 1;
	return 0;
}

_Bool flush(char **argv) {
	for (int i = 1; i < 5; i++)
		if (argv[i][1] != argv[i+1][1])
			return 0;
	return 1;
}

_Bool straight(char **arr) {
	char p;
	for (int i = 1; i < 5; i++)
		for (int j = i + 1; j < 6; j++)
			if (arr[i][0] > arr[j][0]){
				p = arr[i][0];
				arr[i][0] = arr[j][0];
				arr[j][0] = p;
			}
	for (int i = 1; i < 4; i++)
		if (arr[i][0] + 1 != arr[i+1][0])
			return 0;
	return ((arr[5][0] == (arr[4][0] + 1)) || 
			((arr[5][0] == '>') && (arr[1][0] == '2'))) ? 1 : 0;
}

_Bool twopairs(char **arr) {
	int k;
	for (int i = 1; i < 5; i++)
		for (int j = i+1; j < 6; j++)
			if (arr[i][0] == arr[j][0])
				k = i;
	for (int i = 1; i < 5; i++)
		for (int j = i+1; j < 6; j++)
			if (arr[i][0] == arr[j][0] && (i!=k))
				return 1;
	return 0;
}

int three(char **arr) {
	int k;
	int i, max = 0;
	for (i = 1; i < 5; i++){
		k = 0;
		for (int j = i+1; j < 6; j++) {
			k+= (int)(arr[i][0] == arr[j][0]);
		}
		max = (k > max) ? k : max;
	}
	return max;
}
