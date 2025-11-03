JaggedPass_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, JaggedPass_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, JaggedPass_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, JaggedPass_OnLoad
	.byte 0

JaggedPass_OnResume:
	setstepcallback STEP_CB_ASH
	call_if_eq VAR_JAGGED_PASS_STATE, 0, JaggedPass_EventScript_CheckHasMagmaEmblem
	end

JaggedPass_EventScript_CheckHasMagmaEmblem::
	checkitem ITEM_MAGMA_EMBLEM
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_SetReadyToOpenHideout
	return

JaggedPass_EventScript_SetReadyToOpenHideout::
	setvar VAR_JAGGED_PASS_STATE, 1
	return

JaggedPass_OnTransition:
	call_if_eq VAR_JAGGED_PASS_ASH_WEATHER, 1, JaggedPass_EventScript_SetWeatherAsh
	end

JaggedPass_EventScript_SetWeatherAsh::
	setweather WEATHER_VOLCANIC_ASH
	doweather
	return

JaggedPass_OnLoad:
	goto_if_le VAR_JAGGED_PASS_STATE, 1, JaggedPass_EventScript_ConcealHideoutEntrance
	end

JaggedPass_EventScript_ConcealHideoutEntrance::
	setmetatile 16, 17, METATILE_Lavaridge_RockWall, TRUE
	setmetatile 16, 18, METATILE_Lavaridge_RockWall, TRUE
	end

JaggedPass_EventScript_OpenMagmaHideout::
	lockall
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	msgbox JaggedPass_Text_BoulderShakingInResponseToEmblem, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 1   @ vertical pan
	setvar VAR_0x8005, 1   @ horizontal pan
	setvar VAR_0x8006, 16  @ num shakes
	setvar VAR_0x8007, 3   @ shake delay
	special ShakeCamera
	waitstate
	playse SE_EFFECTIVE
	setmetatile 16, 17, METATILE_Lavaridge_CaveEntrance_Top, TRUE
	setmetatile 16, 18, METATILE_Lavaridge_CaveEntrance_Bottom, FALSE
	special DrawWholeMapView
	delay 30
	setvar VAR_JAGGED_PASS_STATE, 2
	waitse
	releaseall
	end

JaggedPass_EventScript_MagmaHideoutGuard::
	lockall
	goto_if_set FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS, JaggedPass_EventScript_GuardDefeated
	waitse
	playse SE_PIN
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox JaggedPass_Text_GruntIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_GRUNT_JAGGED_PASS, JaggedPass_Text_GruntDefeat
	setflag FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

JaggedPass_EventScript_GuardDefeated::
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox JaggedPass_Text_GoWhereverYouWant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

JaggedPass_EventScript_Eric::
	trainerbattle_single TRAINER_ERIC, JaggedPass_Text_EricIntro, JaggedPass_Text_EricDefeat
	msgbox JaggedPass_Text_EricPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Diana::
	trainerbattle_single TRAINER_DIANA_1, JaggedPass_Text_DianaIntro, JaggedPass_Text_DianaDefeat, JaggedPass_EventScript_RegisterDiana
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_DianaRematch
	msgbox JaggedPass_Text_DianaPostBattle, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_RegisterDiana::
	special PlayerFaceTrainerAfterBattle
	msgbox JaggedPass_Text_DianaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DIANA_1
	release
	end

JaggedPass_EventScript_DianaRematch::
	trainerbattle_rematch TRAINER_DIANA_1, JaggedPass_Text_DianaRematchIntro, JaggedPass_Text_DianaRematchDefeat
	msgbox JaggedPass_Text_DianaPostRematch, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Ethan::
	trainerbattle_single TRAINER_ETHAN_1, JaggedPass_Text_EthanIntro, JaggedPass_Text_EthanDefeat, JaggedPass_EventScript_RegisterEthan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_EthanRematch
	msgbox JaggedPass_Text_EthanPostBattle, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_RegisterEthan::
	special PlayerFaceTrainerAfterBattle
	msgbox JaggedPass_Text_EthanRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ETHAN_1
	release
	end

JaggedPass_EventScript_EthanRematch::
	trainerbattle_rematch TRAINER_ETHAN_1, JaggedPass_Text_EthanRematchIntro, JaggedPass_Text_EthanRematchDefeat
	msgbox JaggedPass_Text_EthanPostRematch, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Julio::
	trainerbattle_single TRAINER_JULIO, JaggedPass_Text_JulioIntro, JaggedPass_Text_JulioDefeat
	msgbox JaggedPass_Text_JulioPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Autumn::
	trainerbattle_single TRAINER_AUTUMN, JaggedPass_Text_AutumnIntro, JaggedPass_Text_AutumnDefeat
	msgbox JaggedPass_Text_AutumnPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_Text_EricIntro:
	.string "JAGGED PASS di MT. CHIMNEY…\p"
	.string "Nah, gunung seperti inilah yang\n"
	.string "selalu kuinginkan.\p"
	.string "Jalanan terjal dan bergelombang ini…\n"
	.string "Mengguncang jiwaku!$"

