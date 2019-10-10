#ifndef IMAGEPROVIDER_H
#define IMAGEPROVIDER_H
#include <QQuickImageProvider>
#include <QImage>

class ImageProvider : public QObject, public QQuickImageProvider
{
    Q_OBJECT
public:
    static ImageProvider *instance();

    QImage requestImage(const QString &id, QSize *size, const QSize &requestedSize);
    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize);

    QImage m_img;

signals:
    void refreshImage();

public slots:
    bool setImage(const QString &path);
    bool setImage(const uchar *pData, int size);

private:
    ImageProvider();

};

#endif // IMAGEPROVIDER_H
