// MyThirtithApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>


#include<list>
using namespace std;

class YouTubeChannel {
private:
    string Name;
    //string OwnerName;
    int SubscribersCount;
    list<string> PublishedVideoTitles;

protected:
    string OwnerName;
    int ContentQuality;

public:
    YouTubeChannel(string name, string ownerName) {
        Name = name;
        OwnerName = ownerName;
        SubscribersCount = 0;
        ContentQuality = 0;
    }

    void GetInfo() {
        cout << "Name: " << Name << endl;
        cout << "Owner Name: " << OwnerName << endl;
        cout << "Subscribers Count: " << SubscribersCount << endl;
        cout << "Videos: " << endl;
        for (string videoTitle : PublishedVideoTitles) {
            cout << videoTitle << endl;
        }
        cout << endl;
    }
    void Subscribe() {
        SubscribersCount++;
    }
    void Unsubscribe() {
        if (SubscribersCount > 0)
            SubscribersCount--;
    }
    void PublishVideo(string title) {
        PublishedVideoTitles.push_back(title);
    }
    void CheckAnalytics() {
        if (ContentQuality < 5) 
            cout << Name << " has bad quality content!" << endl;
        else
            cout << Name << " has great quality content!" << endl;
    }
};

class CookingYoutubeChannel:public YouTubeChannel{
public:
    CookingYoutubeChannel(string name,string ownerName):YouTubeChannel(name,ownerName){

    }
    void Practice() {
        cout << OwnerName<<" is practicing cooking, learning new recipes, experimenting with spices..." << endl;
        ContentQuality++;
    }
};

class SingersYoutubeChannel :public YouTubeChannel {
public:
    SingersYoutubeChannel(string name, string ownerName) :YouTubeChannel(name, ownerName) {

    }
    void Practice() {
        cout << OwnerName << " is taking singing classes, learning new songs, learning how to dance..." << endl;
        ContentQuality++;
    }
};



int main()
{
    CookingYoutubeChannel cookingYtChannel("Amy's Kitchen","Amy");
    SingersYoutubeChannel singersYtChannel("JohnSings", "John");
/*    cookingYtChannel.PublishVideo("Apple Pie");
    cookingYtChannel.PublishVideo("Chocolate Cake");
    cookingYtChannel.Subscribe();
    cookingYtChannel.Subscribe();
    cookingYtChannel.Subscribe();
    cookingYtChannel.GetInfo()*/;
    cookingYtChannel.Practice();
    singersYtChannel.Practice();
    singersYtChannel.Practice();
    singersYtChannel.Practice();
    singersYtChannel.Practice();
    singersYtChannel.Practice();
    

    YouTubeChannel ytChannel("CodeBeauty", "Saldina");
    
    YouTubeChannel* yt1 = &cookingYtChannel;
    YouTubeChannel* yt2 = &singersYtChannel;

    yt1->CheckAnalytics();
    yt2->CheckAnalytics();

    system("pause>0");

}

