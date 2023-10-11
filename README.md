The following C programs are for ALX simple_shell project, inside it contains the following shell programs:

* A beautiful code that passes the Betty checks
* A UNIX command line interpreter
* A simple shell 0.1 + that handle's command lines with arguments
* A simple shell 0.2 + that handle's the PATH and fork must not be called if the command doesn’t exist
* A simple shell 0.3 + that:
         -> Implement the exit built-in, that exits the shell
         -> Usage: exit
         -> You don’t have to handle any argument to the built-in exit
* A simple shell 0.4 + that implement the env built-in, that prints the current environment
* A simple shell 0.1 + that:
         -> Write your own getline function
         -> Use a buffer to read many chars at once and call the least possible the read system call
         -> You will need to use static variables
         -> You are not allowed to use getline
* A simple shell 0.2 +
* A simple shell 0.4 + that
         -> handle arguments for the built-in exit
         -> Usage: exit status, where status is an integer used to exit the shell
* A simple shell 1.0 + that implement the setenv and unsetenv builtin commands
         -> setenv
            - Initialize a new environment variable, or modify an existing one
            - Command syntax: setenv VARIABLE VALUE
            - Should print something on stderr on failure
         -> unsetenv
            - Remove an environment variable
            - Command syntax: unsetenv VARIABLE
            - Should print something on stderr on failure
* A simple shell 1.0 +
         -> Implement the builtin command cd
            - Changes the current directory of the process
            - Command syntax: cd [DIRECTORY]
            - If no argument is given to cd the command must be interpreted like cd $HOME
            - You have to handle the command cd -
            - You have to update the environment variable PWD when you change directory
* A simple shell 1.0 + that handle's the commands separator ;
* A simple shell 1.0 + that handle's the && and || shell logical operators
* A simple shell 1.0 +
         -> Implement the alias builtin command
         -> Usage: alias [name[='value'] ...]
            - alias: Prints a list of all aliases, one per line, in the form name='value'
            - alias name [name2 ...]: Prints the aliases name, name2, etc 1 per line, in the form name='value'
            - alias name='value' [...]: Defines an alias for each name whose value is given. If name is already an alias, replaces its value              with value
* A simple shell 1.0 +
         -> Handle variables replacement
         -> Handle the $? variable
         -> Handle the $$ variable
* A simple shell 1.0 + that handle comments (#)
* A simple shell 1.0 +
         -> Usage: simple_shell [filename]
         -> Your shell can take a file as a command line argument
         -> The file contains all the commands that your shell should run before exiting
         -> The file should contain one command per line
         -> n this mode, the shell should not print a prompt and should not read from stdin
