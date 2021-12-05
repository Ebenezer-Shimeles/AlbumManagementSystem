#include <iostream>


#include "Const.h"
#include "utils.h"
/* 
      Written by Ebenezer Shimeles, Seud neuredin, Yeabsira Mekuria and Selihom Kidane
*/


int nArtist=0, nAlbum=0;

int main(int argc, char** argv) {
	//int x = 100;
	//change(x);
	//cout <<x;

    char artistNames[NUMBER_OF_ARTIST_MAX][MAX_NAME_LEN] = {};
    char artistIds[NUMBER_OF_ARTIST_MAX][ MAX_ID_LEN] = {};
    char artistPhoneNumbers[NUMBER_OF_ARTIST_MAX][PHONE_LEN_MAX] = {};
    char artistGenders[NUMBER_OF_ARTIST_MAX] = {};
    char artistEmails[MAX_EMAIL_LEN][MAX_EMAIL_LEN]={};

    char albumIds[NUMBER_OF_ARTIST_MAX * 10][MAX_ID_LEN] = {"alb1"}; // This so because every arist can have 10 albums on average. 
    char albumOwnerIds[NUMBER_OF_ARTIST_MAX * 10][MAX_ID_LEN] = {"art0"};
    char albumTitles[NUMBER_OF_ARTIST_MAX * 10][MAX_TITLE_LEN] = {"Baby"};
    char albumFormats[NUMBER_OF_ARTIST_MAX * 10][MAX_FORMAT_LEN] ={"CD"};
    char albumPublishedDates[NUMBER_OF_ARTIST_MAX * 10][DATE_MAX_LEN] = {"11/11/11"};
    //char dummy;
    char albumPaths[1000][MAX_PATH_LEN] = {"C:\\", "D:\\"};
    //cout <<"HI";testDeleteArtist();
    //cout << "nArtist " <<nArtist<<endl;
    
    nAlbum++;
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
	farewell ();
	return(0);
}
