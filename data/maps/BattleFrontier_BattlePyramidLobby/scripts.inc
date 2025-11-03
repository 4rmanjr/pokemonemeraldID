BattleFrontier_BattlePyramidLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomeLobby_OnWarp
	.byte 0

@ Unused. Pyramid uses Dome's OnWarp (presumably by mistake). Their effects are identical
BattleFrontier_BattlePyramidLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePyramidLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattlePyramidLobby_EventScript_TurnPlayerNorth:
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePyramidLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePyramidLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramidLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattlePyramidLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePyramidLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattlePyramidLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattlePyramidLobby_EventScript_QuitWithoutSaving::
	lockall
	message BattleFrontier_BattlePyramidLobby_Text_DidntSaveBeforeQuittingTakeBag
	waitmessage
	playse SE_EXP_MAX
	waitse
	closemessage
	pyramid_set PYRAMID_DATA_WIN_STREAK, 0
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_DefeatedKing
	msgbox BattleFrontier_BattlePyramidLobby_Text_YouveConqueredPyramid, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_GiveBattlePoints

BattleFrontier_BattlePyramidLobby_EventScript_DefeatedKing::
	msgbox BattleFrontier_BattlePyramidLobby_Text_YouveDefeatedPyramidKing, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_GiveBattlePoints::
	special DoBattlePyramidMonsHaveHeldItem
	call_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_StoreHeldItemsInPyramidBag
	clearflag FLAG_STORING_ITEMS_IN_PYRAMID_BAG
	frontier_checkairshow
	special LoadPlayerParty
	pyramid_clearhelditems
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	message BattleFrontier_BattlePyramidLobby_Text_UsedBattleBagWillBeKept
	waitmessage
	playse SE_EXP_MAX
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_GiveYouTheseBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait
	waitmessage
	pyramid_setprize
	pyramid_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_LostChallenge::
	frontier_checkairshow
	special LoadPlayerParty
	pyramid_clearhelditems
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	lockall
	message BattleFrontier_BattlePyramidLobby_Text_DisappointingHereIsBag
	waitmessage
	playse SE_EXP_MAX
	waitse
	message BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait
	waitmessage
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, FALSE
	pyramid_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_ResumeChallenge::
	goto BattleFrontier_BattlePyramidLobby_EventScript_EnterChallenge

BattleFrontier_BattlePyramidLobby_EventScript_Attendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PYRAMID
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattlePyramidLobby_Text_WelcomeToBattlePyramid, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_AskTakeChallenge::
	message BattleFrontier_BattlePyramidLobby_Text_EmbarkOnChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattlePyramidLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattlePyramidLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	callnative RemoveFollowingPokemon
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattlePyramidLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattlePyramidLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	pyramid_init
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	pyramid_seedfloor
	pyramid_settrainers
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallengeSaveFailed
BattleFrontier_BattlePyramidLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePyramidLobby_Text_ShowYouIntoPyramid, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_BattlePyramidLobby_EventScript_WalkToPanelAndReceiveBag
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_RESULT, 0
	special HealPlayerParty
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR, 1, 1
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExplainChallenge::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainBattlePyramid, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattlePyramidLobby_Text_AwaitFutureChallenge, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattlePyramidLobby_EventScript_HintGiver::
	lockall
	applymovement LOCALID_PYRAMID_LOBBY_HINT_GIVER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidLobby_Text_TellYouWhatMisfortunesAwait, MSGBOX_DEFAULT
	call BattleFrontier_BattlePyramidLobby_EventScript_GiveHint
	msgbox BattleFrontier_BattlePyramidLobby_Text_BelieveMyFortunesOrNot, MSGBOX_DEFAULT
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_GiveHint::
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLvOpen
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePyramidLobby_EventScript_NoHint
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_NoHint
	return

