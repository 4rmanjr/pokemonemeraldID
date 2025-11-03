//gemini
SlateportCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_OnFrame
	.byte 0

SlateportCity_OnTransition:
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 0
	call SlateportCity_EventScript_EnterSlateport
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_MovePeopleForSternInterview
	call_if_eq VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_SetReadyForScottScene
	end

SlateportCity_EventScript_EnterSlateport::
	setflag FLAG_VISITED_SLATEPORT_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	setflag FLAG_HIDE_SLATEPORT_CITY_CONTEST_REPORTER
	return

SlateportCity_EventScript_MovePeopleForSternInterview::
	setobjectxyperm LOCALID_SLATEPORT_CAPT_STERN, 28, 13
	setobjectxyperm LOCALID_SLATEPORT_OLD_WOMAN, 25, 13
	setobjectxyperm LOCALID_SLATEPORT_RICH_BOY, 25, 14
	setobjectxyperm LOCALID_SLATEPORT_COOK, 27, 16
	setobjectxyperm LOCALID_SLATEPORT_GIRL, 28, 16
	setobjectxyperm LOCALID_SLATEPORT_FAT_MAN, 29, 16
	setobjectxyperm LOCALID_SLATEPORT_MAN_1, 31, 14
	setobjectmovementtype LOCALID_SLATEPORT_CAPT_STERN, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype LOCALID_SLATEPORT_OLD_WOMAN, MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT
	setobjectmovementtype LOCALID_SLATEPORT_RICH_BOY, MOVEMENT_TYPE_FACE_UP_AND_RIGHT
	setobjectmovementtype LOCALID_SLATEPORT_COOK, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_SLATEPORT_GIRL, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_SLATEPORT_FAT_MAN, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_SLATEPORT_MAN_1, MOVEMENT_TYPE_FACE_LEFT
	return

SlateportCity_EventScript_SetReadyForScottScene::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 30, SlateportCity_EventScript_MoveScottLeft
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 23, 27
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_EventScript_MoveScottLeft::
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 22, 27
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_OnFrame:
	map_script_2 VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_ScottScene
	.2byte 0

SlateportCity_EventScript_ScottScene::
	lockall
	addobject LOCALID_SLATEPORT_SCOTT
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerFaceScott
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottApproachPlayer
	waitmovement 0
	msgbox SlateportCity_Text_YouDroveTeamAquaAway, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_SCOTT, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 60
	msgbox SlateportCity_Text_MaybeThisTrainer, MSGBOX_DEFAULT
	applymovement LOCALID_SLATEPORT_SCOTT, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox SlateportCity_Text_LetsRegisterEachOther, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SlateportCity_Text_RegisteredScott, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_SCOTT_MATCH_CALL
	msgbox SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExit
	waitmovement 0
	removeobject LOCALID_SLATEPORT_SCOTT
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 10, 12
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_DOWN
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 2
	addvar VAR_SCOTT_STATE, 1
	releaseall
	end

SlateportCity_Movement_PlayerFaceScott:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_ScottApproachPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_Movement_ScottExit:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_EventScript_EnergyGuru::
	lock
	faceplayer
	message SlateportCity_Text_EnergyGuruSellWhatYouNeed
	waitmessage
	pokemart SlateportCity_Pokemart_EnergyGuru
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_EnergyGuru:
	.2byte ITEM_PROTEIN
	.2byte ITEM_IRON
	.2byte ITEM_CARBOS
	.2byte ITEM_ZINC
	.2byte ITEM_CALCIUM
	.2byte ITEM_HP_UP
	pokemartlistend

SlateportCity_EventScript_EffortRibbonWoman::
	lock
	faceplayer
	bufferleadmonspeciesname STR_VAR_1
	msgbox SlateportCity_Text_OhYourPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, LeadMonHasEffortRibbon
	call_if_eq VAR_RESULT, TRUE, SlateportCity_EventScript_MonHasEffortRibbon
	specialvar VAR_RESULT, Special_AreLeadMonEVsMaxedOut
	call_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_MonEVsNotMaxed
	msgbox SlateportCity_Text_PleaseGiveItThisEffortRibbon, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message SlateportCity_Text_ReceivedEffortRibbon
	waitfanfare
	msgbox SlateportCity_Text_PutEffortRibbonOnMon, MSGBOX_DEFAULT
	special GiveLeadMonEffortRibbon
	release
	end

SlateportCity_EventScript_MonEVsNotMaxed::
	msgbox SlateportCity_Text_GoForItLittleHarder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_MonHasEffortRibbon::
	msgbox SlateportCity_Text_EffortRibbonLooksGoodOnIt, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Cook::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_CookSternInterview
	msgbox SlateportCity_Text_SeaweedFullOfLife, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_CookSternInterview::
	msgbox SlateportCity_Text_CaptainComeBackWithBigFish, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_OldWoman::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_OldWomanSternInterview
	msgbox SlateportCity_Text_HowTownIsBornAndGrows, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_OldWomanSternInterview::
	msgbox SlateportCity_Text_CaptSternBeingInterviewed, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Girl::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_GirlSternInterview
	goto_if_set FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_GirlSecretBase
	msgbox SlateportCity_Text_SlateportWonderfulPlace, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_GirlSternInterview::
	msgbox SlateportCity_Text_InterviewerSoCool, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_GirlSecretBase::
	msgbox SlateportCity_Text_BuyBricksSoDecorWontGetDirty, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_RichBoy::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_RichBoySternInterview
	msgbox SlateportCity_Text_GoingToCompeteInBattleTent, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_RichBoySternInterview::
	msgbox SlateportCity_Text_SternSaysDiscoveredSomething, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_FatMan::
	goto_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_FatManSternInterview
	msgbox SlateportCity_Text_BushedHikingFromMauville, MSGBOX_NPC
	end

