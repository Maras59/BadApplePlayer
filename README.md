# BadApplePlayer
A simple program that plays Bad Apple in your Linux terminal, currently only tested in ubuntu

## Running The Program
Ensure you distro is up to date and you have cmake installed:

`sudo apt update && sudo apt install -y cmake`

Install OpenCV:

`sudo apt install libopencv-dev`

Inside of the base directory run the following commands:
~~~
mkdir build
cd build
cmake .. 
make
~~~

You can now run the `./BadApple` binary inside the `build` directory