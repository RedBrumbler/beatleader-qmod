#pragma once
#include "config-utils/shared/config-utils.hpp"
#include "bs-utils/shared/utils.hpp"

DECLARE_CONFIG(ModConfig,
    CONFIG_VALUE(ServerType, std::string, "ServerType", "Main", "");
    CONFIG_VALUE(SaveLocalReplays, bool, "Keep local replays", true, "Save replays on this device");
    CONFIG_VALUE(Modifiers, bool, "Positive modifiers", true, "Show leaderboards with positive modifiers");
    CONFIG_VALUE(AvatarsActive, bool, "Show Avatars", false);
    CONFIG_VALUE(ClansActive, bool, "Show Clans", true);
    CONFIG_VALUE(ScoresActive, bool, "Show Scores", true);
    CONFIG_VALUE(TimesetActive, bool, "Show Timeset", true);
    CONFIG_VALUE(IncognitoList, std::string, "Hidden players", "{}");
    CONFIG_VALUE(ShowReplaySettings, bool, "Show replay settings", true);
)

inline bool UploadEnabled() {
    return bs_utils::Submission::getEnabled();
}

inline bool UploadDisabledByReplay() {
    for (auto kv : bs_utils::Submission::getDisablingMods()) {
        if (kv.id == "replay") {
            return true;
        }
    } 
    return false;
}

inline std::string UploadDisablers() {
    auto map = bs_utils::Submission::getDisablingMods();
    std::string result = "Score submission disabled by ";
    int counter = 0;
    int size = map.size();

    for (auto kv : map) {
        counter++;
        result += kv.id + (counter != size ? ", " : "");
    } 
    return result;
}