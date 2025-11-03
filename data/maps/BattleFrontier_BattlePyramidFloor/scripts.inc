BattleFrontier_BattlePyramidFloor_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePyramidFloor_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidFloor_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePyramidFloor_OnTransition
	.byte 0

BattleFrontier_BattlePyramidFloor_OnFrame:
	map_script_2 VAR_TEMP_D, 1, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight
	map_script_2 VAR_TEMP_PLAYING_PYRAMID_MUSIC, 0, BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic
	map_script_2 VAR_TEMP_F, 1, BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName
	.2byte 0

BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight::
	lockall
	@ pyramid_updatelight, cant use macro because it straddles the loop
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_UPDATE_LIGHT
	setvar VAR_0x8005, 4
	setvar VAR_0x8006, PYRAMID_LIGHT_INCR_RADIUS
	setvar VAR_0x8007, SE_SAVE
	setvar VAR_RESULT, 0
BattleFrontier_BattlePyramidFloor_EventScript_UpdateLightLoop::
	special CallBattlePyramidFunction
	delay 2
	goto_if_ne VAR_RESULT, 2, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLightLoop
	setvar VAR_TEMP_D, 0
	releaseall
	end

BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName::
	special ShowMapNamePopup
	setvar VAR_TEMP_F, 0
	end

BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic::
	playbgm MUS_B_PYRAMID, FALSE
	setvar VAR_TEMP_PLAYING_PYRAMID_MUSIC, 1
	end

BattleFrontier_BattlePyramidFloor_OnResume:
	pyramid_setfloorpal
	frontier_getstatus
	switch VAR_TEMP_CHALLENGE_STATUS
	case 0, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge
	case CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramid_EventScript_WarpToLobby
	case CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_DREW, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_FORFEITED, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	frontier_isbattletype BATTLE_TYPE_TRAINER  @ VAR_RESULT seems to be ignored here
	setvar VAR_TEMP_D, 1
BattleFrontier_BattlePyramidFloor_EventScript_ResetParty::
	pyramid_resetparty
	end

BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
	pyramid_set PYRAMID_DATA_TRAINER_FLAGS, 255
BattleFrontier_BattlePyramid_EventScript_WarpToLobby::
	pyramid_updatelight 0, PYRAMID_LIGHT_SET_RADIUS
	pyramid_clearhelditems
	special HealPlayerParty
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_LOBBY, 7, 13
	waitstate
	end

BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge::
	pyramid_save CHALLENGE_STATUS_SAVING
	special SavePlayerParty
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	pyramid_settrainers
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_OnTransition:
	call BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius::
	pyramid_updatelight 32, PYRAMID_LIGHT_SET_RADIUS
	return

BattlePyramid_WarpToNextFloor::
	call BattleFrontier_EventScript_IncrementWinStreak
	frontier_get FRONTIER_DATA_BATTLE_NUM  @ Floor number
	addvar VAR_RESULT, 1
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
	goto_if_eq VAR_RESULT, 7, BattlePyramid_WarpToTop
	pyramid_seedfloor
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_RESULT, 0
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR, 1, 1
	waitstate
	end

BattlePyramid_WarpToTop::
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_TOP, 17, 17
	waitstate
	end

@ TRAINER_PHILLIP is used as a placeholder
BattlePyramid_TrainerBattle::
	trainerbattle TRAINER_BATTLE_HILL, LOCALID_NONE, TRAINER_PHILLIP, BattleFacility_TrainerBattle_PlaceholderText, BattleFacility_TrainerBattle_PlaceholderText, NULL, LOCALID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, FALSE, FALSE, FALSE
	pyramid_showhint
	waitmessage
	waitbuttonpress
	closemessage
	releaseall
	end

BattlePyramid_FindItemBall::
	pyramid_setitem
	callstd STD_FIND_ITEM
	goto_if_eq VAR_0x8007, 0, BattlePyramid_FindItemBallEnd
	pyramid_hideitem
BattlePyramid_FindItemBallEnd::
	end

BattlePyramid_Retire::
	goto BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost

@ Also used by Trainer Hill
BattleFacility_TrainerBattle_PlaceholderText:
	.string "Ini adalah pesan contoh.$"

