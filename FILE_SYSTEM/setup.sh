#!/bin/bash

#sudo apt install gcc

mkdir -p FILE_SYSTEM
for file in ./src/*.c
do
    gcc -o ./FILE_SYSTEM/$(basename "$file" .c) "$file"
done

echo -e "OPTIONS:\n\t1.mount ID-FS.\n\t2.unmount ID-FS.\n"
read -p "Enter an option: " x
while [ $x -ne 1 ] && [ $x -ne 2 ];
do
	echo -e "Enter a valid option: "
	read x
done
 
if [ $x -eq 1 ];then
	export PATH=$(echo $(pwd))/FILE_SYSTEM:$PATH
	#!/bin/bash
	echo "██╗    ██╗███████╗██╗      ██████╗ ██████╗ ███╗   ███╗███████╗"
	echo "██║    ██║██╔════╝██║     ██╔════╝██╔═══██╗████╗ ████║██╔════╝"
	echo "██║ █╗ ██║█████╗  ██║     ██║     ██║   ██║██╔████╔██║█████╗  "
	echo "██║███╗██║██╔══╝  ██║     ██║     ██║   ██║██║╚██╔╝██║██╔══╝  "
	echo "╚███╔███╔╝███████╗███████╗╚██████╗╚██████╔╝██║ ╚═╝ ██║███████╗"
	echo " ╚══╝╚══╝ ╚══════╝╚══════╝ ╚═════╝ ╚═════╝ ╚═╝     ╚═╝╚══════╝"
	echo "                                                              "
	echo "████████╗ ██████╗     ██╗██████╗       ███████╗███████╗██╗    "
	echo "╚══██╔══╝██╔═══██╗    ██║██╔══██╗      ██╔════╝██╔════╝██║    "
	echo "   ██║   ██║   ██║    ██║██║  ██║█████╗█████╗  ███████╗██║    "
	echo "   ██║   ██║   ██║    ██║██║  ██║╚════╝██╔══╝  ╚════██║╚═╝    "
	echo "   ██║   ╚██████╔╝    ██║██████╔╝      ██║     ███████║██╗    "
	echo "   ╚═╝    ╚═════╝     ╚═╝╚═════╝       ╚═╝     ╚══════╝╚═╝    "

else 
	sudo rm -r FILE_SYSTEM
	echo "ID-FS unmounted."
fi
