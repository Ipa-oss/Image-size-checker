#include "imagesizechecker.h"
#include "ui_imagesizechecker.h"
#include <QFile>
#include <QDebug>
#include <QFileInfo>
#include <exiv2/exiv2.hpp>

ImageSizeChecker::ImageSizeChecker(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ImageSizeChecker)
{
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked,this,&ImageSizeChecker::CreateFileFromPath);
}

ImageSizeChecker::~ImageSizeChecker()
{
    delete ui;
}

bool ImageSizeChecker::CreateFileFromPath()
{
    QString path = ui->lineEdit->text();
    QFile file(path);
    qDebug()<<file.exists();
    if(file.open(QIODevice::ReadWrite|QIODevice::Text)){
        qDebug()<<"Create "<<path<<" Success!";
    }
    else{
        qDebug()<<"Create "<<path<<" Failed!";
        return false;
    }
    qDebug()<<"progress1";
    QByteArray stringBA = path.toLocal8Bit();
    const char* stdPath = stringBA.data();
    Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open(stdPath);
    qDebug()<<"progress2";
    image->readMetadata();
    Exiv2::ExifData& exifData = image->exifData();
    qDebug()<<"progress3";
    auto exifWidth = exifData.findKey(Exiv2::ExifKey("Exif.Image.ImageWidth"));
    qDebug()<<"progress4";
    //qDebug()<<exifWidth;
    auto exifWidth2 = exifWidth->key(); //Breaks here.
    //exifWidth2.element_type;
    //QString strWidth = exifWidth2.toString();
    qDebug()<<exifWidth2;
    return true;
}
