//gemini
MauvilleCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MauvilleCity_Gym_OnLoad
	.byte 0

MauvilleCity_Gym_OnLoad:
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_DeactivatePuzzle
	switch VAR_MAUVILLE_GYM_STATE
	case 0, MauvilleCity_Gym_EventScript_UpdateBarriers
	case 1, MauvilleCity_Gym_EventScript_Switch1Pressed
	case 2, MauvilleCity_Gym_EventScript_Switch2Pressed
	case 3, MauvilleCity_Gym_EventScript_Switch3Pressed
	case 4, MauvilleCity_Gym_EventScript_Switch4Pressed
	end

MauvilleCity_Gym_EventScript_UpdateBarriers::
	goto_if_set FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_SetAltBarriers
	end

MauvilleCity_Gym_EventScript_SetAltBarriers::
	setmetatile 3, 11, METATILE_MauvilleGym_RedBeamV1_On, TRUE
	setmetatile 3, 12, METATILE_MauvilleGym_RedBeamV2_On, TRUE
	setmetatile 3, 13, METATILE_MauvilleGym_PoleTop_On, TRUE
	setmetatile 4, 10, METATILE_MauvilleGym_RedBeamH1_On, FALSE
	setmetatile 5, 10, METATILE_MauvilleGym_RedBeamH2_On, FALSE
	setmetatile 4, 11, METATILE_MauvilleGym_RedBeamH3_On, TRUE
	setmetatile 5, 11, METATILE_MauvilleGym_RedBeamH4_On, TRUE
	setmetatile 7, 10, METATILE_MauvilleGym_RedBeamH1_On, FALSE
	setmetatile 8, 10, METATILE_MauvilleGym_RedBeamH2_On, FALSE
	setmetatile 7, 11, METATILE_MauvilleGym_RedBeamH3_On, TRUE
	setmetatile 8, 11, METATILE_MauvilleGym_RedBeamH4_On, TRUE
	setmetatile 4, 13, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 5, 13, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 4, 14, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 5, 14, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	setmetatile 1, 10, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 2, 10, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 1, 11, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 2, 11, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	setmetatile 6, 8, METATILE_MauvilleGym_PoleBottom_On, TRUE
	setmetatile 6, 9, METATILE_MauvilleGym_FloorTile, FALSE
	setmetatile 6, 10, METATILE_MauvilleGym_PoleTop_Off, FALSE
	setmetatile 4, 6, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 5, 6, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 4, 7, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 5, 7, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	end

MauvilleCity_Gym_EventScript_Switch1Pressed::
	setvar VAR_0x8004, 0
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch2Pressed::
	setvar VAR_0x8004, 1
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch3Pressed::
	setvar VAR_0x8004, 2
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch4Pressed::
	setvar VAR_0x8004, 3
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_DeactivatePuzzle::
	special MauvilleGymDeactivatePuzzle
	end

MauvilleCity_Gym_EventScript_Wattson::
	trainerbattle_single TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonIntro, MauvilleCity_Gym_Text_WattsonDefeat, MauvilleCity_Gym_EventScript_WattsonDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_Gym_EventScript_WattsonRematch
	goto_if_unset FLAG_RECEIVED_TM_SHOCK_WAVE, MauvilleCity_Gym_EventScript_GiveShockWave2
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, MauvilleCity_Gym_EventScript_CompletedNewMauville
	msgbox MauvilleCity_Gym_Text_WattsonPostBattle, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_WattsonDefeated::
	message MauvilleCity_Gym_Text_ReceivedDynamoBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MauvilleCity_Gym_Text_ExplainDynamoBadgeTakeThis, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	clearflag FLAG_HIDE_VERDANTURF_TOWN_SCOTT
	setflag FLAG_DEFEATED_MAUVILLE_GYM
	setflag FLAG_BADGE03_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 3
	call Common_EventScript_SetGymTrainers
	special MauvilleGymDeactivatePuzzle
	special DrawWholeMapView
	playse SE_UNLOCK
	call MauvilleCity_Gym_EventScript_GiveShockWave
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MauvilleCity_Gym_Text_RegisteredWattson, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WATTSON_MATCH_CALL
	release
	end

