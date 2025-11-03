BattleFrontier_Lounge1_MapScripts::
	.byte 0

@ NPC that rates pokemon based on their IVs
BattleFrontier_Lounge1_EventScript_Breeder::
	lock
	faceplayer
	call_if_unset FLAG_MET_BATTLE_FRONTIER_BREEDER, BattleFrontier_Lounge1_EventScript_BreederIntro
	call_if_set FLAG_MET_BATTLE_FRONTIER_BREEDER, BattleFrontier_Lounge1_EventScript_AlreadyMetBreeder
	setflag FLAG_MET_BATTLE_FRONTIER_BREEDER
	goto BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder
	end

BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder::
	special ChoosePartyMon
	waitstate
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge1_EventScript_ShowMonToBreeder
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge1_EventScript_CancelMonSelect
	end

BattleFrontier_Lounge1_EventScript_BreederIntro::
	msgbox BattleFrontier_Lounge1_Text_PokemonBreederIntro, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge1_EventScript_AlreadyMetBreeder::
	msgbox BattleFrontier_Lounge1_Text_LetsLookAtYourPokemon, MSGBOX_DEFAULT
	return

@ BufferVarsForIVRater buffers the following values
@ VAR_0x8005: Sum of the mons IVs
@ VAR_0x8006: Stat id of highest IV stat
@ VAR_0x8007: IV of the highest IV stat
BattleFrontier_Lounge1_EventScript_ShowMonToBreeder::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, BattleFrontier_Lounge1_EventScript_ShowEggToBreeder
	special BufferVarsForIVRater
	goto_if_le VAR_0x8005, 90, BattleFrontier_Lounge1_EventScript_AverageTotalIVs       @ Average of 15
	goto_if_le VAR_0x8005, 120, BattleFrontier_Lounge1_EventScript_AboveAverageTotalIVs @ Average of 20
	goto_if_le VAR_0x8005, 150, BattleFrontier_Lounge1_EventScript_HighTotalIVs         @ Average of 25
	goto_if_ge VAR_0x8005, 151, BattleFrontier_Lounge1_EventScript_VeryHighTotalIVs     @ Average of > 25
	end

BattleFrontier_Lounge1_EventScript_ShowEggToBreeder::
	msgbox BattleFrontier_Lounge1_Text_EvenICantTell, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder
	end

@ Comment on the highest IV stat
BattleFrontier_Lounge1_EventScript_HighestIVStat::
	goto_if_eq VAR_0x8006, STAT_HP, BattleFrontier_Lounge1_EventScript_HighestIVHP
	goto_if_eq VAR_0x8006, STAT_ATK, BattleFrontier_Lounge1_EventScript_HighestIVAtk
	goto_if_eq VAR_0x8006, STAT_DEF, BattleFrontier_Lounge1_EventScript_HighestIVDef
	goto_if_eq VAR_0x8006, STAT_SPEED, BattleFrontier_Lounge1_EventScript_HighestIVSpeed
	goto_if_eq VAR_0x8006, STAT_SPATK, BattleFrontier_Lounge1_EventScript_HighestIVSpAtk
	goto_if_eq VAR_0x8006, STAT_SPDEF, BattleFrontier_Lounge1_EventScript_HighestIVSpDef
	end

@ Comment on the highest IV value
BattleFrontier_Lounge1_EventScript_HighestIVValue::
	goto_if_le VAR_0x8007, 15, BattleFrontier_Lounge1_EventScript_HighestIVLow
	goto_if_le VAR_0x8007, 25, BattleFrontier_Lounge1_EventScript_HighestIVMid
	goto_if_le VAR_0x8007, 30, BattleFrontier_Lounge1_EventScript_HighestIVHigh
	goto_if_ge VAR_0x8007, 31, BattleFrontier_Lounge1_EventScript_HighestIVMax
	end

BattleFrontier_Lounge1_EventScript_EndBreederComments::
	release
	end

BattleFrontier_Lounge1_EventScript_AverageTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_AverageAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_AboveAverageTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_BetterThanAverageAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_HighTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_ImpressiveAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_VeryHighTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_OutstandingAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_HighestIVHP::
	msgbox BattleFrontier_Lounge1_Text_BestAspectHP, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVAtk::
	msgbox BattleFrontier_Lounge1_Text_BestAspectAtk, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVDef::
	msgbox BattleFrontier_Lounge1_Text_BestAspectDef, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpeed::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpeed, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpAtk::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpAtk, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpDef::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpDef, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVLow::
	msgbox BattleFrontier_Lounge1_Text_StatRelativelyGood, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVMid::
	msgbox BattleFrontier_Lounge1_Text_StatImpressive, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVHigh::
	msgbox BattleFrontier_Lounge1_Text_StatOutstanding, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVMax::
	msgbox BattleFrontier_Lounge1_Text_StatFlawless, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_CancelMonSelect::
	msgbox BattleFrontier_Lounge1_Text_NoTimeForMyAdvice, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge1_EventScript_Boy1::
	msgbox BattleFrontier_Lounge1_Text_SaidMyMonIsOutstanding, MSGBOX_NPC
	end

BattleFrontier_Lounge1_EventScript_Boy2::
	msgbox BattleFrontier_Lounge1_Text_DidntDoAnythingSpecialRaisingIt, MSGBOX_NPC
	end

