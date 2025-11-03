GraniteCave_1F_MapScripts::
	.byte 0

GraniteCave_1F_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_FLASH, GraniteCave_1F_EventScript_ReceivedFlash
	msgbox GraniteCave_1F_Text_GetsDarkAheadHereYouGo, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLASH
	setflag FLAG_RECEIVED_HM_FLASH
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_EventScript_ReceivedFlash::
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_Text_GetsDarkAheadHereYouGo:
	.string "Hei, kamu.\n"
	.string "Di depan sangat gelap.\l"
	.string "Akan sulit untuk menjelajah.\p"
	.string "Orang yang datang tadi…\n"
	.string "STEVEN, kalau tidak salah.\p"
	.string "Dia tahu cara menggunakan FLASH, jadi\n"
	.string "seharusnya dia baik-baik saja, tapi…\p"
	.string "Yah, bagi kami para HIKER, menolong\n"
	.string "orang yang kami temui adalah moto kami.\p"
	.string "Ini, akan kuberikan padamu.$"

GraniteCave_1F_Text_ExplainFlash:
	.string "Ajarkan jurus tersembunyi FLASH itu\n"
	.string "ke POKéMON dan gunakan.\p"
	.string "Itu akan menerangi bahkan kegelapan\n"
	.string "pekat di dalam gua.\p"
	.string "Tapi, untuk menggunakannya, kamu\n"
	.string "butuh LENCANA GYM dari GYM POKéMON\l"
	.string "DEWFORD.$"
