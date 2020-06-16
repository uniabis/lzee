/*

 LZE
 Copyright (C)1995,2008 GORRY.

 LZEe - LZE enhancement for Z80 by uniabis
 LZEee - LZE extra enhancement for Z80 by uniabis

 License:zlib license or original LZE license

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

   1. The origin of this software must not be misrepresented; you must not
   claim that you wrote the original software. If you use this software
   in a product, an acknowledgment in the product documentation would be
   appreciated but is not required.

   2. Altered source versions must be plainly marked as such, and must not be
   misrepresented as being the original software.

   3. This notice may not be removed or altered from any source
   distribution.

*/
/********************************************************************************/

#define MACRO
#include	<stdio.h>
#include	<stdlib.h>
#include	<ctype.h>
#include	<limits.h>
#include	<time.h>

#ifdef _MSC_VER
/*
cl /O1 /EHs-c- /MD lzee.c
*/

void _except_handler4_common()
{
	abort();
}

void *memset(void *buf, int ch, size_t n)
{
	unsigned char *ptr = buf;
	while (n-- > 0)
	{
		*(ptr++) = ch;
	}
	return buf;
}

void *memcpy(void *buf1, const void *buf2, size_t n)
{
	unsigned char *d = buf1;
	const unsigned char *s = buf2;
	while (n-- > 0)
	{
		*(d++) = *(s++);
	}
	return buf1;
}

#endif

#define	BZCOMPATIBLE	1	/* 0 or 1 */
#define	SPEED	1		/* 0 or 1 */
/*int	Debug=0;*/
#define	Debug	0
/* #define	DebugMacro(cond,p)	if (cond) p */
#define	DebugMacro(cond,p)	

#define	N	16384
#define	F	256

#if SPEED
#define	IDX	8192
#else
#define	IDX	256
#endif

#define FMT_LZE 1
#define FMT_LZEE 2
#define FMT_LZEXE 3
#define FMT_LZEEE_OBSOLETED_F4 4
#define FMT_LZEEE_F5 5

static int fmt = FMT_LZEE;

FILE	*infile;
FILE	*outfile;
unsigned long	outcount = 0;
unsigned char	text[N+F];
int	son[N+1+IDX];
int	dad[N+1+IDX];
int	same[N];
#define	NIL	-1

/********************************************************************************/

void	error( char *mes )
{
	fputs( mes, stderr );
	fputs( "\n", stderr );
	exit(EXIT_FAILURE);
}

void	init_tree( void )
{
	int	i;

	for ( i=0; i<N+1; i++ ) {
		son[i] = NIL;
		dad[i] = NIL;
	}
	for ( i=0; i<IDX; i++ ) {
		son[N+1+i] = NIL;
		dad[N+1+i] = NIL;
	}
}

int	matchpos, matchlen, noder, nodeo;
int	samecount;

void	insert_node( int r )
{
	unsigned char	*p;
	int	k, o;

	DebugMacro( (Debug>99),  printf( "Insert Node(%d)\n", r ) );

	if ( samecount > 0 ) {
		same[r] = samecount;
		samecount--;
	} else {
		int	i;
		unsigned char	c;

		p = &text[r];
		c = *(p++);
		for ( i=0; i<F-1; i++ ) {
			if ( *(p++) != c ) break;
		}
		samecount = i;
		same[r] = samecount;
		samecount--;
	}

#if SPEED
	k = (text[r]<<5) ^ (text[r+1] );
#else
	k = text[r];
#endif
	o = son[N+1+k];
	son[N+1+k] = r;
	nodeo = o;
	noder = r;
	if ( o < 0 ) { /* if ( o == NIL ) { */
		dad[N+1+k] = r;
		DebugMacro( (Debug>99), printf( "dad[%d]=%d\n", N+1+k, r ) );
		return;
	}
	son[r] = o;
	dad[o] = r;
	dad[r] = NIL;

	return;
}

