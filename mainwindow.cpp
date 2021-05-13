#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <stdlib.h>
#include<QMessageBox>

#include<Vehiculo.h>
#include<almacen.h>


using namespace std;
Almacen almacen;

int aleat(){
    return rand()%(10-1);
}

char letrasAleatorias(){

    char letras[21] = {'B','C','D','F','G','H','J','K','L','M','N','P','Q','R','S','T','V','W','X','Y','Z'};

    return letras[rand()%(22-1)];
}

string calcularMatricula(){

    string matricula;

    for(int i = 0; i < 4; i++){
        matricula.append(to_string(aleat()));
    }

    for(int i = 0; i < 3; i++){

        string buff(1,letrasAleatorias());
        matricula.append(buff);
    }
    return matricula;
}

bool verError(Vehiculo a){

    if (a.getBocinas()&&a.getBurbuja()&&a.getPortavasos()) {
        return true;
    }else if (!a.getBocinas()&&!a.getBurbuja()&&!a.getPortavasos()) {
        return true;
    }else {
     return false;
    }

}
bool comprobarMatricula(string m){

    vector<Vehiculo> vehiculos = almacen.getTotalCoches();
    int tamanho =vehiculos.size();
    for (int i = 0;i < tamanho;i++) {
        if(vehiculos[i].getMatricula()==m){
            return false;
        }
    }
    return true;

}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     ui->CaballosNum->display(75);
}

MainWindow::~MainWindow()
{
    delete ui;
}
//void MainWindow::on_CaballosSlider_sliderMoved(int position)
//{
  //  ui->CaballosNum->display(position);
//}
void MainWindow::on_pushButton_clicked()
{

    string nombre = ui->lineEdit->text().toStdString();
    string color="",combustible,matricula;
    bool rueda,kit,burbujas,bocina,portavasos;

    cout<<"HOLA "<< nombre << endl;
    int ruedas,caballos;
    if(ui->radioButton->isChecked()){
        ruedas=2;

    }
    if(ui->radioButton_2->isChecked()){
        ruedas=3;

    }

    if(ui->radioButton_3->isChecked()){
        ruedas=4;

    }
    caballos = ui->CaballosSlider->value();

    if(ui->AzulBut->isChecked()){
        color="azul";
    }
    if(ui->verdeBut->isChecked()){
        color="verde";
    }
    if(ui->AmarilloBut->isChecked()){
        color="amarillo";
    }

    if(ui->rojoButton->isChecked()){
        color="rojo";
    }


    if(ui->GasolinaButton->isChecked()){
        combustible="Gasolina";
    }
    if(ui->DieselButton->isChecked()){
        combustible="Diesel";
    }


    if(ui->Ruedabut->isChecked()){

        rueda=true;
    }else{
        rueda=false;
    }
    if(ui->kitBut->isChecked()){

        kit=true;
    }else{
        kit=false;
    }



    if (ui->checkBox->checkState()) {
        burbujas=true;

    }else{
        burbujas=false;
    }

    if (ui->checkBox_2->checkState()) {
        bocina=true;

    }else{
        bocina=false;
    }


    if (ui->checkBox_3->checkState()) {
        portavasos=true;

    }else{
        portavasos=false;
    }

    matricula = ui->MatriculaLabel->text().toStdString();

    Vehiculo vehiculoNuevo(nombre,ruedas,caballos,combustible,color,rueda,kit,burbujas,bocina,portavasos,matricula);




    if(color==""){
        QMessageBox msgBox;
        msgBox.setWindowTitle("ERROR");
        msgBox.setText("Seleccione un color");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    }else if(vehiculoNuevo.getNombre() == ""){
        QMessageBox msgBox;
        msgBox.setWindowTitle("ERROR");
        msgBox.setText("Seleccione un nombre para el vehiculo");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    }else if(vehiculoNuevo.getMatricula()== ""){
        QMessageBox msgBox;
        msgBox.setWindowTitle("ERROR");
        msgBox.setText("Usa el boton de Generar matricula");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    }else if(!verError(vehiculoNuevo)){
        QMessageBox msgBox;
        msgBox.setWindowTitle("ERROR");
        msgBox.setText("Error de configuracion");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    }else if(!comprobarMatricula(vehiculoNuevo.getMatricula())){
        QMessageBox msgBox;
        msgBox.setWindowTitle("ERROR");
        msgBox.setText("MATRICULA REPETIDA, GENERE OTRA");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    }else{
        almacen.nuevoVehiculo(vehiculoNuevo);
        ui->listWidget->addItem(QString::fromStdString(vehiculoNuevo.toString()));
    }
}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    ui->listWidget_2->clear();
    string r = item->text().toStdString();

    vector<Vehiculo> coches = almacen.getTotalCoches();

    istringstream split(r);
    vector<string> results((istream_iterator<string>(split)),
                           istream_iterator<string>());


    if(results[2] == "de"){ //Solucion para imprimir el coche de homer, ya que la matricula no esta en la pos 2
        results[2] = results[4];
    }



    for(int i = 0; i < coches.size(); i++){

        if(!coches[i].getMatricula().compare(results[2])){
            Vehiculo c(coches[i]);


            ui->ltipo->setText(QString::fromStdString(c.getTipoVehiculo()));
            ui->lnombre->setText(QString::fromStdString(c.getNombre()));
            ui->lruedas->setNum(c.getRuedas());
            ui->lcaballos->setNum(c.getCaballos());
            ui->itipocom->setText(QString::fromStdString(c.getCombustible()));
            ui->lcolor->setText(QString::fromStdString(c.getColor()));
            ui->lmatricula->setText(QString::fromStdString(c.getMatricula()));
            ui->listWidget_2->addItem(QString::fromStdString(c.getExtra()));

            if(c.getBurbuja()){
                ui->listWidget_2->addItem("Burbuja para niños");
            }

            if(c.getBocinas()){
                ui->listWidget_2->addItem("Multiples bocinas");
            }

            if(c.getPortavasos()){
                ui->listWidget_2->addItem("Posavasos gigante");
            }
        }
    }
}

void MainWindow::on_MatriculaBut_clicked()
{

    ui->MatriculaLabel->setText(QString::fromStdString(calcularMatricula()));
}
