#include <cstdlib>
#include "TADlinkeddeque.hpp"
#include <iostream>
#include <vector>
#include <fstream>


using namespace std;

/*
 * 
 */
int main() {

    
    LinkedDeque <string> *linked=new LinkedDeque<string>();
    int option,seeMenu(),ele;
    do{
        seeMenu();
        cin >> option;

        switch(option){
            
        
        case 1:
        {
            string nom, doc;
            string prioritat;
            
            ifstream dades("dades.txt");
            if(dades.is_open()){
                while (!dades.eof()){
                    cout<<nom+" "+prioritat+" "+doc<<endl;
                }
            }
            
            dades.close();
            break;
        }    
        case 2:
            linked->deleteFront();
            break;
            
        case 3:
            linked->deleteRear();
            break;
                   
        case 4:
        {
            ofstream dades;
            dades.open("dades.txt");
            string nom, doc;
            string prioritat;
            string impresio="";
            int cn,n;
            
            cout<<"Quantes entrades vols introduir"<<endl;
            cin>>n;
            
            do{
                    cin>>nom;
                    cin>>prioritat;
                    cin>>doc;
                    impresio=nom+" "+prioritat+" "+doc;
                    if(prioritat=="1"){
                        linked->insertFront(impresio);
                    }else{
                        linked->insertRear(impresio);
                    }
                    ++cn;
            }while(cn!=n);            

            dades.close();
            break;
        }
        case 5:
            linked->print();   
            break;
         
        case 6:
            cout<<"Fins aviat!"<<endl;
            break;
        
        }
            
    } while (option!=6);
    
return 0;
}

int seeMenu(){
     
    int option,i;
    
string opt []={ "Introduir dades", "Eliminar per davant","Eliminar pel final","Entrades","Imprimir contingut","Sortir" };
vector <string> arr_options (opt, opt+5);
     
    
    //Si marca error, fallo tipic Netbeans.
    
    for (i=0;i<arr_options.size();++i){
        
        cout << i+1 << "." << arr_options[i] << endl;
    
}
    return 0;
}