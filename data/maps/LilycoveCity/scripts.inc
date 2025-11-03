LilycoveCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_OnLoad
	.byte 0

LilycoveCity_OnTransition:
	setflag FLAG_VISITED_LILYCOVE_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_REPORTER
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	call Common_EventScript_SetupRivalGfxId
	end

LilycoveCity_OnLoad:
	call_if_unset FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_SetWailmerMetatiles
	end

LilycoveCity_EventScript_SetWailmerMetatiles::
	setmetatile 76, 12, METATILE_Lilycove_Wailmer0, TRUE
	setmetatile 77, 12, METATILE_Lilycove_Wailmer1, TRUE
	setmetatile 76, 13, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 77, 13, METATILE_Lilycove_Wailmer3, TRUE
	setmetatile 76, 14, METATILE_Lilycove_Wailmer0_Alt, TRUE
	setmetatile 77, 14, METATILE_Lilycove_Wailmer1_Alt, TRUE
	setmetatile 76, 15, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 77, 15, METATILE_Lilycove_Wailmer3, TRUE
	setmetatile 77, 16, METATILE_Lilycove_Wailmer0_Alt, TRUE
	setmetatile 78, 16, METATILE_Lilycove_Wailmer1_Alt, TRUE
	setmetatile 77, 17, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 78, 17, METATILE_Lilycove_Wailmer3, TRUE
	return

LilycoveCity_EventScript_BerryGentleman::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_LILYCOVE_RECEIVED_BERRY, LilycoveCity_EventScript_ReceivedBerry
	msgbox LilycoveCity_Text_BerrySuitsYou, MSGBOX_DEFAULT
	random 10
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_LILYCOVE_RECEIVED_BERRY
	msgbox LilycoveCity_Text_BecauseYoureTrainer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ReceivedBerry::
	msgbox LilycoveCity_Text_PokeblocksSuitPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man3::
	msgbox LilycoveCity_Text_ContestHallInTown, MSGBOX_NPC
	end

LilycoveCity_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_GirlAquaGone
	msgbox LilycoveCity_Text_StrangeCaveInCove, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_GirlAquaGone::
	msgbox LilycoveCity_Text_GoingToMoveDeleterForHMs, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_RichBoy::
	msgbox LilycoveCity_Text_ImFromKanto, MSGBOX_NPC
	end

LilycoveCity_EventScript_Sailor2::
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Sailor2AquaGone
	msgbox LilycoveCity_Text_TeamAquaBeenTrainingWailmer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor2AquaGone::
	msgbox LilycoveCity_Text_SomeonePuntedTeamAquaOut, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2::
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Woman2AquaGone
	msgbox LilycoveCity_Text_SomeoneStoleMyPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2AquaGone::
	msgbox LilycoveCity_Text_MissingPokemonCameBack, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man2::
	msgbox LilycoveCity_Text_ImArtDealer, MSGBOX_NPC
	end

LilycoveCity_EventScript_ExpertM1::
	msgbox LilycoveCity_Text_SeaRemainsForeverYoung, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertF::
	msgbox LilycoveCity_Text_SixtyYearsAgoHusbandProposed, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertM2::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_ExpertM2AquaGone
	msgbox LilycoveCity_Text_TeamAquaRenovatedCavern, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ExpertM2AquaGone::
	msgbox LilycoveCity_Text_TeamAquaLotGoneForGood, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor1::
	msgbox LilycoveCity_Text_HeardTowerCalledSkyPillar, MSGBOX_NPC
	end

LilycoveCity_EventScript_FatMan::
	msgbox LilycoveCity_Text_SawTallTowerOnRoute131, MSGBOX_NPC
	end