void	delete_node( int p )
{
	int	k, q, r;

	DebugMacro( (Debug>99), printf( "Delete Node(%d)\n", p ) );
#if SPEED
	k = (text[p]<<5) ^ (text[p+1] );
#else
	k = text[p];
#endif
	r = N+1+k;
	q = dad[r];
	do {
		DebugMacro( (Debug>99), printf( "%d\n", q ) );
		if ( q < 0 ) return; /* if ( q == NIL ) return; */
		if ( p == q ) {
			if ( dad[q] < 0 ) { /* if ( dad[q] == NIL ) { */
				son[N+1+k] = son[q];
			} else {
				son[dad[q]] = son[q];
			}
			dad[r] = dad[q];
			DebugMacro( (Debug>99), printf( "dad[%d]=%d\n", r, dad[q] ) );
			dad[q] = NIL;
			return;
		}
		r = q;
		q = dad[q];
	} while (!0);

	return;
}

int	get_node( void )
{
	int	r, o, m, n;
	int	mlen;

	DebugMacro( (Debug>99),  printf( "Get Node\n" ) );
	mlen = 0;
	o = nodeo;
	r = noder;
	if ( o < 0 ) { /* if ( o == NIL ) { */
		return (mlen);
	}

	n = same[r];
	do {
		unsigned char	*p, *q;
		int	i;

		m = (r-o) & (N-1);
		if ( m > 8192 ) return (mlen);
		DebugMacro( (Debug>99), printf( "%d ", o ) );
		i = mlen;
		p = &text[r+i+1];
		q = &text[o+i+1];
		if ( i ) { i--; if ( *(--p) != *(--q) ) continue; }
		if ( i ) { i--; if ( *(--p) != *(--q) ) continue; }
		if ( i ) { i--; if ( *(--p) != *(--q) ) continue; }
		if ( i ) { i--; if ( *(--p) != *(--q) ) continue; }
		i = n;
		if ( i > same[o] ) {
			i = same[o];
		}
		p = &text[r+i];
		q = &text[o+i];
		if ( *(p++) != *(q++) ) continue;
		for ( ; i<F; ) {
			i++; if ( *(p++) != *(q++) ) break;
			i++; if ( *(p++) != *(q++) ) break;
			i++; if ( *(p++) != *(q++) ) break;
			i++; if ( *(p++) != *(q++) ) break;
		}
		if ( i>F ) i=F;
		DebugMacro( (Debug>99),  printf( "%d\n", i ) );
		if ( mlen < i ) {
			matchpos = m;
			mlen = i;
			if ( i >= F ) return (mlen);
		}
	} while ( (o=son[o]) >= 0 ); /* } while ( (o=son[o]) != NIL ); */

	return (mlen);
}

/********************************************************************************/

unsigned int	flags;
int	flagscnt;
int	codeptr, code2size;

unsigned char	code[256], code2[4];

void	init_putencode( void )
{
	code[0] = 0;
	if (fmt == FMT_LZEXE) {
		code[1] = 0;
		codeptr = 2;
	} else {
		codeptr = 1;
	}
	flags = 0;
	flagscnt = 0;
}

void	sub_putencode( unsigned char c )
{
	putc( c, outfile );
}

static int bitrev( int b )
{
	return ((b & (1 << 7)) >> 7)
		 | ((b & (1 << 6)) >> 5)
		 | ((b & (1 << 5)) >> 3)
		 | ((b & (1 << 4)) >> 1)
		 | ((b & (1 << 3)) << 1)
		 | ((b & (1 << 2)) << 3)
		 | ((b & (1 << 1)) << 5)
		 | ((b & (1 << 0)) << 7);
}

