#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>

#include "artist.h"
#include "Const.h"

using namespace std;

int viewArtistMenu(){
	int choice;
	cout << "\n\t0)Add add artist 1)\n\tEdit Artist2)\n\tDelete Artist3)\n\tBack To Main Menu\n\t4)Exit\nYour choice: ";
	
	do{
	   cin >>choice;
	   if(choice > 4 || choice < 0) cerr <<endl<< "Error in choice  retry!"<<endl;
    }
    while(choice > 4 || choice < 0);
	
	return choice;
}
void viewArtistBySearch(
          const char artistIds[][8], 
		  const char names[][40], 
		  const char genders[], 
		  const char phones[][11], 
		  const char emails[][80], 
		  int nArtist
){
	int noResult;
	int result[1000];
	cout << "\nSearch ..\n";
    searchArtist(
            artistIds, 
			names, 
			nArtist, 
		    result, 
			&noResult
    );
	displaySearchResult(
             artistIds, 
			 names, 
			 genders, 
			 phones, 
			 emails, 
			 nArtist, 
			 result, 
			noResult
   );  	
}
int mainMenu(){
   cout <<" Please Select your choice \n\t1) Manage Artist, \n\t2)Manage Album \n\t3)Exit\nYour Choice:";	
}

int artistMenu(){
	int choice = 100;
	cout << "Please choose one\n";
	cout << "\t1)View Artist\n\t2)Edit Artist\n\t3)Back To Main Menu\n\t4)Exit\nYour choice:";
	cin>>choice;
	return choice;
}

//Manages artist information

bool artistViewer(
           const char artistIds[][8], 
		   const char names[][40],  
		   const char genders[], 
		   const char phones[][11], 
		   const char emails[][80], 
		   int nArtist
){
	int choice;
	do{
	   choice = viewArtistMenu();	
	   if(choice > 4 || choice < 1) cerr <<endl <<endl<<"Please select a valid  choice!\a"<<endl;
	}while(choice > 4 || choice < 1);
	
	if(choice == 1){
		displayAllArtist(
               artistIds, 
			   names, 
			   genders, 
			   phones, 
			   emails, 
			   nArtist
       );
	}
	else if(choice == 2){
		viewArtistBySearch(
           artistIds, 
		   names, 
           genders, 
		   phones, 
		   emails, 
		   nArtist
		);

	}
	else if(choice == 3){
		system("cls");
	    return false;
	}
	else if(choice == 4) exit(0);
}

bool artistEditor(
         char artistIds[][8], 
		 char names[][40], 
		 char genders[], 
		 char phones[][11], 
		 char emails[][80], 
		 char artistIdsRefs[][8], 
		 char albumIds[][8], 
		 char titles[][80], 
		 char recordFormats[][20], 
		 char datePublished[][11], 
		 char paths[][100], 
		 int & nArtist, 
		 int & nAlbum
){
	//
	int choice = viewArtistMenu();
	if(choice == 0){
		addArtist(
           artistIds, 
		   names, 
		   genders, 
		   phones, 
		   emails, 
		   nArtist
       );
	}
	else if(choice ==1 ){
		editArtist(
           artistIds, 
		   names, 
		   genders, 
		   phones, 
		   emails, 
		   nArtist
        );
	}
	else if(choice == 2){
		deleteArtist(
                  artistIds, 
                  names, 
				  genders, 
				  phones, 
				  emails, 
				  artistIdsRefs, 
				  albumIds, 
				  titles, 
				  recordFormats, 
				  datePublished,
				  paths,
				  nArtist, 
				  nAlbum
       );
	}
	else if(choice == 3){
		return true; //PLEASE FIX THIS
	}
	else if(choice == 4){
		return false;
	}
}

