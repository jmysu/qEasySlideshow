#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QDebug>
#include <QFontDatabase>
#include <QSettings>
#include <QVariant>
#include <QThread>
#include <QSizeGrip>
#include <QScreen>
#include <QDrag>
#include <QMimeData>
#include <QPaintEngine>
#include <QLabel>

#include "globals.h"
#include "settingsmanager.h"
#include "slideshow.h"
#include "settingsdialog.h"
#include "helpdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void resizeEvent(QResizeEvent *);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    Ui::MainWindow *ui;

    QDialog *_settingsDialog;
    bool _settingsShown;

    QDialog *_helpDialog;
    bool _helpShown;
    const SlideshowImage* _slideshowimage;

    SlideShow *_slideshow;
    QTranslator *_currentTranslator;
    QString _currentLanguage;
    QPixmap *current_image;
    QPixmap *current_image_scaled;

    int _mouseClickCoordinate[2];

    bool _details_enabled;

    void loadSettings(void);
    void saveSettings(void);
    void controls(bool enable);
    void displayDetails(bool enable);

    QPoint dragStartPosition;

public slots:
    void displayError(QString msg);
    void updateImage(const SlideshowImage* image);
    void updateImageCursor(void);

    void settingsClosed(bool accepted);
    void helpClosed(void);
    void changeLanguage(QString lang);

    void startedSlideshowInit(void);
    void stoppedSlideshowInit(void);
    void lockButtonClicked(void);
    void updatePauseButton(void);

    void processRightClick(bool status);
    void imageDoubleClicked(void);

    void toggleDetails(const SlideshowImage* image);
    void updateDetails(const SlideshowImage* image) const;

private slots:
    void on_nextButton_clicked(void);
    void on_previousButton_clicked(void);
    void on_settingsButton_clicked();
    void on_helpButton_clicked();
    void on_pauseButton_clicked(void);

    void on_closeButton_clicked();

signals:
    void pauseClicked(void);
    void nextImageClicked(void);
    void previousImageClicked(void);

protected:
    bool eventFilter(QObject *watched, QEvent *event);protected:
};

#endif // MAINWINDOW_H