MauvilleCity_Gym_EventScript_GiveShockWave2::
	giveitem ITEM_TM_SHOCK_WAVE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox MauvilleCity_Gym_Text_ExplainShockWave, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_SHOCK_WAVE
	release
	end

MauvilleCity_Gym_EventScript_GiveShockWave::
	giveitem ITEM_TM_SHOCK_WAVE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox MauvilleCity_Gym_Text_ExplainShockWave, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_SHOCK_WAVE
	return

MauvilleCity_Gym_EventScript_CompletedNewMauville::
	msgbox MauvilleCity_Gym_Text_WattsonGoForthAndEndeavor, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_WattsonRematch::
	trainerbattle_rematch_double TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonPreRematch, MauvilleCity_Gym_Text_WattsonRematchDefeat, MauvilleCity_Gym_Text_WattsonRematchNeedTwoMons
	msgbox MauvilleCity_Gym_Text_WattsonPostRematch, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Switch1::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 1, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 1
	setvar VAR_0x8004, 0
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch2::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 2, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 2
	setvar VAR_0x8004, 1
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch3::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 3, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 3
	setvar VAR_0x8004, 2
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch4::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 4, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 4
	setvar VAR_0x8004, 3
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_PressFloorSwitch::
	special MauvilleGymSetDefaultBarriers
	special MauvilleGymPressSwitch
	special DrawWholeMapView
	playse SE_UNLOCK
	goto_if_set FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_ClearBarriersAltState
	goto_if_unset FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_SetBarriersAltState
	releaseall
	end

MauvilleCity_Gym_EventScript_SwitchDoNothing::
	releaseall
	end

MauvilleCity_Gym_EventScript_SetBarriersAltState::
	setflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	releaseall
	end

MauvilleCity_Gym_EventScript_ClearBarriersAltState::
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	releaseall
	end

MauvilleCity_Gym_EventScript_Kirk::
	trainerbattle_single TRAINER_KIRK, MauvilleCity_Gym_Text_KirkIntro, MauvilleCity_Gym_Text_KirkDefeat
	msgbox MauvilleCity_Gym_Text_KirkPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Shawn::
	trainerbattle_single TRAINER_SHAWN, MauvilleCity_Gym_Text_ShawnIntro, MauvilleCity_Gym_Text_ShawnDefeat
	msgbox MauvilleCity_Gym_Text_ShawnPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Ben::
	trainerbattle_single TRAINER_BEN, MauvilleCity_Gym_Text_BenIntro, MauvilleCity_Gym_Text_BenDefeat
	msgbox MauvilleCity_Gym_Text_BenPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Vivian::
	trainerbattle_single TRAINER_VIVIAN, MauvilleCity_Gym_Text_VivianIntro, MauvilleCity_Gym_Text_VivianDefeat
	msgbox MauvilleCity_Gym_Text_VivianPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Angelo::
	trainerbattle_single TRAINER_ANGELO, MauvilleCity_Gym_Text_AngeloIntro, MauvilleCity_Gym_Text_AngeloDefeat
	msgbox MauvilleCity_Gym_Text_AngeloPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_GymGuidePostVictory
	msgbox MauvilleCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_GymGuidePostVictory::
	msgbox MauvilleCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_GymStatueCertified
	goto MauvilleCity_Gym_EventScript_GymStatue
	end

MauvilleCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_GymStatueCertified
	goto MauvilleCity_Gym_EventScript_GymStatue
	end

