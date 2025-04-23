#include <opencv2/opencv.hpp>
// #include <opencv4/opencv2/core/hal/interface.h>
#include <iostream>
#include <ncurses.h>
#include <vector>

 
using namespace std;
using namespace cv;
 
int main(){
  // Go up a level from "build" directory 
  VideoCapture cap("../BadApple.mp4"); 
  if(!cap.isOpened()){
    cout << "Error opening video stream or file" << endl;
    return -1;
  }
  // Initialize ncurses
  initscr();
  noecho();
  cbreak();

  curs_set(0);
  WINDOW *win = newwin(LINES - 2, COLS - 2, 1, 1);

  // Get video aspect ratio from first frame
  int width = static_cast<int>(cap.get(CAP_PROP_FRAME_WIDTH));
  int height = static_cast<int>(cap.get(CAP_PROP_FRAME_HEIGHT));

  int scaled_w;
  int scaled_h;

  double aspect_ratio = height / (width * 2.5); // TODO: Does this need to be hardcoded? Is there a better number to account for char height? 

  scaled_w = min(width, COLS - 2);
  scaled_h = int(static_cast<double>(width) * aspect_ratio);
  if (scaled_h > LINES - 2) {
    // If the scaled height exceeds max height, scale based on height instead
    scaled_h = min(height, LINES - 2);
    scaled_w = static_cast<int>(static_cast<double>(scaled_h) / aspect_ratio);
  }


  while(1){
 
    Mat frame;
    cap >> frame;
    if (frame.empty())
      break;
    
    vector<uchar> array;
    if (frame.isContinuous()) {
      array.assign(frame.data, frame.data + frame.total()*frame.channels());
    }

    // represent data in ascii and print to screen.



 
    char c=(char)waitKey(25);
    if(c==27)
      break;
  }
  
  cap.release();
  destroyAllWindows();
  
  return 0;
}