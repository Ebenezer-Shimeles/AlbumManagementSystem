#include <iostream>
#include <cstring>
#include <cstdlib>

#include "Const.h"

using namespace std;
void removeArtist(
                  char artistIds[][8],
                  char  name[][40], 
				  char phone[][11],
				  char email[][80], 
				  int selectedIdx, 
				  int & nArtist
){
    if(nArtist < selectedIdx || selectedIdx < 0){
		cerr << "Index length greater than data length"<<endl;
		return;
	}
	cout << "Selected Id :" <<selectedIdx<<endl;
	//Zero out fields to overwrite
	memset(artistIds[selectedIdx], '\0', MAX_ID_LEN);
	memset(name[selectedIdx], '\0', MAX_NAME_LEN);
	memset(phone[selectedIdx], '\0', PHONE_LEN_MAX);
	memset(email[selectedIdx], '\0', MAX_EMAIL_LEN);
	
	if(selectedIdx + 1 == nArtist) //deleting the last one
	{
		nArtist--;
	    return;  //no need to colapse
	}
	///if(selectedIdx + 1 == nArtist) return; //IF it is deleteing the last one
	for(int i=selectedIdx;i<nArtist;i++){ //colpase
			memset(artistIds[i], '\0', MAX_ID_LEN);
	        memset(name[i], '\0', MAX_NAME_LEN);
	        memset(phone[i], '\0', PHONE_LEN_MAX);
	        memset(email[i], '\0', MAX_EMAIL_LEN);
	
		    strcpy(artistIds[i], artistIds[i+1]);
		    strcpy(name[i], name[i+1]);
		    strcpy(phone[i], phone[i+1]);
		    strcpy(email[i], email[i+1]);
	}
    nArtist--;
}
void removeAlbum(
              char artistIdsRef[][8], 
			  char albumIds[][8],
			  char  titles[][80], 
			  char recordFormats[][20], 
			  char datePublisheds[][11], 
			  char paths[][100], int & nAlbum, 
              int selectedIdx
){
	//cout <<"HI";
	 if(nAlbum < selectedIdx || selectedIdx < 0){
		cerr << "Index length greater than data length -Remove ALbum"<<endl;
		return;
	}
	cout << "Deleting Album :" <<selectedIdx<<endl;
	
	//Zero out fields to overwrite
	memset(artistIdsRef[selectedIdx], '\0', MAX_ID_LEN);
	memset(albumIds[selectedIdx], '\0', MAX_ID_LEN);
	memset(titles[selectedIdx], '\0',  MAX_TITLE_LEN);
	memset(datePublisheds[selectedIdx], '\0', DATE_MAX_LEN);
	//memset(phone[selectedIdx], '\0', PHONE_LEN_MAX);
	memset(paths[selectedIdx], '\0', MAX_PATH_LEN);
	
	if(selectedIdx + 1 == nAlbum) //deleting the last one
	{
		nAlbum--;
	    return;  //no need to colapse
	}
	///if(selectedIdx + 1 == nArtist) return; //IF it is deleteing the last one
	for(int i=selectedIdx;i<nAlbum;i++){ //colpase
		    memset(artistIdsRef[selectedIdx], '\0', MAX_ID_LEN);
	        memset(albumIds[selectedIdx], '\0', MAX_ID_LEN);
	        memset(titles[selectedIdx], '\0',  MAX_TITLE_LEN);
	        memset(datePublisheds[selectedIdx], '\0', DATE_MAX_LEN);
	//memset(phone[selectedIdx], '\0', PHONE_LEN_MAX);
	        memset(paths[selectedIdx], '\0', MAX_PATH_LEN);
	
		    strcpy(artistIdsRef[i], artistIdsRef[i+1]);
		    strcpy(albumIds[i], albumIds[i+1]);
		    strcpy(titles[i], titles[i+1]);
		    strcpy(datePublisheds[i], datePublisheds[i+1]);
	}
    nAlbum--;
}
void removeArtistAllAlbums(
             const char artistId[8], 
			 char artistIdsRefs[][8], 
			 char albumIds[][8], 
			 char titles[][80], 
			 char recordFormats[][20], 
			 char datePublished[][11], 
			 char paths[][100],  
			 int & nAlbum)
{
	//cout <<"\n SWAE LEE SUNFLOWER" <<endl;
	int i,cmp;
	//cout <<"SURE2 "<<artistIdsRefs[0] <<endl;
   	for( i=0;i<nAlbum;i++){
   	    cmp = strcmp(artistId, artistIdsRefs[i]);
   	   	cout <<endl << artistId << " == ";
		cout << artistIdsRefs[i] << " " << cmp << endl;
		//continue;
   	    if(cmp == 0){
   	    	cout << "Found Match "<<endl;
   	    	
   	       removeAlbum(
              artistIdsRefs, 
			  albumIds,
			  titles, 
			  recordFormats, 
			  datePublished, 
			  paths, nAlbum, 
              i
           );	
		}
   }

		//cout <<"LOOP";
}

