#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

bool czydopliku = false;
ofstream wynik;

void wypiszXdrzewa(int n, int t, int *a)
{
    if(czydopliku) wynik << "x="; else cout << "x=";
    int dlugoscx = t*n;
    int j = 0;
    for (int i = 1; i <= dlugoscx; i++){
        if(j<n && a[j]==i){
            if(czydopliku) wynik << "1"; else cout << "1";
            j++;
        }else{
            if(czydopliku) wynik << "0"; else cout << "0";
        }
    }
}

int main()
{
        wynik.open("wynik.txt");
        int n = 0;
        cout << "Program generuje wszystkie mo¿liwe reprezentacje typu Z (w kolejnosci RevLex) drzewa t-narnego o podanych w³aœciwoœciach i zamienia go na zapis w reprezentacji typu X." << endl;
        cout << "Gdzie wypisac wyniki? 1 - na ekran 2 - do pliku" << endl;
        cin >> n;
        if(n==2) czydopliku = true;
        n = 0;
        cout << "n oznacza ilosc rozgalezien. Podaj n: ";
        cin >> n;
        int t = 0;
        cout << "t oznacza ilosc galezi w jednym rozgalezieniu. Podaj t: ";
        cin >> t;

        cout << "Rozpoczynam wypisywanie kolejnych mozliwych drzew t-arnych o podanych danych w reprezentacji X (dodatkowo po spacji podaje zapis w reprezentacji typu Z)" << endl;

        int a[1024];
        a[0] = 1;
        for (int i = 1; i < n; i++) a[i] = a[i-1]+t;
        int ilosc = 0;
        /*cout << ilosc << ". z:";
        for (int i = 0; i < n; i++) cout << a[i];
        cout << endl;*/

        do{
            ilosc++;
            if(czydopliku) wynik << ilosc << ". "; else cout << ilosc << ". ";
            wypiszXdrzewa(n, t, a); //if(czydopliku) wynik << else
            if(czydopliku) wynik << " z:"; else cout << " z:";
            for (int i = 0; i < n; i++){
                    if(czydopliku) wynik << a[i] << " "; else cout << a[i] << " ";
            }
            if(czydopliku) wynik << endl; else cout << endl;
            a[n-1]--;
            for(int i = 1; n-i-1>=0 ; ){
                if( a[n-i] == a[n-i-1] ){
                    a[n-i-1]--;
                    a[n-i] = t*(n-i)+1;
                    i++;
                } else break;
            }
        }while(a[0] == 1); //&& ilosc < 24

        if(czydopliku) wynik << "Ilosc wygenerowanych drzew: " << ilosc << endl; else cout << "Ilosc wygenerowanych drzew: " << ilosc << endl;
        if(czydopliku) wynik << "Ilosc lisci: " << (t-1)*n+1 << endl; else cout << "Ilosc lisci: " << (t-1)*n+1 << endl;
        if(czydopliku) cout << "Gotowe. Wyniki znajdziesz w pliku wynik.txt" << endl;

        cin >> n;

        return 0;
}
