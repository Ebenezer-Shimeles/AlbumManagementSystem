#include <iostream>

#include "Const.h"
#include "utils.h"
#include "artist.h"
#include "searchArtist.h"

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
    int *noResult;
    
    searchArtist(
            artistIds, 
			names, 
			nArtist, 
			result, 
			noResult
   );
   int selectedIdx = selectArtist(
    artistIds, 
	names, 
	result, 
	*noResult, 
	2 );
	
	removeArtist(
    artistIds, 
	names, 
	phones,
	emails, 
	selectedIdx, 
	nArtist);
	
	removeArtistAllAlbums(
       artistIds[selectedIdx], 
	   artistIdsRefs, 
	   albumIds, 
	   titles, 
	   recordFormats, 
	   datePublished, 
	   paths,  
	   nAlbum);
	cout <<"\nDone!";
}
bool testDeleteArtist(){
	cout << "HELLO";
}
