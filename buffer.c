#include <stdio.h>
#include <stdlib.h>

static void pr_stdio(const char *name, FILE *fp)
{
	printf("stream = %s, ", name);
	/*
	 * The following is nonportable
	 */
	if (fp->_IO_file_flags & _IO_UNBUFFERED) {
		printf("unbuffered");
	} else if (fp->_IO_file_flags & _IO_LINE_BUF) {
		printf("line buffered");	
	} else { /* if neither of above */
		printf("fully buffered");	
	}

	printf(", buffer size = %d\n", fp->_IO_buf_end - fp->_IO_buf_base);
}

int main(int argc, const char *argv[])
{
	FILE *fp = NULL;

	getc(stdin);	/* stdin */	
	fputs("one line to standard output\n", stdout);	/* stdout */
	fputs("one line to standard error\n", stderr);	/* stderr */

	pr_stdio("stdin", stdin);
	pr_stdio("stdout", stdout);
	pr_stdio("stderr", stderr);

	fp = fopen("/etc/passwd", "r");
	getc(fp);
	pr_stdio("/etc/passwd", fp);

	return 0;
}

