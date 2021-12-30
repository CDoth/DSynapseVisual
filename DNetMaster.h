#ifndef DNETMASTER_H
#define DNETMASTER_H

#include <DWidget.h>
#include <QListWidget>
#include <DSpinBox.h>
#include <QComboBox>
#include <DDoubleSpinBox.h>
#include <DSwitcher.h>
#include <QPushButton>
#include <DLivePlot.h>
#include <DDiscretePlot2.h>


class DLearnSettingsWidget : public DWidget {
    Q_OBJECT
public:
    DLearnSettingsWidget(QWidget *parent = nullptr);
private:
    void _alloc();
    void _place();
    void _init();
    void _connect();
    void _disconnect();
    void _dealloc();
private:
    QComboBox *combo_activation;
    DDoubleSpinBox *spinBox_learnRate;
    DSwitcher *switcher_actout;
    QPushButton *button_ok;
    QPushButton *button_cancel;
    QPushButton *button_drop;

    QVBoxLayout *layoutMain;

    QHBoxLayout *layoutBottom;
    QVBoxLayout *layoutButtons;

};

class DLayerMaster : public DWidget {
    Q_OBJECT
protected:
    void paintEvent(QPaintEvent *event) override;
public:
    DLayerMaster(QWidget *parent = nullptr);
private:
    void _alloc();
    void _place();
    void _init();
    void _connect();
    void _disconnect();
    void _dealloc();
private:
    DSpinBox *spinBox_neurons;
    DLearnSettingsWidget *learnSettings;
    QVBoxLayout *layout_main;
};

class DNetMaster : public DWidget {
    Q_OBJECT
public:
    DNetMaster(QWidget *parent = nullptr);
private:
    void _alloc();
    void _place();
    void _init();
    void _connect();
    void _disconnect();
    void _dealloc();
private:
    QListWidget *list_layers;
    DLayerMaster *layersMaster;

    QComboBox *comboBox_plotTarget;
    DLivePlot *livePlot;
    DDiscretePlot2 *discretePlot;


    DLearnSettingsWidget *learnSettings;

    QPushButton *button_learn;
    QPushButton *button_addLayer;
    QPushButton *button_removeLayer;

    //-----------------------------
    QVBoxLayout *layoutPlotBoard;
    QVBoxLayout *layoutLayersBoard;
    QVBoxLayout *layoutLearnProcess;
    //-----------------------------
    QHBoxLayout *layoutTop;
    QHBoxLayout *layoutBottom;
    QVBoxLayout *layoutMain;





};

#endif // DNETMASTER_H