SlateportCity_EventScript_FatManSternInterview::
	msgbox SlateportCity_Text_AmIOnTV, MSGBOX_SIGN
	end

SlateportCity_EventScript_Man1::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_Man1SternInterview
	msgbox SlateportCity_Text_EveryoneCallsHimCaptStern, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Man1SternInterview::
	msgbox SlateportCity_Text_CaptainsACelebrity, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman1::
	lock
	faceplayer
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_EventScript_Woman1AquaGone
	msgbox SlateportCity_Text_WhatsLongLineOverThere, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman1AquaGone::
	msgbox SlateportCity_Text_VisitedMuseumOften, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_BattleTentSign::
	msgbox SlateportCity_Text_BattleTentSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_SternsShipyardSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_SternsShipyardFerryComplete
	goto_if_set FLAG_BADGE07_GET, SlateportCity_EventScript_SternsShipyardNearsCompletion
	msgbox SlateportCity_Text_SternsShipyardWantedSign, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_SternsShipyardNearsCompletion::
	msgbox SlateportCity_Text_SternsShipyardNearsCompletion, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_SternsShipyardFerryComplete::
	msgbox SlateportCity_Text_SternsShipyardFerryComplete, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_PokemonFanClubSign::
	msgbox SlateportCity_Text_PokemonFanClubSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_OceanicMuseumSign::
	msgbox SlateportCity_Text_OceanicMuseumSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_CitySign::
	msgbox SlateportCity_Text_CitySign, MSGBOX_SIGN
	end

SlateportCity_EventScript_MarketSign::
	msgbox SlateportCity_Text_MarketSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_HarborSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_HarborSignFerryComplete
	msgbox SlateportCity_Text_HarborFerryUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_HarborSignFerryComplete::
	msgbox SlateportCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_NameRatersHouseSign::
	msgbox SlateportCity_Text_NameRatersHouseSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_Maniac::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_ManiacSternInterview
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
	release
	end

@ Unclear if the text here was meant to be different, but its not
SlateportCity_EventScript_ManiacSternInterview::
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman2::
	msgbox SlateportCity_Text_CantChangeTradeMonName, MSGBOX_NPC
	end

SlateportCity_EventScript_Sailor1::
	msgbox SlateportCity_Text_SeaIsSoWet, MSGBOX_NPC
	end

SlateportCity_EventScript_Sailor2::
	msgbox SlateportCity_Text_SinkOldBoats, MSGBOX_NPC
	end

SlateportCity_EventScript_PokefanF::
	msgbox SlateportCity_Text_BuyTooMuch, MSGBOX_NPC
	end

SlateportCity_EventScript_Man2::
	msgbox SlateportCity_Text_BattleTentBuiltRecently, MSGBOX_NPC
	end

SlateportCity_EventScript_AquaGrunt1::
	lock
	faceplayer
	msgbox SlateportCity_Text_QuitPushing, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt2::
	lock
	faceplayer
	msgbox SlateportCity_Text_AquaHasPolicy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt3::
	lock
	faceplayer
	msgbox SlateportCity_Text_BossIsBrilliant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt4::
	lock
	faceplayer
	msgbox SlateportCity_Text_WhatsNewSchemeIWonder, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt5::
	lock
	faceplayer
	msgbox SlateportCity_Text_ShouldTakeItAll, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_5, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt6::
	lock
	faceplayer
	msgbox SlateportCity_Text_DontButtIn, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_6, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt7::
	lock
	faceplayer
	msgbox SlateportCity_Text_RemindsMeOfLongLineForGames, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_7, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt8::
	lock
	faceplayer
	msgbox SlateportCity_Text_WhyAreWeLiningUp, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_8, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt9::
	lock
	faceplayer
	playse SE_PIN
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_Text_WhatDoYouWant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_Text_IllReadSignForYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	msgbox SlateportCity_Text_SaysSomethingLikeSeaIsEndless, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_Movement_DelayAquaGrunt:
	delay_16
	delay_16
	step_end

SlateportCity_EventScript_AquaGrunt10::
	msgbox SlateportCity_Text_ShouldveBroughtMyGameBoy, MSGBOX_SIGN
	end

SlateportCity_EventScript_AquaGrunt11::
	lock
	faceplayer
	msgbox SlateportCity_Text_HotSpringsAfterOperation, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_11, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_DollClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor_Dolls
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_PokemartDecor_Dolls:
	.2byte DECOR_AZURILL_DOLL
	.2byte DECOR_MARILL_DOLL
	.2byte DECOR_SKITTY_DOLL
	pokemartlistend