int	putencode( int r )
{
	int	size;
	unsigned int	fl;
	int	fc;
	int	mlen;
	int	mpos;

	fl = flags;
	fc = flagscnt;
	mlen = matchlen;
	mpos = matchpos;
	size = 0;
	if ( mlen < 2 ) {
		matchlen = 1;
		fl = (fl+fl)+((fmt == FMT_LZEEE_OBSOLETED_F4 || fmt == FMT_LZEEE_F5) ? 0 : 1);
		fc += 1;
		code2[0] = text[r];
		code2size = 1;
	} else {
		if ( ( mlen < 6 ) && ( mpos < 257 ) ) {
			fl = (fl<<4)+(mlen-2)+((fmt == FMT_LZEEE_OBSOLETED_F4 || fmt == FMT_LZEEE_F5) ? 8 : 0);
			fc += 4;
			mpos = 256-mpos;
			code2[0] = (unsigned char) (mpos);
			code2size = 1;
		} else if ( mlen > 9 ) {
			fl = (fl<<2)+((fmt == FMT_LZEEE_OBSOLETED_F4 || fmt == FMT_LZEEE_F5) ? 1 | 2 : 1);
			fc += 2;
			mpos = 8192-mpos;
			if (fmt == FMT_LZEE || fmt == FMT_LZEEE_OBSOLETED_F4 || fmt == FMT_LZEEE_F5) {
				code2[0] = (unsigned char) (mpos>>5)&0xf8;
				code2[1] = (unsigned char) (mpos & 0xff);
			} else if ( fmt == FMT_LZEXE ) {
				code2[0] = (unsigned char) (mpos & 0xff);
				code2[1] = (unsigned char) (mpos>>5)&0xf8;
			} else if ( fmt == FMT_LZE ) {
				code2[0] = (unsigned char) (mpos>>5)&0xff;
				code2[1] = (unsigned char) (mpos<<3);
			}
			code2[2] = (unsigned char) (mlen-((fmt == FMT_LZEEE_F5) ? 2 : 1));
			code2size = 3;
		} else if ( mlen > 2) {
			fl = (fl<<2)+((fmt == FMT_LZEEE_OBSOLETED_F4 || fmt == FMT_LZEEE_F5) ? 1 | 2 : 1);
			fc += 2;
			mpos = 8192-mpos;
			if (fmt == FMT_LZEE || fmt == FMT_LZEEE_OBSOLETED_F4 || fmt == FMT_LZEEE_F5) {
				code2[0] = (unsigned char) ((mpos>>5)&0xf8)|(mlen-2);
				code2[1] = (unsigned char) (mpos & 0xff);
			} else if ( fmt == FMT_LZEXE ) {
				code2[0] = (unsigned char) (mpos & 0xff);
				code2[1] = (unsigned char) ((mpos>>5)&0xf8)|(mlen-2);
			} else if ( fmt == FMT_LZE ) {
				code2[0] = (unsigned char) (mpos>>5)&0xff;
				code2[1] = (unsigned char) (mpos<<3)|(mlen-2);
			}
			code2size = 2;
		} else {
			matchlen = 1;
			fl = (fl+fl)+((fmt == FMT_LZEEE_OBSOLETED_F4 || fmt == FMT_LZEEE_F5) ? 0 : 1);
			fc += 1;
			code2[0] = text[r];
			code2size = 1;
		}
	}
	if (fmt == FMT_LZEXE) {
		if ( fc >= 16 ) {
			int	i;
			unsigned char	*p;

			fc -= 16;
			p = &code[0];
			p[0] = bitrev(fl>>(fc + 8));
			p[1] = bitrev(fl>>(fc + 0));
			DebugMacro( (Debug),  printf( "output code=" ) );
			for ( i=0; i<codeptr; i++ ) {
				sub_putencode( *(p++) );
				DebugMacro( (Debug), printf( "$%02X ", code[i] ) );
			}
			DebugMacro( (Debug), printf( "\n" ) );
			size += codeptr;
			codeptr = 2;
			fl &= (0xffff>>(16-fc));
		}
	} else {
		if ( fc > 8 ) {
			int	i;
			unsigned char	*p;

			fc -= 8;
			p = &code[0];
			*(p) = (fl>>fc);
			DebugMacro( (Debug),  printf( "output code=" ) );
			for ( i=0; i<codeptr; i++ ) {
				sub_putencode( *(p++) );
				DebugMacro( (Debug), printf( "$%02X ", code[i] ) );
			}
			DebugMacro( (Debug), printf( "\n" ) );
			size += codeptr;
			codeptr = 1;
			fl &= (0x00ff>>(8-fc));
		}
	}

	DebugMacro( (Debug), printf( "store code($%02X)=", codeptr ) );
	{
		unsigned char	*p, *q;
		int	i;

		p = &code[codeptr];
		q = &code2[0];
		for ( i=0; i<code2size; i++ ) {
			*(p++) = *(q++);
			DebugMacro( (Debug),  printf( "$%02X ", code2[i] ) );
		}
		codeptr += i;
	}
	DebugMacro( (Debug), printf( "\n" ) );

	flags = fl;
	flagscnt = fc;

	return (size);
}

