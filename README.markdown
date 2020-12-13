# Tutorial: C

Sources:

- <https://www.tutorialspoint.com/cprogramming/index.htm>
- <https://www.geeksforgeeks.org/c-programming-language>
- <https://www.cplusplus.com/reference>

The GNU C Library: <https://www.gnu.org/software/libc/manual/html_mono/libc.html>

## Compiling

Compiling `hello.c`:

```bash
$ gcc hello.c
$ ./a.out
```

## Types

Integer/Float Types:

| type           | storage size | value range                                 | precision         |
| -------------- | ------------ | ------------------------------------------- | ---------         |
| char           | 1 byte       | -128 to 127 or 0 to 255                     | -                 |
| unsigned char  | 1 byte       | 0 to 255                                    | -                 |
| signed char    | 1 byte       | -128 to 127                                 | -                 |
| short          | 2 bytes      | -32,768 to 32,767                           | -                 |
| unsigned short | 2 bytes      | 0 to 65,535                                 | -                 |
| int            | 4 bytes      | -2,147,483,648 to 2,147,483,647             | -                 |
| unsigned int   | 4 bytes      | 0 to 4,294,967,295                          | -                 |
| long           | 8 bytes      | -9223372036854775808 to 9223372036854775807 | -                 |
| unsigned long  | 8 bytes      | 0 to 18446744073709551615                   | -                 |
| float          | 4 bytes      | 1.2E-38 to 3.4E+38                          | 6 decimal places  |
| double         | 8 bytes      | 2.3E-308 to 1.7E+308                        | 15 decimal places |
| long double    | 10 bytes     | 3.4E-4932 to 1.1E+4932                      | 19 decimal places |


Exact size use `sizeof(type)`:

```bash
# limits.h defines some ergonomic constants
$ gcc limits.c
```

Void type:

- void exit (int status);
- int rand(void);
- void *malloc( size_t size );

## Variables

```c
char c, ch;
int i,j, k;
double d;
float f = 3.0, f2 = 5.0;
byte z = 22;
```

Use `extern` to share variables between source files.

## Constants and Literals

Literals:

```c
// Integer literals
85         // decimal
0213       // octal
0x4b       // hexadecimal
30         // int
30u        // unsigned int
30l        // long
30ul       // unsigned long

// Floating ponts
3.14159
314159E-5L

// Character constants
'x'
'\t'
'\u02C0'
```

Constants:

```c
#define LENGTH 50 // Preprocessor
const int LENGTH = 50; // const keyword
```

## Storage Classes

scope and life-time of variables and/or functions:

- auto
- register
- static
- extern

__auto__ (default): functions and local variables.

```c
int mount;            // auto
auto int month;       // auto
```

__register__: stored in a register, max size = 1 WORD, and can't have the & operator applied (it does not have a memory location).

```c
register int miles;   // register
```

__static__:

- local variables: keep the value between functions calls.
- global variables: restrict the scope to the file.

```c
static int count = 5; // static
```

__extern__: global variable visible to all the program files.

```c
// compile: $gcc main.c support.c

// main.c
#include <stdio.h>

int count ;
extern void write_extern();

main() {
   count = 5;
   write_extern();
}

// support.c
#include <stdio.h>

extern int count;

void write_extern(void) {
   printf("count is %d\n", count);
}
```

## Operators

```c
modulus: %

// bitwise
bitwise and: p & q
bitwise or: p | q
bitwise xor: p ^ q
bitwise complement: ~p
bitwise left shift: <<
bitwise right shift: >>

// assignment operators
+=
-=
*=
/=
%=
<<=
>>=
&=
|=
^=

// Misc
sizeof()
&a; // address
*a; // pointer
b ? a : b // conditional operator
```

## Loops

while loop:

```c
while(condition) {
   statement(s);
}
```

for loop:

```c
for ( init; condition; increment ) {
   statement(s);
}
```

do while loop:

```c
do {
   statement(s);
} while( condition );
```

Infinite loop:

```c
for( ; ; ) {
  printf("This loop will run forever.\n");
}
```

loop control statement:

```c
break      // terminate the loop
continue   // go to next iteration
goto
       LOOP:do {
          if( a == 15) {
             goto LOOP;
          }
          printf("value of a: %d\n", a);
          a++;
       }while( a < 20 );
```