gText_BattlePyramidConfirmRest::
	.string "Misi BATTLE PYRAMID-mu akan disimpan\n"
	.string "agar kamu bisa berhenti untuk saat ini.\l"
	.string "Boleh?$"

gText_BattlePyramidConfirmRetire::
	.string "Apa kamu yakin ingin berhenti dari\n"
	.string "misi PYRAMID-mu?$"

BattlePyramid_Text_ExitHintUp1::
	.string "Pintu keluar lantai ini ada di\n"
	.string "arah sana: {UP_ARROW}$"

BattlePyramid_Text_ExitHintLeft1::
	.string "Pintu keluar lantai ini ada di\n"
	.string "arah sana: {LEFT_ARROW}$"

BattlePyramid_Text_ExitHintRight1::
	.string "Pintu keluar lantai ini ada di\n"
	.string "arah sana: {RIGHT_ARROW}$"

BattlePyramid_Text_ExitHintDown1::
	.string "Pintu keluar lantai ini ada di\n"
	.string "arah sana: {DOWN_ARROW}$"

BattlePyramid_Text_ExitHintUp2::
	.string "Pintu keluar di lantai ini ada\n"
	.string "di arah {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft2::
	.string "Pintu keluar di lantai ini ada\n"
	.string "di arah {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight2::
	.string "Pintu keluar di lantai ini ada\n"
	.string "di arah {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown2::
	.string "Pintu keluar di lantai ini ada\n"
	.string "di arah {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp3::
	.string "Pintu keluarnya ada\n"
	.string "di arah {UP_ARROW} sana.$"

BattlePyramid_Text_ExitHintLeft3::
	.string "Pintu keluarnya ada\n"
	.string "di arah {LEFT_ARROW} sana.$"

BattlePyramid_Text_ExitHintRight3::
	.string "Pintu keluarnya ada\n"
	.string "di arah {RIGHT_ARROW} sana.$"

BattlePyramid_Text_ExitHintDown3::
	.string "Pintu keluarnya ada\n"
	.string "di arah {DOWN_ARROW} sana.$"

BattlePyramid_Text_ExitHintUp4::
	.string "Di lantai ini, pintu keluarnya ada\n"
	.string "di suatu tempat di arah {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft4::
	.string "Di lantai ini, pintu keluarnya ada\n"
	.string "di suatu tempat di arah {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight4::
	.string "Di lantai ini, pintu keluarnya ada\n"
	.string "di suatu tempat di arah {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown4::
	.string "Di lantai ini, pintu keluarnya ada\n"
	.string "di suatu tempat di arah {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp5::
	.string "Pintu keluar?\n"
	.string "Ada di arah {UP_ARROW} sana.$"

BattlePyramid_Text_ExitHintLeft5::
	.string "Pintu keluar?\n"
	.string "Ada di arah {LEFT_ARROW} sana.$"

BattlePyramid_Text_ExitHintRight5::
	.string "Pintu keluar?\n"
	.string "Ada di arah {RIGHT_ARROW} sana.$"

BattlePyramid_Text_ExitHintDown5::
	.string "Pintu keluar?\n"
	.string "Ada di arah {DOWN_ARROW} sana.$"

BattlePyramid_Text_ExitHintUp6::
	.string "Pintu keluarnya kebetulan ada\n"
	.string "di arah {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft6::
	.string "Pintu keluarnya kebetulan ada\n"
	.string "di arah {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight6::
	.string "Pintu keluarnya kebetulan ada\n"
	.string "di arah {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown6::
	.string "Pintu keluarnya kebetulan ada\n"
	.string "di arah {DOWN_ARROW}.$"

BattlePyramid_Text_EightItemsRemaining1::
	.string "Apa kamu mencari item?\p"
	.string "Masih ada delapan item yang tersisa\n"
	.string "untuk ditemukan.$"

BattlePyramid_Text_SevenItemsRemaining1::
	.string "Apa kamu mencari item?\p"
	.string "Masih ada tujuh item yang tersisa\n"
	.string "untuk ditemukan.$"

BattlePyramid_Text_SixItemsRemaining1::
	.string "Apa kamu mencari item?\p"
	.string "Masih ada enam item yang tersisa\n"
	.string "untuk ditemukan.$"

