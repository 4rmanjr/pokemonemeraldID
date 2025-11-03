//gemini
Route110_TrickHousePuzzle1_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route110_TrickHousePuzzle1_OnLoad
	.byte 0

Route110_TrickHousePuzzle1_OnLoad:
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 2, Route110_TrickHousePuzzle1_EventScript_OpenDoor
	end

Route110_TrickHousePuzzle1_EventScript_OpenDoor::
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	end

Route110_TrickHousePuzzle1_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 0, Route110_TrickHousePuzzle1_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle1_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_1_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle1_EventScript_Sally::
	trainerbattle_single TRAINER_SALLY, Route110_TrickHousePuzzle1_Text_SallyIntro, Route110_TrickHousePuzzle1_Text_SallyDefeat
	msgbox Route110_TrickHousePuzzle1_Text_SallyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_EventScript_Eddie::
	trainerbattle_single TRAINER_EDDIE, Route110_TrickHousePuzzle1_Text_EddieIntro, Route110_TrickHousePuzzle1_Text_EddieDefeat
	msgbox Route110_TrickHousePuzzle1_Text_EddiePostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_EventScript_Robin::
	trainerbattle_single TRAINER_ROBIN, Route110_TrickHousePuzzle1_Text_RobinIntro, Route110_TrickHousePuzzle1_Text_RobinDefeat
	msgbox Route110_TrickHousePuzzle1_Text_RobinPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_Text_WroteSecretCodeLockOpened::
	.string "{PLAYER} menuliskan kode rahasia di\n"
	.string "pintu.\p"
	.string "“TRICK MASTER luar biasa.……………………\p"
	.string "Kuncinya terbuka!$"

Route110_TrickHousePuzzle1_Text_SallyIntro:
	.string "Aku akan menebas dan meretas jalanku\n"
	.string "menuju kemenangan dengan CUT yang\l"
	.string "baru saja kita pelajari!$"

Route110_TrickHousePuzzle1_Text_SallyDefeat:
	.string "Mengapa Kamu begitu serius?$"

Route110_TrickHousePuzzle1_Text_SallyPostBattle:
	.string "Aku tidak pernah bosan menebas dan\n"
	.string "meretas!$"

Route110_TrickHousePuzzle1_Text_EddieIntro:
	.string "Aku tersesat ke rumah aneh ini secara\n"
	.string "tidak sengaja…$"

Route110_TrickHousePuzzle1_Text_EddieDefeat:
	.string "Dan sekarang Aku kalah…$"

Route110_TrickHousePuzzle1_Text_EddiePostBattle:
	.string "Aku tersesat, Aku kalah dalam\n"
	.string "pertarungan, dan sekarang Aku bahkan\l"
	.string "lebih tersesat lagi… Aku tidak bisa\l"
	.string "keluar…$"

Route110_TrickHousePuzzle1_Text_RobinIntro:
	.string "Sebenarnya siapa TRICK MASTER itu?$"

Route110_TrickHousePuzzle1_Text_RobinDefeat:
	.string "Aku kalah saat Aku sedang melamun!$"

Route110_TrickHousePuzzle1_Text_RobinPostBattle:
	.string "Kamu kuat! Sebenarnya siapa Kamu?$"
