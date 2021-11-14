#include <iostream>
#include <cstring>

#include "Const.h"

using namespace std;

void searchArtistByName(
            const char names[][40], 
			int nArtist, 
			const char targetName[],  
			int result[], 
			int * noResult);

void searchArtistById(
             const char artistIds[][8], 
			 int nArtist, 
			 const char targetId[],  
			 int result[], 
			 int * noResult
);

void searchArtist(
            const char artistIds[][8], 
			const char names[][40], 
			int nArtist, 
			int result[], 
			int * noResult
){
	char choice; 
	cout << "Seraching artist.."<<endl;
    cout << "Do you want to search by \nA)ID or B)Name:  ";
    cin >> choice;
    int results[1000]; // This is where the results are stored
    int *numberOfResults;
    if(choice == 'A' || choice == 'a'){
    	//Search by Id
    	char targetId[MAX_ID_LEN];
    	cout <<endl << "Input the id please: ";
    	
    	cin >>targetId;
    	searchArtistById(
             artistIds, 
			 nArtist, 
			 targetId,  
			 results, 
			 noResult
        );
        //cout <<"Wait please";
	}
	else if(choice == 'B' || choice == 'b'){
		char targetName[MAX_NAME_LEN];
		cout <<"Input the prefix name: ";
		cin >>targetName;
		searchArtistByName(
            names, 
			nArtist, 
			targetName,  
			result, 
			noResult);
	}
	else{
        cerr << "Error in choice!\a";
        exit(-1);
    }
    
}
void searchArtistById(
             const char artistIds[][8], 
			 int nArtist, 
			 const char targetId[],  
			 int result[], 
			 int * noResult
){
	int resLen=0;
	char tmpStore[8];
	for(int j=0;j<8;j++) tmpStore[j] = '\0';
	
	for(int i=0;i<nArtist;i++){
		for(int j=0;j<8;j++){
			tmpStore[j] = artistIds[i][j];
            if(strcmp(tmpStore, targetId) == 0){
            	//cout <<endl<<tmpStore<<" = "<<targetId << "i="<<i<<" j="<<j;
            	result[resLen] = i;
            	resLen++;
            	cout <<endl<<"Reslen : "<<resLen;
            	for(int k=0;k<8;k++) tmpStore[k] = '\0';
            	break;
			}			
		}
		for(int j=0;j<8;j++) tmpStore[j] = '\0';
		cout <<" Relen: " <<resLen<<" ";
		//*noResult = resLen;
	}
}
void searchArtistByName(
            const char names[][40], 
			int nArtist, 
			const char targetName[],  
			int result[], 
			int * noResult){
	int resLen=0;
	char tmpStore[8];
	for(int i=0;i<nArtist;i++){
		for(int j=0;j<8;j++){
			tmpStore[j] = names[i][j];
            if(strcmp(tmpStore, targetName) == 0){
            	//cout <<endl<<tmpStore<<" = "<<targetId << "i="<<i<<" j="<<j;
            	result[resLen] = i;
            	resLen++;
            	cout <<endl<<"Reslen : "<<resLen;
            	for(int k=0;k<8;k++) tmpStore[k] = '\0';
            	break;
			}			
		}
		for(int j=0;j<8;j++) tmpStore[j] = '\0';
		cout <<" Relen: " <<resLen<<" ";
		//*noResult = resLen;
	}
}
