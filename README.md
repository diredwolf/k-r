# k-r

## Introduction

Solutions to the exercises from /The C Programming Language/ by Brian Kernighan
and Dennis Ritchie.

I will try to provide a list of helpful resources at the the end of the README.

## Rules

+ Write in ANSI C (C89).
+ Be pedantic; turn on essentially all warnings.
    #+begin_src sh
    cc -O0 -std=c89 -Wall -Wextra -Werror -Wformat=2 -Wunused-variable -Wno-implicit-int -Wno-return-type -pedantic
  #+end_src
+ For a given problem, use only techniques that have already been covered. If a
  more convenient technique or function has been mentioned but not yet
  explained, it is permissible to use it.

## Resources
+ [The GNU C Reference Manual](https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.pdf)
+ [Bit Twiddling Hacks by Sean Eron Anderson](https://web.archive.org/web/20220620232735/http://graphics.stanford.edu/~seander/bithacks.html)

## To do
+ Finish exercises :
  + 1-20
  + 1-21
  + 1-23
  + 1-24
