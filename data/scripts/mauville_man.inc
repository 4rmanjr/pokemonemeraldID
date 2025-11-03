//gemini
MauvilleCity_PokemonCenter_1F_EventScript_MauvilleOldMan::
	special Script_GetCurrentMauvilleMan
	switch VAR_RESULT
	case MAUVILLE_MAN_BARD, MauvilleCity_PokemonCenter_1F_EventScript_Bard
	case MAUVILLE_MAN_HIPSTER, MauvilleCity_PokemonCenter_1F_EventScript_Hipster
	case MAUVILLE_MAN_TRADER, MauvilleCity_PokemonCenter_1F_EventScript_Trader
	case MAUVILLE_MAN_STORYTELLER, MauvilleCity_PokemonCenter_1F_EventScript_Storyteller
	case MAUVILLE_MAN_GIDDY, MauvilleCity_PokemonCenter_1F_EventScript_Giddy
	end

@ Bard
MauvilleCity_PokemonCenter_1F_EventScript_Bard::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_PlaySong
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong
	end

MauvilleCity_PokemonCenter_1F_EventScript_PlaySong::
	setvar VAR_0x8004, FALSE  @ Play his current song
	special PlayBardSong
	delay 60
	special HasBardSongBeenChanged
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong::
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	end

MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics::
	setvar VAR_0x8004, EASY_CHAT_TYPE_BARD_SONG
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, TRUE  @ Play the new song
	special PlayBardSong
	delay 60
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
	special SaveBardSongLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics::
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2, MSGBOX_DEFAULT
	release
	end

@ Hipster
MauvilleCity_PokemonCenter_1F_EventScript_Hipster::
	lock
	faceplayer
	setflag FLAG_UNLOCKED_TRENDY_SAYINGS
	msgbox MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening, MSGBOX_DEFAULT
	special HasHipsterTaughtWord
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord
	msgbox MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord::
	special HipsterTryTeachWord
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_TeachWord
	msgbox MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TeachWord::
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfWord, MSGBOX_DEFAULT
	special SetHipsterTaughtWord
	release
	end

@ Trader
MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor:
	.string "Hai, Aku TRADER. Mau tukar dekorasi\n"
	.string "denganku?$"

MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues:
	.string "Oh… Kamu membuatku sedih…$"

MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded:
	.string "Tapi kita sudah pernah tukar\n"
	.string "dekorasi, kamu dan Aku.$"

MauvilleCity_PokemonCenter_1F_Text_PickADecorItem:
	.string "Kalau Kamu lihat barang dekorasi\n"
	.string "milikku yang Kamu inginkan, katakan\l"
	.string "saja.$"

MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything:
	.string "Kamu tidak mau apa-apa? Aku merasa\n"
	.string "tidak diinginkan…$"

MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt:
	.string "Barang dekorasi itu dulunya milik\n"
	.string "{STR_VAR_1}.\p"
	.string "Kamu menginginkannya?$"

MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor:
	.string "Eh… Tunggu sebentar. Kamu tidak\n"
	.string "punya sepotong pun dekorasi!$"

MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade:
	.string "Oke, pilih dekorasi yang akan Kamu\n"
	.string "tukarkan padaku.$"

MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade:
	.string "Kamu tidak mau tukar denganku? Aku\n"
	.string "merasa tidak diinginkan…$"

MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis:
	.string "Kamu sudah punya semua {STR_VAR_2}S\n"
	.string "yang bisa disimpan. Kamu tidak\l"
	.string "punya ruang untuk ini.$"

MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor:
	.string "Oke, jadi kita akan tukar\n"
	.string "{STR_VAR_3} milikku dengan\l"
	.string "{STR_VAR_2} milikmu?$"

MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse:
	.string "Barang dekorasi itu sedang\n"
	.string "digunakan. Kamu tidak bisa\l"
	.string "menukarnya.$"

MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC:
	.string "Kalau begitu kita tukar! Aku akan\n"
	.string "kirim dekorasiku ke PC-mu.$"

MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne:
	.string "Ups! Maaf! Itu adalah barang\n"
	.string "dekorasi yang sangat langka. Aku\l"
	.string "tidak bisa menukarnya!\p"
	.string "Apa Kamu tertarik dengan yang lain?$"

