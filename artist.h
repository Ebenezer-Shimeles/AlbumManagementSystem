#include <cstring> //for strcpy function
#include <cstdlib> //for memset function
#include <string>
#include <cstdio>
#include <iostream>



#include "Const.h"

using namespace std;
void removeArtist(
                  char artistIds[][8],
                  char  name[][40], 
				  char phone[][11],
				  char email[][80], 
				  int selectedIdx, 
				  int & nArtist
);
void removeAlbum(
              char artistIdsRef[][8], 
			  char albumIds[][8],
			  char  titles[][80], 
			  char recordFormats[][20], 
			  char datePublisheds[][11], 
			  char paths[][100], int & nAlbum, 
              int selectedIdx
);
void removeArtistAllAlbums(
             const char artistId[8], 
			 char artistIdsRefs[][8], 
			 char albumIds[][8], 
			 char titles[][80], 
			 char recordFormats[][20], 
			 char datePublished[][11], 
			 char paths[][100],  
			 int & nAlbum);

void searchArtistById(
             const char artistIds[][8], 
			 int nArtist, 
			 const char targetId[],  
			 int result[], 
			 int * noResult
);
void searchArtist(
            const char artistIds[][8], 
			const char names[][40], 
			int nArtist, 
			int result[], 
			int * noResult
);
void searchArtistByName(
            const char names[][40], 
			int nArtist, 
			const char targetName[],  
			int result[], 
			int * noResult
);

void getArtistInfo(
    char artistId[MAX_ID_LEN],
	char artistName[MAX_NAME_LEN],
	char &artistGender,
	char artistPhoneNumber[PHONE_LEN_MAX], 
	char artistEmail[MAX_EMAIL_LEN], int nArtist
);
void editArtist(
           const char artistIds[][8], 
		   char names[][40], 
		   char genders[], 
		   char phones[][11], 
		   char emails[][80], 
		   int nArtist
);
bool editArtistInfo(
       const char artistId[], 
	   char name[], 
	   char &gender, 
	   char phone[],
	   char email[]
);
bool addArtist(
           char artistIds[][8], 
		   char names[][40], 
		   char genders[], 
		   char phones[][11], 
		   char emails[][80], 
		   int & nArtist
);
int selectArtist(
    const char artistIds[][8], 
	const char names[][40], 
	const int result[], 
	int noResult, 
	int forWhat 
);
void searchArtistByName(
            const char names[][40], 
			int nArtist, 
			const char targetName[],  
			int result[], 
			int * noResult
);
void displaySearchResult(
             const char artistIds[][8], 
			 const char names[][40], 
			 const char genders[], 
			 const char phones[][11], 
			 const char emails[][80], 
			 int nArtist, 
			 const int result[], 
			 int noResult
);
void displayAllArtist(
               const char artistIds[][8], 
			   const char names[][40], 
			   const char genders[], 
			   const char phones[][11], 
			   const char emails[][80], 
			   int nArtist
);
void displayOneArtist(
       const char artistId[], 
	   const char name[], 
	   char  gender, 
	   const char phone[], 
	   const char email[]
);
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
);



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


