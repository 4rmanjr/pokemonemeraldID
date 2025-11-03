SeafloorCavern_Room3_MapScripts::
	.byte 0

SeafloorCavern_Room3_EventScript_Shelly::
	trainerbattle_single TRAINER_SHELLY_SEAFLOOR_CAVERN, SeafloorCavern_Room3_Text_ShellyIntro, SeafloorCavern_Room3_Text_ShellyDefeat
	msgbox SeafloorCavern_Room3_Text_ShellyPostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_5, SeafloorCavern_Room3_Text_Grunt5Intro, SeafloorCavern_Room3_Text_Grunt5Defeat
	msgbox SeafloorCavern_Room3_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_Text_ShellyIntro:
	.string "Ahahahaha!\p"
	.string "Bagaimana kamu bisa sampai ke sini\n"
	.string "tanpa kapal selam?\l"
	.string "Sungguh anak yang mengesankan!\p"
	.string "Tapi… Aku tidak akan membiarkanmu\n"
	.string "ikut campur di sini.\p"
	.string "Dan, aku ingin balas dendam atas apa\n"
	.string "yang terjadi di WEATHER INSTITUTE…\p"
	.string "Aku akan memberimu sedikit rasa\n"
	.string "sakit! Pasrahkan dirimu!$"

SeafloorCavern_Room3_Text_ShellyDefeat:
	.string "Ahahahaha!\p"
	.string "Aduh!$"

SeafloorCavern_Room3_Text_ShellyPostBattle:
	.string "Ahahahaha!\n"
	.string "Kamu sangat kuat.\p"
	.string "Sangat mengecewakan kamu bukan\n"
	.string "anggota TEAM AQUA.\p"
	.string "Kamu bisa saja menikmati dunia luar biasa\n"
	.string "yang dijanjikan BOS kami sebagai\l"
	.string "salah satu dari kami…$"

SeafloorCavern_Room3_Text_Grunt5Intro:
	.string "Agar impian kami menjadi nyata, kami\n"
	.string "membutuhkan kekuatan POKéMON.\p"
	.string "Tapi pengganggu sepertimu menggunakan\n"
	.string "kekuatan POKéMON untuk mengganggu kami\l"
	.string "bahkan di tempat seperti ini!\p"
	.string "Hidup tidak berjalan sesuai keinginan\n"
	.string "kami!$"

SeafloorCavern_Room3_Text_Grunt5Defeat:
	.string "Gwah!$"

SeafloorCavern_Room3_Text_Grunt5PostBattle:
	.string "Kamu tahu, kami tidak berani\n"
	.string "mempertanyakan motif pemimpin kami.\p"
	.string "Tapi di sini kamu, hanya seorang anak\n"
	.string "nakal, melawan BOS kami.\p"
	.string "Mungkin…\n"
	.string "Kamu pasti sesuatu…$"