MauvilleCity_PokemonCenter_1F_EventScript_Trader::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade
	special GetTraderTradedFlag
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded
	message MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade::
	msgbox MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive::
	special TraderMenuGetDecoration
	waitstate
	goto_if_eq VAR_0x8004, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor
	goto_if_eq VAR_0x8004, 0xFFFF, MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor
	msgbox MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor
	special DoesPlayerHaveNoDecorations
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	end

MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor::
	message MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor::
	message MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive::
	msgbox MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade, MSGBOX_DEFAULT
	special TraderShowDecorationMenu
	waitstate
	goto_if_eq VAR_0x8006, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor
	goto_if_eq VAR_0x8006, 0xFFFF, MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse
	special IsDecorationCategoryFull
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor
	msgbox MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	special TraderDoDecorationTrade
	msgbox MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse::
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	end

MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis, MSGBOX_DEFAULT
	release
	end

@ Storyteller
MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale:
	.string "Aku adalah SANG PENDONGENG. Aku\n"
	.string "akan menceritakan kisah tentang\l"
	.string "TRAINER legendaris kepada Kamu.\p"
	.string "Maukah Kamu mendengar kisahku?$"

MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues:
	.string "Oh… Kamu membuat Aku sedih sekali…$"

MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell:
	.string "Aku tahu tentang legenda ini. Kisah\n"
	.string "mana yang ingin Aku ceritakan\l"
	.string "kepada Kamu?$"

MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales:
	.string "Tetapi, Aku tidak tahu TRAINER\n"
	.string "legendaris. Karena itu, Aku tidak\l"
	.string "punya kisah.\p"
	.string "Di mana seseorang bisa menemukan\n"
	.string "TRAINER yang pantas untuk kisah\l"
	.string "legendaris?$"

MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes:
	.string "Apa itu?! Kamu… Kamu…\p"
	.string "{STR_VAR_2} {STR_VAR_1} kali?!\p"
	.string "Itu sungguh luar biasa! Ini adalah\n"
	.string "kelahiran legenda baru!$"

MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends:
	.string "Itu membuat Aku berpikir,\n"
	.string "mungkinkah ada TRAINER lain dengan\l"
	.string "legenda yang lebih mengesankan\l"
	.string "menunggu untuk ditemukan?$"

MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales:
	.string "Apakah Kamu seorang TRAINER?\p"
	.string "Kalau begitu, beritahu Aku, apakah\n"
	.string "Kamu punya kisah yang sedikit pun\l"
	.string "legendaris?$"

@ Unused
MauvilleCity_PokemonCenter_1F_Text_HearAnotherLegendaryTale:
	.string "Ngomong-ngomong… Maukah Kamu\n"
	.string "mendengar kisah legendaris yang\l"
	.string "lain?$"

MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend:
	.string "Hmm… Aku tidak puas…\p"
	.string "Aku harap Kamu akan membawakan Aku\n"
	.string "berita yang pantas disebut legenda.$"

MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested:
	.string "Aku berharap lebih banyak orang\n"
	.string "akan tertarik mendengar kisah-kisah\l"
	.string "epik Aku tentang TRAINER\l"
	.string "legendaris.$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameTitle::
	.string "TRAINER Si Penyimpan Gembira$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameAction::
	.string "Menyimpan permainan$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameStory::
	.string "Ini adalah kisah tentang seorang\n"
	.string "TRAINER bernama {STR_VAR_3}.\p"
	.string "TRAINER ini menyimpan permainan\n"
	.string "{STR_VAR_1} kali!\p"
	.string "Tidak akan pernah ditemukan TRAINER\n"
	.string "yang lebih waspada daripada\l"
	.string "{STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedTitle::
	.string "TRAINER Sang Pencetus Tren$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedAction::
	.string "Mencetuskan tren$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedStory::
	.string "Ini adalah kisah tentang seorang\n"
	.string "TRAINER bernama {STR_VAR_3}.\p"
	.string "TRAINER ini mencetuskan tren baru\n"
	.string "{STR_VAR_1} kali!\p"
	.string "{STR_VAR_3} sedang mencetuskan tren\n"
	.string "untuk seluruh wilayah HOENN!$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedTitle::
	.string "TRAINER Si Penanam BERRY$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedAction::
	.string "Menanam BERRIES$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedStory::
	.string "Ini adalah kisah tentang seorang\n"
	.string "TRAINER bernama {STR_VAR_3}.\p"
	.string "TRAINER ini menanam BERRIES\n"
	.string "{STR_VAR_1} kali!\p"
	.string "{STR_VAR_3} adalah pencinta BERRIES\n"
	.string "yang legendaris!$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesTitle::
	.string "TRAINER Si Pencinta BIKE$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesAction::
	.string "Menukar BIKE$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesStory::
	.string "Ini adalah kisah tentang seorang\n"
	.string "TRAINER bernama {STR_VAR_3}.\p"
	.string "TRAINER ini menukar BIKE\n"
	.string "{STR_VAR_1} kali!\p"
	.string "{STR_VAR_3} pastilah mencintai BIKE\n"
	.string "dengan mendalam dan penuh gairah!$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsTitle::
	.string "TRAINER Yang Diwawancara$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsAction::
	.string "Mendapat wawancara$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsStory::
	.string "Ini adalah kisah tentang seorang\n"
	.string "TRAINER bernama {STR_VAR_3}.\p"
	.string "TRAINER ini mendapat wawancara\n"
	.string "{STR_VAR_1} kali!\p"
	.string "{STR_VAR_3} pastilah TRAINER yang\n"
	.string "menarik banyak perhatian!$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesTitle::
	.string "TRAINER Si Penggila Pertarungan$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesAction::
	.string "Bertarung$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesStory::
	.string "Ini adalah kisah tentang seorang\n"
	.string "TRAINER bernama {STR_VAR_3}.\p"
	.string "TRAINER ini bertarung {STR_VAR_1}\n"
	.string "kali!\p"
	.string "{STR_VAR_3} pastilah TRAINER yang\n"
	.string "tidak pernah bisa menolak\l"
	.string "kesempatan untuk bertarung!$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtTitle::
	.string "TRAINER Si Penangkap POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtAction::
	.string "Menangkap POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtStory::
	.string "Ini adalah kisah tentang seorang\n"
	.string "TRAINER bernama {STR_VAR_3}.\p"
	.string "TRAINER ini menangkap {STR_VAR_1}\n"
	.string "POKéMON!\p"
	.string "{STR_VAR_3} adalah penangkap\n"
	.string "POKéMON liar yang legendaris!$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtTitle::
	.string "TRAINER Si Pemancing$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtAction::
	.string "Menangkap POKéMON dengan PANCING$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtStory::
	.string "Ini adalah kisah tentang seorang\n"
	.string "TRAINER bernama {STR_VAR_3}.\p"
	.string "TRAINER ini menangkap {STR_VAR_1}\n"
	.string "POKéMON saat memancing!\p"
	.string "{STR_VAR_3} adalah pakar memancing\n"
	.string "yang legendaris!$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedTitle::
	.string "TRAINER Si Penghangat TELUR$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedAction::
	.string "Menetaskan TELUR$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedStory::
	.string "Ini adalah kisah tentang seorang\n"
	.string "TRAINER bernama {STR_VAR_3}.\p"
	.string "TRAINER ini menetaskan {STR_VAR_1}\n"
	.string "POKéMON dari TELUR!\p"
	.string "{STR_VAR_3} adalah penghangat TELUR\n"
	.string "yang legendaris!$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedTitle::
	.string "TRAINER Si Pengevolusi$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedAction::
	.string "Mengevolusikan POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedStory::
	.string "Ini adalah kisah tentang seorang\n"
	.string "TRAINER bernama {STR_VAR_3}.\p"
	.string "TRAINER ini membuat {STR_VAR_1}\n"
	.string "POKéMON berevolusi!\p"
	.string "{STR_VAR_3} adalah pengevolusi\n"
	.string "POKéMON yang terhebat!$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterTitle::
	.string "TRAINER Si Pencinta POKéMON CENTER$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterAction::
	.string "Menggunakan POKéMON CENTER$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterStory::
	.string "Ini adalah kisah tentang seorang\n"
	.string "TRAINER bernama {STR_VAR_3}.\p"
	.string "TRAINER ini menyembuhkan POKéMON\n"
	.string "{STR_VAR_1} kali di POKéMON CENTER!\p"
	.string "Tidak mungkin ada pencinta POKéMON\n"
	.string "CENTER yang lebih hebat daripada\l"
	.string "{STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeTitle::
	.string "TRAINER Si Orang Rumahan$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeAction::
	.string "Memulihkan POKéMON di rumah$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeStory::
	.string "Ini adalah kisah tentang seorang\n"
	.string "TRAINER bernama {STR_VAR_3}.\p"
	.string "TRAINER ini menyembuhkan POKéMON\n"
	.string "{STR_VAR_1} kali di rumah!\p"
	.string "Tidak mungkin ada orang rumahan\n"
	.string "yang lebih daripada {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesTitle::
	.string "TRAINER Si Pencinta SAFARI$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesAction::
	.string "Memasuki SAFARI ZONE$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesStory::
	.string "Ini adalah kisah tentang seorang\n"
	.string "TRAINER bernama {STR_VAR_3}.\p"
	.string "TRAINER ini masuk ke SAFARI ZONE\n"
	.string "{STR_VAR_1} kali!\p"
	.string "{STR_VAR_3} pastilah TRAINER yang\n"
	.string "sisi liarnya muncul di SAFARI ZONE!$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutTitle::
	.string "TRAINER Si Kegilaan CUT$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutAction::
	.string "Menggunakan CUT$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutStory::
	.string "Ini adalah kisah tentang seorang\n"
	.string "TRAINER bernama {STR_VAR_3}.\p"
	.string "TRAINER ini menggunakan CUT\n"
	.string "{STR_VAR_1} kali!\p"
	.string "{STR_VAR_3} pastilah TRAINER yang\n"
	.string "sangat suka CUT!$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashTitle::
	.string "TRAINER Si Penghancur BATU$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashAction::
	.string "Menghancurkan batu$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashStory::
	.string "Ini adalah kisah tentang seorang\n"
	.string "TRAINER bernama {STR_VAR_3}.\p"
	.string "TRAINER ini menggunakan ROCK SMASH\n"
	.string "{STR_VAR_1} kali!\p"
	.string "{STR_VAR_3} pastilah TRAINER yang\n"
	.string "tidak bisa membiarkan satu pun batu\l"
	.string "tidak dihancurkan!$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesTitle::
	.string "TRAINER Si Pencinta Pindah$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesAction::
	.string "Memindahkan SECRET BASE$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesStory::
	.string "Ini adalah kisah tentang seorang\n"
	.string "TRAINER bernama {STR_VAR_3}.\p"
	.string "TRAINER ini memindahkan SECRET BASE\n"
	.string "{STR_VAR_1} kali!\p"
	.string "{STR_VAR_3} adalah TRAINER yang\n"
	.string "suka pindah rumah!$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashTitle::
	.string "TRAINER Si Penggila SPLASH$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashAction::
	.string "Menggunakan SPLASH$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashStory::
	.string "Ini adalah kisah tentang seorang\n"
	.string "TRAINER bernama {STR_VAR_3}.\p"
	.string "TRAINER ini menggunakan SPLASH\n"
	.string "{STR_VAR_1} kali!\p"
	.string "{STR_VAR_3} pastilah TRAINER yang\n"
	.string "suka main CIPRATAN!$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleTitle::
	.string "TRAINER Si Gigih$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleAction::
	.string "Terpaksa menggunakan STRUGGLE$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleStory::
	.string "Ini adalah kisah tentang seorang\n"
	.string "TRAINER bernama {STR_VAR_3}.\p"
	.string "TRAINER ini harus mengandalkan\n"
	.string "STRUGGLE {STR_VAR_1} kali!\p"
	.string "{STR_VAR_3} adalah TRAINER gigih\n"
	.string "yang tidak pernah menyerah pada\l"
	.string "kesulitan!$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsTitle::
	.string "Jagoan SLOT$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsAction::
	.string "Memenangkan jackpot di SLOTS$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsStory::
	.string "Ini adalah kisah seorang TRAINER\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "TRAINER ini memenangkan jackpot di\n"
	.string "SLOT {STR_VAR_1} kali.\p"
	.string "{STR_VAR_3} adalah TRAINER yang\n"
	.string "beruntung di SLOT!$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsTitle::
	.string "Juara ROULETTE$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsAction::
	.string "Menang ROULETTE secara beruntun\n"
	.string "sebanyak$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsStory::
	.string "Ini adalah kisah seorang TRAINER\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "TRAINER ini menang ROULETTE\n"
	.string "{STR_VAR_1} kali berturut-turut.\p"
	.string "{STR_VAR_3} beruntung saat bola\n"
	.string "memantul di ROULETTE!$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesTitle::
	.string "Penantang MENARA PERTARUNGAN$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesAction::
	.string "Mengambil tantangan MENARA\n"
	.string "PERTARUNGAN$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesStory::
	.string "Ini adalah kisah seorang TRAINER\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "TRAINER ini mengambil tantangan\n"
	.string "MENARA PERTARUNGAN {STR_VAR_1}\l"
	.string "kali!\p"
	.string "{STR_VAR_3} adalah TRAINER yang\n"
	.string "mendambakan keunggulan di MENARA\l"
	.string "PERTARUNGAN!$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksTitle::
	.string "TRAINER Pecinta Campuran$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksAction::
	.string "Membuat {POKEBLOCK}S$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksStory::
	.string "Ini adalah kisah seorang TRAINER\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "TRAINER ini membuat {POKEBLOCK}S\n"
	.string "sebanyak {STR_VAR_1} kali!\p"
	.string "Tidak ada yang lebih mahir\n"
	.string "menggunakan BLENDER BERRY daripada\l"
	.string "{STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsTitle::
	.string "TRAINER Pecinta KONTEST$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsAction::
	.string "Mengikuti KONTEST$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsStory::
	.string "Ini adalah kisah seorang TRAINER\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "TRAINER ini mengikuti KONTEST\n"
	.string "sebanyak {STR_VAR_1} kali!\p"
	.string "{STR_VAR_3} pasti suka memamerkan\n"
	.string "POKéMON kepada orang lain!$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsTitle::
	.string "Master KONTEST$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsAction::
	.string "Memenangkan KONTEST$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsStory::
	.string "Ini adalah kisah seorang TRAINER\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "TRAINER ini memenangkan KONTEST\n"
	.string "sebanyak {STR_VAR_1} kali!\p"
	.string "{STR_VAR_3} pasti Master KONTEST\n"
	.string "yang luar biasa!$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedTitle::
	.string "Si Pembelanja Bahagia$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedAction::
	.string "Berbelanja$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedStory::
	.string "Ini adalah kisah seorang TRAINER\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "TRAINER ini membeli barang di toko\n"
	.string "sebanyak {STR_VAR_1} kali!\p"
	.string "{STR_VAR_3} pasti salah satu orang\n"
	.string "yang terlahir untuk berbelanja.$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderTitle::
	.string "TRAINER Penemu Barang$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderAction::
	.string "Menggunakan ITEMFINDER$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderStory::
	.string "Ini adalah kisah seorang TRAINER\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "TRAINER ini menggunakan ITEMFINDER\n"
	.string "sebanyak {STR_VAR_1} kali!\p"
	.string "{STR_VAR_3} pasti suka menyisir\n"
	.string "tanah untuk mencari barang\l"
	.string "tersembunyi!$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedTitle::
	.string "TRAINER Basah Kuyup$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedAction::
	.string "Kehujanan$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedStory::
	.string "Ini adalah kisah seorang TRAINER\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "TRAINER ini basah kuyup karena\n"
	.string "hujan sebanyak {STR_VAR_1} kali!\p"
	.string "Kharisma {STR_VAR_3} bahkan menarik\n"
	.string "hujan!$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexTitle::
	.string "Pembaca POKéDEX Setia$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexAction::
	.string "Mengecek POKéDEX$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexStory::
	.string "Ini adalah kisah seorang TRAINER\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "TRAINER ini mengecek POKéDEX\n"
	.string "sebanyak {STR_VAR_1} kali!\p"
	.string "{STR_VAR_3} pasti suka mengamati\n"
	.string "POKéMON di POKéDEX!$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsTitle::
	.string "Kolektor RIBBON$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsAction::
	.string "Menerima RIBBON$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsStory::
	.string "Ini adalah kisah seorang TRAINER\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "TRAINER ini menerima RIBBON\n"
	.string "sebanyak {STR_VAR_1} kali!\p"
	.string "{STR_VAR_3} pasti seorang TRAINER\n"
	.string "yang suka mengumpulkan RIBBON!$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedTitle::
	.string "TRAINER Pelompat Pinggiran$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedAction::
	.string "Melompati pinggiran$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedStory::
	.string "Ini adalah kisah seorang TRAINER\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "TRAINER ini melompati pinggiran\n"
	.string "sebanyak {STR_VAR_1} kali!\p"
	.string "Jika ada pinggiran untuk dilompati,\n"
	.string "{STR_VAR_3} tidak bisa\l"
	.string "mengabaikannya!$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedTitle::
	.string "Penonton TV Legendaris$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedAction::
	.string "Menonton TV$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedStory::
	.string "Ini adalah kisah seorang TRAINER\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "TRAINER ini menonton TV sebanyak\n"
	.string "{STR_VAR_1} kali!\p"
	.string "{STR_VAR_3} pasti suka menonton TV!$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockTitle::
	.string "TRAINER Sadar Waktu$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockAction::
	.string "Mengecek waktu$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockStory::
	.string "Ini adalah kisah seorang TRAINER\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "TRAINER ini mengecek waktu sebanyak\n"
	.string "{STR_VAR_1} kali!\p"
	.string "{STR_VAR_3} pasti TRAINER yang\n"
	.string "tepat waktu dan sadar akan waktu.$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryTitle::
	.string "Penyihir LOTERE POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryAction::
	.string "Memenangkan LOTERE POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryStory::
	.string "Ini adalah kisah seorang TRAINER\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "TRAINER ini memenangkan LOTERE\n"
	.string "POKéMON sebanyak {STR_VAR_1} kali!\p"
	.string "{STR_VAR_3} pasti punya banyak\n"
	.string "teman untuk bertukar POKéMON!$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareTitle::
	.string "TRAINER Pengguna Penitipan POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareAction::
	.string "Meninggalkan POKéMON di Penitipan\n"
	.string "POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareStory::
	.string "Ini adalah kisah seorang TRAINER\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "TRAINER ini meninggalkan POKéMON di\n"
	.string "Penitipan POKéMON {STR_VAR_1} kali!\p"
	.string "{STR_VAR_3} pasti orang yang gigih\n"
	.string "dalam membesarkan POKéMON secara\l"
	.string "agresif!$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarTitle::
	.string "TRAINER Pecinta KERETA GANTUNG$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarAction::
	.string "Menaiki KERETA GANTUNG$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarStory::
	.string "Ini adalah kisah seorang TRAINER\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "TRAINER ini menaiki KERETA GANTUNG\n"
	.string "sebanyak {STR_VAR_1} kali!\p"
	.string "{STR_VAR_3} pasti TRAINER sibuk\n"
	.string "yang selalu naik turun!$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsTitle::
	.string "TRAINER Pecinta Pemandian Air Panas$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsAction::
	.string "Mandi di pemandian air panas$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsStory::
	.string "Ini adalah kisah seorang TRAINER\n"
	.string "bernama {STR_VAR_3}.\p"
	.string "TRAINER ini mandi di pemandian air\n"
	.string "panas sebanyak {STR_VAR_1} kali!\p"
	.string "{STR_VAR_3} pasti TRAINER dengan\n"
	.string "kulit sehalus bayi!$"