@ Shouldnt occur
BattleFrontier_BattlePyramidLobby_EventScript_NoHint::
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLv50::
	msgbox BattleFrontier_BattlePyramidLobby_Text_Aah, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK_ACTIVE_50
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLv50Streak
	setvar VAR_RESULT, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLv50Streak::
	pyramid_get PYRAMID_DATA_WIN_STREAK_50
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLvOpen::
	msgbox BattleFrontier_BattlePyramidLobby_Text_Aah, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK_ACTIVE_OPEN
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLvOpenStreak
	setvar VAR_RESULT, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLvOpenStreak::
	pyramid_get PYRAMID_DATA_WIN_STREAK_OPEN
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment::
	copyvar VAR_0x8004, VAR_RESULT
	special GetBattlePyramidHint
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_HintParalysis
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_HintPoison
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_HintBurn
	case 3, BattleFrontier_BattlePyramidLobby_EventScript_HintPPWaste
	case 4, BattleFrontier_BattlePyramidLobby_EventScript_HintLevitate
	case 5, BattleFrontier_BattlePyramidLobby_EventScript_HintTrapAbility
	case 6, BattleFrontier_BattlePyramidLobby_EventScript_HintIce
	case 7, BattleFrontier_BattlePyramidLobby_EventScript_HintExplosion
	case 8, BattleFrontier_BattlePyramidLobby_EventScript_HintPsychic
	case 9, BattleFrontier_BattlePyramidLobby_EventScript_HintRock
	case 10, BattleFrontier_BattlePyramidLobby_EventScript_HintFighting
	case 11, BattleFrontier_BattlePyramidLobby_EventScript_HintWeather
	case 12, BattleFrontier_BattlePyramidLobby_EventScript_HintBug
	case 13, BattleFrontier_BattlePyramidLobby_EventScript_HintDark
	case 14, BattleFrontier_BattlePyramidLobby_EventScript_HintWater
	case 15, BattleFrontier_BattlePyramidLobby_EventScript_HintGhost
	case 16, BattleFrontier_BattlePyramidLobby_EventScript_HintSteel
	case 17, BattleFrontier_BattlePyramidLobby_EventScript_HintFlyingDragon
	case 18, BattleFrontier_BattlePyramidLobby_EventScript_HintStoneEvolve
	case 19, BattleFrontier_BattlePyramidLobby_EventScript_HintNormal
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintParalysis::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintParalysis, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPoison::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPoison, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintBurn::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintBurn, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPPWaste::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPPWaste, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintLevitate::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintLevitate, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintTrapAbility::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintTrapAbility, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintIce::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintIce, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintExplosion::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintExplosion, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPsychic::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPsychic, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintRock::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintRock, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintFighting::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintFighting, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintWeather::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintWeather, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintBug::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintBug, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintDark::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintDark, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintWater::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintWater, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintGhost::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintGhost, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintSteel::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintSteel, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintFlyingDragon::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintFlyingDragon, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintStoneEvolve::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintStoneEvolve, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintNormal::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintNormal, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_ShowResults::
	lockall
	frontier_results FRONTIER_FACILITY_PYRAMID
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_WalkToPanelAndReceiveBag::
	applymovement LOCALID_PYRAMID_LOBBY_ATTENDANT, BattleFrontier_BattlePyramidLobby_Movement_AttendantWalkToPanel
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePyramidLobby_Movement_PlayerWalkToPanel
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidLobby_Text_WeWillHoldBagForSafekeeping, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_ReceiveNewBattleBag
	msgbox BattleFrontier_BattlePyramidLobby_Text_PleaseTakePreviousBattleBag, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReceiveBattleBag

BattleFrontier_BattlePyramidLobby_EventScript_ReceiveNewBattleBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_PleaseTakeThisBattleBag, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_ReceiveBattleBag::
	message BattleFrontier_BattlePyramidLobby_Text_ExchangedBagForBattleBag
	waitmessage
	playse SE_EXP_MAX
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_StepOnFloorPanel, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PYRAMID_LOBBY_ATTENDANT, BattleFrontier_BattlePyramidLobby_Movement_AttendantMoveAside
	waitmovement 0
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePyramidLobby_Movement_PlayerStepOnPanel
	waitmovement 0
	return

BattleFrontier_BattlePyramidLobby_Movement_AttendantWalkToPanel:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_down
	step_end

BattleFrontier_BattlePyramidLobby_Movement_PlayerWalkToPanel:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePyramidLobby_Movement_AttendantMoveAside:
	walk_right
	face_left
	step_end