LilycoveCity_EventScript_Man1::
	lockall
	msgbox LilycoveCity_Text_JustArrivedAndSawRarePokemon, MSGBOX_NPC
	applymovement LOCALID_LILYCOVE_MAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_Woman1::
	lockall
	msgbox LilycoveCity_Text_HoneymoonVowToSeeRarePokemon, MSGBOX_NPC
	applymovement LOCALID_LILYCOVE_WOMAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_CitySign::
	msgbox LilycoveCity_Text_CitySign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ContestHallSign::
	msgbox LilycoveCity_Text_ContestHallSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MotelSign::
	msgbox LilycoveCity_Text_MotelSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MuseumSign::
	lockall
	specialvar VAR_0x8004, CountPlayerMuseumPaintings
	switch VAR_0x8004
	case 0, LilycoveCity_EventScript_MuseumSignNoPaintings
	msgbox LilycoveCity_Text_MuseumSignPlayersExhibit, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_MuseumSignNoPaintings::
	msgbox LilycoveCity_Text_MuseumSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_HarborSignFerryReady
	msgbox LilycoveCity_Text_HarborSignUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSignFerryReady::
	msgbox LilycoveCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_TrainerFanClubSign::
	msgbox LilycoveCity_Text_TrainerFanClubSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_DepartmentStoreSign::
	msgbox LilycoveCity_Text_DepartmentStoreSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MoveDeletersHouseSign::
	msgbox LilycoveCity_Text_MoveDeletersHouseSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_WailmerTrainerGrunt::
	lockall
	goto_if_set FLAG_MET_WAILMER_TRAINER, LilycoveCity_EventScript_MetWailmerTrainer
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_Text_GetLostMessingUpTraining, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_MET_WAILMER_TRAINER
	releaseall
	end

LilycoveCity_EventScript_MetWailmerTrainer::
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_AquaGrunt1::
	msgbox LilycoveCity_Text_MovedLootIntoHideoutToday, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt2::
	msgbox LilycoveCity_Text_ChanceToDoBigThings, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt3::
	msgbox LilycoveCity_Text_DontGoNearCaveInCove, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt4::
	msgbox LilycoveCity_Text_IfWorldBecomesOurs, MSGBOX_NPC
	end

LilycoveCity_EventScript_Rival::
	lock
	faceplayer
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LilycoveCity_EventScript_May
	goto_if_eq VAR_RESULT, FEMALE, LilycoveCity_EventScript_Brendan
	end

LilycoveCity_EventScript_May::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattle
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineMayBattle
	msgbox LilycoveCity_Text_MayWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleMayTreecko
	case 1, LilycoveCity_EventScript_BattleMayTorchic
	case 2, LilycoveCity_EventScript_BattleMayMudkip
	end

LilycoveCity_EventScript_MayAskToBattleAgain::
	msgbox LilycoveCity_Text_MayBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_MayAskToBattle::
	msgbox LilycoveCity_Text_MayShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineMayBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_MayNotRaisingPokemon, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_Brendan::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattle
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineBrendanBattle
	msgbox LilycoveCity_Text_BrendanWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleBrendanTreecko
	case 1, LilycoveCity_EventScript_BattleBrendanTorchic
	case 2, LilycoveCity_EventScript_BattleBrendanMudkip
	end

LilycoveCity_EventScript_BrendanAskToBattleAgain::
	msgbox LilycoveCity_Text_BrendanBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_BrendanAskToBattle::
	msgbox LilycoveCity_Text_BrendanShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineBrendanBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_BrendanNoConfidence, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_BattleMayTreecko::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TREECKO, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayTorchic::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TORCHIC, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayMudkip::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_MUDKIP, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleBrendanTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TREECKO, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TORCHIC, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_MUDKIP, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_DefeatedMay::
	msgbox LilycoveCity_Text_MayGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_MayCollectBadges
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_MayPokemonLeague
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_PICHU_DOLL
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_CheckFinalBadge::
	goto_if_set FLAG_BADGE08_GET, LilycoveCity_EventScript_HasFinalBadge
	return

LilycoveCity_EventScript_HasFinalBadge::
	setvar VAR_RESULT, TRUE
	return

