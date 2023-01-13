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
    while (true)
    {
        char i_path[20];
        cin >> i_path;
        Mat img;
        img = imread(i_path, IMREAD_COLOR);
        if (img.empty())
        {
            cout << "cannot load" << endl;
            waitKey(400);
            return 1;
        }
        imshow("image", img);
        waitKey(2000);
        Mat out;
        QRCodeDetector Qrc;
        Qrc.detect(img, out);
        string outstr;
        outstr = Qrc.decode(img, out, out);
        if (outstr.length() > 0)
        {
            cout << outstr << endl;
            imshow("found QRcode:", out);
            destroyWindow("image");
            waitKey();
            destroyWindow("found QRcode:");
        }
        else
        {
            cout << "cannot find QR code in given picture" << endl;
            destroyWindow("image");
        }
        if (pollKey()=='q'){
            break;
        }
        
    }
    return 0;
}