MauvilleCity_PokemonCenter_1F_EventScript_Storyteller::
	lock
	faceplayer
	setvar VAR_0x8008, 0
	setvar VAR_0x8009, 0
	setvar VAR_0x800A, 0
	setvar VAR_0x800B, 0
	msgbox MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, StorytellerGetFreeStorySlot
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales
	message MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell
	waitmessage
	special StorytellerStoryListMenu
	waitstate
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection
	setvar VAR_0x8008, 1
	special Script_StorytellerDisplayStory
	waitmessage
	waitbuttonpress
	specialvar VAR_RESULT, StorytellerUpdateStat
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales
	goto MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale

MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection::
	goto MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	end

MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends, MSGBOX_DEFAULT
	specialvar VAR_RESULT, HasStorytellerAlreadyRecorded
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd
	goto MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales

MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales, MSGBOX_DEFAULT
MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, Script_StorytellerInitializeRandomStat
	goto_if_eq VAR_RESULT, 1, MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale
	msgbox MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller::
	msgbox MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

@ Unused
MauvilleCity_PokemonCenter_1F_EventScript_WaitingForRecordMix::
	msgbox MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd::
	release
	end

@ Giddy
MauvilleCity_PokemonCenter_1F_Text_HearMyStory:
	.string "Aku RIANG! Aku punya cerita yang\n"
	.string "memukau untuk kamu!\p"
	.string "Apakah kamu mau dengar ceritaku?$"

MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues:
	.string "Oh… Kamu membuatku merasa sedih…$"

MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking:
	.string "Juga, aku sedang berpikir…$"

MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain:
	.string "Itu saja, kurasa…\p"
	.string "Kita harus mengobrol lagi! Sampai\n"
	.string "jumpa!$"

MauvilleCity_PokemonCenter_1F_EventScript_Giddy::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_HearMyStory, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale::
	special GiddyShouldTellAnotherTale
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale::
	special GiddyShouldTellAnotherTale
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale::
	msgbox MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	end

@ Giddy will continue to tell stories regardless of whether yes or no is selected below.
@ Each story there is a 10% chance it will be his last. Otherwise he will stop at 10 stories.
MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale::
	special GenerateGiddyLine
	special ShowFieldMessageStringVar4
	waitmessage
	yesnobox 20, 8
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy::
	msgbox MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong:
	.string "Hai, Aku adalah BARD. Maukah Kamu\n"
	.string "mendengar laguku?$"

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1:
	.string "Oh… Kamu membuatku merasa murung…$"

MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers:
	.string "Oh, lagu yang mengharukan… Aku\n"
	.string "harap Aku bisa memainkannya untuk\l"
	.string "orang lain…$"

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics:
	.string "Jadi? Bagaimana menurut Kamu\n"
	.string "laguku?\p"
	.string "Tapi Aku tidak terlalu senang\n"
	.string "dengan liriknya.\p"
	.string "Maukah Kamu menulis lirik baru\n"
	.string "untukku?$"

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2:
	.string "Oh… Kamu membuatku merasa murung…$"

MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou:
	.string "Terima kasih banyak! Biar Aku\n"
	.string "menyanyikannya untuk Kamu.$"

MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo:
	.string "Apakah seperti itu Kamu ingin\n"
	.string "lagumu berlanjut?$"

MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile:
	.string "Baiklah! Itu dia. Aku akan\n"
	.string "menyanyikan lagu ini untuk\l"
	.string "sementara waktu.$"


MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening:
	.string "Hei, yo! Mereka memanggilku\n"
	.string "HIPSTER. Aku akan mengajarimu apa\l"
	.string "yang keren dan terkini.$"

MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou:
	.string "Tapi, hei, Aku sudah mengajarimu\n"
	.string "apa yang keren dan terkini.\p"
	.string "Aku ingin menyebarkan kabar baik\n"
	.string "ini kepada orang lain.$"

MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach:
	.string "Tapi, hei, Kamu sudah tahu banyak\n"
	.string "tentang apa yang keren dan terkini.\p"
	.string "Aku tidak punya hal baru untuk\n"
	.string "diajarkan padamu!$"

MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfWord:
	.string "Hei, pernahkah Kamu dengar tentang\n"
	.string "“{STR_VAR_1} Apa artinya? Yah…\l"
	.string "Tanya saja pada ayah atau ibumu,\l"
	.string "oke?$"
