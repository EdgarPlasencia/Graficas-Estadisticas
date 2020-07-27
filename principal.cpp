#include "principal.h"
#include "ui_principal.h"

#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <QFont>
#include <QString>

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{

    ui->setupUi(this);
    lienzo = QPixmap(500,500);
    lienzo.fill(Qt::white);

    ui->inNota1->setValue(70);
    ui->inNota2->setValue(70);
    ui->inNota3->setValue(70);

    this->dibujar(lienzo);
    this->regla(lienzo);

    ui->outCuadro->setPixmap(lienzo);






}

Principal::~Principal()
{
    delete ui;
}

void Principal::dibujar(QPixmap &lienzo)
{
    //Mayor de todos
    float referencia;
    float nota1ref=ui->inNota1->value();
    float nota2ref=ui->inNota2->value();
    float nota3ref=ui->inNota3->value();

    //referencia=(nota1ref+nota2ref+nota3ref)/3;

    if(nota1ref>=nota2ref&&nota1ref>=nota3ref){
        referencia=nota1ref;
    }else if(nota2ref>nota3ref){
        referencia=nota2ref;
    }else{
        referencia=nota3ref;
    }

    QFont font = ui->outPromedio->font();
    font.setPointSize(12);
    font.setBold(true);
    ui->outPromedio->setFont(font);

    //Cacular Promedio
    float promedio=ui->inNota1->value()+ui->inNota2->value()+ui->inNota3->value();
    float mostrarprom=promedio/3;

    QString strProm = QString::number(mostrarprom,'f',2);

    ui->outPromedio->setText(strProm);

    //CREAR COLORES DE RELLENO
    QColor rellenoAzul(Qt::blue);
    QColor rellenoRojo(Qt::red);
    QColor rellenoAmarillo(Qt::yellow);
    QColor rellenoBlanco(Qt::white);
    QColor rellenoNegro(Qt::black);

    //PAINTER NOTA 1

    QPainter painterNota1(&lienzo);

    //PINCEL NOTA 1
    QPen pincelNota1;


    //ELEGIR COLOR LINEA
    int indexLinea=ui->colorLinea1->currentIndex();
    switch (indexLinea) {
    case 0:
        pincelNota1.setColor(Qt::blue);
        break;
    case 1:
        pincelNota1.setColor(Qt::red);
        break;
    case 2:
        pincelNota1.setColor(Qt::yellow);
        break;
    case 3:
        pincelNota1.setColor(Qt::white);
        break;
    case 4:
        pincelNota1.setColor(Qt::black);
        break;

    }

    //ELEGIR GROSOR DE LINEA NOTA 1

    int indexTam=ui->tamLinea1->currentIndex();
    switch (indexTam) {
    case 0:
        pincelNota1.setWidth(2);
        break;
    case 1:
        pincelNota1.setWidth(4);
        break;
    case 2:
        pincelNota1.setWidth(6);
        break;
    case 3:
        pincelNota1.setWidth(8);
        break;
    case 4:
        pincelNota1.setWidth(10);
        break;

    }


    pincelNota1.setJoinStyle(Qt::MiterJoin);


    //COORDENADAS NOTA 1

    int xNota1=100;
    int nota1= ui->inNota1->value();
    int href1=(nota1*100)/referencia;
    int hNota1=(href1*400)/100;

    int yNota1=(100-href1)*4;

    //ESTABLECER PINCEL AL PINTOR NOTA 1
    painterNota1.setPen(pincelNota1);


    // Establecer el color de relleno 1

    int indexRell=ui->relleno1->currentIndex();
    switch (indexRell) {
    case 0:
        painterNota1.setBrush(rellenoAzul);
        break;
    case 1:
        painterNota1.setBrush(rellenoRojo);
        break;
    case 2:
        painterNota1.setBrush(rellenoAmarillo);
        break;
    case 3:
        painterNota1.setBrush(rellenoBlanco);
        break;
    case 4:
        painterNota1.setBrush(rellenoNegro);
        break;

    }

    // Dibujar primera barra
    if(nota1ref>=nota2ref&&nota1ref>=nota3ref){
    painterNota1.drawRect(xNota1,50,100,400);
    }else{
    painterNota1.drawRect(xNota1,50+yNota1,100,hNota1);
    }

    //CREAR PINCEL PARA NOTA 2

    QPen pincelNota2;

    //GROSOR NOTA 2
    indexTam=ui->tamLinea2->currentIndex();
        switch (indexTam) {
        case 0:
            pincelNota2.setWidth(2);
            break;
        case 1:
            pincelNota2.setWidth(4);
            break;
        case 2:
            pincelNota2.setWidth(6);
            break;
        case 3:
            pincelNota2.setWidth(8);
            break;
        case 4:
            pincelNota2.setWidth(10);
            break;

        }


    pincelNota2.setJoinStyle(Qt::MiterJoin);

    indexLinea=ui->colorLinea2->currentIndex();
    switch (indexLinea) {
    case 0:
        pincelNota2.setColor(Qt::blue);
        break;
    case 1:
        pincelNota2.setColor(Qt::red);
        break;
    case 2:
        pincelNota2.setColor(Qt::yellow);
        break;
    case 3:
        pincelNota2.setColor(Qt::white);
        break;
    case 4:
        pincelNota2.setColor(Qt::black);
        break;

    }

    // Establecer el color al brush (relleno)

    indexRell=ui->relleno2->currentIndex();
        switch (indexRell) {
        case 0:
            painterNota1.setBrush(rellenoAzul);
            break;
        case 1:
            painterNota1.setBrush(rellenoRojo);
            break;
        case 2:
            painterNota1.setBrush(rellenoAmarillo);
            break;
        case 3:
            painterNota1.setBrush(rellenoBlanco);
            break;
        case 4:
            painterNota1.setBrush(rellenoNegro);
            break;

        }

    //ESTABLECER PINCLEL DE LA NOTA 2 AL PINTOR
    painterNota1.setPen(pincelNota2);



    //COORDENADAS NOTA 2
    int xNota2=220;
    int nota2= ui->inNota2->value();
    int href2=(nota2*100)/referencia;
    int hNota2= (href2*400)/100;
    int yNota2=(100-href2)*4;

    // Dibujar segunda barra


    if(nota2ref>=nota1ref&&nota2ref>=nota3ref){
    painterNota1.drawRect(xNota2,50,100,400);
    }else{
    painterNota1.drawRect(xNota2, 50+yNota2, 100, hNota2);
    }


    //CREAR PINCEL PARA NOTA 3

    QPen pincelNota3;

    //GROSOR NOTA 3
    indexTam=ui->tamLinea3->currentIndex();
        switch (indexTam) {
        case 0:
            pincelNota3.setWidth(2);
            break;
        case 1:
            pincelNota3.setWidth(4);
            break;
        case 2:
            pincelNota3.setWidth(6);
            break;
        case 3:
            pincelNota3.setWidth(8);
            break;
        case 4:
            pincelNota3.setWidth(10);
            break;

        }

    pincelNota3.setJoinStyle(Qt::MiterJoin);

    indexLinea=ui->colorLinea3->currentIndex();
    switch (indexLinea) {
    case 0:
        pincelNota3.setColor(Qt::blue);
        break;
    case 1:
        pincelNota3.setColor(Qt::red);
        break;
    case 2:
        pincelNota3.setColor(Qt::yellow);
        break;
    case 3:
        pincelNota3.setColor(Qt::white);
        break;
    case 4:
        pincelNota3.setColor(Qt::black);
        break;

    }

    //ESTABLECER PINCLEL DE LA NOTA 3 AL PINTOR
    painterNota1.setPen(pincelNota3);


    // Establecer el color al brush (relleno)

    indexRell=ui->relleno3->currentIndex();
        switch (indexRell) {
        case 0:
            painterNota1.setBrush(rellenoAzul);
            break;
        case 1:
            painterNota1.setBrush(rellenoRojo);
            break;
        case 2:
            painterNota1.setBrush(rellenoAmarillo);
            break;
        case 3:
            painterNota1.setBrush(rellenoBlanco);
            break;
        case 4:
            painterNota1.setBrush(rellenoNegro);
            break;

        }



    //COORDENADAS NOTA 3
    int xNota3=340;
    int nota3= ui->inNota3->value();
    int href3= (nota3*100)/referencia;
    int hNota3= (href3*400)/100;
    int yNota3=(100-href3)*4;

    // Dibujar tercera barra
    if(nota3ref>=nota2ref&&nota3ref>=nota1ref){
    painterNota1.drawRect(xNota3,50,100,400);
    }else{
    painterNota1.drawRect(xNota3, 50+yNota3, 100, hNota3);
    }



}