BattlePyramid_Text_FiveItemsRemaining1::
	.string "Apa kamu mencari item?\p"
	.string "Masih ada lima item yang tersisa\n"
	.string "untuk ditemukan.$"

BattlePyramid_Text_FourItemsRemaining1::
	.string "Apa kamu mencari item?\p"
	.string "Masih ada empat item yang tersisa\n"
	.string "untuk ditemukan.$"

BattlePyramid_Text_ThreeItemsRemaining1::
	.string "Apa kamu mencari item?\p"
	.string "Masih ada tiga item yang tersisa\n"
	.string "untuk ditemukan.$"

BattlePyramid_Text_TwoItemsRemaining1::
	.string "Apa kamu mencari item?\p"
	.string "Masih ada dua item yang tersisa\n"
	.string "untuk ditemukan.$"

BattlePyramid_Text_OneItemRemaining1::
	.string "Apa kamu mencari item?\p"
	.string "Masih ada satu item yang tersisa\n"
	.string "untuk ditemukan.$"

BattlePyramid_Text_ZeroItemsRemaining1::
	.string "Apa kamu mencari item?\p"
	.string "Tidak ada lagi yang tersisa\n"
	.string "untuk ditemukan!$"

BattlePyramid_Text_EightItemsRemaining2::
	.string "Karena kamu menang, akan kuberitahu\n"
	.string "rahasia kecil!\p"
	.string "Ada delapan item yang tersisa\n"
	.string "di sekitar sini.$"

BattlePyramid_Text_SevenItemsRemaining2::
	.string "Karena kamu menang, akan kuberitahu\n"
	.string "rahasia kecil!\p"
	.string "Ada tujuh item yang tersisa\n"
	.string "di sekitar sini.$"

BattlePyramid_Text_SixItemsRemaining2::
	.string "Karena kamu menang, akan kuberitahu\n"
	.string "rahasia kecil!\p"
	.string "Ada enam item yang tersisa\n"
	.string "di sekitar sini.$"

BattlePyramid_Text_FiveItemsRemaining2::
	.string "Karena kamu menang, akan kuberitahu\n"
	.string "rahasia kecil!\p"
	.string "Ada lima item yang tersisa\n"
	.string "di sekitar sini.$"

BattlePyramid_Text_FourItemsRemaining2::
	.string "Karena kamu menang, akan kuberitahu\n"
	.string "rahasia kecil!\p"
	.string "Ada empat item yang tersisa\n"
	.string "di sekitar sini.$"

BattlePyramid_Text_ThreeItemsRemaining2::
	.string "Karena kamu menang, akan kuberitahu\n"
	.string "rahasia kecil!\p"
	.string "Ada tiga item yang tersisa\n"
	.string "di sekitar sini.$"

BattlePyramid_Text_TwoItemsRemaining2::
	.string "Karena kamu menang, akan kuberitahu\n"
	.string "rahasia kecil!\p"
	.string "Ada dua item yang tersisa\n"
	.string "di sekitar sini.$"

BattlePyramid_Text_OneItemRemaining2::
	.string "Karena kamu menang, akan kuberitahu\n"
	.string "rahasia kecil!\p"
	.string "Ada satu item yang tersisa\n"
	.string "di sekitar sini.$"

BattlePyramid_Text_ZeroItemsRemaining2::
	.string "Karena kamu menang, akan kuberitahu\n"
	.string "rahasia kecil!\p"
	.string "Tidak ada lagi yang tersisa\n"
	.string "di sekitar sini.$"

BattlePyramid_Text_EightItemsRemaining3::
	.string "Bagaimana persediaan item-mu?\p"
	.string "Kukira masih ada delapan item yang\n"
	.string "menunggu untuk ditemukan di lantai ini.$"

BattlePyramid_Text_SevenItemsRemaining3::
	.string "Bagaimana persediaan item-mu?\p"
	.string "Kukira masih ada tujuh item yang\n"
	.string "menunggu untuk ditemukan di lantai ini.$"

BattlePyramid_Text_SixItemsRemaining3::
	.string "Bagaimana persediaan item-mu?\p"
	.string "Kukira masih ada enam item yang\n"
	.string "menunggu untuk ditemukan di lantai ini.$"

