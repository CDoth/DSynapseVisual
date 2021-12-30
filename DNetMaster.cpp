#include "DNetMaster.h"
#include <QPainter>

DLearnSettingsWidget::DLearnSettingsWidget(QWidget *parent) : DWidget(parent) {

    CREATE_WIDGET
}
void DLearnSettingsWidget::_alloc() {
    combo_activation = new QComboBox(this);
    spinBox_learnRate = new DDoubleSpinBox(this, 1, 3);
    switcher_actout = new DSwitcher(this, 0);

    button_ok = new QPushButton("Ok", this);
    button_cancel = new QPushButton("Cancel", this);
    button_drop = new QPushButton("Drop", this);

    layoutMain = new QVBoxLayout(this);
    layoutBottom = new QHBoxLayout;
    layoutButtons = new QVBoxLayout;
}
void DLearnSettingsWidget::_place() {

    layoutButtons->addWidget(button_ok);
    layoutButtons->addWidget(button_cancel);
    layoutButtons->addWidget(button_drop);
    //---------------------------------------
    layoutBottom->addWidget(switcher_actout);
    layoutBottom->addLayout(layoutButtons);
    //---------------------------------------

    layoutMain->addWidget(spinBox_learnRate);
    layoutMain->addWidget(combo_activation);
    layoutMain->addLayout(layoutBottom);
}
void DLearnSettingsWidget::_init() {

    setRectColor(Qt::black);
    enableRect(true);

    combo_activation->addItem("Sigmoid");
    combo_activation->addItem("Gtan");
    combo_activation->addItem("ReLU");
    combo_activation->addItem("Line");

    spinBox_learnRate->x_setName("Learn rate");

    switcher_actout->x_addPosition("rawout");
    switcher_actout->x_addPosition("actout");

    layoutMain->setSizeConstraint(QLayout::SetFixedSize);
}
void DLearnSettingsWidget::_connect() {

}
void DLearnSettingsWidget::_disconnect() {

}
void DLearnSettingsWidget::_dealloc(){

}
//=========================================================
void DLayerMaster::paintEvent(QPaintEvent *event) {
    QPainter p(this);
    drawMainRect(&p, this->rect());
}
DLayerMaster::DLayerMaster(QWidget *parent) :  DWidget(parent) {

    CREATE_WIDGET
}
void DLayerMaster::_alloc() {

    spinBox_neurons = new DSpinBox(this, 5);
    learnSettings = new DLearnSettingsWidget(this);
    layout_main = new QVBoxLayout(this);
}
void DLayerMaster::_place() {

    layout_main->addWidget(spinBox_neurons);
    layout_main->addWidget(learnSettings);
}
void DLayerMaster::_init() {

    spinBox_neurons->x_setName("Size");

}
void DLayerMaster::_connect() {

}
void DLayerMaster::_disconnect() {

}
void DLayerMaster::_dealloc() {

}
//================================================================================== DNetMaster:
DNetMaster::DNetMaster(QWidget *parent) :  DWidget(parent) {

    CREATE_WIDGET
}
void DNetMaster::_alloc() {

    list_layers = new QListWidget(this);
    layersMaster = new DLayerMaster(this);

    comboBox_plotTarget = new QComboBox(this);
    discretePlot = new DDiscretePlot2(this);


    learnSettings = new DLearnSettingsWidget(this);

    button_learn = new QPushButton("Learn", this);
    button_addLayer = new QPushButton("Add layer", this);
    button_removeLayer = new QPushButton("Remove layer", this);

    layoutPlotBoard = new QVBoxLayout;
    layoutLayersBoard = new QVBoxLayout;
    layoutLearnProcess = new QVBoxLayout;

    layoutTop = new QHBoxLayout;
    layoutBottom = new QHBoxLayout;
    layoutMain = new QVBoxLayout(this);

}
void DNetMaster::_place() {

    layoutPlotBoard->addWidget(comboBox_plotTarget);
    layoutPlotBoard->addWidget(discretePlot);
    //---------------------------------
    layoutLayersBoard->addWidget(button_addLayer);
    layoutLayersBoard->addWidget(button_removeLayer);
    layoutLayersBoard->addWidget(list_layers);
    //---------------------------------
    layoutLearnProcess->addWidget(button_learn);
    layoutLearnProcess->addWidget(learnSettings);
    //---------------------------------
    layoutTop->addLayout(layoutLayersBoard);
    layoutTop->addWidget(layersMaster);
    //---------------------------------
    layoutBottom->addLayout(layoutPlotBoard);
    layoutBottom->addLayout(layoutLearnProcess);
    //---------------------------------
    layoutMain->addLayout(layoutTop);
    layoutMain->addLayout(layoutBottom);
}
void DNetMaster::_init() {
    discretePlot->setMinimumSize(100, 100);
    discretePlot->setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
    //--------------------------------------
    comboBox_plotTarget->addItem("Total error");
    comboBox_plotTarget->addItem("Layer weights");
    //--------------------------------------
    setRectColor(Qt::blue);
}
void DNetMaster::_connect() {

}
void DNetMaster::_disconnect() {

}
void DNetMaster::_dealloc() {

}

