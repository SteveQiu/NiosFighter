NiosFighter
===========

For EECE 381

How to use this git repository:

In this repo:
.c 
.h 
.gsys 
.vhd

All project related files manage yourself! Dont pollute this repo with files that we will not edit
ie. Machine Generated Files 

Setup Instructions (please follow):

Initially we assume you have the following file directory structure:
".../eece381/", this top level directory will subsequently be referenced with a simple '/'

1. Create a src folder (/src)
2. init the git repository in the src folder (/src/.git/)
3. add the remote object and pull
	/src/
		.git/
		system/
		software/
		README.md
		etc...
4. Create a quartus two project with the top level directory as the project directory
	/src
	/NiosFighter.qpf
	/etc..
5. Using qsys, build the .qsys file in the /src/system/ directory
6. add the generated .qip file to the quartus two project
7. Add the .vhd file to the quartus 2 project /src/NiosFighter.vhd
8. The quartus two project should now compile. Import the Pin Assignment file then compile
9. Open eclipse for nios tool
10. Create a new project+bsp template project
11. use the generated .sopcinfo file as the eclipse sopcinfo file
12. set the project directory as /src/software/NiosFighter
13. set the bsp project directory as /src/software/NiosFighter_bsp
14. Generate the BSP in eclipse
15. refresh the NiosFighter project (do this after every git pull, it will add the source files to the project)
16. You should now be able to build the NiosFighter project