BattlePyramid_Text_FiveItemsRemaining3::
	.string "Bagaimana persediaan item-mu?\p"
	.string "Kukira masih ada lima item yang\n"
	.string "menunggu untuk ditemukan di lantai ini.$"

BattlePyramid_Text_FourItemsRemaining3::
	.string "Bagaimana persediaan item-mu?\p"
	.string "Kukira masih ada empat item yang\n"
	.string "menunggu untuk ditemukan di lantai ini.$"

BattlePyramid_Text_ThreeItemsRemaining3::
	.string "Bagaimana persediaan item-mu?\p"
	.string "Kukira masih ada tiga item yang\n"
	.string "menunggu untuk ditemukan di lantai ini.$"

BattlePyramid_Text_TwoItemsRemaining3::
	.string "Bagaimana persediaan item-mu?\p"
	.string "Kukira masih ada dua item yang\n"
	.string "menunggu untuk ditemukan di lantai ini.$"

BattlePyramid_Text_OneItemRemaining3::
	.string "Bagaimana persediaan item-mu?\p"
	.string "Kukira hanya ada satu item lagi yang\n"
	.string "menunggu untuk ditemukan di lantai ini.$"

BattlePyramid_Text_ZeroItemsRemaining3::
	.string "Bagaimana persediaan item-mu?\p"
	.string "Kukira tidak ada lagi item yang\n"
	.string "menunggu untuk ditemukan di lantai ini.\l"
	.string "Hati-hati, ya!$"

BattlePyramid_Text_EightItemsRemaining4::
	.string "Kamu kuat, jadi kamu dapat petunjuk!\p"
	.string "Sepertinya ada delapan item lagi\n"
	.string "di lantai.$"

BattlePyramid_Text_SevenItemsRemaining4::
	.string "Kamu kuat, jadi kamu dapat petunjuk!\p"
	.string "Sepertinya ada tujuh item lagi\n"
	.string "di lantai.$"

BattlePyramid_Text_SixItemsRemaining4::
	.string "Kamu kuat, jadi kamu dapat petunjuk!\p"
	.string "Sepertinya ada enam item lagi\n"
	.string "di lantai.$"

BattlePyramid_Text_FiveItemsRemaining4::
	.string "Kamu kuat, jadi kamu dapat petunjuk!\p"
	.string "Sepertinya ada lima item lagi\n"
	.string "di lantai.$"

BattlePyramid_Text_FourItemsRemaining4::
	.string "Kamu kuat, jadi kamu dapat petunjuk!\p"
	.string "Sepertinya ada empat item lagi\n"
	.string "di lantai.$"

BattlePyramid_Text_ThreeItemsRemaining4::
	.string "Kamu kuat, jadi kamu dapat petunjuk!\p"
	.string "Sepertinya ada tiga item lagi\n"
	.string "di lantai.$"

BattlePyramid_Text_TwoItemsRemaining4::
	.string "Kamu kuat, jadi kamu dapat petunjuk!\p"
	.string "Sepertinya ada dua item lagi\n"
	.string "di lantai.$"

BattlePyramid_Text_OneItemRemaining4::
	.string "Kamu kuat, jadi kamu dapat petunjuk!\p"
	.string "Sepertinya hanya ada satu item lagi\n"
	.string "di lantai.$"

BattlePyramid_Text_ZeroItemsRemaining4::
	.string "Kamu kuat, jadi kamu dapat petunjuk!\p"
	.string "Sepertinya tidak ada lagi item\n"
	.string "di lantai.$"

BattlePyramid_Text_EightItemsRemaining5::
	.string "Di lantai PYRAMID ini,\n"
	.string "kudengar ada delapan item…$"

BattlePyramid_Text_SevenItemsRemaining5::
	.string "Di lantai PYRAMID ini,\n"
	.string "kudengar ada tujuh item…$"

BattlePyramid_Text_SixItemsRemaining5::
	.string "Di lantai PYRAMID ini,\n"
	.string "kudengar ada enam item…$"

BattlePyramid_Text_FiveItemsRemaining5::
	.string "Di lantai PYRAMID ini,\n"
	.string "kudengar ada lima item…$"

BattlePyramid_Text_FourItemsRemaining5::
	.string "Di lantai PYRAMID ini,\n"
	.string "kudengar ada empat item…$"

