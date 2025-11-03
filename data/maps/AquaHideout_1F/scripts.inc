//gemini
AquaHideout_1F_MapScripts::
	.byte 0

@ The below two entrance guards give hints about what to do to progress the story
AquaHideout_1F_EventScript_HideoutEntranceGrunt1::
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint1
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint1
	msgbox AquaHideout_1F_Text_OurBossIsSnatchingSomething, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint1::
	msgbox AquaHideout_1F_Text_WhereMightMagmaHideoutBe, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint1::
	msgbox AquaHideout_1F_Text_BossWentToJackASubmarine, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_HideoutEntranceGrunt2::
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint2
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint2
	msgbox AquaHideout_1F_Text_BossIsOnRoute122, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint2::
	msgbox AquaHideout_1F_Text_TeamMagmaAtMtChimney, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint2::
	msgbox AquaHideout_1F_Text_BossIsInSlateportCity, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_1, AquaHideout_1F_Text_Grunt1Intro, AquaHideout_1F_Text_Grunt1Defeat, AquaHideout_1F_EventScript_Grunt1Defeated
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_1F_EventScript_Grunt1Defeated::
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_Text_OurBossIsSnatchingSomething:
	.string "Apa? Apa? Apa mau Kamu dengan TIM\n"
	.string "AQUA?\p"
	.string "BOS kami tidak ada! Dia pergi untuk\n"
	.string "mengambil sesuatu yang penting!\p"
	.string "… … Ke mana dia pergi?\p"
	.string "Wahaha! Apa Kamu benar-benar\n"
	.string "berpikir aku akan memberitahu Kamu\l"
	.string "hal sepenting itu?$"

AquaHideout_1F_Text_WhereMightMagmaHideoutBe:
	.string "Apa? Apa? Apa Kamu anggota rendahan\n"
	.string "TIM MAGMA?\p"
	.string "Aku dengar TIM MAGMA berusaha\n"
	.string "membangunkan POKéMON hebat di\l"
	.string "MARKAS mereka.\p"
	.string "Tapi di mana kira-kira MARKAS\n"
	.string "mereka?$"

AquaHideout_1F_Text_BossWentToJackASubmarine:
	.string "Apa? Apa? Apa mau Kamu dengan TIM\n"
	.string "AQUA?\p"
	.string "BOS kami tidak ada! Dia pergi untuk\n"
	.string "merampas kapal selam!\p"
	.string "… … Ke mana dia pergi?\p"
	.string "Wahaha! Apa Kamu benar-benar\n"
	.string "berpikir aku akan memberitahu Kamu\l"
	.string "hal sepenting itu?$"

AquaHideout_1F_Text_BossIsOnRoute122:
	.string "Apa? Apa? Apa mau Kamu dengan TIM\n"
	.string "AQUA?\p"
	.string "BOS kami tidak ada! Dia sedang\n"
	.string "menuju ke G.N. ABU di RUTE 122!\p"
	.string "… … Mengapa dia pergi?\p"
	.string "Wahaha! Apa Kamu benar-benar\n"
	.string "berpikir aku akan memberitahu Kamu\l"
	.string "hal sepenting itu?$"

AquaHideout_1F_Text_TeamMagmaAtMtChimney:
	.string "Apa? Apa? Apa Kamu anggota rendahan\n"
	.string "TIM MAGMA?\p"
	.string "Aku dengar TIM MAGMA mengincar\n"
	.string "POKéMON hebat di G. CEROBONG.\p"
	.string "Tapi POKéMON seperti apa itu?$"

AquaHideout_1F_Text_BossIsInSlateportCity:
	.string "Apa? Apa? Apa mau Kamu dengan TIM\n"
	.string "AQUA?\p"
	.string "BOS kami tidak ada! Dia sedang\n"
	.string "menuju ke KOTA SLATEPORT!\p"
	.string "… … Mengapa dia pergi?\p"
	.string "Wahaha! Apa Kamu benar-benar\n"
	.string "berpikir aku akan memberitahu Kamu\l"
	.string "hal sepenting itu?$"

AquaHideout_1F_Text_Grunt1Intro:
	.string "Ayiyiyi! Karakter mencurigakan\n"
	.string "terdeteksi!$"

AquaHideout_1F_Text_Grunt1Defeat:
	.string "Grrrrr… Aku kalah!$"

AquaHideout_1F_Text_Grunt1PostBattle:
	.string "Aku kalah demi TIM, tapi aku sudah\n"
	.string "melakukan tugasku…$"
