#include <stdio.h>

typedef char byte;
typedef short int word;
typedef short int adr;

byte b_read  (adr a);             // читает из "старой памяти" mem байт с "адресом" a.
void b_write (adr a, byte val);   // пишет значение val в "старую память" mem в байт с "адресом" a.
word w_read  (adr a);             // читает из "старой памяти" mem слово с "адресом" a.
void w_write (adr a, word val);   // пишет значение val в "старую память" mem в слово с "адресом" a.

byte mem[(64-8)*1024];


int main()
{
    word w;


    w = w_read(2);
    printf("%04hx\n", w);


    return 0;
}


word w_read (adr a) {
	word w;
	w = (mem[a+1] << 8) | (mem[a] & 0xFF);
	
	return w;
}
