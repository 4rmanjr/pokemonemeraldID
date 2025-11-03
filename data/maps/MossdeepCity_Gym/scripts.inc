MossdeepCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_Gym_OnLoad
	.byte 0

@ NOTE: Mossdeep Gym was redesigned between R/S and E. Leftover (and now functionally unused) scripts are commented below

MossdeepCity_Gym_OnTransition:
	setflag FLAG_TEMP_HIDE_FOLLOWER @ Hide follower since it can collide with moving statues
	end

@ All the below checks are leftover from RS. FLAG_MOSSDEEP_GYM_SWITCH_X is never set
MossdeepCity_Gym_OnLoad:
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_SetSwitch1Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
	end

MossdeepCity_Gym_EventScript_CheckSwitch2::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_SetSwitch2Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
	end

MossdeepCity_Gym_EventScript_CheckSwitch3::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_SetSwitch3Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
	end

MossdeepCity_Gym_EventScript_CheckSwitch4::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_SetSwitch4Metatiles
	end

@ All the below set metatile scripts are leftover from RS and are functionally unused
MossdeepCity_Gym_EventScript_SetSwitch1Metatiles::
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
	end

MossdeepCity_Gym_EventScript_SetSwitch2Metatiles::
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
	end

MossdeepCity_Gym_EventScript_SetSwitch3Metatiles::
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
	end

MossdeepCity_Gym_EventScript_SetSwitch4Metatiles::
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Up, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Down, TRUE
	end

MossdeepCity_Gym_EventScript_TateAndLiza::
	trainerbattle_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaIntro, MossdeepCity_Gym_Text_TateAndLizaDefeat, MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons, MossdeepCity_Gym_EventScript_TateAndLizaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MossdeepCity_Gym_EventScript_TateAndLizaRematch
	goto_if_unset FLAG_RECEIVED_TM_CALM_MIND, MossdeepCity_Gym_EventScript_GiveCalmMind2
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostBattle, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_TateAndLizaDefeated::
	message MossdeepCity_Gym_Text_ReceivedMindBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
	setflag FLAG_BADGE07_GET
	setflag FLAG_HIDE_AQUA_HIDEOUT_GRUNTS
	clearflag FLAG_HIDE_SLATEPORT_CITY_STERNS_SHIPYARD_MR_BRINEY
	clearflag FLAG_UNKNOWN_0x393
	setvar VAR_0x8008, 7
	call Common_EventScript_SetGymTrainers
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS
	clearflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_STEVEN
	setvar VAR_MOSSDEEP_CITY_STATE, 1
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_STEVEN
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE, 1
	call MossdeepCity_Gym_EventScript_GiveCalmMind
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MossdeepCity_Gym_Text_RegisteredTateAndLiza, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_TATE_AND_LIZA_MATCH_CALL
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind2::
	giveitem ITEM_TM_CALM_MIND
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_CALM_MIND
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind::
	giveitem ITEM_TM_CALM_MIND
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_CALM_MIND
	return

MossdeepCity_Gym_EventScript_TateAndLizaRematch::
	trainerbattle_rematch_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaPreRematch, MossdeepCity_Gym_Text_TateAndLizaRematchDefeat, MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostRematch, MSGBOX_AUTOCLOSE
	end

@ All the below switch scripts are leftover from RS and are functionally unused
MossdeepCity_Gym_EventScript_Switch1::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_ClearSwitch1
	setflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed::
	special DrawWholeMapView
	playse SE_CLICK
	releaseall
	end

MossdeepCity_Gym_EventScript_ClearSwitch1::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch2::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_ClearSwitch2
	setflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch2::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Down, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch3::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_ClearSwitch3
	setflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch3::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch4::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_ClearSwitch4
	setflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Up, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch4::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_WarpToEntrance::
	lockall
	warpmossdeepgym MAP_MOSSDEEP_CITY_GYM, 7, 30
	waitstate
	releaseall
	end