SlateportCity_EventScript_ComeBackWithSecretPower::
	msgbox gText_ComeBackWithSecretPower, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_DecorClerk::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_ComeBackWithSecretPower
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_PokemartDecor:
	.2byte DECOR_RED_BRICK
	.2byte DECOR_BLUE_BRICK
	.2byte DECOR_YELLOW_BRICK
	.2byte DECOR_RED_BALLOON
	.2byte DECOR_BLUE_BALLOON
	.2byte DECOR_YELLOW_BALLOON
	.2byte DECOR_C_LOW_NOTE_MAT
	.2byte DECOR_D_NOTE_MAT
	.2byte DECOR_E_NOTE_MAT
	.2byte DECOR_F_NOTE_MAT
	.2byte DECOR_G_NOTE_MAT
	.2byte DECOR_A_NOTE_MAT
	.2byte DECOR_B_NOTE_MAT
	.2byte DECOR_C_HIGH_NOTE_MAT
	pokemartlistend

SlateportCity_EventScript_PowerTMClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SlateportCity_Pokemart_PowerTMs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_PowerTMs:
	.2byte ITEM_TM_HIDDEN_POWER
	.2byte ITEM_TM_SECRET_POWER
	pokemartlistend

@ Scene with Capt Sterns interview and Team Aqua announcing plans to steal Submarine
SlateportCity_EventScript_CaptStern::
	lockall
	msgbox SlateportCity_Text_SternMoveAheadWithExploration, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_GabbyWonderfulThanksForInterview, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GABBY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 10
	applymovement LOCALID_SLATEPORT_TY, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 25
	applymovement LOCALID_SLATEPORT_CAPT_STERN, SlateportCity_Movement_SternWatchGabbyAndTyExit
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerFaceStern
	applymovement LOCALID_SLATEPORT_GABBY, SlateportCity_Movement_GabbyExit
	applymovement LOCALID_SLATEPORT_TY, SlateportCity_Movement_TyExit
	waitmovement 0
	removeobject LOCALID_SLATEPORT_GABBY
	removeobject LOCALID_SLATEPORT_TY
	msgbox SlateportCity_Text_SternWhewFirstInterview, MSGBOX_DEFAULT
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Text_OhPlayerWeMadeDiscovery, MSGBOX_DEFAULT
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	msgbox SlateportCity_Text_AquaWillAssumeControlOfSubmarine, MSGBOX_DEFAULT
	applymovement LOCALID_SLATEPORT_COOK, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_SLATEPORT_FAT_MAN, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_SLATEPORT_OLD_WOMAN, SlateportCity_Movement_OldWomanConcern
	applymovement LOCALID_SLATEPORT_RICH_BOY, Common_Movement_QuestionMark
	applymovement LOCALID_SLATEPORT_MAN_1, SlateportCity_Movement_ManConcern
	waitmovement 0
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox SlateportCity_Text_SternWhatWasAllThat, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Text_FromHarborTryingToTakeSub, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_CAPT_STERN, SlateportCity_Movement_SternEnterHarbor
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerEnterHarbor
	waitmovement 0
	removeobject LOCALID_SLATEPORT_CAPT_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SUBMARINE_SHADOW
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_AQUA_GRUNT
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_ARCHIE
	setvar VAR_SLATEPORT_CITY_STATE, 2
	warp MAP_SLATEPORT_CITY_HARBOR, 11, 14
	waitstate
	releaseall
	end

SlateportCity_Movement_OldWomanConcern:
	delay_16
	delay_16
	emote_question_mark
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_ManConcern:
	emote_question_mark
	walk_in_place_faster_up
	delay_16
	walk_in_place_faster_down
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_GabbyExit:
	delay_16
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Movement_TyExit:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Movement_Unused:
	walk_down
	walk_in_place_faster_up
	step_end

SlateportCity_Movement_SternEnterHarbor:
	walk_right
	walk_up
	walk_up
	set_invisible
	step_end

SlateportCity_Movement_SternWatchGabbyAndTyExit:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_left
	step_end

SlateportCity_Movement_PlayerEnterHarbor:
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_right
	walk_up
	step_end

SlateportCity_Movement_PlayerFaceStern:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_down
	step_end

SlateportCity_EventScript_Ty::
	msgbox SlateportCity_Text_BigSmileForCamera, MSGBOX_SIGN
	end

SlateportCity_EventScript_Gabby::
	msgbox SlateportCity_Text_MostInvaluableExperience, MSGBOX_SIGN
	end

SlateportCity_EventScript_Man3::
	msgbox SlateportCity_Text_WonderIfLighthouseStartlesPokemon, MSGBOX_NPC
	end

SlateportCity_EventScript_BerryPowderClerk::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POWDER_JAR, SlateportCity_EventScript_ReceivedPowderJar
	msgbox SlateportCity_Text_ExplainBerries, MSGBOX_DEFAULT
	giveitem ITEM_POWDER_JAR
	setflag FLAG_RECEIVED_POWDER_JAR
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_ReceivedPowderJar::
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_ExplainBerryPowder
	msgbox SlateportCity_Text_BroughtMeSomeBerryPowder, MSGBOX_DEFAULT
	special DisplayBerryPowderVendorMenu
	goto SlateportCity_EventScript_ChooseBerryPowderItem
	end