int	finish_putencode( void )
{
	int	i;
	int	size;

	size = 0;
	flags = (flags << 2)+((fmt == FMT_LZEEE_OBSOLETED_F4 || fmt == FMT_LZEEE_F5) ? 1 | 2 : 1);
	flagscnt += 2;
	code2[0] = (unsigned char) 0;
	code2[1] = (unsigned char) 0;
	code2[2] = (unsigned char) 0;
	code2size = 3;
	if (fmt == FMT_LZEXE) {
		if ( flagscnt >= 16 ) {
			flagscnt -= 16;
			code[0] = bitrev(flags>>(flagscnt + 8));
			code[1] = bitrev(flags>>(flagscnt + 0));
			DebugMacro( (Debug), printf( "output code=" ) );
			for ( i=0; i<codeptr; i++ ) {
				putc( code[i], outfile );
				DebugMacro( (Debug), printf( "$%02X ", code[i] ) );
			}
			DebugMacro( (Debug), printf( "\n" ) );
			size += codeptr;
			codeptr = 2;
			flags &= (0xffff>>(16-flagscnt));
		}
	} else {
		if ( flagscnt > 8 ) {
			flagscnt -= 8;
			code[0] = (flags>>flagscnt);
			DebugMacro( (Debug), printf( "output code=" ) );
			for ( i=0; i<codeptr; i++ ) {
				putc( code[i], outfile );
				DebugMacro( (Debug), printf( "$%02X ", code[i] ) );
			}
			DebugMacro( (Debug), printf( "\n" ) );
			size += codeptr;
			codeptr = 1;
			flags &= (0x00ff>>(8-flagscnt));
		}
	}
	DebugMacro( (Debug), printf( "store code($%02X)=", codeptr ) );
	for ( i=0; i<code2size; i++ ) {
		code[codeptr++] = code2[i];
		DebugMacro( (Debug), printf( "$%02X ", code2[i] ) );
	}
	DebugMacro( (Debug), printf( "\n" ) );

	if (fmt == FMT_LZEXE) {
		if ( flagscnt > 0 ) {
			flags<<=(16-flagscnt);
			code[0] = bitrev(flags>>(0 + 8));
			code[1] = bitrev(flags>>(0 + 0));
		}
		if ( codeptr > 2 ) {
			DebugMacro( (Debug), printf( "output code=" ) );
			for ( i=0; i<codeptr; i++ ) {
				putc( code[i], outfile );
				DebugMacro( (Debug),  printf( "$%02X ", code[i] ) );
			}
			DebugMacro( (Debug), printf( "\n" ) );
			size += codeptr;
		}
	} else {
		if ( flagscnt > 0 ) {
			code[0] = (flags<<(8-flagscnt));
		}
		if ( codeptr > 1 ) {
			DebugMacro( (Debug), printf( "output code=" ) );
			for ( i=0; i<codeptr; i++ ) {
				putc( code[i], outfile );
				DebugMacro( (Debug),  printf( "$%02X ", code[i] ) );
			}
			DebugMacro( (Debug), printf( "\n" ) );
			size += codeptr;
		}
	}


	return (size);
}

/********************************************************************************/

void	encode( void )
{
	int 	i, c, r, s, len, mlen;
	char	ok_delete_node;
	unsigned long int	incount = 0, printcount = 0, cr;

	ok_delete_node = 0;
	init_tree();
	init_putencode();
	s = 0;
	r = N-F;
	for ( i=s; i<r; i++ ) {
		text[i] = 0;
	}
	for ( i=0; i<F; i++ ) {
		c = getc( infile );
		if ( c == EOF ) break;
		text[r+i] = c;
	}
	incount = i;
	len = i;
	if ( incount == 0 ) return;
#if BZCOMPATIBLE
	if ( fmt != FMT_LZEXE ) {
		insert_node( r );
		sub_putencode( text[r] );
		c = getc( infile );
		incount++;
		if ( c != EOF ) {
			text[s] = c;
			if ( s < (F-1) ) text[s+N] = c;
			s = (s+1) & (N-1);
			r = (r+1) & (N-1);
		} else {
			s = (s+1) & (N-1);
			r = (r+1) & (N-1);
			len--;
			if ( !len ) goto NoEncode;
		}
	}
#endif
	insert_node( r );
	do {
		matchlen = get_node();
		if ( matchlen > len ) matchlen = len;
		outcount += putencode( r );

		DebugMacro( (Debug), printf( "text[r]=$%02X r=%4d s=%4d matchpos=%4d matchlen=%4d\n", text[r], r, s, matchpos, matchlen ) );

		matchpos = N+1;
		mlen = matchlen;
		for ( i=0; i<mlen; i++ ) {
			c = getc( infile );
			if ( c ==EOF ) break;
			if ( ok_delete_node ) {
				delete_node(s);
			} else {
				if ( s == N-F-1 ) ok_delete_node = !0;
			}
			text[s] = c;
			if ( s < (F-1) ) text[s+N] = c;
			s = (s+1) & (N-1);
			r = (r+1) & (N-1);
			insert_node(r);
		}
		if ( (incount+=i) > printcount ) {
			printf( "%12lu\r", incount );
			printcount += 1024*16;
		}
		while ( i++ < mlen ) {
			if ( ok_delete_node ) {
				delete_node(s);
			} else {
				if ( s == N-F-1 ) ok_delete_node = !0;
			}
			s = (s+1) & (N-1);
			r = (r+1) & (N-1);
			if ( --len ) {
				insert_node(r);
			}
		}
	} while ( len > 0 );

  NoEncode:;
	outcount += finish_putencode();
	printf( "In : %lu bytes\n", incount );
	printf( "Out: %lu bytes\n", outcount );
	if ( incount != 0 ) {
		cr = ( 1000 * outcount + (incount/2) ) / incount;
		printf( " Out/In: %lu.%03lu\n", cr/1000, cr%1000 );
	}
}

