#include "include/screen.h"

char *vidmemptr = (char *)0xb8000; // pointer to video memory

void kprint(const char *str, unsigned int loc )
// Handles printing of a string to the kernel screen
// When providing characterstring argument, #[BG_COLORCODE_4BIT][FG_COLORCODE_4BIT] can be added before text
// which need be colored.
{
	unsigned int currentcolor = 0x07; // See colorcodes.h for color code specification
	for (;*str;str++) {
		if (*str == '#' &&
			*(str+1) != '#')
		{
			str++; // go to hexcodeone location
			// get the hex value code
			int charcodeone = *(str++);
			if (charcodeone >= 'A' && charcodeone <= 'F')
			{
				currentcolor = (charcodeone - 'A' + 0xA) * 16;
			}
			else if (charcodeone >= 'a' && charcodeone <= 'f')
			{
				currentcolor = (charcodeone - 'a' + 0xA) * 16;
			}
			else if (charcodeone >= '0' && charcodeone <= '9')
			{
				currentcolor = (charcodeone - '1' + 0x1) * 16;
			}
			int charcodetwo = *(str++);
			if (charcodetwo >= 'A' && charcodetwo <= 'F')
			{
				currentcolor += charcodetwo - 'A' + 0xA;
			}
			else if (charcodetwo >= 'a' && charcodetwo <= 'f')
			{
				currentcolor += charcodetwo - 'a' + 0xA;
			}
			else if (charcodetwo >= '0' && charcodetwo <= '9')
			{
				currentcolor += charcodetwo - '1' + 0x1;
			}
			else if (charcodetwo == '#')
			{
			}
			continue;
		}
		else if (*str == '#' &&
			*(str+1) == '#') // Handles "##"
		{
			str++;
		}
		else if (*str == '\n')
		{
			unsigned int line_size = CHAR_BYTE_SIZE * LINE_COLUMNS;
			loc = loc + (line_size - loc % (line_size));
			str++;
			continue;
		}
		vidmemptr[loc++] = *str;     // print char
		vidmemptr[loc++] = currentcolor; // default light grey fg on black bg
	}
	
}

/*
		if (*str == '#' &&
			*(str+1) != '#')
		{
			str++; // go to hexcodeone location
			// get the hex value code
			int charcodeone = *(str++);
			if (charcodeone >= 'A' && charcodeone <= 'F')
			{
				currentcolor = (charcodeone - 'A' + 0xA) * 16;
			}
			else if (charcodeone >= 'a' && charcodeone <= 'f')
			{
				currentcolor = (charcodeone - 'a' + 0xA) * 16;
			}
			else if (charcodeone >= '0' && charcodeone <= '9')
			{
				currentcolor = (charcodeone - '1' + 0x1) * 16;
			}
			int charcodetwo = *(str++);
			if (charcodetwo >= 'A' && charcodetwo <= 'F')
			{
				currentcolor += charcodetwo - 'A' + 0xA;
			}
			else if (charcodetwo >= 'a' && charcodetwo <= 'f')
			{
				currentcolor += charcodetwo - 'a' + 0xA;
			}
			else if (charcodetwo >= '0' && charcodetwo <= '9')
			{
				currentcolor += charcodetwo - '1' + 0x1;
			}
			else if (charcodetwo == '#')
			{
			}
			continue;
		}
		else if (*str == '#' &&
			*(str+1) == '#') // Handles "##"
		{
			str++;
		}
		else if (*str == '\n')
		{
			unsigned int line_size = CHAR_BYTE_SIZE * LINE_COLUMNS;
			loc = loc + (line_size - loc % (line_size));
			str++;
			continue;
		}
		*/

/*
void kprint(const char *str)
{
    // When providing characterstring argument, #[BG_COLORCODE_4BIT][FG_COLORCODE_4BIT] can be added before text
    // which need be colored.
    // Example in *exitmsg in kernel.c, kernel_exit_handler()
    unsigned int currentcolor = 0x07; // fg color code of light gray on black bg
    unsigned int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '#' &&
            str[i + 1] != '#')
        {
            i++; // go to hexcodeone location
            // get the hex value code
            int charcodeone = str[i++];
            if (charcodeone >= 'A' && charcodeone <= 'F')
            {
                currentcolor = (charcodeone - 'A' + 0xA) * 16;
            }
            else if (charcodeone >= 'a' && charcodeone <= 'f')
            {
                currentcolor = (charcodeone - 'a' + 0xA) * 16;
            }
            else if (charcodeone >= '0' && charcodeone <= '9')
            {
                currentcolor = (charcodeone - '1' + 0x1) * 16;
            }
            int charcodetwo = str[i++];
            if (charcodetwo >= 'A' && charcodetwo <= 'F')
            {
                currentcolor += charcodetwo - 'A' + 0xA;
            }
            else if (charcodetwo >= 'a' && charcodetwo <= 'f')
            {
                currentcolor += charcodetwo - 'a' + 0xA;
            }
            else if (charcodetwo >= '0' && charcodetwo <= '9')
            {
                currentcolor += charcodetwo - '1' + 0x1;
            }
            else if (charcodetwo == '#')
            {
            }
            continue;
        }
        else if (str[i] == '#' &&
                 str[i + 1] == '#') // Handles "##"
        {
            i++;
        }
        else if (str[i] == '\n')
        {
            unsigned int line_size = CHAR_BYTE_SIZE * COLUMNS_IN_LINE;
            current_loc = current_loc + (line_size - current_loc % (line_size));
            i++;
            continue;
        }
        vidmemptr[current_loc++] = str[i++];     // print char
        vidmemptr[current_loc++] = currentcolor; // default light grey fg on black bg}
    }
}
*/