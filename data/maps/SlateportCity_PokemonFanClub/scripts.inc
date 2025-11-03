//gemini
SlateportCity_PokemonFanClub_MapScripts::
	.byte 0

SlateportCity_PokemonFanClub_EventScript_Chairman::
	lock
	faceplayer
	goto_if_unset FLAG_ENTERED_CONTEST, SlateportCity_PokemonFanClub_EventScript_ChairmanNotEnteredContest
	call_if_unset FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN, SlateportCity_PokemonFanClub_EventScript_MeetChairman
	switch VAR_SLATEPORT_FAN_CLUB_STATE
	case 0, SlateportCity_PokemonFanClub_EventScript_ChairmanFirstAssessment
	case 1, SlateportCity_PokemonFanClub_EventScript_ChairmanTryAssessPokemon
	case 2, SlateportCity_PokemonFanClub_EventScript_NoMoreScarves
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanFirstAssessment::
	setvar VAR_SLATEPORT_FAN_CLUB_STATE, 1
	msgbox SlateportCity_PokemonFanClub_Text_AllowMeToExamineYourPokemon, MSGBOX_DEFAULT
	goto SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanTryAssessPokemon::
	setvar VAR_TEMP_2, 0
	call_if_set FLAG_RECEIVED_YELLOW_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_GREEN_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_PINK_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_BLUE_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_RED_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_eq VAR_TEMP_2, CONTEST_CATEGORIES_COUNT, SlateportCity_PokemonFanClub_EventScript_ReceivedAllScarves
	goto_if_eq VAR_SLATEPORT_FAN_CLUB_STATE, 2, SlateportCity_PokemonFanClub_EventScript_NoMoreScarves
	msgbox SlateportCity_PokemonFanClub_Text_HowIsYourPokemonGrowing, MSGBOX_DEFAULT
	goto SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon
	end

SlateportCity_PokemonFanClub_EventScript_NoMoreScarves::
	msgbox SlateportCity_PokemonFanClub_Text_NothingElseToGiveYou, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon::
	msgbox SlateportCity_PokemonFanClub_Text_HmHmISee, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, 0
	call_if_unset FLAG_RECEIVED_YELLOW_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonTough
	call_if_unset FLAG_RECEIVED_GREEN_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonSmart
	call_if_unset FLAG_RECEIVED_PINK_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonCute
	call_if_unset FLAG_RECEIVED_BLUE_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonBeauty
	call_if_unset FLAG_RECEIVED_RED_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonCool
	bufferleadmonspeciesname STR_VAR_1
	switch VAR_TEMP_1
	case 0, SlateportCity_PokemonFanClub_EventScript_NoHighConditions
	case 1, SlateportCity_PokemonFanClub_EventScript_GiveRedScarf
	case 2, SlateportCity_PokemonFanClub_EventScript_GiveBlueScarf
	case 3, SlateportCity_PokemonFanClub_EventScript_GivePinkScarf
	case 4, SlateportCity_PokemonFanClub_EventScript_GiveGreenScarf
	case 5, SlateportCity_PokemonFanClub_EventScript_GiveYellowScarf
	release
	end

SlateportCity_PokemonFanClub_EventScript_ReceivedAllScarves::
	setvar VAR_SLATEPORT_FAN_CLUB_STATE, 2
	return

SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf::
	addvar VAR_TEMP_2, 1
	return

SlateportCity_PokemonFanClub_EventScript_NoHighConditions::
	msgbox SlateportCity_PokemonFanClub_Text_GiveMonMorePokeblocks, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveRedScarf::
	checkitemspace ITEM_RED_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_RED_SCARF
	giveitem ITEM_RED_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainRedScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveBlueScarf::
	checkitemspace ITEM_BLUE_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_BLUE_SCARF
	giveitem ITEM_BLUE_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainBlueScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GivePinkScarf::
	checkitemspace ITEM_PINK_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_PINK_SCARF
	giveitem ITEM_PINK_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainPinkScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveGreenScarf::
	checkitemspace ITEM_GREEN_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_GREEN_SCARF
	giveitem ITEM_GREEN_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainGreenScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveYellowScarf::
	checkitemspace ITEM_YELLOW_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_YELLOW_SCARF
	giveitem ITEM_YELLOW_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainYellowScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf::
	msgbox SlateportCity_PokemonFanClub_Text_NoSpaceForReward, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_CheckMonCool::
	specialvar VAR_RESULT, CheckLeadMonCool
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonCool
	return

