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
    
    int CantMov = 0; //la cantidad de movimientos
    int PromVestidos = Sum / size; //este es el valor que todos los demas deben de tener
    int Max = 0;
    int mult = 1;
    
    if(Sum % size != 0 ){//aqui no se puede hacer el intercambio
        CantMov = -1;
        
    }else{//aqui puedes hacer el intercambio
        
        //aqui consigues el valor maximo
        for(int i = 0; i< size; i++){
            if(Array[i] > Max){
                Max = Array[i];
            }
            
            //aqui la cantidad de movimientos
            if(Array[i] < PromVestidos){
                CantMov++;
            }
            
            Array[i] = PromVestidos;
        }
        
        /*
         falta cuando es par restarle menos dos
         */
        if(Max == 0){
            CantMov = 0;
        }else if(Max == size){
            CantMov = size -1;
        }else if(Max % 2 != 0)
            CantMov++;
        
        while( Max / 10 != 0){
                mult = Max / 10;
                mult =  Max / mult;
                Max = Max / 10;
                CantMov = CantMov * mult;
        }
    }
    
    cout << CantMov << endl;
    
    return 0;
}