bool artistManager(
       char artistIds[][8], 
	   char names[][40],
	   char genders[],
	   char phones[][11],
	   char emails[][80],
	   char artistIdsRefs[][8],
	   char albumIds[][8],
	   char titles[][80],
	   char recordFormats[][20],
	   char datePublished[][11],
	   char paths[][100],
	   int & nArtist,
	   int & nAlbum
)
{
	int choice = artistMenu();
	if(choice == 1){
		artistViewer(
           artistIds, 
		   names,  
		   genders, 
		   phones, 
		   emails, 
		   nArtist
		);
	}
	else if(choice == 2){
		bool choice = artistEditor(
         artistIds, 
		 names, 
		 genders, 
		 phones, 
		 emails, 
		 artistIdsRefs, 
		 albumIds, 
		 titles, 
		 recordFormats, 
		 datePublished, 
		 paths, 
		 nArtist, 
		 nAlbum
        );
		if(!choice )exit(0);
	}
	else if(choice == 3)
	{
		system("cls");
        return false;
	}
	else if(choice ==4) exit(0);
}
void mainManager(
    char artistIds[][8], 
	char names[][40], 
	char genders[], 
	char phones[][11],
	char emails[][80], 
	char artistIdsRefs[][8], 
	char albumIds[][8],
	char titles[][80],
	char recordFormats[][20],
	char datePublished[][11],
	char paths[][100],
    int & nArtist,
	int & nAlbum
){
	mainMenu();
	int choice=10;
	do{
	    
	    cin >> choice;
	    if(choice > 3 || choice < 1){
		    cerr <<endl<<"Error in choice Please retry!\a\n";
	    }
    }
	while(choice > 3 || choice < 1);
	
	if(choice == 1){
	   if(!artistManager(
          artistIds, 
	      names,
	      genders,
	      phones,
	      emails,
	      artistIdsRefs,
	      albumIds,
	      titles,
	      recordFormats,
	      datePublished,
	      paths,
	      nArtist,
	      nAlbum
       )) 
	   mainManager(
            artistIds, 
	        names, 
	        genders, 
	        phones,
            emails, 
	        artistIdsRefs, 
	        albumIds,
	        titles,
	        recordFormats,
	        datePublished,
	        paths,
            nArtist,
	        nAlbum
      );
	}
	else if(choice == 2); //mamnage album
	else if(choice == 3) exit(0);
}

void farewell (){
	cout <<"\nGoodbye!\n";
}
void loadAlbum(
      char albumIds[NUMBER_OF_ARTIST_MAX * 10][MAX_ID_LEN], // This so because every arist can have 10 albums on average. 
    char albumOwnerIds[NUMBER_OF_ARTIST_MAX * 10][MAX_ID_LEN],
    char albumTitles[NUMBER_OF_ARTIST_MAX * 10][MAX_TITLE_LEN],
    char albumFormats[NUMBER_OF_ARTIST_MAX * 10][MAX_FORMAT_LEN],
    char albumPublishedDates[NUMBER_OF_ARTIST_MAX * 10][DATE_MAX_LEN],
	int nAlbums 
){
	cout << "Loading albums\n";
}
void loadArtists(
             char artistIds[][8], 
			 char names[][40], 
			 char genders[], 
			 char phones[][11], 
			 char emails[][80], 
			 int & nArtist
){
	
	cout << "Loading artists\n";
}
void loading(
            char artistIds[][8], 
			char names[][40], 
			char genders[], 
			char phones[][11], 
			char emails[][80], 
			char artistIdRefs[][8], 
			char albumIds[][8], 
			char titles[][80], 
			char recordFormats[][20], 
			char datePublished[][11], 
			char paths[][100],
			int & nArtist, 
			int & nAlbum){
				
    cout <<"\nLoading...\n";
	loadArtists(
             artistIds, 
			 names, 
			 genders, 
			 phones, 
			 emails, 
			 nArtist
	 );
	 loadAlbum(
       albumIds,  
       artistIdRefs,
       titles,
       recordFormats,
       datePublished,
	   nAlbum 
    );
}
void welcome(){
	cout << "Hello, welcome to our Album management system!\n";
}
