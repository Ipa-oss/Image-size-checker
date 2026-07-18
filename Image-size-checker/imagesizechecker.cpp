/* List of tested formats:
.png
.jpg
.jpeg
.gif
.bmp

*/

#include "imagesizechecker.h"
#include "ui_imagesizechecker.h"

#include <QDebug>

ImageSizeChecker::ImageSizeChecker(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ImageSizeChecker)
{
    ui->setupUi(this);
    connect(ui->dirButton,&QPushButton::clicked,this,&ImageSizeChecker::getPath);
    connect(ui->startButton,&QPushButton::clicked,this,&ImageSizeChecker::getFilesInDir);
}

ImageSizeChecker::~ImageSizeChecker()
{
    delete ui;
}

bool ImageSizeChecker::imageSizeConfirmation(QString imagePath, int recievedWidth, int recievedHeight)
{
    QFile file(imagePath); // unified button handler and subfunct? //what?
    if (!file.exists()){
        qDebug()<<"File not found.";
        return false;
    }
    image.load(imagePath);
    qDebug()<<"Height:"<<image.height();
    qDebug()<<"Width:"<<image.width();
    if (recievedHeight > image.height() && recievedWidth > image.width()){
        qDebug()<<"Image is too small.";
        file.moveToTrash();
    }else{
        qDebug()<<"Image is big enough.";
    }
    return true;
}

void ImageSizeChecker::getPath()
{
    ui->fetchedPath->setText(fileWindow.getExistingDirectory(nullptr, "Use directory", "", QFileDialog::ShowDirsOnly)); //Uncanny how well this works
}

void ImageSizeChecker::getFilesInDir()
{
    ui->statusLabel->setText("Status: WORKING DO NOT CLOSE!"); //This doesn't have time to write lmao.
    QWidget::repaint();
    path = ui->fetchedPath->text();
    strMinHeight = ui->minHeight->text();
    strMinWidth = ui->minWidth->text();
    minHeight = strMinHeight.toInt();
    minWidth = strMinWidth.toInt();
    for (QDirListing::DirEntry dirEntry : QDirListing(path, QStringList{"*.png","*.jpg","*.jpeg","*.gif","*.bmp"}, QDirListing::IteratorFlag::FilesOnly)){
        imageSizeConfirmation(dirEntry.filePath(), minWidth, minHeight);
    }
    ui->statusLabel->setText("Status: Finished! Check your trash.");
}