## Functions

```c
int max(int x, int y) {
  return (x <= y) ? y : x;
}
```

Call by value: copies the actual value of the arguments

```c
void swap(int x, int y) {
   int temp;
   temp = x;
   x = y;
   y = temp;
   return;
}

int a = 100;
int b = 200;
swap(a, b);
// a = 100
// b = 200
```

Call by reference:

```c
void swap(int *x, int *y) {
   int temp;
   temp = *x;
   *x = *y;
   *y = temp;
   return;
}

int a = 100;
int b = 200;
swap(&a, &b);

// a = 200
// b = 100
```

## Scope Rules

- local
- global
- formal: function arguments, they take precedence over global variables.

## Arrays

```c
double balance[5] = {1000.0, 2.0, 3.4, 7.0, 50.0};
double salary = balance[0];
int matrix[10][10];
int matrix[3][2] = { {0,1}, {2,3}, {4,5} };
int a = matrix[0][0];
```

### Passing arrays as function arguments

```c
void myFunction(int *param) {..}
void myFunction(int param[10]) {..}
void myFunction(int param[]) {..}
```

```c
double average(int arr[], int size) {
  double sum = 0;

  for(i = 0; i < size;  ++i){
    sum += arr[i]
  }

  int avg = sum / size;

  return avg;
}

int main () {
  int balance[5] = {1, 2, 3, 4, 5}
  double avg = average(balance, 5);
}
```

### Return array from function in C

The local variable that you are going to return __must__ be declared static.

```c
#include <stdio.h>

int * getRandom( ) {

   static int  r[10];
   int i;

   srand( (unsigned)time( NULL ) );/* set the seed */

   for ( i = 0; i < 10; ++i) {
      r[i] = rand();
   }

   return r;
}

int main () {

   int *p;
   int i;

   p = getRandom();

   for ( i = 0; i < 10; i++ ) {
      printf( "*(p + %d) : %d\n", i, *(p + i));
   }

   return 0;
}
```

### Pointer to an Array in C

An array name is a constant pointer to the first element of the array.

For example, `double balance[50];` balance points to `&balance[0]`:

```c
double *p;
double balance[10];

p = balance;
p[0];
*(balance + 1);
```

## Pointers

```c
int    *ip;    /* pointer to an integer */
double *dp;    /* pointer to a double */
float  *fp;    /* pointer to a float */
char   *ch     /* pointer to a character */
```

```c
int  var = 20; // &var = bffd8b3c
int  *ip = NULL; // NULL = 0 address
ip = &var;
ip // bffd8b3c = &var
*ip // 20

if (ptr) // succeeds if p is not null
if (!ptr) // succeeds if p is null
```

### Arithmetic operations

```c
#include <stdio.h>

const int MAX = 3;

int main () {

   int  var[] = {10, 100, 200};
   int  i, *ptr;
   ptr = var;

   for ( i = 0; i < MAX; i++) {
      ptr++;
   }

   while ( ptr <= &var[MAX - 1] ) {
      ptr--;
   }

   return 0;
}
```

### Array of pointers

```c
#include <stdio.h>

const int MAX = 3;

int main () {

   int  var[] = {10, 100, 200};
   int i, *ptr[MAX];

   for ( i = 0; i < MAX; i++) {
      ptr[i] = &var[i];
   }

   for ( i = 0; i < MAX; i++) {
      printf("Value of var[%d] = %d\n", i, *ptr[i] );
   }

   return 0;
}
```

```c
char *names[] = {
  "Zara Ali",
  "Hina Ali",
  "Nuha Ali",
  "Sara Ali"
};

int i = 0;

for ( i = 0; i < MAX; i++) {
  printf("Value of names[%d] = %s\n", i, names[i] );
}
```

### Passing pointers to functions

```c
#include <stdio.h>
#include <time.h>

void getSeconds(unsigned long *par);

int main () {
   unsigned long sec;
   getSeconds( &sec );

   return 0;
}

void getSeconds(unsigned long *par) {
   *par = time( NULL );
   return;
}
```