BattlePyramid_Text_ThreeItemsRemaining5::
	.string "Di lantai PYRAMID ini,\n"
	.string "kudengar ada tiga item…$"

BattlePyramid_Text_TwoItemsRemaining5::
	.string "Di lantai PYRAMID ini,\n"
	.string "kudengar ada dua item…$"

BattlePyramid_Text_OneItemRemaining5::
	.string "Di lantai PYRAMID ini,\n"
	.string "kudengar ada satu item…$"

BattlePyramid_Text_ZeroItemsRemaining5::
	.string "Di lantai PYRAMID ini,\n"
	.string "kudengar tidak ada item…$"

BattlePyramid_Text_EightItemsRemaining6::
	.string "Apa kamu sudah mengumpulkan item?\p"
	.string "Kuyakin masih ada delapan item lagi\n"
	.string "di lantai ini.$"

BattlePyramid_Text_SevenItemsRemaining6::
	.string "Apa kamu sudah mengumpulkan item?\p"
	.string "Kuyakin masih ada tujuh item lagi\n"
	.string "di lantai ini.$"

BattlePyramid_Text_SixItemsRemaining6::
	.string "Apa kamu sudah mengumpulkan item?\p"
	.string "Kuyakin masih ada enam item lagi\n"
	.string "di lantai ini.$"

BattlePyramid_Text_FiveItemsRemaining6::
	.string "Apa kamu sudah mengumpulkan item?\p"
	.string "Kuyakin masih ada lima item lagi\n"
	.string "di lantai ini.$"

BattlePyramid_Text_FourItemsRemaining6::
	.string "Apa kamu sudah mengumpulkan item?\p"
	.string "Kuyakin masih ada empat item lagi\n"
	.string "di lantai ini.$"

BattlePyramid_Text_ThreeItemsRemaining6::
	.string "Apa kamu sudah mengumpulkan item?\p"
	.string "Kuyakin masih ada tiga item lagi\n"
	.string "di lantai ini.$"

BattlePyramid_Text_TwoItemsRemaining6::
	.string "Apa kamu sudah mengumpulkan item?\p"
	.string "Kuyakin masih ada dua item lagi\n"
	.string "di lantai ini.$"

BattlePyramid_Text_OneItemRemaining6::
	.string "Apa kamu sudah mengumpulkan item?\p"
	.string "Kuyakin masih ada satu item lagi\n"
	.string "di lantai ini.$"

BattlePyramid_Text_ZeroItemsRemaining6::
	.string "Apa kamu sudah mengumpulkan item?\p"
	.string "Kuyakin tidak ada lagi item\n"
	.string "di lantai ini.$"

BattlePyramid_Text_SevenTrainersRemaining1::
	.string "Kamu benar-benar hebat!\p"
	.string "Tapi masih ada tujuh TRAINER tangguh\n"
	.string "selain aku!$"

BattlePyramid_Text_SixTrainersRemaining1::
	.string "Kamu benar-benar hebat!\p"
	.string "Tapi masih ada enam TRAINER tangguh\n"
	.string "selain aku!$"

BattlePyramid_Text_FiveTrainersRemaining1::
	.string "Kamu benar-benar hebat!\p"
	.string "Tapi masih ada lima TRAINER tangguh\n"
	.string "selain aku!$"

BattlePyramid_Text_FourTrainersRemaining1::
	.string "Kamu benar-benar hebat!\p"
	.string "Tapi masih ada empat TRAINER tangguh\n"
	.string "selain aku!$"

BattlePyramid_Text_ThreeTrainersRemaining1::
	.string "Kamu benar-benar hebat!\p"
	.string "Tapi masih ada tiga TRAINER tangguh\n"
	.string "selain aku!$"

BattlePyramid_Text_TwoTrainersRemaining1::
	.string "Kamu benar-benar hebat!\p"
	.string "Tapi masih ada dua TRAINER tangguh\n"
	.string "selain aku!$"

BattlePyramid_Text_OneTrainersRemaining1::
	.string "Kamu benar-benar hebat!\p"
	.string "Tapi masih ada satu TRAINER tangguh\n"
	.string "selain aku!$"

BattlePyramid_Text_ZeroTrainersRemaining1::
	.string "Kamu benar-benar hebat!\p"
	.string "Tak ada lagi yang bisa\n"
	.string "mengalahkanmu!$"

