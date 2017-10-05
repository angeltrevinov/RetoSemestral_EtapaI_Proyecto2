/*
 Angel Odiel Treviño Villanueva
 A01336559
 Estructura de Datos
 Reto Semestral
 Etapa I
 Reto Super Washing Machines
 */

/*
    NOTE: En leetcode tienes que cambiarlo a vectores porque lo pusieron adentro de una clase
 */

#include <iostream>

using namespace std;

int main() {
    
    int size;// numero de lavadoras
    cin >> size;

    int Array[size];//el array de lavadoras
    
    int Sum = 0; //suma total de prendas
    
    //aqui llena el Array con el numero de prendas en la lavadora
    for(int i = 0; i < size; i++){
        cin >> Array[i];
        Sum = Sum + Array[i];
    }
    
    int NumCu = 0, Mayor = Array[0];//Numero de prendas en cada lavadora, El mayor
    int CantMov = 0, NumMenos = 0;// Cantidad de movimientos, Todos los otros numeros
    
    NumCu = Sum / size;
    
    if(NumCu >= 1){
        //solo si se puede mover y tener todos iguales
        for(int i = 0; i < size; i++){
            
            if(Array[i] > Mayor){
                Mayor = Array[i];
                Array[i] = 0;
            }
            
            NumMenos = NumMenos + Array[i];
        }
        
        CantMov = Mayor - NumMenos -1; //La cantidad de movimientos es el numero mayor - todo lo demas -1
        
    }else{
        CantMov = -1;
    }
    
    for(int i = 0; i < size; i++){
        Array[i] = NumCu;
    }
    cout << CantMov << endl;
    
    return 0;
}
