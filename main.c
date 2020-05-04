#include <stdio.h>
#include <assert.h>

typedef unsigned char byte;
typedef unsigned short int word;
typedef word adr;
typedef int dword;

byte mem [64 * 1024];


word w_read  (adr a);
void w_write (adr a, word val);
byte b_read  (adr a);  
void b_write (adr a, byte val);


int main ()
{
	
    return 0;
}


byte b_read(adr a)
{
	return mem[a];
}

void b_write (adr a, byte val)
{
    mem[a] = val;
}

word w_read (adr a)
{
    assert(a % 2 == 0);
    word wrd1= mem[a];
    word wrd2 = mem[a + 1];
    wrd2 <<= 8;
    return wrd1 + wrd2;
}

void w_write (adr a, word val)
{
	assert((a % 2) == 0);
	mem[a] = (byte) val;
	mem[a + 1] = (byte) (val >> 8);
}
