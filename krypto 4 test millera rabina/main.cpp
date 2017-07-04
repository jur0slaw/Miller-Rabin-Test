#include <iostream>
#include <string.h>
#include <cmath>

using namespace std;


int main()
{
    int n,q;

    cout << "podaj nieparzysta liczbe n" << endl ;

    cin >> n;

    cout << "podaj liczbe q" << endl;

    cin >> q;

    int d = n-1;

    int s = 0;

    while(d%2==0){
        d/=2;
        s++;
    }

    cout << "oto d: " << d << "  oto s:  " << s << endl;




    int podstawa, modulo;
    podstawa = q;
    modulo = n;
    long int  wykladnik;
    wykladnik = d;
    long int temp = wykladnik;


    int wykladnik_bin[64];

    memset(wykladnik_bin,0,64*sizeof(int));

    int i=0;
    while(temp>0){
        wykladnik_bin[63-i]=temp%2;
        temp=temp/2;
        i++;
    }

    for(i=0;i<64;i++){
        //cout << wykladnik_bin[i];
    }

        cout << endl;

    i = 0;

    while(wykladnik_bin[i]==0){
        i++;
    }

    int pierwszy_adres=i;

    long long int potegi_modulo[64];

    potegi_modulo[63]=podstawa%modulo;
   // cout << potegi_modulo[63] << endl;


    for(i=62;i>=pierwszy_adres;i--){
        potegi_modulo[i]=(potegi_modulo[i+1]*potegi_modulo[i+1])%modulo;
    //    cout << potegi_modulo[i] << endl;
    }
    long long int wynik=1;

    for(i=pierwszy_adres;i<64;i++){
        if(wykladnik_bin[i]==1){
            wynik=(wynik*potegi_modulo[i])%modulo;
        }
    }

    bool pierwszy_warunek=false;
    bool drugi_warunek=false;

    cout << q <<"^"<< d  << "=" << wynik << "mod(" << n << ")" << endl;

    if(wynik==1){
        pierwszy_warunek=true;
    }

    for(i=1;i<s;i++){
            wynik=(wynik*wynik)%modulo;
            if(wynik==modulo-1){
                cout << q <<"^"<< (int)pow(2,i)<< "*" << d  << "=" << -1 << "mod(" << n << ")" << endl;
                drugi_warunek=true;
                break;
            }
            else{
                 cout << q <<"^"<< (int)pow(2,i)<< "*" << d  << "=" << wynik << "mod(" << n << ")" << endl;
            }
    }

    if(pierwszy_warunek == true || drugi_warunek == true){
        cout << "Liczba n jest prawdopodobnie liczba pierwsza";
    }else{
        cout << "Liczba n jest liczba zlozona";
    }




    return 0;
}
