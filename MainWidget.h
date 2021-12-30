#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <DNetMaster.h>
#include <QLabel>
#include "__dsynapseVisual_global.h"
#include <DButtonsBoard.h>

#include "DSVTask_FunctionApproximation.h"
#include <QTextBrowser>


class DSVMainWidget : public DWidget {
    Q_OBJECT
public:
    DSVMainWidget(QWidget *parent = nullptr);
private:
    void _alloc();
    void _place();
    void _init();
    void _connect();
    void _disconnect();
    void _dealloc();

    void addTask(DSVTask_base *t);
private slots:
    void startTask(int);
private:
    //----------------------------------
    DArray<DSVTask_base*> tasks;
    //----------------------------------


    DButtonsBoard *buttonsBoard_tasks;
    DSVTask_base *currentTask;
    DNetMaster *currentNet;
    QTextBrowser *logOutput;

    QGridLayout *layoutMain;

};

#endif // MAINWIDGET_H

