#include <stdio.h>			// needed for vsnprintf 
#include <stdlib.h>			// needed for malloc-free
#include <stdarg.h>			// needed for va_list

#ifndef _vscprintf
// For some reason, MSVC fails to honour this #infndef
// Hence function renamed to _vscprintf_so().

int _vscprintf_so(const char * format, va_list pargs)
{
	int retval;
}
