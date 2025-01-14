#include "include/Models/Difficulty.hpp"

Difficulty::Difficulty(rapidjson::Value const& document) {
    stars = document["stars"].GetFloat();
    status = document["status"].GetInt();
    type = document["type"].GetInt();

    auto receivedVotes = document["votes"].GetArray();

    for(const auto& vote : receivedVotes) {
        votes.push_back(vote.GetFloat());
    }

    auto receivedModifierValues = document["modifierValues"].GetObject();

    for(auto& kv : receivedModifierValues){
        string key = kv.name.GetString();
        std::transform(key.begin(), key.end(), key.begin(), ::toupper);
        modifierValues[key] = kv.value.GetFloat();
    }
}

Difficulty::Difficulty(float starsGiven, int statusGiven, int typeGiven, vector<float> votesGiven, unordered_map<string, float> modifierValuesGiven) {
    stars = starsGiven;
    status = statusGiven;
    type = typeGiven;
    votes = votesGiven;
    modifierValues = modifierValuesGiven;
}