#include "artist.h"
#include "Const.h"

#include <iostream>
#include <string>
#include <sstream>

int nArtist=0, nAlbum=0;

using namespace std;

bool Album_manager();
int Album_editor();
int Artist_manu();
bool Artist_manager();
int main_menu(int);
bool is_digits(const std::string &str);

int main()
{
	char artistNames[NUMBER_OF_ARTIST_MAX][MAX_NAME_LEN] = {};
    char artistIds[NUMBER_OF_ARTIST_MAX][ MAX_ID_LEN] = {};
    char artistPhoneNumbers[NUMBER_OF_ARTIST_MAX][PHONE_LEN_MAX] = {};
    char artistGenders[NUMBER_OF_ARTIST_MAX] = {};
    char artistEmails[MAX_EMAIL_LEN][MAX_EMAIL_LEN]={};

    char albumIds[NUMBER_OF_ARTIST_MAX * 10][MAX_ID_LEN] = {}; // This so because every arist can have 10 albums on average. 
    char albumOwnerIds[NUMBER_OF_ARTIST_MAX * 10][MAX_ID_LEN] = {};
    char albumTitles[NUMBER_OF_ARTIST_MAX * 10][MAX_TITLE_LEN] = {};
    char albumFormats[NUMBER_OF_ARTIST_MAX * 10][MAX_FORMAT_LEN] ={};
    char albumPublishedDates[NUMBER_OF_ARTIST_MAX * 10][DATE_MAX_LEN] = {};
    //char dummy;
    char albumPaths[1000][MAX_PATH_LEN];
    int mai,nAlbum=0,x;
    bool exit_=true;
    cout<<"1. main manager\n2. exit\n";
    x=main_menu(2);

    switch (x){
    case 1:{
        cout<<"main menu\n";
        cout<<"1. Artist managemener\n2. Album managemener\n3.main\n4.Exit\n";
        mai= main_menu(4);

        if(mai==1){
            cout<<"Artist manager\n";
            exit_= Artist_manager();
           if(!exit_){
            return 0;
           }
        }
        else if (mai==2){
            cout<<"Album manager\n";
           exit_ = Album_manager();
           if(!exit){
            return 0;
           }
        }
        else if(mai=3)main();
        else return 0;
        break;
            }
    case 2:{
       return 0;
        break;
        }

    default :
       {
        cout<<"wrong input\n";
        break;
       }
    }

}
int Artist_manu(){
    int choi;
        cout<<"1.Display_all\n2.Veiew artist_by _search\n3.return_main\n4. exit\n";
        choi=main_menu(4);

        return choi;
}
//void search_artist(){
//    int choise;
//    cout<<"1.by_name\n2. by_ID\n";
//    do{
//        cout<<" enter again: ";
//        cin>>choise;
//        if (choise<1||choise>2)cout<<"Erorr \n ";
//    }while(choise<1||choise>2);
//    if (choise==1){
//            cout<<"by_name\n";
//            srerchArtist();
//                }
//    else{
//            cout<<"by_ID";
//
//    }

//}
int Artist_editor(){
    int x;
    cout<<"1.Add_Artist\n2.Artist_edit\n3.Delet_Artist\n4.return_to_main\n5.Exit\n";
    x=main_menu(5);
}
bool Artist_manager(){
    int choise_art,choise,choise_View,choise_edit;
    cout<<"1. Artist_view\n2.rutern_to_mian\n3. Exits\n";
    choise=main_menu(3);
    if (choise==3){return false;}
    else if(choise==1){
            cout<<"1. artist view\n2. artist edit\n3.exti\n4.return_to_main\n";
        choise_art=main_menu(4);//here
        if (choise_art==1){
            cout<<"Artist_view\n";
            choise_View=Artist_manu();
            if(choise_View==1){
                cout<<"display_All\n";
            }
            else if(choise_View==2){
                cout<<"Veiew artist_by _search\n";
                //search_artist();
            }
            else return 0;

        }
        else if(choise_art==2){
            cout<<"Artist_edit\n";
            choise_edit= Artist_editor();
                if(choise_edit=1){
                    cout<<"Add\n";
                }
                else if (choise_edit=2){
                    cout<<"Edit_Artist\n";
                }else if(choise_edit=3){
                    cout<<"Delete_Artist\n";
                }
                else if(choise_edit==4){
                    main();
                }
                else return 0;
        }
        else if(choise_art==4) main();
        else{
            return 0;
        }
    }
    else {
        cout<<"main\n";
        main();
    }
}
// Album part
int Album_editor(){
    int x;
    cout<<"1.Add_Album\n2.Album_edit\n3.Delet_Album\n4.return_to_main\n5.Exit\n";
    x=main_menu(5);
}
int album_manu(){
    int choise;
        cout<<"1. almbum view\n2. Album edit\n3. exti\n4. return_to_main\n";
        choise=main_menu(4);
        return choise;
}
bool Album_manager(){

    int choise_art,choise,choise_View,choise_edit;
    cout<<"1. album_view\n2.rutern_to_mian\n3. Exits\n";
    choise=main_menu(3);
    if (choise==3){return false;}
    else if(choise==1){

        choise_art=album_manu();//here
        if (choise_art==1){
            cout<<"Album_view\n";
            choise_View=album_manu();
            if(choise_View==1){
                cout<<"display_All_album\n";
                //SearchArtistNameById();
            }
            else if(choise_View==2){
                cout<<"Veiew Album_by _search\n";
                //search_artist();
                //selectArtist();
                //SearchAlbumByArtistId();
                //displaSearchAlbumResult();
            }
            else return 0;

        }
        else if(choise_art==2){
            cout<<"Album_edit\n";
            choise_edit=Album_editor();
                if(choise_edit=1){
                    cout<<"Add_Album\n";
                }
                else if (choise_edit=2){
                    cout<<"Edit_Album\n";
                }else if(choise_edit=3){
                    cout<<"Delete_Album\n";
                }
                else if(choise_edit==4){
                    main();
                }
                else return 0;
        }
        else if(choise_art==4) main();
        else{
            return 0;
        }
    }
    else {
        cout<<"main\n";
        main();
    }
}




int main_menu( int y){

    string choise="0";
    bool is_number;
    int x;

    string tmpS;
    int tmpI;
    cout<<"Enter your choise: ";

    do{
        do{
        is_number=true;
//          cin.clear();
//        cin.ignore(1000,'\n');
//        getline(cin,choise);
            cin >> choise;
         if (!is_digits(choise)){
                cout<<"your input is wrong enter again: ";
            }
        }while(!is_digits(choise));
        int tmpI;
		stringstream IntIn(choise);
		IntIn >> tmpI; 
		//cout <<tmpI <<" "<<choise<<" dsid \n";
        if(tmpI < 1 || tmpI > y){
            cout<<"enter corret choise again: ";
        }
    }while(tmpI < 1 || tmpI>y);
    cout<<"thankyou\n";
    return tmpI;

}
bool is_digits(const std::string &str)
{
   return str.find_first_not_of("0123456789") == std::string::npos;
}