JaggedPass_Text_EricDefeat:
	.string "Kalah membuatku kesal!$"

JaggedPass_Text_EricPostBattle:
	.string "Ya, aku memang kalah…\p"
	.string "Tapi, soal cinta pada gunung, aku\n"
	.string "menang darimu!$"

JaggedPass_Text_DianaIntro:
	.string "Tempat ini bukan untuk pendakian\n"
	.string "santai. Tidak cocok untuk piknik.$"

JaggedPass_Text_DianaDefeat:
	.string "Ohhh, tidak!\n"
	.string "Tanahnya terlalu bergelombang…$"

JaggedPass_Text_DianaPostBattle:
	.string "Apa kamu tahu?\p"
	.string "Beberapa orang dengan cerdik\n"
	.string "mengendarai sepeda mereka melewati\l"
	.string "jalur yang sangat bergelombang ini.$"

JaggedPass_Text_DianaRegister:
	.string "Apa kamu akan kembali ke area ini?\n"
	.string "Jika iya, aku ingin tanding ulang.$"

JaggedPass_Text_DianaRematchIntro:
	.string "Piknik itu menyenangkan di mana saja.\n"
	.string "Sama seperti POKéMON!$"

JaggedPass_Text_DianaRematchDefeat:
	.string "Aku kalah hanya karena tanahnya\n"
	.string "terlalu bergelombang!$"

JaggedPass_Text_DianaPostRematch:
	.string "Akan kulupakan kekalahan ini dan\n"
	.string "nikmati saja pendakian ini.$"

JaggedPass_Text_EthanIntro:
	.string "JAGGED PASS sulit untuk dilalui.\n"
	.string "Ini tempat yang bagus untuk berlatih.$"

JaggedPass_Text_EthanDefeat:
	.string "Semuanya berakhir saat kami masih\n"
	.string "mencari pijakan yang bagus…$"

JaggedPass_Text_EthanPostBattle:
	.string "Kalau aku punya ACRO BIKE, aku bisa\n"
	.string "melompati tepian.$"

JaggedPass_Text_EthanRegister:
	.string "Saat aku sudah terbiasa dengan\n"
	.string "jalanan ini, aku pasti akan menang!\p"
	.string "Bisakah kamu mendaftarkanku di\n"
	.string "POKéNAV-mu?$"

JaggedPass_Text_EthanRematchIntro:
	.string "Aku sudah terbiasa dengan jalanan\n"
	.string "ini. Sekarang aku bernyanyi sambil\l"
	.string "mendaki.$"

JaggedPass_Text_EthanRematchDefeat:
	.string "Masih tidak mudah bertarung di tanah\n"
	.string "yang bergelombang ini…$"

JaggedPass_Text_EthanPostRematch:
	.string "Seharusnya aku mendapatkan ACRO BIKE\n"
	.string "dari RYDEL di KOTA MAUVILLE…$"

JaggedPass_Text_GruntIntro:
	.string "Wah!\n"
	.string "Sedang apa kamu di sini?\p"
	.string "Apa yang kulakukan di sini?\p"
	.string "Bukan urusanmu!$"

JaggedPass_Text_GruntDefeat:
	.string "Urrrgh…\p"
	.string "Seharusnya aku langsung masuk ke\n"
	.string "MARKAS kami…$"

JaggedPass_Text_GoWhereverYouWant:
	.string "Oke, oke!\n"
	.string "Aku akui--kamu kuat!\p"
	.string "Jangan khawatirkan aku.\n"
	.string "Pergilah ke mana pun kamu mau!$"

JaggedPass_Text_BoulderShakingInResponseToEmblem:
	.string "Oh! Batu besar ini bergetar\n"
	.string "merespon MAGMA EMBLEM!$"

JaggedPass_Text_JulioIntro:
	.string "Aiyeeh! Mengerikan sekali menuruni\n"
	.string "gunung ini dalam sekali jalan!$"

JaggedPass_Text_JulioDefeat:
	.string "Aku merasa hancur berkeping-keping…$"

JaggedPass_Text_JulioPostBattle:
	.string "Sepedaku terpental-pental, bokongku\n"
	.string "jadi sakit…$"

JaggedPass_Text_AutumnIntro:
	.string "Aku mendaki bukit ini setiap hari.\n"
	.string "Aku percaya pada kekuatanku!$"

JaggedPass_Text_AutumnDefeat:
	.string "Hmm…\n"
	.string "Apa yang salah?$"

JaggedPass_Text_AutumnPostBattle:
	.string "Tonjolan batu aneh apa itu yang ada\n"
	.string "sedikit di atas bukit dari sini?$"

