
# Unix Utilities

This project aims to provide a collection of simplified UNIX utilities implemented in C, including versions of commonly used commands such as cat, grep, zip, and unzip. Each utility is implemented to perform specific tasks efficiently within the Unix environment.

## cat

The program **wcat** is a simple program. Generally, it reads a file as
specified by the user and prints its contents. A typical usage is as follows,
in which the user wants to see the contents of main.c, and thus types: 

```
prompt> ./wcat main.c
#include <stdio.h>
...
```

**Details**

* **wcat** can be invoked with one or more files on the command
  line; it just print out each file in turn. 
* In all non-error cases, **wcat** exits with status code 0.
* If *no files* are specified on the command line, **wcat** just exit
  and return 0.
* If the program tries to **fopen()** a file and fails, it prints
  message "wcat: cannot open file" and exit
  with status code 1.  If multiple files are specified on the command line,
  the files is printed out in order until the end of the file list is
  reached or an error opening a file is reached. 


## grep

**wgrep**, a variant of the UNIX
tool **grep**. This tool looks through a file, line by line, trying to find a
user-specified search term in the line. If a line has the word within it, the
line is printed out, otherwise it is not. 

Here is how a user would look for the term **foo** in the file **bar.txt**:

```
prompt> ./wgrep foo bar.txt
this line has foo in it
so does this foolish line; do you see where?
even this line, which has barfood in it, will be printed.
```

**Details**

* **wgrep** is always passed a search term and zero or
  more files to grep through. It go
  through each line and see if the search term is in it; if so, the line
  should be printed, and if not, the line should be skipped.
* The matching is case sensitive. Thus, if searching for **foo**, lines
  with **Foo** will *not* match.
* If **wgrep** is passed no command-line arguments, it prints
  "wgrep: searchterm [file ...]" (followed by a newline) and exit with
  status 1.  
* If **wgrep** encounters a file that it cannot open, it prints
  "wgrep: cannot open file" (followed by a newline) and exit with status 1. 
* In all other cases, **wgrep** exits with return code 0.

## wzip and wunzip

**wzip** is a
file compression tool, and the **wunzip** is a file decompression
tool. 

The type of compression used here is a simple form of compression called
*run-length encoding* (*RLE*). RLE is quite simple: when you encounter **n**
characters of the same type in a row, the compression tool (**wzip**) will
turn that into the number **n** and a single instance of the character.

Thus, if we had a file with the following contents:
```
aaaaaaaaaabbbb
```
the tool would turn it (logically) into:
```
10a4b
```

**wzip** tool uses shell 
redirection in order to write the compressed output to a file. For example,
to compress the file **file.txt** into a (hopefully smaller) **file.z**,
you would type:

```
prompt> ./wzip file.txt > file.z
```

The **wunzip** tool simply does the reverse of the **wzip** tool, taking
in a compressed file and writing (to standard output again) the uncompressed
results. For example, to see the contents of **file.txt**, you would type:

```
prompt> ./wunzip file.z
```

**wunzip** should read in the compressed file
and print out the uncompressed output to standard output.

**Details**

* Correct invocation should pass one or more files via the command line to the 
  program; if no files are specified, the program should exit with return code
  1 and print "wzip: file1 [file2 ...]" (followed by a newline) or
  "wunzip: file1 [file2 ...]" (followed by a newline) for **wzip** and
  **wunzip** respectively. 
* Do note that if multiple files are passed to **wzip*, they are compressed
  into a single compressed output, and when unzipped, will turn into a single
  uncompressed stream of text (thus, the information that multiple files were
  originally input into **wzip** is lost). The same thing holds for
  **wunzip**. 
