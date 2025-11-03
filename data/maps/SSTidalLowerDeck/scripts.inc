//gemini
SSTidalLowerDeck_MapScripts::
	.byte 0

SSTidalLowerDeck_EventScript_Phillip::
	trainerbattle_single TRAINER_PHILLIP, SSTidalLowerDeck_Text_PhillipIntro, SSTidalLowerDeck_Text_PhillipDefeat
	msgbox SSTidalLowerDeck_Text_PhillipPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalLowerDeck_EventScript_Leonard::
	trainerbattle_single TRAINER_LEONARD, SSTidalLowerDeck_Text_LeonardIntro, SSTidalLowerDeck_Text_LeonardDefeat
	msgbox SSTidalLowerDeck_Text_LeonardPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalLowerDeck_Text_PhillipIntro:
	.string "Arrrgh! Aku muak dan lelah sekali\n"
	.string "membersihkan tempat sebesar ini!\p"
	.string "Ayo kita bertarung sebentar!$"

SSTidalLowerDeck_Text_PhillipDefeat:
	.string "Adik, Aku kalah!$"

SSTidalLowerDeck_Text_PhillipPostBattle:
	.string "Kami adalah KAKAK BERADIK PEMBERSH!\p"
	.string "Yang tua menuangkan deterjen, dan\n"
	.string "yang muda melakukan penyikatan!$"

SSTidalLowerDeck_Text_LeonardIntro:
	.string "Ini adalah dasar lambung kapal.\n"
	.string "Tempatnya luas. Cocok untuk\l"
	.string "pertarungan POKéMON.$"

SSTidalLowerDeck_Text_LeonardDefeat:
	.string "Kakak, Aku kalah!$"

SSTidalLowerDeck_Text_LeonardPostBattle:
	.string "Kami adalah KAKAK BERADIK PEMBERSH!\p"
	.string "Yang tua menuangkan deterjen, dan\n"
	.string "yang muda melakukan penyikatan!$"
