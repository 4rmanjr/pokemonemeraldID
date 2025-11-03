SeafloorCavern_Room1_MapScripts::
	.byte 0

SeafloorCavern_Room1_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_1, SeafloorCavern_Room1_Text_Grunt1Intro, SeafloorCavern_Room1_Text_Grunt1Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_2, SeafloorCavern_Room1_Text_Grunt2Intro, SeafloorCavern_Room1_Text_Grunt2Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_Text_Grunt1Intro:
	.string "Kami tidak butuh anak kecil di sini!\n"
	.string "Pulang saja sana!$"

SeafloorCavern_Room1_Text_Grunt1Defeat:
	.string "Aku ingin pulang…$"

SeafloorCavern_Room1_Text_Grunt1PostBattle:
	.string "Aku ingin naik pangkat agar aku bisa\n"
	.string "memerintah GRUNT lain…$"

SeafloorCavern_Room1_Text_Grunt2Intro:
	.string "Kapal selam itu… Kecil sekali di dalamnya.\n"
	.string "Seluruh badanku pegal!$"

SeafloorCavern_Room1_Text_Grunt2Defeat:
	.string "Kalah membuatku pegal!$"

SeafloorCavern_Room1_Text_Grunt2PostBattle:
	.string "Kapal selam yang kami bajak itu, ya,\n"
	.string "perjalanannya sangat brutal.\l"
	.string "Terlalu sempit di dalamnya!$"