BattleFrontier_BattlePyramidLobby_Movement_PlayerStepOnPanel:
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePyramidLobby_EventScript_StoreHeldItemsInPyramidBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_MonHoldingItemCannotTake, MSGBOX_DEFAULT
	setflag FLAG_STORING_ITEMS_IN_PYRAMID_BAG
	special TryStoreHeldItemsInPyramidBag
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_HeldItemsStoredInPyramidBag
	message BattleFrontier_BattlePyramidLobby_Text_BagCannotHoldPickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_HeldItemsStoredInPyramidBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HeldItemsMovedToBag, MSGBOX_DEFAULT
	return

@ When exiting Battle Pyramid with a full pyramid bag and held items the player must select to keep/toss party held items and make room for any kept items by tossing from the pyramid bag
BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep::
	multichoice 17, 6, MULTI_FRONTIER_ITEM_CHOOSE, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromBag
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromParty
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems
	end

BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromBag::
	special ChooseItemsToTossFromPyramidBag
	waitstate
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromParty::
	special BattlePyramidChooseMonHeldItems
	waitstate
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems::
	special DoBattlePyramidMonsHaveHeldItem
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_PartyStillHasHeldItems
	return

BattleFrontier_BattlePyramidLobby_EventScript_PartyStillHasHeldItems::
	msgbox BattleFrontier_BattlePyramidLobby_Text_LeastOneMonHoldingItem, MSGBOX_DEFAULT
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_Woman::
	msgbox BattleFrontier_BattlePyramidLobby_Text_TrainersNoticeRunning, MSGBOX_NPC
	end

BattleFrontier_BattlePyramidLobby_EventScript_FatMan::
	msgbox BattleFrontier_BattlePyramidLobby_Text_LostLotOfItems, MSGBOX_NPC
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattlePyramidLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattlePyramidLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 15, 2, MULTI_BATTLE_PYRAMID_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_RulesPokemon
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_RulesTrainers
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_RulesMaze
	case 3, BattleFrontier_BattlePyramidLobby_EventScript_RulesBag
	case 4, BattleFrontier_BattlePyramidLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_ExitRules
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesPokemon::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainMonRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesTrainers::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainTrainerRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesMaze::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainMazeRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainBagRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattlePyramidLobby_Text_WelcomeToBattlePyramid:
	.string "Tempat di mana keberanian TRAINER\n"
	.string "diuji!\p"
	.string "Selamat datang di BATTLE PYRAMID!\p"
	.string "Aku adalah pemandumu dalam\n"
	.string "Battle Quest.$"

BattleFrontier_BattlePyramidLobby_Text_EmbarkOnChallenge:
	.string "Apa kamu cukup berani untuk memulai\n"
	.string "tantangan Battle Quest?$"

BattleFrontier_BattlePyramidLobby_Text_AwaitFutureChallenge:
	.string "Tantanganmu kami nantikan di masa depan!$"

BattleFrontier_BattlePyramidLobby_Text_ExplainBattlePyramid:
	.string "Battle Quest adalah pertarungan di\n"
	.string "mana kamu harus menjelajahi PYRAMID\l"
	.string "dan mencoba mencapai puncak.\p"
	.string "Di dalam PYRAMID ada tujuh lantai\n"
	.string "labirin, semuanya diisi tidak hanya\l"
	.string "TRAINER hebat juga POKéMON liar.\p"
	.string "Kamu harus masuk dengan tiga POKéMON,\n"
	.string "tanpa memegang item apapun.\p"
	.string "Dalam pendakianmu, akan disediakan\n"
	.string "BATTLE BAG untuk item.\p"
	.string "Jika tantanganmu gagal, semua item\n"
	.string "di dalam BATTLE BAG akan hilang.\p"
	.string "Jika kamu ingin menghentikan tantangan,\n"
	.string "kamu harus memilih “ISTIRAHAT”\l"
	.string "dan simpan permainan.\p"
	.string "Jika tidak disimpan sebelum berhenti,\n"
	.string "kamu akan didiskualifikasi.$"

BattleFrontier_BattlePyramidLobby_Text_WhichLevelMode:
	.string "PYRAMID menawarkan dua pilihan,\n"
	.string "Level 50 dan Open Level.\l"
	.string "Mana yang akan kamu masuki?$"