void searchArtist(
            const char artistIds[][8], 
			const char names[][40], 
			int nArtist, 
			int result[], 
			int * noResult
){
	char choice; 
	cout << "Searching artist.."<<endl;
    cout << "Do you want to search by \nA)ID or B)Name:  ";
    cin >> choice;
    int results[1000]; // This is where the results are stored
    //int *numberOfResults;
    if(choice == 'A' || choice == 'a'){
    	//Search by Id
    	char targetId[MAX_ID_LEN] = {};
    	
    	cout <<endl << "Input the id please: ";
    	
    	cin >>targetId;
    	cout <<endl<< "The target ID is: "<<targetId<<endl;
        //*noResult = 10;	
    	//return;
    	//all Fine
    	searchArtistById(
             artistIds, 
			 nArtist, 
			 targetId,  
			 result, 
			 noResult
        );
        //noResult[0] = 10004;
        //cout << "Result length search: "<< *noResult << endl;
        //cout <<"Wait please";
	}
	else if(choice == 'B' || choice == 'b'){
		char targetName[MAX_NAME_LEN];
		cout <<"Input the prefix name: ";
		cin >>targetName;
		searchArtistByName(
            names, 
			nArtist, 
			targetName,  
			result, 
			noResult);
	}
	else{
        cerr << "Error in choice!\a";
        exit(-1);
    }
    
}
void searchArtistById(
             const char artistIds[][8], 
			 int nArtist, 
			 const char targetId[],  
			 int result[], 
			 int * noResult
){
	//*noResult = 100;
	cout << "Searching for " << targetId<<endl;
	int resLen=0;
	char tmpStore[8];
	memset(tmpStore, '\0', 8); //clear the junk
	
	for(int i=0;i<nArtist;i++){
		for(int j=3, k=0;j< MAX_ID_LEN;j++,k++){ //jump 3 because of 'art'  prefix
			tmpStore[k] = artistIds[i][j];
			cout <<tmpStore << " vs " <<targetId <<endl;
            if(strcmp(tmpStore, targetId) == 0){
            	//cout <<endl<<tmpStore<<" = "<<targetId << "i="<<i<<" j="<<j;
            	result[resLen] = i;
            	resLen++;
            	//cout <<endl<<"Reslen : "<<resLen;
            	
            	cout << endl << "Found match: " << artistIds[i] << " & " << targetId<<endl; 
            	//memset(tmpStore, '\0', 8);
            	break;
			}			
		}
		memset(tmpStore, '\0', 8);
	
		//cout <<" Relen: " <<resLen<<" " <<endl;
		*noResult = resLen;
		//cout <<" Relen ptr : " <<*noResult<<" " <<endl;
	}
	//cout << "Done searching by ID" <<endl;
}
void searchArtistByName(
            const char names[][40], 
			int nArtist, 
			const char targetName[],  
			int result[], 
			int * noResult){
	int resLen=0;
	char tmpStore[8];
	for(int i=0;i<nArtist;i++){
		for(int j=0;j<8;j++){
			tmpStore[j] = names[i][j];
            if(strcmp(tmpStore, targetName) == 0){
            	//cout <<endl<<tmpStore<<" = "<<targetId << "i="<<i<<" j="<<j;
            	result[resLen] = i;
            	resLen++;
            	//cout <<endl<<"Reslen : "<<resLen;
            	for(int k=0;k<8;k++) tmpStore[k] = '\0';
            	break;
			}			
		}
		for(int j=0;j<8;j++) tmpStore[j] = '\0';
		//cout <<" Relen: " <<resLen<<" ";
		//*noResult = resLen;
	}
	*noResult = resLen;
}

void formatEmail (char email[]){
	if(email[0] >= 'a') email[0] -= 'a' - 'A';
}
bool validateEmail (const char email[]){
	//of the form eben@  <-as @and head blah.com -<foot
	if(strlen(email) > MAX_EMAIL_LEN){
		cerr <<endl << "Error the length is big!"<<endl;
		return false;
	}
	bool hasAt =  false;
	bool hasDot = false;
	bool hasFoot = false;
	int i, j=0;
    //char tmp[MAX_EMAIL_LEN];
	for(i=0;i<strlen(email);i++){
		if(email[i] == '@' && i > 0){
	       hasAt= true;
		   break; 
		}
	}
	for(;i<strlen(email);i++, j++){
		if(email[i] == '.' && j> 0){
		   hasDot = true;
		   break;
	    }  
	}
	if(i < strlen(email) - 1) hasFoot = true;
	return hasAt && hasDot && hasFoot;
      
}



void getArtistEmail (char email[]){

	
	char artistEmail[MAX_EMAIL_LEN] = {};
	bool isValid = false;
	while(!isValid){
		cout <<endl << "Input the artist's email"<<endl;
		cin >>artistEmail;
	    isValid  = validateEmail(artistEmail);	
	    if(!isValid) cerr<<endl<<"Invalid email!"<<endl;
	}
	formatEmail(artistEmail);
	strcpy(email, artistEmail);
}



bool validatePhone (const char phone[]){
	//cout <<"Here";
	if(strlen(phone ) > PHONE_LEN_MAX) return false;
	for(int i=0;i<strlen(phone);i++){
		if(!(phone[i] >= '0' && phone[i] <= '9')) return false;
	}
	
	return true;
}



void getArtistPhone (char phone[]){
	char phoneNumber[PHONE_LEN_MAX] = {};
	bool isValid = false;
	while(!isValid){
	
	    cout <<endl <<"Please input phone number"<<endl;
	    cin>>phoneNumber;
	    isValid = validatePhone(phoneNumber);
	    if(!isValid) cerr << endl<<"Please input a valid  number";
    }
    strcpy(phone, phoneNumber);
	
}


bool validateGender( char gender){
	return gender == 'F' || gender == 'M';
}