MauvilleCity_Gym_EventScript_GymStatueCertified::
	msgbox MauvilleCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_Gym_EventScript_GymStatue::
	msgbox MauvilleCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_Gym_Text_GymGuideAdvice:
	.string "Hei, apa kabar, calon\n"
	.string "JUARA {PLAYER}?\p"
	.string "WATTSON, PEMIMPIN GYM MAUVILLE,\n"
	.string "menggunakan POKéMON tipe LISTRIK.\p"
	.string "Jika kamu menantangnya dengan\n"
	.string "POKéMON tipe AIR, dia akan\l"
	.string "menyetrum mereka! Bzzt!\p"
	.string "Dia memasang pintu kendali\n"
	.string "sakelar di seluruh GYM-nya!\l"
	.string "Aneh!\p"
	.string "Hei, semangat!$"

MauvilleCity_Gym_Text_GymGuidePostVictory:
	.string "Wah, kamu menyetrum!\n"
	.string "Kamu telah membuka pintu!$"

MauvilleCity_Gym_Text_KirkIntro:
	.string "Jiwa listrikku, akan hancurkan\n"
	.string "impianmu, whoa-yeahah!$"

MauvilleCity_Gym_Text_KirkDefeat:
	.string "Itu terpasang, bertenaga,\n"
	.string "listrik berlebihan, kawan!$"

MauvilleCity_Gym_Text_KirkPostBattle:
	.string "POKéMON & rock, semuanya tentang\n"
	.string "hati, whoa-yeah!$"

MauvilleCity_Gym_Text_ShawnIntro:
	.string "Aku berlatih di bawah WATTSON!\n"
	.string "Tidak mungkin aku kalah mudah!$"

MauvilleCity_Gym_Text_ShawnDefeat:
	.string "Tercabut & mati…$"

MauvilleCity_Gym_Text_ShawnPostBattle:
	.string "WATTSON, PEMIMPIN GYM kami, sudah\n"
	.string "ada sejak lama sekali.\p"
	.string "Dia sudah bertarung bahkan sebelum\n"
	.string "ayahmu lahir, si tua tangguh itu.$"

MauvilleCity_Gym_Text_BenIntro:
	.string "GYM ini punya teka-teki!\n"
	.string "Menyenangkan, bukan?$"

MauvilleCity_Gym_Text_BenDefeat:
	.string "Tidak menyenangkan kalah…$"

MauvilleCity_Gym_Text_BenPostBattle:
	.string "WATTSON bilang dia suka memasang\n"
	.string "perangkap kecil dengan sakelar.$"

MauvilleCity_Gym_Text_VivianIntro:
	.string "Dengan pesonaku & jurus POKéMON-ku,\n"
	.string "kamu akan terkejut!$"

MauvilleCity_Gym_Text_VivianDefeat:
	.string "Aku terkejut oleh kekuatanmu!$"

MauvilleCity_Gym_Text_VivianPostBattle:
	.string "Aku dengar MAUVILLE didirikan\n"
	.string "oleh WATTSON.\p"
	.string "Dia adalah TRAINER jauh sebelum\n"
	.string "kita menjadi TRAINER.\l"
	.string "Dia pasti tahu banyak hal!$"

MauvilleCity_Gym_Text_AngeloIntro:
	.string "Aku suka hal-hal berkilau!$"

MauvilleCity_Gym_Text_AngeloDefeat:
	.string "Oh…\n"
	.string "Mataku pusing…$"

MauvilleCity_Gym_Text_AngeloPostBattle:
	.string "WATTSON dari GYM MAUVILLE punya\n"
	.string "dahi berkilau. Itu membuatku senang!$"

MauvilleCity_Gym_Text_WattsonIntro:
	.string "Aku sudah menyerah pada rencanaku\n"
	.string "untuk mengubah kota ini.\p"
	.string "Jadi, aku menghabiskan waktuku\n"
	.string "membuat perangkap pintu di GYM-ku.\p"
	.string "Oh? Sekarang, apa yang kamu\n"
	.string "lakukan di sini?\p"
	.string "Apa itu? Kamu bilang kamu sudah\n"
	.string "melewati semua pintu jebakku?\p"
	.string "Wahahahah!\n"
	.string "Itu lucu sekali!\p"
	.string "Kalau begitu, aku, WATTSON,\n"
	.string "PEMIMPIN GYM MAUVILLE, akan\l"
	.string "menyetrummu!$"

