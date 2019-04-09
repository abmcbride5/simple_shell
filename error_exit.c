#include "shell.h"



int main(void)
/* checks exit status */
{
	ls $some_file
	if ["$?" = "0"]; then
	       rm*
	else
	      echo "Cannot change file!" 1>&2
	      exit 1
fi


/* Exit function */
error_exit()
{
	echo "$1" 1>&2
		exit 1
		}

# Using error_exit

	if ls $some_file; then
		rm *
	else
		error_exit "Cannot change directory!  Aborting."
fi