BattlePyramid_Text_SevenTrainersRemaining2::
	.string "Menyebalkan sekali!\p"
	.string "Tapi masih ada tujuh TRAINER tersisa!\n"
	.string "Seseorang akan mengalahkanmu!$"

BattlePyramid_Text_SixTrainersRemaining2::
	.string "Menyebalkan sekali!\p"
	.string "Tapi masih ada enam TRAINER tersisa!\n"
	.string "Seseorang akan mengalahkanmu!$"

BattlePyramid_Text_FiveTrainersRemaining2::
	.string "Menyebalkan sekali!\p"
	.string "Tapi masih ada lima TRAINER tersisa!\n"
	.string "Seseorang akan mengalahkanmu!$"

BattlePyramid_Text_FourTrainersRemaining2::
	.string "Menyebalkan sekali!\p"
	.string "Tapi masih ada empat TRAINER tersisa!\n"
	.string "Seseorang akan mengalahkanmu!$"

BattlePyramid_Text_ThreeTrainersRemaining2::
	.string "Menyebalkan sekali!\p"
	.string "Tapi masih ada tiga TRAINER tersisa!\n"
	.string "Seseorang akan mengalahkanmu!$"

BattlePyramid_Text_TwoTrainersRemaining2::
	.string "Menyebalkan sekali!\p"
	.string "Tapi masih ada dua TRAINER tersisa!\n"
	.string "Seseorang akan mengalahkanmu!$"

BattlePyramid_Text_OneTrainersRemaining2::
	.string "Menyebalkan sekali!\p"
	.string "Tapi masih ada satu TRAINER tersisa!\n"
	.string "Aku yakin kamu akan kalah!$"

BattlePyramid_Text_ZeroTrainersRemaining2::
	.string "Menyebalkan sekali!\p"
	.string "Tapi tidak ada lagi TRAINER\n"
	.string "yang bisa melawanmu!$"

BattlePyramid_Text_SevenTrainersRemaining3::
	.string "Cukup mengesankan!\p"
	.string "Tapi masih ada tujuh TRAINER lagi\n"
	.string "di lantai ini. Bisa kamu kalahkan semua?$"

BattlePyramid_Text_SixTrainersRemaining3::
	.string "Cukup mengesankan!\p"
	.string "Tapi masih ada enam TRAINER lagi\n"
	.string "di lantai ini. Bisa kamu kalahkan semua?$"

BattlePyramid_Text_FiveTrainersRemaining3::
	.string "Cukup mengesankan!\p"
	.string "Tapi masih ada lima TRAINER lagi\n"
	.string "di lantai ini. Bisa kamu kalahkan semua?$"


BattlePyramid_Text_FourTrainersRemaining3::
	.string "Cukup mengesankan!\p"
	.string "Tapi masih ada empat TRAINER lagi\n"
	.string "di lantai ini. Bisa kamu kalahkan semua?$"

BattlePyramid_Text_ThreeTrainersRemaining3::
	.string "Cukup mengesankan!\p"
	.string "Tapi masih ada tiga TRAINER lagi\n"
	.string "di lantai ini. Bisa kamu kalahkan semua?$"

BattlePyramid_Text_TwoTrainersRemaining3::
	.string "Cukup mengesankan!\p"
	.string "Tapi masih ada dua TRAINER lagi\n"
	.string "di lantai ini. Bisa kamu kalahkan keduanya?$"

BattlePyramid_Text_OneTrainersRemaining3::
	.string "Cukup mengesankan!\p"
	.string "Tapi masih ada satu TRAINER lagi\n"
	.string "di lantai ini. Bisakah kamu menang?$"

BattlePyramid_Text_ZeroTrainersRemaining3::
	.string "Cukup mengesankan!\p"
	.string "Kamu sudah mengalahkan semua TRAINER\n"
	.string "di lantai ini.$"

BattlePyramid_Text_SevenTrainersRemaining4::
	.string "Mungkin kamu bisa menyapu bersih\n"
	.string "tujuh TRAINER tersisa di lantai ini.$"

BattlePyramid_Text_SixTrainersRemaining4::
	.string "Mungkin kamu bisa menyapu bersih\n"
	.string "enam TRAINER tersisa di lantai ini.$"

