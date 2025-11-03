MtChimney_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MtChimney_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, MtChimney_OnTransition
	.byte 0

MtChimney_OnTransition:
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 1
	end

MtChimney_OnResume:
	setstepcallback STEP_CB_ASH
	end

MtChimney_EventScript_Archie::
	lock
	faceplayer
	call_if_unset FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieGoStopTeamMagma
	call_if_set FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieBusyFighting
	closemessage
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_EVIL_LEADER_PLEASE_STOP
	release
	end

MtChimney_EventScript_ArchieGoStopTeamMagma::
	msgbox MtChimney_Text_ArchieGoStopTeamMagma, MSGBOX_DEFAULT
	return

MtChimney_EventScript_ArchieBusyFighting::
	msgbox MtChimney_Text_ArchieIHaveMyHandsFull, MSGBOX_DEFAULT
	return

MtChimney_EventScript_Maxie::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox MtChimney_Text_MeteoriteWillActivateVolcano, MSGBOX_DEFAULT
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_Delay48
	waitmovement 0
	msgbox MtChimney_Text_MaxieIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MAXIE_MT_CHIMNEY, MtChimney_Text_MaxieDefeat
	msgbox MtChimney_Text_MaxieYouHaventSeenLastOfMagma, MSGBOX_DEFAULT
	closemessage
	delay 30
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_MT_CHIMNEY_MAXIE
	removeobject LOCALID_MT_CHIMNEY_MAGMA_GRUNT_1
	removeobject LOCALID_MT_CHIMNEY_TABITHA
	removeobject LOCALID_MT_CHIMNEY_MAGMA_GRUNT_2
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA
	fadescreenswapbuffers FADE_FROM_BLACK
	setobjectxyperm LOCALID_MT_CHIMNEY_ARCHIE, 10, 12
	addobject LOCALID_MT_CHIMNEY_ARCHIE
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieApproachPlayerEast
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieApproachPlayerNorth
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MtChimney_Text_ArchieThankYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieExitEast
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieExitNorth
	removeobject LOCALID_MT_CHIMNEY_ARCHIE
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA
	setflag FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY
	clearflag FLAG_HIDE_FALLARBOR_HOUSE_PROF_COZMO
	setflag FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO
	clearflag FLAG_HIDE_MT_CHIMNEY_LAVA_COOKIE_LADY
	releaseall
	end

MtChimney_EventScript_ArchieApproachPlayerEast::
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieApproachPlayerEast
	waitmovement 0
	return

MtChimney_EventScript_ArchieApproachPlayerNorth::
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieApproachPlayerNorth
	waitmovement 0
	return

MtChimney_EventScript_ArchieExitEast::
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieExitEast
	waitmovement 0
	return

MtChimney_EventScript_ArchieExitNorth::
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieExitNorth
	waitmovement 0
	return

MtChimney_EventScript_LavaCookieLady::
	lock
	faceplayer
	showmoneybox 0, 0
	msgbox MtChimney_Text_LavaCookiesJust200, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_DeclineLavaCookie
	checkmoney 200
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_NotEnoughMoney
	msgbox MtChimney_Text_ThankYouDear, MSGBOX_DEFAULT
	checkitemspace ITEM_LAVA_COOKIE
	call_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RemoveMoney
.if OW_SHOW_ITEM_DESCRIPTIONS == OW_ITEM_DESCRIPTIONS_OFF
	giveitem ITEM_LAVA_COOKIE
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_BagIsFull
	hidemoneybox
	release
	end

MtChimney_EventScript_BagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end
.else
	hidemoneybox
	giveitem ITEM_LAVA_COOKIE
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_BagIsFull
	release
	end

MtChimney_EventScript_BagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	release
	end
.endif @ OW_SHOW_ITEM_DESCRIPTIONS


MtChimney_EventScript_RemoveMoney::
	removemoney 200
	updatemoneybox
	return