BattleFrontier_BattlePyramidLobby_Text_SelectThreeMons:
	.string "Bagus. Sekarang, silakan pilih tiga\n"
	.string "POKéMON yang ingin menemanimu.$"

BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLvOpen:
	.string "Ada sedikit masalah, petualang!\p"
	.string "Kamu sepertinya tidak punya tiga\n"
	.string "POKéMON yang memenuhi syarat.\p"
	.string "Harap diingat juga untuk mengambil\n"
	.string "semua item dari POKéMON-mu.\p"
	.string "TELUR{STR_VAR_1} tidak memenuhi syarat.\p"
	.string "Jika sudah siap, silakan\n"
	.string "temui aku lagi.$"

BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLv50:
	.string "Ada sedikit masalah, petualang!\p"
	.string "Kamu sepertinya tidak punya tiga\n"
	.string "POKéMON yang memenuhi syarat.\p"
	.string "Tiga POKéMON harus berbeda dan\n"
	.string "masing-masing tidak lebih dari Lv. 50.\p"
	.string "Harap diingat juga untuk mengambil\n"
	.string "semua item dari POKéMON-mu.\p"
	.string "TELUR{STR_VAR_1} tidak memenuhi syarat.\p"
	.string "Jika sudah siap, silakan\n"
	.string "temui aku lagi.$"

BattleFrontier_BattlePyramidLobby_Text_OkayToSaveBeforeChallenge:
	.string "Sebelum kamu masuk BATTLE PYRAMID,\n"
	.string "permainan harus disimpan. Boleh?$"

BattleFrontier_BattlePyramidLobby_Text_ShowYouIntoPyramid:
	.string "Baiklah. Aku akan mengantarmu\n"
	.string "masuk ke BATTLE PYRAMID.$"

BattleFrontier_BattlePyramidLobby_Text_WeWillHoldBagForSafekeeping:
	.string "Kami akan menyimpan Tas-mu,\n"
	.string "{PLAYER}, selama kamu menjelajah.$"

BattleFrontier_BattlePyramidLobby_Text_PleaseTakePreviousBattleBag:
	.string "Sebagai gantinya, silakan ambil\n"
	.string "BATTLE BAG yang kamu pakai sebelumnya.$"

BattleFrontier_BattlePyramidLobby_Text_PleaseTakeThisBattleBag:
	.string "Sebagai gantinya, silakan ambil\n"
	.string "BATTLE BAG ini.$"

BattleFrontier_BattlePyramidLobby_Text_ExchangedBagForBattleBag:
	.string "{PLAYER} menukar Tas dengan\n"
	.string "BATTLE BAG.$"

BattleFrontier_BattlePyramidLobby_Text_StepOnFloorPanel:
	.string "Saat kamu menginjak panel ini,\n"
	.string "kamu akan pindah ke lantai yang lebih\l"
	.string "tinggi di dalam PYRAMID.\p"
	.string "Semoga petualanganmu\n"
	.string "berjalan dengan aman!$"

BattleFrontier_BattlePyramidLobby_Text_DidntSaveBeforeQuittingTakeBag:
	.string "Masalah besar, penjelajah!\p"
	.string "Kamu tidak menyimpan permainan\n"
	.string "sebelum tantanganmu berakhir.\p"
	.string "Akibatnya, tantanganmu telah\n"
	.string "didiskualifikasi, maaf.\p"
	.string "Ini Tas yang kami simpan\n"
	.string "untukmu.\p"
	.string "{PLAYER} mendapatkan Tas kembali.$"

BattleFrontier_BattlePyramidLobby_Text_YouveConqueredPyramid:
	.string "Senang melihatmu kembali!\p"
	.string "Kamu telah menaklukkan PYRAMID!\n"
	.string "Luar biasa!$"

BattleFrontier_BattlePyramidLobby_Text_MonHoldingItemCannotTake:
	.string "Ah, ada sedikit masalah.\p"
	.string "Setidaknya satu POKéMON masih\n"
	.string "memegang sebuah item.\p"
	.string "Maaf, item yang didapat di PYRAMID\n"
	.string "tidak bisa dibawa keluar.$"

