#include <iostream>
#include <cstring>

#include "Const.h"

using namespace std;
void searchAlbumByArtistId(
               const char artistIdsRefs[][8], 
			   int nAlbum, 
			   const char targetId[], //must contain art 
			   int result[],
			   int * noResult
);
//getAlbumPath
int selectAlbum(  const char artistIds[][MAX_ID_LEN], 
	const char titles[][MAX_TITLE_LEN], 
	const int result[], 
	int noResult
){
   int choice;
   cout <<endl <<"Please select an album"<<endl;
   for(int i =0;i<noResult;i++){
   	cout <<i+1 << ")[ title: " << titles[i] << endl;
   }	
   bool isOver;
   do{

       cin >> choice;
       isOver = choice > noResult || choice < 1;
       if(isOver) cerr <<endl <<"Error in choice retry!: ";
   }while(isOver);
   return choice;
}
void deleteAlbum(
            const char artistIds[][MAX_ID_LEN], 
			const char artistNames[][40],
			int nArtist, 
			char artistIdsRef[][MAX_ID_LEN], 
			char albumIds[][8], 
			char titles[][80],
			char recordFormats[][MAX_FORMAT_LEN],
			char datePublisheds[][11],
			char paths[][100],
		    int & nAlbum)
{
	int result[1000], noResult;
	searchArtist(
            artistIds, 
			artistNames, 
			nArtist, 
			result, 
			&noResult
   );
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
			   artistIds[selectedIdx], //must contain art 
			   result,
			   &noResult
    );
    selectedIdx = selectAlbum(
	    artistIds, 
	    titles, 
	    result, 
        noResult
    );
    removeAlbum(
              artistIdsRef, 
			  albumIds,
			  titles, 
			  recordFormats, 
			  datePublisheds, 
			  paths, nAlbum, 
              selectedIdx
   );
}
void getAlbumPath (char albumPath[]){
	cin>>albumPath;
}
void formatAlbumFormat(char albumFormat[]){
	for(int i=0;i<strlen(albumFormat);i++)
	{
		if(albumFormat[i] >= 'a') albumFormat[i] -= 'a' - 'A';
	}
}
bool validateAlbumFormat (const char albumFormat[]){
	return stricmp(albumFormat, "CD")  == 0|| stricmp(albumFormat, "DVD") == 0;
}
void getAlbumFormat(char format[MAX_FORMAT_LEN]){
	bool isValid;
	do{
	
		cin >>format;
	    isValid = validateAlbumFormat(format);
	    if(!isValid) cerr << "Please input eithe DVD or CD";
	}while(!isValid);
}

void formatAlbumTitle (char albumTitle[]){
	if(albumTitle[0] >= 'a') albumTitle[0] -= 'a' - 'A';
}
bool validateAlbumTitle (const char albumTitle[]){
	for(int i =0;i<strlen(albumTitle);i++)
	{
		//if(!(albumTitle[i] >= 'a' && albumTitle[i] <= 'z') || !(albumTitle[i] >= 'A' && albumTitle[i] <= 'Z')) return false;
	}
	return true;
}
void getAlbumTitle (char title[]){
	bool isValid;
	do{
	   cin >> title;
	   isValid = validateAlbumTitle(title);
	   if(!isValid) cerr <<endl << "Error in album title Renter correctly: "<<endl;
	   if(strlen(title) > MAX_TITLE_LEN) cerr<< "TOO MUCH LENGTH!";
    }while(!isValid || strlen(title) > MAX_TITLE_LEN);
    formatAlbumTitle(title);
}
bool validateAlbumDate(unsigned int day, unsigned int month, unsigned int year){
	return day < 31 && month < 12 && year < 2020;
}
void getAlbumDate (char albumDate[]){
	cin >> albumDate;
}
void getAlbumInfo (char titles[],char recordFormats[], char datePublished[], char paths[]){
    //cout << "HEre";
    cout << endl <<"Input Album title: "<<endl;
	getAlbumTitle(titles);
	cout << "Input Albums format: ";
	getAlbumFormat(recordFormats);
	cout << "Input album date: ";
	getAlbumDate (datePublished);
	cout << "Get album path: ";
	getAlbumPath(paths);
}
bool addAlbum(
      const char artistIds[][8], 
	  const char artistNames[][40], 
	  int nArtist,
	  char artistIdsRef[][8], 
	  char albumIds[][MAX_ID_LEN], 
	  char titles[][80], 
	  char recordFormats[][ MAX_FORMAT_LEN], 
	  char datePublisheds[][11], 
	  char paths[][100], 
	  int & nAlbum
){
	
	int noResult=0, results[1000] ={};
	searchArtist(
            artistIds, 
			artistNames, 
			nArtist, 
			results, 
			&noResult
   );
    int selectedIdx = selectArtist(
        artistIds, 
	    artistNames, 
	    results, 
	    noResult, 
	     0 
	);
	char albumTitle[MAX_TITLE_LEN] = {};
	char format[MAX_FORMAT_LEN] = {};
	char datePublished[DATE_MAX_LEN] = {};
	char path[MAX_PATH_LEN]= {};
	cout <<"Here";
	getAlbumInfo (albumTitle, format,  datePublished, path);
	
	
	
	strcpy(artistIdsRef[selectedIdx- 1], artistIds[selectedIdx]);
	char tmp[MAX_ID_LEN] = {};
	sprintf(tmp, "alb%d", nAlbum); //albums have alb* text 
	strcpy(albumIds[selectedIdx - 1], tmp); 
	strcpy(titles[selectedIdx - 1], albumTitle); 
	strcpy(recordFormats[selectedIdx - 1], format); 
	strcpy(datePublisheds[selectedIdx - 1], datePublished); 
	strcpy(paths[selectedIdx - 1], path); 
    nAlbum ++;
	///getAlbumFormat(format);
	return true;
}
void searchAlbumByArtistId(
               const char artistIdsRefs[][8], 
			   int nAlbum, 
			   const char targetId[], //must contain art 
			   int result[],
			   int * noResult
){
	//char tmpStore[8]={};
	cout << "Searching for " << targetId<<endl;
	int resLen=0;
	char tmpStore[8] ={};
	memset(tmpStore, '\0', 8); //clear the junk
	
	for(int i=0;i<nAlbum;i++){
		for(int j=0, k=0;j< MAX_ID_LEN;j++,k++){ //jump 3 because of 'art'  prefix
			tmpStore[k] = artistIdsRefs[i][j];
		//	cout <<tmpStore << " vs " <<targetId <<endl;
            if(strcmp(tmpStore, targetId) == 0){
            	//cout <<endl<<tmpStore<<" = "<<targetId << "i="<<i<<" j="<<j;
            	result[resLen] = i;
            	resLen++;
            	//cout <<endl<<"Reslen : "<<resLen;
            	
            	cout << endl << "Found match: " << artistIdsRefs[i] << " & " << targetId<<endl; 
            	//memset(tmpStore, '\0', 8);
            	break;
			}			
		}
		memset(tmpStore, '\0', 8);
	
		//cout <<" Relen: " <<resLen<<" " <<endl;
		*noResult = resLen;
		//cout <<" Relen ptr : " <<*noResult<<" " <<endl;
	}
}
void searchArtistNameById(
          const char artistIds[][8], 
		  const char artistNames[][40],
		  char name[40],
		  const char id[],
		  int nArtist
){
    for(int i=0;i<nArtist;i++){
    	if(strcmp(id, artistIds[i]) == 0){
    	 
    	   strcpy(name, artistNames[i]);
		}
	}	
}

