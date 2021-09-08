#include <stdio.h>

void print_it() {
 printf("Bit operations are fun!\n");
}

void print_int() {
	int x = 10;
	int y = 13;
	printf("x = %d\n", x);
	printf("y = %d\n", y);
	printf("size of signed int in bytes is %i.\n",sizeof(x));
	printf("size of signed int in bits is %i.\n",8*sizeof(x));
	printf("%i + %i = %i.\n",x,y,x+y);  
}

void print_float() {
	float x = 10.0;
        float y = 13.0;
        printf("x = %f\n", x);
        printf("y = %f\n", y);
        printf("size of single float in bytes is %li.\n",sizeof(x));
        printf("size of single float in bits is %li.\n",8*sizeof(x));
        printf("%f + %f = %f.\n",x,y,(x+y)); 
	 printf("%f + %f = %i.\n",x,y,(int)(x+y)); 
}

void print_char() {
  char c = 'C';
  char a = 65;
  char b = 'B';
  char f = 'F';
  char e = 'E';
  char str[]  =  {c, a, f, e, b, a, b, e,'\0'};
  printf("c = %c\n", c);
  printf("a = %c\n", a);
  printf("%s\n", str);
  printf("number of bytes: %lu.\n", sizeof(str));
}

void packing_bytes() {
    unsigned char b3 = 202;
    unsigned char b2 = 254;
    unsigned char b1 = 186;
    unsigned char b0 = 190;
    unsigned int u = b3;
    u = u<<8;
    u = u+ b2;
    u = u<<8;
    u = u+ b1;
    u = u<<8;
    u = u+ b0;
    printf("%X\n",u);
}

void unpacking_bytes() {
  unsigned int i1 = 1835098984u;
  unsigned int i2 = 1768842611u;
  unsigned char a,b,c,d,e,f,g,h;;
  a = (i1 >>24);
  b = ((i1 <<8) >>24);
  c = ((i1 <<16) >>24);
  d = i1;
  e = (i2 >>24);
  f = ((i2 <<8) >>24);
  g = ((i2 <<16) >>24);
  h = i2;
  printf("%c%c%c%c%c%c%c%c\n", a,b,c,d,e,f,g,h);
}

void print_bits() {
  
    unsigned char a =  181;
    signed char b =  -75;
    unsigned i;
    for (i = 1 << 7; i > 0; i = i / 2){
        (a & i) ? printf("1") : printf("0");
    }
    printf("\n");
    for (i = 1 << 7; i > 0; i = i / 2){
        (b & i) ? printf("1") : printf("0");
   }
	    printf("\n");
}

void extracting_fields() {
  unsigned int i1 = 0xCAFEBABE;
  unsigned int a,b,c,d,e,f,g,h,j;
  a = (i1 >>29);
   b = ((i1 <<3) >>28);
   c = ((i1 <<7) >>28);
   d = ((i1 <<11) >>29);
   e =  ((i1 <<14) >>29);
   f = ((i1 <<17) >>28);
   g = ((i1 <<21) >>28);
   h = ((i1 <<25) >>29);
    unsigned int i = ((i1 <<28) >>30);
   j = ((i1 <<30)>>30 );

  printf("%i %i %i %i %i %i %i %i %i %i\n",a,b,c,d,e,f,g,h,i,j);


}

void updating_fields() {
  unsigned int i1 = 17512807u;
  int mask = ((1 << (21-18+1))-1) << 18;
  int updatingValue1 = (8 << 18) & mask;
  int readyValue = i1 & (~mask);
  i1 = readyValue |updatingValue1 ;

  mask = ((1 << (14-10+1))-1) << 10;
  updatingValue1 = (17 << 10) & mask;
  readyValue = i1 & (~mask);
  i1 = updatingValue1 | readyValue;
  printf("%08X\n", i1);
}
