#include "S2M.hpp"
#include "Helpers/RPCHelpers.hpp"
#if RETRO_USE_MOD_LOADER
#include "PublicFunctions.hpp"
#endif

using namespace RSDK;

GlobalVariables::Constructor c;
GlobalVariables *globals = nullptr;

#if RETRO_REV0U
void GlobalVariables::Init(void *g)
{
    GlobalVariables *globals = (GlobalVariables *)g;
    memset(globals, 0, sizeof(GlobalVariables));

    // Global Variable Initialization Goes Here!

    globals->playerID       = ID_SONIC | (ID_TAILS << 8);
    globals->saveSlotID     = NO_SAVE_SLOT;
    globals->medalMods      = MEDAL_INSTASHIELD + MEDAL_PEELOUT;
    globals->stock          = (ID_KNUCKLES << 8) | ID_TAILS;
    globals->characterFlags = ID_SONIC | ID_TAILS | ID_KNUCKLES;

    globals->superMusicEnabled = true;
    globals->playerSpriteStyle = GAME_SM;
    globals->gameSpriteStyle   = GAME_SM;
    globals->ostStyle          = GAME_SM;
    globals->starpostStyle     = GAME_SM;

    globals->restart1UP      = 100;
    globals->restartScore1UP = 5000;
    globals->restartLives[0] = 3;
    globals->restartLives[1] = 3;
    globals->restartLives[2] = 3;
    globals->restartLives[3] = 3;

    globals->useManiaBehavior  = true;

    globals->gravityDir        = CMODE_FLOOR;
    globals->tileCollisionMode = TILECOLLISION_DOWN;
}
#endif

void LinkGameLogic(RSDK::EngineInfo *info)
{
#if DISCORD_RPC
    InitDiscord(); // initializes the discord core at startup
#endif
#if RETRO_USE_MOD_LOADER
    GameLogic::InitPublicFunctions();
#endif
}

#if RETRO_USE_MOD_LOADER
bool32 LinkModLogic(EngineInfo *info, const char *id)
{
#if RETRO_REV02
    LinkGameLogicDLL(info);
#else
    LinkGameLogicDLL(*info);
#endif

    RSDK::Mod::modID = id;

    return true;
}
#endif