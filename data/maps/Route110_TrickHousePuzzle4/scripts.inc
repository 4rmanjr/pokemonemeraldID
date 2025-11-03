//gemini
Route110_TrickHousePuzzle4_MapScripts::
	.byte 0

Route110_TrickHousePuzzle4_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_4_STATE, 0, Route110_TrickHousePuzzle4_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle4_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_4_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle4_EventScript_Cora::
	trainerbattle_single TRAINER_CORA, Route110_TrickHousePuzzle4_Text_CoraIntro, Route110_TrickHousePuzzle4_Text_CoraDefeat
	msgbox Route110_TrickHousePuzzle4_Text_CoraPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_EventScript_Yuji::
	trainerbattle_single TRAINER_YUJI, Route110_TrickHousePuzzle4_Text_YujiIntro, Route110_TrickHousePuzzle4_Text_YujiDefeat
	msgbox Route110_TrickHousePuzzle4_Text_YujiPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_EventScript_Paula::
	trainerbattle_single TRAINER_PAULA, Route110_TrickHousePuzzle4_Text_PaulaIntro, Route110_TrickHousePuzzle4_Text_PaulaDefeat
	msgbox Route110_TrickHousePuzzle4_Text_PaulaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_Text_WroteSecretCodeLockOpened:
	.string "{PLAYER} menuliskan kode rahasia itu\n"
	.string "di pintu.\p"
	.string "“TRICK MASTER itu keren.……………………\p"
	.string "Kunci itu terbuka!$"

Route110_TrickHousePuzzle4_Text_CoraIntro:
	.string "Terlalu merepotkan untuk memikirkan\n"
	.string "ini. Aku cuma ingin bertarung!$"

Route110_TrickHousePuzzle4_Text_CoraDefeat:
	.string "Meskipun Aku kalah, Aku masih paling\n"
	.string "suka bertarung!$"

Route110_TrickHousePuzzle4_Text_CoraPostBattle:
	.string "Bukankah kamu setuju? Kamu akan pergi\n"
	.string "ke mana pun jika ada TRAINER di sana.$"

Route110_TrickHousePuzzle4_Text_YujiIntro:
	.string "Heh! Batu besar seperti ini, Aku bisa\n"
	.string "singkirkan hanya dengan satu jari!$"

Route110_TrickHousePuzzle4_Text_YujiDefeat:
	.string "Aku bisa mendorong batu besar, tapi\n"
	.string "Aku tak bisa memecahkan teka-teki…$"

Route110_TrickHousePuzzle4_Text_YujiPostBattle:
	.string "Tidak cukup hanya dengan berotot…\n"
	.string "Kamu harus menggunakan kepalamu.\l"
	.string "Jadilah pintar!$"

Route110_TrickHousePuzzle4_Text_PaulaIntro:
	.string "TRICK HOUSE semakin sulit, bukan?$"

Route110_TrickHousePuzzle4_Text_PaulaDefeat:
	.string "Aaak!$"

Route110_TrickHousePuzzle4_Text_PaulaPostBattle:
	.string "Apakah ada yang sudah sampai akhir?$"
