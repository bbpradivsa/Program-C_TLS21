/*
TUGAS TLS
KALKULATOR SEDERHANA

BERFUNGSI UTK MEMBANTU PARA PELAJAR MENCARI NILAI DARI BEBERAPA PERHITUNGAN MATEMATIS TERTENTU, DENGAN ERROR YANG CUKUP KECIL
*/
#include <iostream>
#include <cmath>
#define pi 3.14
using namespace std;

int volume()
{
    float diameter, height, volume, area;
    string solidFigure;

    cout<<"Insert Desired Figure (Cylinder or Cone)? "<<"\nCASE SENSITIVE!"<<"\nInput: ";
    cin>>solidFigure;
    
    if(solidFigure == "Cylinder" || solidFigure == "Cone")
    {
        cout<<"Diameter: ";
        cin>>diameter;
        cout<<"Height: ";
        cin>>height;
        
        if(solidFigure == "Cylinder")
        {
            volume = pi/4 * pow(diameter, 2) * height; /*Rumus: pi x d^2 x 1/4 * tinggi*/
            area = 2 * (pi/4 * pow(diameter, 2)) + (pi * diameter * height); /*Rumus: 2(pi/4 x d^2) + pi x diameter x tinggi*/
        }
        else if(solidFigure == "Cone")
        {
            volume = pi/12 * pow(diameter, 2) * height; /*Rumus 1/3(pi/4 x d^2) x tinggi*/
            area = (pi/4 * pow(diameter, 2)) + (pi * (sqrt(pow(diameter/2, 2) + pow(height, 2))) * diameter/2); /*Rumus: (pi/4 x d^2) + pi x diameter/2 x akar ((diameter/2)^2 + tinggi^2)*/
        }
    }
    else
    {
        cout<<"Error";
        return 0;
    }
    
    cout<<"Volume of your "<<solidFigure<<" is "<<volume<<endl;
    cout<<"Area of your "<<solidFigure<<" is "<<area;
    return 0;
}

int kpk()
{
    int a,temp=1;
    cout<<"Jumlah bilangan yang ingin diinput: ";
    cin>>a;

    int b[a];
    for(int i=0;i<a;i++)
    {
        cout<<"Bilangan ke-"<<i+1<<": ";
        cin>>b[i];
    }
    for(int i=0;i<a;i++)
    {
        for(int j=i+1;j<a;j++)
        {
            for(int k=1;k<=b[i]*b[j];k++)
            {
                if(k%b[i]==0 && k%b[j]==0 && k%temp==0)
                {
                    temp=k;
                    break;
                }
            }
        }
    }
    cout<<"KPK dari ke-"<<a<<" Bilangan tersebut adalah: "<<temp;
    return 0;
}

int sorting ()
{
    int n=0;
    cout<<"Jumlah bilangan yang ingin diinput: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Bilangan ke-"<<i+1<<": ";
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        int temp=0;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[i])
            {
                temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
    }
    cout<<"Sorted: \n";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}

int konversi()
{
    int input,detik,menit,jam;
    cout<<"Input waktu dalam satuan detik: ";
    cin>>input;

    detik=input%3600;
    menit=detik/60;
    jam=input/3600;
    detik=detik%60;
    
    cout<<"Output: (Jam:Menit:Detik)\n";
    cout<<jam<<":";
    cout<<menit<<":";
    cout<<detik;
    return 0;
}

int main()
{
    int state;
    cout<<"Selamat datang! :)\nMau menghitung apa? \n(1) Volume Kerucut/Tabung (2) Menghitung KPK \n(3) Mengurutkan bilangan (4) Konversi detik ke jam\n";
    cin>>state;

    if(state>4||state<1){
    cout<<"Input tidak dikenal, silahkan mulai ulang program.\n";
    cout<<"Program terminated with invalid input. Program will terminate.";
    return 0;}

    else if(state==1)
    {
        volume();
        state=0;
    }
    else if(state==2)
    {
        kpk();
        state=0;
    }
    else if(state==3)
    {
        sorting();
        state=0;
    }
    else if(state==4)
    {
        konversi();
        state=0;
    }
    cout<<"\nProgram runs correctly. Program will terminate.";
}