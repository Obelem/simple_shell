# So here's the modifications I made

## 1. Workflow
The program now takes this route:

** prompt() -> tokenifier() -> file_path() -> read_cmd(); **

## 2. Why the file_stat() function?
* It adds path to the command line input

* Also prevents the program from calling the fork() system call if the command doesn't exist by using the stat() system call.

## Things to edit
There are a bunch of standard library functions I used, please make custom versions.

***Cheers***
