#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>
#include <string>
using namespace std;
using namespace cv;
int main(){
    char i_path[20];
    cin >> i_path;
    Mat img;
    img = imread(i_path,IMREAD_COLOR);
    if (img.empty()){
        cout<<"cannot load"<<endl;
        waitKey(400);
        return 1;
    }
    imshow("image",img);
    waitKey();
    Mat out;
    QRCodeDetector Qrc;
    Qrc.detect(img,out);
    string outstr;
    outstr = Qrc.decode(img,out,out);
    cout << outstr <<endl;
    imshow("found QRcode:",out);
    waitKey();
    return 0;
}