MossdeepCity_Gym_EventScript_Preston::
	trainerbattle_single TRAINER_PRESTON, MossdeepCity_Gym_Text_PrestonIntro, MossdeepCity_Gym_Text_PrestonDefeat
	msgbox MossdeepCity_Gym_Text_PrestonPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Virgil::
	trainerbattle_single TRAINER_VIRGIL, MossdeepCity_Gym_Text_VirgilIntro, MossdeepCity_Gym_Text_VirgilDefeat
	msgbox MossdeepCity_Gym_Text_VirgilPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Blake::
	trainerbattle_single TRAINER_BLAKE, MossdeepCity_Gym_Text_BlakeIntro, MossdeepCity_Gym_Text_BlakeDefeat
	msgbox MossdeepCity_Gym_Text_BlakePostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Hannah::
	trainerbattle_single TRAINER_HANNAH, MossdeepCity_Gym_Text_HannahIntro, MossdeepCity_Gym_Text_HannahDefeat
	msgbox MossdeepCity_Gym_Text_HannahPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Samantha::
	trainerbattle_single TRAINER_SAMANTHA, MossdeepCity_Gym_Text_SamanthaIntro, MossdeepCity_Gym_Text_SamanthaDefeat
	msgbox MossdeepCity_Gym_Text_SamanthaPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Maura::
	trainerbattle_single TRAINER_MAURA, MossdeepCity_Gym_Text_MauraIntro, MossdeepCity_Gym_Text_MauraDefeat
	msgbox MossdeepCity_Gym_Text_MauraPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Sylvia::
	trainerbattle_single TRAINER_SYLVIA, MossdeepCity_Gym_Text_SylviaIntro, MossdeepCity_Gym_Text_SylviaDefeat
	msgbox MossdeepCity_Gym_Text_SylviaPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Nate::
	trainerbattle_single TRAINER_NATE, MossdeepCity_Gym_Text_NateIntro, MossdeepCity_Gym_Text_NateDefeat
	msgbox MossdeepCity_Gym_Text_NatePostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Macey::
	trainerbattle_single TRAINER_MACEY, MossdeepCity_Gym_Text_MaceyIntro, MossdeepCity_Gym_Text_MaceyDefeat
	msgbox MossdeepCity_Gym_Text_MaceyPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Clifford::
	trainerbattle_single TRAINER_CLIFFORD, MossdeepCity_Gym_Text_CliffordIntro, MossdeepCity_Gym_Text_CliffordDefeat
	msgbox MossdeepCity_Gym_Text_CliffordPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Nicholas::
	trainerbattle_single TRAINER_NICHOLAS, MossdeepCity_Gym_Text_NicholasIntro, MossdeepCity_Gym_Text_NicholasDefeat
	msgbox MossdeepCity_Gym_Text_NicholasPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Kathleen::
	trainerbattle_single TRAINER_KATHLEEN, MossdeepCity_Gym_Text_KathleenIntro, MossdeepCity_Gym_Text_KathleenDefeat
	msgbox MossdeepCity_Gym_Text_KathleenPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MOSSDEEP_GYM, MossdeepCity_Gym_EventScript_GymGuidePostVictory
	msgbox MossdeepCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_GymGuidePostVictory::
	msgbox MossdeepCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

@ Leftover from RS, functionally unused
MossdeepCity_Gym_Movement_WaitAfterSwitchUse:
	delay_16
	delay_16
	step_end

MossdeepCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
	goto MossdeepCity_Gym_EventScript_GymStatue
	end

MossdeepCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
	goto MossdeepCity_Gym_EventScript_GymStatue
	end

MossdeepCity_Gym_EventScript_GymStatueCertified::
	msgbox MossdeepCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_GymStatue::
	msgbox MossdeepCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_YellowFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 0
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_BlueFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 1
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_GreenFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 2
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_PurpleFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 3
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_RedFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 4
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_Text_GymGuideAdvice:
	.string "Yo, apa kabar, calon CHAMPION\n"
	.string "{PLAYER}?\p"
	.string "PEMIMPIN GYM di sini menggunakan POKéMON\n"
	.string "tipe PSYCHIC.\p"
	.string "Jika kamu melawan dengan POKéMON tipe\n"
	.string "FIGHTING atau POISON,\l"
	.string "damage yang diterima akan parah!\p"
	.string "Selain itu, mereka akan menyerangmu\n"
	.string "dengan kombinasi serangan luar biasa.\p"
	.string "Jika ingin menang, tunjukkan\n"
	.string "kedekatanmu dengan POKéMON-mu.\l"
	.string "Semangat!$"

MossdeepCity_Gym_Text_GymGuidePostVictory:
	.string "Wow, kamu luar biasa!\n"
	.string "Kamu TRAINER yang hebat!$"

