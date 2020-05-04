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
	load_file();
	
	/*
	byte b, b0, b1;
	word w, w0;
	
	b0 = 0x0b;
	b_write(0, b0);
	b = b_read(0);
	printf("%02hhx\n", b);
	
	b0 = 0xfb;
	b1 = 0xfa;
	b_write(2, b0);
	b_write(3, b1);
	w = w_read(2);
	printf("%04hx\n", w);
	
	w0 = w_read(2);
	w_write(4, w0);
	w = w_read(4);
	b0 = b_read(4);
	b = b_read(5);
	printf("<<%02hhx>>\n<<%02hhx>>\n%04hx\n", b0, b, w);
	*/
	
	return 0;
}


word w_read (adr a) {
	word w;
	w = (mem[a+1] << 8) | (mem[a] & 0xFF);
	
	return w;
}

byte b_read (adr a) {
	return mem[a];
}

void b_write (adr a, byte val) {
	mem[a] = val;
}

void w_write (adr a, word val) {
	mem[a] = val & 0xFF;
	mem[a + 1] = (val >> 8);
}

void load_file() {
	unsigned int adrs, n, i, el;
	while (scanf("%x%x", &adrs, &n) == 2) {
		for(i = 0; i < n; i++) {
			scanf("%x", &el);
			b_write(adrs + i, el);
		}
	}
}
