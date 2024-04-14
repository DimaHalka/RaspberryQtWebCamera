#include <QApplication>
#include <QTimer>
#include <QLabel>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Open the webcam
    VideoCapture cap(0);
    if (!cap.isOpened()) {
        qDebug() << "Error: Unable to open the webcam";
        return -1;
    }

    // Create a QLabel to display the video stream
    QLabel label;
    label.show();

    // Create a QTimer to update the QLabel with new frames
    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, [&]() {
        Mat frame;
        cap >> frame; // Capture a frame from the webcam

        // Convert the OpenCV frame to a QImage for display
        QImage qImage(frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);
        label.setPixmap(QPixmap::fromImage(qImage.rgbSwapped())); // Swapping RGB to BGR

        // Resize the QLabel to fit the video stream
        label.setScaledContents(true);
        label.adjustSize();
    });
    timer.start(30); // Update every 30 milliseconds

    return a.exec();
}