MtChimney_EventScript_DeclineLavaCookie::
	msgbox MtChimney_Text_OhFineThen, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_EventScript_NotEnoughMoney::
	msgbox MtChimney_Text_YouveNotGotTheMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_Movement_ArchieApproachPlayerEast:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	step_end

MtChimney_Movement_ArchieExitEast:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_ArchieApproachPlayerNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

MtChimney_Movement_ArchieExitNorth:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused2:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused3:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused4:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused5:
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused6:
	delay_16
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused7:
	delay_16
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused8:
	delay_16
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

MtChimney_Movement_Unused9:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused10:
	walk_down
	step_end

MtChimney_Movement_Unused11:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused12:
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused13:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused14:
	lock_facing_direction
	walk_fast_left
	unlock_facing_direction
	face_right
	step_end

MtChimney_Movement_Unused15:
	walk_left
	walk_in_place_faster_right
	delay_16
	step_end

MtChimney_EventScript_BusyAquaGrunt1::
	msgbox MtChimney_Text_MagmaOutnumbersUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt2::
	msgbox MtChimney_Text_LessHabitatForWaterPokemon, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt3::
	msgbox MtChimney_Text_MagmasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_Tabitha::
	trainerbattle_single TRAINER_TABITHA_MT_CHIMNEY, MtChimney_Text_TabithaIntro, MtChimney_Text_TabithaDefeat
	msgbox MtChimney_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_2, MtChimney_Text_Grunt2Intro, MtChimney_Text_Grunt2Defeat
	msgbox MtChimney_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_BusyMagmaGrunt1::
	msgbox MtChimney_Text_TeamAquaAlwaysMessingWithPlans, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt2::
	msgbox MtChimney_Text_MeteoritesPackAmazingPower, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt3::
	msgbox MtChimney_Text_YouBetterNotMessWithUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt4::
	msgbox MtChimney_Text_AquasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt5::
	msgbox MtChimney_Text_DouseThemInFire, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt6::
	msgbox MtChimney_Text_KeepMakingMoreLand, MSGBOX_SIGN
	end

MtChimney_EventScript_MagmaPoochyena::
	msgbox MtChimney_Text_Bufoh, MSGBOX_SIGN
	end

MtChimney_EventScript_AquaPoochyena::
	msgbox MtChimney_Text_Bushaa, MSGBOX_SIGN
	end

MtChimney_EventScript_MeteoriteMachine::
	lockall
	goto_if_unset FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, MtChimney_EventScript_MachineOn
	goto_if_set FLAG_RECEIVED_METEORITE, MtChimney_EventScript_MachineOff
	msgbox MtChimney_Text_RemoveTheMeteorite, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_LeaveMeteoriteAlone
	msgbox MtChimney_Text_PlayerRemovedMeteorite, MSGBOX_DEFAULT
	giveitem ITEM_METEORITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_METEORITE
	releaseall
	end

MtChimney_EventScript_LeaveMeteoriteAlone::
	msgbox MtChimney_Text_PlayerLeftMeteorite, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_MachineOff::
	msgbox MtChimney_Text_MachineMakesNoResponse, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_MachineOn::
	msgbox MtChimney_Text_MetoriteFittedOnMachine, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_RouteSign::
	msgbox MtChimney_Text_RouteSign, MSGBOX_SIGN
	end

MtChimney_EventScript_Shelby::
	trainerbattle_single TRAINER_SHELBY_1, MtChimney_Text_ShelbyIntro, MtChimney_Text_ShelbyDefeat, MtChimney_EventScript_DefeatedShelby
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RematchShelby
	msgbox MtChimney_Text_ShelbyPostBattle, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_DefeatedShelby::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtChimney_Text_ShelbyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SHELBY_1
	release
	end