SlateportCity_EventScript_ExplainBerryPowder::
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_ChooseBerryPowderItem::
	message SlateportCity_Text_ExchangeWhatWithIt
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BERRY_POWDER_VENDOR
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, SlateportCity_EventScript_EnergyPowder
	case 1, SlateportCity_EventScript_EnergyRoot
	case 2, SlateportCity_EventScript_HealPowder
	case 3, SlateportCity_EventScript_RevivalHerb
	case 4, SlateportCity_EventScript_Protein
	case 5, SlateportCity_EventScript_Iron
	case 6, SlateportCity_EventScript_Carbos
	case 7, SlateportCity_EventScript_Calcium
	case 8, SlateportCity_EventScript_Zinc
	case 9, SlateportCity_EventScript_HPUp
	case 10, SlateportCity_EventScript_PPUp
	case 11, SlateportCity_EventScript_CancelPowderItemSelect
	case MULTI_B_PRESSED, SlateportCity_EventScript_CancelPowderItemSelect
	end

SlateportCity_EventScript_EnergyPowder::
	bufferitemname STR_VAR_1, ITEM_ENERGY_POWDER
	setvar VAR_0x8008, ITEM_ENERGY_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_EnergyRoot::
	bufferitemname STR_VAR_1, ITEM_ENERGY_ROOT
	setvar VAR_0x8008, ITEM_ENERGY_ROOT
	setvar VAR_0x8009, 80
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_HealPowder::
	bufferitemname STR_VAR_1, ITEM_HEAL_POWDER
	setvar VAR_0x8008, ITEM_HEAL_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_RevivalHerb::
	bufferitemname STR_VAR_1, ITEM_REVIVAL_HERB
	setvar VAR_0x8008, ITEM_REVIVAL_HERB
	setvar VAR_0x8009, 300
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Protein::
	bufferitemname STR_VAR_1, ITEM_PROTEIN
	setvar VAR_0x8008, ITEM_PROTEIN
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Iron::
	bufferitemname STR_VAR_1, ITEM_IRON
	setvar VAR_0x8008, ITEM_IRON
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Carbos::
	bufferitemname STR_VAR_1, ITEM_CARBOS
	setvar VAR_0x8008, ITEM_CARBOS
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Calcium::
	bufferitemname STR_VAR_1, ITEM_CALCIUM
	setvar VAR_0x8008, ITEM_CALCIUM
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Zinc::
	bufferitemname STR_VAR_1, ITEM_ZINC
	setvar VAR_0x8008, ITEM_ZINC
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_HPUp::
	bufferitemname STR_VAR_1, ITEM_HP_UP
	setvar VAR_0x8008, ITEM_HP_UP
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_PPUp::
	bufferitemname STR_VAR_1, ITEM_PP_UP
	setvar VAR_0x8008, ITEM_PP_UP
	setvar VAR_0x8009, 3000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_CancelPowderItemSelect::
	msgbox SlateportCity_Text_ComeBackToTradeBerryPowder, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_TryBuyBerryPowderItem::
	msgbox SlateportCity_Text_ExchangeBerryPowderForItem, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_EventScript_ChooseBerryPowderItem
	copyvar VAR_0x8004, VAR_0x8009
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NotEnoughBerryPowder
	giveitem VAR_0x8008
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NoRoomForBerryPowderItem
	copyvar VAR_0x8004, VAR_0x8009
	special TakeBerryPowder
	special PrintPlayerBerryPowderAmount
	msgbox SlateportCity_Text_FineBerryPowderTradeSomethingElse, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_EventScript_ChooseBerryPowderItem
	msgbox SlateportCity_Text_WhenYouGetMoreBringItToMe, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_NoRoomForBerryPowderItem::
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_NotEnoughBerryPowder::
	msgbox SlateportCity_Text_DontHaveEnoughBerryPowder, MSGBOX_DEFAULT
	goto SlateportCity_EventScript_ChooseBerryPowderItem
	end

SlateportCity_EventScript_ScottBattleTentScene::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	opendoor 10, 12
	waitdooranim
	addobject LOCALID_SLATEPORT_SCOTT
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PushPlayerDown
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExitBattleTent
	waitmovement 0
	closedoor 10, 12
	waitdooranim
	msgbox SlateportCity_Text_TakingBattleTentChallenge, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExitAfterBattleTent
	waitmovement 0
	removeobject LOCALID_SLATEPORT_SCOTT
	addvar VAR_SCOTT_STATE, 1
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	releaseall
	end

SlateportCity_Movement_PushPlayerDown:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

SlateportCity_Movement_PlayerWatchScottExit:
	delay_16
	walk_in_place_faster_right
	step_end

SlateportCity_Movement_ScottExitBattleTent:
	delay_8
	walk_down
	step_end

SlateportCity_Movement_ScottExitAfterBattleTent:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_EventScript_BerryCrushRankingsSign::
	lockall
	special ShowBerryCrushRankings
	waitstate
	releaseall
	end

SlateportCity_Text_EnergyGuruSellWhatYouNeed:
	.string "Aku GURU ENERGI! Aku akan bertekad\n"
	.string "dan menjual padamu apa yang kamu\l"
	.string "butuhkan!$"

SlateportCity_Text_OhYourPokemon:
	.string "Oh? {STR_VAR_1} milikmu…$"

SlateportCity_Text_PleaseGiveItThisEffortRibbon:
	.string "Bertekad dengan luar biasa!\p"
	.string "Sebagai hadiahnya, berikanlah PITA\n"
	.string "UPAYA ini.$"

SlateportCity_Text_ReceivedEffortRibbon:
	.string "{PLAYER} menerima PITA UPAYA.$"

