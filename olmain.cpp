#include <iostream>


#include "Const.h"
#include "utils.h"
/* 
      Written by Ebenezer Shimeles, Sued, Yeabsira and Selihom
*/

/*
"	artistIds, names, genders, phones, emails are arrays that contains the artist information in an array
"	nArtist is the number of artist information currently existing in the arrays
"	artistIdRefs, char albumIds, titles, recordFormat, datePublished, paths are arrays to be loaded with album information
"	nAlbum is the number of albums information currently existing in the arrays 

*/
int nArtist=0, nAlbum=0;

int main(int argc, char** argv) {
	//int x = 100;
	//change(x);
	//cout <<x;

    char artistNames[NUMBER_OF_ARTIST_MAX][MAX_NAME_LEN] = {};
    char artistIds[NUMBER_OF_ARTIST_MAX][ MAX_ID_LEN] = {"12+"};
    char artistPhoneNumbers[NUMBER_OF_ARTIST_MAX][PHONE_LEN_MAX] = {};
    char artistGenders[NUMBER_OF_ARTIST_MAX] = {};
    char artistEmails[MAX_EMAIL_LEN][MAX_EMAIL_LEN]={};

    char albumIds[NUMBER_OF_ARTIST_MAX * 10][MAX_ID_LEN] = {"12"}; // This so because every arist can have 10 albums on average. 
    char albumOwnerIds[NUMBER_OF_ARTIST_MAX * 10][MAX_ID_LEN] = {"12"};
    char albumTitles[NUMBER_OF_ARTIST_MAX * 10][MAX_TITLE_LEN] = {"Better now"};
    char albumFormats[NUMBER_OF_ARTIST_MAX * 10][MAX_FORMAT_LEN] ={"CD"};
    char albumPublishedDates[NUMBER_OF_ARTIST_MAX * 10][DATE_MAX_LEN] = {"11/11/11"};
    //char dummy;
    char albumPaths[1000][MAX_PATH_LEN];
    //cout <<"HI";testDeleteArtist();
    //cout << "nArtist " <<nArtist<<endl;
    nAlbum++;
    nArtist++;
    welcome();
    loading(
	              artistIds, 
				  artistNames, 
				  artistGenders, 
				  artistPhoneNumbers, 
				  artistEmails, 
				  albumOwnerIds, 
				  albumIds, 
				  albumTitles, 
				  albumFormats, 
				  albumPublishedDates, 
				  albumPaths,
				  nArtist, 
				  nAlbum
	);
	while(1){
	  mainManager(
	      artistIds, 
	      artistNames, 
	      artistGenders, 
	      artistPhoneNumbers,
	      artistEmails, 
	      albumOwnerIds, 
	      albumIds,
	      albumTitles,
	      albumFormats,
	      albumPublishedDates,
	      albumPaths,
          nArtist,
	      nAlbum
	  );
    }
	farewell ();
	return(0);
}
