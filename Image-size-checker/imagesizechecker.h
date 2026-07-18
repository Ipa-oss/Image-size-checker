#ifndef IMAGESIZECHECKER_H
#define IMAGESIZECHECKER_H

#include <QMainWindow>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class ImageSizeChecker;
}
QT_END_NAMESPACE

class ImageSizeChecker : public QMainWindow
{
    Q_OBJECT

public:
    explicit ImageSizeChecker(QWidget *parent = nullptr);
    ~ImageSizeChecker() override;

private:
    Ui::ImageSizeChecker *ui;
    bool imageSizeConfirmation(QString,int,int);
    void getPath();
    void getFilesInDir();
    QImage image;
    QFileDialog fileWindow;
    QString path;
    QString strMinHeight = "";
    QString strMinWidth = "";
    int minHeight = 0;
    int minWidth = 0;
};
#endif // IMAGESIZECHECKER_H