LilycoveCity_EventScript_MayCollectBadges::
	msgbox LilycoveCity_Text_MayYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayPokemonLeague::
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_MayBattleFrontier
	msgbox LilycoveCity_Text_MayYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayBattleFrontier::
	msgbox LilycoveCity_Text_MayYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DefeatedBrendan::
	msgbox LilycoveCity_Text_BrendanGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_BrendanCollectBadges
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_BrendanPokemonLeague
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_SWABLU_DOLL
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_BrendanCollectBadges::
	msgbox LilycoveCity_Text_BrendanYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanPokemonLeague::
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_BrendanBattleFrontier
	msgbox LilycoveCity_Text_BrendanYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanBattleFrontier::
	msgbox LilycoveCity_Text_BrendanYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_RivalFlyAway::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject VAR_LAST_TALKED
	waitfieldeffect FLDEFF_NPCFLY_OUT
	savebgm MUS_DUMMY
	fadedefaultbgm
	setflag FLAG_MET_RIVAL_LILYCOVE
	release
	end

LilycoveCity_EventScript_SchoolKidM::
	lock
	faceplayer
	msgbox LilycoveCity_Text_DoYouKnowAboutBerryBlender, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, LilycoveCity_EventScript_KnowAboutBerryBlender
	call_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DontKnowAboutBerryBlender
	release
	end

LilycoveCity_EventScript_KnowAboutBerryBlender::
	msgbox LilycoveCity_Text_FasterSpinBetterPokeblocks, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DontKnowAboutBerryBlender::
	msgbox LilycoveCity_Text_ExplainBerryBlender, MSGBOX_DEFAULT
	return

LilycoveCity_Text_MayShoppingLetsBattle:
	.string "MAY: Oh, hei? {PLAYER}{KUN}, kamu juga\n"
	.string "sedang berbelanja?\p"
	.string "Aku membeli banyak sekali BONEKA dan\n"
	.string "POSTER.\p"
	.string "Tentu saja, aku juga sudah menangkap\n"
	.string "banyak POKéMON, dan aku\l"
	.string "membesarkannya dengan baik juga.\p"
	.string "Sebenarnya, aku lebih khawatir\n"
	.string "apakah kamu membesarkan POKéMON\l"
	.string "dengan benar, {PLAYER}{KUN}.\p"
	.string "Aku akan bertarung denganmu, jadi\n"
	.string "kamu bisa menunjukkan POKéMON-mu,\l"
	.string "{PLAYER}{KUN}.$"

LilycoveCity_Text_MayNotRaisingPokemon:
	.string "MAY: Oh, kenapa? {PLAYER}{KUN}, apa\n"
	.string "kamu tidak membesarkan POKéMON-mu?\p"
	.string "Itu bukan pertunjukan yang bagus\n"
	.string "sebagai seorang TRAINER…$"

LilycoveCity_Text_MayBattleMe:
	.string "MAY: Ayo, bertarunglah denganku,\n"
	.string "agar aku bisa melihat POKéMON-mu!$"

LilycoveCity_Text_MayWontBeBeaten:
	.string "MAY: POKéMON yang kubesarkan tidak\n"
	.string "akan terkalahkan oleh POKéMON-mu,\l"
	.string "{PLAYER}{KUN}!$"

LilycoveCity_Text_MayDefeat:
	.string "… … … … … … … …\p"
	.string "Aku ingat pertarunganku denganmu,\n"
	.string "{PLAYER}{KUN}, di ROUTE 103.\p"
	.string "Pertarungan itu membantumu menjadi\n"
	.string "sekuat ini, {PLAYER}{KUN}, kan?$"

LilycoveCity_Text_MayGoingBackToLittleroot:
	.string "MAY: Aku berpikir untuk segera\n"
	.string "kembali ke LITTLEROOT.\p"
	.string "Aku sudah menangkap cukup banyak\n"
	.string "POKéMON, dan POKéDEX-ku sudah\l"
	.string "lumayan terisi, jadi aku akan pulang\l"
	.string "untuk menunjukkannya pada ayahku.$"

