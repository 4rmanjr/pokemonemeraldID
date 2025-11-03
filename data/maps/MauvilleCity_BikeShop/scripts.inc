//gemini
MauvilleCity_BikeShop_MapScripts::
	.byte 0

MauvilleCity_BikeShop_EventScript_Rydel::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, MauvilleCity_BikeShop_EventScript_AskSwitchBikes
	goto_if_set FLAG_DECLINED_BIKE, MauvilleCity_BikeShop_EventScript_SkipGreeting
	msgbox MauvilleCity_BikeShop_Text_RydelGreeting, MSGBOX_DEFAULT
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_SkipGreeting::
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_ChooseBike::
	message MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne
	waitmessage
	multichoice 21, 8, MULTI_BIKE, TRUE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_GetMachBike
	case 1, MauvilleCity_BikeShop_EventScript_GetAcroBike
	end

MauvilleCity_BikeShop_EventScript_NotFar::
	setflag FLAG_DECLINED_BIKE
	msgbox MauvilleCity_BikeShop_Text_GuessYouDontNeedBike, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_YesFar::
	setflag FLAG_RECEIVED_BIKE
	goto MauvilleCity_BikeShop_EventScript_ChooseBike
	end

MauvilleCity_BikeShop_EventScript_GetMachBike::
	msgbox MauvilleCity_BikeShop_Text_ChoseMachBike, MSGBOX_DEFAULT
	giveitem ITEM_MACH_BIKE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_GetAcroBike::
	msgbox MauvilleCity_BikeShop_Text_ChoseAcroBike, MSGBOX_DEFAULT
	giveitem ITEM_ACRO_BIKE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes, MSGBOX_DEFAULT
	special SwapRegisteredBike
	release
	end

MauvilleCity_BikeShop_EventScript_AskSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_WantToSwitchBikes, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_SwitchBikes
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_KeepBike
	end

@ If the player does not have a bike on them Rydel assumes its stored in the PC
MauvilleCity_BikeShop_EventScript_SwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_IllSwitchBikes, MSGBOX_DEFAULT
	checkitem ITEM_ACRO_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchAcroForMach
	checkitem ITEM_MACH_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchMachForAcro
	msgbox MauvilleCity_BikeShop_Text_OhYourBikeIsInPC, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_KeepBike::
	msgbox MauvilleCity_BikeShop_Text_HappyYouLikeIt, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_SwitchAcroForMach::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedAcroForMach, MSGBOX_DEFAULT
	removeitem ITEM_ACRO_BIKE
	giveitem ITEM_MACH_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_SwitchMachForAcro::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedMachForAcro, MSGBOX_DEFAULT
	removeitem ITEM_MACH_BIKE
	giveitem ITEM_ACRO_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_Assistant::
	msgbox MauvilleCity_BikeShop_Text_HandbooksAreInBack, MSGBOX_NPC
	end

MauvilleCity_BikeShop_EventScript_MachBikeHandbook::
	message MauvilleCity_BikeShop_Text_MachHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage::
	multichoice 0, 0, MULTI_MACH_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_HowToRide
	case 1, MauvilleCity_BikeShop_EventScript_HowToTurn
	case 2, MauvilleCity_BikeShop_EventScript_SandySlopes
	case 3, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	end

MauvilleCity_BikeShop_EventScript_HowToRide::
	message MauvilleCity_BikeShop_Text_HowToRideMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_HowToTurn::
	message MauvilleCity_BikeShop_Text_HowToTurnMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_SandySlopes::
	message MauvilleCity_BikeShop_Text_SandySlopes
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitMachHandbook::
	release
	end

MauvilleCity_BikeShop_EventScript_AcroBikeHandbook::
	message MauvilleCity_BikeShop_Text_AcroHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage::
	multichoice 0, 0, MULTI_ACRO_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_Wheelies
	case 1, MauvilleCity_BikeShop_EventScript_BunnyHops
	case 2, MauvilleCity_BikeShop_EventScript_Jumps
	case 3, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	end