BattleFrontier_BattlePyramidLobby_Text_HeldItemsMovedToBag:
	.string "Semua item yang dipegang POKéMON-mu\n"
	.string "akan dipindahkan ke BATTLE BAG-mu, {PLAYER}.$"

BattleFrontier_BattlePyramidLobby_Text_BagCannotHoldPickItemsToKeep:
	.string "Maaf, BATTLE BAG tidak bisa\n"
	.string "menampung semua item-mu.\p"
	.string "Silakan pilih item yang akan kamu\n"
	.string "simpan di BATTLE BAG dan POKéMON-mu.$"

BattleFrontier_BattlePyramidLobby_Text_LeastOneMonHoldingItem:
	.string "Setidaknya satu POKéMON masih\n"
	.string "memegang sebuah item.$"

BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep:
	.string "Silakan pilih item yang akan kamu\n"
	.string "simpan di BATTLE BAG dan POKéMON-mu.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_ReturnedEverythingMonsHeld:
	.string "{PLAYER} mengembalikan semua yang\n"
	.string "dipegang POKéMON.$"

BattleFrontier_BattlePyramidLobby_Text_UsedBattleBagWillBeKept:
	.string "BATTLE BAG yang kamu gunakan akan\n"
	.string "disimpan untuk tantangan berikutnya.\p"
	.string "{PLAYER} menyerahkan BATTLE BAG\n"
	.string "untuk mendapatkan Tas kembali.$"

BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait:
	.string "Aku harus mencatat hasilmu.\n"
	.string "Mohon tunggu.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_ForConqueringPyramidTakeThis:
	.string "Sebagai kenang-kenangan telah\n"
	.string "menaklukkan BATTLE PYRAMID, terimalah ini.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_ReceivedPrizeItem:
	.string "{PLAYER} mendapatkan hadiah\n"
	.string "{STR_VAR_1}.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_BagIsFull:
	.string "…Ah…\n"
	.string "Tas-mu sepertinya penuh.\p"
	.string "Silakan kembali setelah kamu\n"
	.string "merapikan isi Tas-mu.$"

BattleFrontier_BattlePyramidLobby_Text_DisappointingHereIsBag:
	.string "Mengecewakan sekali…\p"
	.string "Ini Tas yang kami simpan\n"
	.string "untukmu.\p"
	.string "{PLAYER} mendapatkan Tas kembali.$"

BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge:
	.string "Kami menantikan\n"
	.string "tantanganmu berikutnya!$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_HereIsPrize:
	.string "Kami telah menantikan\n"
	.string "kedatanganmu!\p"
	.string "Ini hadiahmu karena telah\n"
	.string "menaklukkan PYRAMID.$"

BattleFrontier_BattlePyramidLobby_Text_TellYouWhatMisfortunesAwait:
	.string "Selamat datang…\p"
	.string "Aku akan memberitahumu nasib buruk\n"
	.string "apa yang menanti di dalam PYRAMID…$"

BattleFrontier_BattlePyramidLobby_Text_Aah:
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "… … … … … …\n"
	.string "Aah!$"

BattleFrontier_BattlePyramidLobby_Text_HintParalysis:
	.string "Aku melihat percikan api…\p"
	.string "…Dan di dalamnya, kulihat POKéMON-mu\n"
	.string "berjuang melawan kelumpuhan…$"

BattleFrontier_BattlePyramidLobby_Text_HintPoison:
	.string "Aku melihat racun…\p"
	.string "…Dan, kulihat POKéMON-mu menderita\n"
	.string "karena efek racun…$"

BattleFrontier_BattlePyramidLobby_Text_HintBurn:
	.string "Aku melihat api merah terang…\p"
	.string "…Dan, kulihat POKéMON-mu menderita\n"
	.string "karena luka bakar…$"

BattleFrontier_BattlePyramidLobby_Text_HintPPWaste:
	.string "Aku merasakan tekanan dahsyat dari\n"
	.string "amarah yang tak terbalas…\p"
	.string "Ini adalah kutukan…\p"
	.string "…Dan, kulihat Power Points POKéMON-mu\n"
	.string "terkuras dan tidak punya pilihan\l"
	.string "selain menggunakan STRUGGLE…$"