MauvilleCity_Gym_Text_WattsonDefeat:
	.string "Wahahahah!\n"
	.string "Baiklah, aku kalah!\p"
	.string "Kamu akhirnya memberiku sensasi!\n"
	.string "Ambil BADGE ini!$"

MauvilleCity_Gym_Text_ReceivedDynamoBadge:
	.string "{PLAYER} menerima DYNAMO BADGE\n"
	.string "dari WATTSON.$"

MauvilleCity_Gym_Text_ExplainDynamoBadgeTakeThis:
	.string "Dengan DYNAMO BADGE, POKéMON bisa\n"
	.string "pakai ROCK SMASH di luar pertarungan.\p"
	.string "&, itu juga akan membuat POKéMON-mu\n"
	.string "sedikit lebih cepat.\p"
	.string "Hmm…\n"
	.string "Kamu harus ambil ini juga!$"

MauvilleCity_Gym_Text_ExplainShockWave:
	.string "TM34 itu berisi SHOCK WAVE.\p"
	.string "Itu jurus terpercaya yang tidak\n"
	.string "pernah meleset! Kamu bisa\l"
	.string "mengandalkannya!\p"
	.string "… … … … … …$"

MauvilleCity_Gym_Text_RegisteredWattson:
	.string "Mendaftarkan PEMIMPIN GYM WATTSON\n"
	.string "ke POKéNAV.$"

MauvilleCity_Gym_Text_WattsonPostBattle:
	.string "Aku dipenuhi optimisme, melihat\n"
	.string "TRAINER muda menjanjikan sepertimu!$"

MauvilleCity_Gym_Text_WattsonGoForthAndEndeavor:
	.string "Wahahahah!\n"
	.string "Maju & berjuanglah, anak muda!$"

MauvilleCity_Gym_Text_GymStatue:
	.string "GYM POKéMON KOTA MAUVILLE$"

MauvilleCity_Gym_Text_GymStatueCertified:
	.string "GYM POKéMON KOTA MAUVILLE\p"
	.string "TRAINER BERSERTIFIKAT WATTSON:\n"
	.string "{PLAYER}$"

MauvilleCity_Gym_Text_WattsonPreRematch:
	.string "WATTSON: Ah-ha! Akhirnya\n"
	.string "datang juga! Aku tahu apa\l"
	.string "yang kamu inginkan. Kamu ingin\n"
	.string "melawan POKéMON-ku!\p"
	.string "Wahahahaha!\p"
	.string "Aku akan membuatmu\n"
	.string "mengeluarkan percikan api!\l"
	.string "Jangan bilang aku tidak\n"
	.string "memperingatkanmu!$"

MauvilleCity_Gym_Text_WattsonRematchDefeat:
	.string "Aduh…\n"
	.string "Baterai kami habis…$"

MauvilleCity_Gym_Text_WattsonPostRematch:
	.string "WATTSON: Kami harus mengisi\n"
	.string "ulang baterai kami lagi.\p"
	.string "Ketika kami sudah terisi penuh,\n"
	.string "kami akan senang hati menerima\l"
	.string "tantanganmu.\p"
	.string "Jadi, kembalilah lagi nanti,\n"
	.string "ya?$"

MauvilleCity_Gym_Text_WattsonRematchNeedTwoMons:
	.string "WATTSON: Ah-ha! Akhirnya\n"
	.string "datang juga! Aku tahu apa\l"
	.string "yang kamu inginkan. Kamu ingin\n"
	.string "melawan POKéMON-ku!\p"
	.string "Wahahahaha!\p"
	.string "Ups! Tunggu!\n"
	.string "Kamu hanya punya satu POKéMON!\p"
	.string "Datanglah padaku dengan dua\n"
	.string "POKéMON atau lebih, oke?$"
