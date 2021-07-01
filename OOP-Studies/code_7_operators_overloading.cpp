#include <iostream>
#include <string>
#include <list>

class YoutubeChannel{
public:
  std::string Name;
  int SubscriberCount;

  YoutubeChannel(std::string name, int subscribersCount){
    Name = name;
    SubscriberCount = subscribersCount;
  }

  bool operator==(const YoutubeChannel& channel){
    return this->Name == channel.Name;
  }

  bool operator>(const YoutubeChannel& channel){
    return this->SubscriberCount > channel.SubscriberCount;
  }

  bool operator<(const YoutubeChannel& channel){
    return this->SubscriberCount < channel.SubscriberCount;
  }

  // friend std::ostream& operator<<(std::ostream& COUT , YoutubeChannel& ytChannel){
  //   COUT << "Name: " << ytChannel.Name << std::endl;
  //   COUT << "Subscribers: " << ytChannel.SubscriberCount << std::endl;
  //   COUT << std::endl;
  //   return COUT;
  // }
};

std::ostream& operator<<(std::ostream& COUT , YoutubeChannel& ytChannel){
    COUT << "Name: " << ytChannel.Name << std::endl;
    COUT << "Subscribers: " << ytChannel.SubscriberCount << std::endl;
    COUT << std::endl;
    return COUT;
}

class MyCollection {
public:
  std::list<YoutubeChannel> myChannels;

  void operator+=(const YoutubeChannel& channel) {
    this->myChannels.push_back(channel);
  }
  void operator-=(const YoutubeChannel& channel) {
    this->myChannels.remove(channel);
  }
};

std::ostream& operator<<(std::ostream& COUT, MyCollection& myCollection){
  COUT << "=-=-=-=-=-=-=-=-=-My Collection of Channels-=-=-=-=-=-=-=-=-=" << std::endl;
  for(YoutubeChannel ytChannel: myCollection.myChannels){
    COUT << ytChannel;
  }
  COUT << std::endl;
  return COUT;
}

int main(){
  YoutubeChannel yt1 = YoutubeChannel("Lucas Bivar", 1000);
  YoutubeChannel yt2 = YoutubeChannel("Filipe Deschamps", 500000);
  std::cout << yt1;

  // operator<<(std::cout, yt1);

  MyCollection myCollection;
  myCollection += yt1;
  myCollection += yt2;

  std::cout << myCollection;

  myCollection -= yt1;
  std::cout << myCollection;

  if(yt1 > yt2){
    std::cout << "Channel 1 is greater than Channel 2!" << std::endl;
  }else{
    std::cout << "Channel 1 isn't greater than Channel 2!" << std::endl;
  }

  if(yt1 < yt2){
    std::cout << "Channel 1 is less than Channel 2!" << std::endl;
  }else{
    std::cout << "Channel 1 isn't less than Channel 2!" << std::endl;
  }

  return 0;
}

// g++ -Wall -std=c++17 OOP-Studies/code_7_operators_overloading.cpp -o main && ./main