#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSound>

#include "voipc.h"
#include "ui_mainwindow.h"

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QString sipStatus();

public slots:
    void execCommand(const int cmd, const QString &arg);

private slots:
    void dialButtonClicked();
    void callClicked();
    void hangupClicked();
    void muteClicked();
    void voipCStateChanged();
    void checkRegistration();
    void holdClicked();

protected:
    void closeEvent(QCloseEvent* event);

private:
    void initialize();
    void incommingCall();
    void confirmCall();
    void disconnctdCall();
    void setStatus(const QString &status, const QString &styleSheet);
    void sendDtmf(char digit);

    QSound *toneSound;
    QSound *ringSound;

    bool m_incommingCall;
    VoipC voipc;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
