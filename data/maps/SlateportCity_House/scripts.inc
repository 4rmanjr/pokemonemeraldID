//gemini
SlateportCity_House_MapScripts::
	.byte 0

SlateportCity_House_EventScript_PokefanM::
	msgbox SlateportCity_House_Text_NatureToDoWithStatGains, MSGBOX_NPC
	end

SlateportCity_House_EventScript_Girl::
	msgbox SlateportCity_House_Text_MustBeGoingToBattleTent, MSGBOX_NPC
	end

SlateportCity_House_Text_NatureToDoWithStatGains:
	.string "POKéMON-ku memiliki sifat HASTY.\p"
	.string "Ia memiliki SPEED yang lebih tinggi\n"
	.string "dibandingkan POKéMON-ku yang lain.\p"
	.string "Mungkin sifat mereka ada hubungannya\n"
	.string "dengan peningkatan stat POKéMON.$"

SlateportCity_House_Text_MustBeGoingToBattleTent:
	.string "Kamu seorang TRAINER, kan?\p"
	.string "Karena kamu datang ke SLATEPORT CITY,\n"
	.string "kamu pasti akan pergi ke BATTLE TENT.$"