char getArtistGender(){
	bool isValid = false;
	char gen;
	while(!isValid){
	
	    cout <<endl<<"Please input geneder" <<endl <<" Male ->M Female ->F: ";
     	cin >>gen;
     	isValid = validateGender(gen);
    }
    return gen;
	
}



bool validateName (const char name[]){
	if(strlen(name) > MAX_NAME_LEN){ //to prevent overflow
		cerr <<endl<< "Name is greater than maximum"<<endl;
		return false;
	}
	int noWhite = 0;
	for(int i=0;i<strlen(name);i ++){
        if(!(name[i] >= 'A' && name[i] <= 'Z') && !(name[i] >= 'a' && name[i] <= 'z') && name[i] != ' ' ){
	         cout << "Failled here => " << name[i];
			 return false;
		}
		if(name[i] == ' ' && i != 0 & i != strlen(name) - 1) {
		//	     cout << "White at " <<i;
				 noWhite++;
		} 
        // else cout << name[i] << " is not a whitespace "<<endl;
		//only checks if it is alphabetic A-Za-z	
	    //cout <<endl<<"checking"<<endl;
	}
	//cout <<"TMP";
	if(noWhite >= 1) return true;
	cout <<  "This is not a full name please input the full name";
	return false;
}



void formatName (char name[]){
	int i=0;
	for(;name[i]==' ';i++);  //jump whitelines
	if(name[i] >= 'a') name[i] -= ('a' -  'A'); //capitalize
 	for(;name[i]!=' ';i++);
	for(;name[i]==' ';i++);  //jump whitelines
	if(name[i] >= 'a') name[i] -= ('a' -  'A'); //capitalize
}



void getArtistName (char name[]){
	bool isValid = false;
	while(!isValid){
		//cout << "isValid " <<isValid;
	    string str;
	    char tmpName[MAX_NAME_LEN] = {};
	    cout << "\nPlease input the artist Name\n";
	    getline(cin,str);
	    memcpy(tmpName, str.c_str(), str.size());
	    //cout << "Tmp Name " <<tmpName;
	    isValid = validateName(tmpName);
	    if(isValid) strcpy(name, tmpName);
	    else{
	        cout << "\nInvalid name! retry!\n\a";
	       // getArtistName(name);
        }
   } 
   formatName(name);
	
}
void getArtistInfo(
    char artistId[MAX_ID_LEN],
	char artistName[MAX_NAME_LEN],
	char &artistGender,
	char artistPhoneNumber[PHONE_LEN_MAX], 
	char artistEmail[MAX_EMAIL_LEN], int nArtist ){
		
	strcpy(artistId, "art");
	sprintf(artistId+3, "%d", nArtist);    
    //strcpy(artistId+3, to_string(nArtist).c_str() );
    
    getArtistName(artistName);
    artistGender = getArtistGender();
    getArtistPhone (artistPhoneNumber);
    getArtistEmail (artistEmail);
}
bool addArtist(
           char artistIds[][8], 
		   char names[][40], 
		   char genders[], 
		   char phones[][11], 
		   char emails[][80], 
		   int & nArtist
){
    char artistId[MAX_ID_LEN] = {};
	char artistName[MAX_NAME_LEN] = {};
	char artistGender;
	char artistPhoneNumber[PHONE_LEN_MAX] = {};
	char artistEmail[MAX_EMAIL_LEN] = {};
	
    getArtistInfo(    
	    artistId,
        artistName,
	    artistGender,
	    artistPhoneNumber, 
	    artistEmail, nArtist
	);
    //cout << artistName << " " << artistGender << " "<<artistEmail << " "<<artistPhoneNumber;
    //return true;
    //genders[nArtist] = 'M';
    //strcpy(artistId, "12445");
	//strcpy(artistName, "Ebenezer");
	//strcpy(artistPhoneNumber, "0912701156");
	//strcpy(artistEmail, "ebenezertesfaye@yahoo.com");	
	strcpy(artistIds[nArtist], artistId);
	strcpy(names[nArtist], artistName);
	genders[nArtist] = artistGender;
	strcpy(phones[nArtist], artistPhoneNumber);
	strcpy(emails[nArtist], artistEmail);
	nArtist++;

	 
}
void displayAllArtist(
               const char artistIds[][8], 
			   const char names[][40], 
			   const char genders[], 
			   const char phones[][11], 
			   const char emails[][80], 
			   int nArtist
){
	// Reponsibilty: only displayninh nothing else
	/*
	   I think this is complete 
	*/
	if(!nArtist){
	  cout << "No Artist are stored!";
	  return;
    }
    for(int i=0;i<nArtist;i++){
    	cout << i+1 << ") ";
    	cout << "[";
        cout << "name: " <<names[i] << ", id: " << artistIds[i] <<", gender: " << genders[i] <<", phone: " << phones[i] << ", email: " << emails[i];
		cout << "]" <<endl; 
	}
}

