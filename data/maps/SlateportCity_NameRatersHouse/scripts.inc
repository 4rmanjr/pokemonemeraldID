//gemini
SlateportCity_NameRatersHouse_MapScripts::
	.byte 0

SlateportCity_NameRatersHouse_EventScript_NameRater::
	lock
	faceplayer
	msgbox SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate::
	msgbox SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special ChooseBoxMon
	waitstate
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_RateMonNickname
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_DeclineNameRate::
	msgbox SlateportCity_NameRatersHouse_Text_DoVisitAgain, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_RateMonNickname::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, SlateportCity_NameRatersHouse_EventScript_CantRateEgg
	special BufferMonNickname
	special IsMonOTIDNotPlayers
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	specialvar VAR_RESULT, MonOTNameNotPlayer
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	msgbox SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChangeNickname
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_CantRateEgg::
	msgbox SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT::
	msgbox SlateportCity_NameRatersHouse_Text_MagnificentName, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_ChangeNickname::
	msgbox SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe, MSGBOX_DEFAULT
	call_if_eq VAR_MON_BOX_ID, 0xFF, Common_EventScript_NameReceivedPartyMon
	call_if_ne VAR_MON_BOX_ID, 0xFF, Common_EventScript_NameReceivedBoxMon
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_NewNameDifferent
	msgbox SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_NewNameDifferent::
	msgbox SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname:
	.string "Hai, hai! Aku si PENILAI NAMA! Aku\n"
	.string "adalah peramal nama!\p"
	.string "Dengan senang hati aku akan menilai\n"
	.string "nama panggilan POKéMON milikmu.$"

SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname:
	.string "Nama panggilan POKéMON mana yang\n"
	.string "harus aku kritik?$"

SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne:
	.string "Hmmm… {STR_VAR_1}, benarkah? Itu\n"
	.string "nama yang cukup bagus yang kamu\l"
	.string "berikan.\p"
	.string "Tapi! Bagaimana menurutmu, jika aku\n"
	.string "menyarankan nama yang sedikit lebih\l"
	.string "baik?$"

SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe:
	.string "Ah, bagus. Kalau begitu, apa nama\n"
	.string "panggilan barunya?$"

SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName:
	.string "Selesai! Mulai sekarang, POKéMON\n"
	.string "ini akan dikenal sebagai\l"
	.string "{STR_VAR_1}!\p"
	.string "Itu nama yang lebih baik dari\n"
	.string "sebelumnya! Sungguh keberuntungan\l"
	.string "bagimu!$"

SlateportCity_NameRatersHouse_Text_DoVisitAgain:
	.string "Aku mengerti. Datanglah berkunjung\n"
	.string "lagi.$"

SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior:
	.string "Selesai! Mulai sekarang, POKéMON\n"
	.string "ini akan dikenal sebagai\l"
	.string "{STR_VAR_1}!\p"
	.string "Kelihatannya tidak berbeda dari\n"
	.string "sebelumnya, namun ini jauh lebih\l"
	.string "unggul!\p"
	.string "Sungguh keberuntungan bagimu!$"

SlateportCity_NameRatersHouse_Text_MagnificentName:
	.string "Hmmm… {STR_VAR_1} rupanya!\p"
	.string "Ini adalah nama panggilan yang luar\n"
	.string "biasa! Tak bercacat dan tanpa cela!\p"
	.string "Kamu harus menjaga {STR_VAR_1}\n"
	.string "milikmu ini mulai sekarang dan\l"
	.string "seterusnya.$"

SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg:
	.string "Tunggu, tunggu. Itu hanyalah sebuah\n"
	.string "TELUR!$"