MauvilleCity_BikeShop_EventScript_Wheelies::
	message MauvilleCity_BikeShop_Text_Wheelies
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_BunnyHops::
	message MauvilleCity_BikeShop_Text_BunnyHops
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_Jumps::
	message MauvilleCity_BikeShop_Text_Jumps
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitAcroHandbook::
	release
	end

MauvilleCity_BikeShop_Text_RydelGreeting:
	.string "Wah, wah, ada apa ini?\n"
	.string "Seorang pelanggan yang paling\n"
	.string "bersemangat!\p"
	.string "Aku? Kamu bisa memanggilku RYDEL.\n"
	.string "Aku pemilik toko sepeda ini.$"

MauvilleCity_BikeShop_Text_DidYouComeFromFarAway:
	.string "RYDEL: RUNNING SHOES-mu…\n"
	.string "Sangat kotor sekali.\p"
	.string "Apa kamu datang dari jauh?$"

MauvilleCity_BikeShop_Text_GuessYouDontNeedBike:
	.string "RYDEL: Benarkah?\p"
	.string "Kalau begitu, kurasa kamu tidak\n"
	.string "membutuhkan BIKE-ku.$"

MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne:
	.string "RYDEL: Hm, hm… … … … …\p"
	.string "Kamu bilang kamu datang jauh-jauh\n"
	.string "dari Kota LITTLEROOT?\p"
	.string "Astaga!\n"
	.string "Itu sangat jauh sekali!\p"
	.string "Jika kamu punya salah satu BIKE-ku,\n"
	.string "kamu bisa pergi ke mana saja dengan\l"
	.string "mudah sambil merasakan belaian\l"
	.string "lembut angin!\p"
	.string "Aku akan beritahu kamu!\n"
	.string "Aku akan memberimu sebuah BIKE!\p"
	.string "Oh, tunggu sebentar!\p"
	.string "Aku lupa memberitahumu bahwa ada\n"
	.string "dua jenis BIKE!\p"
	.string "Yaitu MACH BIKE & ACRO BIKE!\p"
	.string "MACH BIKE untuk pengendara yang\n"
	.string "ingin merasakan angin dengan tubuh\l"
	.string "mereka!\p"
	.string "& ACRO BIKE untuk mereka yang lebih\n"
	.string "suka berkendara teknis!\p"
	.string "Aku orang yang baik hati, jadi kamu\n"
	.string "bisa punya yang mana saja yang kamu\l"
	.string "suka!\p"
	.string "Kamu akan pilih yang mana?$"

MauvilleCity_BikeShop_Text_ChoseMachBike:
	.string "{PLAYER} memilih MACH BIKE.$"

MauvilleCity_BikeShop_Text_ChoseAcroBike:
	.string "{PLAYER} memilih ACRO BIKE.$"

MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes:
	.string "RYDEL: Jika kamu ingin menukar BIKE,\n"
	.string "datang saja padaku!$"

MauvilleCity_BikeShop_Text_WantToSwitchBikes:
	.string "RYDEL: Oh? Apa kamu berpikir untuk\n"
	.string "menukar BIKE?$"

MauvilleCity_BikeShop_Text_IllSwitchBikes:
	.string "RYDEL: Oke, tidak masalah!\n"
	.string "Aku akan menukar BIKE untukmu!$"

MauvilleCity_BikeShop_Text_ExchangedMachForAcro:
	.string "{PLAYER} menukar MACH BIKE dengan\n"
	.string "ACRO BIKE.$"

MauvilleCity_BikeShop_Text_ExchangedAcroForMach:
	.string "{PLAYER} menukar ACRO BIKE dengan\n"
	.string "MACH BIKE.$"

MauvilleCity_BikeShop_Text_HappyYouLikeIt:
	.string "RYDEL: Bagus, bagus!\n"
	.string "Aku senang kamu menyukainya!$"