BattleFrontier_Lounge1_Text_PokemonBreederIntro:
	.string "Selama 70 tahun aku telah membesarkan POKéMON!\n"
	.string "Akulah pria yang mereka hormati sebagai\l"
	.string "POKéMON BREEDER legendaris!\p"
	.string "Jika kamu sudah berpengalaman sepertiku,\n"
	.string "kamu akan melihat kemampuan POKéMON\l"
	.string "sekilas.\p"
	.string "Kamu seorang TRAINER. Tidakkah kamu\n"
	.string "tertarik untuk mengetahui kemampuan\l"
	.string "POKéMON-mu sendiri?\p"
	.string "Sini!\n"
	.string "Mari kita lihat POKéMON-mu!$"

BattleFrontier_Lounge1_Text_AverageAbility:
	.string "…Hmm…\p"
	.string "Yang ini, secara keseluruhan, akan\n"
	.string "kugambarkan memiliki kemampuan rata-rata.$"

BattleFrontier_Lounge1_Text_BetterThanAverageAbility:
	.string "…Hmm…\p"
	.string "Yang ini, secara keseluruhan, akan\n"
	.string "kugambarkan memiliki kemampuan di atas rata-rata.$"

BattleFrontier_Lounge1_Text_ImpressiveAbility:
	.string "…Hmm…\p"
	.string "Yang ini, secara keseluruhan, menurutku\n"
	.string "kemampuannya cukup mengesankan!$"

BattleFrontier_Lounge1_Text_OutstandingAbility:
	.string "…Hmm…\p"
	.string "Yang ini, secara keseluruhan, menurutku\n"
	.string "kemampuannya luar biasa hebat!$"

BattleFrontier_Lounge1_Text_BestAspectHP:
	.string "Kebetulan, aspek terbaiknya,\n"
	.string "menurutku, adalah HP-nya…$"

BattleFrontier_Lounge1_Text_BestAspectAtk:
	.string "Kebetulan, aspek terbaiknya,\n"
	.string "menurutku, adalah ATTACK-nya…$"

BattleFrontier_Lounge1_Text_BestAspectDef:
	.string "Kebetulan, aspek terbaiknya,\n"
	.string "menurutku, adalah DEFENSE-nya…$"

BattleFrontier_Lounge1_Text_BestAspectSpAtk:
	.string "Kebetulan, aspek terbaiknya,\n"
	.string "menurutku, adalah SPECIAL ATTACK-nya…$"

BattleFrontier_Lounge1_Text_BestAspectSpDef:
	.string "Kebetulan, aspek terbaiknya,\n"
	.string "menurutku, adalah SPECIAL DEFENSE-nya…$"

BattleFrontier_Lounge1_Text_BestAspectSpeed:
	.string "Kebetulan, aspek terbaiknya,\n"
	.string "menurutku, adalah SPEED-nya…$"

BattleFrontier_Lounge1_Text_StatRelativelyGood:
	.string "Status itu relatif bagus.\n"
	.string "…Hm… Begitulah aku menilainya.$"

BattleFrontier_Lounge1_Text_StatImpressive:
	.string "Status itu cukup mengesankan.\n"
	.string "…Hm… Begitulah aku menilainya.$"

BattleFrontier_Lounge1_Text_StatOutstanding:
	.string "Status itu luar biasa!\n"
	.string "…Hm… Begitulah aku menilainya.$"

BattleFrontier_Lounge1_Text_StatFlawless:
	.string "Sempurna! Sesuatu yang sempurna!\n"
	.string "…Hm… Begitulah aku menilainya.$"

BattleFrontier_Lounge1_Text_NoTimeForMyAdvice:
	.string "Apa?\n"
	.string "Kamu tidak punya waktu untuk nasihatku?\p"
	.string "Kamu harus selalu bersemangat untuk belajar\n"
	.string "dari pengalaman orang yang lebih tua!$"

@ Unused
BattleFrontier_Lounge1_Text_HaveBusinessNeedsTending:
	.string "Ya, ada apa sekarang?\p"
	.string "Aku punya urusan yang harus diselesaikan!\n"
	.string "Lain kali saja!$"

BattleFrontier_Lounge1_Text_LetsLookAtYourPokemon:
	.string "Ah, anak muda! Apakah kemampuan\n"
	.string "POKéMON-mu membuatmu penasaran?\p"
	.string "Sini, sini!\n"
	.string "Mari kita lihat POKéMON-mu!$"

BattleFrontier_Lounge1_Text_EvenICantTell:
	.string "Aku memang ahli, tapi bahkan aku tidak bisa\n"
	.string "memberi tahu apa pun tentang TELUR!\p"
	.string "Tunjukkan POKéMON!\n"
	.string "Aku perlu melihat POKéMON!$"

BattleFrontier_Lounge1_Text_SaidMyMonIsOutstanding:
	.string "Dia bilang POKéMON-ku luar biasa!\n"
	.string "Aku senang telah membesarkannya dengan hati-hati!$"

BattleFrontier_Lounge1_Text_DidntDoAnythingSpecialRaisingIt:
	.string "Dia bilang POKéMON-ku luar biasa!\n"
	.string "Padahal aku tidak melakukan sesuatu yang\l"
	.string "istimewa saat membesarkannya…$"


