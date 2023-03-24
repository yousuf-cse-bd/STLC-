/**
 * @file ListChallengeSec2.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Create a menu driven app that will simulate a user playing from a playlist of songs
 * @version 0.1
 * @date 2023-03-24
 * @since FriDay; 03:15 PM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
#include <iostream>
#include <string>
#include <string_view>
#include <algorithm>
#include <iomanip>
#include <list>
#pragma pack(1)
using namespace std;

class Song{
	friend ostream &operator<< (ostream &cout, const Song &song){
		cout<<setw(25)<<left<<song.songTitle<<setw(25)<<left<<song.artistName<<setw(5)<<right<<song.rating;
		return cout;
	}
private:
	string songTitle{};
	string artistName{};
	int rating{};
	
	constexpr static const char *const defSongTitle{"Untitle"};
	constexpr static const char *const defArtistName{"Unknown"};
	constexpr static int defRating{0};
	
public:
	Song(const string_view &songTitle = defSongTitle, 
		const string_view &artistName = defArtistName, 
			const int &rating = defRating):
			songTitle{songTitle}, artistName{artistName},rating{rating}{
			/*Custom default parameterized constructor*/
		}
		
	bool operator< (const Song &rhs) const {
		return (this->rating < rhs.rating);
	}
	
	bool operator== (const Song &rhs) const {
		return((this->songTitle == rhs.songTitle) && (this->artistName == rhs.artistName)&&
		(this->rating == rhs.rating));
	}
	/*Getter methods*/
	string getSongTitle(void) const {
		return songTitle;
	}
	string getArtistName(void) const {
		return artistName;
	}
	int getRating(void) const {
		return rating;
	}
	~Song(void) = default;
};

inline char menuFunction(void){
	char selector{'\0'};
	cout<<"========================MENU========================"<<endl;
	cout<<"F - Play Frist Song"<<endl;
	cout<<"N - Play Next Song"<<endl;
	cout<<"P - Play Previous Song"<<endl;
	cout<<"A - Add and Play a New Song at Current  Location"<<endl;
	cout<<"L - List the Current Playlist"<<endl;
	cout<<"===================================================="<<endl;
	cout<<"Enter a Selection (Q to QUIT): ";
	cin>>selector;
	return selector;
}

inline void displayPlaylist(const list <Song> &playList, const Song &songNow){
	
	for_each(playList.cbegin(), playList.cend(),
		[](const Song &x){
			cout<<"[ "<<x<<" "<<"]"<<endl;
		}
	);
	
	cout<<"\n"<<setw(35)<<"$$$Playing Now$$$"<<endl;
	cout<<setfill('-');
	cout<<"[***"<<setw(25)<<left<<songNow.getSongTitle();
	cout<<setw(25)<<left<<songNow.getArtistName();
	cout<<setw(5)<<right<<songNow.getRating()<<"***]"<<endl;
	cout<<setfill(' ');
}


void playCurrentSong(const Song &songNow){ /*No copy constructor calls*/
	cout<<"\n"<<setw(35)<<"###Playing Now###"<<endl;
	cout<<setfill('-');
	cout<<"[***"<<setw(25)<<left<<songNow.getSongTitle();
	cout<<setw(25)<<left<<songNow.getArtistName();
	cout<<setw(5)<<right<<songNow.getRating()<<"***]"<<endl;
	cout<<setfill(' '); /*Reset*/
}


int main(int argc, const char *const argv[]){
    system("cls");
	list <Song> playList{
		{"God's Plan", "Drake", 5},
		{"Never Be The Same", "Camila Cabello", 5},
		{"Pray For Me", "The Weekend and K. Lamar", 4},
		{"The Middle", "Zedd, Maren Morris & Grey", 5},
		{"Wait", "Maroone 5", 4},
		{"Whatever It Takes", "Imagine Dragon", 3}
	};
	list <Song> :: iterator currentSong {playList.begin()};
	displayPlaylist(playList, *currentSong);
	char selector{'\0'};
	do{
		selector = menuFunction();
		if(selector == 'q' || selector == 'Q'){
			cout<<setw(50)<<setfill('<')<<":QUIT(0)"<<setfill(' ')<<endl;
		}
		else if(selector == 'f' || selector == 'F'){ /*F - Play Frist Song*/
			currentSong = playList.begin();
			playCurrentSong(*currentSong);
		}
		else if(selector == 'n' || selector == 'N'){/*N - Play Next Song*/
			cout<<"Playing NEXT song->>"<<endl;
			if(*currentSong == playList.back()){
				currentSong = playList.begin();
				playCurrentSong(*currentSong);
			}
			else{
				++currentSong;
				playCurrentSong(*currentSong);
			}
			
		}
		else if(selector == 'p' || selector == 'P'){/*P - Play Previous Song*/
			cout<<"Playing PRIVIOUS song<<-"<<endl;
			if(*currentSong == playList.front()){
				currentSong = playList.end();
				currentSong--;
				playCurrentSong(*currentSong);
			}
			else{
				--currentSong;
				playCurrentSong(*currentSong);
			}
		}
		else if(selector == 'a' || selector == 'A'){/*A - Add and Play a New Song at Current  Location*/
			cout<<"Adding and playing NEW song:"<<endl;
			string songTitle{};
			string artistName{};
			int rating{};
			
			cin.ignore(); /*New line bug fixt*/
			cout<<"Enter a new song name here: ";
			getline(cin, songTitle);
			cout<<"Enter the artist name here: ";
			getline(cin, artistName);

			cout<<"Enter the rating of the song here(1-5): ";
			cin>>rating;
			
//			playList.insert(currentSong, {songTitle, artistName, rating}); /*Same*/
			playList.insert(currentSong, Song{songTitle, artistName, rating});
			--currentSong;
			playCurrentSong(*currentSong);
		}
		else if(selector == 'l' || selector == 'L'){/*L - List the Current Playlist*/
			displayPlaylist(playList, *currentSong);
		}
		else{
			cout<<"\t\tInvalid Selection, Choose the Right Option..!"<<endl;
		}
	}while(selector != 'q' && selector != 'Q');
	constexpr char smilee{2};
	cout<<setw(50)<<setfill(smilee)<<right<<"HappyEnding...!"<<endl;
    system("pause>0");
	return 0;
}