void	decode( unsigned long int size )
{
	unsigned int	flags;
	int	flagscnt;
	int	i, j, k, r, c;
	unsigned int	u;
	int	bit;

#define	GetBit()						\
if ( fmt == FMT_LZEXE ) {						\
	bit = (flags & 1);						\
	flags >>= 1;						\
	if ((--flagscnt)<=0) {					\
		if ((c = getc(infile)) == EOF ) goto Err;	\
		flags = c;	\
		if ((c = getc(infile)) == EOF ) goto Err;	\
		flags |= c << 8;	\
		flagscnt = 16;					\
	}							\
} else {								\
	if ((--flagscnt)<0) {					\
		if ((c = getc(infile)) == EOF ) goto Err;	\
		DebugMacro( (Debug>99), printf( "\nGetBit($%02X) ", c ) );	\
		flags = c;					\
		flagscnt += 8;					\
	}							\
	bit = ((flags<<=1) & 256 );				\
}								

	flags = 0;
	flagscnt = 0;
	if ( fmt == FMT_LZEXE ) {
		if ((c = getc(infile)) == EOF ) goto Err;
		flags = c;
		if ((c = getc(infile)) == EOF ) goto Err;
		flags |= c << 8;
		flagscnt = 16;
	}
	r = N-F;
#if BZCOMPATIBLE
	if ( fmt != FMT_LZEXE ) {
		if ((c = getc(infile)) == EOF ) goto Err;
		putc( c, outfile );
		text[r++] = c;
		r &= (N-1);
	}
#endif
	do {
		GetBit();
		if (fmt == FMT_LZEEE_OBSOLETED_F4 || fmt == FMT_LZEEE_F5) bit = !bit;
		if (bit) {
						/* 1 */
			if ((c = getc(infile)) == EOF ) break;
			DebugMacro( (Debug>99), printf( "1($%02X) ", c ) );
			putc( c, outfile );
			DebugMacro( (Debug), printf( "text[r]=$%02X r=%4d \n", c, r ) );
			text[r++] = c;
			r &= (N-1);
		} else {
			GetBit();
			if (bit) {
						/* 01 */
				if ((i = getc(infile)) == EOF ) goto Err;
				if ((j = getc(infile)) == EOF ) goto Err;
				DebugMacro( (Debug>99), printf( "01($%02X,$%02X) ", i, j ) );
				if (fmt == FMT_LZEE || fmt == FMT_LZEEE_OBSOLETED_F4 || fmt == FMT_LZEEE_F5) {
					u = ((i & 0xf8)<<5) | j;
					j = i & 0x07;
				} else if ( fmt == FMT_LZEXE ) {
					u = ((j & 0xf8)<<5) | i;
					j = j & 0x07;
				} else if ( fmt == FMT_LZE ) {
					u = ((i<<8) | j)>>3;
					j = j & 0x07;
				} else { goto Err; }
				if ( j == 0 ) {
					if ((j = getc(infile)) == EOF ) goto Err;
					DebugMacro( (Debug>99), printf( "($%02X) ", j ) );
					if ( j==0 ) goto Quit;
					if ( fmt == FMT_LZEXE ) {
						if ( j==1 ) continue;
					}
					j += (fmt == FMT_LZEEE_F5) ? 2 : 1;
				} else {
					j += 2;
				}
				i = r-(8192-u);
			} else {
						/* 00 */
				GetBit();
				j  = ( bit ? 2 : 0 );
				GetBit();
				j += ( bit ? 1 : 0 );
				j += 2;
				if ((i = getc(infile)) == EOF ) goto Err;
				DebugMacro( (Debug>99), printf( "00($%02X) ", i ) );
				i = r-(256-i);
			}
			for ( k=0; k<j; k++ ) {
				c = text[(i+k) & (N-1)];
				putc( c, outfile );
				DebugMacro( (Debug), printf( "text[r]=$%02X j=%4d r=%4d i=%4d \n", c, j, r, i ) );
				text[r++] = c;
				r &= (N-1);
			}
		}
	} while (!0);
  Quit:;
  Err:;
	printf( "%12lu\n", size );
}