SlateportCity_PokemonFanClub_EventScript_SetMonCool::
	setvar VAR_TEMP_1, 1
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonBeauty::
	specialvar VAR_RESULT, CheckLeadMonBeauty
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonBeauty
	return

SlateportCity_PokemonFanClub_EventScript_SetMonBeauty::
	setvar VAR_TEMP_1, 2
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonCute::
	specialvar VAR_RESULT, CheckLeadMonCute
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonCute
	return

SlateportCity_PokemonFanClub_EventScript_SetMonCute::
	setvar VAR_TEMP_1, 3
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonSmart::
	specialvar VAR_RESULT, CheckLeadMonSmart
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonSmart
	return

SlateportCity_PokemonFanClub_EventScript_SetMonSmart::
	setvar VAR_TEMP_1, 4
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonTough::
	specialvar VAR_RESULT, CheckLeadMonTough
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonTough
	return

SlateportCity_PokemonFanClub_EventScript_SetMonTough::
	setvar VAR_TEMP_1, 5
	return

SlateportCity_PokemonFanClub_EventScript_ChairmanNotEnteredContest::
	goto_if_set FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN, SlateportCity_PokemonFanClub_EventScript_ChairmanEnterContest
	msgbox SlateportCity_PokemonFanClub_Text_MeetChairman, MSGBOX_DEFAULT
	setflag FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanEnterContest::
	msgbox SlateportCity_PokemonFanClub_Text_LikeToSeeEnteredContestPokemon, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_MeetChairman::
	msgbox SlateportCity_PokemonFanClub_Text_MeetChairman, MSGBOX_DEFAULT
	setflag FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN
	return

SlateportCity_PokemonFanClub_EventScript_SootheBellWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SOOTHE_BELL, SlateportCity_PokemonFanClub_EventScript_ReceivedSootheBell
	msgbox SlateportCity_PokemonFanClub_Text_ShowMePokemonThatLoveYou, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, SlateportCity_PokemonFanClub_EventScript_GiveSootheBell
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveSootheBell::
	playse SE_PIN
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_LAST_TALKED, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_PokemonFanClub_Text_PokemonAdoresYou, MSGBOX_DEFAULT
	giveitem ITEM_SOOTHE_BELL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SOOTHE_BELL
	release
	end

SlateportCity_PokemonFanClub_EventScript_ReceivedSootheBell::
	msgbox SlateportCity_PokemonFanClub_Text_TreatPokemonWithLove, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_Man::
	msgbox SlateportCity_PokemonFanClub_Text_PokemonDontLikeFainting, MSGBOX_NPC
	end

SlateportCity_PokemonFanClub_EventScript_Twin::
	msgbox SlateportCity_PokemonFanClub_Text_MonEnjoyedProtein, MSGBOX_NPC
	end

SlateportCity_PokemonFanClub_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_EventScript_Azumarill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_Text_MeetChairman:
	.string "Ehem! Aku adalah KETUA KELUB\n"
	.string "PENGGEMAR POKéMON!\p"
	.string "Karena Aku KETUA, tentu saja Aku\n"
	.string "yang paling penting!\p"
	.string "Tak seorang pun bisa melebihi Aku\n"
	.string "dalam hal membesarkan POKéMON. Tak\l"
	.string "seorang pun!\p"
	.string "Baiklah, akan Aku ceritakan tentang\n"
	.string "KONTEST POKéMON.\p"
	.string "Itu adalah acara di mana seseorang\n"
	.string "dapat memamerkan POKéMON untuk\l"
	.string "dilihat dunia!\p"
	.string "Namun, acara itu diadakan di\n"
	.string "kota-kota yang jauh, jadi Aku tidak\l"
	.string "bisa sering berpartisipasi.\p"
	.string "Itu sebabnya kami berkumpul di sini\n"
	.string "untuk memamerkan POKéMON kami, dan\l"
	.string "meminta orang lain memamerkan milik\l"
	.string "mereka.$"

