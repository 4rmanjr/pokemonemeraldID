SeafloorCavern_Room4_MapScripts::
	.byte 0

SeafloorCavern_Room4_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_3, SeafloorCavern_Room4_Text_Grunt3Intro, SeafloorCavern_Room4_Text_Grunt3Defeat
	msgbox SeafloorCavern_Room4_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room4_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_4, SeafloorCavern_Room4_Text_Grunt4Intro, SeafloorCavern_Room4_Text_Grunt4Defeat
	msgbox SeafloorCavern_Room4_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room4_Text_Grunt3Intro:
	.string "Siapa kamu?\n"
	.string "Dari mana kamu datang?$"

SeafloorCavern_Room4_Text_Grunt3Defeat:
	.string "Kalah…$"

SeafloorCavern_Room4_Text_Grunt3PostBattle:
	.string "Aku tidak bisa menemukan jalan keluar!\p"
	.string "Aku tidak takut. Jangan salah paham!$"

SeafloorCavern_Room4_Text_Grunt4Intro:
	.string "Siapa kamu?\n"
	.string "Mau ke mana kamu?$"

SeafloorCavern_Room4_Text_Grunt4Defeat:
	.string "Aku gagal menang!$"

SeafloorCavern_Room4_Text_Grunt4PostBattle:
	.string "Partnerku lupa peta di kapal\n"
	.string "selam itu!\p"
	.string "Betapa tidak berguna dia!$"