SlateportCity_Text_PutEffortRibbonOnMon:
	.string "{PLAYER} memasang PITA UPAYA pada\n"
	.string "{STR_VAR_1}.$"

SlateportCity_Text_GoForItLittleHarder:
	.string "Kamu harus bertekad sedikit lebih\n"
	.string "keras.\p"
	.string "Jika kamu melakukannya, Aku akan\n"
	.string "memberikan sesuatu yang bagus untuk\l"
	.string "POKéMON-mu.$"

SlateportCity_Text_EffortRibbonLooksGoodOnIt:
	.string "Oh! {STR_VAR_1} milikmu, PITA UPAYA\n"
	.string "itu terlihat bagus dikenakannya!$"

SlateportCity_Text_WonderIfLighthouseStartlesPokemon:
	.string "Cahaya mercusuar mencapai puluhan\n"
	.string "mil jauhnya.\p"
	.string "Aku ingin tahu apakah itu tidak\n"
	.string "membuat POKéMON di laut terkejut.$"

SlateportCity_Text_SeaweedFullOfLife:
	.string "Wah, lihat ini!\p"
	.string "Rumput laut yang bisa kamu dapatkan\n"
	.string "di sekitar sini segar dan penuh\l"
	.string "kehidupan.\p"
	.string "Wah, kelihatannya bahkan bisa\n"
	.string "berdiri tegak dan menyerang!$"

SlateportCity_Text_HowTownIsBornAndGrows:
	.string "Tempat air bersih, hasil panen\n"
	.string "melimpah berkumpul.\p"
	.string "Dan tempat orang-orang berkumpul,\n"
	.string "pasar segera dimulai.\p"
	.string "Begitulah kota lahir dan tumbuh.$"

SlateportCity_Text_SlateportWonderfulPlace:
	.string "Berbelanja di tempat kamu bisa\n"
	.string "menghirup aroma laut…\p"
	.string "SLATEPORT adalah tempat yang sangat\n"
	.string "indah!$"

SlateportCity_Text_BuyBricksSoDecorWontGetDirty:
	.string "Jika kamu meletakkan BONEKA atau\n"
	.string "BANTAL di lantai, benda-benda itu\l"
	.string "akan kotor.\p"
	.string "Aku akan membeli beberapa BATU BATA\n"
	.string "agar BONEKA dan BANTAL-ku tidak\l"
	.string "kotor saat Aku meninggalkannya.$"

SlateportCity_Text_GoingToCompeteInBattleTent:
	.string "Grooar! Aku juga akan berkompetisi\n"
	.string "di KEMAH PERTARUNGAN!\p"
	.string "Tapi sebelum itu, Aku harus\n"
	.string "menangkap beberapa POKéMON!$"

SlateportCity_Text_BushedHikingFromMauville:
	.string "Fiuh… Aku benar-benar lelah…\p"
	.string "Aku berjalan kaki dari KOTA\n"
	.string "MAUVILLE. Tapi, wah, kota ini besar\l"
	.string "sekali.\p"
	.string "Jika Aku tahu ini, Aku akan menaiki\n"
	.string "SEPEDA-ku ke sini.$"

SlateportCity_Text_EveryoneCallsHimCaptStern:
	.string "STERN, orang yang membangun MUSEUM,\n"
	.string "kebetulan juga adalah pemimpin tim\l"
	.string "eksplorasi bawah laut.\p"
	.string "Jadi, semua orang memanggilnya\n"
	.string "KAPTEN STERN.$"

SlateportCity_Text_WhatsLongLineOverThere:
	.string "Apa itu di sana? Antrean panjang\n"
	.string "itu…$"

SlateportCity_Text_VisitedMuseumOften:
	.string "Ketika Aku masih kecil, Aku sering\n"
	.string "mengunjungi MUSEUM.\p"
	.string "Aku sering memimpikan misteri laut\n"
	.string "setelah melihat pameran.$"

SlateportCity_Text_QuitPushing:
	.string "Hei! Berhenti mendorong! Ini\n"
	.string "antrean, tidakkah kamu lihat?$"

SlateportCity_Text_AquaHasPolicy:
	.string "TEAM AQUA punya kebijakan untuk\n"
	.string "berkumpul dan bubar di lokasi\l"
	.string "operasi.$"

SlateportCity_Text_BossIsBrilliant:
	.string "BOS kami cemerlang.\p"
	.string "Apa yang ingin dia lakukan dengan\n"
	.string "MUSEUM sekarang?$"

SlateportCity_Text_WhatsNewSchemeIWonder:
	.string "Apa rencana barunya, ya?\p"
	.string "BOS kami menakutkan saat marah,\n"
	.string "jadi lebih baik Aku tidak mengacau…$"

SlateportCity_Text_ShouldTakeItAll:
	.string "Jika ada sesuatu yang kami butuhkan\n"
	.string "di MUSEUM, kami harus mengambil\l"
	.string "semuanya!$"

SlateportCity_Text_DontButtIn:
	.string "Hei, kamu di sana! Jangan menyela!$"

SlateportCity_Text_RemindsMeOfLongLineForGames:
	.string "Antrean panjang, ya?\p"
	.string "Itu mengingatkanku pada saat-saat\n"
	.string "Aku mengantre untuk membeli game\l"
	.string "laris…$"

