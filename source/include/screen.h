#pragma once
#define LINES 25
#define LINE_COLUMNS 80
#define CHAR_BYTE_SIZE 2
/* High byte -
 *   High half of byte - bg color
 *   Low half of byte - fg color
 * Low byte - string character
*/
#define SCREENSIZE CHAR_BYTE_SIZE * LINE_COLUMNS * LINES

char *vidmemptr;

void kprint(const char *str, unsigned int loc);