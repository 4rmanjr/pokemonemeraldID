//gemini
Route110_TrickHousePuzzle8_MapScripts::
	.byte 0

Route110_TrickHousePuzzle8_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_8_STATE, 0, Route110_TrickHousePuzzle8_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle8_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_8_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle8_EventScript_Vincent::
	trainerbattle_single TRAINER_VINCENT, Route110_TrickHousePuzzle8_Text_VincentIntro, Route110_TrickHousePuzzle8_Text_VincentDefeat
	msgbox Route110_TrickHousePuzzle8_Text_VincentPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_EventScript_Keira::
	trainerbattle_single TRAINER_KEIRA, Route110_TrickHousePuzzle8_Text_KeiraIntro, Route110_TrickHousePuzzle8_Text_KeiraDefeat
	msgbox Route110_TrickHousePuzzle8_Text_KeiraPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_EventScript_Leroy::
	trainerbattle_single TRAINER_LEROY, Route110_TrickHousePuzzle8_Text_LeroyIntro, Route110_TrickHousePuzzle8_Text_LeroyDefeat
	msgbox Route110_TrickHousePuzzle8_Text_LeroyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_Text_WroteSecretCodeLockOpened::
	.string "{PLAYER} menuliskan kode rahasia di\n"
	.string "pintu.\p"
	.string "“Aku cinta TRICK MASTER.……………………\p"
	.string "Kuncinya terbuka!$"

Route110_TrickHousePuzzle8_Text_VincentIntro:
	.string "Tidak banyak TRAINER yang berhasil\n"
	.string "sejauh ini.$"

Route110_TrickHousePuzzle8_Text_VincentDefeat:
	.string "Itu berarti Kamu juga tangguh…$"

Route110_TrickHousePuzzle8_Text_VincentPostBattle:
	.string "Kamu mengalahkan JUARA LIGA POKéMON?\n"
	.string "Itu keterlaluan!$"

Route110_TrickHousePuzzle8_Text_KeiraIntro:
	.string "Anggap dirimu beruntung karena\n"
	.string "bertarung denganku!$"

Route110_TrickHousePuzzle8_Text_KeiraDefeat:
	.string "Ini tidak benar! Aku tidak boleh\n"
	.string "kalah!$"

Route110_TrickHousePuzzle8_Text_KeiraPostBattle:
	.string "Keajaiban Kamu mengalahkanku. Kamu\n"
	.string "bisa membual tentang itu.$"

Route110_TrickHousePuzzle8_Text_LeroyIntro:
	.string "Kamu juga berjuang keras melalui\n"
	.string "tantangan TRICK HOUSE.$"

Route110_TrickHousePuzzle8_Text_LeroyDefeat:
	.string "Aku mengerti… Kamu punya gaya yang\n"
	.string "luar biasa.$"

Route110_TrickHousePuzzle8_Text_LeroyPostBattle:
	.string "Melihat seseorang sepertimu\n"
	.string "seharusnya menyenangkan TRICK MASTER.$"
