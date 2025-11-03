//gemini
Route111_WinstrateFamilysHouse_MapScripts::
	.byte 0

Route111_WinstrateFamilysHouse_EventScript_Victor::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICTOR
	msgbox Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Victoria::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICTORIA
	goto_if_set FLAG_RECEIVED_MACHO_BRACE, Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace
	msgbox Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace, MSGBOX_DEFAULT
	giveitem ITEM_MACHO_BRACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MACHO_BRACE
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace::
	msgbox Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vivi::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VIVI
	msgbox Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vicky::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICKY
	goto_if_set FLAG_TEMP_4, Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrong, MSGBOX_DEFAULT
	setflag FLAG_TEMP_4
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo::
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection::
	closemessage
	applymovement VAR_0x8008, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou:
	.string "Kamu adalah Trainer pertama yang Aku\n"
	.string "lihat menggunakan POKéMON begitu ahli.\l"
	.string "Tapi, Aku harus memberitahumu\l"
	.string "bahwa putraku lebih kuat\l"
	.string "darimu.\p"
	.string "Dia bahkan menghadapi tantangan\n"
	.string "POKéMON LEAGUE, harus kamu tahu.$"

Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace:
	.string "Kami menggunakan MACHO BRACE ini\n"
	.string "untuk memperkuat POKéMON kami lebih\l"
	.string "efektif dalam pelatihan.\p"
	.string "Karena kamu sudah mengalahkan kami\n"
	.string "semua di sini, Aku tidak tahu apakah\l"
	.string "kamu membutuhkannya, tapi kami ingin\l"
	.string "kamu memiliki MACHO BRACE kami.$"

Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles:
	.string "Dalam hal pertarungan POKéMON, kami\n"
	.string "cenderung sangat bersemangat.$"

Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers:
	.string "Mama lebih kuat dari Papa.\p"
	.string "Aku lebih kuat dari Mama.\p"
	.string "Dan Nenek lebih kuat dariku!\p"
	.string "Tapi kakak laki-lakiku bahkan lebih\n"
	.string "kuat dari Nenek.$"

Route111_WinstrateFamilysHouse_Text_GrandsonStrong:
	.string "Tidak diragukan lagi bahwa kamu kuat.\p"
	.string "Tapi jika kamu bertarung melawan\n"
	.string "cucuku, kamu akan berakhir menangis\l"
	.string "karena frustrasi.\p"
	.string "Dia jauh lebih kuat dari Trainer mana\n"
	.string "pun yang keluarga kami kenal.\p"
	.string "Dia pasti sedang menantang CHAMPION\n"
	.string "POKéMON LEAGUE sekarang.\p"
	.string "Mengenal cucuku, dia mungkin sudah\n"
	.string "menjadi CHAMPION!$"

Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort:
	.string "Cucuku pasti sedang menantang\n"
	.string "CHAMPION POKéMON LEAGUE sekarang.\p"
	.string "Mengenal cucuku, dia mungkin sudah\n"
	.string "menjadi CHAMPION!$"