MtChimney_EventScript_RematchShelby::
	trainerbattle_rematch TRAINER_SHELBY_1, MtChimney_Text_ShelbyRematchIntro, MtChimney_Text_ShelbyRematchDefeat
	msgbox MtChimney_Text_ShelbyPostRematch, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Melissa::
	trainerbattle_single TRAINER_MELISSA, MtChimney_Text_MelissaIntro, MtChimney_Text_MelissaDefeat
	msgbox MtChimney_Text_MelissaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sheila::
	trainerbattle_single TRAINER_SHEILA, MtChimney_Text_SheilaIntro, MtChimney_Text_SheilaDefeat
	msgbox MtChimney_Text_SheilaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Shirley::
	trainerbattle_single TRAINER_SHIRLEY, MtChimney_Text_ShirleyIntro, MtChimney_Text_ShirleyDefeat
	msgbox MtChimney_Text_ShirleyPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_1, MtChimney_Text_Grunt1Intro, MtChimney_Text_Grunt1Defeat
	msgbox MtChimney_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sawyer::
	trainerbattle_single TRAINER_SAWYER_1, MtChimney_Text_SawyerIntro, MtChimney_Text_SawyerDefeat, MtChimney_EventScript_SawyerDefeated
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_SawyerRematch
	msgbox MtChimney_Text_SawyerPostBattle, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_SawyerDefeated::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtChimney_Text_SawyerRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SAWYER_1
	release
	end

MtChimney_EventScript_SawyerRematch::
	trainerbattle_rematch TRAINER_SAWYER_1, MtChimney_Text_SawyerRematchIntro, MtChimney_Text_SawyerRematchDefeat
	msgbox MtChimney_Text_SawyerPostRematch, MSGBOX_AUTOCLOSE
	end

MtChimney_Text_MeteoriteWillActivateVolcano:
	.string "Kekuatan yang terkandung dalam METEORITE…\p"
	.string "Dengan memperkuat kekuatannya dengan\n"
	.string "mesin ini, aktivitas vulkanik GUNUNG\l"
	.string "CHIMNEY akan langsung meningkat…\p"
	.string "Energinya akan tumbuh jauh di dalam\n"
	.string "kawah dan…\l"
	.string "Fufufu…$"

MtChimney_Text_MaxieIntro:
	.string "MAXIE: Hm?\n"
	.string "Siapa kamu?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Aku dengar ARCHIE mengeluhkan seorang anak\n"
	.string "yang ikut campur dalam urusan TEAM AQUA.\l"
	.string "Pasti kamu yang dia maksud.\p"
	.string "Cih! Jadi kamu berpikir untuk\n"
	.string "mengganggu kami, TEAM MAGMA?\p"
	.string "Dengar baik-baik.\n"
	.string "Dahulu kala, makhluk hidup menggunakan\l"
	.string "daratan untuk hidup dan berkembang.\p"
	.string "Itulah mengapa daratan sangat penting!\n"
	.string "Itu adalah tempat lahirnya semua!\p"
	.string "Itulah mengapa TEAM MAGMA berdedikasi\n"
	.string "untuk memperluas daratan.\p"
	.string "Ini demi kemajuan umat manusia\n"
	.string "dan POKéMON!\p"
	.string "Dan untuk itu, kami membutuhkan kekuatan\n"
	.string "dari apa yang tidur di dalam gunung ini…\p"
	.string "Oh! Kamu tidak perlu\n"
	.string "tahu sebanyak itu.\p"
	.string "Tapi, tidak masalah!\n"
	.string "Aku akan mengajarimu konsekuensi dari\l"
	.string "ikut campur dalam rencana besar kami!$"

MtChimney_Text_MaxieDefeat:
	.string "Apa?!\p"
	.string "Aku, MAXIE, lengah?!$"

MtChimney_Text_MaxieYouHaventSeenLastOfMagma:
	.string "MAXIE: Tapi, cukuplah.\n"
	.string "Aku akan mundur kali ini.\p"
	.string "Tapi jangan berpikir bahwa ini adalah yang terakhir\n"
	.string "kamu melihat TEAM MAGMA.\p"
	.string "Fufufu…\p"
	.string "Bahkan tanpa METEORITE, jika kami\n"
	.string "mendapatkan ORB itu… Fufufu…$"

