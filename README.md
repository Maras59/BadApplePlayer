# BadApplePlayer
A simple program that plays Bad Apple in your Linux terminal, currently only tested in ubuntu

## Running The Program
Ensure you distro is up to date. You will need OpenCV, ncurses, and cmake installed:
~~~
sudo apt install libopencv-dev
sudo apt install cmake
sudo apt-get install libncurses-dev
~~~

Inside of the base directory run the following commands:
~~~
mkdir build
cd build
cmake .. 
make
~~~

You can now run the `./BadApple` binary inside the `build` directory