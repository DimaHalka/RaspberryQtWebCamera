#include <QApplication>
#include <QTimer>
#include <QLabel>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    VideoCapture cap(0);
    if (!cap.isOpened()) {
        qDebug() << "Error: Unable to open the webcam";
        return -1;
    }

    QLabel label;
    label.show();

    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, [&]() {
        Mat frame;
        cap >> frame; // Capture a frame from the webcam

        QImage qImage(frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);
        label.setPixmap(QPixmap::fromImage(qImage.rgbSwapped())); // Swapping RGB to BGR

        label.setScaledContents(true);
        label.adjustSize();
    });
    timer.start(30); // Update every 30 milliseconds

    return a.exec();
}
