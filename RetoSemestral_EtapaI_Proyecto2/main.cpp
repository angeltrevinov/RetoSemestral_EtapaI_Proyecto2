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
#include <vector>

using namespace std;

int main() {
    vector <int> machines;//esto lo quitas en codeleet
    int Size = machines.size();
    vector <int> Sum(Size + 1, 0);//aqui se va a guardar la cantidad que cada lavadora necesita
    int CantMov = 0, Prom = 0;
    
    //aqui suma lo que esta en la posicion anterior en sum y la posicion en machines y lo guarda a lado para saber cuantos necesita
    for(int i = 0; i < Size; i++){
        Sum.at(i + 1) = Sum.at(i) + machines.at(i);
    }
    Prom = Sum.at(Size) / Size;
    if(Sum.at(Size)  % Size){ //entra si no hay suficiente ropa para repartir equitativamente entre las lavadoras
        CantMov = -1;
        
    }else{//aqui entra solo si es posible repartir equitatvamente
        
        Prom = Sum.at(Size) / Size;
        
        for(int i= 0; i < Size; i++){
            int Left = i * Prom - Sum.at(i); //guarda cuanto tienes a la izquierda comparado con el promedio
            int Right = (Size - i - 1) * Prom - (Sum.at(Size) - Sum.at(i) - machines.at(i));//checa cuantos tienes en la derecha comparado con el promedio
            if(Left > 0 && Right > 0)
                CantMov = max(CantMov, abs(Left) + abs(Right));//max saca el valor mas grande entre los dos parametros
            else
                CantMov = max(CantMov, max(abs(Left), abs(Right)));
        }
    }
    
    return CantMov;
}