SlateportCity_PokemonFanClub_Text_LikeToSeeEnteredContestPokemon:
	.string "POKéMON milik TRAINER yang pernah\n"
	.string "mengikuti KONTEST POKéMON… Itu, Aku\l"
	.string "ingin melihatnya.$"

SlateportCity_PokemonFanClub_Text_AllowMeToExamineYourPokemon:
	.string "Ehem! Aku lihat Kamu pernah\n"
	.string "berpartisipasi dalam KONTEST\l"
	.string "POKéMON!\p"
	.string "Kumohon! Izinkan Aku memeriksa\n"
	.string "bagaimana Kamu membesarkan POKéMON\l"
	.string "milikmu.\p"
	.string "Aku senang tiada akhir melihat\n"
	.string "POKéMON yang dibesarkan oleh\l"
	.string "TRAINER lain.\p"
	.string "Ekspresi bahagia POKéMON yang\n"
	.string "dibesarkan dengan perawatan yang\l"
	.string "benar…\p"
	.string "Mata ramah TRAINER yang merawat dan\n"
	.string "membesarkan POKéMON tersebut…\p"
	.string "Pikiran itu saja sudah memenuhi\n"
	.string "hati Aku dengan sukacita yang\l"
	.string "meluap-luap.\p"
	.string "Oh! Aku mohon maaf! Maafkan Aku\n"
	.string "karena mengoceh terlalu lama!\p"
	.string "Kumohon! Izinkan Aku memeriksa\n"
	.string "seberapa besar POKéMON-mu telah\l"
	.string "tumbuh!$"

SlateportCity_PokemonFanClub_Text_HowIsYourPokemonGrowing:
	.string "Bagaimana POKéMON-mu tumbuh?\n"
	.string "Izinkan Aku memeriksanya.$"

SlateportCity_PokemonFanClub_Text_HmHmISee:
	.string "Hm, hm… Aku mengerti…$"

SlateportCity_PokemonFanClub_Text_GiveMonMorePokeblocks:
	.string "Hmmm… Tidak buruk, tapi tidak bagus\n"
	.string "juga…\p"
	.string "Kamu, sebagai TRAINER, harus lebih\n"
	.string "berusaha dalam membesarkan POKéMON\l"
	.string "ini!\p"
	.string "Misalnya, bolehkah Aku menyarankan\n"
	.string "agar Kamu memberinya lebih banyak\l"
	.string "{POKEBLOCK}?$"

SlateportCity_PokemonFanClub_Text_NoSpaceForReward:
	.string "Astaga…\p"
	.string "POKéMON-mu tumbuh dengan cukup\n"
	.string "baik, jadi Kamu pantas mendapat\l"
	.string "hadiah.\p"
	.string "Sayangnya, Kamu tidak punya ruang\n"
	.string "untuk ini di TAS-mu.$"

SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis:
	.string "{STR_VAR_1} milikmu, ia tumbuh\n"
	.string "dengan cara yang paling\l"
	.string "mengesankan! Ia adalah spesimen\l"
	.string "yang bagus!\p"
	.string "Tapi! Jika Kamu memberinya ini, ia\n"
	.string "akan tumbuh lebih baik lagi!\l"
	.string "Sungguh!$"

SlateportCity_PokemonFanClub_Text_ExplainRedScarf:
	.string "Biarkan POKéMON memegang SYAL MERAH\n"
	.string "itu.\p"
	.string "Semua orang akan mengenali\n"
	.string "keKerenan POKéMON itu!$"

