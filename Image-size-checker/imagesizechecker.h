#ifndef IMAGESIZECHECKER_H
#define IMAGESIZECHECKER_H

#include <QMainWindow>

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
    bool CreateFileFromPath();
    bool moveToNewFolder();
};
#endif // IMAGESIZECHECKER_H