MtChimney_Text_TabithaIntro:
	.string "Hehehe!\p"
	.string "Jadi kamu sudah datang jauh-jauh ke sini!\p"
	.string "Tapi kamu terlambat!\n"
	.string "Aku sudah mengantarkan METEORITE\l"
	.string "dari AIR TERJUN METEOR ke KETUA!$"

MtChimney_Text_TabithaDefeat:
	.string "Hehehe…\p"
	.string "Meskipun Aku kalah, jika pemimpin kami\n"
	.string "membangunkan benda itu…$"

MtChimney_Text_TabithaPostBattle:
	.string "KETUA, cepatlah!\n"
	.string "Berikan energi METEORITE padanya!\p"
	.string "Hehehe…$"

MtChimney_Text_Grunt2Intro:
	.string "Kami dari TEAM MAGMA bekerja keras demi\n"
	.string "kepentingan semua orang.\p"
	.string "Misalnya, jika kekuatan benda itu menciptakan lebih banyak\n"
	.string "daratan, akan ada lebih banyak tempat untuk hidup.\p"
	.string "Semua orang akan bahagia!$"

MtChimney_Text_Grunt2Defeat:
	.string "Hah?\n"
	.string "Apa maksudmu Aku kalah?$"

MtChimney_Text_Grunt2PostBattle:
	.string "KETUA kami berkata, “Itu akan membuat semua orang\n"
	.string "bahagia.”\p"
	.string "Tapi mengapa semua orang terus-menerus\n"
	.string "menghalangi kami?$"

MtChimney_Text_Grunt1Intro:
	.string "Jika ada lebih banyak daratan, Aku akan bisa\n"
	.string "mendapatkan rumah besar milikku sendiri!\p"
	.string "Aku akan membangunnya di atas lava yang mengeras!$"

MtChimney_Text_Grunt1Defeat:
	.string "Mimpiku tentang rumah besar…$"

MtChimney_Text_Grunt1PostBattle:
	.string "Anak sepertimu, kamu seharusnya\n"
	.string "bermain-main di ombak!$"

MtChimney_Text_TeamAquaAlwaysMessingWithPlans:
	.string "TEAM AQUA yang menyebalkan itu…\n"
	.string "Mereka selalu mengacaukan rencana kami!$"

MtChimney_Text_MeteoritesPackAmazingPower:
	.string "METEORITE menyimpan kekuatan yang luar biasa!$"

MtChimney_Text_YouBetterNotMessWithUs:
	.string "Sebaiknya kamu tidak mengganggu kami!\p"
	.string "Kami mencoba membangunkan benda itu\n"
	.string "demi kebaikan semua orang!$"

MtChimney_Text_AquasNameSimilar:
	.string "Kami TEAM MAGMA!\p"
	.string "Mereka TEAM AQUA!\p"
	.string "Aku sangat kesal karena mereka\n"
	.string "menggunakan nama seperti kami!$"

MtChimney_Text_DouseThemInFire:
	.string "Ya!\n"
	.string "Siram mereka dengan api!$"

MtChimney_Text_KeepMakingMoreLand:
	.string "Kami akan terus membuat lebih banyak daratan!$"

MtChimney_Text_Bufoh:
	.string "Bufoh!$"

MtChimney_Text_ArchieGoStopTeamMagma:
	.string "ARCHIE: Grr, {PLAYER}!\n"
	.string "Aku seharusnya sudah menduga kamu akan muncul!\p"
	.string "Lihat sendiri apa yang dilakukan para fanatik\n"
	.string "TEAM MAGMA!\p"
	.string "Mereka mencoba menyuntikkan kekuatan METEORITE\n"
	.string "yang dicuri ke dalam gunung berapi!\p"
	.string "Melakukan hal seperti itu akan menyebabkan\n"
	.string "gunung berapi meletus!$"

