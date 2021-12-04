#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>

#include "artist.h"
#include "album.h"
#include "Const.h"

using namespace std;

void farewell (){
	cout <<"\nGoodbye!\n";
	exit(0);
}
int viewArtistMenu(){
	int choice = 100;
	cout << "Please choose one:";
	cout << "\n\t1)Display All Artist\n\t2)View Artist By Search\n\t3)Back To Main Menu\n\t4)Exit\nYour choice: ";
	bool tmp;
	do{
		cin >>choice;
		tmp = choice >5 || choice < 1;
		if(tmp) cerr << endl <<"Error in choice please retry" <<endl;
	}while(tmp);
	return choice;
}
int editAlbumMenu(){
	cout << "Choose one please\n\t1)Add Artist Album\n\t2)Edit Artist Album\n\t3)Delete Artist Album\n\t4)Back To Main Menu\n\t5)Exit\nYour choice:";
	int choice;
	bool isValid = false;
	do{
		cin >> choice;
		isValid = choice <=5 && choice >=1;
		if(!isValid) cerr << "\nError in choice retry\a: ";
	}while(!isValid);
	return choice;
}
bool albumEditor(
         const char artistIds[][8], 
		 const char artistNames[][40], 
		 int nArtist, 
		 char artistIdsRef[][8], 
		 char albumIds[][MAX_ID_LEN], 
		 char titles[][80], 
		 char recordFormats[][MAX_FORMAT_LEN], 
		 char datePublisheds[][11], 
		 char paths[][100],
		  int & nAlbum
){
	//"\n\t1)Add Artist Album\n\t2)Edit Artist Album\n\t3)Delete Artist Album\n\t4)Back To Main Menu\n\t5)Exit\nYour choice";
	switch(editAlbumMenu()){
		case 1:{
			//add
			bool suc = addAlbum(
			       artistIds, 
			       artistNames,
			       nArtist, 
				   artistIdsRef,
			       albumIds,
			       titles,
			       recordFormats,
				   datePublisheds, 
				   paths, 
			       nAlbum
			);
			if(!suc) cerr << "Adding album failed!";
		    return true;
		}
		case 2:{
			//edit
		
			editAlbum(
			       artistIds, 
			       artistNames,
			       nArtist, 
				   artistIdsRef,
			       albumIds,
			       titles,
			       recordFormats,
				   datePublisheds, 
				   paths, 
			       nAlbum
			); 
			return true;
		}
		case 3:{
			//delete
			 deleteAlbum(	 
			       artistIds, 
			       artistNames,
			       nArtist, 
				   artistIdsRef,
			       albumIds,
			       titles,
			       recordFormats,
				   datePublisheds, 
				   paths, 
			       nAlbum
			 );
			return true;
		}
		case 4:{
			//back
			return true;
			//break;
		}
		case 5:{
			//exit
			return false;
		}
		
	}
}
void displaSearchAlbumResult(
       //const char artistIdsRef[][8],
	   const char albumIds[][8], 
	   const char titles[][80], 
	   const char recordFormats[][20], 
	   const char datePublisheds[][11], 
	   const char paths[][100],
       int results[], 
	   int noResult
){
	if(!noResult) cout <<endl<< "The artist has no albums"<<endl;
	for(int i=0;i<noResult;i++){
	
	    int albumIndex = results[i];
	    cout <<endl << "["<< i+1 << ") Title: " << titles[albumIndex] << "Album Id:  "<< albumIds[albumIndex]<<endl;
		cout  <<"\t Date Published: "<< datePublisheds[albumIndex] << " Path:";
		cout  << paths[albumIndex]<<" record format: "<<recordFormats[albumIndex] << "]"<<endl;
   }

} 
void viewArtistAlbumsBySearch(
       const char artistIds[][8], 
	   const char artistNames[][40], 
	   int nArtist, 
	   const char artistIdsRef[][8],
	   const char albumIds[][8], 
	   const char titles[][80], 
	   const char recordFormats[][20], 
	   const char datePublisheds[][11], 
	   const char paths[][100], 
	   int  nAlbum
){
	int result[1000];
	int noResult = 0;
	searchArtist(
            artistIds, 
			artistNames, 
			nArtist, 
		    result, 
			&noResult
    );
    cout << "No res "<<noResult<<endl;
    if(noResult == 0 ) return; //works! 
    int selectedIdx = selectArtist(
        artistIds, 
	    artistNames, 
	    result, 
	    noResult, 
	     0 
	);

	searchAlbumByArtistId(
              artistIdsRef, 
			   nAlbum, 
			   artistIds[selectedIdx - 1], //must contain art 
			   result,
			   &noResult
    );
    
    displaSearchAlbumResult(
       //const char artistIdsRef[][8],
	   albumIds, 
	   titles, 
	   recordFormats, 
	   datePublisheds, 
	   paths,
       result, 
	   noResult
    );
}
int albumMenu(){
	int choice = 100;
	
	cout << "\n\t1)View Artist Albums\n\t2)Edit Artist Album\n\t3)Back To Main Menu\n\t4)Exit\nYour choice: ";
	bool tmp;
	do{
		cin >> choice;
	    tmp = choice > 4 || choice < 0;
		if(tmp) cerr << "Error! in choice retry!\a\n";
	}while(tmp);
	return choice;
}

