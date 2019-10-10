#include "ImageProvider.h"
#include <QFile>

ImageProvider *ImageProvider::instance()
{
    static ImageProvider *p = nullptr;
    if(!p)  p = new ImageProvider();
    return p;
}

ImageProvider::ImageProvider()
    : QQuickImageProvider(QQuickImageProvider::Image)
{

}

bool ImageProvider::setImage(const QString &path)
{
    QString s = QUrl(path).toLocalFile();
    bool b = m_img.load(s);
    emit refreshImage();
    return b;
}

bool ImageProvider::setImage(const uchar *pData, int size)
{
   m_img.loadFromData(pData, size);
   // m_img.load("d:/1.jpg");
    emit refreshImage();
    return true;
}

QImage ImageProvider::requestImage(const QString &id, QSize *size, const QSize &requestedSize)
{
    (void)id;
    (void)size;
    (void)requestedSize;
    return m_img;
}

QPixmap ImageProvider::requestPixmap(const QString &id, QSize *size, const QSize &requestedSize)
{
    (void)id;
    (void)size;
    (void)requestedSize;
    return QPixmap::fromImage(m_img);
}