void displaySearchResult(
             const char artistIds[][8], 
			 const char names[][40], 
			 const char genders[], 
			 const char phones[][11], 
			 const char emails[][80], 
			 int nArtist, 
			 const int result[], 
			 int noResult)
{
	cout <<endl<<"Results: "<<endl;
	for(int i=0;i<noResult;i++){
		cout << i + 1<<") " <<names[result[i]]<< "    "<<artistIds[result[i]]<<endl;
		//cout <<"result[" <<i <<  "] = "<<result[i];
	}
}
int selectArtist(
    const char artistIds[][8], 
	const char names[][40], 
	const int result[], 
	int noResult, 
	int forWhat 
){
    //cout << "MMA "<<noResult << " ";
	if(forWhat == 2) cout <<"Please select a specific artist to deleted: "<<endl;
    else if(forWhat == 1) cout << "Please select a specific artist to be edited: "<<endl;
	cout <<endl;
	int res;
	cin>>res;
	if(result == 0){
		cerr << "No results with this Id found!";
		return -1;
	}
	return res;
}

void displayOneArtist(
       const char artistId[], 
	   const char name[], 
	   char  gender, 
	   const char phone[], 
	   const char email[]
){
     	cout << "Id: " << artistId <<endl;
     	cout << "Name: " << name <<endl;
     	cout << "Gender: " << gender <<endl;
        cout << "Phone: " << phone <<endl;
     	cout << "Email: " << email <<endl;
}
void do_nothing(){
}
bool editArtistInfo(
       const char artistId[], 
	   char name[], 
	   char &gender, 
	   char phone[],
	   char email[]
){
	char newName[MAX_NAME_LEN] = {}, newGender, newPhone[PHONE_LEN_MAX]={}, newEmail[MAX_EMAIL_LEN] = {};
	string tmp;
	cout << endl <<"Enter '-' to skip editing field";
	cout <<endl << "Input the new name please: ";
	getline(cin, tmp);
	strcpy(newName, tmp.c_str());
	cout <<endl << "Input the new gender please: ";
	bool isGoodGender = false;
	while(!isGoodGender) {
		cin >> newGender;
		if(newGender == 'M' || newGender == '-' || newGender == 'F') isGoodGender = true;
		else cout << "\nPlease input M or F !\a";
	}
	cout <<endl << "Input the new phone number pleas: ";
	cin >> newPhone;
	cout <<endl<<"Input the new email please: ";
	cin >>newEmail;
	
	if(strcmp(newName, "-") != 0){
		memset(name, '\0', MAX_NAME_LEN);
		strcpy(name, newName);
	}
	if(newGender != '-'){
		//memset(name, '\0', MAX_NAME_LEN);
		//strcpy(name, newName);
		gender = newGender;
	}
	if(strcmp(newPhone, "-") != 0){
		memset(phone, '\0', PHONE_LEN_MAX);
		strcpy(phone, newPhone);
	}
	if(strcmp(newEmail, "-") != 0){
		memset(email, '\0', MAX_EMAIL_LEN);
		strcpy(email, newEmail);
	}
	cout << "The new artist infos: \n";
    displayOneArtist(
       artistId, 
	   newName, 
	   newGender, 
	   newPhone, 
	   newEmail
    );

}
void editArtist(
           const char artistIds[][8], 
		   char names[][40], 
		   char genders[], 
		   char phones[][11], 
		   char emails[][80], 
		   int nArtist
){
	int noResult;
	int results[1000];
     searchArtist(
            artistIds, 
			names, 
			nArtist, 
			results, 
			&noResult
   );
   cout << "  Results Number: "<<noResult;
   displaySearchResult(
             artistIds, 
			 names, 
			 genders, 
			 phones, 
			 emails, 
			 nArtist, 
			 results, 
			 noResult
   );	
  int selected =  selectArtist(
    artistIds, 
	names, 
	results, 
	noResult, 
	1 
  );
  char g = 'A';
  editArtistInfo(
               artistIds[selected - 1], 
			   names[selected - 1],
			   
			   genders[selected - 1], 
			   //genders[selected - 1], 
			   phones[selected - 1 ], 
			   emails[selected - 1]
  );
}
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

