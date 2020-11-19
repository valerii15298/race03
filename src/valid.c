#include "header.h"

_Bool isrank(char *c, _Bool len) {
	if (len)
		return ((c[0] == '1') && (c[1] == '0'));
	return ((*c >= 50) && (*c <= 57)) || ((*c == 'J') || 
			(*c == 'Q') || (*c == 'K') || (*c == 'A'));
}

_Bool issuit(char c) {
	return ((c == 'H') || (c == 'C') || (c == 'S') || (c == 'D'));
}

int mx_strlen(char *c) {
	int i = -1;
	while(c[++i]);
	return i;
}
