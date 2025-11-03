DewfordTown_Hall_MapScripts::
	.byte 0

DewfordTown_Hall_EventScript_Girl::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special IsTrendyPhraseBoring
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Hall_EventScript_GirlBoredOfTrend
	msgbox DewfordTown_Hall_Text_CantImagineLifeWithoutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_GirlBoredOfTrend::
	msgbox DewfordTown_Hall_Text_GettingBoredOfTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Woman::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TeachingMonAboutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Man::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special BufferDeepLinkPhrase
	msgbox DewfordTown_Hall_Text_DeepLinkBetweenXAndY, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DewfordTown_Hall_EventScript_ConfirmTrendLink
	goto_if_eq VAR_RESULT, NO, DewfordTown_Hall_EventScript_RejectTrendLink
	end

DewfordTown_Hall_EventScript_ConfirmTrendLink::
	msgbox DewfordTown_Hall_Text_MyHunchWasRight, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_RejectTrendLink::
	msgbox DewfordTown_Hall_Text_NotEasyToKeepUp, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_ExpertM::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TVShowAboutTrend, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEWFORD_HALL_EXPERT_M, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_Twin::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEWFORD_HALL_TWIN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_LittleBoy::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_CollectTrendMerchandise, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Bookshelf::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_BooksAboutTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_Painting::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_ScreamTitle
	case 4, DewfordTown_Hall_EventScript_ScreamTitle
	case 1, DewfordTown_Hall_EventScript_SmileTitle
	case 5, DewfordTown_Hall_EventScript_ScreamTitle
	case 2, DewfordTown_Hall_EventScript_LastTitle
	case 6, DewfordTown_Hall_EventScript_LastTitle
	case 3, DewfordTown_Hall_EventScript_BirthTitle
	case 7, DewfordTown_Hall_EventScript_LastTitle
	end

DewfordTown_Hall_EventScript_ScreamTitle::
	msgbox DewfordTown_Hall_Text_TrendsScream, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SmileTitle::
	msgbox DewfordTown_Hall_Text_TrendsSmile, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_LastTitle::
	msgbox DewfordTown_Hall_Text_LastTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_BirthTitle::
	msgbox DewfordTown_Hall_Text_BirthOfTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SchoolKidM::
	lockall
	setvar VAR_0x8008, 0
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_PsychicM::
	lockall
	setvar VAR_0x8008, 1
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_DoTrendDebate::
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_TrendDebate1
	case 1, DewfordTown_Hall_EventScript_TrendDebate1
	case 2, DewfordTown_Hall_EventScript_TrendDebate2
	case 3, DewfordTown_Hall_EventScript_TrendDebate2
	case 4, DewfordTown_Hall_EventScript_TrendDebate3
	case 5, DewfordTown_Hall_EventScript_TrendDebate3
	case 6, DewfordTown_Hall_EventScript_TrendDebate4
	case 7, DewfordTown_Hall_EventScript_TrendDebate5
	end

DewfordTown_Hall_EventScript_TrendDebate1::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_SawTrendCoolestThing, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_AllegedTrendNotAuthentic, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate2::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_ComposedTrendThemeSong, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WorkOnYourSinging, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate3::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_OrganizeTrendParty, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_BrilliantIndeed, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate4::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_TrendHasBecomePartOfLife, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate5::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WellBeTrendDuo, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_DontMovePlayer1::
	return

DewfordTown_Hall_EventScript_DebateReact1::
	applymovement LOCALID_DEWFORD_HALL_PSYCHIC_M, DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft
	waitmovement 0
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactWest
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_DontMovePlayer2
	end

DewfordTown_Hall_EventScript_PlayerReactWest::
	goto_if_eq VAR_FACING, DIR_EAST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

DewfordTown_Hall_EventScript_DontMovePlayer2::
	return

DewfordTown_Hall_EventScript_DebateReact2::
	applymovement LOCALID_DEWFORD_HALL_SCHOOL_KID_M, DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight
	waitmovement 0
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactNorthSouth
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_PlayerReactEast
	end

DewfordTown_Hall_EventScript_PlayerReactNorthSouth::
	call_if_eq VAR_FACING, DIR_NORTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp
	call_if_eq VAR_FACING, DIR_SOUTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

DewfordTown_Hall_EventScript_PlayerReactEast::
	goto_if_eq VAR_FACING, DIR_WEST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft:
	walk_in_place_left
	step_end

DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight:
	walk_in_place_right
	step_end

