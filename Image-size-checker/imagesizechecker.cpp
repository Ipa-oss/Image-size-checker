#include "imagesizechecker.h"
#include "ui_imagesizechecker.h"
#include <QFile>
#include <QDebug>
#include <QFileInfo>
#include <libexif/exif-data.h>
#include <libexif/exif-loader.h>
#include <iostream>

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
    ExifData* ED;
    ExifLoader* EL;
    EL = exif_loader_new();
    qDebug()<<"progress1";
    QByteArray stringBA = path.toLocal8Bit();
    const char* stdPath = stringBA.data();
    qDebug()<<"progress2";
    exif_loader_write_file(EL,stdPath);
    ED = exif_loader_get_data(EL);
    qDebug()<<"progress3";
    //ED = exif_data_new_from_file(stdChar);
    //exif_data_load_data(ED,);
    //exif_data_dump(ED);
    ExifEntry* EE;
    qDebug()<<"progress3.1";
    EE = exif_data_get_entry(ED,ExifTag::EXIF_TAG_IMAGE_WIDTH); //This line breaks the code, no clue why.
    qDebug()<<"progress3.2";
    exif_entry_dump(EE,1);
    qDebug()<<"progress4";
    return true;
}
