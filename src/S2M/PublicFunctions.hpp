#pragma once
#include "S2M.hpp"
#include "All.hpp"

using namespace RSDK;

#if RETRO_USE_MOD_LOADER
#define ADD_PUBLIC_FUNC(func) GameLogic::AddPublicFunction(#func, &func)

namespace GameLogic
{

template <typename X, typename Type> inline static void AddPublicFunction(const char *functionName, Type(X::*functionPtr))
{
    modTable->AddPublicFunction(functionName, reinterpret_cast<void *&>(functionPtr));
}
template <typename Type> inline static void AddPublicFunction(const char *functionName, Type(*functionPtr))
{
    modTable->AddPublicFunction(functionName, reinterpret_cast<void *&>(functionPtr));
}

static void InitPublicFunctions()
{
    // ARZ/ArrowLauncher
    ADD_PUBLIC_FUNC(ArrowLauncher::DebugSpawn);
    ADD_PUBLIC_FUNC(ArrowLauncher::DebugDraw);
    ADD_PUBLIC_FUNC(ArrowLauncher::State_AwaitPlayer);
    ADD_PUBLIC_FUNC(ArrowLauncher::State_Activate);
    ADD_PUBLIC_FUNC(ArrowLauncher::State_FireArrow);

    // ARZ/BreakoffPillar
    ADD_PUBLIC_FUNC(BreakoffPillar::DebugSpawn);
    ADD_PUBLIC_FUNC(BreakoffPillar::DebugDraw);
    ADD_PUBLIC_FUNC(BreakoffPillar::State_AwaitPlayer);
    ADD_PUBLIC_FUNC(BreakoffPillar::State_Shaking);
    ADD_PUBLIC_FUNC(BreakoffPillar::State_Falling);
    ADD_PUBLIC_FUNC(BreakoffPillar::State_Fallen);

    // ARZ/ChopChop
    ADD_PUBLIC_FUNC(ChopChop::DebugSpawn);
    ADD_PUBLIC_FUNC(ChopChop::DebugDraw);
    ADD_PUBLIC_FUNC(ChopChop::Setup);
    ADD_PUBLIC_FUNC(ChopChop::State_Swimming);
    ADD_PUBLIC_FUNC(ChopChop::State_AttackDelay);
    ADD_PUBLIC_FUNC(ChopChop::State_Attack);

    // ARZ/Grounder
    ADD_PUBLIC_FUNC(Grounder::DebugSpawn);
    ADD_PUBLIC_FUNC(Grounder::DebugDraw);
    ADD_PUBLIC_FUNC(Grounder::State_Hidden);
    ADD_PUBLIC_FUNC(Grounder::State_Appear);
    ADD_PUBLIC_FUNC(Grounder::State_Moving);
    ADD_PUBLIC_FUNC(Grounder::State_Turning);

    // ARZ/Wisp
    ADD_PUBLIC_FUNC(Wisp::DebugSpawn);
    ADD_PUBLIC_FUNC(Wisp::DebugDraw);
    ADD_PUBLIC_FUNC(Wisp::HandlePlayerInteractions);
    ADD_PUBLIC_FUNC(Wisp::CheckOffScreen);
    ADD_PUBLIC_FUNC(Wisp::State_Init);
    ADD_PUBLIC_FUNC(Wisp::State_Idle);
    ADD_PUBLIC_FUNC(Wisp::State_FlyTowardTarget);
    ADD_PUBLIC_FUNC(Wisp::State_FlyAway);

    // Bonus/BonusTitleCard
    ADD_PUBLIC_FUNC(BonusTitleCard::SetupTitleWords);
    ADD_PUBLIC_FUNC(BonusTitleCard::Draw_SlidingIn);

    // CNZ/CircleBumper
    ADD_PUBLIC_FUNC(CircleBumper::DebugDraw);
    ADD_PUBLIC_FUNC(CircleBumper::DebugSpawn);
    ADD_PUBLIC_FUNC(CircleBumper::CheckPlayerCollisions);
    ADD_PUBLIC_FUNC(CircleBumper::Collide_Normal);
    ADD_PUBLIC_FUNC(CircleBumper::Collide_Bumped);
    ADD_PUBLIC_FUNC(CircleBumper::Move_Fixed);
    ADD_PUBLIC_FUNC(CircleBumper::Move_Linear);
    ADD_PUBLIC_FUNC(CircleBumper::Move_Circular);
    ADD_PUBLIC_FUNC(CircleBumper::Move_Path);
    ADD_PUBLIC_FUNC(CircleBumper::Move_Track);

    // CNZ/Crawl
    ADD_PUBLIC_FUNC(Crawl::DebugDraw);
    ADD_PUBLIC_FUNC(Crawl::DebugSpawn);
    ADD_PUBLIC_FUNC(Crawl::State_Setup);
    ADD_PUBLIC_FUNC(Crawl::State_Moving);
    ADD_PUBLIC_FUNC(Crawl::State_Idle);
    ADD_PUBLIC_FUNC(Crawl::State_Defend);

    // CNZ/Flipper
    ADD_PUBLIC_FUNC(Flipper::DebugDraw);
    ADD_PUBLIC_FUNC(Flipper::DebugSpawn);

    // CNZ/SlotMachine
    ADD_PUBLIC_FUNC(SlotMachine::DebugSpawn);
    ADD_PUBLIC_FUNC(SlotMachine::DebugDraw);
    ADD_PUBLIC_FUNC(SlotMachine::PlayRingSFX);
    ADD_PUBLIC_FUNC(SlotMachine::State_Idle);
    ADD_PUBLIC_FUNC(SlotMachine::State_Ready);
    ADD_PUBLIC_FUNC(SlotMachine::State_Hold);
    ADD_PUBLIC_FUNC(SlotMachine::State_Unused);
    ADD_PUBLIC_FUNC(SlotMachine::State_Reward);
    ADD_PUBLIC_FUNC(SlotMachine::State_Wait);

    // CNZ/SlotPrize
    ADD_PUBLIC_FUNC(SlotPrize::State_Winner);
    ADD_PUBLIC_FUNC(SlotPrize::State_Loser);

    // CNZ/SnakeBlock
    ADD_PUBLIC_FUNC(SnakeBlock::DebugDraw);
    ADD_PUBLIC_FUNC(SnakeBlock::DebugSpawn);

    // CNZ/TargetBumper
    ADD_PUBLIC_FUNC(TargetBumper::DebugSpawn);
    ADD_PUBLIC_FUNC(TargetBumper::DebugDraw);
    ADD_PUBLIC_FUNC(TargetBumper::CheckPlayerCollisions);
    ADD_PUBLIC_FUNC(TargetBumper::State_Idle);
    ADD_PUBLIC_FUNC(TargetBumper::State_Hit);

    // CNZ/TriBumper
    ADD_PUBLIC_FUNC(TriBumper::SetPlayerVelocity);
    ADD_PUBLIC_FUNC(TriBumper::HandleBump);

    // CNZ/VFlipper
    ADD_PUBLIC_FUNC(VFlipper::DebugDraw);
    ADD_PUBLIC_FUNC(VFlipper::DebugSpawn);
    ADD_PUBLIC_FUNC(VFlipper::State_Idle);
    ADD_PUBLIC_FUNC(VFlipper::State_Activated_L);
    ADD_PUBLIC_FUNC(VFlipper::State_Activated_R);

    // Common/BreakableWall
    ADD_PUBLIC_FUNC(BreakableWall::State_PieceWait);
    ADD_PUBLIC_FUNC(BreakableWall::State_Piece);
    ADD_PUBLIC_FUNC(BreakableWall::State_Wall);
    ADD_PUBLIC_FUNC(BreakableWall::State_Floor);
    ADD_PUBLIC_FUNC(BreakableWall::State_BurrowFloor);
    ADD_PUBLIC_FUNC(BreakableWall::State_BurrowFloorUp);
    ADD_PUBLIC_FUNC(BreakableWall::State_Ceiling);
    ADD_PUBLIC_FUNC(BreakableWall::State_DrawWall);
    ADD_PUBLIC_FUNC(BreakableWall::State_DrawFloor);
    ADD_PUBLIC_FUNC(BreakableWall::State_DrawPiece);
    ADD_PUBLIC_FUNC(BreakableWall::CheckBreak_Wall);
    ADD_PUBLIC_FUNC(BreakableWall::CheckBreak_Floor);
    ADD_PUBLIC_FUNC(BreakableWall::CheckBreak_BurrowFloor);
    ADD_PUBLIC_FUNC(BreakableWall::CheckBreak_BurrowFloorUp);
    ADD_PUBLIC_FUNC(BreakableWall::CheckBreak_Ceiling);
    ADD_PUBLIC_FUNC(BreakableWall::Break);
    ADD_PUBLIC_FUNC(BreakableWall::GiveScoreBonus);

    // Common/Button
    ADD_PUBLIC_FUNC(Button::HandleFloor);
    ADD_PUBLIC_FUNC(Button::HandleRoof);
    ADD_PUBLIC_FUNC(Button::HandleRWall);
    ADD_PUBLIC_FUNC(Button::HandleLWall);

    // Common/CollapsingPlatform
    ADD_PUBLIC_FUNC(CollapsingPlatform::SetupTiles);
    ADD_PUBLIC_FUNC(CollapsingPlatform::SetupHWrapTiles);
    ADD_PUBLIC_FUNC(CollapsingPlatform::SetupTagLink);
    ADD_PUBLIC_FUNC(CollapsingPlatform::CrumbleFromLeft);
    ADD_PUBLIC_FUNC(CollapsingPlatform::CrumbleFromRight);
    ADD_PUBLIC_FUNC(CollapsingPlatform::CrumbleFromCenter);
    ADD_PUBLIC_FUNC(CollapsingPlatform::CrumbleFromLeftRight);
    ADD_PUBLIC_FUNC(CollapsingPlatform::CrumbleFromLeftRightCenter);
    ADD_PUBLIC_FUNC(CollapsingPlatform::CrumbleFromLeftRightCenter_Reverse);
    ADD_PUBLIC_FUNC(CollapsingPlatform::CrumbleDestroy);

    // Common/Decoration
    ADD_PUBLIC_FUNC(Decoration::DrawSprites);

    // Common/ForceSpin
    ADD_PUBLIC_FUNC(ForceSpin::DrawSprites);
    ADD_PUBLIC_FUNC(ForceSpin::SetPlayerState);

    // Common/ForceUnstick
    ADD_PUBLIC_FUNC(ForceUnstick::DrawSprites);

    // Common/ParallaxSprite
    ADD_PUBLIC_FUNC(ParallaxSprite::State_Emitter);
    ADD_PUBLIC_FUNC(ParallaxSprite::State_Particle);
    ADD_PUBLIC_FUNC(ParallaxSprite::State_Static);
    ADD_PUBLIC_FUNC(ParallaxSprite::State_Normal);

    // Common/Platform
    ADD_PUBLIC_FUNC(Platform::State_Fixed);
    ADD_PUBLIC_FUNC(Platform::State_Fall);
    ADD_PUBLIC_FUNC(Platform::State_Falling);
    ADD_PUBLIC_FUNC(Platform::State_Falling2);
    ADD_PUBLIC_FUNC(Platform::State_Hold);
    ADD_PUBLIC_FUNC(Platform::State_Linear);
    ADD_PUBLIC_FUNC(Platform::State_Circular);
    ADD_PUBLIC_FUNC(Platform::State_Swing);
    ADD_PUBLIC_FUNC(Platform::State_Clacker);
    ADD_PUBLIC_FUNC(Platform::State_Push_Init);
    ADD_PUBLIC_FUNC(Platform::State_Push);
    ADD_PUBLIC_FUNC(Platform::State_Push_SlideOffL);
    ADD_PUBLIC_FUNC(Platform::State_Push_SlideOffR);
    ADD_PUBLIC_FUNC(Platform::State_Push_Fall);
    ADD_PUBLIC_FUNC(Platform::State_Path);
    ADD_PUBLIC_FUNC(Platform::State_PathStop);
    ADD_PUBLIC_FUNC(Platform::State_Track);
    ADD_PUBLIC_FUNC(Platform::State_React);
    ADD_PUBLIC_FUNC(Platform::State_Hover_React);
    ADD_PUBLIC_FUNC(Platform::State_ReactMove);
    ADD_PUBLIC_FUNC(Platform::State_ReactSlow);
    ADD_PUBLIC_FUNC(Platform::State_Hover);
    ADD_PUBLIC_FUNC(Platform::State_ReactWait);
    ADD_PUBLIC_FUNC(Platform::State_DoorSlide);
    ADD_PUBLIC_FUNC(Platform::State_PathReact);
    ADD_PUBLIC_FUNC(Platform::State_Child);
    ADD_PUBLIC_FUNC(Platform::State_DipRock);
    ADD_PUBLIC_FUNC(Platform::State_SwingReact);
    ADD_PUBLIC_FUNC(Platform::State_Swing2);
    ADD_PUBLIC_FUNC(Platform::State_SwingWait);
    ADD_PUBLIC_FUNC(Platform::State_SwingReturn);
    ADD_PUBLIC_FUNC(Platform::State_TrackReact);
    ADD_PUBLIC_FUNC(Platform::State_Track2);
    ADD_PUBLIC_FUNC(Platform::State_TrackWait);
    ADD_PUBLIC_FUNC(Platform::State_TrackReturn);
    ADD_PUBLIC_FUNC(Platform::Collision_Platform);
    ADD_PUBLIC_FUNC(Platform::Collision_Solid);
    ADD_PUBLIC_FUNC(Platform::Collision_Solid_NoCrush);
    ADD_PUBLIC_FUNC(Platform::Collision_Solid_Hurt_Sides);
    ADD_PUBLIC_FUNC(Platform::Collision_Solid_Hurt_Bottom);
    ADD_PUBLIC_FUNC(Platform::Collision_Solid_Hurt_Top);
    ADD_PUBLIC_FUNC(Platform::Collision_Solid_Hold);
    ADD_PUBLIC_FUNC(Platform::Collision_Solid_Barrel);
    ADD_PUBLIC_FUNC(Platform::Collision_Sticky);
    ADD_PUBLIC_FUNC(Platform::Collision_Tiles);
    ADD_PUBLIC_FUNC(Platform::Collision_Hurt);
    ADD_PUBLIC_FUNC(Platform::Collision_None);
    ADD_PUBLIC_FUNC(Platform::Collision_Solid_Hurt_All);
    ADD_PUBLIC_FUNC(Platform::Collision_Solid_Hurt_NoCrush);
    ADD_PUBLIC_FUNC(Platform::HandleStood);
    ADD_PUBLIC_FUNC(Platform::HandleStood_Tiles);
    ADD_PUBLIC_FUNC(Platform::HandleStood_Hold);
    ADD_PUBLIC_FUNC(Platform::HandleStood_Barrel);
    ADD_PUBLIC_FUNC(Platform::HandleStood_Sticky);

    // Common/PlatformControl
    ADD_PUBLIC_FUNC(PlatformControl::ManagePlatformVelocity);

    // Common/ScreenWrap
    ADD_PUBLIC_FUNC(ScreenWrap::CheckCompetitionWrap);
    ADD_PUBLIC_FUNC(ScreenWrap::WrapTileLayer);
    ADD_PUBLIC_FUNC(ScreenWrap::Unknown1);
    ADD_PUBLIC_FUNC(ScreenWrap::HandleVWrap);
    ADD_PUBLIC_FUNC(ScreenWrap::HandleHWrap);
    ADD_PUBLIC_FUNC(ScreenWrap::State_Vertical);
    ADD_PUBLIC_FUNC(ScreenWrap::State_Horizontal);

    // Common/SpinBooster
    ADD_PUBLIC_FUNC(SpinBooster::GetRollDir);
    ADD_PUBLIC_FUNC(SpinBooster::HandleRollDir);
    ADD_PUBLIC_FUNC(SpinBooster::ApplyRollVelocity);
    ADD_PUBLIC_FUNC(SpinBooster::DrawArrow);
    ADD_PUBLIC_FUNC(SpinBooster::DrawSprites);
    ADD_PUBLIC_FUNC(SpinBooster::HandleForceRoll);

    // Common/Springboard
    ADD_PUBLIC_FUNC(Springboard::DebugSpawn);
    ADD_PUBLIC_FUNC(Springboard::DebugDraw);

    // Common/Water
    ADD_PUBLIC_FUNC(Water::DrawHook_ApplyWaterPalette);
    ADD_PUBLIC_FUNC(Water::DrawHook_RemoveWaterPalette);
    ADD_PUBLIC_FUNC(Water::SetupTagLink);
    ADD_PUBLIC_FUNC(Water::SpawnBubble);
    ADD_PUBLIC_FUNC(Water::SpawnCountDownBubble);
    ADD_PUBLIC_FUNC(Water::BubbleFloatBehavior);
    ADD_PUBLIC_FUNC(Water::ApplyHeightTriggers);
    ADD_PUBLIC_FUNC(Water::State_Water);
    ADD_PUBLIC_FUNC(Water::State_Pool);
    ADD_PUBLIC_FUNC(Water::State_Splash);
    ADD_PUBLIC_FUNC(Water::BubbleFinishPopBehavior);
    ADD_PUBLIC_FUNC(Water::State_BubbleBreathed);
    ADD_PUBLIC_FUNC(Water::State_Bubbler);
    ADD_PUBLIC_FUNC(Water::State_Countdown);
    ADD_PUBLIC_FUNC(Water::State_CountdownFollow);
    ADD_PUBLIC_FUNC(Water::State_HeightTrigger);
    ADD_PUBLIC_FUNC(Water::Draw_Water);
    ADD_PUBLIC_FUNC(Water::Draw_Pool);
    ADD_PUBLIC_FUNC(Water::Draw_Splash);
    ADD_PUBLIC_FUNC(Water::Draw_Countdown);
    ADD_PUBLIC_FUNC(Water::Draw_Bubbler);
    ADD_PUBLIC_FUNC(Water::Draw_Bubble);

    // CPZ/ChemicalBall
    ADD_PUBLIC_FUNC(ChemicalBall::CheckHit);
    ADD_PUBLIC_FUNC(ChemicalBall::State_MoveArc);
    ADD_PUBLIC_FUNC(ChemicalBall::State_MoveVertical);

    // CPZ/ChemicalDropper
    ADD_PUBLIC_FUNC(ChemicalDropper::SpawnDebris);
    ADD_PUBLIC_FUNC(ChemicalDropper::Oscillate);
    ADD_PUBLIC_FUNC(ChemicalDropper::State_MoveRight);
    ADD_PUBLIC_FUNC(ChemicalDropper::State_GetChemicals);
    ADD_PUBLIC_FUNC(ChemicalDropper::State_DropChemicals);
    ADD_PUBLIC_FUNC(ChemicalDropper::State_MoveLeft);
    ADD_PUBLIC_FUNC(ChemicalDropper::State_Destroyed);
    ADD_PUBLIC_FUNC(ChemicalDropper::State_DebrisExplode);
    ADD_PUBLIC_FUNC(ChemicalDropper::State_DebrisDelay);
    ADD_PUBLIC_FUNC(ChemicalDropper::State_Debris);
    ADD_PUBLIC_FUNC(ChemicalDropper::Mani_Idle);
    ADD_PUBLIC_FUNC(ChemicalDropper::Mani_Extend);
    ADD_PUBLIC_FUNC(ChemicalDropper::Mani_Filling);
    ADD_PUBLIC_FUNC(ChemicalDropper::Mani_Retract);
    ADD_PUBLIC_FUNC(ChemicalDropper::Dani_Closed);
    ADD_PUBLIC_FUNC(ChemicalDropper::Dani_Filling);
    ADD_PUBLIC_FUNC(ChemicalDropper::Dani_Wait);
    ADD_PUBLIC_FUNC(ChemicalDropper::Dani_Extend);
    ADD_PUBLIC_FUNC(ChemicalDropper::Dani_OpenHatch);
    ADD_PUBLIC_FUNC(ChemicalDropper::Dani_Retract);
    ADD_PUBLIC_FUNC(ChemicalDropper::Drop_BubbleHit);
    ADD_PUBLIC_FUNC(ChemicalDropper::Drop_CreateSplash);

    // CPZ/CPZEggman
    ADD_PUBLIC_FUNC(CPZEggman::Oscillate);
    ADD_PUBLIC_FUNC(CPZEggman::State_AwaitPlayer);
    ADD_PUBLIC_FUNC(CPZEggman::State_BossFight);
    ADD_PUBLIC_FUNC(CPZEggman::State_Explode);
    ADD_PUBLIC_FUNC(CPZEggman::State_DefeatFall);
    ADD_PUBLIC_FUNC(CPZEggman::State_DefeatRise);
    ADD_PUBLIC_FUNC(CPZEggman::State_Flee);
    ADD_PUBLIC_FUNC(CPZEggman::State_Escape);

    // CPZ/CPZSetup
    ADD_PUBLIC_FUNC(CPZSetup::StageFinish_EndAct1);
    ADD_PUBLIC_FUNC(CPZSetup::HandleActTransition);
    ADD_PUBLIC_FUNC(CPZSetup::StageFinish_EndAct2);

    // CPZ/Grabber
    ADD_PUBLIC_FUNC(Grabber::DebugDraw);
    ADD_PUBLIC_FUNC(Grabber::DebugSpawn);
    ADD_PUBLIC_FUNC(Grabber::CheckPlayerCollisions);
    ADD_PUBLIC_FUNC(Grabber::CheckOffScreen);
    ADD_PUBLIC_FUNC(Grabber::HandleExplode);
    ADD_PUBLIC_FUNC(Grabber::State_Init);
    ADD_PUBLIC_FUNC(Grabber::State_CheckForGrab);
    ADD_PUBLIC_FUNC(Grabber::State_GrabDelay);
    ADD_PUBLIC_FUNC(Grabber::State_HandleTurn);
    ADD_PUBLIC_FUNC(Grabber::State_TryToGrab);
    ADD_PUBLIC_FUNC(Grabber::State_RiseUp);
    ADD_PUBLIC_FUNC(Grabber::State_GrabbedPlayer);
    ADD_PUBLIC_FUNC(Grabber::State_Struggle);
    ADD_PUBLIC_FUNC(Grabber::State_PlayerEscaped);

    // CPZ/OneWayDoor
    ADD_PUBLIC_FUNC(OneWayDoor::HandlePlayerInteractions);
    ADD_PUBLIC_FUNC(OneWayDoor::State_MoveDown);
    ADD_PUBLIC_FUNC(OneWayDoor::State_MoveUp);
    ADD_PUBLIC_FUNC(OneWayDoor::Draw_CPZ);

    // CPZ/RotatingStair
    ADD_PUBLIC_FUNC(RotatingStair::State_Move);
    ADD_PUBLIC_FUNC(RotatingStair::State_Move_Intervals);

    // CPZ/SpeedBooster
    ADD_PUBLIC_FUNC(SpeedBooster::DebugSpawn);
    ADD_PUBLIC_FUNC(SpeedBooster::DebugDraw);
    ADD_PUBLIC_FUNC(SpeedBooster::State_SpeedBooster);
    ADD_PUBLIC_FUNC(SpeedBooster::HandleInteractions);

    // CPZ/Spiny
    ADD_PUBLIC_FUNC(Spiny::DebugSpawn);
    ADD_PUBLIC_FUNC(Spiny::DebugDraw);
    ADD_PUBLIC_FUNC(Spiny::CheckPlayerCollisions);
    ADD_PUBLIC_FUNC(Spiny::CheckOffScreen);
    ADD_PUBLIC_FUNC(Spiny::State_Init);
    ADD_PUBLIC_FUNC(Spiny::State_Floor);
    ADD_PUBLIC_FUNC(Spiny::State_Shoot_Floor);
    ADD_PUBLIC_FUNC(Spiny::State_Wall);
    ADD_PUBLIC_FUNC(Spiny::State_Shoot_Wall);
    ADD_PUBLIC_FUNC(Spiny::State_Shot);
    ADD_PUBLIC_FUNC(Spiny::State_ShotDisappear);

    // CPZ/Staircase
    ADD_PUBLIC_FUNC(Staircase::SfxCheck_HitBlocks);
    ADD_PUBLIC_FUNC(Staircase::State_Idle);
    ADD_PUBLIC_FUNC(Staircase::State_Wait);
    ADD_PUBLIC_FUNC(Staircase::State_MoveBlocks);
    ADD_PUBLIC_FUNC(Staircase::State_MovedBlocks);
    ADD_PUBLIC_FUNC(Staircase::Draw_Blocks);
    ADD_PUBLIC_FUNC(Staircase::Draw_Shake);

    // CPZ/TippingPlatform
    ADD_PUBLIC_FUNC(TippingPlatform::State_Tipping_Boss);
    ADD_PUBLIC_FUNC(TippingPlatform::State_RestorePlatform);
    ADD_PUBLIC_FUNC(TippingPlatform::State_Tipping);
    ADD_PUBLIC_FUNC(TippingPlatform::State_Restore);
    ADD_PUBLIC_FUNC(TippingPlatform::State_Tipping_Delay);

    // CPZ/TransportTube
    ADD_PUBLIC_FUNC(TransportTube::SetupDirections);
    ADD_PUBLIC_FUNC(TransportTube::HandleVelocityChange);
    ADD_PUBLIC_FUNC(TransportTube::State_ChangeDir);
    ADD_PUBLIC_FUNC(TransportTube::State_Entry);
    ADD_PUBLIC_FUNC(TransportTube::State_ToTargetEntity);
    ADD_PUBLIC_FUNC(TransportTube::State_TargetSeqNode);
    ADD_PUBLIC_FUNC(TransportTube::State_ChooseDir);
    ADD_PUBLIC_FUNC(TransportTube::State_Exit);

    // CPZ/TubeSpring
    ADD_PUBLIC_FUNC(TubeSpring::Spring_State_Vertical);
    ADD_PUBLIC_FUNC(TubeSpring::State_Idle);
    ADD_PUBLIC_FUNC(TubeSpring::State_Springing);
    ADD_PUBLIC_FUNC(TubeSpring::State_Pullback);
    ADD_PUBLIC_FUNC(TubeSpring::HandleInteractions);

    // DEZ/Blastoid
    ADD_PUBLIC_FUNC(Blastoid::DebugSpawn);
    ADD_PUBLIC_FUNC(Blastoid::DebugDraw);
    ADD_PUBLIC_FUNC(Blastoid::CheckPlayerCollisions);
    ADD_PUBLIC_FUNC(Blastoid::State_Init);
    ADD_PUBLIC_FUNC(Blastoid::State_Body);
    ADD_PUBLIC_FUNC(Blastoid::State_Projectile);

    // DEZ/Crate
    ADD_PUBLIC_FUNC(Crate::Break);
    ADD_PUBLIC_FUNC(Crate::MoveY);
    ADD_PUBLIC_FUNC(Crate::Collide);
    ADD_PUBLIC_FUNC(Crate::State_None);
    ADD_PUBLIC_FUNC(Crate::State_ApplyGravity);
    ADD_PUBLIC_FUNC(Crate::State_WaitToFall);
    ADD_PUBLIC_FUNC(Crate::State_Fall);

    // DEZ/FlasherMKII
    ADD_PUBLIC_FUNC(FlasherMKII::DebugSpawn);
    ADD_PUBLIC_FUNC(FlasherMKII::DebugDraw);
    ADD_PUBLIC_FUNC(FlasherMKII::CheckOffScreen);
    ADD_PUBLIC_FUNC(FlasherMKII::HandlePlayerCollisions);
    ADD_PUBLIC_FUNC(FlasherMKII::HandleHarmPlayerCollisions);
    ADD_PUBLIC_FUNC(FlasherMKII::State_Idle);
    ADD_PUBLIC_FUNC(FlasherMKII::State_Moving);
    ADD_PUBLIC_FUNC(FlasherMKII::State_WeakFlash);
    ADD_PUBLIC_FUNC(FlasherMKII::State_StrongFlash);
    ADD_PUBLIC_FUNC(FlasherMKII::State_FinishedFlashing);

    // DEZ/MetalArm
    ADD_PUBLIC_FUNC(MetalArm::SfxCheck_MetalArm);
    ADD_PUBLIC_FUNC(MetalArm::GetArmPosition);
    ADD_PUBLIC_FUNC(MetalArm::CheckPlayerCollisions);
    ADD_PUBLIC_FUNC(MetalArm::State_Idle);
    ADD_PUBLIC_FUNC(MetalArm::State_MoveToHold);
    ADD_PUBLIC_FUNC(MetalArm::State_Holding);
    ADD_PUBLIC_FUNC(MetalArm::State_MoveToStart);

    // DEZ/PopOut
    ADD_PUBLIC_FUNC(PopOut::SetupHitboxes);

    // DEZ/Press
    ADD_PUBLIC_FUNC(Press::CheckCanSuper);
    ADD_PUBLIC_FUNC(Press::Move);
    ADD_PUBLIC_FUNC(Press::State_Crush);
    ADD_PUBLIC_FUNC(Press::State_FinalCrush);
    ADD_PUBLIC_FUNC(Press::HandleMovement);
    ADD_PUBLIC_FUNC(Press::State_HandleCrates);
    ADD_PUBLIC_FUNC(Press::DrawHandle);

    // DEZ/Tubinaut
    ADD_PUBLIC_FUNC(Tubinaut::DebugSpawn);
    ADD_PUBLIC_FUNC(Tubinaut::DebugDraw);
    ADD_PUBLIC_FUNC(Tubinaut::CheckPlayerCollisions);
    ADD_PUBLIC_FUNC(Tubinaut::CheckAttacking);
    ADD_PUBLIC_FUNC(Tubinaut::OrbHit);
    ADD_PUBLIC_FUNC(Tubinaut::HandleRepel);
    ADD_PUBLIC_FUNC(Tubinaut::HandleOrbs);
    ADD_PUBLIC_FUNC(Tubinaut::CheckOffScreen);
    ADD_PUBLIC_FUNC(Tubinaut::State_Init);
    ADD_PUBLIC_FUNC(Tubinaut::State_Move);
    ADD_PUBLIC_FUNC(Tubinaut::Orb_Relax);
    ADD_PUBLIC_FUNC(Tubinaut::Orb_PrepareAttack);
    ADD_PUBLIC_FUNC(Tubinaut::Orb_Attack);
    ADD_PUBLIC_FUNC(Tubinaut::Orb_Cooldown);
    ADD_PUBLIC_FUNC(Tubinaut::Orb_BodyDeath);

    // EHZ/Bridge
    ADD_PUBLIC_FUNC(Bridge::DebugDraw);
    ADD_PUBLIC_FUNC(Bridge::DebugSpawn);
    ADD_PUBLIC_FUNC(Bridge::Burn);
    ADD_PUBLIC_FUNC(Bridge::HandleCollisions);

    // EHZ/Buzzer
    ADD_PUBLIC_FUNC(Buzzer::DebugDraw);
    ADD_PUBLIC_FUNC(Buzzer::DebugSpawn);
    ADD_PUBLIC_FUNC(Buzzer::CheckPlayerCollisions);
    ADD_PUBLIC_FUNC(Buzzer::State_Init);
    ADD_PUBLIC_FUNC(Buzzer::State_Flying);
    ADD_PUBLIC_FUNC(Buzzer::State_Idle);
    ADD_PUBLIC_FUNC(Buzzer::State_Shooting);
    ADD_PUBLIC_FUNC(Buzzer::State_Invisible);
    ADD_PUBLIC_FUNC(Buzzer::State_ProjectileCharge);
    ADD_PUBLIC_FUNC(Buzzer::State_ProjectileShot);

    // EHZ/Coconuts
    ADD_PUBLIC_FUNC(Coconuts::DebugDraw);
    ADD_PUBLIC_FUNC(Coconuts::DebugSpawn);
    ADD_PUBLIC_FUNC(Coconuts::CheckPlayerCollisions);
    ADD_PUBLIC_FUNC(Coconuts::State_Init);
    ADD_PUBLIC_FUNC(Coconuts::State_AwaitPlayer);
    ADD_PUBLIC_FUNC(Coconuts::State_Moving);
    ADD_PUBLIC_FUNC(Coconuts::State_Throwing);
    ADD_PUBLIC_FUNC(Coconuts::State_HasThrown);
    ADD_PUBLIC_FUNC(Coconuts::State_Coconut);

    // EHZ/EggDriller
    ADD_PUBLIC_FUNC(EggDriller::Car_SelfDriving);
    ADD_PUBLIC_FUNC(EggDriller::Car_EggmanEnter);
    ADD_PUBLIC_FUNC(EggDriller::Car_Driving);
    ADD_PUBLIC_FUNC(EggDriller::Car_Explode);
    ADD_PUBLIC_FUNC(EggDriller::Car_Destroyed);
    ADD_PUBLIC_FUNC(EggDriller::Drill_Attached);
    ADD_PUBLIC_FUNC(EggDriller::Drill_Idle);
    ADD_PUBLIC_FUNC(EggDriller::Drill_Fired);
    ADD_PUBLIC_FUNC(EggDriller::Wheel_Attached);
    ADD_PUBLIC_FUNC(EggDriller::Wheel_Idle);
    ADD_PUBLIC_FUNC(EggDriller::Wheel_Bounce);

    // EHZ/EHZEggman
    ADD_PUBLIC_FUNC(EHZEggman::PlayHeliSFX);
    ADD_PUBLIC_FUNC(EHZEggman::State_AwaitPlayer);
    ADD_PUBLIC_FUNC(EHZEggman::State_FlyIn);
    ADD_PUBLIC_FUNC(EHZEggman::State_EnterCar);
    ADD_PUBLIC_FUNC(EHZEggman::State_StartCar);
    ADD_PUBLIC_FUNC(EHZEggman::State_InCar);
    ADD_PUBLIC_FUNC(EHZEggman::State_Explode);
    ADD_PUBLIC_FUNC(EHZEggman::State_ExitCar);
    ADD_PUBLIC_FUNC(EHZEggman::State_Flee);
    ADD_PUBLIC_FUNC(EHZEggman::State_Escape);

    // EHZ/EHZSetup
    ADD_PUBLIC_FUNC(EHZSetup::StageFinish_EndAct1);
    ADD_PUBLIC_FUNC(EHZSetup::HandleActTransition);
    ADD_PUBLIC_FUNC(EHZSetup::StageFinish_EndAct2);

    // EHZ/Masher
    ADD_PUBLIC_FUNC(Masher::DebugDraw);
    ADD_PUBLIC_FUNC(Masher::DebugSpawn);
    ADD_PUBLIC_FUNC(Masher::CheckPlayerCollisions);
    ADD_PUBLIC_FUNC(Masher::State_Jumping);

    // Global/ActClear
    ADD_PUBLIC_FUNC(ActClear::State_EnterResults);
    ADD_PUBLIC_FUNC(ActClear::State_ScoreShownDelay);
    ADD_PUBLIC_FUNC(ActClear::State_TallyScore);
    ADD_PUBLIC_FUNC(ActClear::State_SaveGameProgress);
    ADD_PUBLIC_FUNC(ActClear::State_ShowResultsTA);
    ADD_PUBLIC_FUNC(ActClear::State_WaitForSave);
    ADD_PUBLIC_FUNC(ActClear::State_EndEvent);
    ADD_PUBLIC_FUNC(ActClear::State_RecoverPlayers);
    ADD_PUBLIC_FUNC(ActClear::DrawNumbers);
    ADD_PUBLIC_FUNC(ActClear::DrawTime);
    ADD_PUBLIC_FUNC(ActClear::CheckPlayerVictory);
    ADD_PUBLIC_FUNC(ActClear::SetupForceOnScreenP2);
    ADD_PUBLIC_FUNC(ActClear::SaveGameCallback);

    // Global/Animals
    ADD_PUBLIC_FUNC(Animals::CheckDirection);
    ADD_PUBLIC_FUNC(Animals::CheckPlatformCollision);
    ADD_PUBLIC_FUNC(Animals::CheckGroundCollision);
    ADD_PUBLIC_FUNC(Animals::State_Fall);
    ADD_PUBLIC_FUNC(Animals::State_Fly);
    ADD_PUBLIC_FUNC(Animals::State_Bounce);
    ADD_PUBLIC_FUNC(Animals::State_Placed);
    ADD_PUBLIC_FUNC(Animals::State_IntroFly);
    ADD_PUBLIC_FUNC(Animals::State_IntroBounce);
    ADD_PUBLIC_FUNC(Animals::State_FlyAround);
    ADD_PUBLIC_FUNC(Animals::State_WaitBounce);
    ADD_PUBLIC_FUNC(Animals::State_FlyAway);
    ADD_PUBLIC_FUNC(Animals::State_MissionPlaced);

    // Global/Announcer
    ADD_PUBLIC_FUNC(Announcer::StartCountdown);
    ADD_PUBLIC_FUNC(Announcer::AnnounceGoal);
    ADD_PUBLIC_FUNC(Announcer::Draw_Countdown);
    ADD_PUBLIC_FUNC(Announcer::Draw_Finished);
    ADD_PUBLIC_FUNC(Announcer::State_Countdown);
    ADD_PUBLIC_FUNC(Announcer::State_Finished);

    // Global/BoundsMarker
    ADD_PUBLIC_FUNC(BoundsMarker::State_Init);
    ADD_PUBLIC_FUNC(BoundsMarker::State_Apply);
    ADD_PUBLIC_FUNC(BoundsMarker::State_Restore);
    ADD_PUBLIC_FUNC(BoundsMarker::StoreBounds);
    ADD_PUBLIC_FUNC(BoundsMarker::RestoreBounds);
    ADD_PUBLIC_FUNC(BoundsMarker::Unknown3);
    ADD_PUBLIC_FUNC(BoundsMarker::Unknown4);
    ADD_PUBLIC_FUNC(BoundsMarker::ApplyBounds);
    ADD_PUBLIC_FUNC(BoundsMarker::ApplyAllBounds);
    ADD_PUBLIC_FUNC(BoundsMarker::CheckOnScreen);
    ADD_PUBLIC_FUNC(BoundsMarker::GetNearestX);

    // Global/Camera
    ADD_PUBLIC_FUNC(Camera::SetCameraBoundsXY);
    ADD_PUBLIC_FUNC(Camera::SetCameraBoundsX);
    ADD_PUBLIC_FUNC(Camera::SetTargetEntity);
    ADD_PUBLIC_FUNC(Camera::ShakeScreen);
    ADD_PUBLIC_FUNC(Camera::HandleHBounds);
    ADD_PUBLIC_FUNC(Camera::HandleVBounds);
    ADD_PUBLIC_FUNC(Camera::State_Init);
    ADD_PUBLIC_FUNC(Camera::State_MapView);
    ADD_PUBLIC_FUNC(Camera::State_Center);
    ADD_PUBLIC_FUNC(Camera::State_FollowXY);
    ADD_PUBLIC_FUNC(Camera::State_FollowX);
    ADD_PUBLIC_FUNC(Camera::State_FollowY);

    // Global/COverlay
    ADD_PUBLIC_FUNC(COverlay::DebugDraw);
    ADD_PUBLIC_FUNC(COverlay::DebugSpawn);
    ADD_PUBLIC_FUNC(COverlay::DrawTile);

    // Global/Debris
    ADD_PUBLIC_FUNC(Debris::StateDraw_Default);
    ADD_PUBLIC_FUNC(Debris::State_Init);
    ADD_PUBLIC_FUNC(Debris::State_Move);
    ADD_PUBLIC_FUNC(Debris::State_Fall);
    ADD_PUBLIC_FUNC(Debris::CheckPlayerCollisions);
    ADD_PUBLIC_FUNC(Debris::CreateFromEntries);
    ADD_PUBLIC_FUNC(Debris::State_Destroy);
    ADD_PUBLIC_FUNC(Debris::VelocityFromID);

    // Global/DebugMode
    ADD_PUBLIC_FUNC(DebugMode::State_None);

    // Global/Dust
    ADD_PUBLIC_FUNC(Dust::State_SpinDash);
    ADD_PUBLIC_FUNC(Dust::State_DustTrail);
    ADD_PUBLIC_FUNC(Dust::State_DustPuff);
    ADD_PUBLIC_FUNC(Dust::State_DustPuff_Collide);
    ADD_PUBLIC_FUNC(Dust::State_GlideTrail);
    ADD_PUBLIC_FUNC(Dust::State_Static);

    // Global/EggPrison
    ADD_PUBLIC_FUNC(EggPrison::DebugSpawn);
    ADD_PUBLIC_FUNC(EggPrison::DebugDraw);
    ADD_PUBLIC_FUNC(EggPrison::HoverMovement);
    ADD_PUBLIC_FUNC(EggPrison::State_Init);
    ADD_PUBLIC_FUNC(EggPrison::State_Idle);
    ADD_PUBLIC_FUNC(EggPrison::State_OpenPt1);
    ADD_PUBLIC_FUNC(EggPrison::State_OpenPt2);
    ADD_PUBLIC_FUNC(EggPrison::State_Wait);
    ADD_PUBLIC_FUNC(EggPrison::State_FlyAway);

    // Global/Explosion
    ADD_PUBLIC_FUNC(Explosion::Spawn);
    ADD_PUBLIC_FUNC(Explosion::SpawnGroup);

    // Global/GameOver
    ADD_PUBLIC_FUNC(GameOver::SaveGameCallback);
    ADD_PUBLIC_FUNC(GameOver::State_MoveIn);
    ADD_PUBLIC_FUNC(GameOver::State_Wait);
    ADD_PUBLIC_FUNC(GameOver::State_MoveOut);

    // Global/HUD
    ADD_PUBLIC_FUNC(HUD::DrawLifeNumbers);
    ADD_PUBLIC_FUNC(HUD::DrawNumbersBase10);
    ADD_PUBLIC_FUNC(HUD::DrawNumbersBase16);
    ADD_PUBLIC_FUNC(HUD::DrawNumbersHyperRing);
    ADD_PUBLIC_FUNC(HUD::GetButtonFrame);
    ADD_PUBLIC_FUNC(HUD::GetActionButtonFrames);
    ADD_PUBLIC_FUNC(HUD::State_MoveIn);
    ADD_PUBLIC_FUNC(HUD::State_MoveOut);
    ADD_PUBLIC_FUNC(HUD::MoveIn);
    ADD_PUBLIC_FUNC(HUD::MoveOut);
    ADD_PUBLIC_FUNC(HUD::EnableRingFlash);
    ADD_PUBLIC_FUNC(HUD::CharacterIndexFromID);

    // Global/InvisibleBlock
    ADD_PUBLIC_FUNC(InvisibleBlock::DrawSprites);

    // Global/ItemBox
    ADD_PUBLIC_FUNC(ItemBox::DebugDraw);
    ADD_PUBLIC_FUNC(ItemBox::DebugSpawn);
    ADD_PUBLIC_FUNC(ItemBox::State_Done);
    ADD_PUBLIC_FUNC(ItemBox::State_Break);
    ADD_PUBLIC_FUNC(ItemBox::State_IconFinish);
    ADD_PUBLIC_FUNC(ItemBox::State_Idle);
    ADD_PUBLIC_FUNC(ItemBox::State_Falling);
    ADD_PUBLIC_FUNC(ItemBox::CheckHit);
    ADD_PUBLIC_FUNC(ItemBox::GivePowerup);
    ADD_PUBLIC_FUNC(ItemBox::Break);
    ADD_PUBLIC_FUNC(ItemBox::HandleFallingCollision);
    ADD_PUBLIC_FUNC(ItemBox::HandlePlatformCollision);
    ADD_PUBLIC_FUNC(ItemBox::HandleObjectCollisions);

    // Global/Localization
    ADD_PUBLIC_FUNC(Localization::LoadStrings);
    ADD_PUBLIC_FUNC(Localization::GetString);
    ADD_PUBLIC_FUNC(Localization::GetZoneName);

    // Global/Music
    ADD_PUBLIC_FUNC(Music::SetMusicTrack);
    ADD_PUBLIC_FUNC(Music::SwapMusicTrack);
    ADD_PUBLIC_FUNC(Music::Stop);
    ADD_PUBLIC_FUNC(Music::Pause);
    ADD_PUBLIC_FUNC(Music::Resume);
    ADD_PUBLIC_FUNC(Music::IsPlaying);
    ADD_PUBLIC_FUNC(Music::PlayJingle);
    ADD_PUBLIC_FUNC(Music::PlayTrack);
    ADD_PUBLIC_FUNC(Music::Play);
    ADD_PUBLIC_FUNC(Music::PlayAutoMusicQueuedTrack);
    ADD_PUBLIC_FUNC(Music::HandleMusicStack_Powerups);
    ADD_PUBLIC_FUNC(Music::CheckMusicStack_Active);
    ADD_PUBLIC_FUNC(Music::GetNextTrackStartPos);
    ADD_PUBLIC_FUNC(Music::JingleFadeOut);
    ADD_PUBLIC_FUNC(Music::FinishJingle);
    ADD_PUBLIC_FUNC(Music::ClearMusicStack);
    ADD_PUBLIC_FUNC(Music::PlayOnFade);
    ADD_PUBLIC_FUNC(Music::FadeOut);
    ADD_PUBLIC_FUNC(Music::State_PlayOnLoad);
    ADD_PUBLIC_FUNC(Music::State_Jingle);
    ADD_PUBLIC_FUNC(Music::State_FadeTrackIn);
    ADD_PUBLIC_FUNC(Music::State_JingleFade);
    ADD_PUBLIC_FUNC(Music::State_StopOnFade);
    ADD_PUBLIC_FUNC(Music::State_PlayOnFade);

    // Global/PauseMenu
    ADD_PUBLIC_FUNC(PauseMenu::SetupMenu);
    ADD_PUBLIC_FUNC(PauseMenu::SetupTintTable);
    ADD_PUBLIC_FUNC(PauseMenu::AddButton);
    ADD_PUBLIC_FUNC(PauseMenu::ClearButtons);
    ADD_PUBLIC_FUNC(PauseMenu::HandleButtonPositions);
    ADD_PUBLIC_FUNC(PauseMenu::PauseSound);
    ADD_PUBLIC_FUNC(PauseMenu::ResumeSound);
    ADD_PUBLIC_FUNC(PauseMenu::StopSound);
    ADD_PUBLIC_FUNC(PauseMenu::FocusCamera);
    ADD_PUBLIC_FUNC(PauseMenu::UpdateCameras);
    ADD_PUBLIC_FUNC(PauseMenu::CheckAndReassignControllers);
    ADD_PUBLIC_FUNC(PauseMenu::IsDisconnected);
    ADD_PUBLIC_FUNC(PauseMenu::GetPlayerCount);
    ADD_PUBLIC_FUNC(PauseMenu::ResumeButtonCB);
    ADD_PUBLIC_FUNC(PauseMenu::RestartButtonCB);
    ADD_PUBLIC_FUNC(PauseMenu::ExitButtonCB);
    ADD_PUBLIC_FUNC(PauseMenu::RestartDialog_YesCB);
    ADD_PUBLIC_FUNC(PauseMenu::ExitDialog_YesCB);
    ADD_PUBLIC_FUNC(PauseMenu::RestartFadeCB);
    ADD_PUBLIC_FUNC(PauseMenu::ExitFadeCB);
    ADD_PUBLIC_FUNC(PauseMenu::ActionCB_Button);
    ADD_PUBLIC_FUNC(PauseMenu::State_SetupButtons);
    ADD_PUBLIC_FUNC(PauseMenu::State_StartPause);
    ADD_PUBLIC_FUNC(PauseMenu::State_Paused);
    ADD_PUBLIC_FUNC(PauseMenu::State_ForcedPause);
    ADD_PUBLIC_FUNC(PauseMenu::State_Resume);
    ADD_PUBLIC_FUNC(PauseMenu::State_SetupTitleFade);
    ADD_PUBLIC_FUNC(PauseMenu::State_FadeToTitle);
    ADD_PUBLIC_FUNC(PauseMenu::State_HandleFadeout);
    ADD_PUBLIC_FUNC(PauseMenu::DrawStartPause);
    ADD_PUBLIC_FUNC(PauseMenu::DrawPauseMenu);
    ADD_PUBLIC_FUNC(PauseMenu::DrawEndPause);
    ADD_PUBLIC_FUNC(PauseMenu::Draw_RegularPause);
    ADD_PUBLIC_FUNC(PauseMenu::Draw_ForcePause);

    // Global/PlaneSwitch
    ADD_PUBLIC_FUNC(PlaneSwitch::DrawSprites);
    ADD_PUBLIC_FUNC(PlaneSwitch::CheckCollisions);

    // Global/Player
    ADD_PUBLIC_FUNC(Player::LoadSprites);
    ADD_PUBLIC_FUNC(Player::LoadPlayerSprites);
    ADD_PUBLIC_FUNC(Player::DrawSprite);
    ADD_PUBLIC_FUNC(Player::CheckValidState);
    ADD_PUBLIC_FUNC(Player::SaveValues);
    ADD_PUBLIC_FUNC(Player::GiveScoreBonus);
    ADD_PUBLIC_FUNC(Player::GiveScore);
    ADD_PUBLIC_FUNC(Player::GiveRings);
    ADD_PUBLIC_FUNC(Player::GiveLife);
    ADD_PUBLIC_FUNC(Player::UpdatePhysicsState);
    ADD_PUBLIC_FUNC(Player::ApplyShield);
    ADD_PUBLIC_FUNC(Player::ChangeCharacter);
    ADD_PUBLIC_FUNC(Player::InvertGravity);
    ADD_PUBLIC_FUNC(Player::TryTransform);
    ADD_PUBLIC_FUNC(Player::GetNearestPlayerX);
    ADD_PUBLIC_FUNC(Player::GetNearestPlayerXY);
    ADD_PUBLIC_FUNC(Player::HandleIdleAnimation_Classic);
    ADD_PUBLIC_FUNC(Player::HandleGroundAnimation_Classic);
    ADD_PUBLIC_FUNC(Player::HandleIdleAnimation);
    ADD_PUBLIC_FUNC(Player::HandleGroundAnimation);
    ADD_PUBLIC_FUNC(Player::HandleGroundMovement);
    ADD_PUBLIC_FUNC(Player::HandleGroundRotation);
    ADD_PUBLIC_FUNC(Player::HandleAirRotation);
    ADD_PUBLIC_FUNC(Player::HandleAirMovement);
    ADD_PUBLIC_FUNC(Player::HandleAirFriction);
    ADD_PUBLIC_FUNC(Player::HandleRollDeceleration);
    ADD_PUBLIC_FUNC(Player::CheckStartFlyCarry);
    ADD_PUBLIC_FUNC(Player::HandleSuperColors_Sonic);
    ADD_PUBLIC_FUNC(Player::HandleSuperColors_Tails);
    ADD_PUBLIC_FUNC(Player::HandleSuperColors_Knux);
    ADD_PUBLIC_FUNC(Player::HandleSuperForm);
    ADD_PUBLIC_FUNC(Player::DoSuperDash);
    ADD_PUBLIC_FUNC(Player::FinishedReturnToPlayer);
    ADD_PUBLIC_FUNC(Player::ResetBoundaries);
    ADD_PUBLIC_FUNC(Player::HandleDeath);
    ADD_PUBLIC_FUNC(Player::Action_Jump);
    ADD_PUBLIC_FUNC(Player::Action_Roll);
    ADD_PUBLIC_FUNC(Player::Action_Spindash);
    ADD_PUBLIC_FUNC(Player::Action_Peelout);
    ADD_PUBLIC_FUNC(Player::Action_DblJumpSonic);
    ADD_PUBLIC_FUNC(Player::Action_DblJumpTails);
    ADD_PUBLIC_FUNC(Player::Action_DblJumpKnux);
    ADD_PUBLIC_FUNC(Player::Action_SuperDash);
    ADD_PUBLIC_FUNC(Player::State_Static);
    ADD_PUBLIC_FUNC(Player::State_Ground);
    ADD_PUBLIC_FUNC(Player::State_Air);
    ADD_PUBLIC_FUNC(Player::State_LookUp);
    ADD_PUBLIC_FUNC(Player::State_Crouch);
    ADD_PUBLIC_FUNC(Player::State_Roll);
    ADD_PUBLIC_FUNC(Player::State_Spindash);
    ADD_PUBLIC_FUNC(Player::State_Peelout);
    ADD_PUBLIC_FUNC(Player::State_Hurt);
    ADD_PUBLIC_FUNC(Player::State_Death);
    ADD_PUBLIC_FUNC(Player::State_Drown);
    ADD_PUBLIC_FUNC(Player::State_DeathHold);
    ADD_PUBLIC_FUNC(Player::State_DropDash);
    ADD_PUBLIC_FUNC(Player::State_BubbleBounce);
    ADD_PUBLIC_FUNC(Player::State_TailsFlight);
    ADD_PUBLIC_FUNC(Player::State_FlyCarried);
    ADD_PUBLIC_FUNC(Player::State_KnuxGlideLeft);
    ADD_PUBLIC_FUNC(Player::State_KnuxGlideRight);
    ADD_PUBLIC_FUNC(Player::State_KnuxGlideDrop);
    ADD_PUBLIC_FUNC(Player::State_KnuxGlideSlide);
    ADD_PUBLIC_FUNC(Player::State_KnuxWallClimb);
    ADD_PUBLIC_FUNC(Player::State_KnuxLedgePullUp);
    ADD_PUBLIC_FUNC(Player::State_FlyToPlayer);
    ADD_PUBLIC_FUNC(Player::State_ReturnToPlayer);
    ADD_PUBLIC_FUNC(Player::State_HoldRespawn);
    ADD_PUBLIC_FUNC(Player::State_Victory);
    ADD_PUBLIC_FUNC(Player::State_TubeRoll);
    ADD_PUBLIC_FUNC(Player::State_TubeAirRoll);
    ADD_PUBLIC_FUNC(Player::State_TransportTube);
    ADD_PUBLIC_FUNC(Player::State_WaterSlide);
    ADD_PUBLIC_FUNC(Player::State_WaterCurrent);
    ADD_PUBLIC_FUNC(Player::State_GroundFalse);
    ADD_PUBLIC_FUNC(Player::State_Transform);
    ADD_PUBLIC_FUNC(Player::State_StartSuper);
    ADD_PUBLIC_FUNC(Player::State_SuperFlying);
    ADD_PUBLIC_FUNC(Player::Gravity_NULL);
    ADD_PUBLIC_FUNC(Player::Gravity_True);
    ADD_PUBLIC_FUNC(Player::Gravity_False);
    ADD_PUBLIC_FUNC(Player::DisableInputs);
    ADD_PUBLIC_FUNC(Player::CheckP2KeyPress);
    ADD_PUBLIC_FUNC(Player::HandleSidekickRespawn);
    ADD_PUBLIC_FUNC(Player::GetDelayedInput);
    ADD_PUBLIC_FUNC(Player::Input_Gamepad);
    ADD_PUBLIC_FUNC(Player::Input_GamepadAssist);
    ADD_PUBLIC_FUNC(Player::Input_NULL);
    ADD_PUBLIC_FUNC(Player::Input_AI_WaitForP1);
    ADD_PUBLIC_FUNC(Player::Input_AI_Follow);
    ADD_PUBLIC_FUNC(Player::Input_AI_SpindashPt1);
    ADD_PUBLIC_FUNC(Player::Input_AI_SpindashPt2);
    ADD_PUBLIC_FUNC(Player::GetHitbox);
    ADD_PUBLIC_FUNC(Player::GetAltHitbox);
    ADD_PUBLIC_FUNC(Player::CheckCollisionTouch);
    ADD_PUBLIC_FUNC(Player::CheckCollisionTouchDefault);
    ADD_PUBLIC_FUNC(Player::BoxCollisionResponce);
    ADD_PUBLIC_FUNC(Player::CheckCollisionBox);
    ADD_PUBLIC_FUNC(Player::CheckCollisionPlatform);
    ADD_PUBLIC_FUNC(Player::Hit);
    ADD_PUBLIC_FUNC(Player::Hurt);
    ADD_PUBLIC_FUNC(Player::HurtFlip);
    ADD_PUBLIC_FUNC(Player::FireHurt);
    ADD_PUBLIC_FUNC(Player::CheckAttacking);
    ADD_PUBLIC_FUNC(Player::CheckBadnikTouch);
    ADD_PUBLIC_FUNC(Player::CheckBadnikBreak);
    ADD_PUBLIC_FUNC(Player::CheckBossHit);
    ADD_PUBLIC_FUNC(Player::LightningHurt);
    ADD_PUBLIC_FUNC(Player::ProjectileHurt);

    // Global/ReplayRecorder
    ADD_PUBLIC_FUNC(ReplayRecorder::TitleCardCB);
    ADD_PUBLIC_FUNC(ReplayRecorder::Resume);
    ADD_PUBLIC_FUNC(ReplayRecorder::StartCB);
    ADD_PUBLIC_FUNC(ReplayRecorder::FinishCB);
    ADD_PUBLIC_FUNC(ReplayRecorder::Buffer_Move);
    ADD_PUBLIC_FUNC(ReplayRecorder::SaveReplayDLG_NoCB);
    ADD_PUBLIC_FUNC(ReplayRecorder::SaveReplayDLG_YesCB);
    ADD_PUBLIC_FUNC(ReplayRecorder::SaveReplayDLG_CB);
    ADD_PUBLIC_FUNC(ReplayRecorder::SaveReplay);
    ADD_PUBLIC_FUNC(ReplayRecorder::SaveFile_Replay);
    ADD_PUBLIC_FUNC(ReplayRecorder::SaveCallback_ReplayDB);
    ADD_PUBLIC_FUNC(ReplayRecorder::SaveCallback_TimeAttackDB);
    ADD_PUBLIC_FUNC(ReplayRecorder::Buffer_PackInPlace);
    ADD_PUBLIC_FUNC(ReplayRecorder::Buffer_Unpack);
    ADD_PUBLIC_FUNC(ReplayRecorder::Buffer_LoadFile);
    ADD_PUBLIC_FUNC(ReplayRecorder::Buffer_SaveFile);
    ADD_PUBLIC_FUNC(ReplayRecorder::LoadReplayCallback);
    ADD_PUBLIC_FUNC(ReplayRecorder::SaveReplayCallback);
    ADD_PUBLIC_FUNC(ReplayRecorder::ConfigureGhost_CB);
    ADD_PUBLIC_FUNC(ReplayRecorder::SetupActions);
    ADD_PUBLIC_FUNC(ReplayRecorder::SetupWriteBuffer);
    ADD_PUBLIC_FUNC(ReplayRecorder::DrawGhostDisplay);
    ADD_PUBLIC_FUNC(ReplayRecorder::Record);
    ADD_PUBLIC_FUNC(ReplayRecorder::StartRecording);
    ADD_PUBLIC_FUNC(ReplayRecorder::Play);
    ADD_PUBLIC_FUNC(ReplayRecorder::Rewind);
    ADD_PUBLIC_FUNC(ReplayRecorder::Seek);
    ADD_PUBLIC_FUNC(ReplayRecorder::SeekFunc);
    ADD_PUBLIC_FUNC(ReplayRecorder::Stop);
    ADD_PUBLIC_FUNC(ReplayRecorder::SetGimmickState);
    ADD_PUBLIC_FUNC(ReplayRecorder::ForceApplyFramePtr);
    ADD_PUBLIC_FUNC(ReplayRecorder::ApplyFramePtr);
    ADD_PUBLIC_FUNC(ReplayRecorder::CheckPlayerGimmickState);
    ADD_PUBLIC_FUNC(ReplayRecorder::PackFrame);
    ADD_PUBLIC_FUNC(ReplayRecorder::PlayBackInput);
    ADD_PUBLIC_FUNC(ReplayRecorder::Pause);
    ADD_PUBLIC_FUNC(ReplayRecorder::PlayerState_PlaybackReplay);
    ADD_PUBLIC_FUNC(ReplayRecorder::Late_Playback);
    ADD_PUBLIC_FUNC(ReplayRecorder::Late_RecordFrames);
    ADD_PUBLIC_FUNC(ReplayRecorder::State_SetupPlayback);
    ADD_PUBLIC_FUNC(ReplayRecorder::State_Playback);
    ADD_PUBLIC_FUNC(ReplayRecorder::State_Record);

    // Global/Ring
    ADD_PUBLIC_FUNC(Ring::DebugSpawn);
    ADD_PUBLIC_FUNC(Ring::DebugDraw);
    ADD_PUBLIC_FUNC(Ring::Collect);
    ADD_PUBLIC_FUNC(Ring::LoseRings);
    ADD_PUBLIC_FUNC(Ring::LoseHyperRings);
    ADD_PUBLIC_FUNC(Ring::FakeLoseRings);
    ADD_PUBLIC_FUNC(Ring::CheckPlatformCollisions);
    ADD_PUBLIC_FUNC(Ring::CheckObjectCollisions);
    ADD_PUBLIC_FUNC(Ring::State_Normal);
    ADD_PUBLIC_FUNC(Ring::State_Linear);
    ADD_PUBLIC_FUNC(Ring::State_Circular);
    ADD_PUBLIC_FUNC(Ring::State_Path);
    ADD_PUBLIC_FUNC(Ring::State_Track);
    ADD_PUBLIC_FUNC(Ring::State_Lost);
    ADD_PUBLIC_FUNC(Ring::State_LostFX);
    ADD_PUBLIC_FUNC(Ring::State_Combi);
    ADD_PUBLIC_FUNC(Ring::State_Attracted);
    ADD_PUBLIC_FUNC(Ring::State_Sparkle);
    ADD_PUBLIC_FUNC(Ring::Draw_Normal);
    ADD_PUBLIC_FUNC(Ring::Draw_Oscillating);
    ADD_PUBLIC_FUNC(Ring::Draw_Sparkle);

    // Global/SaveGame
    ADD_PUBLIC_FUNC(SaveGame::LoadSaveData);
    ADD_PUBLIC_FUNC(SaveGame::RecallCollectedEntities);
    ADD_PUBLIC_FUNC(SaveGame::LoadFileCB);
    ADD_PUBLIC_FUNC(SaveGame::SaveFileCB);
    ADD_PUBLIC_FUNC(SaveGame::GetSaveDataPtr);
    ADD_PUBLIC_FUNC(SaveGame::CheckDisableRestart);
    ADD_PUBLIC_FUNC(SaveGame::GetSaveRAM);
    ADD_PUBLIC_FUNC(SaveGame::LoadFile);
    ADD_PUBLIC_FUNC(SaveGame::SaveFile);
    ADD_PUBLIC_FUNC(SaveGame::SaveLoadedCB);
    ADD_PUBLIC_FUNC(SaveGame::SaveProgress);
    ADD_PUBLIC_FUNC(SaveGame::ClearNoSave);
    ADD_PUBLIC_FUNC(SaveGame::ClearSaveSlot);
    ADD_PUBLIC_FUNC(SaveGame::ClearRestartData);
    ADD_PUBLIC_FUNC(SaveGame::StoreStageState);
    ADD_PUBLIC_FUNC(SaveGame::SavePlayerState);
    ADD_PUBLIC_FUNC(SaveGame::LoadPlayerState);
    ADD_PUBLIC_FUNC(SaveGame::ResetPlayerState);
    ADD_PUBLIC_FUNC(SaveGame::LoadGameState);
    ADD_PUBLIC_FUNC(SaveGame::SaveGameState);
    ADD_PUBLIC_FUNC(SaveGame::AllChaosEmeralds);
    ADD_PUBLIC_FUNC(SaveGame::GetEmeralds);
    ADD_PUBLIC_FUNC(SaveGame::SetEmeralds);
    ADD_PUBLIC_FUNC(SaveGame::GetEmerald);
    ADD_PUBLIC_FUNC(SaveGame::SetEmerald);
    ADD_PUBLIC_FUNC(SaveGame::ClearCollectedSpecialRings);
    ADD_PUBLIC_FUNC(SaveGame::GetCollectedSpecialRing);
    ADD_PUBLIC_FUNC(SaveGame::SetCollectedSpecialRing);

    // Global/Shield
    ADD_PUBLIC_FUNC(Shield::SpawnLightningSparks);
    ADD_PUBLIC_FUNC(Shield::State_Default);
    ADD_PUBLIC_FUNC(Shield::State_Insta);
    ADD_PUBLIC_FUNC(Shield::State_BubbleDrop);
    ADD_PUBLIC_FUNC(Shield::State_BubbleBounce);
    ADD_PUBLIC_FUNC(Shield::State_FireDash);
    ADD_PUBLIC_FUNC(Shield::State_LightningSparks);
    ADD_PUBLIC_FUNC(Shield::State_LightningFlash);

    // Global/SignPost
    ADD_PUBLIC_FUNC(SignPost::DebugSpawn);
    ADD_PUBLIC_FUNC(SignPost::DebugDraw);
    ADD_PUBLIC_FUNC(SignPost::State_Done);
    ADD_PUBLIC_FUNC(SignPost::State_InitDelay);
    ADD_PUBLIC_FUNC(SignPost::Spawn);
    ADD_PUBLIC_FUNC(SignPost::State_Fall_Classic);
    ADD_PUBLIC_FUNC(SignPost::HandleSpin);
    ADD_PUBLIC_FUNC(SignPost::HandleSparkles);
    ADD_PUBLIC_FUNC(SignPost::State_Sparkle_Classic);
    ADD_PUBLIC_FUNC(SignPost::HandleCamBounds);
    ADD_PUBLIC_FUNC(SignPost::CheckTouch);
    ADD_PUBLIC_FUNC(SignPost::State_SpinVS);
    ADD_PUBLIC_FUNC(SignPost::State_Spin);
    ADD_PUBLIC_FUNC(SignPost::State_FlyUp);
    ADD_PUBLIC_FUNC(SignPost::State_Wait);
    ADD_PUBLIC_FUNC(SignPost::State_Falling);
    ADD_PUBLIC_FUNC(SignPost::State_FakeFalling);
    ADD_PUBLIC_FUNC(SignPost::State_Landed_Classic);

    // Global/SpecialRing
    ADD_PUBLIC_FUNC(SpecialRing::DebugSpawn);
    ADD_PUBLIC_FUNC(SpecialRing::DebugDraw);
    ADD_PUBLIC_FUNC(SpecialRing::State_Idle);
    ADD_PUBLIC_FUNC(SpecialRing::State_Flash);
    ADD_PUBLIC_FUNC(SpecialRing::State_Warp);

    // Global/Spikes
    ADD_PUBLIC_FUNC(Spikes::Draw_Normal);
    ADD_PUBLIC_FUNC(Spikes::CheckHit);

    // Global/Spring
    ADD_PUBLIC_FUNC(Spring::DebugSpawn);
    ADD_PUBLIC_FUNC(Spring::DebugDraw);
    ADD_PUBLIC_FUNC(Spring::State_Vertical);
    ADD_PUBLIC_FUNC(Spring::State_Horizontal);
    ADD_PUBLIC_FUNC(Spring::State_Diagonal);
    ADD_PUBLIC_FUNC(Spring::State_Falling);

    // Global/StarPost
    ADD_PUBLIC_FUNC(StarPost::DebugDraw);
    ADD_PUBLIC_FUNC(StarPost::DebugSpawn);
    ADD_PUBLIC_FUNC(StarPost::ResetStarPosts);
    ADD_PUBLIC_FUNC(StarPost::CheckBonusStageEntry);
    ADD_PUBLIC_FUNC(StarPost::CheckCollisions);
    ADD_PUBLIC_FUNC(StarPost::State_Idle);
    ADD_PUBLIC_FUNC(StarPost::State_Spinning);

    // Global/SuperFlicky
    ADD_PUBLIC_FUNC(SuperFlicky::HandleSuperColors);
    ADD_PUBLIC_FUNC(SuperFlicky::HandleAttack);
    ADD_PUBLIC_FUNC(SuperFlicky::State_Init);
    ADD_PUBLIC_FUNC(SuperFlicky::State_Active);
    ADD_PUBLIC_FUNC(SuperFlicky::State_Restore);
    ADD_PUBLIC_FUNC(SuperFlicky::State_Drop);
    ADD_PUBLIC_FUNC(SuperFlicky::State_FlyAway);

    // Global/SuperSparkle
    ADD_PUBLIC_FUNC(SuperSparkle::State_SuperSparkle);

    // Global/TimeAttackGate
    ADD_PUBLIC_FUNC(TimeAttackGate::HandleSpin);
    ADD_PUBLIC_FUNC(TimeAttackGate::HandleStart);
    ADD_PUBLIC_FUNC(TimeAttackGate::AddRecord);
    ADD_PUBLIC_FUNC(TimeAttackGate::WaitSave_Leaderboards);
    ADD_PUBLIC_FUNC(TimeAttackGate::CheckTouch);
    ADD_PUBLIC_FUNC(TimeAttackGate::State_Gate);
    ADD_PUBLIC_FUNC(TimeAttackGate::State_Restarter);
    ADD_PUBLIC_FUNC(TimeAttackGate::State_Fadeout);
    ADD_PUBLIC_FUNC(TimeAttackGate::Draw_Gate);
    ADD_PUBLIC_FUNC(TimeAttackGate::Draw_Restarter);

    // Global/TitleCard
    ADD_PUBLIC_FUNC(TitleCard::ChangeTitleColors);
    ADD_PUBLIC_FUNC(TitleCard::SetupTitleWords);
    ADD_PUBLIC_FUNC(TitleCard::HandleCamera);
    ADD_PUBLIC_FUNC(TitleCard::PiecePositions);
    ADD_PUBLIC_FUNC(TitleCard::MovePositions_SlideIn);
    ADD_PUBLIC_FUNC(TitleCard::MovePositions_ShowTitle);
    ADD_PUBLIC_FUNC(TitleCard::MovePositions_SlideAway);
    ADD_PUBLIC_FUNC(TitleCard::State_SetupBGElements);
    ADD_PUBLIC_FUNC(TitleCard::State_OpeningBG);
    ADD_PUBLIC_FUNC(TitleCard::State_EnterTitle);
    ADD_PUBLIC_FUNC(TitleCard::State_ShowingTitle);
    ADD_PUBLIC_FUNC(TitleCard::State_SlideAway);
    ADD_PUBLIC_FUNC(TitleCard::State_Supressed);
    ADD_PUBLIC_FUNC(TitleCard::Draw_SlideIn);
    ADD_PUBLIC_FUNC(TitleCard::Draw_ShowTitleCard);
    ADD_PUBLIC_FUNC(TitleCard::Draw_SlideAway);

    // Global/Zone
    ADD_PUBLIC_FUNC(Zone::GetZoneID);
    ADD_PUBLIC_FUNC(Zone::HandlePlayerBounds);
    ADD_PUBLIC_FUNC(Zone::AddToHyperList);
    ADD_PUBLIC_FUNC(Zone::StoreEntities);
    ADD_PUBLIC_FUNC(Zone::ReloadEntities);
    ADD_PUBLIC_FUNC(Zone::StartFadeOut);
    ADD_PUBLIC_FUNC(Zone::StartFadeOut_MusicFade);
    ADD_PUBLIC_FUNC(Zone::GoBonus_Pinball);
    ADD_PUBLIC_FUNC(Zone::StartTeleportAction);
    ADD_PUBLIC_FUNC(Zone::RotateOnPivot);
    ADD_PUBLIC_FUNC(Zone::Draw_Fade);
    ADD_PUBLIC_FUNC(Zone::State_Fade);
    ADD_PUBLIC_FUNC(Zone::ApplyWorldBounds);
    ADD_PUBLIC_FUNC(Zone::CurrentID);
    ADD_PUBLIC_FUNC(Zone::CurrentStageSaveable);
    ADD_PUBLIC_FUNC(Zone::GetListPos);
    ADD_PUBLIC_FUNC(Zone::GetTileInfo);
    ADD_PUBLIC_FUNC(Zone::GetZoneListPos);

    // Helpers/BadnikHelpers
    ADD_PUBLIC_FUNC(BadnikHelpers::BadnikBreak);
    ADD_PUBLIC_FUNC(BadnikHelpers::BadnikBreakUnseeded);
    ADD_PUBLIC_FUNC(BadnikHelpers::Oscillate);

    // Helpers/CutsceneRules
    ADD_PUBLIC_FUNC(CutsceneRules::CheckAct1);
    ADD_PUBLIC_FUNC(CutsceneRules::CheckAct2);
    ADD_PUBLIC_FUNC(CutsceneRules::CheckOutroAct2);
    ADD_PUBLIC_FUNC(CutsceneRules::CheckOutroAct1);
    ADD_PUBLIC_FUNC(CutsceneRules::CheckStageReload);

    // Helpers/CutsceneSeq
    ADD_PUBLIC_FUNC(CutsceneSeq::NewState);
    ADD_PUBLIC_FUNC(CutsceneSeq::SetSkipType);
    ADD_PUBLIC_FUNC(CutsceneSeq::CheckSkip);
    ADD_PUBLIC_FUNC(CutsceneSeq::GetEntity);
    ADD_PUBLIC_FUNC(CutsceneSeq::LockPlayerControl);
    ADD_PUBLIC_FUNC(CutsceneSeq::LockAllPlayerControl);
    ADD_PUBLIC_FUNC(CutsceneSeq::StartSequence);

    // Helpers/DialogRunner
    ADD_PUBLIC_FUNC(DialogRunner::HandleCallback);
    ADD_PUBLIC_FUNC(DialogRunner::NotifyAutoSave_CB);
    ADD_PUBLIC_FUNC(DialogRunner::NotifyAutoSave);
    ADD_PUBLIC_FUNC(DialogRunner::SetNoSaveDisabled);
    ADD_PUBLIC_FUNC(DialogRunner::SetNoSaveEnabled);
    ADD_PUBLIC_FUNC(DialogRunner::PromptSavePreference_CB);
    ADD_PUBLIC_FUNC(DialogRunner::CheckUserAuth_CB);
    ADD_PUBLIC_FUNC(DialogRunner::ManageNotifs);
    ADD_PUBLIC_FUNC(DialogRunner::TrackGameProgressCB);
    ADD_PUBLIC_FUNC(DialogRunner::GetNextNotif);
    ADD_PUBLIC_FUNC(DialogRunner::CheckUnreadNotifs);
    ADD_PUBLIC_FUNC(DialogRunner::NotifyAutosave);
    ADD_PUBLIC_FUNC(DialogRunner::GetUserAuthStatus);
    ADD_PUBLIC_FUNC(DialogRunner::PromptSavePreference);
    ADD_PUBLIC_FUNC(DialogRunner::CheckUserAuth_OK);

    // Helpers/DrawHelpers
    ADD_PUBLIC_FUNC(DrawHelpers::DrawHitboxOutline);
    ADD_PUBLIC_FUNC(DrawHelpers::DrawPath);
    ADD_PUBLIC_FUNC(DrawHelpers::DrawArrowAdditive);
    ADD_PUBLIC_FUNC(DrawHelpers::DrawIsocelesTriangle);
    ADD_PUBLIC_FUNC(DrawHelpers::DrawLine);
    ADD_PUBLIC_FUNC(DrawHelpers::DrawCross);
    ADD_PUBLIC_FUNC(DrawHelpers::Load);
    ADD_PUBLIC_FUNC(DrawHelpers::DrawArrow);
    ADD_PUBLIC_FUNC(DrawHelpers::DrawRectOutline);
    ADD_PUBLIC_FUNC(DrawHelpers::DrawArenaBounds);

    // Helpers/FXAudioPan
    ADD_PUBLIC_FUNC(FXAudioPan::CheckCB);
    ADD_PUBLIC_FUNC(FXAudioPan::UpdateCB);
    ADD_PUBLIC_FUNC(FXAudioPan::PlayDistancedSfx);
    ADD_PUBLIC_FUNC(FXAudioPan::HandleAudioDistance);

    // Helpers/FXFade
    ADD_PUBLIC_FUNC(FXFade::State_FadeOut);
    ADD_PUBLIC_FUNC(FXFade::State_Wait);
    ADD_PUBLIC_FUNC(FXFade::State_FadeIn);
    ADD_PUBLIC_FUNC(FXFade::State_FadeInBlack);

    // Helpers/FXTileModifier
    ADD_PUBLIC_FUNC(FXTileModifier::GetNearest);
    ADD_PUBLIC_FUNC(FXTileModifier::Find);

    // Helpers/GameProgress
    ADD_PUBLIC_FUNC(GameProgress::GetProgressRAM);
    ADD_PUBLIC_FUNC(GameProgress::Save);
    ADD_PUBLIC_FUNC(GameProgress::DumpProgress);
    ADD_PUBLIC_FUNC(GameProgress::ClearProgress);
    ADD_PUBLIC_FUNC(GameProgress::MarkZoneCompleted);
    ADD_PUBLIC_FUNC(GameProgress::CollectEmerald);
    ADD_PUBLIC_FUNC(GameProgress::GetNotifStringID);
    ADD_PUBLIC_FUNC(GameProgress::CountUnreadNotifs);
    ADD_PUBLIC_FUNC(GameProgress::GetNextNotif);
    ADD_PUBLIC_FUNC(GameProgress::CheckUnlock);

    // Helpers/LogHelpers
    ADD_PUBLIC_FUNC(LogHelpers::PrintText);
    ADD_PUBLIC_FUNC(LogHelpers::PrintString);
    ADD_PUBLIC_FUNC(LogHelpers::PrintInt32);
    ADD_PUBLIC_FUNC(LogHelpers::Print);
    ADD_PUBLIC_FUNC(LogHelpers::PrintVector2);

    // Helpers/MathHelpers
    ADD_PUBLIC_FUNC(MathHelpers::LerpToPos);
    ADD_PUBLIC_FUNC(MathHelpers::Lerp);
    ADD_PUBLIC_FUNC(MathHelpers::LerpSin1024);
    ADD_PUBLIC_FUNC(MathHelpers::Lerp2Sin1024);
    ADD_PUBLIC_FUNC(MathHelpers::LerpSin512);
    ADD_PUBLIC_FUNC(MathHelpers::GetBezierPoint);
    ADD_PUBLIC_FUNC(MathHelpers::SquareRoot);
    ADD_PUBLIC_FUNC(MathHelpers::Distance);
    ADD_PUBLIC_FUNC(MathHelpers::GetBezierCurveLength);
    ADD_PUBLIC_FUNC(MathHelpers::PointInHitbox);
    ADD_PUBLIC_FUNC(MathHelpers::PositionBoxesIntersect);
    ADD_PUBLIC_FUNC(MathHelpers::GetInteractionDir);
    ADD_PUBLIC_FUNC(MathHelpers::CheckValidIntersect);
    ADD_PUBLIC_FUNC(MathHelpers::CheckPositionOverlap);
    ADD_PUBLIC_FUNC(MathHelpers::GetEdgeDistance);
    ADD_PUBLIC_FUNC(MathHelpers::ConstrainToBox);

    // Helpers/MenuParam
    ADD_PUBLIC_FUNC(MenuParam::GetMenuParam);

    // Helpers/Options
    ADD_PUBLIC_FUNC(Options::GetOptionsRAM);
    ADD_PUBLIC_FUNC(Options::Reload);
    ADD_PUBLIC_FUNC(Options::GetWinSize);
    ADD_PUBLIC_FUNC(Options::LoadCallback);
    ADD_PUBLIC_FUNC(Options::LoadOptionsBin);
    ADD_PUBLIC_FUNC(Options::SaveOptionsBin);
    ADD_PUBLIC_FUNC(Options::SetLanguage);
    ADD_PUBLIC_FUNC(Options::LoadValuesFromSettings);
    ADD_PUBLIC_FUNC(Options::LoadOptionsCallback);
    ADD_PUBLIC_FUNC(Options::SaveOptionsCallback);

    // Helpers/PlayerHelpers
    ADD_PUBLIC_FUNC(PlayerHelpers::IsPaused);

    // Helpers/PlayerProbe
    ADD_PUBLIC_FUNC(PlayerProbe::Print);
    ADD_PUBLIC_FUNC(PlayerProbe::DrawSprites);
    ADD_PUBLIC_FUNC(PlayerProbe::DrawArrow);

    // Helpers/ReplayDB
    ADD_PUBLIC_FUNC(ReplayDB::CreateDB);
    ADD_PUBLIC_FUNC(ReplayDB::LoadDB);
    ADD_PUBLIC_FUNC(ReplayDB::SaveDB);
    ADD_PUBLIC_FUNC(ReplayDB::AddReplay);
    ADD_PUBLIC_FUNC(ReplayDB::DeleteReplay);
    ADD_PUBLIC_FUNC(ReplayDB::DeleteReplay_CB);
    ADD_PUBLIC_FUNC(ReplayDB::DeleteReplaySave_CB);
    ADD_PUBLIC_FUNC(ReplayDB::DeleteReplaySave2_CB);
    ADD_PUBLIC_FUNC(ReplayDB::LoadDBCallback);
    ADD_PUBLIC_FUNC(ReplayDB::SaveDBCallback);
    ADD_PUBLIC_FUNC(ReplayDB::LoadCallback);
    ADD_PUBLIC_FUNC(ReplayDB::Buffer_PackEntry);
    ADD_PUBLIC_FUNC(ReplayDB::Buffer_UnpackEntry);

    // Helpers/Soundboard
    ADD_PUBLIC_FUNC(Soundboard::LoadSfx);
    ADD_PUBLIC_FUNC(Soundboard::LoadSfxName);

    // Helpers/TimeAttackData
    ADD_PUBLIC_FUNC(TimeAttackData::TrackActClear);
    ADD_PUBLIC_FUNC(TimeAttackData::TrackTAClear);
    ADD_PUBLIC_FUNC(TimeAttackData::TrackEnemyDefeat);
    ADD_PUBLIC_FUNC(TimeAttackData::GetTimeAttackRAM);
    ADD_PUBLIC_FUNC(TimeAttackData::Clear);
    ADD_PUBLIC_FUNC(TimeAttackData::GetZoneListPos);
    ADD_PUBLIC_FUNC(TimeAttackData::GetPackedTime);
    ADD_PUBLIC_FUNC(TimeAttackData::GetUnpackedTime);
    ADD_PUBLIC_FUNC(TimeAttackData::GetRecordedTime);
    ADD_PUBLIC_FUNC(TimeAttackData::CreateDB);
    ADD_PUBLIC_FUNC(TimeAttackData::LoadDB);
    ADD_PUBLIC_FUNC(TimeAttackData::SaveDB);
    ADD_PUBLIC_FUNC(TimeAttackData::LoadDBCallback);
    ADD_PUBLIC_FUNC(TimeAttackData::SaveDBCallback);
    ADD_PUBLIC_FUNC(TimeAttackData::MigrateLegacySaves);
    ADD_PUBLIC_FUNC(TimeAttackData::AddDBRow);
    ADD_PUBLIC_FUNC(TimeAttackData::AddRecord);
    ADD_PUBLIC_FUNC(TimeAttackData::GetScore);
    ADD_PUBLIC_FUNC(TimeAttackData::GetReplayID);
    ADD_PUBLIC_FUNC(TimeAttackData::ConfigureTableView);
    ADD_PUBLIC_FUNC(TimeAttackData::Leaderboard_GetRank);
    ADD_PUBLIC_FUNC(TimeAttackData::AddLeaderboardEntry);
    ADD_PUBLIC_FUNC(TimeAttackData::GetLeaderboardInfo);

    // HPZ/Batbot
    ADD_PUBLIC_FUNC(Batbot::DebugSpawn);
    ADD_PUBLIC_FUNC(Batbot::DebugDraw);
    ADD_PUBLIC_FUNC(Batbot::CheckPlayerCollisions);
    ADD_PUBLIC_FUNC(Batbot::State_Init);
    ADD_PUBLIC_FUNC(Batbot::State_Idle);
    ADD_PUBLIC_FUNC(Batbot::State_Attack);
    ADD_PUBLIC_FUNC(Batbot::State_SwoopLeft);
    ADD_PUBLIC_FUNC(Batbot::State_SwoopRight);

    // HPZ/HPZSetup
    ADD_PUBLIC_FUNC(HPZSetup::GetTileInfo);

    // HPZ/Jellygnite
    ADD_PUBLIC_FUNC(Jellygnite::DebugSpawn);
    ADD_PUBLIC_FUNC(Jellygnite::DebugDraw);
    ADD_PUBLIC_FUNC(Jellygnite::SetupAnimations);
    ADD_PUBLIC_FUNC(Jellygnite::CheckPlayerCollisions);
    ADD_PUBLIC_FUNC(Jellygnite::HandlePlayerStruggle);
    ADD_PUBLIC_FUNC(Jellygnite::CheckInWater);
    ADD_PUBLIC_FUNC(Jellygnite::DrawBackTentacle);
    ADD_PUBLIC_FUNC(Jellygnite::DrawFrontTentacle);
    ADD_PUBLIC_FUNC(Jellygnite::State_Init);
    ADD_PUBLIC_FUNC(Jellygnite::State_Swimming);
    ADD_PUBLIC_FUNC(Jellygnite::State_GrabbedPlayer);
    ADD_PUBLIC_FUNC(Jellygnite::State_Explode);

    // HPZ/Pendulum
    ADD_PUBLIC_FUNC(Pendulum::DebugDraw);
    ADD_PUBLIC_FUNC(Pendulum::DebugSpawn);

    // HPZ/RailRocket
    ADD_PUBLIC_FUNC(RailRocket::DebugDraw);
    ADD_PUBLIC_FUNC(RailRocket::DebugSpawn);
    ADD_PUBLIC_FUNC(RailRocket::State_AwaitPlayer);
    ADD_PUBLIC_FUNC(RailRocket::State_MoveToTarget);
    ADD_PUBLIC_FUNC(RailRocket::State_ReachedTarget);
    ADD_PUBLIC_FUNC(RailRocket::State_ReturnToStart);
    ADD_PUBLIC_FUNC(RailRocket::State_Finished);

    // HPZ/Redz
    ADD_PUBLIC_FUNC(Redz::DebugSpawn);
    ADD_PUBLIC_FUNC(Redz::DebugDraw);
    ADD_PUBLIC_FUNC(Redz::CheckPlayerCollisions);
    ADD_PUBLIC_FUNC(Redz::State_Init);
    ADD_PUBLIC_FUNC(Redz::State_Walk);
    ADD_PUBLIC_FUNC(Redz::State_Turn);
    ADD_PUBLIC_FUNC(Redz::State_PrepareAttack);
    ADD_PUBLIC_FUNC(Redz::State_Attack);
    ADD_PUBLIC_FUNC(Redz::Flame_Setup);
    ADD_PUBLIC_FUNC(Redz::Flame_State);

    // HPZ/Stegway
    ADD_PUBLIC_FUNC(Stegway::DebugSpawn);
    ADD_PUBLIC_FUNC(Stegway::DebugDraw);
    ADD_PUBLIC_FUNC(Stegway::CheckOffScreen);
    ADD_PUBLIC_FUNC(Stegway::HandlePlayerInteractions);
    ADD_PUBLIC_FUNC(Stegway::SetupAnims);
    ADD_PUBLIC_FUNC(Stegway::State_Init);
    ADD_PUBLIC_FUNC(Stegway::State_Moving);
    ADD_PUBLIC_FUNC(Stegway::State_Turn);
    ADD_PUBLIC_FUNC(Stegway::State_RevUp);
    ADD_PUBLIC_FUNC(Stegway::State_RevRelease);
    ADD_PUBLIC_FUNC(Stegway::State_Dash);

    // HPZ/WaterGush
    ADD_PUBLIC_FUNC(WaterGush::SetupHitboxes);
    ADD_PUBLIC_FUNC(WaterGush::DrawSprites);

    // HTZ/AIZRockPile
    ADD_PUBLIC_FUNC(AIZRockPile::DebugDraw);
    ADD_PUBLIC_FUNC(AIZRockPile::DebugSpawn);
    ADD_PUBLIC_FUNC(AIZRockPile::SpawnRocks);

    // HTZ/HTZSetup
    ADD_PUBLIC_FUNC(HTZSetup::GetTileInfo);

    // HTZ/Rexon
    ADD_PUBLIC_FUNC(Rexon::DebugSpawn);
    ADD_PUBLIC_FUNC(Rexon::DebugDraw);
    ADD_PUBLIC_FUNC(Rexon::CheckOffScreen);
    ADD_PUBLIC_FUNC(Rexon::CheckPlayerCollisions);
    ADD_PUBLIC_FUNC(Rexon::DestroyRexon);
    ADD_PUBLIC_FUNC(Rexon::State_Init);
    ADD_PUBLIC_FUNC(Rexon::State_Hidden);
    ADD_PUBLIC_FUNC(Rexon::State_Rising);
    ADD_PUBLIC_FUNC(Rexon::State_Shooting);
    ADD_PUBLIC_FUNC(Rexon::State_Destroyed);
    ADD_PUBLIC_FUNC(Rexon::State_Explode);
    ADD_PUBLIC_FUNC(Rexon::State_Debris);
    ADD_PUBLIC_FUNC(Rexon::State_Projectile);

    // HTZ/RisingLava
    ADD_PUBLIC_FUNC(RisingLava::State_CheckRiseStart);
    ADD_PUBLIC_FUNC(RisingLava::State_RiseShake);
    ADD_PUBLIC_FUNC(RisingLava::State_StoppedRising);

    // HTZ/SeeSaw
    ADD_PUBLIC_FUNC(SeeSaw::DebugSpawn);
    ADD_PUBLIC_FUNC(SeeSaw::DebugDraw);
    ADD_PUBLIC_FUNC(SeeSaw::SetupHitbox);
    ADD_PUBLIC_FUNC(SeeSaw::State_OrbIdle);
    ADD_PUBLIC_FUNC(SeeSaw::State_None);
    ADD_PUBLIC_FUNC(SeeSaw::State_NoOrb);
    ADD_PUBLIC_FUNC(SeeSaw::State_OrbLaunched);

    // HTZ/Sol
    ADD_PUBLIC_FUNC(Sol::DebugSpawn);
    ADD_PUBLIC_FUNC(Sol::DebugDraw);
    ADD_PUBLIC_FUNC(Sol::HandlePlayerInteractions);
    ADD_PUBLIC_FUNC(Sol::HandlePlayerHurt);
    ADD_PUBLIC_FUNC(Sol::HandleRotation);
    ADD_PUBLIC_FUNC(Sol::CheckOffScreen);
    ADD_PUBLIC_FUNC(Sol::State_Init);
    ADD_PUBLIC_FUNC(Sol::State_Moving);
    ADD_PUBLIC_FUNC(Sol::State_ShootingOrbs);
    ADD_PUBLIC_FUNC(Sol::State_NoOrbs);
    ADD_PUBLIC_FUNC(Sol::State_SmallFireball);
    ADD_PUBLIC_FUNC(Sol::State_ActiveFireball);
    ADD_PUBLIC_FUNC(Sol::State_FlameDissipate);
    ADD_PUBLIC_FUNC(Sol::State_FireballOilFlame);
    ADD_PUBLIC_FUNC(Sol::State_OilFlame);

    // HTZ/Spiker
    ADD_PUBLIC_FUNC(Spiker::DebugSpawn);
    ADD_PUBLIC_FUNC(Spiker::DebugDraw);
    ADD_PUBLIC_FUNC(Spiker::Setup);
    ADD_PUBLIC_FUNC(Spiker::State_Pause);
    ADD_PUBLIC_FUNC(Spiker::State_Wandering);
    ADD_PUBLIC_FUNC(Spiker::State_Launching);
    ADD_PUBLIC_FUNC(Spiker::State_Cone);
    ADD_PUBLIC_FUNC(Spiker::Cone_None);
    ADD_PUBLIC_FUNC(Spiker::Cone_Attached);
    ADD_PUBLIC_FUNC(Spiker::Cone_Launching);

    // HTZ/ZipLine
    ADD_PUBLIC_FUNC(ZipLine::VSSwap_CheckBusy);
    ADD_PUBLIC_FUNC(ZipLine::GrabHandle);
    ADD_PUBLIC_FUNC(ZipLine::ForceReleasePlayers);
    ADD_PUBLIC_FUNC(ZipLine::GetJoinPos);
    ADD_PUBLIC_FUNC(ZipLine::State_Moving);

    // Menu/ContinuePlayer
    ADD_PUBLIC_FUNC(ContinuePlayer::HandleDashAnim);
    ADD_PUBLIC_FUNC(ContinuePlayer::State_Idle);
    ADD_PUBLIC_FUNC(ContinuePlayer::State_ChargeDash);
    ADD_PUBLIC_FUNC(ContinuePlayer::State_DashRelease);

    // Menu/ContinueSetup
    ADD_PUBLIC_FUNC(ContinueSetup::Draw_Fade);
    ADD_PUBLIC_FUNC(ContinueSetup::State_FadeIn);
    ADD_PUBLIC_FUNC(ContinueSetup::State_HandleCountdown);
    ADD_PUBLIC_FUNC(ContinueSetup::State_ContinueGame);
    ADD_PUBLIC_FUNC(ContinueSetup::State_ReturnToMenu);

    // Menu/DASetup
    ADD_PUBLIC_FUNC(DASetup::State_Idle);
    ADD_PUBLIC_FUNC(DASetup::Draw_Fade);
    ADD_PUBLIC_FUNC(DASetup::DisplayTrack);
    ADD_PUBLIC_FUNC(DASetup::SetupUI);
    ADD_PUBLIC_FUNC(DASetup::State_ManageControl);

    // Menu/ExtrasMenu
    ADD_PUBLIC_FUNC(ExtrasMenu::Initialize);
    ADD_PUBLIC_FUNC(ExtrasMenu::HandleUnlocks);
    ADD_PUBLIC_FUNC(ExtrasMenu::SetupActions);
    ADD_PUBLIC_FUNC(ExtrasMenu::ProcessInputs);
    ADD_PUBLIC_FUNC(ExtrasMenu::Start_BossRush);
    ADD_PUBLIC_FUNC(ExtrasMenu::BossRush_ActionCB);
    ADD_PUBLIC_FUNC(ExtrasMenu::Start_MusicPlayer);
    ADD_PUBLIC_FUNC(ExtrasMenu::MusicPlayer_ActionCB);
    ADD_PUBLIC_FUNC(ExtrasMenu::Start_LevelSelect);
    ADD_PUBLIC_FUNC(ExtrasMenu::LevelSelect_ActionCB);
    ADD_PUBLIC_FUNC(ExtrasMenu::Start_ExtraLevels);
    ADD_PUBLIC_FUNC(ExtrasMenu::ExtraLevels_ActionCB);
    ADD_PUBLIC_FUNC(ExtrasMenu::Start_Credits);
    ADD_PUBLIC_FUNC(ExtrasMenu::Credits_ActionCB);

    // Menu/LevelSelect
    ADD_PUBLIC_FUNC(LevelSelect::Draw_Fade);
    ADD_PUBLIC_FUNC(LevelSelect::State_Init);
    ADD_PUBLIC_FUNC(LevelSelect::State_FadeIn);
    ADD_PUBLIC_FUNC(LevelSelect::State_Navigate);
    ADD_PUBLIC_FUNC(LevelSelect::State_FadeOut);
    ADD_PUBLIC_FUNC(LevelSelect::ManagePlayerIcon);
    ADD_PUBLIC_FUNC(LevelSelect::SetLabelHighlighted);
    ADD_PUBLIC_FUNC(LevelSelect::HandleColumnChange);
    ADD_PUBLIC_FUNC(LevelSelect::HandleNewStagePos);

    // Menu/MainMenu
    ADD_PUBLIC_FUNC(MainMenu::Initialize);
    ADD_PUBLIC_FUNC(MainMenu::BackPressCB_ReturnToTitle);
    ADD_PUBLIC_FUNC(MainMenu::ExitGame);
    ADD_PUBLIC_FUNC(MainMenu::ExitButton_ActionCB);
    ADD_PUBLIC_FUNC(MainMenu::StartExitGame);
    ADD_PUBLIC_FUNC(MainMenu::MenuButton_ActionCB);
    ADD_PUBLIC_FUNC(MainMenu::HandleUnlocks);
    ADD_PUBLIC_FUNC(MainMenu::SetupActions);
    ADD_PUBLIC_FUNC(MainMenu::MenuSetupCB);

    // Menu/ManiaModeMenu
    ADD_PUBLIC_FUNC(ManiaModeMenu::Initialize);
    ADD_PUBLIC_FUNC(ManiaModeMenu::InitAPI);
    ADD_PUBLIC_FUNC(ManiaModeMenu::InitLocalization);
    ADD_PUBLIC_FUNC(ManiaModeMenu::GetActiveMenu);
    ADD_PUBLIC_FUNC(ManiaModeMenu::ChangeMenuBG);
    ADD_PUBLIC_FUNC(ManiaModeMenu::ChangeMenuTrack);
    ADD_PUBLIC_FUNC(ManiaModeMenu::StartReturnToTitle);
    ADD_PUBLIC_FUNC(ManiaModeMenu::ReturnToTitle);
    ADD_PUBLIC_FUNC(ManiaModeMenu::HandleUnlocks);
    ADD_PUBLIC_FUNC(ManiaModeMenu::SetupActions);
    ADD_PUBLIC_FUNC(ManiaModeMenu::HandleMenuReturn);
    ADD_PUBLIC_FUNC(ManiaModeMenu::State_HandleTransition);
    ADD_PUBLIC_FUNC(ManiaModeMenu::MovePromptCB);

    // Menu/MenuSetup
    ADD_PUBLIC_FUNC(MenuSetup::StartTransition);
    ADD_PUBLIC_FUNC(MenuSetup::SaveFileCB);

    // Menu/OptionsMenu
    ADD_PUBLIC_FUNC(OptionsMenu::Initialize);
    ADD_PUBLIC_FUNC(OptionsMenu::HandleUnlocks);
    ADD_PUBLIC_FUNC(OptionsMenu::SetupActions);
    ADD_PUBLIC_FUNC(OptionsMenu::HandleMenuReturn);
    ADD_PUBLIC_FUNC(OptionsMenu::InitVideoOptionsMenu);
    ADD_PUBLIC_FUNC(OptionsMenu::VideoControl_Win_MenuUpdateCB);
    ADD_PUBLIC_FUNC(OptionsMenu::VideoControl_Win_YPressCB);
    ADD_PUBLIC_FUNC(OptionsMenu::DlgRunnerCB_RevertVideoChanges);
    ADD_PUBLIC_FUNC(OptionsMenu::VideoControl_Win_BackPressCB);
    ADD_PUBLIC_FUNC(OptionsMenu::ApplyChangesDlg_BackPress_YesCB);
    ADD_PUBLIC_FUNC(OptionsMenu::ApplyChangesDlg_Win_NoCB);
    ADD_PUBLIC_FUNC(OptionsMenu::ApplyChangesDlg_NoCB);
    ADD_PUBLIC_FUNC(OptionsMenu::ApplyChangesDlg_Win_YesCB);
    ADD_PUBLIC_FUNC(OptionsMenu::ApplyChangesDlg_Win_BackPress_YesCB);
    ADD_PUBLIC_FUNC(OptionsMenu::ApplyChangesDlg_BackPress_NoCB);
    ADD_PUBLIC_FUNC(OptionsMenu::VideoMenuButton_ActionCB);
    ADD_PUBLIC_FUNC(OptionsMenu::SoundMenuButton_ActionCB);
    ADD_PUBLIC_FUNC(OptionsMenu::DataOptionsMenuButton_ActionCB);
    ADD_PUBLIC_FUNC(OptionsMenu::ControlsMenuButton_DefaultKB_ActionCB);
    ADD_PUBLIC_FUNC(OptionsMenu::ControlsMenuButton_Default_ActionCB);
    ADD_PUBLIC_FUNC(OptionsMenu::ControlsMenuButton_ActionCB);
    ADD_PUBLIC_FUNC(OptionsMenu::SetDefaultMappings);
    ADD_PUBLIC_FUNC(OptionsMenu::SetupKBControlsMenu);
    ADD_PUBLIC_FUNC(OptionsMenu::KeyboardIDButton_Win_ActionCB);
    ADD_PUBLIC_FUNC(OptionsMenu::MenuSetupCB);
    ADD_PUBLIC_FUNC(OptionsMenu::SaveOptionsCB_Load);
    ADD_PUBLIC_FUNC(OptionsMenu::TransitionCB_ReloadScene);
    ADD_PUBLIC_FUNC(OptionsMenu::SaveOptionsCB_Action);
    ADD_PUBLIC_FUNC(OptionsMenu::ShaderButton_ActionCB);
    ADD_PUBLIC_FUNC(OptionsMenu::WindowScaleButton_ActionCB);
    ADD_PUBLIC_FUNC(OptionsMenu::BorderlessButton_ActionCB);
    ADD_PUBLIC_FUNC(OptionsMenu::FullScreenButton_ActionCB);
    ADD_PUBLIC_FUNC(OptionsMenu::VSyncButton_ActionCB);
    ADD_PUBLIC_FUNC(OptionsMenu::TripleBufferButton_ActionCB);
    ADD_PUBLIC_FUNC(OptionsMenu::UISlider_ChangedCB);
    ADD_PUBLIC_FUNC(OptionsMenu::EraseSaveDataCB);
    ADD_PUBLIC_FUNC(OptionsMenu::AreYouSureDlg_YesCB_EraseSaveGame);
    ADD_PUBLIC_FUNC(OptionsMenu::AreYouSureDlg_YesCB_EraseAllData);
    ADD_PUBLIC_FUNC(OptionsMenu::EraseSaveGameButton_ActionCB);
    ADD_PUBLIC_FUNC(OptionsMenu::AreYouSureDlg_YesCB_EraseTimeAttack);
    ADD_PUBLIC_FUNC(OptionsMenu::EraseTimeAttackButton_ActionCB);
    ADD_PUBLIC_FUNC(OptionsMenu::AreYouSureDlg_YesCB_EraseReplays);
    ADD_PUBLIC_FUNC(OptionsMenu::EraseReplaysCB);
    ADD_PUBLIC_FUNC(OptionsMenu::EraseReplaysButton_ActionCB);
    ADD_PUBLIC_FUNC(OptionsMenu::EraseAllButton_ActionCB);

    // Menu/SaveMenu
    ADD_PUBLIC_FUNC(SaveMenu::Initialize);
    ADD_PUBLIC_FUNC(SaveMenu::HandleUnlocks);
    ADD_PUBLIC_FUNC(SaveMenu::SetupActions);
    ADD_PUBLIC_FUNC(SaveMenu::HandleMenuReturn);
    ADD_PUBLIC_FUNC(SaveMenu::GetMedalMods);
    ADD_PUBLIC_FUNC(SaveMenu::SaveFileCB);
    ADD_PUBLIC_FUNC(SaveMenu::SecretsTransitionCB);
    ADD_PUBLIC_FUNC(SaveMenu::LeaveSecretsMenu);
    ADD_PUBLIC_FUNC(SaveMenu::SaveSel_MenuUpdateCB);
    ADD_PUBLIC_FUNC(SaveMenu::SaveSel_YPressCB);
    ADD_PUBLIC_FUNC(SaveMenu::SaveButton_ActionCB);

    // Menu/ThanksSetup
    ADD_PUBLIC_FUNC(ThanksSetup::State_ThanksForPlaying);
    ADD_PUBLIC_FUNC(ThanksSetup::State_FadeOut);
    ADD_PUBLIC_FUNC(ThanksSetup::Draw_Fade);

    // Menu/TimeAttackMenu
    ADD_PUBLIC_FUNC(TimeAttackMenu::Initialize);
    ADD_PUBLIC_FUNC(TimeAttackMenu::HandleUnlocks);
    ADD_PUBLIC_FUNC(TimeAttackMenu::SetupActions);
    ADD_PUBLIC_FUNC(TimeAttackMenu::HandleMenuReturn);
    ADD_PUBLIC_FUNC(TimeAttackMenu::DeleteReplayActionCB);
    ADD_PUBLIC_FUNC(TimeAttackMenu::ConfirmDeleteReplay_Yes_CB);
    ADD_PUBLIC_FUNC(TimeAttackMenu::DeleteReplayCB);
    ADD_PUBLIC_FUNC(TimeAttackMenu::ReplayCarousel_ActionCB);
    ADD_PUBLIC_FUNC(TimeAttackMenu::WatchReplay);
    ADD_PUBLIC_FUNC(TimeAttackMenu::ReplayLoad_CB);
    ADD_PUBLIC_FUNC(TimeAttackMenu::WatchReplayActionCB_ReplaysMenu);
    ADD_PUBLIC_FUNC(TimeAttackMenu::ChallengeReplayActionCB_ReplaysMenu);
    ADD_PUBLIC_FUNC(TimeAttackMenu::WatchReplayCB_RanksMenu);
    ADD_PUBLIC_FUNC(TimeAttackMenu::ChallengeReplayCB_RanksMenu);
    ADD_PUBLIC_FUNC(TimeAttackMenu::LoadScene_Fadeout);
    ADD_PUBLIC_FUNC(TimeAttackMenu::MenuSetupCB_Replay);
    ADD_PUBLIC_FUNC(TimeAttackMenu::MenuUpdateCB_Replay);
    ADD_PUBLIC_FUNC(TimeAttackMenu::MenuUpdateCB);
    ADD_PUBLIC_FUNC(TimeAttackMenu::ReplayButton_ActionCB);
    ADD_PUBLIC_FUNC(TimeAttackMenu::YPressCB_Replay);
    ADD_PUBLIC_FUNC(TimeAttackMenu::SortReplayChoiceCB);
    ADD_PUBLIC_FUNC(TimeAttackMenu::SetupDetailsView);
    ADD_PUBLIC_FUNC(TimeAttackMenu::TAModule_ActionCB);
    ADD_PUBLIC_FUNC(TimeAttackMenu::StartTAAttempt);
    ADD_PUBLIC_FUNC(TimeAttackMenu::LoadScene);
    ADD_PUBLIC_FUNC(TimeAttackMenu::YPressCB_ZoneSel);
    ADD_PUBLIC_FUNC(TimeAttackMenu::BackPressCB_ZoneSel);
    ADD_PUBLIC_FUNC(TimeAttackMenu::YPressCB_Details);
    ADD_PUBLIC_FUNC(TimeAttackMenu::ResetTimes_YesCB);
    ADD_PUBLIC_FUNC(TimeAttackMenu::XPressCB_Details);
    ADD_PUBLIC_FUNC(TimeAttackMenu::TAZoneModule_ActionCB);
    ADD_PUBLIC_FUNC(TimeAttackMenu::RankButton_ActionCB);
    ADD_PUBLIC_FUNC(TimeAttackMenu::MenuSetupCB_Details);
    ADD_PUBLIC_FUNC(TimeAttackMenu::TAZoneModule_ChoiceChangeCB);
    ADD_PUBLIC_FUNC(TimeAttackMenu::CharButton_ActionCB);
    ADD_PUBLIC_FUNC(TimeAttackMenu::TransitionToDetailsCB);
    ADD_PUBLIC_FUNC(TimeAttackMenu::SetupLeaderboardsCarousel);

    // Menu/UIButton
    ADD_PUBLIC_FUNC(UIButton::ManageChoices);
    ADD_PUBLIC_FUNC(UIButton::GetChoicePtr);
    ADD_PUBLIC_FUNC(UIButton::SetChoiceSelectionWithCB);
    ADD_PUBLIC_FUNC(UIButton::SetChoiceSelection);
    ADD_PUBLIC_FUNC(UIButton::GetActionCB);
    ADD_PUBLIC_FUNC(UIButton::FailCB);
    ADD_PUBLIC_FUNC(UIButton::ProcessButtonCB_Scroll);
    ADD_PUBLIC_FUNC(UIButton::ProcessTouchCB_Multi);
    ADD_PUBLIC_FUNC(UIButton::ProcessTouchCB_Single);
    ADD_PUBLIC_FUNC(UIButton::ProcessButtonCB);
    ADD_PUBLIC_FUNC(UIButton::CheckButtonEnterCB);
    ADD_PUBLIC_FUNC(UIButton::CheckSelectedCB);
    ADD_PUBLIC_FUNC(UIButton::ButtonEnterCB);
    ADD_PUBLIC_FUNC(UIButton::ButtonLeaveCB);
    ADD_PUBLIC_FUNC(UIButton::SelectedCB);
    ADD_PUBLIC_FUNC(UIButton::State_HandleButtonLeave);
    ADD_PUBLIC_FUNC(UIButton::State_HandleButtonEnter);
    ADD_PUBLIC_FUNC(UIButton::State_Selected);

    // Menu/UIButtonPrompt
    ADD_PUBLIC_FUNC(UIButtonPrompt::GetButtonMappings);
    ADD_PUBLIC_FUNC(UIButtonPrompt::GetGamepadType);
    ADD_PUBLIC_FUNC(UIButtonPrompt::MappingsToFrame);
    ADD_PUBLIC_FUNC(UIButtonPrompt::CheckTouch);
    ADD_PUBLIC_FUNC(UIButtonPrompt::SetButtonSprites);
    ADD_PUBLIC_FUNC(UIButtonPrompt::State_CheckIfSelected);
    ADD_PUBLIC_FUNC(UIButtonPrompt::State_Selected);

    // Menu/UICarousel
    ADD_PUBLIC_FUNC(UICarousel::HandleScrolling);
    ADD_PUBLIC_FUNC(UICarousel::HandleButtonPositions);

    // Menu/UICharButton
    ADD_PUBLIC_FUNC(UICharButton::DrawButton);
    ADD_PUBLIC_FUNC(UICharButton::SelectedCB);
    ADD_PUBLIC_FUNC(UICharButton::CheckButtonEnterCB);
    ADD_PUBLIC_FUNC(UICharButton::CheckSelectedCB);
    ADD_PUBLIC_FUNC(UICharButton::ButtonEnterCB);
    ADD_PUBLIC_FUNC(UICharButton::ButtonLeaveCB);
    ADD_PUBLIC_FUNC(UICharButton::State_HandleButtonLeave);
    ADD_PUBLIC_FUNC(UICharButton::State_HandleButtonEnter);
    ADD_PUBLIC_FUNC(UICharButton::State_Selected);

    // Menu/UIChoice
    ADD_PUBLIC_FUNC(UIChoice::SetChoiceActive);
    ADD_PUBLIC_FUNC(UIChoice::SetChoiceInactive);
    ADD_PUBLIC_FUNC(UIChoice::TouchedCB_Left);
    ADD_PUBLIC_FUNC(UIChoice::TouchedCB_Right);
    ADD_PUBLIC_FUNC(UIChoice::CheckTouch);
    ADD_PUBLIC_FUNC(UIChoice::State_HandleButtonLeave);
    ADD_PUBLIC_FUNC(UIChoice::State_HandleButtonEnter);

    // Menu/UIControl
    ADD_PUBLIC_FUNC(UIControl::GetButtonID);
    ADD_PUBLIC_FUNC(UIControl::MenuChangeButtonInit);
    ADD_PUBLIC_FUNC(UIControl::SetActiveMenuButtonPrompts);
    ADD_PUBLIC_FUNC(UIControl::SetActiveMenu);
    ADD_PUBLIC_FUNC(UIControl::SetMenuLostFocus);
    ADD_PUBLIC_FUNC(UIControl::SetInactiveMenu);
    ADD_PUBLIC_FUNC(UIControl::SetupButtons);
    ADD_PUBLIC_FUNC(UIControl::GetUIControl);
    ADD_PUBLIC_FUNC(UIControl::isMoving);
    ADD_PUBLIC_FUNC(UIControl::MatchMenuTag);
    ADD_PUBLIC_FUNC(UIControl::HandleMenuChange);
    ADD_PUBLIC_FUNC(UIControl::HandleMenuLoseFocus);
    ADD_PUBLIC_FUNC(UIControl::ReturnToParentMenu);
    ADD_PUBLIC_FUNC(UIControl::ClearInputs);
    ADD_PUBLIC_FUNC(UIControl::SetTargetPos);
    ADD_PUBLIC_FUNC(UIControl::HandlePosition);
    ADD_PUBLIC_FUNC(UIControl::ProcessInputs);
    ADD_PUBLIC_FUNC(UIControl::ProcessButtonInput);
    ADD_PUBLIC_FUNC(UIControl::ContainsPos);

    // Menu/UIDialog
    ADD_PUBLIC_FUNC(UIDialog::CreateActiveDialog);
    ADD_PUBLIC_FUNC(UIDialog::SetupText);
    ADD_PUBLIC_FUNC(UIDialog::AddButton);
    ADD_PUBLIC_FUNC(UIDialog::Setup);
    ADD_PUBLIC_FUNC(UIDialog::CloseOnSel_HandleSelection);
    ADD_PUBLIC_FUNC(UIDialog::DrawBGShapes);
    ADD_PUBLIC_FUNC(UIDialog::HandleButtonPositions);
    ADD_PUBLIC_FUNC(UIDialog::Close);
    ADD_PUBLIC_FUNC(UIDialog::HandleAutoClose);
    ADD_PUBLIC_FUNC(UIDialog::ButtonActionCB);
    ADD_PUBLIC_FUNC(UIDialog::State_Appear);
    ADD_PUBLIC_FUNC(UIDialog::State_Idle);
    ADD_PUBLIC_FUNC(UIDialog::State_Close);
    ADD_PUBLIC_FUNC(UIDialog::CreateDialogOk);
    ADD_PUBLIC_FUNC(UIDialog::CreateDialogYesNo);
    ADD_PUBLIC_FUNC(UIDialog::CreateDialogOkCancel);

    // Menu/UIDiorama
    ADD_PUBLIC_FUNC(UIDiorama::ChangeDiorama);

    // Menu/UIInfoLabel
    ADD_PUBLIC_FUNC(UIInfoLabel::SetText);
    ADD_PUBLIC_FUNC(UIInfoLabel::SetString);
    ADD_PUBLIC_FUNC(UIInfoLabel::DrawSprites);

    // Menu/UIKeyBinder
    ADD_PUBLIC_FUNC(UIKeyBinder::GetButtonListID);
    ADD_PUBLIC_FUNC(UIKeyBinder::GetMappings);
    ADD_PUBLIC_FUNC(UIKeyBinder::SetMappings);
    ADD_PUBLIC_FUNC(UIKeyBinder::GetKeyNameFrameID);
    ADD_PUBLIC_FUNC(UIKeyBinder::DrawSprites);
    ADD_PUBLIC_FUNC(UIKeyBinder::ActionCB);
    ADD_PUBLIC_FUNC(UIKeyBinder::CheckButtonEnterCB);
    ADD_PUBLIC_FUNC(UIKeyBinder::CheckSelectedCB);
    ADD_PUBLIC_FUNC(UIKeyBinder::ButtonEnterCB);
    ADD_PUBLIC_FUNC(UIKeyBinder::ButtonLeaveCB);
    ADD_PUBLIC_FUNC(UIKeyBinder::SelectedCB);
    ADD_PUBLIC_FUNC(UIKeyBinder::MoveKeyToActionCB_No);
    ADD_PUBLIC_FUNC(UIKeyBinder::MoveKeyToActionCB_Yes);
    ADD_PUBLIC_FUNC(UIKeyBinder::State_HandleButtonLeave);
    ADD_PUBLIC_FUNC(UIKeyBinder::State_HandleButtonEnter);
    ADD_PUBLIC_FUNC(UIKeyBinder::State_Selected);

    // Menu/UILoadingIcon
    ADD_PUBLIC_FUNC(UILoadingIcon::StartWait);
    ADD_PUBLIC_FUNC(UILoadingIcon::FinishWait);
    ADD_PUBLIC_FUNC(UILoadingIcon::State_Show);
    ADD_PUBLIC_FUNC(UILoadingIcon::State_Hide);

    // Menu/UIPopover
    ADD_PUBLIC_FUNC(UIPopover::CreatePopover);
    ADD_PUBLIC_FUNC(UIPopover::AddButton);
    ADD_PUBLIC_FUNC(UIPopover::Setup);
    ADD_PUBLIC_FUNC(UIPopover::DrawSprites);
    ADD_PUBLIC_FUNC(UIPopover::SetupButtonPositions);
    ADD_PUBLIC_FUNC(UIPopover::Close);
    ADD_PUBLIC_FUNC(UIPopover::BackPressCB);
    ADD_PUBLIC_FUNC(UIPopover::ButtonActionCB);
    ADD_PUBLIC_FUNC(UIPopover::State_Appear);
    ADD_PUBLIC_FUNC(UIPopover::State_Idle);
    ADD_PUBLIC_FUNC(UIPopover::State_Close);

    // Menu/UIRankButton
    ADD_PUBLIC_FUNC(UIRankButton::SetRankText);
    ADD_PUBLIC_FUNC(UIRankButton::SetTimeAttackRank);
    ADD_PUBLIC_FUNC(UIRankButton::SetupLeaderboardRank);
    ADD_PUBLIC_FUNC(UIRankButton::DrawSprites);
    ADD_PUBLIC_FUNC(UIRankButton::CheckButtonEnterCB);
    ADD_PUBLIC_FUNC(UIRankButton::CheckSelectedCB);
    ADD_PUBLIC_FUNC(UIRankButton::ButtonEnterCB);
    ADD_PUBLIC_FUNC(UIRankButton::ButtonLeaveCB);
    ADD_PUBLIC_FUNC(UIRankButton::FailCB);
    ADD_PUBLIC_FUNC(UIRankButton::SelectedCB);
    ADD_PUBLIC_FUNC(UIRankButton::State_HandleButtonLeave);
    ADD_PUBLIC_FUNC(UIRankButton::State_HandleButtonEnter);
    ADD_PUBLIC_FUNC(UIRankButton::State_Selected);

    // Menu/UIReplayCarousel
    ADD_PUBLIC_FUNC(UIReplayCarousel::ProcessButtonCB);
    ADD_PUBLIC_FUNC(UIReplayCarousel::HandlePositions);
    ADD_PUBLIC_FUNC(UIReplayCarousel::SetupButtonCallbacks);
    ADD_PUBLIC_FUNC(UIReplayCarousel::HandleTouchPositions);
    ADD_PUBLIC_FUNC(UIReplayCarousel::TouchedCB);
    ADD_PUBLIC_FUNC(UIReplayCarousel::SetupVisibleReplayButtons);
    ADD_PUBLIC_FUNC(UIReplayCarousel::DrawStageInfo);
    ADD_PUBLIC_FUNC(UIReplayCarousel::DrawReplayInfo);
    ADD_PUBLIC_FUNC(UIReplayCarousel::StartAction);
    ADD_PUBLIC_FUNC(UIReplayCarousel::SetUnselected);
    ADD_PUBLIC_FUNC(UIReplayCarousel::Draw_Loading);
    ADD_PUBLIC_FUNC(UIReplayCarousel::Draw_NoReplays);
    ADD_PUBLIC_FUNC(UIReplayCarousel::Draw_Carousel);
    ADD_PUBLIC_FUNC(UIReplayCarousel::State_Init);
    ADD_PUBLIC_FUNC(UIReplayCarousel::State_Unselected);
    ADD_PUBLIC_FUNC(UIReplayCarousel::State_Selected);
    ADD_PUBLIC_FUNC(UIReplayCarousel::State_StartAction);

    // Menu/UIResPicker
    ADD_PUBLIC_FUNC(UIResPicker::GetDisplayInfo);
    ADD_PUBLIC_FUNC(UIResPicker::ApplySettings);
    ADD_PUBLIC_FUNC(UIResPicker::ProcessButtonCB);
    ADD_PUBLIC_FUNC(UIResPicker::ProcessTouchCB);
    ADD_PUBLIC_FUNC(UIResPicker::TouchedCB_Left);
    ADD_PUBLIC_FUNC(UIResPicker::TouchedCB_Right);
    ADD_PUBLIC_FUNC(UIResPicker::SetChoiceActive);
    ADD_PUBLIC_FUNC(UIResPicker::SetChoiceInactive);
    ADD_PUBLIC_FUNC(UIResPicker::State_HandleButtonLeave);
    ADD_PUBLIC_FUNC(UIResPicker::State_HandleButtonEnter);

    // Menu/UISaveSlot
    ADD_PUBLIC_FUNC(UISaveSlot::GetPlayerIDFromID);
    ADD_PUBLIC_FUNC(UISaveSlot::GetIDFromPlayerID);
    ADD_PUBLIC_FUNC(UISaveSlot::DrawFileIcons);
    ADD_PUBLIC_FUNC(UISaveSlot::DrawPlayerInfo);
    ADD_PUBLIC_FUNC(UISaveSlot::SetupButtonElements);
    ADD_PUBLIC_FUNC(UISaveSlot::SetupAnimators);
    ADD_PUBLIC_FUNC(UISaveSlot::LoadSaveInfo);
    ADD_PUBLIC_FUNC(UISaveSlot::HandleSaveIcons);
    ADD_PUBLIC_FUNC(UISaveSlot::DeleteDLG_CB);
    ADD_PUBLIC_FUNC(UISaveSlot::DeleteSaveCB);
    ADD_PUBLIC_FUNC(UISaveSlot::ProcessButtonCB);
    ADD_PUBLIC_FUNC(UISaveSlot::SelectedCB);
    ADD_PUBLIC_FUNC(UISaveSlot::NextCharacter);
    ADD_PUBLIC_FUNC(UISaveSlot::PrevCharacter);
    ADD_PUBLIC_FUNC(UISaveSlot::NextZone);
    ADD_PUBLIC_FUNC(UISaveSlot::PrevZone);
    ADD_PUBLIC_FUNC(UISaveSlot::CheckButtonEnterCB);
    ADD_PUBLIC_FUNC(UISaveSlot::CheckSelectedCB);
    ADD_PUBLIC_FUNC(UISaveSlot::ButtonEnterCB);
    ADD_PUBLIC_FUNC(UISaveSlot::ButtonLeaveCB);
    ADD_PUBLIC_FUNC(UISaveSlot::HandleSaveIconChange);
    ADD_PUBLIC_FUNC(UISaveSlot::State_NotSelected);
    ADD_PUBLIC_FUNC(UISaveSlot::State_OtherWasSelected);
    ADD_PUBLIC_FUNC(UISaveSlot::State_NewSave);
    ADD_PUBLIC_FUNC(UISaveSlot::State_ActiveSave);
    ADD_PUBLIC_FUNC(UISaveSlot::StateInput_NewSave);
    ADD_PUBLIC_FUNC(UISaveSlot::State_CompletedSave);
    ADD_PUBLIC_FUNC(UISaveSlot::State_Selected);

    // Menu/UIShifter
    ADD_PUBLIC_FUNC(UIShifter::HandleShift);

    // Menu/UISlider
    ADD_PUBLIC_FUNC(UISlider::DrawFGShapes);
    ADD_PUBLIC_FUNC(UISlider::DrawSlider);
    ADD_PUBLIC_FUNC(UISlider::ButtonPressCB);
    ADD_PUBLIC_FUNC(UISlider::TouchCB);
    ADD_PUBLIC_FUNC(UISlider::ButtonEnterCB);
    ADD_PUBLIC_FUNC(UISlider::ButtonLeaveCB);
    ADD_PUBLIC_FUNC(UISlider::CheckButtonEnterCB);
    ADD_PUBLIC_FUNC(UISlider::CheckSelectedCB);
    ADD_PUBLIC_FUNC(UISlider::State_HandleButtonLeave);
    ADD_PUBLIC_FUNC(UISlider::State_HandleButtonEnter);

    // Menu/UITABanner
    ADD_PUBLIC_FUNC(UITABanner::SetupDetails);
    ADD_PUBLIC_FUNC(UITABanner::DrawStageInfo);
    ADD_PUBLIC_FUNC(UITABanner::DrawBannerInfo);

    // Menu/UITAZoneModule
    ADD_PUBLIC_FUNC(UITAZoneModule::Setup);
    ADD_PUBLIC_FUNC(UITAZoneModule::FailCB);
    ADD_PUBLIC_FUNC(UITAZoneModule::SelectedCB);
    ADD_PUBLIC_FUNC(UITAZoneModule::CheckButtonEnterCB);
    ADD_PUBLIC_FUNC(UITAZoneModule::CheckSelectedCB);
    ADD_PUBLIC_FUNC(UITAZoneModule::ButtonEnterCB);
    ADD_PUBLIC_FUNC(UITAZoneModule::ButtonLeaveCB);
    ADD_PUBLIC_FUNC(UITAZoneModule::ProcessButtonCB);
    ADD_PUBLIC_FUNC(UITAZoneModule::State_Init);
    ADD_PUBLIC_FUNC(UITAZoneModule::State_NotSelected);
    ADD_PUBLIC_FUNC(UITAZoneModule::State_Selected);
    ADD_PUBLIC_FUNC(UITAZoneModule::State_HasBeenSelected);

    // Menu/UITransition
    // ADD_PUBLIC_FUNC(UITransition::StartTransition);
    ADD_PUBLIC_FUNC(UITransition::MatchNewTag);
    ADD_PUBLIC_FUNC(UITransition::SetNewTag);
    ADD_PUBLIC_FUNC(UITransition::DrawFade);
    ADD_PUBLIC_FUNC(UITransition::State_Init);
    ADD_PUBLIC_FUNC(UITransition::State_TransitionIn);
    ADD_PUBLIC_FUNC(UITransition::State_TransitionOut);

    // Menu/UIVideo
    ADD_PUBLIC_FUNC(UIVideo::SkipCB);
    ADD_PUBLIC_FUNC(UIVideo::State_PlayVideo1);
    ADD_PUBLIC_FUNC(UIVideo::State_PlayVideo2);
    ADD_PUBLIC_FUNC(UIVideo::State_FinishPlayback);

    // Menu/UIWidgets
    ADD_PUBLIC_FUNC(UIWidgets::ApplyLanguage);
    ADD_PUBLIC_FUNC(UIWidgets::DrawRectOutline_Black);
    ADD_PUBLIC_FUNC(UIWidgets::DrawRectOutline_Blended);
    ADD_PUBLIC_FUNC(UIWidgets::DrawRectOutline_Flash);
    ADD_PUBLIC_FUNC(UIWidgets::DrawRightTriangle);
    ADD_PUBLIC_FUNC(UIWidgets::DrawEquilateralTriangle);
    ADD_PUBLIC_FUNC(UIWidgets::DrawParallelogram);
    ADD_PUBLIC_FUNC(UIWidgets::DrawLeftRightArrows);
    ADD_PUBLIC_FUNC(UIWidgets::DrawTriJoinRect);
    ADD_PUBLIC_FUNC(UIWidgets::DrawTime);

    // Menu/UIWinSize
    ADD_PUBLIC_FUNC(UIWinSize::SetupText);
    ADD_PUBLIC_FUNC(UIWinSize::ApplySettings);
    ADD_PUBLIC_FUNC(UIWinSize::ProcessButtonCB);
    ADD_PUBLIC_FUNC(UIWinSize::ProcessTouchCB);
    ADD_PUBLIC_FUNC(UIWinSize::TouchedCB_Left);
    ADD_PUBLIC_FUNC(UIWinSize::TouchedCB_Right);
    ADD_PUBLIC_FUNC(UIWinSize::SetChoiceActive);
    ADD_PUBLIC_FUNC(UIWinSize::SetChoiceInactive);
    ADD_PUBLIC_FUNC(UIWinSize::State_HandleButtonLeave);
    ADD_PUBLIC_FUNC(UIWinSize::State_HandleButtonEnter);

    // OOZ/Aquis
    ADD_PUBLIC_FUNC(Aquis::DebugSpawn);
    ADD_PUBLIC_FUNC(Aquis::DebugDraw);
    ADD_PUBLIC_FUNC(Aquis::CheckPlayerCollisions);
    ADD_PUBLIC_FUNC(Aquis::CheckOffScreen);
    ADD_PUBLIC_FUNC(Aquis::State_Init);
    ADD_PUBLIC_FUNC(Aquis::State_Idle);
    ADD_PUBLIC_FUNC(Aquis::State_Moving);
    ADD_PUBLIC_FUNC(Aquis::State_Shoot);
    ADD_PUBLIC_FUNC(Aquis::State_Turning);
    ADD_PUBLIC_FUNC(Aquis::State_Flee);
    ADD_PUBLIC_FUNC(Aquis::State_Shot);

    // OOZ/BallCannon
    ADD_PUBLIC_FUNC(BallCannon::CheckPlayerEntry);
    ADD_PUBLIC_FUNC(BallCannon::State_Idle);
    ADD_PUBLIC_FUNC(BallCannon::State_Inserted);
    ADD_PUBLIC_FUNC(BallCannon::State_Turning);
    ADD_PUBLIC_FUNC(BallCannon::State_EjectPlayer);
    ADD_PUBLIC_FUNC(BallCannon::State_CorkBlocked);
    ADD_PUBLIC_FUNC(BallCannon::State_CorkOpened);
    ADD_PUBLIC_FUNC(BallCannon::State_CorkDebris);

    // OOZ/Fan
    ADD_PUBLIC_FUNC(Fan::SetupTagLink);
    ADD_PUBLIC_FUNC(Fan::HandlePlayerInteractions_Top);
    ADD_PUBLIC_FUNC(Fan::HandlePlayerInteractions_Bottom);
    ADD_PUBLIC_FUNC(Fan::HandlePlayerInteractions_Left);
    ADD_PUBLIC_FUNC(Fan::HandlePlayerInteractions_Right);
    ADD_PUBLIC_FUNC(Fan::State_Started);
    ADD_PUBLIC_FUNC(Fan::State_Stopped);
    ADD_PUBLIC_FUNC(Fan::Activate_Interval);
    ADD_PUBLIC_FUNC(Fan::Activate_Button);
    ADD_PUBLIC_FUNC(Fan::Deactivate_Button);
    ADD_PUBLIC_FUNC(Fan::Activate_Platform);
    ADD_PUBLIC_FUNC(Fan::Activate);

    // OOZ/GasPlatform
    ADD_PUBLIC_FUNC(GasPlatform::PopPlatform);
    ADD_PUBLIC_FUNC(GasPlatform::State_Popped);
    ADD_PUBLIC_FUNC(GasPlatform::State_SpringCooldown);
    ADD_PUBLIC_FUNC(GasPlatform::State_Shaking);

    // OOZ/Octus
    ADD_PUBLIC_FUNC(Octus::DebugSpawn);
    ADD_PUBLIC_FUNC(Octus::DebugDraw);
    ADD_PUBLIC_FUNC(Octus::CheckPlayerCollisions);
    ADD_PUBLIC_FUNC(Octus::CheckOffScreen);
    ADD_PUBLIC_FUNC(Octus::State_Init);
    ADD_PUBLIC_FUNC(Octus::State_CheckPlayerInRange);
    ADD_PUBLIC_FUNC(Octus::State_JumpDelay);
    ADD_PUBLIC_FUNC(Octus::State_Jump);
    ADD_PUBLIC_FUNC(Octus::State_Shoot);
    ADD_PUBLIC_FUNC(Octus::State_Fall);
    ADD_PUBLIC_FUNC(Octus::State_Shot);

    // OOZ/OOZSetup
    ADD_PUBLIC_FUNC(OOZSetup::SfxCheck_Flame2);
    ADD_PUBLIC_FUNC(OOZSetup::SfxCheck_Slide);
    ADD_PUBLIC_FUNC(OOZSetup::SfxCheck_OilSwim);
    ADD_PUBLIC_FUNC(OOZSetup::Draw_Flames);
    ADD_PUBLIC_FUNC(OOZSetup::HandleActiveFlames);
    ADD_PUBLIC_FUNC(OOZSetup::StartFire);
    ADD_PUBLIC_FUNC(OOZSetup::PlayerState_OilPool);
    ADD_PUBLIC_FUNC(OOZSetup::PlayerState_OilStrip);
    ADD_PUBLIC_FUNC(OOZSetup::PlayerState_OilSlide);
    ADD_PUBLIC_FUNC(OOZSetup::PlayerState_OilFall);

    // OOZ/PushSpring
    ADD_PUBLIC_FUNC(PushSpring::Collide_Top);
    ADD_PUBLIC_FUNC(PushSpring::Collide_Bottom);
    ADD_PUBLIC_FUNC(PushSpring::Collide_Left);
    ADD_PUBLIC_FUNC(PushSpring::Collide_Right);
    ADD_PUBLIC_FUNC(PushSpring::Draw_Top);
    ADD_PUBLIC_FUNC(PushSpring::Draw_Bottom);
    ADD_PUBLIC_FUNC(PushSpring::Draw_Left);
    ADD_PUBLIC_FUNC(PushSpring::Draw_Right);
    ADD_PUBLIC_FUNC(PushSpring::State_WaitForPushed);
    ADD_PUBLIC_FUNC(PushSpring::State_BeingPushed);
    ADD_PUBLIC_FUNC(PushSpring::State_PushRecoil);

    // SFZ/SCZSetup
    ADD_PUBLIC_FUNC(SCZSetup::PlayerState_Pilot);

    // SFZ/Tornado
    ADD_PUBLIC_FUNC(Tornado::State_Init);
    ADD_PUBLIC_FUNC(Tornado::State_SetupControl);
    ADD_PUBLIC_FUNC(Tornado::HandlePlayerCollisions);
    ADD_PUBLIC_FUNC(Tornado::State_PlayerControlled);
    ADD_PUBLIC_FUNC(Tornado::State_Mayday);
    ADD_PUBLIC_FUNC(Tornado::State_FlyAway_Right);
    ADD_PUBLIC_FUNC(Tornado::State_FlyAway_Left);

    // SFZ/TornadoPath
    ADD_PUBLIC_FUNC(TornadoPath::SetupHitbox);
    ADD_PUBLIC_FUNC(TornadoPath::HandleMoveSpeed);
    ADD_PUBLIC_FUNC(TornadoPath::State_SetTornadoSpeed);
    ADD_PUBLIC_FUNC(TornadoPath::State_ReturnCamera);
    ADD_PUBLIC_FUNC(TornadoPath::State_DisablePlayerInteractions);
    ADD_PUBLIC_FUNC(TornadoPath::State_ExitTornadoSequence);
    ADD_PUBLIC_FUNC(TornadoPath::State_PrepareCatchPlayer);
    ADD_PUBLIC_FUNC(TornadoPath::State_CatchPlayer);
    ADD_PUBLIC_FUNC(TornadoPath::State_UberCaterkillerBossNode);
    ADD_PUBLIC_FUNC(TornadoPath::State_HandleUberCaterkillerBoss);
    ADD_PUBLIC_FUNC(TornadoPath::State_GoToStopNode);
    ADD_PUBLIC_FUNC(TornadoPath::State_SetupMSZ1CutsceneST);
    ADD_PUBLIC_FUNC(TornadoPath::State_FinishCrash);

    // Special/HP_Checkpoint
    ADD_PUBLIC_FUNC(HP_Checkpoint::State_Init);
    ADD_PUBLIC_FUNC(HP_Checkpoint::State_AwaitPlayer);
    ADD_PUBLIC_FUNC(HP_Checkpoint::State_ShowResults);
    ADD_PUBLIC_FUNC(HP_Checkpoint::State_ExitMessage);
    ADD_PUBLIC_FUNC(HP_Checkpoint::State_ShowNewRingTarget);
    ADD_PUBLIC_FUNC(HP_Checkpoint::State_FadeOut);
    ADD_PUBLIC_FUNC(HP_Checkpoint::State_GoToResults);
    ADD_PUBLIC_FUNC(HP_Checkpoint::DrawRings);
    ADD_PUBLIC_FUNC(HP_Checkpoint::Draw_Results);
    ADD_PUBLIC_FUNC(HP_Checkpoint::Draw_Fade);
    ADD_PUBLIC_FUNC(HP_Checkpoint::Draw_Exit);

    // Special/HP_Collectable
    ADD_PUBLIC_FUNC(HP_Collectable::State_Ring);
    ADD_PUBLIC_FUNC(HP_Collectable::State_Bomb);
    ADD_PUBLIC_FUNC(HP_Collectable::State_EmeraldTrigger);
    ADD_PUBLIC_FUNC(HP_Collectable::State_EmeraldTryCollect);
    ADD_PUBLIC_FUNC(HP_Collectable::State_EmeraldHandleFinish);
    ADD_PUBLIC_FUNC(HP_Collectable::State_Sparkle);
    ADD_PUBLIC_FUNC(HP_Collectable::State_Lost);
    ADD_PUBLIC_FUNC(HP_Collectable::State_Explosion);
    ADD_PUBLIC_FUNC(HP_Collectable::Draw_Ring);
    ADD_PUBLIC_FUNC(HP_Collectable::Draw_Bomb);
    ADD_PUBLIC_FUNC(HP_Collectable::Draw_Emerald);
    ADD_PUBLIC_FUNC(HP_Collectable::Draw_LostRing);
    ADD_PUBLIC_FUNC(HP_Collectable::LoseRings);

    // Special/HP_Halfpipe
    ADD_PUBLIC_FUNC(HP_Halfpipe::SetupFaces);
    ADD_PUBLIC_FUNC(HP_Halfpipe::SetupVertices);
    ADD_PUBLIC_FUNC(HP_Halfpipe::DrawShadow);
    ADD_PUBLIC_FUNC(HP_Halfpipe::DrawTexture);
    ADD_PUBLIC_FUNC(HP_Halfpipe::DrawSprite);
    ADD_PUBLIC_FUNC(HP_Halfpipe::ProcessScanEdge);
    ADD_PUBLIC_FUNC(HP_Halfpipe::ProcessScanEdgeUV);
    ADD_PUBLIC_FUNC(HP_Halfpipe::DrawFadedFace);
    ADD_PUBLIC_FUNC(HP_Halfpipe::DrawTexturedFace);
    ADD_PUBLIC_FUNC(HP_Halfpipe::TransformVertices);
    ADD_PUBLIC_FUNC(HP_Halfpipe::TransformVertexBuffer);
    ADD_PUBLIC_FUNC(HP_Halfpipe::SortDrawList);
    ADD_PUBLIC_FUNC(HP_Halfpipe::Draw3DScene);
    ADD_PUBLIC_FUNC(HP_Halfpipe::MatrixTranslateXYZ);
    ADD_PUBLIC_FUNC(HP_Halfpipe::MatrixRotateXYZ);
    ADD_PUBLIC_FUNC(HP_Halfpipe::MatrixMultiply);

    // Special/HP_HUD
    ADD_PUBLIC_FUNC(HP_HUD::DrawRingCount);

    // Special/HP_Message
    ADD_PUBLIC_FUNC(HP_Message::SetMessage);
    ADD_PUBLIC_FUNC(HP_Message::SetupAniChars);
    ADD_PUBLIC_FUNC(HP_Message::DrawMessage);
    ADD_PUBLIC_FUNC(HP_Message::State_SingleMessage);
    ADD_PUBLIC_FUNC(HP_Message::State_NotEnough);
    ADD_PUBLIC_FUNC(HP_Message::State_GetRings);
    ADD_PUBLIC_FUNC(HP_Message::State_RingReminder);
    ADD_PUBLIC_FUNC(HP_Message::State_AniChar);
    ADD_PUBLIC_FUNC(HP_Message::State_InitStartMessage);
    ADD_PUBLIC_FUNC(HP_Message::State_StartMessageDelay);
    ADD_PUBLIC_FUNC(HP_Message::State_StartMessageSendDelay);
    ADD_PUBLIC_FUNC(HP_Message::State_StartMessageStartFadeIn);
    ADD_PUBLIC_FUNC(HP_Message::State_StartMessageFadeIn);
    ADD_PUBLIC_FUNC(HP_Message::State_StartMessageEnterMessage);
    ADD_PUBLIC_FUNC(HP_Message::State_StartMessageShowMessage);
    ADD_PUBLIC_FUNC(HP_Message::State_StartMessageSetupNextMsg);
    ADD_PUBLIC_FUNC(HP_Message::State_RingReminderTrigger);
    ADD_PUBLIC_FUNC(HP_Message::Draw_Message);
    ADD_PUBLIC_FUNC(HP_Message::Draw_NotEnough);
    ADD_PUBLIC_FUNC(HP_Message::Draw_GetRings);
    ADD_PUBLIC_FUNC(HP_Message::Draw_RingReminder);
    ADD_PUBLIC_FUNC(HP_Message::Draw_AniChar);
    ADD_PUBLIC_FUNC(HP_Message::Draw_StartMessage);
    ADD_PUBLIC_FUNC(HP_Message::Draw_Fade);

    // Special/HP_Player
    ADD_PUBLIC_FUNC(HP_Player::LoadSprites);
    ADD_PUBLIC_FUNC(HP_Player::LoadSpritesVS);
    ADD_PUBLIC_FUNC(HP_Player::LoadPlayerSprites);
    ADD_PUBLIC_FUNC(HP_Player::CheckP2KeyPress);
    ADD_PUBLIC_FUNC(HP_Player::GetDelayedInput);
    ADD_PUBLIC_FUNC(HP_Player::Input_Gamepad);
    ADD_PUBLIC_FUNC(HP_Player::Input_GamepadAssist);
    ADD_PUBLIC_FUNC(HP_Player::Input_AI_Follow);
    ADD_PUBLIC_FUNC(HP_Player::State_Ground);
    ADD_PUBLIC_FUNC(HP_Player::State_Air);
    ADD_PUBLIC_FUNC(HP_Player::State_Hurt);
    ADD_PUBLIC_FUNC(HP_Player::Draw_Normal);
    ADD_PUBLIC_FUNC(HP_Player::Hurt);
    ADD_PUBLIC_FUNC(HP_Player::Hit);
    ADD_PUBLIC_FUNC(HP_Player::GiveRings);

    // Special/HP_SpecialClear
    ADD_PUBLIC_FUNC(HP_SpecialClear::GiveScoreBonus);
    ADD_PUBLIC_FUNC(HP_SpecialClear::DrawNumbers);
    ADD_PUBLIC_FUNC(HP_SpecialClear::State_FadeIn);
    ADD_PUBLIC_FUNC(HP_SpecialClear::State_FadeIdle);
    ADD_PUBLIC_FUNC(HP_SpecialClear::State_EnterText);
    ADD_PUBLIC_FUNC(HP_SpecialClear::State_EnterEmeralds);
    ADD_PUBLIC_FUNC(HP_SpecialClear::State_TallyScore);
    ADD_PUBLIC_FUNC(HP_SpecialClear::State_Failed);
    ADD_PUBLIC_FUNC(HP_SpecialClear::State_FadeOut);
    ADD_PUBLIC_FUNC(HP_SpecialClear::State_ExitResults);
    ADD_PUBLIC_FUNC(HP_SpecialClear::State_WinShowReward);
    ADD_PUBLIC_FUNC(HP_SpecialClear::State_WinEnterText);
    ADD_PUBLIC_FUNC(HP_SpecialClear::State_WinEvent);
    ADD_PUBLIC_FUNC(HP_SpecialClear::State_WinIdle);
    ADD_PUBLIC_FUNC(HP_SpecialClear::Draw_FadeIn);
    ADD_PUBLIC_FUNC(HP_SpecialClear::Draw_Results);
    ADD_PUBLIC_FUNC(HP_SpecialClear::Draw_FadeOut);
    ADD_PUBLIC_FUNC(HP_SpecialClear::Draw_Exit);

    // SSZ/Bomb
    ADD_PUBLIC_FUNC(Bomb::DebugSpawn);
    ADD_PUBLIC_FUNC(Bomb::DebugDraw);
    ADD_PUBLIC_FUNC(Bomb::CheckOffScreen);
    ADD_PUBLIC_FUNC(Bomb::CheckPlayerCollisions);
    ADD_PUBLIC_FUNC(Bomb::State_Init);
    ADD_PUBLIC_FUNC(Bomb::State_Walk);
    ADD_PUBLIC_FUNC(Bomb::State_Idle);
    ADD_PUBLIC_FUNC(Bomb::State_Explode);
    ADD_PUBLIC_FUNC(Bomb::State_Shrapnel);

    // SSZ/Caterkiller
    ADD_PUBLIC_FUNC(Caterkiller::DebugSpawn);
    ADD_PUBLIC_FUNC(Caterkiller::DebugDraw);
    ADD_PUBLIC_FUNC(Caterkiller::CheckOffScreen);
    ADD_PUBLIC_FUNC(Caterkiller::CheckTileCollisions);
    ADD_PUBLIC_FUNC(Caterkiller::Draw_Body);
    ADD_PUBLIC_FUNC(Caterkiller::Draw_Segment);
    ADD_PUBLIC_FUNC(Caterkiller::HandlePlayerInteractions);
    ADD_PUBLIC_FUNC(Caterkiller::CheckTileAngle);
    ADD_PUBLIC_FUNC(Caterkiller::State_Init);
    ADD_PUBLIC_FUNC(Caterkiller::State_Contract);
    ADD_PUBLIC_FUNC(Caterkiller::State_LiftHead);
    ADD_PUBLIC_FUNC(Caterkiller::State_Uncontract);
    ADD_PUBLIC_FUNC(Caterkiller::State_LowerHead);
    ADD_PUBLIC_FUNC(Caterkiller::StateSplit_Head);
    ADD_PUBLIC_FUNC(Caterkiller::StateSplit_Body);

    // SSZ/Pinata
    ADD_PUBLIC_FUNC(Pinata::DebugDraw);
    ADD_PUBLIC_FUNC(Pinata::DebugSpawn);
    ADD_PUBLIC_FUNC(Pinata::State_CheckPlayerCollisions);
    ADD_PUBLIC_FUNC(Pinata::State_Destroyed);

    // SSZ/RollerMKII
    ADD_PUBLIC_FUNC(RollerMKII::DebugSpawn);
    ADD_PUBLIC_FUNC(RollerMKII::DebugDraw);
    ADD_PUBLIC_FUNC(RollerMKII::CheckOffScreen);
    ADD_PUBLIC_FUNC(RollerMKII::CheckPlayerCollisions);
    ADD_PUBLIC_FUNC(RollerMKII::CheckPlayerCollisions_Rolling);
    ADD_PUBLIC_FUNC(RollerMKII::HandleObjectCollisions);
    ADD_PUBLIC_FUNC(RollerMKII::HandlePlatformCollisions);
    ADD_PUBLIC_FUNC(RollerMKII::HandleCollisions);
    ADD_PUBLIC_FUNC(RollerMKII::State_Init);
    ADD_PUBLIC_FUNC(RollerMKII::State_Idle);
    ADD_PUBLIC_FUNC(RollerMKII::State_SpinUp);
    ADD_PUBLIC_FUNC(RollerMKII::State_RollDelay);
    ADD_PUBLIC_FUNC(RollerMKII::State_Rolling_Air);
    ADD_PUBLIC_FUNC(RollerMKII::State_Rolling_Ground);
    ADD_PUBLIC_FUNC(RollerMKII::State_Bumped);

    // SSZ/SeltzerBottle
    ADD_PUBLIC_FUNC(SeltzerBottle::State_Spraying);
    ADD_PUBLIC_FUNC(SeltzerBottle::State_TryReset);

    // SSZ/SeltzerWater
    ADD_PUBLIC_FUNC(SeltzerWater::State_Sprayed);
    ADD_PUBLIC_FUNC(SeltzerWater::State_Falling);
    ADD_PUBLIC_FUNC(SeltzerWater::State_Splash);

    // SSZ/Vultron
    ADD_PUBLIC_FUNC(Vultron::DebugSpawn);
    ADD_PUBLIC_FUNC(Vultron::DebugDraw);
    ADD_PUBLIC_FUNC(Vultron::CheckPlayerCollisions);
    ADD_PUBLIC_FUNC(Vultron::CheckOffScreen);
    ADD_PUBLIC_FUNC(Vultron::State_Init);
    ADD_PUBLIC_FUNC(Vultron::State_CheckPlayerInRange);
    ADD_PUBLIC_FUNC(Vultron::State_Hop);
    ADD_PUBLIC_FUNC(Vultron::State_Dive);
    ADD_PUBLIC_FUNC(Vultron::State_Flying);
    ADD_PUBLIC_FUNC(Vultron::State_Rise);
    ADD_PUBLIC_FUNC(Vultron::State_PrepareDive);
    ADD_PUBLIC_FUNC(Vultron::State_Targeting);

    // SWZ/BouncePlant
    ADD_PUBLIC_FUNC(BouncePlant::SetupNodePositions);
    ADD_PUBLIC_FUNC(BouncePlant::GetNodeStandY);
    ADD_PUBLIC_FUNC(BouncePlant::GetNodeY);

    // SWZ/Dragonfly
    ADD_PUBLIC_FUNC(Dragonfly::DebugDraw);
    ADD_PUBLIC_FUNC(Dragonfly::DebugSpawn);
    ADD_PUBLIC_FUNC(Dragonfly::CheckOffScreen);
    ADD_PUBLIC_FUNC(Dragonfly::CheckPlayerCollisions);
    ADD_PUBLIC_FUNC(Dragonfly::State_Init);
    ADD_PUBLIC_FUNC(Dragonfly::State_Move);
    ADD_PUBLIC_FUNC(Dragonfly::State_Debris);

    // SWZ/GymBar
    ADD_PUBLIC_FUNC(GymBar::DebugSpawn);
    ADD_PUBLIC_FUNC(GymBar::DebugDraw);
    ADD_PUBLIC_FUNC(GymBar::HandlePlayerInteractions);
    ADD_PUBLIC_FUNC(GymBar::HandleSwingJump);
    ADD_PUBLIC_FUNC(GymBar::PlayerState_SwingV);
    ADD_PUBLIC_FUNC(GymBar::PlayerState_Hang);
    ADD_PUBLIC_FUNC(GymBar::PlayerState_SwingH);

    // SWZ/PetalPile
    ADD_PUBLIC_FUNC(PetalPile::GetLeafPattern);
    ADD_PUBLIC_FUNC(PetalPile::State_Init);
    ADD_PUBLIC_FUNC(PetalPile::State_HandleInteractions);
    ADD_PUBLIC_FUNC(PetalPile::State_SetupEmitter);
    ADD_PUBLIC_FUNC(PetalPile::State_Emitter);
    ADD_PUBLIC_FUNC(PetalPile::StateLeaf_Setup);
    ADD_PUBLIC_FUNC(PetalPile::StateLeaf_Delay);
    ADD_PUBLIC_FUNC(PetalPile::StateLeaf_HandleVelocity);
    ADD_PUBLIC_FUNC(PetalPile::StateLeaf_Fall);
    ADD_PUBLIC_FUNC(PetalPile::Draw_Leaf);

    // SWZ/Rhinobot
    ADD_PUBLIC_FUNC(Rhinobot::DebugSpawn);
    ADD_PUBLIC_FUNC(Rhinobot::DebugDraw);
    ADD_PUBLIC_FUNC(Rhinobot::CheckTileCollisions);
    ADD_PUBLIC_FUNC(Rhinobot::CheckPlayerCollisions);
    ADD_PUBLIC_FUNC(Rhinobot::CheckOffScreen);
    ADD_PUBLIC_FUNC(Rhinobot::Delay_Charge);
    ADD_PUBLIC_FUNC(Rhinobot::Delay_Skidding);
    ADD_PUBLIC_FUNC(Rhinobot::Delay_SkidFinish);
    ADD_PUBLIC_FUNC(Rhinobot::State_Init);
    ADD_PUBLIC_FUNC(Rhinobot::State_Moving);
    ADD_PUBLIC_FUNC(Rhinobot::State_Skidding);
    ADD_PUBLIC_FUNC(Rhinobot::State_Idle);
    ADD_PUBLIC_FUNC(Rhinobot::State_Fall);

    // SWZ/Snowflakes
    ADD_PUBLIC_FUNC(Snowflakes::HandleWrap);
    ADD_PUBLIC_FUNC(Snowflakes::CreateSnowflake);

    // SWZ/Splats
    ADD_PUBLIC_FUNC(Splats::DebugDraw);
    ADD_PUBLIC_FUNC(Splats::DebugSpawn);
    ADD_PUBLIC_FUNC(Splats::CheckPlayerCollisions);
    ADD_PUBLIC_FUNC(Splats::CheckOffScreen);
    ADD_PUBLIC_FUNC(Splats::State_Init);
    ADD_PUBLIC_FUNC(Splats::State_BounceAround);
    ADD_PUBLIC_FUNC(Splats::State_Land);

    // SWZ/SWZSetup
    ADD_PUBLIC_FUNC(SWZSetup::StageFinish_EndAct1);
    ADD_PUBLIC_FUNC(SWZSetup::HandleActTransition);
    ADD_PUBLIC_FUNC(SWZSetup::StageFinish_EndAct2);

    // SWZ/UncurlPlant
    ADD_PUBLIC_FUNC(UncurlPlant::CalculateDrawPositions);
    ADD_PUBLIC_FUNC(UncurlPlant::CalculatePositions);

    // SWZ/WallBumper
    ADD_PUBLIC_FUNC(WallBumper::DebugSpawn);
    ADD_PUBLIC_FUNC(WallBumper::DebugDraw);
    ADD_PUBLIC_FUNC(WallBumper::HandleInteractions);

    // Title/LogoSetup
    ADD_PUBLIC_FUNC(LogoSetup::ImageCallback);
    ADD_PUBLIC_FUNC(LogoSetup::Draw_Fade);
    ADD_PUBLIC_FUNC(LogoSetup::State_ShowLogos);
    ADD_PUBLIC_FUNC(LogoSetup::State_FadeToNextLogos);
    ADD_PUBLIC_FUNC(LogoSetup::State_NextLogos);
    ADD_PUBLIC_FUNC(LogoSetup::State_ShowNextLogos);

    // Title/Sega
    ADD_PUBLIC_FUNC(Sega::State_SonicRunIn);
    ADD_PUBLIC_FUNC(Sega::State_SonicRunOut);
    ADD_PUBLIC_FUNC(Sega::State_OriginalGameBy);
    ADD_PUBLIC_FUNC(Sega::State_PresentsText);

    // Title/TitleLogo
    ADD_PUBLIC_FUNC(TitleLogo::SetupPressStart);
    ADD_PUBLIC_FUNC(TitleLogo::State_Ribbon);
    ADD_PUBLIC_FUNC(TitleLogo::State_PressButton);
    ADD_PUBLIC_FUNC(TitleLogo::State_HandleSetup);

    // Title/TitleSetup
    ADD_PUBLIC_FUNC(TitleSetup::VideoSkipCB);
    ADD_PUBLIC_FUNC(TitleSetup::State_Wait);
    ADD_PUBLIC_FUNC(TitleSetup::State_TwinklesFadingIn);
    ADD_PUBLIC_FUNC(TitleSetup::State_WhiteFlash);
    ADD_PUBLIC_FUNC(TitleSetup::State_ClearFlash);
    ADD_PUBLIC_FUNC(TitleSetup::State_SetupStartText);
    ADD_PUBLIC_FUNC(TitleSetup::State_WaitForEnter);
    ADD_PUBLIC_FUNC(TitleSetup::State_FadeToMenu);
    ADD_PUBLIC_FUNC(TitleSetup::State_FadeToVideo);
    ADD_PUBLIC_FUNC(TitleSetup::Draw_FadeBlack);
    ADD_PUBLIC_FUNC(TitleSetup::Draw_Flash);

} // static void InitPublicFunctions

} // namespace GameLogic

#endif