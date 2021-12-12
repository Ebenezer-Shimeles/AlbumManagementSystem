#include <iostream>
#include <cstring>

#include "Const.h"

using namespace std;


void sortAlbum(
          char artistIdRefs[][MAX_ID_LEN], 
		  char albumIds[][MAX_ID_LEN], 
		  char titles[][MAX_TITLE_LEN], 
		  char recordFormats[][MAX_FORMAT_LEN], 
		  char datePublished[][DATE_MAX_LEN], 
		  char paths[][MAX_PATH_LEN],  
		  int nAlbum
){
   char tempAlbumId[MAX_ID_LEN] ={};
   char tempRefId[MAX_ID_LEN] = {};
   char tempTitle[MAX_TITLE_LEN] ={};
   char tempFormat[MAX_FORMAT_LEN] = {};
   char tempDate[DATE_MAX_LEN] ={};
   char tempPath[MAX_PATH_LEN];
   int i, j;

    for(i=0;i<nAlbum;i++)  
    for(j=1; j<nAlbum; j++)
    {
        if(stricmp(artistIdRefs[j-1], artistIdRefs[j])>0)
        {
        	strcpy( tempPath,  paths[j-1]);
            strcpy( paths[j-1],  paths[j]);
            strcpy( paths[j], tempPath);
            
            strcpy( tempDate,  datePublished[j-1]);
            strcpy( datePublished[j-1],  datePublished[j]);
            strcpy( datePublished[j], tempDate);
            
            strcpy(tempAlbumId, albumIds[j-1]);
            strcpy(albumIds[j-1], albumIds[j]);
            strcpy(albumIds[j], tempAlbumId);


            strcpy(tempRefId, artistIdRefs[j-1]);
            strcpy(artistIdRefs[j-1], artistIdRefs[j]);
            strcpy(artistIdRefs[j], tempRefId);

      
            strcpy( tempTitle,  titles[j-1]);
            strcpy( titles[j-1],  titles[j]);
            strcpy( titles[j], tempTitle);

            strcpy( tempFormat,  recordFormats[j-1]);
            strcpy( recordFormats[j-1],  recordFormats[j]);
            strcpy( recordFormats[j], tempFormat);            
		}
    }
}
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
   if(!noResult){
    cerr << "No albums  found!";
    return -1;
   }
   cout <<endl <<"Please select an album ["<<noResult <<"]"<<endl;
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
	int result[1000] ={}, noResult=0;
	searchArtist(
            artistIds, 
			artistNames, 
			nArtist, 
			result, 
			&noResult
   );
   cout << "Con: " << noResult;
   int selectedIdx = selectArtist(
        artistIds, 
	    artistNames, 
	    result, 
	    noResult, 
	     0 
	);
	if(selectedIdx == -1) {
		
		return;
	}
	int result2[100] ={};
	searchAlbumByArtistId(
              artistIdsRef, 
			   nAlbum, 
			   artistIds[result[selectedIdx - 1]], //must contain art 
			   result2,
			   &noResult
    );
    selectedIdx = selectAlbum(
	    artistIds, 
	    titles, 
	    result2, 
        noResult
    );
    if(selectedIdx == -1) return;
    removeAlbum(
              artistIdsRef, 
			  albumIds,
			  titles, 
			  recordFormats, 
			  datePublisheds, 
			  paths, nAlbum, 
              selectedIdx - 1
   );
}
void formatAlbumPath(char albumFormat[]){
	
}
bool validateAlbumPath(const char path[]){
	//ALbum must start with A->Z:\ no special char
	
	//https://en.wikipedia.org/wiki/Filename
	if(!isalpha(path[0]) || path[1] != ':' || path[2] != '\\'){
		cerr << "Error please input a valid drive!\a";
		return false;
	}
	char notAllowedChars[] = {
	  '/', '?', '%', '*', ':', '|', '"', '.', '>', '<', ',', ';', '=' };
	
    bool lastSlash = true;
    
    int i;
    for(i=3;i<strlen(path);i++){
    	for(int j=0;j<strlen(notAllowedChars);j++){
    		if(path[i] == notAllowedChars[j]){
    			cerr <<  "Not allowed character!:\a error at =>"<< path[i]<<"\n"<< path[i];
    			
    			return false;
			}
		}
		if(path[i] == '\\'){
		    if(lastSlash == true){
				cerr << "Error empty directory name!\a => " << i +1 <<"th character " <<  path[i]<< " ";
				return false;
			} //else lastSlash = true;
			lastSlash = true;
		}
		else lastSlash = false;
	}
	if(i<3) return false;
	return true;
}
void getAlbumPath (char albumPath[]){
	cout << "Get album path: ";
	
	bool isValid = false;
	do{
	
	   cin>>albumPath;
	   isValid = validateAlbumPath(albumPath);
	   if(!isValid) cout << "Retry!: ";
    }while(!isValid);
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
    cout << "Input Albums format: ";
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
    if(strlen(albumTitle) > MAX_TITLE_LEN){
    	cerr << "This length is too much!\a Input a shorter one!";
    	return false;
	}
	//for(int i =0;i<strlen(albumTitle);i++)
	//{
		//if(!(albumTitle[i] >= 'a' && albumTitle[i] <= 'z') || !(albumTitle[i] >= 'A' && albumTitle[i] <= 'Z')) return false;
	//}
	return true;
}
void getAlbumTitle (char title[]){
	cout << endl <<"Input Album title: "<<endl;
	bool isValid;
	do{
	   cin >> title;
	   isValid = validateAlbumTitle(title);
	   if(!isValid) cerr <<endl << "Error in album title Renter correctly: "<<endl;
	  // if(strlen(title) > MAX_TITLE_LEN) cerr<< "TOO MUCH LENGTH!";
    }while(!isValid || strlen(title) > MAX_TITLE_LEN);
    formatAlbumTitle(title);
}
bool validateAlbumDate(char date[10]){
	unsigned int day,  month, year;
	char dayS[3]={}, monthS[3] ={}, yearS[5]={};
	
	if(date[2] != '/' || date[5] != '/' || strlen(date) != 10){
		cerr << "Error in date format!\a retry! in dd/mm/YYYY format: ";
		return false;
	}
	//substr()
	//substring(date, dayS, 0, 2);
	//substring(date, monthS, 3, 2);
	//substring(date, yearS, 6, 4);
	memcpy(dayS, date, 2);
	memcpy(monthS, date + 3, 2);
	memcpy(yearS, date+6, 4);
	
    day = atoi(dayS);
    month = atoi(monthS);
    year = atoi(yearS);
    
	cout <<"Day: " << dayS << " Month: " << month << " Year: " << year <<endl;

	bool is = day <= 31 && month <= 12 && year < 2022 && day > 0 && month > 0 && year >0;
    if(!is) cerr << "Error this date in not valid\a retry!:  ";
    return is;
}
void getAlbumDate (char albumDate[10]){
	// dd/mm/YYYY
	cout << "Input date in dd/mm/YYY format please: ";
     char tempDate[10] = {};
	bool isValid;
	do{
	  
	   cin >> tempDate;
	   isValid = validateAlbumDate(tempDate);
    }while(!isValid);
	strcpy(albumDate, tempDate);
	//cin >> albumDate;
}
void getAlbumInfo (char titles[],char recordFormats[], char datePublished[], char paths[]){
    //cout << "HEre";
    
	getAlbumTitle(titles);

	getAlbumFormat(recordFormats);
	
	getAlbumDate (datePublished);

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
	  char datePublisheds[][DATE_MAX_LEN], 
	  char paths[][MAX_PATH_LEN], 
	  int & nAlbum
){
	static int nId =0;
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
	if(selectedIdx == -1) return false;
	char albumTitle[MAX_TITLE_LEN] = {};
	char format[MAX_FORMAT_LEN] = {};
	char datePublished[DATE_MAX_LEN] = {};
	char path[MAX_PATH_LEN]= {};
	//cout <<"Here";
	getAlbumInfo (albumTitle, format,  datePublished, path);
	
	
	cout <<endl <<endl <<"Adding Title: " <<albumTitle<< " format " << format <<endl <<endl; 
	strcpy(artistIdsRef[nAlbum], artistIds[results[selectedIdx -  1]]);
	char tmp[MAX_ID_LEN] = {};
	sprintf(tmp, "alb%d", nId); //albums have alb* text 
	strcpy(albumIds[nAlbum], tmp); 
	strcpy(titles[nAlbum], albumTitle); 
	strcpy(recordFormats[nAlbum], format); 
	strcpy(datePublisheds[nAlbum], datePublished); 
	strcpy(paths[nAlbum], path); 
    nAlbum ++;
	///getAlbumFormat(format);
	nId++;
	sortAlbum(artistIdsRef, albumIds, titles, recordFormats,datePublisheds, paths,  nAlbum);
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
	cout << "ID search Searching for " << targetId<<endl;
	int resLen=0;
	char tmpStore[8] ={};
	memset(tmpStore, '\0', 8); //clear the junk
	
	for(int i=0;i<nAlbum;i++){
		/*for(int j=0, k=0;j< MAX_ID_LEN;j++,k++){ //jump 3 because of 'art'  prefix
			tmpStore[k] = artistIdsRefs[i][j];
	    	
            if(stricmp(tmpStore, targetId) == 0){
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
	
		//cout <<" Relen ptr : " <<*noResult<<" " <<endl;*/
		cout << artistIdsRefs[i] << " vs " <<targetId <<endl;
		if(stricmp(artistIdsRefs[i], targetId) == 0){
			cout << "Found match " << artistIdsRefs[i] <<endl; 
			result[resLen] = i;
			resLen++;
		}
	}
	*noResult = resLen;
	
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
void displayOneAlbum(
          const char artistIdsRef[], 
		  const char albumIds[], 
		  const char titles[], 
		  const char  recordFormats[], 
		  const char datePublisheds[], 
		  const char paths[]
){
     cout  << ") ID: " << albumIds << " Owner " << artistIdsRef<<" Title: " <<titles << " Format: " <<recordFormats <<  " Date Published: " <<datePublisheds <<  " Paths: " <<paths <<endl;	
}
void displayAllAlbum(
		const char artistNames[][MAX_NAME_LEN], 
		const char artistIdsRef[][8], 
		const char albumIds[][8], 
		const char titles[][80], 
		const char recordFormats[][20], 
		const char datePublisheds[][11], 
		const char paths[][100], 
		int nAlbum
){
	if(!nAlbum){
		cerr << "No albums found!" <<endl;
		return;
	}
	for(int i=0;i<nAlbum;i++){	 
	   cout << i + 1;
	   displayOneAlbum(
           artistIdsRef[i], 
		  albumIds[i], 
		  titles[i], 
		  recordFormats[i], 
		  datePublisheds[i], 
		  paths[i]
    );
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
		cout << "  Album Id: " <<albumIds[i] <<" Owner's name: " << name << "  Owner's Id: " << artistIds << "  Title "<<titles[i];
		cout <<"]"<<endl; 		
	    res++;
	 }
 }
 if(res==0) cout <<endl<< "No ALBUMS FOUND!"<<endl;      

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
	int &nAlbum
)
{
	int results[1000]={}, noResult=0;
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
	if(selectedIdx == -1) return;
	int res2[1000]={};
	searchAlbumByArtistId(
              artistIdsRef, 
			   nAlbum, 
			   artistIds[results[selectedIdx - 1]], //must contain art 
			   res2,
			   &noResult
    );
    selectedIdx = selectAlbum(
	    artistIds, 
	    titles, 
	    res2, 
        noResult
    );
    if(selectedIdx == -1 )return;
    editAlbumInfo(
         artistIdsRef[res2[selectedIdx - 1]], 
		  albumIds[res2[selectedIdx - 1]], 
		  titles[res2[selectedIdx- 1]], 
		   recordFormats[res2[selectedIdx - 1]], 
		  datePublisheds[res2[selectedIdx - 1]], 
		  paths[res2[selectedIdx - 1]]
     );
     sortAlbum(artistIdsRef, albumIds, titles, recordFormats, datePublisheds, paths, nAlbum);
		
}