MtChimney_Text_ArchieIHaveMyHandsFull:
	.string "ARCHIE: Grrr…\p"
	.string "Aku ingin menghentikan MAXIE itu,\n"
	.string "tapi Aku tidak bisa!\p"
	.string "Tidak ketika Aku sedang sibuk bertarung\n"
	.string "melawan tiga lawan sekaligus!$"

MtChimney_Text_ArchieThankYou:
	.string "ARCHIE: {PLAYER}!\n"
	.string "Terima kasih!\p"
	.string "Dengan bantuanmu, kami menggagalkan rencana\n"
	.string "destruktif TEAM MAGMA!\p"
	.string "Tapi… Kamu…\n"
	.string "Kamu di pihak siapa?\p"
	.string "Ah, tidak masalah.\p"
	.string "Kami akan tetap waspada dan terus\n"
	.string "mengejar TEAM MAGMA.\p"
	.string "{PLAYER}, kita akan bertemu lagi!$"

MtChimney_Text_MagmaOutnumbersUs:
	.string "Sial… TEAM MAGMA lebih banyak dari kami!\n"
	.string "Kami tidak bisa mengimbangi mereka!$"

MtChimney_Text_LessHabitatForWaterPokemon:
	.string "Jika mereka memperluas daratan, akan ada\n"
	.string "lebih sedikit habitat untuk POKéMON AIR!$"

MtChimney_Text_MagmasNameSimilar:
	.string "Kami TEAM AQUA!\p"
	.string "Mereka TEAM MAGMA!\p"
	.string "Aku sangat kesal karena mereka menggunakan\n"
	.string "nama yang membingungkan seperti itu!$"

MtChimney_Text_Bushaa:
	.string "Bushaa!$"

MtChimney_Text_LavaCookiesJust200:
	.string "KUE LAVA adalah makanan khas\n"
	.string "GUNUNG CHIMNEY.\p"
	.string "Cobalah satu. Harganya hanya ¥200.$"

MtChimney_Text_ThankYouDear:
	.string "Terima kasih, sayang!$"

MtChimney_Text_YouveNotGotTheMoney:
	.string "Oh, sayang. Kamu tidak bisa membeli apa pun jika\n"
	.string "kamu tidak punya uang.$"

MtChimney_Text_OhFineThen:
	.string "Oh, baiklah kalau begitu.$"

MtChimney_Text_MetoriteFittedOnMachine:
	.string "Sebuah METEORITE terpasang pada mesin\n"
	.string "misterius…\p"
	.string "Mesin itu sepertinya menyimpan\n"
	.string "energi di dalam METEORITE.$"

MtChimney_Text_RemoveTheMeteorite:
	.string "Sebuah METEORITE terpasang pada mesin\n"
	.string "misterius…\p"
	.string "Apakah kamu ingin melepaskan METEORITE?$"

MtChimney_Text_PlayerRemovedMeteorite:
	.string "{PLAYER} melepaskan METEORITE dari\n"
	.string "mesin misterius itu.$"

MtChimney_Text_PlayerLeftMeteorite:
	.string "{PLAYER} meninggalkan METEORITE di\n"
	.string "tempatnya.$"

MtChimney_Text_MachineMakesNoResponse:
	.string "Mesin misterius ini…\n"
	.string "Tidak ada respons sama sekali.$"

MtChimney_Text_RouteSign:
	.string "{DOWN_ARROW} JALUR BERBATU\n"
	.string "KOTA LAVARIDGE DI DEPAN$"

MtChimney_Text_ShelbyIntro:
	.string "Aku sudah ke pemandian air panas dan\n"
	.string "menyegarkan tulang-tulangku yang lelah.\l"
	.string "Saat ini Aku merasa kuat!$"

MtChimney_Text_ShelbyDefeat:
	.string "Ya ampun.\n"
	.string "Kamu sungguh luar biasa!$"

MtChimney_Text_ShelbyPostBattle:
	.string "Yah, yah, Aku kalah. Aku tidak bisa menyebut\n"
	.string "diriku seorang AHLI sekarang, kan?$"