BattlePyramid_Text_FiveTrainersRemaining4::
	.string "Mungkin kamu bisa menyapu bersih\n"
	.string "lima TRAINER tersisa di lantai ini.$"

BattlePyramid_Text_FourTrainersRemaining4::
	.string "Mungkin kamu bisa menyapu bersih\n"
	.string "empat TRAINER tersisa di lantai ini.$"

BattlePyramid_Text_ThreeTrainersRemaining4::
	.string "Mungkin kamu bisa menyapu bersih\n"
	.string "tiga TRAINER tersisa di lantai ini.$"

BattlePyramid_Text_TwoTrainersRemaining4::
	.string "Mungkin kamu bisa menyapu bersih\n"
	.string "dua TRAINER tersisa di lantai ini.$"

BattlePyramid_Text_OneTrainersRemaining4::
	.string "Mungkin kamu bisa menyelesaikan sapu bersih\n"
	.string "dengan satu TRAINER tersisa di lantai ini.$"

BattlePyramid_Text_ZeroTrainersRemaining4::
	.string "Tak ada satu orang pun yang tersisa\n"
	.string "yang bisa mengalahkanmu sekarang…$"

BattlePyramid_Text_SevenTrainersRemaining5::
	.string "Kamu mungkin punya kemampuan untuk mengalahkan\n"
	.string "tujuh TRAINER ahli yang tersisa.$"

BattlePyramid_Text_SixTrainersRemaining5::
	.string "Kamu mungkin punya kemampuan untuk mengalahkan\n"
	.string "enam TRAINER ahli yang tersisa.$"

BattlePyramid_Text_FiveTrainersRemaining5::
	.string "Kamu mungkin punya kemampuan untuk mengalahkan\n"
	.string "lima TRAINER ahli yang tersisa.$"

BattlePyramid_Text_FourTrainersRemaining5::
	.string "Kamu mungkin punya kemampuan untuk mengalahkan\n"
	.string "empat TRAINER ahli yang tersisa.$"

BattlePyramid_Text_ThreeTrainersRemaining5::
	.string "Kamu mungkin punya kemampuan untuk mengalahkan\n"
	.string "tiga TRAINER ahli yang tersisa.$"

BattlePyramid_Text_TwoTrainersRemaining5::
	.string "Kamu mungkin punya kemampuan untuk mengalahkan\n"
	.string "dua TRAINER ahli yang tersisa.$"

BattlePyramid_Text_OneTrainersRemaining5::
	.string "Kamu mungkin punya kemampuan untuk mengalahkan\n"
	.string "satu TRAINER ahli yang tersisa.$"

BattlePyramid_Text_ZeroTrainersRemaining5::
	.string "Keahlianmu tidak tercela.\p"
	.string "Tidak ada lagi TRAINER di sini\n"
	.string "yang punya kesempatan mengalahkanmu.$"

BattlePyramid_Text_SevenTrainersRemaining6::
	.string "Bisakah kamu terus menang melawan\n"
	.string "tujuh TRAINER yang tersisa?$"

BattlePyramid_Text_SixTrainersRemaining6::
	.string "Bisakah kamu terus menang melawan\n"
	.string "enam TRAINER yang tersisa?$"

BattlePyramid_Text_FiveTrainersRemaining6::
	.string "Bisakah kamu terus menang melawan\n"
	.string "lima TRAINER yang tersisa?$"

BattlePyramid_Text_FourTrainersRemaining6::
	.string "Bisakah kamu terus menang melawan\n"
	.string "empat TRAINER yang tersisa?$"

BattlePyramid_Text_ThreeTrainersRemaining6::
	.string "Bisakah kamu terus menang melawan\n"
	.string "tiga TRAINER yang tersisa?$"

BattlePyramid_Text_TwoTrainersRemaining6::
	.string "Bisakah kamu terus menang melawan\n"
	.string "dua TRAINER yang tersisa?$"

BattlePyramid_Text_OneTrainersRemaining6::
	.string "Bisakah kamu terus menang melawan\n"
	.string "TRAINER terakhir yang tersisa?$"

BattlePyramid_Text_ZeroTrainersRemaining6::
	.string "Tidak ada lagi TRAINER yang bisa\n"
	.string "melawanmu sekarang…$"
