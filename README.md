# SIMPLE SHELL PROJECT 
**By Pitso Mkansi, And Akatugba Wisdom**

<p align="center"> <strong>DESCRIPTION</strong>  </P>
<p align="justified">                                              This project is an implementation of the shell created as a Milestone Project for C programming language at ALX Africa Software Engineering Remote Program. </br>                            The shell-basic is a project in the month 2 of the first trimester, that helps student to understand the advanced                           concepts behind the shell program include process, system call, bit manipulation, file managment, error handling ... </br>      Shell is a simple UNIX command interpreter that replicates functionalities of the simple shell (sh).


This program was written entirely in C Language.                </p>

# Requirements
#  General
Allowed editors: vi, vim, emacs
All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
All your files should end with a new line
A README.md file, at the root of the folder of the project is mandatory
Your code should use the Betty style. 
It will be checked using betty-style.pl and betty-doc.pl
Your shell should not have any memory leaks 
No more than 5 functions per file          
All your header files should be include guarded 
Use system calls only when you need to (why?)          
# GitHub
*There should be one project repository per group. If you and your partner have a repository with the same name in both your acc
ounts, you risk a 0% score. Add your partner as a collaborator.*

More Info
Output                                                          Unless specified otherwise, your program must have the exact same output as sh (/bin/sh) as well as the exact same error output.The only difference is when you print an error, the name of the program must be equivalent to your argv[0] (See below)
Example of error with sh:

$echo "qwerty" | /bin/sh</br>
/bin/sh: 1: qwerty : not found</br>
$echo "qwerty" | /bin/../bin/sh</br>
/bin/../bin/sh: 1: qwerty: not found</br>
$

Same error with your program hsh:
```
$echo "qwerty" | ./hsh</br>
./hsh: 1: qwerty : not found</br>
$echo "qwerty"|./././hsh</br>
./././hsh: 1: qwerty: not found</br>
$
```
# List of allowed functions and system calls
access (man 2 access)</br>
chdir (man 2 chdir)</br>
close (man 2 close)</br>
closedir (man 3 closedir)</br>
execve (man 2 execve)</br>
exit (man 3 exit)</br>
exit (man 2 exit)</br>
fflush (man 3 fflush)</br>
fork (man 2 fork)</br>
free (man 3 free)</br>
getcwd (man 3 getcwd)</br>
getline (man 3 getline)</br>
getpid (man 2 getpid)</br>
isatty (man 3 isatty)</br>
kill (man 2 kill)</br>
malloc (man 3 malloc)</br>
open (man 2 open)</br>
opendir (man 3 opendir)</br>
perror (man 3 perror)</br>
read (man 2 read)</br>
readdir (man 3 readdir)</br>
signal (man 2 signal)</br>
stat (xstat) (man 2 stat)</br>
lstat (lxstat) (man 2 lstat)</br>
fstat (fxstat) (man 2 fs tat)</br>
strtok (man 3 strtok)</br>
wait (man 2 wait)</br>
waitpid (man 2 waitpid)</br>
wait3 (man 2 wait3)</br>
wait4 (man 2 wait4)</br>
write (man 2 write)</br>

# Compilation
## Your shell will be compiled this way:

`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

# files
- README.md - description about the project repo
- man_1_simple_shell - is the man page for the shell we are going to write.
- AUTHORS - file at the  root of your repository, listing all individuals having contributed content to the repository.
- main.h - is the header file which contains the standared header file and prototype of o function used in the program.
- main.c - initialize the program with infinite loop by call the prompt function  
- prompt.c - it use getline system call to read the input from the user and run infinite loop with fork to keep prompt going.
- special_character - It identiies if the special inputs such as if the frist input is slash,the user typed exit or env...   
- string.c -it handles the strings(string length, write string,find string in directory,concatane strings....) 
- cmd.c - it finds the command the user entered.
- execute.c - execute the command.

## How to add Author file
`Bash script for generating the list of authors in git repo`
```

#!/bin/sh

git shortlog -se \
| perl -spe 's/^\s+\d+\s+//' \
| sed -e '/^CommitSyncScript.*$/d' \
> AUTHORS
