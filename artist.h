int selectArtist(
    const char artistIds[][8], 
	const char names[][40], 
	const int result[], 
	int noResult, 
	int forWhat 
){
    cout << "MMA "<<noResult << " ";
	if(forWhat == 2) cout <<"Please select a specific artist to deleted:\nName     Id "<<endl;
	return -1;
	for(int i=0;i<noResult;i++){
		cout << i + 1<<") " <<names[i]<< "    "<<artistIds[i]<<endl;
	}
	cout <<endl;
	int res;
	cin>>res;
	if(result == 0){
		cerr << "No results with this Id found!";
		return -1;
	}
	return res;
}
void removeArtist(
    char artistId[][8], 
	char  name[][40], 
	char phone[][11],
	char email[][80], 
	int selectedIdx, 
	int & nArtist){
	
}
void removeArtistAllAlbums(
    const char artistId[], 
	char artistIdsRefs[][8], 
	char albumIds[][8], 
	char titles[][80], 
	char recordFormats[][20], 
	char datePublished[][11], 
	char paths[][100],  
	int & nAlbum
){
	
}
