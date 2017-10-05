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
    
    double NumCu = 0;//Numero de prendas en cada lavadora
    int Mayor = Array[0];// El mayor
    int CantMov = 0;// Cantidad de movimientos
    
    NumCu = Sum / size;
    
    for(int i = 0; i < size; i++){
        //para encontrar el mayor
        if(Array[i] > Mayor){
            Mayor = Array[i];
        }
        
        //numero de movimientos
        if(Array[i] < NumCu){
            CantMov++;
        }
        Array[i] = NumCu;
    }
    
    if(NumCu > 1){
        if(Mayor % 2 != 0){
            CantMov++;
        }
        
    }else if(NumCu == 1){
        CantMov = Mayor -1;
        
    }else if(Mayor == 0){
        CantMov = 0;
    }else
        CantMov = -1;
    
    cout << CantMov << endl;
    
    return 0;
}
