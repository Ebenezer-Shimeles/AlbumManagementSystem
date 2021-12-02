#include <string>
#include <iostream>
using namespace std;

struct ScoreInfo{
	char name[100];
	char id[100];
	char names[10][6];
	double scores[6];
};
double GetPoint(char grade){
	if(grade == 'A') return 4.00;
    else if(grade == 'B') return 3.00;
    else if(grade == 'C') return 2.00;
    else if(grade =='D') return 1.00;
    else if(grade == 'F') return 0.00;
    else return 'F';
}
char GetGrade(double score){
	if(score > 84.5 && score< 100 ) return 'A';
	else if(score < 84.5 && score > 79.5) return 'B';
	else if(score <= 79.5 && score >74.5) return 'C';
	else if(score <= 74.5 && score > 69.5) return  'D';
	else if(score <= 69.5 && score > 50) return 'D';
	else if(score < 50 ) return 'F';
 
	
}
int main(){
   ScoreInfo info;
   double cumilative = 0;
   cout << "Input the name: ";
   cin >> info.name;
   cout << "Input the ID";
   	cin>> info.id;
   	
   for(int i=0;i<5;i++)
   {
   	 int courseNo = i +1;
   	 cout << "Enter the name of course " << courseNo << " ";
   	 cin >> info.names[i];
   	 cout << "Enter the score out of a hundred: ";
   	 bool isValid = true;
	do{
		cin >> info.scores[i];
		isValid = info.scores[i] <= 100 && info.scores[i] > 0;
		if(!isValid )cerr <<endl<<"Please input a valid value!\a";
     }while(!isValid);
   }
  // cout <<endl << "NameL " <<info.name <<endl;
   //cout <<endl << "ID: " <<info.id <<endl;
   //cout <<endl<<" Course    Grade     Point"<<endl;
   for(int i=0;i<5;i++){
    char gr;
   	  //char gr = grade[0];
   	double score = info.scores[i];
   	double n = 0;
   	if(score > 84.5 && score<= 100 ){
	   n = 4.00; 
	   gr = 'A';
}
	else if(score < 84.5 && score > 79.5){
	   n = 3.00; 
	   gr = 'B';
}
	else if(score <= 79.5 && score >74.5){
	   n = 3.00; 
	   gr = 'B';
}
	else if(score <= 74.5 && score > 69.5){
	   n = 2.00; 
	   gr = 'C';
}
	else if(score <= 69.5 && score > 50){
	   n = 2.00; 
	   gr = 'D';
}
	else if(score < 50 )
	{
	   n = 1.00; 
	   gr = 'D';
}
   	cumilative += n; 
   	 cout << "Name: "<<info.names[i] << " Grade: " << gr << " Score:" << n << " "<< score<<endl;
   }
   float x = cumilative / 5;
   cout <<endl<< "GPA: "<< x;
} 
