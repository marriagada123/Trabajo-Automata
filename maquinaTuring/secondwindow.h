#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include <QStringList>

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = 0);
    ~SecondWindow();

private slots:
    void on_pushButton_Confirmar_clicked();

    void on_pushButton_inserta_clicked();

private:
    Ui::SecondWindow *ui;
    int fila;
    bool transCorrecta;
    bool tablaGenerada;
    int numeroEstado;
    int estadoInicial;
    int estadoFinal;
    QString header;
    QStringList header2;
};

#endif // SECONDWINDOW_H
