#include <iostream>
using namespace std;
// void ganti(int *p){
//     *p = 50;
//     cout<<p<<endl;
// }
int main(){
    // int *p, *q, *r;
    // int n = 10;
    // p = &n;
    // cout<<*p<<endl;
    // cout<<p;

    // int array[3]= {10,20,30};
    // int i;
    // int *k;

    // k=array;
    // for(i=0;i<3;i++){
    //     cout<<*(k+i)<<" ";
    // }

    // char kota[] = "YOGYAKARTA";
    // cout<<kota<<endl;
    // char *j = kota;
    // cout<<*j<<endl;
    // int i;
    // for(i=0;i<10;i++){
    //     cout<<*(j+i)<<" ";
    // }

    // int x =10;
    // cout<<x<<endl;
    // ganti(&x);
    // cout<<x<<endl;
    // cout<<&x<<endl;

    int x=20;
    int *i=&x;
    int **ii = &i;
    cout<<**ii<<endl;

    return 0;
}