DewfordTown_Hall_EventScript_SludgeBombMan::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	goto_if_set FLAG_RECEIVED_TM_SLUDGE_BOMB, DewfordTown_Hall_EventScript_ReceivedSludgeBomb
	msgbox DewfordTown_Hall_Text_GiveYouSludgeBomb, MSGBOX_DEFAULT
	giveitem ITEM_TM_SLUDGE_BOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_SLUDGE_BOMB
	release
	end

DewfordTown_Hall_EventScript_ReceivedSludgeBomb::
	msgbox DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_Text_CantImagineLifeWithoutTrend:
	.string "Apa yang lagi tren? Yah, sudah\n"
	.string "pasti “{STR_VAR_1}”!\p"
	.string "Aku tidak bisa membayangkan hidup\n"
	.string "tanpa “{STR_VAR_1}”!$"

DewfordTown_Hall_Text_GettingBoredOfTrend:
	.string "Apa yang lagi tren? Yah, sudah\n"
	.string "pasti “{STR_VAR_1}”!\p"
	.string "Tapi aku mulai agak bosan\n"
	.string "dengannya.\p"
	.string "Aku harus mencari hal besar\n"
	.string "berikutnya.$"

DewfordTown_Hall_Text_TeachingMonAboutTrend:
	.string "Aku sedang mengajari POKéMON-ku\n"
	.string "tentang “{STR_VAR_1},” tapi tidak\l"
	.string "berjalan lancar.\p"
	.string "Kurasa itu agak terlalu berlebihan.$"

DewfordTown_Hall_Text_DeepLinkBetweenXAndY:
	.string "Aku sekarang sedang mempelajari\n"
	.string "“{STR_VAR_1}” yang keren dan\l"
	.string "trendi.\p"
	.string "Benarkah ada hubungan erat antara\n"
	.string "“{STR_VAR_1}” dan “{STR_VAR_2}”?$"

DewfordTown_Hall_Text_MyHunchWasRight:
	.string "Oh! Jadi, firasatku benar!\p"
	.string "Aku selangkah lebih dekat untuk\n"
	.string "menjadi keren dan gaul, gila!$"

DewfordTown_Hall_Text_NotEasyToKeepUp:
	.string "Apa?! Benarkah begitu?!\p"
	.string "Tidak mudah bagi pria tua sepertiku\n"
	.string "untuk mengikuti tren!$"

DewfordTown_Hall_Text_TVShowAboutTrend:
	.string "Seluruh urusan tentang\n"
	.string "“{STR_VAR_1}” ini… Apakah tidak ada\l"
	.string "acara TV tentang itu?$"

DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea:
	.string "Di seberang lautan…\p"
	.string "Apakah “{STR_VAR_1}” bahkan lebih\n"
	.string "populer?$"

DewfordTown_Hall_Text_CollectTrendMerchandise:
	.string "Aku mengoleksi merchandise resmi\n"
	.string "berlisensi “{STR_VAR_1}”.\p"
	.string "Aku punya BONEKA “{STR_VAR_1}”\n"
	.string "resmi…\p"
	.string "Pakaian merek “{STR_VAR_1}” resmi…\p"
	.string "Dan buku bergambar “{STR_VAR_1}”\n"
	.string "berlisensi resmi.\p"
	.string "Heheh, aku punya! Aku tidak akan\n"
	.string "berbagi apa pun denganmu!$"

DewfordTown_Hall_Text_BooksAboutTrend:
	.string "MENGIDENTIFIKASI “{STR_VAR_1}” YANG\n"
	.string "BAGUS & “{STR_VAR_1}” YANG BURUK…\p"
	.string "HUBUNGAN ANTARA “{STR_VAR_1}” DAN\n"
	.string "POKéMON…\p"
	.string "“{STR_VAR_1}” YANG BERGUNA…\p"
	.string "Itu penuh sesak dengan buku-buku\n"
	.string "tentang “{STR_VAR_1}.”$"

DewfordTown_Hall_Text_TrendsScream:
	.string "Judulnya adalah “TERIAKAN\n"
	.string "{STR_VAR_1}”.$"

DewfordTown_Hall_Text_TrendsSmile:
	.string "Judulnya adalah “SENYUM\n"
	.string "{STR_VAR_1}”.$"

DewfordTown_Hall_Text_LastTrend:
	.string "Judulnya adalah “{STR_VAR_1} YANG\n"
	.string "TERAKHIR”.$"

DewfordTown_Hall_Text_BirthOfTrend:
	.string "Judulnya adalah “KELAHIRAN\n"
	.string "{STR_VAR_1}”.$"