MtChimney_Text_ShelbyRegister:
	.string "Terima kasih, nak. Itu menyenangkan, seolah\n"
	.string "Aku bertarung dengan cucuku sendiri.\p"
	.string "Tolong, datanglah menemuiku lagi untuk\n"
	.string "pertandingan ulang.$"

MtChimney_Text_ShelbyRematchIntro:
	.string "Jika kamu bisa menyatukan hatimu dengan\n"
	.string "POKéMON-mu, maka kamu seharusnya\l"
	.string "bisa mencapai hal-hal besar.$"

MtChimney_Text_ShelbyRematchDefeat:
	.string "Ya ampun.\n"
	.string "Kamu sungguh luar biasa!$"

MtChimney_Text_ShelbyPostRematch:
	.string "Mungkin hatimu telah menyatu\n"
	.string "dengan hati POKéMON-mu.$"

MtChimney_Text_MelissaIntro:
	.string "Aku punya api di dalam diriku, sayang.\n"
	.string "Aku tidak tahan! Aku harus bertarung!$"

MtChimney_Text_MelissaDefeat:
	.string "Ooh, itu adalah pertandingan yang sangat panas!$"

MtChimney_Text_MelissaPostBattle:
	.string "Panasnya GUNUNG CHIMNEY menghangatkan\n"
	.string "diriku, sayang!$"

MtChimney_Text_SheilaIntro:
	.string "Aku akhirnya sampai di GUNUNG CHIMNEY.\n"
	.string "Aku ingin POKéMON-ku bertarung!$"

MtChimney_Text_SheilaDefeat:
	.string "Caramu bertarung…\n"
	.string "Ini seperti letusan GUNUNG CHIMNEY!$"

MtChimney_Text_SheilaPostBattle:
	.string "Seperti yang Aku katakan, Aku akhirnya sampai di\n"
	.string "GUNUNG CHIMNEY. Sayang sekali jika\l"
	.string "Aku hanya sedikit melihat-lihat…\p"
	.string "Aku ingin bertarung dan membeli\n"
	.string "KUE sebagai suvenir.$"

MtChimney_Text_ShirleyIntro:
	.string "Sejak Aku mandi di pemandian air panas,\n"
	.string "Aku merasa sangat baik!\l"
	.string "Aku yakin Aku akan menang!$"

MtChimney_Text_ShirleyDefeat:
	.string "Aduh!\n"
	.string "Aku kedinginan setelah keluar dari air.$"

MtChimney_Text_ShirleyPostBattle:
	.string "Aku harus berendam lagi di pemandian\n"
	.string "air panas. Mau ikut?\p"
	.string "Hanya bercanda!$"

MtChimney_Text_SawyerIntro:
	.string "Ini adalah gunung yang indah! Banyak\n"
	.string "orang-orang bersemangat di sekitar sini!$"

MtChimney_Text_SawyerDefeat:
	.string "Oh, kamu juga sangat bersemangat!$"

MtChimney_Text_SawyerPostBattle:
	.string "Aku rasa Aku perlu berendam di\n"
	.string "PEMANDIAN AIR PANAS LAVARIDGE bersama penduduk setempat!$"

MtChimney_Text_SawyerRegister:
	.string "Aku suka bola api kecil sepertimu.\n"
	.string "Biarkan Aku mendaftarkanmu di POKéNAV-ku.$"

MtChimney_Text_SawyerRematchIntro:
	.string "Aku senang dikelilingi oleh orang-orang bersemangat\n"
	.string "di sekitar sini. Aku tidak akan kalah!$"

MtChimney_Text_SawyerRematchDefeat:
	.string "Astaga, kamu masih sama\n"
	.string "bersemangatnya seperti sebelumnya!$"

MtChimney_Text_SawyerPostRematch:
	.string "Sebenarnya, di sini memang panas.\n"
	.string "Aku terlalu berlebihan berpakaian untuk daerah ini.$"
