# BadApplePlayer
Play Bad Apple in your terminal! Depends on OpenCV and ncurses, written in C++. Currently only tested in Ubuntu but feel free to try it anywhere, it is built with cmake after all.

## Running in Ubuntu
Ensure you distro is up to date. You may need OpenCV, ncurses, and cmake installed:
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
