// ---------------------------------------------------------------------
// RSDK Project: Sonic 2 Mania
// Object Description: Explosion Object
// Object Author: Ducky
// ---------------------------------------------------------------------

#include "Explosion.hpp"
#include "Player.hpp"
#include "Zone.hpp"

using namespace RSDK;

namespace GameLogic
{
RSDK_REGISTER_OBJECT(Explosion);

void Explosion::Update()
{
    this->animator.Process();

    this->position.x += this->velocity.x;
    this->position.y += this->velocity.y;

    if (this->animator.frameID == this->animator.frameCount - 1)
        this->Destroy();
}
void Explosion::LateUpdate() {}
void Explosion::StaticUpdate() {}
void Explosion::Draw() { this->animator.DrawSprite(NULL, false); }

void Explosion::Create(void *data)
{
    this->active  = ACTIVE_NORMAL;
    this->visible = true;
    if (this->planeFilter > 0 && ((uint8)this->planeFilter - 1) & 2)
        this->drawGroup = Zone::sVars->objectDrawGroup[1];
    else
        this->drawGroup = Zone::sVars->objectDrawGroup[0];

    this->animator.SetAnimation(sVars->aniFrames, (uint16)VOID_TO_INT(data), true, 0);
}

void Explosion::StageLoad()
{
    sVars->aniFrames.Load("Global/Explosions.bin", SCOPE_STAGE);

    sVars->sfxDestroy.Get("Global/Destroy.wav");
    sVars->sfxExplosion.Get("Stage/Explosion.wav");
}

Explosion *Explosion::Spawn(RSDK::GameObject::Entity *parent, RSDK::Vector2 position, uint8 drawOrder, int16 rangeX, int16 rangeY, int16 timer,
                            int16 tablePos, uint8 childType)
{
    return nullptr;
}

void Explosion::SpawnGroup(RSDK::GameObject::Entity *parent, RSDK::Vector2 *offset, uint16 count, RSDK::Vector2 *origin,
                           RSDK::SpriteAnimation *aniFrames, uint16 *aniIDs, uint16 *timers, uint8 drawOrder, bool32 isHarmful)
{
}

#if RETRO_INCLUDE_EDITOR
void Explosion::EditorDraw()
{
    this->animator.SetAnimation(sVars->aniFrames, this->aniID, true, 0);
    this->animator.DrawSprite(&this->position, false);
}

void Explosion::EditorLoad() { sVars->aniFrames.Load("Global/Explosions.bin", SCOPE_STAGE); }
#endif

#if RETRO_REV0U
void Explosion::StaticLoad(Static *sVars)
{
    RSDK_INIT_STATIC_VARS(Explosion);
    sVars->aniFrames.Init();

    sVars->sfxExplosion.Init();
    sVars->sfxDestroy.Init();
}
#endif

void Explosion::Serialize() {}

} // namespace GameLogic