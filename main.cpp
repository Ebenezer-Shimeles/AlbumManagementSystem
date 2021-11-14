#include <iostream>

#include "utils.h"
#include "Const.h"
#include "deleteArtist.h"
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
	int nArtist=1, nAlbum=1;
    char artistNames[NUMBER_OF_ARTIST_MAX][MAX_NAME_LEN] = {"Ebenezer"};
    char artistIds[NUMBER_OF_ARTIST_MAX][ MAX_ID_LEN] = {"124"};
    char artistPhoneNumbers[NUMBER_OF_ARTIST_MAX][PHONE_LEN_MAX] = {"0912701156"};
    char artistGenders[NUMBER_OF_ARTIST_MAX] = {'M'};
    char artistEmails[MAX_EMAIL_LEN][MAX_EMAIL_LEN]={"ebenezertesaye@yahoo.com"};

    char albumIds[NUMBER_OF_ARTIST_MAX * 10][MAX_ID_LEN] ={"1"}; // This so because every arist can have 10 albums on average. 
    char albumOwnerIds[NUMBER_OF_ARTIST_MAX * 10][MAX_ID_LEN] = {"1"};
    char albumTitles[NUMBER_OF_ARTIST_MAX * 10][MAX_TITLE_LEN] = {"Illmatic"};
    char albumFormats[NUMBER_OF_ARTIST_MAX * 10][MAX_FORMAT_LEN] ={"Cd"};
    char albumPublishedDates[NUMBER_OF_ARTIST_MAX * 10][DATE_MAX_LEN] = {"1/1/2001"};
    //char dummy;
    char albumPaths[1000][MAX_PATH_LEN];
    //cout <<"HI";testDeleteArtist();
    deleteArtist(
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
				 nAlbum);
	//greet();
	return(0);
}