SlateportCity_PokemonFanClub_Text_ExplainBlueScarf:
	.string "Biarkan POKéMON memegang SYAL BIRU\n"
	.string "itu.\p"
	.string "Keindahannya akan lebih ditekankan\n"
	.string "daripada sekarang!$"

SlateportCity_PokemonFanClub_Text_ExplainPinkScarf:
	.string "Biarkan POKéMON memegang SYAL MERAH\n"
	.string "MUDA itu.\p"
	.string "Itu akan lebih menonjolkan keImutan\n"
	.string "POKéMON tersebut!$"

SlateportCity_PokemonFanClub_Text_ExplainGreenScarf:
	.string "Biarkan POKéMON memegang SYAL HIJAU\n"
	.string "itu.\p"
	.string "Itu akan meningkatkan kePintaran\n"
	.string "POKéMON!$"

SlateportCity_PokemonFanClub_Text_ExplainYellowScarf:
	.string "Biarkan POKéMON memegang SYAL\n"
	.string "KUNING itu.\p"
	.string "Itu akan meningkatkan keKetangguhan\n"
	.string "POKéMON-mu jauh lebih besar!$"

SlateportCity_PokemonFanClub_Text_NothingElseToGiveYou:
	.string "Maaf, tapi Aku tidak punya hal lain\n"
	.string "untuk diberikan padamu! Sama sekali\l"
	.string "tidak ada!\p"
	.string "Bagaimanapun, Kamu diberkati dengan\n"
	.string "karunia membesarkan POKéMON tanpa\l"
	.string "menggunakan item apa pun!$"

SlateportCity_PokemonFanClub_Text_ShowMePokemonThatLoveYou:
	.string "Aku senang melihat POKéMON yang\n"
	.string "mencintai TRAINER mereka.\p"
	.string "POKéMON sangat peka terhadap\n"
	.string "perasaan TRAINER mereka.\p"
	.string "Jika Kamu memperlakukan POKéMON-mu\n"
	.string "dengan kasih sayang dan perhatian,\l"
	.string "mereka akan membalas cinta Kamu.\p"
	.string "Ketika POKéMON-mu tumbuh mencintai\n"
	.string "Kamu, mohon datang dan tunjukkan\l"
	.string "pada Aku.$"

SlateportCity_PokemonFanClub_Text_PokemonAdoresYou:
	.string "POKéMON-mu benar-benar memuja Kamu.\p"
	.string "Untuk Kamu, TRAINER yang paling\n"
	.string "penyayang, ini hadiah dari KELUB\l"
	.string "PENGGEMAR!$"

SlateportCity_PokemonFanClub_Text_TreatPokemonWithLove:
	.string "POKéMON sangat peka terhadap\n"
	.string "perasaan TRAINER mereka.\p"
	.string "Jika Kamu memperlakukan POKéMON-mu\n"
	.string "dengan kasih sayang dan perhatian,\l"
	.string "mereka akan membalas cinta Kamu.$"

SlateportCity_PokemonFanClub_Text_PokemonDontLikeFainting:
	.string "Jika Kamu terus membiarkan POKéMON\n"
	.string "pingsan dalam pertempuran, ia akan\l"
	.string "membenci hal itu.\p"
	.string "Tak lama, ia akan menjadi kurang\n"
	.string "percaya pada TRAINER.\p"
	.string "Dengan kata lain, ia pasti tidak\n"
	.string "akan menyukai Kamu.$"

SlateportCity_PokemonFanClub_Text_MonEnjoyedProtein:
	.string "Apakah POKéMON senang jika item\n"
	.string "digunakan pada mereka?\p"
	.string "Milikku bertingkah sangat bahagia\n"
	.string "ketika Aku memberinya PROTEIN.$"

SlateportCity_PokemonFanClub_Text_Skitty:
	.string "SKITTY: Fffnyaaaah…$"

SlateportCity_PokemonFanClub_Text_Zigzagoon:
	.string "ZIGZAGOON: Kyuuu…$"

SlateportCity_PokemonFanClub_Text_Azumarill:
	.string "AZUMARILL: Marimari?$"