LilycoveCity_Text_MayYouGoingToCollectBadges:
	.string "{PLAYER}{KUN}, apa yang akan kamu\n"
	.string "lakukan?\p"
	.string "Mengumpulkan semua LENCANA GYM dan\n"
	.string "menantang LIGA POKéMON?\p"
	.string "Yah, selagi kamu mengumpulkan\n"
	.string "LENCANA, {PLAYER}{KUN}, aku akan\l"
	.string "mengerjakan POKéDEX-ku. Aku akan\l"
	.string "menyelesaikannya sebelum kamu!\p"
	.string "Sampai jumpa!$"

LilycoveCity_Text_MayYouGoingToPokemonLeague:
	.string "{PLAYER}{KUN}, apa yang akan kamu\n"
	.string "lakukan?\p"
	.string "Apa kamu akan menantang LIGA\n"
	.string "POKéMON?\p"
	.string "Atau, apa kamu akan menyelesaikan\n"
	.string "POKéDEX-mu?\p"
	.string "Aku mungkin kalah bertarung darimu,\n"
	.string "tapi aku akan menyelesaikan POKéDEX\l"
	.string "-ku sebelum kamu!\p"
	.string "Sampai jumpa!$"

LilycoveCity_Text_MayYouGoingToBattleFrontier:
	.string "{PLAYER}{KUN}, apa yang akan kamu\n"
	.string "lakukan?\p"
	.string "Apa kamu akan menantang BATTLE\n"
	.string "FRONTIER?\p"
	.string "Atau, apa kamu akan menyelesaikan\n"
	.string "POKéDEX-mu?\p"
	.string "Aku mungkin kalah bertarung darimu,\n"
	.string "tapi aku akan menyelesaikan POKéDEX\l"
	.string "-ku sebelum kamu!\p"
	.string "Sampai jumpa!$"

LilycoveCity_Text_BrendanShoppingLetsBattle:
	.string "BRENDAN: Oh, hei, ini {PLAYER}.\p"
	.string "Aku sedang menjalankan tugas dari\n"
	.string "ayahku. Tidak, aku tidak membeli\l"
	.string "BONEKA.\p"
	.string "Ngomong-ngomong, sudah lama ya.\p"
	.string "Mau bertarung untuk melihat siapa\n"
	.string "yang membesarkan POKéMON lebih baik?$"

LilycoveCity_Text_BrendanNoConfidence:
	.string "BRENDAN: Oh, ada apa?\n"
	.string "Tidak percaya diri?$"

LilycoveCity_Text_BrendanBattleMe:
	.string "BRENDAN: Mau bertarung untuk melihat\n"
	.string "siapa yang membesarkan POKéMON\l"
	.string "lebih baik?$"

LilycoveCity_Text_BrendanWontBeBeaten:
	.string "BRENDAN: Aww, tapi kamu tahu aku\n"
	.string "tidak akan kalah dari {PLAYER}.$"

LilycoveCity_Text_BrendanDefeat:
	.string "Huh…\n"
	.string "Kamu sudah banyak berlatih.\p"
	.string "Agak menyakitkan--aku memulainya\n"
	.string "lebih dulu darimu sebagai TRAINER…$"

LilycoveCity_Text_BrendanGoingBackToLittleroot:
	.string "BRENDAN: Aku…\n"
	.string "Aku berencana pulang ke LITTLEROOT.\p"
	.string "Kamu tahu aku membantu ayahku dengan\n"
	.string "POKéDEX-nya. Sudah cukup terisi,\l"
	.string "jadi aku harus menunjukkannya\l"
	.string "padanya.$"

LilycoveCity_Text_BrendanYouGoingToCollectBadges:
	.string "{PLAYER}, apa yang akan kamu lakukan?\p"
	.string "Mengumpulkan semua LENCANA GYM dan\n"
	.string "menantang LIGA POKéMON?\p"
	.string "Mungkin aku akan melakukannya juga…\p"
	.string "Yah, bagaimanapun, semangat!$"

