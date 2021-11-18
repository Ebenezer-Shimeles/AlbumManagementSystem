#include <iostream>

#include "Const.h"
#include "utils.h"
#include "artist.h"
//#include "searchArtist.h"
#include "removeArtist.h"


using namespace std;
void deleteArtist(
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
    // Responsibility:	Handles delete choice.
    int result[1000];
    int noResult;
    
    searchArtist(
            artistIds, 
			names, 
			nArtist, 
			result, 
			&noResult
   );
   //cout << "Here" <<endl;
   if(noResult == 0){
   	cout <<"Nothing found!\a";
   	exit(0);
   }
   cout << endl<<"Number of results : " << noResult<<endl;
   //exit(0);
   
   for(int k=0;k<noResult;k++)
       cout <<"Found at index: " << k << " Result: " << artistIds[k]<<endl;
   //ALL FINE UP TO HERE

   displaySearchResult(
             artistIds, 
			 names, 
			 genders, 
			 phones, 
			 emails, 
			 nArtist, 
			 result, 
			 noResult);
   int selectedIdx = selectArtist(
        artistIds, 
	    names, 
	    result, 
	    noResult, 
	     2 
	);
	cout << "You selected " << selectedIdx;
	if(selectedIdx > noResult || selectedIdx < 1){
		cerr << "Err in choice !";
		exit(-1);
	}
	//cout <<"HERE";
	removeArtistAllAlbums(
       artistIds[selectedIdx - 1], 
	   artistIdsRefs, 
	   albumIds, 
	   titles, 
	   recordFormats, 
	   datePublished, 
	   paths,  
	   nAlbum
	);
	removeArtist(
        artistIds, 
	    names, 
	    phones,
	    emails, 
	    selectedIdx - 1, 
	    nArtist
	);
//	cout <<endl<<"Sure! "<<selectedIdx - 1;
	
	cout <<"\nDone!";
}
bool testDeleteArtist(){
	cout << "HELLO";
}
