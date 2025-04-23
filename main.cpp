#include <opencv2/opencv.hpp>
// #include <opencv4/opencv2/core/hal/interface.h>
#include <iostream>
#include <ncurses.h>
#include <vector>

 
using namespace std;
using namespace cv;
 

const string ASCII_CHARS = " .:-=+*#%@";

char getAsciiChar(uchar intensity) {
    size_t index = (intensity * (ASCII_CHARS.length() - 1)) / 255;
    return ASCII_CHARS[index];
}

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
    nodelay(stdscr, TRUE);

    WINDOW *win = newwin(LINES - 2, COLS - 2, 1, 1);

    int width = static_cast<int>(cap.get(CAP_PROP_FRAME_WIDTH));
    int height = static_cast<int>(cap.get(CAP_PROP_FRAME_HEIGHT));

    int scaled_w;
    int scaled_h;

    double aspect_ratio = height / (width * 2.5); // TODO: Does this need to be hardcoded? Is there a better number to account for char height? 

    while(1){
        Mat o_frame, rs_frame, f_frame; // Original, resized, final
        cap >> o_frame;
        if (o_frame.empty())
            break;
        
        // Recalculate every frame to allow dynamic resizing
        scaled_w = min(width, COLS - 2);
        scaled_h = int(static_cast<double>(width) * aspect_ratio);
        if (scaled_h > LINES - 2) {
            // If the scaled height exceeds max height, scale based on height instead
            scaled_h = min(height, LINES - 2);
            scaled_w = static_cast<int>(static_cast<double>(scaled_h) / aspect_ratio);
        }

        resize(o_frame, rs_frame, Size(scaled_w, scaled_h));
        cvtColor(rs_frame, f_frame, COLOR_BGR2GRAY);
        
        double fps = cap.get(CAP_PROP_FPS);
        int delay = static_cast<int>(1000 / fps);
        napms(delay);

        curs_set(0);
        clear();

        // represent data in ascii and print to screen.
        for (int y = 0; y < f_frame.rows; y++) {
            for (int x = 0; x < f_frame.cols; x++) {
                uchar pixel = f_frame.at<uchar>(y,x);
                mvaddch(y, x, getAsciiChar(pixel));
            }
        }
    
        refresh();

        if (getch() == 'q') break;
    }
    
    
    cap.release();
    destroyAllWindows();
    endwin();
    return 0;
}