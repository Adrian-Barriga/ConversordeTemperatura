#include "conversor.h"
#include "ui_conversor.h"

Conversor::Conversor(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Conversor)
{
    ui->setupUi(this);

    /*Realizamos todas las conecciones necesarias
    Para lograr que convertir la temperatura en lo deseado*/

    connect(ui->dialcent, SIGNAL(valueChanged(int)),
            this, SLOT(cent2fahr(int)));

    connect(ui->dialfahr, SIGNAL(valueChanged(int)),
            this, SLOT(fahr2cent(int)));

    connect(ui->dialkel, SIGNAL(valueChanged(int)),
            this, SLOT(kel2fahr(int)));

    connect(ui->dialfahr, SIGNAL(valueChanged(int)),
            this, SLOT(fahr2kel(int)));

    connect(ui->dialcent, SIGNAL(valueChanged(int)),
            this, SLOT(cent2kel(int)));

    connect(ui->dialkel, SIGNAL(valueChanged(int)),
            this, SLOT(kel2cent(int)));
}

Conversor::~Conversor()
{
    delete ui;
}

void Conversor::cent2fahr(int grados)
{
    if (ui->dialcent->hasFocus()){
        int f = (grados * 9.0/5 +32);
        ui->dialfahr->setValue(f);
    }

}

void Conversor::fahr2cent(int grados)
{
    if (ui->dialfahr->hasFocus()){
        int c = (grados - 32) - 5.0/9;
        ui->dialcent->setValue(c);
    }
}

void Conversor::cent2kel(int grados)
{
    if (ui->dialcent->hasFocus()){
        int k = (grados + 273) ;
        ui->dialkel->setValue(k);
    }
}

void Conversor::fahr2kel(int grados)
{
    if (ui->dialfahr->hasFocus()){
        int k = (grados - 32) * 5.0/9 +273;
        ui->dialkel->setValue(k);
    }
}

void Conversor::kel2fahr(int grados)
{
    if (ui->dialkel->hasFocus()){
        int f = (grados - 273) * 9/5.0 + 32;
        ui->dialfahr->setValue(f);
    }
}

void Conversor::kel2cent(int grados)
{
    if (ui->dialkel->hasFocus()){
        int c = (grados - 273);
        ui->dialcent->setValue(c);
    }
}