int viewAlbumMenu(){
	int choice = 100;
    cout <<"Please choice one";
	cout << "\n\t1)Display All Album\n\t2)View Album By Search\n\t3)Back To Main Menu\n\t4)Exit\nYour choice: ";
	bool tmp;
	do{
		cin >> choice;
		tmp = choice > 4 || choice < 0;
		if(tmp) cerr << "Error! in choice retry!\a\n";
	}while(tmp);
	return choice;
}
bool albumViewer(
       const char artistIds[][8], 
	   const char artistNames[][40], 
	   int nArtist, 
	   const char artistIdsRef[][8],
	   const char albumIds[][8], 
	   const char titles[][80], 
	   const char recordFormats[][20], 
	   const char datePublisheds[][11], 
	   const char paths[][100], 
	   int  nAlbum
){
	int choice = viewAlbumMenu();
	switch(choice){
		case 1:{
			char id[MAX_ID_LEN]={};
			cout << "Please input the artis's Id:   ";
			cin >>id;
            displayAllAlbums( 
               id, 
		       artistNames, 
		       artistIdsRef, 
		       albumIds, 
		       titles, 
		       recordFormats, 
		       datePublisheds, 
		       paths, 
               nAlbum
			);
			//system("pause");
			return true; //back to main menu			
		
		}
		case 2:{
			viewArtistAlbumsBySearch(
                artistIds, 
	            artistNames, 
	            nArtist, 
	            artistIdsRef,
	            albumIds, 
	            titles, 
	            recordFormats, 
	            datePublisheds, 
	            paths,
	            nAlbum
            );
            //system("pause");
			return true; //back to main menu
		}
		case 3:{
			return true; //back to main menu
			//break;
		}
		case 4:{
			return false;
			//farewell();
			//break;
		}
		
	}
}
bool albumManager(
             const char artistIds[][8],
			 const char artistNames[][40], 
			 int nArtist, char artistIdsRef[][8], 
			 char albumIds[][8], 
			 char titles[][80],
			 char recordFormats[][20],
			 char datePublisheds[][11],
			 char paths[][100], 
             int & nAlbum
){
	cout << "ALbum manager\n";
	int choice = albumMenu();
	switch(choice){
		case 1:{
			//album viewer
			return  albumViewer(
                artistIds, 
	            artistNames, 
	            nArtist,    
	            artistIdsRef,
	            albumIds, 
	            titles, 
	            recordFormats, 
	            datePublisheds, 
	            paths, 
	            nAlbum
             );
		//	return true;
		}
		case 2:{
			//alubum editor
			return albumEditor(
                artistIds, 
	            artistNames, 
	            nArtist,    
	            artistIdsRef,
	            albumIds, 
	            titles, 
	            recordFormats, 
	            datePublisheds, 
	            paths, 
	            nAlbum
           ) ;// cerr << "Edditing Failed!\a\n"; 
			//return true;
		}
		case 3:{
			return true;
			//break;
		}
		case 4:{
			return false;
			//farewell();
			//break;
		}
	}
}

int viewAlbMenu(){ //some
	int choice;
	cout << "\n\t0)Add add artist\n\t1)Edit Artist2)\n\tDelete Artist3)\n\tBack To Main Menu\n\t4)Exit\nYour choice: ";
	
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
   cout <<" Please Select your choice\n\t1)Manage Artist\n\t2)Manage Album\n\t3)Exit\nYour Choice:";	
}

int artistMenu(){
	int choice = 100;
	cout << "Please choose one\n";
	cout << "\t1)View Artist\n\t2)Edit Artist\n\t3)Back To Main Menu\n\t4)Exit\nYour choice:";
    bool isValid;
	do{
        
    	cin>>choice;
        isValid = choice <= 4 || choice >= 1;
        if(!isValid) cerr<<endl<<"Error in input please reenter!\a:";
	}while(!isValid);
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
		//system("cls");
	    return false;
	}
	else if(choice == 4) farewell();
}
int editArtistMenu(){
	int choice;
	cout << "\n\t0)Add artist\n\t1)Edit Artist\n\t2)Delete Artist\n\t3)Back To Main Menu\n\t4)Exit\nYour choice:";
	bool isValid = false;
	do{
		
		cin >> choice;
		isValid = choice <= 4 && choice >=0;
		if(!isValid) cerr << "Error in chooice please retry!\a:";
	}while(!isValid);
	return choice;
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
	int choice = editArtistMenu();
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
		return false; //PLEASE FIX THIS
	}
	else if(choice == 4){
		farewell();
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
		cout << "View Artist chooosen!" <<endl;
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
		if(!choice ) return false;
	}
	else if(choice == 3)
	{
		//system("cls");
        return false;
	}
	else if(choice ==4) farewell();
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
	
	system("pause"); //change to timeout 5
	system("cls");
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
	else if(choice == 2){
		bool choice = albumManager(
             artistIds,
			 names, 
			 nArtist, 
			 artistIdsRefs, 
			 albumIds, 
			 titles,
			 recordFormats,
			 datePublished,
			 paths, 
             nAlbum
       );
       if(choice){ //choice 3 => mainmanager return true or choice 4=> farewell =>exit
       	//system("cls");
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
	   else farewell();
	}
	else if(choice == 3) farewell();
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