SlateportCity_Text_WhyAreWeLiningUp:
	.string "Kenapa kita harus mengantre dan\n"
	.string "membayar? Kita seharusnya langsung\l"
	.string "masuk saja!$"

SlateportCity_Text_WhatDoYouWant:
	.string "Apa? Apa yang kamu mau?$"

SlateportCity_Text_IllReadSignForYou:
	.string "Kamu mau membaca tanda ini? Aku\n"
	.string "akan membacakannya untukmu!$"

SlateportCity_Text_SaysSomethingLikeSeaIsEndless:
	.string "Coba lihat…\p"
	.string "Emm… Kurasa tertulis sesuatu\n"
	.string "seperti “kehidupan di laut tak ada\l"
	.string "habisnya.” Ya, Aku cukup yakin\l"
	.string "begitulah bunyinya.$"

SlateportCity_Text_ShouldveBroughtMyGameBoy:
	.string "Gerutuan…\p"
	.string "Seharusnya Aku membawa Game Boy\n"
	.string "Advance-ku supaya Aku tidak bosan\l"
	.string "mengantre…\p"
	.string "Gerutuan…$"

SlateportCity_Text_HotSpringsAfterOperation:
	.string "Setelah operasi ini selesai, Aku\n"
	.string "akan membawamu ke spa air panas!\p"
	.string "Itu yang dikatakan pemimpin kami.\n"
	.string "Aku tidak sabar!$"

SlateportCity_Text_SeaIsSoWet:
	.string "Laut itu sangat luas…\p"
	.string "Mungkinkah laut tercipta dari air\n"
	.string "mata yang ditumpahkan POKéMON?$"

SlateportCity_Text_SinkOldBoats:
	.string "Apakah kamu tahu apa yang mereka\n"
	.string "lakukan dengan kapal-kapal tua yang\l"
	.string "terlalu reyot untuk berlayar?\p"
	.string "Mereka menenggelamkannya di laut\n"
	.string "agar menjadi habitat bagi POKéMON.$"

SlateportCity_Text_BuyTooMuch:
	.string "Setiap kali Aku berkunjung ke sini,\n"
	.string "Aku terbawa suasana dan membeli\l"
	.string "terlalu banyak.$"

SlateportCity_Text_GetNameRaterToHelpYou:
	.string "Jika kamu ingin mengubah nama\n"
	.string "panggilan POKéMON-mu, kamu harus\l"
	.string "meminta bantuan PENILAI NAMA.$"

SlateportCity_Text_CantChangeTradeMonName:
	.string "POKéMON apa pun yang kamu dapatkan\n"
	.string "dalam pertukaran, kamu tidak bisa\l"
	.string "mengubah nama panggilannya.\p"
	.string "Rasa cinta TRAINER asli terhadap\n"
	.string "POKéMON itu ada dalam nama\l"
	.string "panggilannya.$"

SlateportCity_Text_BattleTentBuiltRecently:
	.string "Baru-baru ini, KEMAH PERTARUNGAN\n"
	.string "dibangun di SLATEPORT.\p"
	.string "GEDUNG OLAHRAGA memang\n"
	.string "menyenangkan, tapi KEMAH\l"
	.string "PERTARUNGAN luar biasa dengan\l"
	.string "caranya sendiri.\p"
	.string "Kamu harus mencari POKéMON tangguh\n"
	.string "untuk KEMAH PERTARUNGAN!$"

SlateportCity_Text_CaptSternBeingInterviewed:
	.string "Aku berharap itu adalah bintang\n"
	.string "terkenal sehingga Aku bisa\l"
	.string "mendapatkan tanda tangan.\p"
	.string "Tapi siapa yang diwawancarai itu?\n"
	.string "Bukankah itu KAPTEN STERN?$"

SlateportCity_Text_InterviewerSoCool:
	.string "Pewawancara wanita itu sangat keren\n"
	.string "dan cantik.\p"
	.string "Ketika Aku besar nanti, Aku akan\n"
	.string "menjadi jurnalis internasional!$"

SlateportCity_Text_SternSaysDiscoveredSomething:
	.string "KAPTEN STERN bilang mereka\n"
	.string "menemukan sesuatu di dasar laut.\p"
	.string "Aku ingin tahu apa itu? Apa\n"
	.string "gerangan itu?$"

SlateportCity_Text_CaptainComeBackWithBigFish:
	.string "Apa yang terjadi di sini?\p"
	.string "Apakah SANG KAPTEN kembali membawa\n"
	.string "ikan besar dari dasar laut?$"

SlateportCity_Text_AmIOnTV:
	.string "Hei! Apakah kamu menonton? Apakah\n"
	.string "Aku di TV?$"

SlateportCity_Text_CaptainsACelebrity:
	.string "Wawancara TV! Di sini! KAPTEN\n"
	.string "adalah seorang selebriti!$"

SlateportCity_Text_BigSmileForCamera:
	.string "TY: Oke, KAPTEN STERN, senyum lebar\n"
	.string "ke kamera!$"

SlateportCity_Text_MostInvaluableExperience:
	.string "GABBY: Begitu, begitu. Kamu telah\n"
	.string "mendapatkan pengalaman yang paling\l"
	.string "tak ternilai…$"

