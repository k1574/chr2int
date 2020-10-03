#include <stdlib.h>
#include <stdio.h>
#include <string.h>

enum{
	MAXSTRLEN = 1024
} ;

char *argv0;

void
usage()
{
	fprintf(stderr, "Usage: %s [ASCII string]\n", argv0);
	exit(1);
}

void
main(int argc, char *argv[])
{
	int i, l, n, buflen;
	char *s;
	char buf[BUFSIZ];
	argv0 = argv[0] ;
	if(argc==1){
		buflen = sizeof(buf)/sizeof(buf[1]) ;
		do{
			n = fread(buf, sizeof(buf[0]), buflen, stdin) ;
			for( i=0 ; i<n ; ++i )
				printf("%d\n", buf[i]);
		}while( n == buflen );
	} else if( argc==2) {
		s = argv[1] ;
		l = strnlen(s, MAXSTRLEN) ;
		for(i=0 ; i<l ; ++i)
			printf("%u\n", s[i]);
	} else
		usage();
	exit(1);
}