void Principal::regla(QPixmap &lienzo)
{
    QPainter painter(&lienzo);

    QPen pincel;
    pincel.setWidth(2);


    painter.setPen(pincel);

    painter.drawText(130,470,"Nota1");
    painter.drawText(250,470,"Nota2");
    painter.drawText(370,470,"Nota3");

    float mostrarprom;

    //promedio=ui->inNota1->value()+ui->inNota2->value()+ui->inNota3->value();
    float nota1ref=ui->inNota1->value();
    float nota2ref=ui->inNota2->value();
    float nota3ref=ui->inNota3->value();

    if(nota1ref>=nota2ref&&nota1ref>=nota3ref){
        mostrarprom=nota1ref;
    }else if(nota2ref>nota3ref){
        mostrarprom=nota2ref;
    }else{
        mostrarprom=nota3ref;
    }

    float regla=mostrarprom/10;


    QString strProm;


    for(int i=50;i<=450;i++){
        strProm = QString::number(mostrarprom,'f',2);
        painter.drawText(1,i,strProm);
        mostrarprom=mostrarprom-regla;
        i=i+39;
    }


    for(int i=50;i<=450;i++){

        painter.drawLine(40,i,60,i);
        i=i+39;
    }


    painter.drawLine(50,50,50,450);
    painter.drawLine(50,450,450,450);

}


void Principal::on_actionGuardar_triggered()
{
    QString nombreArchivo = QFileDialog::getSaveFileName(
                this,"Guardar imagen",QString(),"Imagenes (*.png)");
    if (!nombreArchivo.isEmpty()){
        if (lienzo.save(nombreArchivo))
            QMessageBox::information(this,"Guardar imagen","Archivo guarado en: " + nombreArchivo);
        else
            QMessageBox::warning(this,"Guardar imagen","No se pudo guardar el archivo");
    }
}




void Principal::on_bmtPromediar_released()
{
    lienzo = QPixmap(500,500);
    lienzo.fill(Qt::white);
    regla(lienzo);
    dibujar(lienzo);
     ui->outCuadro->setPixmap(lienzo);


}