BattleFrontier_BattlePyramidLobby_Text_HintLevitate:
	.string "Aku melihat POKéMON melayang tinggi…\p"
	.string "…Dan, kulihat POKéMON-mu frustrasi\n"
	.string "oleh jurus tipe GROUND yang tak berdaya…$"

BattleFrontier_BattlePyramidLobby_Text_HintTrapAbility:
	.string "Aku merasakan energi dahsyat naik\n"
	.string "dari tanah di bawah…\p"
	.string "…Dan, kulihat POKéMON-mu tidak bisa\n"
	.string "lepas dari cengkeraman kekuatan itu…$"

BattleFrontier_BattlePyramidLobby_Text_HintIce:
	.string "Aku melihat POKéMON tipe ES…\p"
	.string "…Dan, kulihat POKéMON-mu melawan\n"
	.string "efek pembekuan dari es…$"

BattleFrontier_BattlePyramidLobby_Text_HintExplosion:
	.string "Aku melihat serentetan jurus yang\n"
	.string "membahayakan pengguna…\p"
	.string "…Dan, kulihat POKéMON-mu\n"
	.string "jatuh karenanya…$"

BattleFrontier_BattlePyramidLobby_Text_HintPsychic:
	.string "Aku melihat POKéMON tipe PSYCHIC…\p"
	.string "…Dan, kulihat POKéMON-mu tersiksa\n"
	.string "oleh jurus PSYCHIC…$"

BattleFrontier_BattlePyramidLobby_Text_HintRock:
	.string "Aku melihat POKéMON tipe BATU…\p"
	.string "…Dan, kulihat POKéMON-mu menderita\n"
	.string "karena jurus BATU…$"

BattleFrontier_BattlePyramidLobby_Text_HintFighting:
	.string "Aku melihat POKéMON tipe TARUNG…\p"
	.string "…Dan, kulihat POKéMON-mu dipukuli\n"
	.string "oleh jurus TARUNG…$"

BattleFrontier_BattlePyramidLobby_Text_HintWeather:
	.string "RAIN DANCE… SUNNY DAY…\n"
	.string "SANDSTORM… HAIL…\p"
	.string "Aku melihat POKéMON yang menjadi lebih\n"
	.string "kuat seiring cuaca…\p"
	.string "…Dan, kulihat POKéMON-mu dibuat bingung\n"
	.string "oleh berbagai jenis jurus…$"

BattleFrontier_BattlePyramidLobby_Text_HintBug:
	.string "Aku melihat POKéMON tipe SERANGGA…\p"
	.string "…Dan, kulihat POKéMON-mu menderita\n"
	.string "dari berbagai jenis serangan…$"

BattleFrontier_BattlePyramidLobby_Text_HintDark:
	.string "Aku melihat POKéMON tipe GELAP…\p"
	.string "…Dan, kulihat POKéMON-mu menderita\n"
	.string "karena jurus tipe GELAP…$"

BattleFrontier_BattlePyramidLobby_Text_HintWater:
	.string "Aku melihat POKéMON tipe AIR…\p"
	.string "…Dan, kulihat POKéMON-mu menderita\n"
	.string "karena jurus tipe AIR…$"

BattleFrontier_BattlePyramidLobby_Text_HintGhost:
	.string "Aku melihat POKéMON tipe HANTU…\p"
	.string "…Dan, kulihat POKéMON-mu menderita\n"
	.string "karena jurus tipe HANTU…$"

BattleFrontier_BattlePyramidLobby_Text_HintSteel:
	.string "Aku melihat POKéMON tipe BAJA…\p"
	.string "…Dan, kulihat POKéMON-mu menderita\n"
	.string "karena jurus yang sangat kuat…$"

BattleFrontier_BattlePyramidLobby_Text_HintFlyingDragon:
	.string "Aku melihat POKéMON terbang…\p"
	.string "…Dan, kulihat POKéMON-mu menderita\n"
	.string "karena jurus yang sangat kuat…$"

BattleFrontier_BattlePyramidLobby_Text_HintStoneEvolve:
	.string "Aku melihat mereka yang telah\n"
	.string "berevolusi dari kekuatan batu…\p"
	.string "Aku juga merasakan api, air,\n"
	.string "dan listrik…\p"
	.string "…Dan, kulihat POKéMON-mu menderita\n"
	.string "dari ketiga kekuatan itu…$"

