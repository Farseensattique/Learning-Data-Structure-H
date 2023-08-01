#include <iostream>
using namespace std;

struct Music
{
    string song;
    string artist;
    string genre;
    Music *prevMusic;
    Music *nextMusic;
};

class Playlist
{
public:
    Music *firstMusic = NULL;
    Music *lastMusic = NULL;
    Music *newMusic, *currentMusic;
    string play;

    void addMusic(string song, string artist, string genre)
    {
        newMusic = new Music;
        newMusic->song = song;
        newMusic->artist = artist;
        newMusic->genre = genre;
        newMusic->prevMusic = lastMusic;
        newMusic->nextMusic = NULL;

        if (lastMusic != NULL)
        {
            lastMusic->nextMusic = newMusic;
        }
        else
        {
            firstMusic = newMusic;
        }
        lastMusic = newMusic;
    }

    void searchBySong(string song)
    {
        currentMusic = firstMusic;
        while (currentMusic != NULL)
        {
            if (currentMusic->song == song)
            {
                cout << currentMusic->song << " is ready to play" << endl;
                return;
            }
            currentMusic = currentMusic->nextMusic;
        }
    }

    void searchByArtist(string artist)
    {
        currentMusic = firstMusic;
        while (currentMusic != NULL)
        {
            if (currentMusic->artist == artist)
            {
                cout << "Song: " << currentMusic->song << ", Artist: " << currentMusic->artist << ", Genre: " << currentMusic->genre << endl;
            }
            currentMusic = currentMusic->nextMusic;
        }
    }

    void searchByGenre(string genre)
    {
        currentMusic = firstMusic;
        while (currentMusic != NULL)
        {
            if (currentMusic->genre == genre)
            {
                cout << "Song: " << currentMusic->song << ", Artist: " << currentMusic->artist << ", Genre: " << currentMusic->genre << endl;
            }
            currentMusic = currentMusic->nextMusic;
        }
    }
};

int main()
{
    int totalSong;
    cout << "Total Number of songs in the playlist: ";
    cin >> totalSong;
    cin.ignore();

    Playlist music;
    string song, artist, genre;
    cout << "Enter the name of the songs downloaded in the playlist: " << endl;
    for (int i = 0; i < totalSong; i++)
    {
        cout << "Song Name: ";
        getline(cin, song);
        cout << "Artist: ";
        getline(cin, artist);
        cout << "Genre: ";
        getline(cin, genre);
        cout << endl;
        music.addMusic(song, artist, genre);
    }

    string play;
    cout << "Search for a song by song name or artist name or genre: ";
    getline(cin, play);

    music.searchBySong(play);
    music.searchByArtist(play);
    music.searchByGenre(play);

    return 0;
}
