#include <iostream>
#include <ctime>

using namespace std;


void Populate(int arr[], int &len){
	for(int i=0;i<len;i++){
		cout << i+1 << "]: ";
	     cin>>arr[i];
    }
}
void MinMax(int arr[], int len, int &max, int &min, int &maxfre,int &minfre){
    max = arr[0];
	min = arr[0];
	for(int i=0;i<len;i++){
		if(arr[i] > max){
		  max = arr[i];
		  maxfre=0;
	    }
		if(arr[i] < min){
		  min = arr[i];
		  minfre = 0;
	     }
        if(arr[i] == max) maxfre++;
		if(arr[i] == min) minfre++;		
	}
}
void Display( int max, int min, int maxfre, int minfre){
     cout << "Max :" <<max<<endl;
     cout << "Min :" <<min<<endl;
     cout << "maxFre: "<<maxfre<<endl;
     cout << "minfre: "<<minfre;
}
int main(){
	int arr[10], len = 10, max, min, minfre, maxfre;
	Populate(arr, len);
	MinMax(arr, len, max, min, maxfre, minfre);
	Display( max, min, maxfre,minfre);
	
}
