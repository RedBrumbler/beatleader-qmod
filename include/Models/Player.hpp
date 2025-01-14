#pragma once

#include "beatsaber-hook/shared/config/rapidjson-utils.hpp"
#include "include/Models/Clan.hpp"

#include <string>
using namespace std;

struct ProfileSettings {
    string message;
    string effectName;
    int hue;
    float saturation;

    ProfileSettings(rapidjson::Value const& document);
    ProfileSettings() = default;
};

struct Social {
    string service;
    string link;
    string user;

    Social(rapidjson::Value const& document);
    Social() = default;
};

class Player
{
    public:
    string id;
    string name;
    string country;
    string avatar;
    string role;
    int rank;
    int countryRank;
    float pp;
    std::optional<ProfileSettings> profileSettings;
    
    vector<string> friends;
    vector<Social> socials;
    vector<Clan> clans;

    Player(rapidjson::Value const& document);
    Player() = default;
};
