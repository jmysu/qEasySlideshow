#ifndef DISPLAYLABEL_H
#define DISPLAYLABEL_H

#include <QLabel>
#include <QPixmap>
#include <QDebug>
#include <QMouseEvent>
#include <QMenu>
#include <QDesktopServices>

#include "globals.h"
#include "settingsmanager.h"
#include "detailsdialog.h"
#include "slideshowimage.h"

class DisplayLabel : public QLabel
{
    Q_OBJECT
public:
    explicit DisplayLabel(QWidget *parent = nullptr);
    void clearImage(void);
    void displayImage();
    void setImage(const SlideshowImage* slideshowimage);

    void resizeEvent(QResizeEvent *) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;
    void setBackgroundColor(QColor backgroundColor);
protected:
    void contextMenuEvent(QContextMenuEvent *event) override;
private:
    QPixmap _image;
    QColor _backgroundColor;
    const SlideshowImage* _slideshowimage;

    void openFolder(bool ignoreSettings);
    void openImage(void);
signals:
    void rightMouseSucces(bool result);
    void openDetails(const SlideshowImage* image);
    void doubleClicked(void);
};

#endif // DISPLAYLABEL_H