MossdeepCity_Gym_Text_PrestonIntro:
	.string "Pertarungan bergantung pada kekuatan\n"
	.string "semangatmu! Yang lemah takkan menang!$"

MossdeepCity_Gym_Text_PrestonDefeat:
	.string "Aku kalah!\n"
	.string "Aku harus melatih lagi semangatku!$"

MossdeepCity_Gym_Text_PrestonPostBattle:
	.string "Yang ragu-ragu akan kalah.\n"
	.string "Itu peringatanku untukmu.$"

MossdeepCity_Gym_Text_VirgilIntro:
	.string "Biar kulihat bakatmu!$"

MossdeepCity_Gym_Text_VirgilDefeat:
	.string "Bakatmu sungguh spektakuler!$"

MossdeepCity_Gym_Text_VirgilPostBattle:
	.string "Jika ada yang jenius di dunia ini,\n"
	.string "maka GYM LEADER kami adalah mereka!\p"
	.string "Namun, kamu mungkin lebih berbakat\n"
	.string "dari mereka…$"

MossdeepCity_Gym_Text_BlakeIntro:
	.string "Fufufu… Lihat aku mengangkat POKé BALL\n"
	.string "dengan telekinesis!\p"
	.string "Wrooooooooaaaar!\n"
	.string "… … … … … … …\p"
	.string "Terkadang, aku tidak sinkron…$"

MossdeepCity_Gym_Text_BlakeDefeat:
	.string "Kemampuan bertarung POKéMON-ku juga\n"
	.string "tidak sinkron!$"

MossdeepCity_Gym_Text_BlakePostBattle:
	.string "POKé BALL terlalu berat untuk diangkat\n"
	.string "secara psikis. Tapi debu ini…\p"
	.string "Whoooooooooooooooh!\n"
	.string "… … … … … …\p"
	.string "Tidak, aku tidak curang!\n"
	.string "Aku tidak meniupnya! Sungguh!$"

MossdeepCity_Gym_Text_HannahIntro:
	.string "Saat kamu kalah dariku, jangan terlalu\n"
	.string "keras pada dirimu sendiri.\p"
	.string "Bukannya kamu lemah--hanya saja aku\n"
	.string "terlalu kuat!$"

MossdeepCity_Gym_Text_HannahDefeat:
	.string "Kamu terlalu kuat!$"

MossdeepCity_Gym_Text_HannahPostBattle:
	.string "Aku tidak akan meratapi kekalahan.\n"
	.string "Aku hanya perlu berlatih lebih giat.\p"
	.string "Berpikir positif--itulah kelebihanku!$"

MossdeepCity_Gym_Text_SamanthaIntro:
	.string "Aku melihatnya…\n"
	.string "Aku melihat masa depanmu…\p"
	.string "Jika bisa mengalahkanku, akan\n"
	.string "kuberitahu masa depanmu!$"

MossdeepCity_Gym_Text_SamanthaDefeat:
	.string "Aku menyerah!$"

MossdeepCity_Gym_Text_SamanthaPostBattle:
	.string "Kamu akan menjalani pertarungan sengit\n"
	.string "dengan GYM LEADER kami…\p"
	.string "Hasilnya…\n"
	.string "Tidak akan kamu dengar dariku!$"

MossdeepCity_Gym_Text_MauraIntro:
	.string "Jalan yang kamu tempuh…\n"
	.string "Pengalaman yang kamu dapatkan…\p"
	.string "Hadapi aku dengan semua yang kamu\n"
	.string "pelajari!$"

MossdeepCity_Gym_Text_MauraDefeat:
	.string "Kamu telah menempuh jalan yang hebat!$"

MossdeepCity_Gym_Text_MauraPostBattle:
	.string "Masa depan cerah menanti mereka\n"
	.string "yang bekerja keras.\p"
	.string "Bagi mereka yang bermalas-malasan,\n"
	.string "hanya ada keputusasaan di akhir.\p"
	.string "Apa yang kamu tabur, itu yang\n"
	.string "akan kamu tuai…$"

MossdeepCity_Gym_Text_SylviaIntro:
	.string "Bahkan dengan risiko nyawa, aku akan\n"
	.string "memenangkan pertarungan ini!$"

MossdeepCity_Gym_Text_SylviaDefeat:
	.string "Apa yang kamu lakukan…\n"
	.string "Itu membuatku ngeri…$"

