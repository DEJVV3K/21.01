#include <iostream>
#include <fstream>

using namespace std;

const int o = 100;

bool sprCzySzescian(int number) {
    int szescian = 0;
    for (int i = 0; i < number / 2 && number >= szescian; i++) {
        szescian = i * i * i;
        if(number == szescian) {
            return true;
        }
    }
    return false;
}

int main() {
    ifstream wej("ciagi.txt");
    ofstream wyj("wynik.txt");

    bool szescian1;
    bool szescian2;
    int ciag[1000];
    int szescianCiag[100];
    int ilearytm = 0;
    int maxroznica = 0;
    int usunZero = 0;
    for(int q = 0; q < o; q++)
    {
        int dlugosc;
        wej >> dlugosc;
        for(int i = 0; i < dlugosc; i++) {
            szescian1 = false;
            wej >> ciag[i];
            szescian1 = sprCzySzescian(ciag[i]);
            if(szescian1 == true) {
            	usunZero++;
                szescianCiag[usunZero] = ciag[i];
                szescian2 = true;
            }
        }
        szescian2 = false;
    }
    for(int i = 0; i < usunZero; i++) {
        wyj << szescianCiag[i] << endl;
    }
    
	wej.close();
	wyj.close();
    
    return 0;
}
