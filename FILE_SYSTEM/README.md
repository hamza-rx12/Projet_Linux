To mount the file system you need to use source command:
	source ./setup.sh
Running the setup.sh file without it wont work as the export command 
inside the script cant is run inside a subshell and wont affect the shell.