void	Usage( void )
{
	printf(
		"Usage: lzee [option] {command} {infile} {outfile}\n"
		"\n"
		"  {command}\n"
		"    e : Encode without header\n"
		"    E : Encode with header\n"
		"    d : Decode without header\n"
		"    D : Decode with header\n"
		"\n"
		"  [option]\n"
		"    f[format]...\n"
		"\n"
		"  [format]\n"
		"    1 : lze\n"
		"    2 : LZEe(default)\n"
		"    3 : LZEXE RAW\n"
		"    4 : LZEee f4(obsoleted) \n"
		"    5 : LZEee f5\n"
		"    r : Force without header\n"
	);
	exit(EXIT_FAILURE);
}

int	main( int argc, char *argv[] )
{

	unsigned long int	size = 0;

	char	*inbuf;
	char	*outbuf;
	int		raw = 0;

	if ( argc > 1 && (argv[1][0] | 0x20) == 'f') {
		int p = 1;
		char f;
		while ((f = argv[1][p++]) != 0) {
			switch ( f ) {
			case '1':
				fmt = FMT_LZE;
				break;
			case '2':
				fmt = FMT_LZEE;
				break;
			case '3':
				fmt = FMT_LZEXE;
				break;
			case '4':
				fmt = FMT_LZEEE_OBSOLETED_F4;
				break;
			case '5':
				fmt = FMT_LZEEE_F5;
				break;
			case 'R':
			case 'r':
				raw = 1;
				break;
			}
		}
		argv++;
		argc--;
	}

	if ( argc != 4 ) Usage();
	infile = fopen( argv[2], "rb" );
	if ( infile == NULL ) error( "Error: Open Input File" );
	outfile = fopen( argv[3], "wb" );
	if ( outfile == NULL ) error( "Error: Open Output File" );
	if ( NULL != ( inbuf = malloc( 16*1024 ) ) ) {
		setvbuf( infile, inbuf, _IOFBF, 16*1024 );
	}
	if ( NULL != ( outbuf = malloc( 16*1024 ) ) ) {
		setvbuf( outfile, outbuf, _IOFBF, 16*1024 );
	}
	switch( *argv[1] ) {
	  case	'E':
		if ( !raw ) {
			fseek( infile, 0L, SEEK_END );
			size = ftell( infile );
			putc( (int)((size >> 24) & 0xff), outfile );
			putc( (int)((size >> 16) & 0xff), outfile );
			putc( (int)((size >>  8) & 0xff), outfile );
			putc( (int)((size >>  0) & 0xff), outfile );
			rewind( infile );
		}
	  case	'e':
		encode();
		break;
	  case	'D':
		if ( !raw ) {
			size  = (((unsigned long)getc( infile )) << 24);
			size |= (((unsigned long)getc( infile )) << 16);
			size |= (((unsigned long)getc( infile )) <<  8);
			size |= (((unsigned long)getc( infile )) <<  0);
		}
	  case	'd':
		decode( size );
		break;
	}
	fclose( infile );
	fclose( outfile );
	printf( "Time: %fs\n", ((double)clock())/CLK_TCK );
	return (EXIT_SUCCESS);
}