LilycoveCity_Text_BrendanYouGoingToPokemonLeague:
	.string "{PLAYER}, apa yang akan kamu lakukan?\p"
	.string "Karena kamu sekuat itu, apa kamu\n"
	.string "akan menantang LIGA POKéMON?\p"
	.string "Heh, bahkan aku--jika aku melatih\n"
	.string "POKéMON-ku sedikit lagi, aku\l"
	.string "seharusnya lebih kuat darimu, {PLAYER}.\p"
	.string "Yah, bagaimanapun, semangat!$"

LilycoveCity_Text_BrendanYouGoingToBattleFrontier:
	.string "{PLAYER}, apa yang akan kamu lakukan?\p"
	.string "Apa kamu akan menantang BATTLE\n"
	.string "FRONTIER?\p"
	.string "Atau, apa kamu akan menyelesaikan\n"
	.string "POKéDEX-mu?\p"
	.string "Karena kamu sekuat itu, kamu harus\n"
	.string "mempertimbangkan BATTLE FRONTIER.\p"
	.string "Heh, jika aku melatih POKéMON-ku\n"
	.string "sedikit lagi, aku akan lebih kuat\l"
	.string "darimu, {PLAYER}.\p"
	.string "Mungkin aku harus pergi ke BATTLE\n"
	.string "FRONTIER.\p"
	.string "Yah, bagaimanapun, semangat!$"

LilycoveCity_Text_MovedLootIntoHideoutToday:
	.string "Fufufu…\p"
	.string "Kami memindahkan lebih banyak barang\n"
	.string "curian ke MARKAS rahasia kami hari\l"
	.string "ini…\p"
	.string "Si-siapa kamu?!\n"
	.string "Aku hanya bicara sendiri!$"

LilycoveCity_Text_ChanceToDoBigThings:
	.string "Aku hanya seorang BAWAHAN, jadi aku\n"
	.string "tidak tahu apa yang dipikirkan BOS…\p"
	.string "Tapi dengan berada di TIM AQUA, aku\n"
	.string "tahu aku akan mendapat kesempatan\l"
	.string "untuk melakukan hal-hal besar!\p"
	.string "Si-siapa kamu?!\n"
	.string "Aku hanya bicara sendiri!$"

LilycoveCity_Text_DontGoNearCaveInCove:
	.string "Hei, kamu!\p"
	.string "Jangan dekati gua di teluk itu!\p"
	.string "Kenapa? Kamu tidak butuh alasan!\n"
	.string "Aku orang dewasa, jadi dengarkan\l"
	.string "saja aku!$"

LilycoveCity_Text_IfWorldBecomesOurs:
	.string "Jika seluruh dunia ini menjadi milik\n"
	.string "kami, TIM AQUA, ini akan menjadi\l"
	.string "tempat yang lebih bahagia bagi\l"
	.string "POKéMON juga.$"

LilycoveCity_Text_WailmerLeapOutOfWater:
	.string "Itu dia! WAILMER!\n"
	.string "Lompat keluar dari air sekarang!$"

LilycoveCity_Text_GetLostMessingUpTraining:
	.string "Hah? Apa maumu?\p"
	.string "Kamu mengganggu latihan kami, jadi\n"
	.string "bisakah kamu, pergi?$"
	
LilycoveCity_Text_ContestHallInTown:
	.string "Ada POKéMON CONTEST HALL di kota\n"
	.string "ini. \p"
	.string "Itu berarti POKéMON yang dibesarkan\n"
	.string "dengan baik akan datang dari seluruh\l"
	.string "negeri.\p"
	.string "Hatiku jadi berdebar-debar!$"

LilycoveCity_Text_StrangeCaveInCove:
	.string "Pernahkah kamu melihat gua aneh di\n"
	.string "teluk di ujung kota?$"

LilycoveCity_Text_GoingToMoveDeleterForHMs:
	.string "Aku akan mengajari POKéMON-ku\n"
	.string "beberapa jurus baru untuk mengikuti\l"
	.string "CONTEST.\p"
	.string "Jadi, aku akan menemui MOVE DELETER\n"
	.string "dan membuatnya melupakan jurus HM.$"

