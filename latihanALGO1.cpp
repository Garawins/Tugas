#include <iostream>
using namespace std;
int main(){
    int array[5] = {10,20,30,40,50};
    int i;
    int *k;
    k = array;

    int sebelum, min, max, sum, avg;

    for(i=0;i<5;i++){
         cout<<*(k+i)<<" "<<endl;
        if(sebelum <*(k+i)){
            sebelum = *(k+i);
        } else 
        {
            min = *(k+i);
        }
        if(sebelum >*(k+i)){
            sebelum = *(k+i);
        } else 
        {
            max = *(k+i);
        }

        sum = sum + *(k+i);

    }
    avg = sum/5;

    cout << "Minimal : " << min << endl;
    cout << "Maximal : " << max << endl;
    cout << "Rata-rata : " << avg << endl;
    cout << "Jumlah : " << sum << endl;
}