BattleFrontier_BattlePyramidLobby_Text_HintNormal:
	.string "Aku melihat POKéMON tipe NORMAL…\p"
	.string "…Dan, kulihat POKéMON-mu menderita\n"
	.string "karena jurus yang sangat kuat…$"

BattleFrontier_BattlePyramidLobby_Text_BelieveMyFortunesOrNot:
	.string "Percaya atau tidak dengan ramalanku,\n"
	.string "pilihan ada padamu…\p"
	.string "Masa depan bisa berubah kapan saja…\n"
	.string "Semoga perjalananmu aman…$"

BattleFrontier_BattlePyramidLobby_Text_TrainersNoticeRunning:
	.string "Tahukah kamu?\p"
	.string "Jika kamu berlari kencang, TRAINER\n"
	.string "mungkin akan melihatmu dan bertarung.\p"
	.string "Jadi, jika ingin menghindari TRAINER,\n"
	.string "jangan tatap mata mereka, tapi\l"
	.string "menyelinaplah dengan hati-hati.$"

BattleFrontier_BattlePyramidLobby_Text_LostLotOfItems:
	.string "Awaaaaaaarrrrgh!\p"
	.string "Aku punya banyak sekali item, tapi\n"
	.string "semuanya hilang saat aku kalah!\p"
	.string "Awaaaaaaarrrrgh!$"

BattleFrontier_BattlePyramidLobby_Text_YouveDefeatedPyramidKing:
	.string "Selamat datang kembali!\n"
	.string "Kamu melakukan hal yang mustahil!\p"
	.string "Kamu telah mengalahkan RAJA PYRAMID\n"
	.string "dan menaklukkan BATTLE PYRAMID!$"

BattleFrontier_BattlePyramidLobby_Text_GiveYouTheseBattlePoints:
	.string "Penjelajah muda!\n"
	.string "Sebagai penghargaan atas keberanianmu,\l"
	.string "kami berikan Battle Point ini!$"

BattleFrontier_BattlePyramidLobby_Text_RulesAreListed:
	.string "Aturan Battle Quest terdaftar.$"

BattleFrontier_BattlePyramidLobby_Text_ReadWhichHeading:
	.string "Judul mana yang ingin kamu baca?$"

BattleFrontier_BattlePyramidLobby_Text_ExplainMonRules:
	.string "Saat PYRAMID ditaklukkan, POKéMON\n"
	.string "liar yang muncul di dalamnya akan\l"
	.string "digantikan oleh jenis yang berbeda.\p"
	.string "Jelajahi, amati, dan pelajari jenis\n"
	.string "POKéMON liar apa yang mungkin kamu temui.$"

BattleFrontier_BattlePyramidLobby_Text_ExplainTrainerRules:
	.string "Para TRAINER menunggumu\n"
	.string "di dalam PYRAMID.\p"
	.string "Di setiap lantai, ada hingga\n"
	.string "delapan TRAINER.\p"
	.string "Saat kamu mengalahkan seorang TRAINER,\n"
	.string "kamu akan dapat petunjuk untuk avonturmu.$"

BattleFrontier_BattlePyramidLobby_Text_ExplainMazeRules:
	.string "Labirin di PYRAMID menata ulang\n"
	.string "dirinya sendiri setiap kali kamu masuk.\p"
	.string "Labirinnya remang-remang.\n"
	.string "Kamu harus maju dengan hati-hati.\p"
	.string "Cahaya akan semakin terang setiap kali\n"
	.string "kamu mengalahkan POKéMON liar atau TRAINER.$"

BattleFrontier_BattlePyramidLobby_Text_ExplainBagRules:
	.string "BATTLE BAG berfungsi sebagai Tas-mu\n"
	.string "selama di dalam PYRAMID.\p"
	.string "Ada dua BATTLE BAG terpisah--\n"
	.string "masing-masing untuk petualangan\l"
	.string "Level 50 dan Open Level.\p"
	.string "Masing-masing dapat menampung hingga\n"
	.string "99 buah dari sepuluh jenis item.\p"
	.string "Isi BATTLE BAG akan hilang\n"
	.string "jika misimu gagal.$"