DewfordTown_Hall_Text_SawTrendCoolestThing:
	.string "Aku melihat “{STR_VAR_1}”! Keren,\n"
	.string "kan?\p"
	.string "Itu, seperti, hal paling keren yang\n"
	.string "ada!\p"
	.string "Itu luar biasa! Itu yang asli, oh\n"
	.string "ya!$"

DewfordTown_Hall_Text_AllegedTrendNotAuthentic:
	.string "Oh, tidak, tidak, tidak.\p"
	.string "Dugaan “{STR_VAR_1}” yang kamu\n"
	.string "klaim telah lihat--itu bukan yang\l"
	.string "asli.\p"
	.string "Yang otentik jauh lebih… Bagaimana\n"
	.string "Aku harus mengatakannya? Lebih\l"
	.string "tajam, namun lebih lembut!\p"
	.string "Ah, tidak masalah. Ini\n"
	.string "mencengangkan!$"

DewfordTown_Hall_Text_ComposedTrendThemeSong:
	.string "Hei, dengarkan, Aku membuat lagu\n"
	.string "tema untuk “{STR_VAR_1}.”\p"
	.string "“{STR_VAR_1}” benar-benar populer\n"
	.string "saat ini.\p"
	.string "Oke, dengarkan! … …\p"
	.string "Oh! {STR_VAR_1}!\p"
	.string "{STR_VAR_1} yang luar biasa!$"

DewfordTown_Hall_Text_WorkOnYourSinging:
	.string "… …\p"
	.string "Aku berani bilang, kawan, ada\n"
	.string "baiknya kamu berlatih menyanyi\l"
	.string "sebelum kamu main-main dengan\l"
	.string "“{STR_VAR_1}.”$"

DewfordTown_Hall_Text_OrganizeTrendParty:
	.string "Pokoknya, seperti yang Aku katakan\n"
	.string "tadi, kita harus berkumpul dan\l"
	.string "mengadakan pesta “{STR_VAR_1}” di\l"
	.string "pulau ini.$"

DewfordTown_Hall_Text_BrilliantIndeed:
	.string "Oh, ide yang sangat bagus!\p"
	.string "Ini akan menentukan sekali dan\n"
	.string "untuk selamanya siapa yang terbaik\l"
	.string "di “{STR_VAR_1}.” Memang brilian!\p"
	.string "Mulai hari ini, hidup kita akan\n"
	.string "berputar di sekitar “{STR_VAR_1}”!$"

DewfordTown_Hall_Text_TrendHasBecomePartOfLife:
	.string "Aku sedang berpikir, sih…\p"
	.string "Tidakkah kamu setuju bahwa\n"
	.string "“{STR_VAR_1}” telah berkembang dari\l"
	.string "sesuatu yang trendi menjadi bagian\l"
	.string "dari kehidupan sehari-hari kita?$"

DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind:
	.string "Maaf? Sebanyak itu, apa?\p"
	.string "Namun, memang benar bahwa\n"
	.string "“{STR_VAR_1}” sangat membebani\l"
	.string "pikiranmu, baik saat kamu bangun\l"
	.string "maupun tidur.\p"
	.string "Tentu saja, kamu adalah PROFESOR\n"
	.string "“{STR_VAR_1}”, sobat lama!$"

DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible:
	.string "Jika kamu dan aku bekerja sama\n"
	.string "sebagai duo, kita akan menjadi tak\l"
	.string "terkalahkan dalam segala hal\l"
	.string "“{STR_VAR_1}”!$"

DewfordTown_Hall_Text_WellBeTrendDuo:
	.string "Tepat sekali, temanku!\p"
	.string "Kita akan menjadi DUO\n"
	.string "“{STR_VAR_1}”!\p"
	.string "Bukankah itu gambaran yang bagus?\n"
	.string "Hahahah!$"

DewfordTown_Hall_Text_GiveYouSludgeBomb:
	.string "Bagiku, SLUDGE BOMB berada di\n"
	.string "puncak popularitas. Ini yang\l"
	.string "terbaik.\p"
	.string "Hah? Kamu bilang kamu tidak tahu\n"
	.string "tentang SLUDGE BOMB?\p"
	.string "Itu benar-benar menyedihkan. Aku\n"
	.string "akan memberimu satu.$"

DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo:
	.string "Aku suka SLUDGE BOMB.\p"
	.string "Tapi POKéMON dengan jurus\n"
	.string "“{STR_VAR_1}” juga sedang tren.$"