```c
#include <stdio.h>

double getAverage(int *arr, int size);

int main () {

   int balance[5] = {1000, 2, 3, 17, 50};
   double avg;

   avg = getAverage( balance, 5 ) ;

   return 0;
}

double getAverage(int *arr, int size) {

   int  i, sum = 0;
   double avg;

   for (i = 0; i < size; ++i) {
      sum += arr[i];
   }

   avg = (double)sum / size;
   return avg;
}
```

### Returning pointers from functions

See [return array from function in C](#return-array-from-function-in-c)

### Passing functions as function parameters

```c
#include <stdio.h>

void print(int x);
void func(void (*f)(int));

void print ( int x ) {
  printf("%d\n", x);
}

void func ( void (*f)(int) ) {
  for ( int ctr = 0 ; ctr < 5 ; ctr++ ) {
    (*f)(ctr);
  }
}

int main() {

  func(print);

  return 0;
}
```

## Strings

```c
char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
char greeting[] = "Hello";
```

```c
strcpy(s1,s2); // copies string s2 into string s1
strcat(s1, s2); // concatenates s1 ++ s2
strlen(s1);
strcmp(s1,s2); // < 0 if s1 < s2
               // 0   if s1 == s2
               // > 0 if s1 > s2
strchr(s1, ch); // returns a pointer to the first occurrence of 'ch' in s1.
strstr(s1, s2); // returns a pointer to the first occurence of string s2 in string s1.
```

```c
#include <stdio.h>
#include <string.h>

int main () {

   char str1[12] = "Hello";
   char str2[12] = "World";
   char str3[12];
   int  len ;

   /* copy str1 into str3 */
   strcpy(str3, str1);
   printf("strcpy( str3, str1) :  %s\n", str3 );

   /* concatenates str1 and str2 */
   strcat( str1, str2);
   printf("strcat( str1, str2):   %s\n", str1 );

   /* total lenghth of str1 after concatenation */
   len = strlen(str1);
   printf("strlen(str1) :  %d\n", len );

   return 0;
}
```

## Structures

```c
#include <stdio.h>
#include <string.h>

struct Books {
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
};

void printBook( struct Books book );
void printBook2( struct Books *book );

int main( ) {

   struct Books Book1;
   struct Books Book2;

   strcpy( Book1.title, "C Programming");
   strcpy( Book1.author, "Nuha Ali");
   strcpy( Book1.subject, "C Programming Tutorial");
   Book1.book_id = 6495407;

   strcpy( Book2.title, "Telecom Billing");
   strcpy( Book2.author, "Zara Ali");
   strcpy( Book2.subject, "Telecom Billing Tutorial");
   Book2.book_id = 6495700;

   printf( "Book 1 title : %s\n", Book1.title);
   printf( "Book 1 author : %s\n", Book1.author);
   printf( "Book 1 subject : %s\n", Book1.subject);
   printf( "Book 1 book_id : %d\n", Book1.book_id);

   printf( "Book 2 title : %s\n", Book2.title);
   printf( "Book 2 author : %s\n", Book2.author);
   printf( "Book 2 subject : %s\n", Book2.subject);
   printf( "Book 2 book_id : %d\n", Book2.book_id);

   printBook( Book1 );
   printBook2( &Book1 );

   return 0;
}

void printBook( struct Books book ) {
   printf( "Book title : %s\n", book.title);
   printf( "Book author : %s\n", book.author);
   printf( "Book subject : %s\n", book.subject);
   printf( "Book book_id : %d\n", book.book_id);
}

void printBook2( struct Books *book ) {
   printf( "Book title : %s\n", book->title);
   printf( "Book author : %s\n", book->author);
   printf( "Book subject : %s\n", book->subject);
   printf( "Book book_id : %d\n", book->book_id);
}
```

## Unions

Store different data types in the same memory location.

```c
#include <stdio.h>
#include <string.h>

union Data {
   int i;
   float f;
   char str[20];
};

int main( ) {
   union Data data;

   printf( "Memory size occupied by data : %d\n", sizeof(data)); // 20

   data.i = 10;
   data.f = 220.5;
   strcpy( data.str, "C Programming");

   printf( "data.i : %d\n", data.i); // data.i : 1917853763
   printf( "data.f : %f\n", data.f); // data.f : 4122360580327794860452759994368.000000
   printf( "data.str : %s\n", data.str); // data.str : C Programming

   return 0;
}
```

## Bit Fields

You can at most use 1 bit for each variable.

The minimum size is a WORD.

```c
#include <stdio.h>
#include <string.h>

// Requires 8 bytes
struct {
   unsigned int widthValidated;
   unsigned int heightValidated;
} status1;

// Requires 4 bytes, only 2 bits are used.
struct {
   unsigned int widthValidated : 1;
   unsigned int heightValidated : 1;
} status2;

int main( ) {
   printf( "Memory size occupied by status1 : %d\n", sizeof(status1)); // Memory size occupied by status1 : 8
   printf( "Memory size occupied by status2 : %d\n", sizeof(status2)); // Memory size occupied by status2 : 4
   return 0;
}
```

If you will use up to 32 variables each one with a width of 1 bit, then also the status structure will use 4 bytes.

If you try to use more bits than the requested you are going to do a no-op.

## Typedef

Type alias `typedef unsigned char BYTE;`.

```c
#include <stdio.h>
#include <string.h>

typedef struct Books {
   char title[50];
   char author[50];
   char subject[100];
   int book_id;
} Book;

#define TRUE  1
#define FALSE 0

int main( ) {
   Book book; // no need to write struct.
              // works the same way.

   printf("Value of True: %d\n", TRUE);

   return 0;
}
```

### typedef vs #define

`typedef` can only be used for type aliases, `#define` can be used for more things.

`typedef` is interpreted by the compiler whereas `#define` is processed by the pre-processor.

## Input & Output

```c
int getchar(void); // returns the next available character from the stdin
int putchar(int c);
```
```c
char *gets(char *s); // deprecated in favor of fgets()
int puts(const char *s);

// Example
#include <stdio.h>
int main( ) {
   char str[100];
   printf( "Enter a value :");
   gets( str );
   printf( "\nYou entered: ");
   puts( str );
   return 0;
}
```

```c
int scanf(const char *format, ...)
int printf(const char *format, ...)

// Example
#include <stdio.h>
int main( ) {
   char str[100];
   int i;
   scanf("%s %d", str, &i);
   printf( "\nYou entered: %s %d ", str, i);
   return 0;
}
```

## File I/O

### Open/Close
```c
// mode (you can combine them e.g. rb, wb, rb+):
// r     read
// w     write (if it does not exist, creates a new file)
// a     append (if it does not exist, creates a new file)
// r+    read+write
// w+    read+write. Truncates the file to 0  (if it does not exist, creates a new file)
// a+    read+wite. read from start, write appending (if it does not exist, creates a new file)
FILE *fopen( const char * filename, const char * mode );
int fclose( FILE *fp );
```

### Writing

```c
int fputc( int c, FILE *fp ); // single char
int fputs( const char *s, FILE *fp ); // string
int fprintf(FILE *fp,const char *format, ...) // similar to fputs

//Example
#include <stdio.h>

main() {
   FILE *fp;
   fp = fopen("/tmp/test.txt", "w+");
   fprintf(fp, "This is testing for fprintf...\n");
   fputs("This is testing for fputs...\n", fp);
   fclose(fp);
}
```

### Reading

```c
int fgetc( FILE * fp ); // Char
char *fgets( char *buf, int n, FILE *fp ); // appends a null character aat the end of buf.
                                           // stops when it encounters a '\n' or EOF or reads n characters.
int fscanf(FILE *fp, const char *format, ...)

//Example
#include <stdio.h>

main() {
   FILE *fp;
   char buff[255];

   fp = fopen("/tmp/test.txt", "r");
   fscanf(fp, "%s", buff);
   printf("1 : %s\n", buff );

   fgets(buff, 255, (FILE*)fp);
   printf("2: %s\n", buff );

   fgets(buff, 255, (FILE*)fp);
   printf("3: %s\n", buff );
   fclose(fp);
}
```


### Binary I/O Functions

```c
size_t fread(void *ptr, size_t size_of_elements, size_t number_of_elements, FILE *a_file);

size_t fwrite(const void *ptr, size_t size_of_elements, size_t number_of_elements, FILE *a_file);
```

## Preprocessors

CPP (C preprocessor) is a separate state in the compilation process.

```c
#define          Substitutes a preprocessor macro.
#include         Inserts a particular header from another file.
#undef           Undefined a preprocessor macro.
#ifdef           Returns true if this macro is defined.
#ifndef          Returns true if this macro is not defined.
#if              Test if a compiler time condition is true.
#else
#elif
#endif
#error          Prints error message on stderr.
#pragma         Issues special commands to the compiler, using a standardized method.

// Examples
#define MAX_ARRAY_LENGTH 20

#include <stdio.h>
#include "myheader.h"

#undef  FILE_SIZE
#define FILE_SIZE 42

#ifndef MESSAGE
   #define MESSAGE "You wish!"
#endif

#ifdef DEBUG
   #error "DEBUG MODE"
#endif
```

### Predefined macros

```c
#include <stdio.h>

int main() {
   printf("File :%s\n", __FILE__ ); // File :test.c
   printf("Date :%s\n", __DATE__ ); // Date :Jun 2 2012
   printf("Time :%s\n", __TIME__ ); // Time :03:36:24
   printf("Line :%d\n", __LINE__ ); // Line :8
   printf("ANSI :%d\n", __STDC__ ); // ANSI :1
}
```

### Preprocessor Operators

The Macro Continuation (\) Operator

The Stringize (#) Operator

```c
#include <stdio.h>

#define  message_for(a, b)  \
   printf(#a " and " #b ": We love you!\n")

int main(void) {
   message_for(Carole, Debra); // Carole and Debra: We love you!
   return 0;
}
```

The Token Pasting (##) Operator

```c
#include <stdio.h>

#define tokenpaster(n) printf ("token" #n " = %d", token##n)

int main(void) {
   int token34 = 40;
   // Replaced by:
   // printf ("token34 = %d", token34);
   tokenpaster(34); // Outputs: token34 = 40
   return 0;
}
```

The Defined() Operator

```c
#include <stdio.h>

#if !defined (MESSAGE)
   #define MESSAGE "You wish!"
#endif

int main(void) {
   printf("Here is the message: %s\n", MESSAGE);
   return 0;
}
```

Parameterized Macros

The definition will be __inlined__.

```c
#include <stdio.h>

#define MAX(x,y) ((x) > (y) ? (x) : (y))

int main(void) {
   printf("Max between 20 and 10 is %d\n", MAX(10, 20));
   return 0;
}
```

## Header Files

File with extension __.h__ which contains function declarations and macro definitions to be shared.

The compiler comes with some header files.

```c
#include <stdio.h> // System headers files.       You can add directories using -l
#include "file" // Only in the current directory. You can add directories using -l
```

The preprocessors copies the source of the header file into your program.

Prevent copying the header file multiple types.

```c
#ifndef STDIO
#define STDIO
  #include <stdio.h>
#endif
```

## Type Casting

Cast operator: `mean = (double) sum / count;`

## Error Handling

Error codes defined in <error.h>.

errno, perror(), and strerror()

```c
#include <stdio.h>
#include <errno.h>
#include <string.h>

extern int errno ;

int main () {

   FILE * pf;
   int errnum;
   pf = fopen ("unexist.txt", "rb");

   if (pf == NULL) {

      errnum = errno;
      fprintf(stderr, "Value of errno: %d\n", errno); // Value of errno: 2
      perror("Error printed by perror"); // Error printed by perror: No such file or directory
      fprintf(stderr, "Error opening file: %s\n", strerror( errnum )); // Error opening file: No such file or directory
   } else {

      fclose (pf);
   }

   return 0;
}
```

## Variable Arguments

```c
#include <stdio.h>
#include <stdarg.h> // required for variadic arguments

double average(int num,...) {

   va_list valist;
   double sum = 0.0;
   int i;

   /* initialize valist for num number of arguments */
   va_start(valist, num);

   /* access all the arguments assigned to valist */
   for (i = 0; i < num; i++) {
      sum += va_arg(valist, int);
   }

   /* clean memory reserved for valist */
   va_end(valist);

   return sum/num;
}

int main() {
   printf("Average of 2, 3, 4, 5 = %f\n", average(4, 2,3,4,5));
   printf("Average of 5, 10, 15 = %f\n", average(3, 5,10,15));
}
```

## Memory Management

From `<stdlib.h>`:

```c
void *calloc(int num, int size); // num * size bytes
void free(void *address);
void *malloc(int num); // num bytes
void *realloc(void *address, int newsize); // extens allocated memory up to newsize.
```

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

   char name[100];
   char *description;

   strcpy(name, "Zara Ali");

   description = malloc( 200 * sizeof(char) );

   if( description == NULL ) {
      fprintf(stderr, "Error - unable to allocate required memory\n");
   } else {
      strcpy( description, "Zara ali a DPS student in class 10th");
   }

   printf("Name = %s\n", name );
   printf("Description: %s\n", description ); // Description: Zara ali a DPS student in class 10th
}
```

## Command Line Arguments

```bash
$./a.out testing
The argument supplied is testing
```

```c
#include <stdio.h>

// argv[0] = name of the program
// argv[1] pointer to the first command line argument.
int main( int argc, char *argv[] )  {

   if( argc == 2 ) {
      printf("The argument supplied is %s\n", argv[1]);
   }
   else if( argc > 2 ) {
      printf("Too many arguments supplied.\n");
   }
   else {
      printf("One argument expected.\n");
   }
}

```


# Tutorial: GCC and Make

## GCC

Source: <https://www3.ntu.edu.sg/home/ehchua/programming/cpp/gcc_make.html>

The GNU C Compiler (GCC). Current version 8.3.0

```bash
# 1.
$ gcc -Wall -g source1.c source2.c -o program_name

-g: debug
-v: verbose
-Dname: defining macros. Example -DDEBUG="TRUE", -DHaskell="Haskell 98"

# 2. Compile and then link
$ gcc -c -Wall hello.c
$ gcc -c -Wall util.c
$ gcc hello.o util.o -o hello

# Shared library .so
Compile using -shared
```

### GCC Compilation Process

```
Source (.c, .h)

      Preprocessing (cpp)

Include Header, Expand Macro (.i)

      Compilation (gcc)

Assembly Code (.s)

      Assemble (as)

Machine Code (.o)

      Linking (ld)

Static Library (.a)
Executable Machine Code
```

GCC compiles the program in the four previous steps:

```bash
# Pre-processing
$ cpp hello.c > hello.i
# Compilation
$ gcc -S hello.i
# Assembly
$ as -o hello.o hello.s
# Linker
$ ld -o hello hello.o ..libraries...
```

### Headers (.h), Static Libraries (.a) and Shared Libraries (.a)

#### Static vs Shared

A library is a collection of pre-compiled object files that can be linked into your programs via the linker.

Static (.a): the code is copied into the executable.

Dynamic (.so): only a small table of references is copied. Before the executable is run, the OS loads the machine code needed for the external functions (dynamic linking).

#### Searching for Header Files and Libraries (-I, -L and -l)

The __compiler__ needs the __headers file__ to compile the code.

The __linker__ needs the __libraries__ to resolve external references from other object files or libraries.

For headers: gcc option `-Idir` or `CPATH` environment variable.

For librares: `-Ldir` or `LIBRARY_PATH`. In addition, you also have to specify the library name: `-lxxx.a`.

The are some default paths:

```bash
$ gcc -v -o hello hello.c
# -L/usr/lib/gcc/x86_64-pc-cygwin/6.4.0
# -L/usr/x86_64-pc-cygwin/lib
# -L/usr/lib
# -L/lib
# -lgcc_s     // libgcc_s.a
# -lgcc       // libgcc.a
# -lcygwin    // libcygwin.a
# -ladvapi32  // libadvapi32.a
# -lshell32   // libshell32.a
# -luser32    // libuser32.a
# -lkernel32  // libkernel32.a
```

#### Utilities for examining the compiled files

```bash
# File type
$ file
# List symbol table of object files
$ nm hello.o
# List Dynamic-Link Libraries
$ ldd hello
```

## Make

Automate compilation.

```make
# Makefile
CC = gcc -Wall

all: hello

# Checks if hello.o exists, otherwise looks for a rule to create it.
hello: hello.o
	 $(CC) -o hello hello.o

hello.o: hello.c
	 $(CC) -c hello.c

clean:
	 rm hello.o hello
```

### Automatic variables

```
$@: the target filename.
$*: the target filename without the file extension.
$<: the first prerequisite filename.
$^: the filenames of all the prerequisites, separated by spaces, discard duplicates.
$+: similar to $^, but includes duplicates.
$?: the names of all prerequisites that are newer than the target, separated by spaces.
```

Example:

```make
all: hello

# $@ matches the target; $< matches the first dependent
hello: hello.o
	gcc -o $@ $<

hello.o: hello.c
	gcc -c $<

clean:
	rm hello.o hello
```

### Virtual Path (VPATH)

```make
# Search for dependencies and targets from "src" and "include" directories
# The directories are separated by space
VPATH = src include
```

### Pattern Rules

```make
# Applicable for create .o object file.
# '%' matches filename.
# $< is the first pre-requisite
# $(COMPILE.c) consists of compiler name and compiler options
# $(OUTPUT_OPTIONS) could be -o $@
%.o: %.c
	$(COMPILE.c) $(OUTPUT_OPTION) $<

# Applicable for create executable (without extension) from object .o object file
# $^ matches all the pre-requisites (no duplicates)
%: %.o
$(LINK.o) $^ $(LOADLIBES) $(LDLIBS) -o $@
```

### A sample Makefile

```make
# A sample Makefile
# This Makefile demonstrates and explains
# Make Macros, Macro Expansions,
# Rules, Targets, Dependencies, Commands, Goals
# Artificial Targets, Pattern Rule, Dependency Rule.

# Comments start with a # and go to the end of the line.

# Here is a simple Make Macro.
LINK_TARGET = test_me.exe

# Here is a Make Macro that uses the backslash to extend to multiple lines.
OBJS =  \
 Test1.o \
 Test2.o \
 Main.o

# Here is a Make Macro defined by two Macro Expansions.
# A Macro Expansion may be treated as a textual replacement of the Make Macro.
# Macro Expansions are introduced with $ and enclosed in (parentheses).
REBUILDABLES = $(OBJS) $(LINK_TARGET)

# Here is a simple Rule (used for "cleaning" your build environment).
# It has a Target named "clean" (left of the colon ":" on the first line),
# no Dependencies (right of the colon),
# and two Commands (indented by tabs on the lines that follow).
# The space before the colon is not required but added here for clarity.
clean :
  rm -f $(REBUILDABLES)
  echo Clean done

# There are two standard Targets your Makefile should probably have:
# "all" and "clean", because they are often command-line Goals.
# Also, these are both typically Artificial Targets, because they don't typically
# correspond to real files named "all" or "clean".

# The rule for "all" is used to incrementally build your system.
# It does this by expressing a dependency on the results of that system,
# which in turn have their own rules and dependencies.
all : $(LINK_TARGET)
  echo All done

# There is no required order to the list of rules as they appear in the Makefile.
# Make will build its own dependency tree and only execute each rule only once
# its dependencies' rules have been executed successfully.

# Here is a Rule that uses some built-in Make Macros in its command:
# $@ expands to the rule's target, in this case "test_me.exe".
# $^ expands to the rule's dependencies, in this case the three files
# main.o, test1.o, and  test2.o.
$(LINK_TARGET) : $(OBJS)
  g++ -g -o $@ $^

# Here is a Pattern Rule, often used for compile-line.
# It says how to create a file with a .o suffix, given a file with a .cpp suffix.
# The rule's command uses some built-in Make Macros:
# $@ for the pattern-matched target
# $< for the pattern-matched dependency
%.o : %.cpp
  g++ -g -o $@ -c $<

# These are Dependency Rules, which are rules without any command.
# Dependency Rules indicate that if any file to the right of the colon changes,
# the target to the left of the colon should be considered out-of-date.
# The commands for making an out-of-date target up-to-date may be found elsewhere
# (in this case, by the Pattern Rule above).
# Dependency Rules are often used to capture header file dependencies.
Main.o : Main.h Test1.h Test2.h
Test1.o : Test1.h Test2.h
Test2.o : Test2.h

# Alternatively to manually capturing dependencies, several automated
# dependency generators exist.  Here is one possibility (commented out)...
# %.dep : %.cpp
#   g++ -M $(FLAGS) $< > $@
# include $(OBJS:.o=.dep)
```
