//se importan todas las librerias que se requieren
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//se declaran las funciones
double matrix_product(double matrix1, double matrix2, int filas1, int columnas1, int filas2, int columnas2);
double get_matrix();
//se crea la funcion main
int main (){
  //se crean las vairables filas
  int filas1;
  int filas2;
  //se crean las vairables columnas
  int columnas1;
  int columnas2;
  //imprime en consola
  cout<<"ingrese el numero de filas de la matriz1: "<<endl;
  //guarda lo que el usuario escribio en la consola en la variable filas1
  cin>>filas1;
  cout<<"ingrese el numero de columnas de la matriz1: "<<endl;
  //guarda lo que el usuario escribio en la consola en la variable columnas1
  cin>>columnas1;
  cout<<"las dimensiones de su matriz1 son "<< filas1 <<" "<<columnas1<<endl;
  //imprime en consola
  cout<<"ingrese el numero de filas de la matriz2: "<<endl;
  //guarda lo que el usuario escribio en la consola en la variable filas2
  cin>>filas2;
  cout<<"ingrese el numero de columnas de la matriz2: "<<endl;
  //guarda lo que el usuario escribio en la consola en la variable columnas2
  cin>>columnas2;
  cout<<"las dimensiones de su matriz2 son "<< filas2 <<" "<<columnas2<<endl;
  //llama al metodo get_matrix
  double** matrix1= get_matrix(int filas1,int columnas1);
  double** matrix2= get_matrix(int filas2,int columnas2);
  //imprime las matrices
  cout<<"la matriz1 es: "<<matrix1<<endl;
  cout<<"la matriz2 es: "<<matrix2<<endl;
  //imprime el producto de matrix1 y matrix2 y llama al metodo de matrix_product
  double** matrix_product=matrix_product(double matrix1, double matrix2, int filas1, int columnas1, int filas2, int columnas2);
  cout<<"el producto de matriz1 y matriz2 es: "<<matrix_product<<endl;
}
//metodos
double matrix_product(double matrix1, double matrix2, int filas1, int columnas1, int filas2, int columnas2){
  //crea la matriz resultado
  //crea una matriz de vectores como un puntero. Parametro:numero de filas
  double** resultado = new double*[filas1];
  //ciclo que llena la matriz con vectores vacios
  for(int i=0;i<filas1;i++){
    resultado[i]=new double[columnas2];
  }
  //verifica si las dimensiones son correctas
  if(columnas1!=filas2){
    //retorna mensaje de error
    cout<<"no se pueden multiplicar las matrices, las dimensiones no son validas"<<endl;
    return 1;
  }
  //si las dimensiones son correctas hace la multiplicacion
  else{
    double temp;
    for(int i=0;i<filas1;i++){
      for(int j=0;j<columnas2;j++){
        for(int k=0;k<columnas1;k++){
          temp+=matrix1[i][k]*matrix2[k][j];

        }
        resultado[i][j]=temp;
        temp=0;
      }
    }
  }
}
double get_matrix(int filas,int columnas){
  //crea una matriz de vectores como un puntero. Parametro:numero de filas
  double** matrix = new double*[filas];
  //ciclo que llena la matriz con vectores vacios
  for(int i=0;i<filas;i++){
    matrix[i]=new double[columnas];
  }
  //ciclo que llena cada espacio de la matriz
  for(int i=0;i<filas;i++){
    for(int j=0;j<columnas;j++){
        double temp;
        cout<<"ingrese el elemento "<<i<<","<<j<<endl;
        cin>> temp;
        matrix[i][j]=temp;
    }
  }
  return matrix;
}