MossdeepCity_Gym_Text_SylviaPostBattle:
	.string "Beraninya kamu mengalahkanku…\p"
	.string "Bukan salahku jika sesuatu yang\n"
	.string "mengerikan menimpamu…$"

MossdeepCity_Gym_Text_NateIntro:
	.string "Hohoho.\p"
	.string "Kamu perlu aku menunjukkan betapa\n"
	.string "uletnya tipe PSYCHIC.$"

MossdeepCity_Gym_Text_NateDefeat:
	.string "Oh! Astaga!\n"
	.string "Gaya bertarungmu luar biasa!$"

MossdeepCity_Gym_Text_NatePostBattle:
	.string "A-aku… aku tidak membiarkan kekalahan\n"
	.string "menggangguku, s-seburuk apa pun itu.$"

MossdeepCity_Gym_Text_KathleenIntro:
	.string "Akan kutunjukkan waktu yang sangat\n"
	.string "mengerikan dan menakutkan!$"

MossdeepCity_Gym_Text_KathleenDefeat:
	.string "T-tidaaaaak!$"

MossdeepCity_Gym_Text_KathleenPostBattle:
	.string "Vitalitasmu menular!\n"
	.string "Cepat menjauh dariku!$"

MossdeepCity_Gym_Text_CliffordIntro:
	.string "Aku mungkin sudah melewati masa\n"
	.string "kejayaanku, tapi jangan meremehkanku.$"

MossdeepCity_Gym_Text_CliffordDefeat:
	.string "Ah, kamu meluap dengan kekuatan\n"
	.string "masa muda!$"

MossdeepCity_Gym_Text_CliffordPostBattle:
	.string "Sepertinya aku tidak bisa mengatasi\n"
	.string "energimu yang muda itu.$"

MossdeepCity_Gym_Text_MaceyIntro:
	.string "Kamu tidak akan sampai akhir!\n"
	.string "Tidak jika aku bisa mencegahnya!$"

MossdeepCity_Gym_Text_MaceyDefeat:
	.string "Bagaimana kamu bisa sekuat ini?$"

MossdeepCity_Gym_Text_MaceyPostBattle:
	.string "Hmph! Kamu mungkin kuat, tapi kamu\n"
	.string "tidak cocok untuk tipe PSYCHIC!\p"
	.string "Caramu bertarung entah kenapa brutal!$"

MossdeepCity_Gym_Text_NicholasIntro:
	.string "Wroooar! Rasakan kekuatan\n"
	.string "pertarungan POKéMON-ku yang super!$"

MossdeepCity_Gym_Text_NicholasDefeat:
	.string "Oh!\n"
	.string "Kalah!$"

MossdeepCity_Gym_Text_NicholasPostBattle:
	.string "Baiklah! Aku akan mengembangkan kekuatan\n"
	.string "POKéMON spesial yang tak terkalahkan.$"

MossdeepCity_Gym_Text_TateAndLizaIntro:
	.string "TATE: Hehehe… Kamu terkejut?\p"
	.string "LIZA: Fufufu… Kamu terkejut?\p"
	.string "TATE: Bahwa ada dua PEMIMPIN GYM?\n"
	.string "LIZA: Bahwa ada dua PEMIMPIN GYM?\p"
	.string "TATE: Kami kembar!\n"
	.string "LIZA: Kami kembar!\p"
	.string "TATE: Kami tidak perlu bicara karena…\n"
	.string "LIZA: Kami bisa saling mengetahui apa…\p"
	.string "TATE: Yang dipikirkan satu sama lain…\n"
	.string "LIZA: Semua di pikiran kami!\p"
	.string "TATE: Kombinasi kami ini…\n"
	.string "LIZA: Bisakah kamu mengalahkannya?$"

MossdeepCity_Gym_Text_TateAndLizaDefeat:
	.string "TATE: Apa?! Kombinasi kami…\n"
	.string "LIZA: Hancur!\p"
	.string "TATE: Mau bagaimana lagi. Kamu menang…\n"
	.string "LIZA: Jadi, sebagai pengakuan, ambil ini.$"

MossdeepCity_Gym_Text_ReceivedMindBadge:
	.string "{PLAYER} menerima LENCANA PIKIRAN\n"
	.string "dari TATE dan LIZA.$"

MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis:
	.string "TATE: LENCANA PIKIRAN meningkatkan\n"
	.string "SP. ATK dan SP. DEF POKéMON.\p"
	.string "LIZA: Ini juga memungkinkanmu memakai\n"
	.string "gerakan HM DIVE di luar pertarungan.\p"
	.string "TATE: Kamu juga harus mengambil ini.$"

MossdeepCity_Gym_Text_ExplainCalmMind:
	.string "TATE: TM04 itu berisi…\n"
	.string "LIZA: CALM MIND!\p"
	.string "TATE: Itu meningkatkan SP. ATK dan…\n"
	.string "LIZA: Itu meningkatkan SP. DEF!\p"
	.string "TATE: Itu adalah gerakan yang sempurna…\n"
	.string "LIZA: Untuk POKéMON PSYCHIC!\p"
	.string "… … … … … …$"

MossdeepCity_Gym_Text_RegisteredTateAndLiza:
	.string "Mendaftarkan PEMIMPIN GYM TATE & LIZA\n"
	.string "di POKéNAV.$"

MossdeepCity_Gym_Text_TateAndLizaPostBattle:
	.string "TATE: Sepertinya ikatan antara kamu\n"
	.string "dan POKéMON-mu jauh lebih kuat dari\l"
	.string "ikatan yang kami bagi sebagai kembar.\p"
	.string "LIZA: Kamu akan menjadi lebih kuat!\n"
	.string "Kami sudah melawanmu, jadi kami tahu.$"

MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons:
	.string "TATE: Hehehe… Kamu terkejut?\p"
	.string "LIZA: Bahwa ada dua PEMIMPIN GYM?\p"
	.string "TATE: Ups, kamu hanya punya satu…\n"
	.string "LIZA: POKéMON yang bisa bertarung.\p"
	.string "TATE: Kami tidak bisa bertarung begitu!\p"
	.string "LIZA: Jika kamu ingin menantang kami,\n"
	.string "bawalah lebih banyak POKéMON.$"

MossdeepCity_Gym_Text_GymStatue:
	.string "GYM POKéMON KOTA MOSSDEEP$"

MossdeepCity_Gym_Text_GymStatueCertified:
	.string "GYM POKéMON KOTA MOSSDEEP\p"
	.string "TRAINER BERSERTIFIKAT LIZA DAN TATE:\n"
	.string "{PLAYER}$"

MossdeepCity_Gym_Text_TateAndLizaPreRematch:
	.string "TATE: POKéMON…\n"
	.string "LIZA: POKéMON…\p"
	.string "TATE: Dengan mengubah komposisi tim…\n"
	.string "LIZA: Gaya bertarung berubah.\p"
	.string "TATE: Tapi aku…\n"
	.string "LIZA: Tapi aku…\p"
	.string "TATE: Aku akan selalu bersama LIZA!\n"
	.string "LIZA: Aku akan selalu bersama TATE!\p"
	.string "TATE: Kombinasi kami…\n"
	.string "LIZA: Akan kami tunjukkan lagi dan lagi!$"

MossdeepCity_Gym_Text_TateAndLizaRematchDefeat:
	.string "TATE: Kamu dan POKéMON-mu…\n"
	.string "LIZA: Seolah-olah kalian bersaudara!$"

MossdeepCity_Gym_Text_TateAndLizaPostRematch:
	.string "TATE: Kamu bisa menjatuhkan kami,\n"
	.string "tapi kami tidak akan pernah menyerah!\p"
	.string "LIZA: Karena kami berdua,\n"
	.string "kami selalu mendukung satu sama lain!$"

MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons:
	.string "TATE: Kamu kembali lagi…\n"
	.string "LIZA: Kamu kembali lagi…\p"
	.string "TATE: Untuk memberi kami pertandingan\n"
	.string "ulang.\n"
	.string "LIZA: Untuk memberi kami pertandingan\n"
	.string "ulang.\p"
	.string "TATE: Tapi…\n"
	.string "LIZA: Untuk pertandingan kami…\p"
	.string "TATE: Kamu hanya membawa satu POKéMON!\n"
	.string "LIZA: Kamu hanya membawa satu POKéMON!\p"
	.string "TATE: Kami butuh kamu membawa setidaknya…\n"
	.string "LIZA: Dua POKéMON saat kamu kembali.$"
