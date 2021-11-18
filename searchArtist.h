#include <iostream>
#include <cstring>
#include <cstdlib>

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
	cout << "Searching artist.."<<endl;
    cout << "Do you want to search by \nA)ID or B)Name:  ";
    cin >> choice;
    int results[1000]; // This is where the results are stored
    //int *numberOfResults;
    if(choice == 'A' || choice == 'a'){
    	//Search by Id
    	char targetId[MAX_ID_LEN] = {};
    	
    	cout <<endl << "Input the id please: ";
    	
    	cin >>targetId;
    	cout <<endl<< "The target ID is: "<<targetId<<endl;
        //*noResult = 10;	
    	//return;
    	//all Fine
    	searchArtistById(
             artistIds, 
			 nArtist, 
			 targetId,  
			 result, 
			 noResult
        );
        //noResult[0] = 10004;
        //cout << "Result length search: "<< *noResult << endl;
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
	//*noResult = 100;
	cout << "Searching for " << targetId<<endl;
	int resLen=0;
	char tmpStore[8];
	memset(tmpStore, '\0', 8); //clear the junk
	
	for(int i=0;i<nArtist;i++){
		for(int j=0;j< MAX_ID_LEN;j++){ //jump 3 because of 'art'  prefix
			tmpStore[j] = artistIds[i][j];
			cout <<tmpStore << " vs " <<targetId <<endl;
            if(strcmp(tmpStore, targetId) == 0){
            	//cout <<endl<<tmpStore<<" = "<<targetId << "i="<<i<<" j="<<j;
            	result[resLen] = i;
            	resLen++;
            	//cout <<endl<<"Reslen : "<<resLen;
            	
            	cout << endl << "Found match: " << artistIds[i] << " & " << targetId<<endl; 
            	//memset(tmpStore, '\0', 8);
            	break;
			}			
		}
		memset(tmpStore, '\0', 8);
	
		//cout <<" Relen: " <<resLen<<" " <<endl;
		*noResult = resLen;
		//cout <<" Relen ptr : " <<*noResult<<" " <<endl;
	}
	//cout << "Done searching by ID" <<endl;
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
            	//cout <<endl<<"Reslen : "<<resLen;
            	for(int k=0;k<8;k++) tmpStore[k] = '\0';
            	break;
			}			
		}
		for(int j=0;j<8;j++) tmpStore[j] = '\0';
		//cout <<" Relen: " <<resLen<<" ";
		//*noResult = resLen;
	}
	*noResult = resLen;
}