SlateportCity_Text_SternMoveAheadWithExploration:
	.string "KAPTEN STERN: Ya, benar. Kami\n"
	.string "berniat untuk melanjutkan\l"
	.string "eksplorasi kami.$"

SlateportCity_Text_GabbyWonderfulThanksForInterview:
	.string "GABBY: Itu luar biasa, KAPTEN\n"
	.string "STERN! Terima kasih telah\l"
	.string "menyempatkan waktu dari jadwal\l"
	.string "sibukmu untuk berbicara dengan\l"
	.string "kami.\p"
	.string "Kami harap kami dapat mewawancarai\n"
	.string "kamu lagi dengan berita penemuan\l"
	.string "lainnya!$"

SlateportCity_Text_SternWhewFirstInterview:
	.string "KAPTEN STERN: Fiuh…\p"
	.string "Itu pertama kalinya Aku difilmkan\n"
	.string "untuk TV. Itu sangat menegangkan.$"

SlateportCity_Text_OhPlayerWeMadeDiscovery:
	.string "Oh! {PLAYER}{KUN}! Kamu terlihat\n"
	.string "hebat!\p"
	.string "Kami membuat penemuan besar pada\n"
	.string "eksplorasi dasar laut terakhir\l"
	.string "kami.\p"
	.string "Kami menemukan gua bawah laut di\n"
	.string "RUTE 128.\p"
	.string "Kami pikir itu adalah habitat\n"
	.string "POKéMON yang dikatakan telah lama\l"
	.string "punah.$"

SlateportCity_Text_AquaWillAssumeControlOfSubmarine:
	.string "Fufufu… Kapten STERN, kurasa.\p"
	.string "Kami dari TIM AQUA akan mengambil\n"
	.string "alih kapal selam Kamu!\p"
	.string "Keberatan Kamu tidak berarti! Kami\n"
	.string "mengharapkan kerja sama total Kamu!\p"
	.string "Fufufu… Tonton dan pelajari saja\n"
	.string "apa yang telah direncanakan TIM\l"
	.string "AQUA!$"

SlateportCity_Text_SternWhatWasAllThat:
	.string "KAPTEN STERN: Apa maksud semua itu?\p"
	.string "Kedengarannya seperti seseorang\n"
	.string "menggunakan megafon…\p"
	.string "Dari mana asalnya?$"

SlateportCity_Text_FromHarborTryingToTakeSub:
	.string "Itu dari PELABUHAN!\p"
	.string "Kapal selamnya! Mereka mencoba\n"
	.string "mengambilnya!$"

SlateportCity_Text_PleaseComeWithMe:
	.string "{PLAYER}{KUN}! Tolong, ikut Aku!$"

SlateportCity_Text_BattleTentSign:
	.string "TENTARA PERTARUNGAN LOKASI\n"
	.string "SLATEPORT “Temukan itu! POKéMON\l"
	.string "terhebat!$"

SlateportCity_Text_SternsShipyardWantedSign:
	.string "GALANGAN KAPAL STERN\p"
	.string "“Dicari: Seorang pelaut yang mampu\n"
	.string "berlayar di semua arus.$"

SlateportCity_Text_SternsShipyardNearsCompletion:
	.string "GALANGAN KAPAL STERN\p"
	.string "“Kapal feri S.S. TIDAL hampir\n"
	.string "selesai untuk melayani pelabuhan\l"
	.string "SLATEPORT dan LILYCOVE.$"

SlateportCity_Text_SternsShipyardFerryComplete:
	.string "GALANGAN KAPAL STERN\p"
	.string "“Pemberangkatan feri\n"
	.string "SLATEPORT-LILYCOVE S.S. TIDAL\l"
	.string "diurus di PELABUHAN.$"

SlateportCity_Text_PokemonFanClubSign:
	.string "KLUB PENGGEMAR POKéMON “Memanggil\n"
	.string "semua penggemar POKéMON!$"

SlateportCity_Text_OceanicMuseumSign:
	.string "“Lautan tak berujung menopang semua\n"
	.string "kehidupan. MUSEUM LAUT$"

SlateportCity_Text_CitySign:
	.string "KOTA SLATEPORT\p"
	.string "“Pelabuhan tempat manusia dan\n"
	.string "POKéMON bertemu.$"

SlateportCity_Text_MarketSign:
	.string "PASAR SLATEPORT “Barang unik yang\n"
	.string "tidak ditemukan di tempat lain!$"

SlateportCity_Text_HarborFerryUnderConstruction:
	.string "PELABUHAN SLATEPORT “Kapal feri\n"
	.string "S.S. TIDAL sedang dalam pembangunan\l"
	.string "di GALANGAN KAPAL.\p"
	.string "“Layanan dijadwalkan akan segera\n"
	.string "dimulai.\p"
	.string "PELABUHAN SLATEPORT “Nikmati\n"
	.string "pelayaran menyenangkan di atas feri\l"
	.string "S.S. TIDAL.$"

SlateportCity_Text_HarborSign:
	.string "RUMAH PENILAI NAMA “Nama panggilan\n"
	.string "POKéMON dinilai.\p"
	.string "Jika POKéMON liar terluka, ia\n"
	.string "menyembuhkan dirinya sendiri dengan\l"
	.string "mengunyah BERI.$"

SlateportCity_Text_NameRatersHouseSign:
	.string "Apa Kamu tahu itu?$"

