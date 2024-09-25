# DockerApp
This will have the source files of a C++ app I made, inspired by Algorithm Visualisers on youtube.
My goal is to containerize it on Linux and deploy on other platforms like Windows and other distributions through docker. 

I'll add how to compile it manually on Linux with SFML including a makefile for handling multiple compiling commands.

## Compiling from source

- Install SFML, I downloaded version 2.6
  * My makefile must be in the same directory as SFML library and include files. Otherwise, edit my makefile
    in accordance to the official SFML and Linux guide.

## Running the application

- If installed normally through package manager ignore this step
- Either edit LD_LIBRARY_PATH or edit /etc/ld.so.conf to have access to library
  * LD_LIBRARY_PATH is quick but unstable if handled incorrectly, use for debugging
    - set this to "/path/to/SFML/lib", so like "~/SFML/lib" in my case
    - Not permanent
  * /etc/ld.so.conf is permanent and much more stable
    -  On docker, we'll be using /etc/ld.so.conf

## How to use Docker
- Use the following to get the image of containerized app: `docker pull dankjoker/algovisualizer:1`
- Using the appropiate Docker compose command this will launch the image within a container
- Using the Bash Script allows local X11 fowarding, Launches the Container, when the user leaves the container it automatically disables the local X11 fowarding permission


###
