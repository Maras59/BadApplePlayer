# BadApplePlayer
A simple program that plays Bad Apple in your Linux terminal, currently only tested in ubuntu

## Running The Program
Ensure you distro is up to date and you have cmake installed:

`sudo apt update && sudo apt install -y cmake`

Install OpenCV:

`sudo apt install libopencv-dev`

Create a `build` directory if one does not exist. Inside of the build directory run the following commands:
~~~
cmake .. 
make
~~~

You can now run `./OpenCVTest`