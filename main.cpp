#include <iostream>

#include "utils.h"
#include "Const.h"
#include "deleteArtist.h"
#include "album.h"
/* 
      Written by Ebenezer Shimeles, Sued, Yeabsira and Selihom
*/

/*
"	artistIds, names, genders, phones, emails are arrays that contains the artist information in an array
"	nArtist is the number of artist information currently existing in the arrays
"	artistIdRefs, char albumIds, titles, recordFormat, datePublished, paths are arrays to be loaded with album information
"	nAlbum is the number of albums information currently existing in the arrays 

*/

int main(int argc, char** argv) {
	//int x = 100;
	//change(x);
	//cout <<x;
	int nArtist=0, nAlbum=0;
    char artistNames[NUMBER_OF_ARTIST_MAX][MAX_NAME_LEN] = {};
    char artistIds[NUMBER_OF_ARTIST_MAX][ MAX_ID_LEN] = {};
    char artistPhoneNumbers[NUMBER_OF_ARTIST_MAX][PHONE_LEN_MAX] = {};
    char artistGenders[NUMBER_OF_ARTIST_MAX] = {};
    char artistEmails[MAX_EMAIL_LEN][MAX_EMAIL_LEN]={};

    char albumIds[NUMBER_OF_ARTIST_MAX * 10][MAX_ID_LEN] = {}; // This so because every arist can have 10 albums on average. 
    char albumOwnerIds[NUMBER_OF_ARTIST_MAX * 10][MAX_ID_LEN] = {};
    char albumTitles[NUMBER_OF_ARTIST_MAX * 10][MAX_TITLE_LEN] = {};
    char albumFormats[NUMBER_OF_ARTIST_MAX * 10][MAX_FORMAT_LEN] ={};
    char albumPublishedDates[NUMBER_OF_ARTIST_MAX * 10][DATE_MAX_LEN] = {};
    //char dummy;
    char albumPaths[1000][MAX_PATH_LEN];
    //cout <<"HI";testDeleteArtist();
    //cout << "nArtist " <<nArtist<<endl;
    
    do{
    	addArtist(
           artistIds, 
		   artistNames, 
		   artistGenders, 
		   artistPhoneNumbers, 
		   artistEmails, 
		   nArtist
       );
    	displayAllArtist(
           artistIds, 
		   artistNames, 
		   artistGenders, 
		   artistPhoneNumbers, 
		   artistEmails, 
		   nArtist
        );
        editArtist(
         artistIds, 
		   artistNames, 
		   artistGenders, 
		   artistPhoneNumbers, 
		   artistEmails, 
		   nArtist);
        
	}while(true);
	//greet();
	return(0);
}
