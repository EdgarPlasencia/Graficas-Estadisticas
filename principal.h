#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();

public slots:


private slots:
    void on_actionGuardar_triggered();


    void on_bmtPromediar_released();

private:
    Ui::Principal *ui;
    QPixmap lienzo;

    void dibujar(QPixmap &lienzo);
    //Dibujar regla de referencia
    void regla(QPixmap &lienzo);
};
#endif // PRINCIPAL_H