void displayAllAlbums( 
        const char artistIds[8], 
		const char artistNames[][MAX_NAME_LEN], 
		const char artistIdsRef[][8], 
		const char albumIds[][8], 
		const char titles[][80], 
		const char recordFormats[][20], 
		const char datePublisheds[][11], 
		const char paths[][100], 
        int  nAlbum)
{
 unsigned int i=0;
 //cout <<"HERE " <<nAlbum ;
 char name[40] = {};
 int res=0;
 for(i=0;i<nAlbum;i++){
 	cout << artistIds << " Vs " <<artistIdsRef[i] <<endl;
 	if(strcmp(artistIds, artistIdsRef[i]) == 0){
 		memset(name, '\0', 40);
 		searchArtistNameById(artistIdsRef, artistNames, name, artistIds, 1000);
        cout << "[";
		cout <<" Owner's name: " << name << "  Owner's Id: " << artistIds << "  Album Id: " <<albumIds[i] << "  Title "<<titles[i];
		cout <<"]"<<endl; 		
	    res++;
	 }
 }
 if(res==0) cout <<endl<< "No ALBUMS FOUND!"<<endl;      

}



void displayOneAlbum(
          const char artistIdsRef[], 
		  const char albumIds[], 
		  char titles[], 
		  char  recordFormats[], 
		  char datePublisheds[], 
		  const char paths[]
){
     cout << "Titlte: " <<titles << " Format: " <<recordFormats <<  " Date Published: " <<datePublisheds <<  " Paths: " <<paths;	
}
bool editAlbumInfo(
         const char artistIdsRef[], 
		 const char albumIds[], 
		 char titles[], 
		 char  recordFormats[], 
		 char datePublisheds[], 
		 char paths[]
){
     cout <<endl <<"Please input the new title: " <<endl;
     memset(titles, '\0', MAX_TITLE_LEN);
     cin >> titles;
	 cout << "Please input the new format: " <<endl;
	 memset(recordFormats, '\0', MAX_FORMAT_LEN);
	 cin >>recordFormats;
	 cout << "Please input the new date :" <<endl;
	 memset(datePublisheds, '\0', DATE_MAX_LEN);
	 cin >> datePublisheds;
	 cout << "Please input the new path: "<<endl;
	 memset(paths, '\0', MAX_PATH_LEN);
	 cin >>paths;	
	 
	 displayOneAlbum(
          artistIdsRef, 
		  albumIds, 
		  titles, 
		  recordFormats, 
		  datePublisheds, 
		  paths
   );
}
void editAlbum(
    const char artistIds[][8], 
	const char artistNames[][40], 
	int nArtist, 
	char artistIdsRef[][8], 
	char albumIds[][MAX_ID_LEN], 
	char titles[][80], 
	char recordFormats[][MAX_FORMAT_LEN], 
	char datePublisheds[][DATE_MAX_LEN], 
	char paths[][100], 
	int nAlbum
)
{
	int results[1000], noResult;
	searchArtist(
            artistIds, 
			artistNames, 
			nArtist, 
			results, 
			&noResult
   );
    int selectedIdx = selectArtist(
        artistIds, 
	    artistNames, 
	    results, 
	    noResult, 
	     0 
	);
	searchAlbumByArtistId(
              artistIdsRef, 
			   nAlbum, 
			   artistIds[selectedIdx], //must contain art 
			   results,
			   &noResult
    );
    selectedIdx = selectAlbum(
	    artistIds, 
	    titles, 
	    results, 
        noResult
    );
    editAlbumInfo(
         artistIdsRef[selectedIdx], 
		  albumIds[selectedIdx], 
		  titles[selectedIdx], 
		   recordFormats[selectedIdx], 
		  datePublisheds[selectedIdx], 
		  paths[selectedIdx]
     );
		
}