LilycoveCity_Text_ImFromKanto:
	.string "Aku datang dari KANTO.\p"
	.string "Wilayah HOENN indah dengan semua air\n"
	.string "dan alamnya yang hijau.\p"
	.string "Hah? Tunggu sebentar…\p"
	.string "Mungkinkah ada POKéMON langka yang\n"
	.string "hanya hidup di area ini?$"

LilycoveCity_Text_TeamAquaBeenTrainingWailmer:
	.string "TIM AQUA telah melatih WAILMER\n"
	.string "mereka di teluk.\p"
	.string "Kami para PELAUT tidak bisa membawa\n"
	.string "perahu kami ke laut karena mereka\l"
	.string "menghalangi!$"

LilycoveCity_Text_SomeonePuntedTeamAquaOut:
	.string "Ahoy, apa kamu tahu?\p"
	.string "Seseorang telah menyingkirkan TIM\n"
	.string "AQUA untuk kita!\p"
	.string "Itu membuat WAILMER keluar dari\n"
	.string "teluk, jadi kami bisa mengeluarkan\l"
	.string "perahu kami lagi.$"

LilycoveCity_Text_SomeoneStoleMyPokemon:
	.string "Aku sedang tidur santai di penginapan\n"
	.string "tepi laut dengan suara ombak…\p"
	.string "Saat seseorang mencuri POKéMON-ku!\p"
	.string "Siapa penculiknya?\n"
	.string "TIM AQUA? Apa itu TIM AQUA?$"

LilycoveCity_Text_MissingPokemonCameBack:
	.string "POKéMON-ku yang hilang…\n"
	.string "Ia kembali tanpa kusadari!$"

LilycoveCity_Text_ImArtDealer:
	.string "Aku seorang PENJUAL KARYA SENI.\p"
	.string "Aku adalah pembeli dan penjual seni\n"
	.string "rupa, terutama lukisan.\p"
	.string "Kudengar MUSEUM di sini memiliki\n"
	.string "karya-karya luar biasa yang\l"
	.string "dipamerkan…$"

LilycoveCity_Text_SeaRemainsForeverYoung:
	.string "Bahkan saat kita menjadi tua dan\n"
	.string "keriput, laut tetap awet muda dengan\l"
	.string "kecemerlangan hidup yang nyata…\p"
	.string "Fwohoho fwohohohoho…$"

LilycoveCity_Text_SixtyYearsAgoHusbandProposed:
	.string "Enam puluh tahun yang lalu suamiku\n"
	.string "melamarku di sini.\l"
	.string "Lautnya tetap seindah dulu.\p"
	.string "Mufufufu mufufufufufu…$"

LilycoveCity_Text_TeamAquaRenovatedCavern:
	.string "Hm, kamu tahu tentang gua aneh di\n"
	.string "teluk ini?\p"
	.string "Itu tadinya formasi alami, tapi\n"
	.string "kemudian gerombolan TIM AQUA itu\l"
	.string "datang dan melakukan renovasi.\p"
	.string "Mereka menyebut diri mereka\n"
	.string "“TIM AQUA pecinta alam”!\p"
	.string "Tapi apa yang mereka lakukan dan\n"
	.string "katakan sama sekali tidak cocok!$"

LilycoveCity_Text_TeamAquaLotGoneForGood:
	.string "Gua di teluk itu…\p"
	.string "Aku tidak langsung menyadarinya,\n"
	.string "tapi sekarang benar-benar kosong.\p"
	.string "Gerombolan TIM AQUA itu, mereka\n"
	.string "pasti sudah pergi untuk selamanya.$"

LilycoveCity_Text_CitySign:
	.string "KOTA LILYCOVE\p"
	.string "“Di mana daratan berakhir dan\n"
	.string "lautan dimulai.”$"

LilycoveCity_Text_ContestHallSign:
	.string "POKéMON CONTEST HALL\n"
	.string "“Tempat berkumpulnya para TRAINER!”$"

LilycoveCity_Text_MotelSign:
	.string "MOTEL COVE LILY\p"
	.string "“Ingat kami sebagai COVE LILY dari\n"
	.string "LILYCOVE.”$"

