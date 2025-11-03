//gemini
Route114_FossilManiacsHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsHouse_OnTransition
	.byte 0

Route114_FossilManiacsHouse_OnTransition:
	setflag FLAG_LANDMARK_FOSSIL_MANIACS_HOUSE
	end

Route114_FossilManiacsHouse_EventScript_FossilManiacsBrother::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_DIG, Route114_FossilManiacsHouse_EventScript_ReceivedDig
	msgbox Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother, MSGBOX_DEFAULT
	giveitem ITEM_TM_DIG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_DIG
	release
	end

Route114_FossilManiacsHouse_EventScript_ReceivedDig::
	msgbox Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsHouse_EventScript_RockDisplay::
	msgbox Route114_FossilManiacsHouse_Text_RocksFillDisplayCase, MSGBOX_SIGN
	end

Route114_FossilManiacsHouse_EventScript_Bookshelf::
	msgbox Route114_FossilManiacsHouse_Text_CrammedWithBooks, MSGBOX_SIGN
	end

Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother:
	.string "Kakakku adalah FOSSIL MANIAC… Dia\n"
	.string "orang baik yang menyukai FOSSILS…\p"
	.string "Dia juga suka menggali lubang… Dia\n"
	.string "menggali lubang ini sendirian…\p"
	.string "Kamu boleh ambil ini, agar Kamu bisa\n"
	.string "DIG lubang persis seperti kakakku…$"

Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance:
	.string "Jika Kamu membuat POKéMON melakukan\n"
	.string "DIG di dalam gua, Kamu akan\l"
	.string "dikembalikan ke pintu masuk…$"

Route114_FossilManiacsHouse_Text_RocksFillDisplayCase:
	.string "Batu-batu dengan bentuk aneh memenuhi\n"
	.string "kotak pajangan…$"

Route114_FossilManiacsHouse_Text_CrammedWithBooks:
	.string "KOMPOSISI LAPISAN TANAH… BAGAIMANA\n"
	.string "HUJAN MEMBENTUK DARATAN… BATU, TANAH,\l"
	.string "DAN BEBATUAN…\p"
	.string "Penuh sesak dengan buku.$"
