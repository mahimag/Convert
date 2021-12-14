# A Number Converting Utility
Until you starting thinking in base-2 or base-16, converting between decimal,
hexadecimal, and binary integer representations is extremely valuable.  The
conversion is easy, but it is tedious.  Is there a way we could automate the
conversion of an decimal integer to hex or binary?

 Your assignment: write a C-program, **convert**, that takes decimal integers 
and prints the representation of each value
in either hex or binary.  Your code should be in one file in **convert.c**.

  Which representation should the program print?  Convert takes a single
command-line argument that is either "-x" or "-b".  Of course "-x" indicates
that the program should print the value in hexadecimal; "-b" indicates that it
should print binary.

## TEST CASES:
```  
  $./convert -x 1234
  1234=0x4d2
  
  $./convert -x 1234 4231
  1234=0x4d2
  4321=0x10e1

  $./convert -b 1234 4321
  1234=100 1101 0010
  4321=1 0000 1110 0001

  $./convert
  Usage: ./convert [-x|-b] num1 [num2 ...]
  
  $./convert -b
  Usage: ./convert [-x|-b] num1 [num2 ...]
  
  $./convert -x
  Usage: ./convert [-x|-b] num1 [num2 ...]
  
  $./convert 1234
  Usage: ./convert [-x|-b] num1 [num2 ...]
 ```
In the examples above, `$` is the Unix command prompt.

# Parsing Command Line Arguments
Unix command line programs like **convert** usually take command line arguments. Parsing and figuring out what to do
with command line arguments is part and parcel of computer systems programming. Luckily there are functions
that help us out with command line parsing. The one you should use is `getopt`. You can find out more about it by
typing
```
 man 3 getopt
```
on the Unix command line.

# Strings to Ints
In C, strings are converted to ints with the `atoi` function. Find out more with
```
 man 3 atoi
```

# Useful string functions
In C, taking care to not overflow buffers is a critical skill. 
The `sprintf` and `asprintf` functions may be useful in this homework:
```
man 3 asprintf
```

# Usage and Errors
Normally, C programs should print errors to stderr and exit with a code other than 1. In our case, this messes up the automated tests which expect
output to stdout and a return code of 0. Therefore, make sure you **print all messages to stdout, including the Usage message, and exit with 0**.
 
# Submitting
Write your code in **convert.c**. There is a Makefile that allows you to build your program with `make`. To use it, you will
want to clone the code in this repo to your local machine.

Submit **convert.c** to this repo. Autograded tests will run. Make sure to check that you got the test
cases correct.