SlateportCity_Text_ExplainBerries:
	.string "Seseorang melihat itu dan mendapat\n"
	.string "ide untuk membuat obat dari BERI.\p"
	.string "Apa Kamu tahu itu?\p"
	.string "Untuk mengubah BERI menjadi obat,\n"
	.string "mereka harus dihancurkan menjadi\l"
	.string "bubuk.\p"
	.string "Apa Kamu tahu itu?\p"
	.string "Kamu sepertinya tertarik pada BERI!\p"
	.string "Aku punya sesuatu yang bagus untuk\n"
	.string "orang seperti Kamu.\p"
	.string "Aku baru-baru ini memasang mesin di\n"
	.string "PUSAT POKéMON untuk menghancurkan\l"
	.string "BERI.\p"
	.string "Mesin PENGHANCUR BERI ada di SUDUT\n"
	.string "LANGSUNG di lantai atas.$"

SlateportCity_Text_ExplainBerryPowder:
	.string "Apa Kamu tahu?\p"
	.string "Bisakah Kamu membuat BUBUK BERI\n"
	.string "untuk Aku menggunakan mesin-mesin\l"
	.string "itu?\p"
	.string "Aku bisa membuatkan Kamu segala\n"
	.string "macam obat jika Kamu membawakan Aku\l"
	.string "banyak BUBUK BERI.\p"
	.string "Apa Kamu membawakan Aku BUBUK BERI?\p"
	.string "Dengan apa Kamu ingin menukarnya?$"

SlateportCity_Text_BroughtMeSomeBerryPowder:
	.string "Oke, Kamu ingin menukar BUBUK BERI\n"
	.string "Kamu dengan satu {STR_VAR_1}?$"

SlateportCity_Text_ExchangeWhatWithIt:
	.string "Aduh. Kamu tidak punya cukup BUBUK\n"
	.string "BERI.$"

SlateportCity_Text_ExchangeBerryPowderForItem:
	.string "Ini BUBUK BERI yang bagus. Ini akan\n"
	.string "menjadi obat yang luar biasa.$"

SlateportCity_Text_DontHaveEnoughBerryPowder:
	.string "Apakah Kamu ingin menukar lebih\n"
	.string "banyak BUBUK BERI Kamu dengan\l"
	.string "sesuatu yang lain?$"

SlateportCity_Text_FineBerryPowderTradeSomethingElse:
	.string "Oke! Jika Kamu mendapatkan lebih\n"
	.string "banyak BUBUK BERI, bawakan kepada\l"
	.string "Aku, ya!\p"
	.string "Kembalilah jika Kamu ingin menukar\n"
	.string "BUBUK BERI Kamu dengan obat-obatan.$"

SlateportCity_Text_WhenYouGetMoreBringItToMe:
	.string "Aku selalu mengadakan bazar di\n"
	.string "sini.$"

SlateportCity_Text_ComeBackToTradeBerryPowder:
	.string "Apa Kamu tahu?\p"
	.string "SCOTT: Hah? Aku yakin Aku pernah\n"
	.string "bertemu Kamu di suatu tempat\l"
	.string "sebelumnya.\p"
	.string "Apa Aku sudah memperkenalkan diri\n"
	.string "kepada Kamu? Jika belum, nama Aku\l"
	.string "SCOTT.$"

SlateportCity_Text_YouDroveTeamAquaAway:
	.string "Aku baru saja melihat TIM AQUA lari\n"
	.string "dari sini seolah mereka tersengat.\p"
	.string "Coba Aku tebak-Kamu yang mengusir\n"
	.string "mereka?\p"
	.string "SCOTT: Hmm… Mungkin, mungkin saja,\n"
	.string "TRAINER ini…\p"
	.string "SCOTT: Baiklah! Aku pikir Kamu akan\n"
	.string "menjadi teman baik.$"

SlateportCity_Text_MaybeThisTrainer:
	.string "Jadi, mari kita daftarkan satu sama\n"
	.string "lain di POKéNAV kita.$"

SlateportCity_Text_LetsRegisterEachOther:
	.string "… … … … … …\p"
	.string "Mendaftarkan orang bernama SCOTT\n"
	.string "ini di POKéNAV.\p"
	.string "SCOTT: Yang ingin Aku lakukan\n"
	.string "adalah ikut bersama Kamu, tapi Aku\l"
	.string "juga ingin mengawasi bakat orang\l"
	.string "lain.$"

SlateportCity_Text_RegisteredScott:
	.string "Jadi, Aku akan berkelana ke\n"
	.string "kota-kota lain sedikit lagi.$"

SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou:
	.string "Sampai jumpa, {PLAYER}{KUN}!\p"
	.string "SCOTT: Oh, hei! Kalau bukan\n"
	.string "{PLAYER}{KUN}!\p"
	.string "{PLAYER}{KUN}, coba Aku tebak-Kamu\n"
	.string "akan mengikuti tantangan TENTARA\l"
	.string "PERTARUNGAN?$"

SlateportCity_Text_TakingBattleTentChallenge:
	.string "Ya! Itu ide yang bagus! Itu ide\n"
	.string "yang sangat hebat!\p"
	.string "Bagaimanapun, TRAINER yang tangguh\n"
	.string "sangat cocok untuk TENTARA\l"
	.string "PERTARUNGAN!\p"
	.string "Berikan upaya terbaik Kamu!$"