MauvilleCity_BikeShop_Text_OhYourBikeIsInPC:
	.string "Oh? Apa yang terjadi pada BIKE yang\n"
	.string "kuberikan padamu?\p"
	.string "Oh, aku mengerti, kamu menyimpannya\n"
	.string "menggunakan PC-mu.\p"
	.string "Baiklah, keluarkan dari penyimpanan\n"
	.string "PC, & aku akan senang menukarnya!\p"
	.string "Semoga angin selalu mendukungmu\n"
	.string "dalam petualanganmu!$"

MauvilleCity_BikeShop_Text_HandbooksAreInBack:
	.string "Aku belajar tentang BIKE sambil\n"
	.string "bekerja di sini.\p"
	.string "Jika kamu butuh saran tentang cara\n"
	.string "mengendarai BIKE-mu, ada beberapa\l"
	.string "buku panduan di belakang.$"

MauvilleCity_BikeShop_Text_MachHandbookWhichPage:
	.string "Ini buku panduan tentang MACH BIKE.\p"
	.string "Halaman mana yang ingin kamu baca?$"

MauvilleCity_BikeShop_Text_HowToRideMachBike:
	.string "BIKE bergerak ke arah yang ditekan\n"
	.string "pada + Control Pad.\p"
	.string "Akan melaju setelah bergerak.\p"
	.string "Untuk berhenti, lepaskan + Control\n"
	.string "Pad. BIKE akan melambat hingga\l"
	.string "berhenti.\p"
	.string "Mau baca halaman lain?$"

MauvilleCity_BikeShop_Text_HowToTurnMachBike:
	.string "MACH BIKE memang cepat, tapi tidak\n"
	.string "bisa berhenti dengan cepat.\p"
	.string "Agak sulit untuk berbelok di\n"
	.string "tikungan.\p"
	.string "Lepaskan + Control Pad sedikit\n"
	.string "sebelum tikungan & pelan-pelan.\p"
	.string "Mau baca halaman lain?$"

MauvilleCity_BikeShop_Text_SandySlopes:
	.string "Ada lereng berpasir kecil di seluruh\n"
	.string "wilayah HOENN.\p"
	.string "Pasir yang gembur membuat mustahil\n"
	.string "untuk mendaki secara normal.\p"
	.string "Tapi jika kamu punya MACH BIKE,\n"
	.string "kamu bisa melaju di lereng berpasir.\p"
	.string "Mau baca halaman lain?$"

MauvilleCity_BikeShop_Text_AcroHandbookWhichPage:
	.string "Ini buku panduan tentang ACRO BIKE.\p"
	.string "Halaman mana yang ingin kamu baca?$"

MauvilleCity_BikeShop_Text_Wheelies:
	.string "Tekan Tombol B saat berkendara,\n"
	.string "roda depan akan terangkat.\p"
	.string "Kamu bisa melaju dengan roda depan\n"
	.string "terangkat menggunakan + Control Pad.\p"
	.string "Teknik ini disebut wheelie.\p"
	.string "Mau baca halaman lain?$"

MauvilleCity_BikeShop_Text_BunnyHops:
	.string "Dengan menekan Tombol B terus,\n"
	.string "BIKE-mu bisa melompat di tempat.\p"
	.string "Teknik ini disebut bunny hop.\p"
	.string "Kamu juga bisa berkendara sambil\n"
	.string "melompat.\p"
	.string "Mau baca halaman lain?$"

MauvilleCity_BikeShop_Text_Jumps:
	.string "Tekan Tombol B & + Control Pad\n"
	.string "secara bersamaan untuk melompat.\p"
	.string "Tekan + Control Pad ke samping\n"
	.string "untuk melompat ke samping.\p"
	.string "Tekan ke belakang agar BIKE berganti\n"
	.string "arah saat melompat.\p"
	.string "Mau baca halaman lain?$"