LilycoveCity_Text_MuseumSign:
	.string "MUSEUM LILYCOVE\p"
	.string "“Pameran Koleksi Mahakarya\n"
	.string "POKéMON!”$"

LilycoveCity_Text_MuseumSignPlayersExhibit:
	.string "MUSEUM LILYCOVE\p"
	.string "“Pameran Koleksi POKéMON {PLAYER}!”$"

LilycoveCity_Text_HarborSignUnderConstruction:
	.string "PELABUHAN KOTA LILYCOVE\p"
	.string "“Kapal feri S.S. TIDAL sedang dalam\n"
	.string "pembangunan di KOTA SLATEPORT.\p"
	.string "“Layanan dijadwalkan akan segera\n"
	.string "dimulai.”$"

LilycoveCity_Text_HarborSign:
	.string "PELABUHAN KOTA LILYCOVE\p"
	.string "“Nikmati pelayaran menyenangkan\n"
	.string "dengan feri S.S. TIDAL.”$"

LilycoveCity_Text_TrainerFanClubSign:
	.string "KLUB PENGGEMAR TRAINER POKéMON\p"
	.string "Nama-nama TRAINER dicoret-coret di\n"
	.string "seluruh papan nama…$"

LilycoveCity_Text_DepartmentStoreSign:
	.string "TOKO SERBA ADA LILYCOVE\p"
	.string "“Penuh dengan barang dagangan hebat\n"
	.string "dan kegembiraan!\p"
	.string "“Tempat yang bagus untuk menemukan\n"
	.string "sesuatu yang kamu butuhkan!”$"

LilycoveCity_Text_MoveDeletersHouseSign:
	.string "RUMAH MOVE DELETER\p"
	.string "“Jurus POKéMON yang tidak diinginkan\n"
	.string "dihapus.”$"

LilycoveCity_Text_DoYouKnowAboutBerryBlender:
	.string "Apa kamu tahu tentang mesin\n"
	.string "BERRY BLENDER?$"

LilycoveCity_Text_FasterSpinBetterPokeblocks:
	.string "Orang-orang harus bekerja sama untuk\n"
	.string "membuatnya berputar lebih cepat.\p"
	.string "Semakin cepat kamu membuatnya\n"
	.string "berputar, semakin baik {POKEBLOCK}S\l"
	.string "yang bisa kamu dapatkan, kudengar.$"

LilycoveCity_Text_ExplainBerryBlender:
	.string "Ini digunakan untuk membuat sejenis\n"
	.string "permen yang disebut {POKEBLOCK}.\p"
	.string "Jika kamu memberikan {POKEBLOCK} yang\n"
	.string "bagus ke POKéMON, kondisinya akan\l"
	.string "meningkat pesat.$"

LilycoveCity_Text_HeardTowerCalledSkyPillar:
	.string "Kudengar ada menara di suatu tempat\n"
	.string "di jalur laut.\p"
	.string "Namanya SKY PILLAR, kudengar.$"

LilycoveCity_Text_SawTallTowerOnRoute131:
	.string "Aku melihat menara tinggi ini di\n"
	.string "suatu tempat di sekitar ROUTE 131.\p"
	.string "Mungkinkah itu…?$"

LilycoveCity_Text_JustArrivedAndSawRarePokemon:
	.string "Kami baru saja tiba di sini untuk\n"
	.string "liburan bulan madu kami.\p"
	.string "Kami kebetulan melihat POKéMON tipe\n"
	.string "NAGA terbang tinggi di langit.\p"
	.string "Apa POKéMON keren seperti itu hidup\n"
	.string "di wilayah HOENN?$"

LilycoveCity_Text_HoneymoonVowToSeeRarePokemon:
	.string "Saat bulan madu, kami bersumpah\n"
	.string "untuk melihat POKéMON langka\l"
	.string "sebanyak mungkin.\p"
	.string "Jadi kami senang melihat POKéMON\n"
	.string "langka begitu kami tiba.\p"
	.string "Maksudku, kami benar-benar bahagia!$"
