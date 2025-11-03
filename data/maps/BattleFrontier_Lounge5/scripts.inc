BattleFrontier_Lounge5_MapScripts::
	.byte 0

BattleFrontier_Lounge5_EventScript_NatureGirl::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge5_Text_NatureGirlGreeting, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	special ChoosePartyMon
	waitstate
	lock
	faceplayer
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, BattleFrontier_Lounge5_EventScript_NatureGirlEgg
	special ShowNatureGirlMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirlEgg::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlEgg, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlNoneShown, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_Gentleman::
	msgbox BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_BlackBelt::
	msgbox BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_LittleBoy::
	msgbox BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot, MSGBOX_NPC
	end

BattleFrontier_Lounge5_Text_NatureGirlGreeting::
	.string "Ehehe!\n"
	.string "Aku bisa tahu apa yang dipikirkan POKéMON!\p"
	.string "Tolong!\n"
	.string "Boleh aku lihat POKéMON-mu?$"

BattleFrontier_Lounge5_Text_NatureGirlNoneShown::
	.string "Huuu!\n"
	.string "Pelit!$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighAttackLow::
	.string "Hmhm…\p"
	.string "Yang ini bilang dia suka bertarung!\n"
	.string "Dia akan bertarung meskipun punya banyak\l"
	.string "luka!$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighDefenseLow::
	.string "Hmhm…\p"
	.string "Yang ini bilang dia suka bertarung!\n"
	.string "Tapi kalau sudah banyak luka,\l"
	.string "dia akan mengkhawatirkan dirinya sendiri!$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighSupportLow::
	.string "Hmhm…\p"
	.string "Yang ini bilang dia suka bertarung!\n"
	.string "Tapi kalau sudah banyak luka,\l"
	.string "dia akan jadi licik!$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighAttackLow::
	.string "Hmhm…\p"
	.string "Yang ini bilang dia menjaga dirinya sendiri!\n"
	.string "Tapi kalau sudah banyak luka,\l"
	.string "dia akan balas menyerang!$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighDefenseLow::
	.string "Hmhm…\p"
	.string "Yang ini bilang dia menjaga dirinya sendiri!\n"
	.string "Dia bilang dia mengkhawatirkan dirinya sendiri\l"
	.string "baik punya banyak luka atau tidak!$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighSupportLow::
	.string "Hmhm…\p"
	.string "Yang ini bilang dia menjaga dirinya sendiri!\n"
	.string "Tapi kalau sudah banyak luka,\l"
	.string "dia akan jadi licik!$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighAttackLow::
	.string "Hmhm…\p"
	.string "Yang ini bilang dia suka berbuat licik!\n"
	.string "Tapi kalau sudah banyak luka,\l"
	.string "dia akan balas menyerang!$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighDefenseLow::
	.string "Hmhm…\p"
	.string "Yang ini bilang dia suka berbuat licik!\n"
	.string "Tapi kalau sudah banyak luka,\l"
	.string "dia akan mengkhawatirkan dirinya sendiri!$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighSupportLow::
	.string "Hmhm…\p"
	.string "Yang ini bilang dia suka berbuat licik!\n"
	.string "Dia bilang dia suka berbuat licik meskipun\l"
	.string "punya banyak luka!$"

BattleFrontier_Lounge5_Text_NatureGirlEgg::
	.string "Konyol! TELUR itu sedang tidur!\n"
	.string "Aku tidak bisa bicara dengannya!$"

BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon::
	.string "Menawan sekali!\n"
	.string "Gadis kecil itu mengklaim dia bisa\l"
	.string "mengerti POKéMON!$"

BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound::
	.string "Aku punya perasaan bahwa gadis kecil itu\n"
	.string "mengatakan sesuatu yang mendalam.$"

BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot::
	.string "Aku tahu sesuatu!\p"
	.string "Gadis kecil itu sering bermain di rumah\n"
	.string "merah!$"


