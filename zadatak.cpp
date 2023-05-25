
#include <iostream>
#include <thread>
#include <chrono>

//globalne varijable stanja
//pocetno su sva stanja upaljena
bool s_a = 1;
bool s_b = 1;
bool s_c = 1;

//ispisuje trenutna stanja za A, B, C svakih 5s
void current_state(){
    while (true){
        bool states[3] = {s_a, s_b, s_c};
        for(int i = 0; i<3;i++){
            char symb = 65 + i;
            
            if(states[i]==1){
                std::cout << symb << " upaljen" << std::endl;
            }

            else{
                std::cout << symb << " ugasen" << std::endl;
            }
            
        }
        std::cout << "---------------------" << std::endl;
        //cekamo 5s za ponovni ispis trenutnog stanja (za pregledniji ispis promjeniti na 2000ms)
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));

    }
    
}


int main(){
    //definiramo varijablu u koju upisujemo stanje
    char state;
    //definiramo thread i pokrecemo ga
    auto exec_current = [](){current_state();};
    std::thread t(exec_current);
    t.detach();

    while(true){
        //std::cout << "Ugasiti stanje ";
        //upis stanja kojeg gasimo
        std::cin >> state;
        std::cout << "Gasenje " << state << std::endl;
        std::cout << "---------------------" << std::endl;

        //ako upisano stanje A
        if(state=='A'){
            s_a = 0;
            s_b = 1;
            s_c = 1;

            //cekamo 2s izmedu paljenja/gasenja stanja
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));

            s_a = 0;
            s_b = 0;
            s_c = 1;

            std::this_thread::sleep_for(std::chrono::milliseconds(2000));

            s_a = 0;
            s_b = 0;
            s_c = 0;

            std::this_thread::sleep_for(std::chrono::milliseconds(2000));

            s_a = 1;
            s_b = 0;
            s_c = 0;

            
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));

            s_a = 1;
            s_b = 1;
            s_c = 0;

            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        }

        //ako upisano stanje B
        else if(state=='B'){
            s_a = 1;
            s_b = 0;
            s_c = 1;

            std::this_thread::sleep_for(std::chrono::milliseconds(2000));

            s_a = 1;
            s_b = 0;
            s_c = 0;

            std::this_thread::sleep_for(std::chrono::milliseconds(2000));

            s_a = 1;
            s_b = 1;
            s_c = 0;

            std::this_thread::sleep_for(std::chrono::milliseconds(2000));

        }
        else if(state=='C'){
            s_a = 1;
            s_b = 1;
            s_c = 0;

            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        }

        s_a = 1;
        s_b = 1;
        s_c = 1;

    }

}