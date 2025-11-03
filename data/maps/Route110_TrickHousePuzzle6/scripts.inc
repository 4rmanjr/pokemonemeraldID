//gemini
Route110_TrickHousePuzzle6_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle6_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route110_TrickHousePuzzle6_OnWarp
	.byte 0

Route110_TrickHousePuzzle6_OnTransition:
	special RotatingGate_InitPuzzle
	end

Route110_TrickHousePuzzle6_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, Route110_TrickHousePuzzle6_EventScript_InitPuzzle
	.2byte 0

@ NOTE: This rotating gate puzzle makes use of VAR_TEMP_0 - VAR_TEMP_5
Route110_TrickHousePuzzle6_EventScript_InitPuzzle::
	special RotatingGate_InitPuzzleAndGraphics
	end

Route110_TrickHousePuzzle6_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_6_STATE, 0, Route110_TrickHousePuzzle6_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle6_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_6_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle6_EventScript_Sophia::
	trainerbattle_single TRAINER_SOPHIA, Route110_TrickHousePuzzle6_Text_SophiaIntro, Route110_TrickHousePuzzle6_Text_SophiaDefeat
	msgbox Route110_TrickHousePuzzle6_Text_SophiaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_EventScript_Benny::
	trainerbattle_single TRAINER_BENNY, Route110_TrickHousePuzzle6_Text_BennyIntro, Route110_TrickHousePuzzle6_Text_BennyDefeat
	msgbox Route110_TrickHousePuzzle6_Text_BennyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_EventScript_Sebastian::
	trainerbattle_single TRAINER_SEBASTIAN, Route110_TrickHousePuzzle6_Text_SebastianIntro, Route110_TrickHousePuzzle6_Text_SebastianDefeat
	msgbox Route110_TrickHousePuzzle6_Text_SebastianPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_Text_WroteSecretCodeLockOpened:
	.string "{PLAYER} menuliskan kode rahasia di\n"
	.string "pintu.\p"
	.string "“TRICK MASTER adalah hidupku.……………………\p"
	.string "Kuncinya terbuka dengan bunyi klik!$"

Route110_TrickHousePuzzle6_Text_SophiaIntro:
	.string "Ketika kudengar ada rumah aneh, Aku\n"
	.string "harus memeriksanya.$"

Route110_TrickHousePuzzle6_Text_SophiaDefeat:
	.string "Aku telah menemukan seorang TRAINER\n"
	.string "tangguh!$"

Route110_TrickHousePuzzle6_Text_SophiaPostBattle:
	.string "Aku yakin Aku bersenang-senang\n"
	.string "memeriksa tempat ini.\p"
	.string "Ini adalah tantangan yang Aku rasa\n"
	.string "pantas diulang!$"

Route110_TrickHousePuzzle6_Text_BennyIntro:
	.string "Mungkin Aku bisa membuat POKéMON\n"
	.string "BURUNG-ku terbang melewati tembok…$"

Route110_TrickHousePuzzle6_Text_BennyDefeat:
	.string "Gwaaah! Aku gagal!$"

Route110_TrickHousePuzzle6_Text_BennyPostBattle:
	.string "Ehehehe… Kurasa Aku kalah karena Aku\n"
	.string "mencoba curang.$"

Route110_TrickHousePuzzle6_Text_SebastianIntro:
	.string "Aku pusing karena pintu berputar ini…$"

Route110_TrickHousePuzzle6_Text_SebastianDefeat:
	.string "Semuanya berputar-putar. Aku tidak\n"
	.string "tahan lagi…$"

Route110_TrickHousePuzzle6_Text_SebastianPostBattle:
	.string "Kamu tampaknya tidak terpengaruh sama\n"
	.string "sekali. Atau Kamu memasang muka datar?$"
