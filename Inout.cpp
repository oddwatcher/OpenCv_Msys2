#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>
#include <string>
using namespace std;
using namespace cv;
int main()
{
    Mat frame;
    //--- INITIALIZE VIDEOCAPTURE
    VideoCapture cap;
    // open the default camera using default API
    // cap.open(0);
    // OR advance usage: select any API backend
    int deviceID = 0;        // 0 = open default camera
    int apiID = cv::CAP_ANY; // 0 = autodetect default API
    // open selected camera using selected API
    cap.open(deviceID, apiID);
    // check if we succeeded
    if (!cap.isOpened())
    {
        cerr << "ERROR! Unable to open camera\n";
        return -1;
    }
    //--- GRAB AND WRITE LOOP
    cout << "Start grabbing" << endl
         << "Press any key to terminate" << endl;
    for (;;)
    {
        // get a new frame from camera and store it into 'frame'
        cap.read(frame);
        if (frame.empty())// check if succeeded
        {
            cerr << "ERROR! blank frame grabbed\n";
            break;
        }
        // show live and wait for a key with timeout long enough to show images
        imshow("Live", frame);
        waitKey(25);
        QRCodeDetector Qrc;
        Mat detect;
        if (Qrc.detect(frame, detect))
        {
            Mat out;
            string outstr;
            outstr = Qrc.decode(frame, detect, out);
            if (outstr.length() > 0)
            {
                cout << outstr << endl;
                imshow("found QRcode:", out);
                waitKey();
            }
        }
        if (pollKey() == 'q'){
            break;
        }   
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}