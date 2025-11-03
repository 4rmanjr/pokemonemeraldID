RustboroCity_PokemonSchool_MapScripts::
	.byte 0

RustboroCity_PokemonSchool_EventScript_Blackboard::
	lockall
	msgbox RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic::
	message RustboroCity_PokemonSchool_Text_ReadWhichTopic
	waitmessage
	multichoicegrid 8, 1, MULTI_STATUS_INFO, 3, FALSE
	switch VAR_RESULT
	case 0, RustboroCity_PokemonSchool_EventScript_Poison
	case 1, RustboroCity_PokemonSchool_EventScript_Paralysis
	case 2, RustboroCity_PokemonSchool_EventScript_Sleep
	case 3, RustboroCity_PokemonSchool_EventScript_Burn
	case 4, RustboroCity_PokemonSchool_EventScript_Freeze
	case 5, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	case MULTI_B_PRESSED, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	end

RustboroCity_PokemonSchool_EventScript_Poison::
	msgbox RustboroCity_PokemonSchool_Text_ExplainPoison, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Paralysis::
	msgbox RustboroCity_PokemonSchool_Text_ExplainParalysis, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Sleep::
	msgbox RustboroCity_PokemonSchool_Text_ExplainSleep, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Burn::
	msgbox RustboroCity_PokemonSchool_Text_ExplainBurn, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Freeze::
	msgbox RustboroCity_PokemonSchool_Text_ExplainFreeze, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ExitTopicSelect::
	releaseall
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid1::
	msgbox RustboroCity_PokemonSchool_Text_TradingRightNow, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid2::
	msgbox RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_RichBoy::
	msgbox RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_Lass::
	msgbox RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_SchoolKidM::
	msgbox RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_StudentNotebook::
	msgbox RustboroCity_PokemonSchool_Text_StudentsNotes, MSGBOX_SIGN
	end

RustboroCity_PokemonSchool_EventScript_Teacher::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_QUICK_CLAW, RustboroCity_PokemonSchool_EventScript_GaveQuickClaw
	call_if_eq VAR_FACING, DIR_EAST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast
	call_if_eq VAR_FACING, DIR_WEST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest
	msgbox RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw, MSGBOX_DEFAULT
	giveitem ITEM_QUICK_CLAW
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	setflag FLAG_RECEIVED_QUICK_CLAW
	release
	end

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_GaveQuickClaw::
	msgbox RustboroCity_PokemonSchool_Text_ExplainQuickClaw, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	release
	end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest:
	walk_left
	walk_down
	walk_down
	walk_right
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	walk_right
	step_end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_right
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

RustboroCity_PokemonSchool_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE, RustboroCity_PokemonSchool_EventScript_ScottWatchStudents
	goto_if_set FLAG_MET_SCOTT_RUSTBORO, RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_RUSTBORO
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready::
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge::
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottWatchStudents::
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges:
	.string "Papan tulis ini mencantumkan perubahan\n"
	.string "status yang dapat memengaruhi POKéMON dalam pertarungan.$"

RustboroCity_PokemonSchool_Text_ReadWhichTopic:
	.string "Topik mana yang ingin kamu baca?$"

RustboroCity_PokemonSchool_Text_ExplainPoison:
	.string "Jika POKéMON keracunan, ia akan\n"
	.string "terus kehilangan HP secara bertahap.\p"
	.string "Efek racun tetap ada setelah\n"
	.string "pertarungan.\p"
	.string "HP POKéMON yang keracunan akan\n"
	.string "berkurang saat ia bepergian.\p"
	.string "Sembuhkan keracunan menggunakan ANTIDOTE.$"

RustboroCity_PokemonSchool_Text_ExplainParalysis:
	.string "Jika POKéMON lumpuh,\n"
	.string "SPEED-nya akan menurun.\p"
	.string "Ia juga mungkin tidak dapat bergerak\n"
	.string "saat dalam pertarungan.\p"
	.string "Kelumpuhan tetap ada setelah pertarungan.\n"
	.string "Sembuhkan menggunakan PARLYZ HEAL.$"

RustboroCity_PokemonSchool_Text_ExplainSleep:
	.string "Jika POKéMON tertidur, ia tidak akan\n"
	.string "bisa menyerang.\p"
	.string "POKéMON mungkin akan bangun dengan\n"
	.string "sendirinya, tetapi jika pertarungan\l"
	.string "berakhir saat ia tidur, ia akan tetap tidur.\p"
	.string "Bangunkan menggunakan AWAKENING.$"

RustboroCity_PokemonSchool_Text_ExplainBurn:
	.string "Luka bakar mengurangi kekuatan ATTACK,\n"
	.string "dan secara bertahap mengurangi HP korban.\p"
	.string "Luka bakar tetap ada setelah pertarungan.\n"
	.string "Sembuhkan luka bakar menggunakan BURN HEAL.$"

RustboroCity_PokemonSchool_Text_ExplainFreeze:
	.string "Jika POKéMON membeku, ia menjadi\n"
	.string "tidak berdaya sama sekali.\p"
	.string "Ia akan tetap membeku setelah pertarungan.\n"
	.string "Cairkan menggunakan ICE HEAL.$"

RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw:
	.string "Murid yang tidak belajar akan\n"
	.string "merasakan sedikit QUICK CLAW-ku.\p"
	.string "Apakah kamu murid yang baik atau tidak\n"
	.string "akan terlihat dari caramu menggunakan\l"
	.string "item ini.$"

RustboroCity_PokemonSchool_Text_ExplainQuickClaw:
	.string "POKéMON yang memegang QUICK CLAW akan\n"
	.string "sesekali mempercepat dan bergerak\l"
	.string "lebih dulu dari lawannya.\p"
	.string "Ada banyak item lain yang dimaksudkan\n"
	.string "untuk dipegang oleh POKéMON.\p"
	.string "Hanya itu saja akan memberimu banyak\n"
	.string "topik untuk dipelajari!$"

RustboroCity_PokemonSchool_Text_TradingRightNow:
	.string "Aku sedang menukar POKéMON dengan\n"
	.string "temanku sekarang.$"

RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot:
	.string "Aku selalu menginginkan SEEDOT, dan\n"
	.string "akhirnya aku mendapatkannya!$"

RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems:
	.string "POKéMON bisa memegang item, tapi mereka\n"
	.string "tidak tahu apa yang harus dilakukan\l"
	.string "dengan item buatan manusia seperti\lPOTION dan ANTIDOTE.$"

RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself:
	.string "Kamu tahu bagaimana beberapa gerakan\n"
	.string "POKéMON bisa membuat POKéMON bingung?\p"
	.string "POKéMON yang bingung kadang-kadang\n"
	.string "akan menyerang dirinya sendiri\ltanpa sengaja.\p"
	.string "Tapi setelah keluar dari pertarungan,\n"
	.string "ia akan kembali normal.$"

RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry:
	.string "POKéMON yang memegang BERRY akan\n"
	.string "menyembuhkan dirinya sendiri…\p"
	.string "Ada banyak jenis item yang bisa\n"
	.string "dipegang POKéMON…\p"
	.string "Wah, sulit sekali mencatatnya…$"

RustboroCity_PokemonSchool_Text_StudentsNotes:
	.string "Ini adalah buku catatan siswa…\p"
	.string "POKéMON harus ditangkap menggunakan\n"
	.string "POKé BALL.\p"
	.string "Hingga enam POKéMON dapat menemani\n"
	.string "seorang TRAINER.\p"
	.string "Seorang TRAINER adalah seseorang yang\n"
	.string "menangkap POKéMON, membesarkannya,\l"
	.string "dan bertarung dengannya.\p"
	.string "Misi seorang TRAINER adalah mengalahkan\n"
	.string "TRAINER kuat yang menanti penantang\l"
	.string "di POKéMON GYM.$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut:
	.string "Halo? Bukankah kita pernah bertemu?\n"
	.string "Aku rasa di PETALBURG CITY.\p"
	.string "Izinkan aku memperkenalkan diri.\n"
	.string "Namaku SCOTT.\p"
	.string "Aku telah berkeliling ke mana-mana\n"
	.string "mencari TRAINER yang luar biasa.\p"
	.string "Lebih spesifiknya, aku mencari\n"
	.string "ahli pertarungan POKéMON.\p"
	.string "Jadi, apa yang membawamu ke SEKOLAH ini?\n"
	.string "Apakah kamu juga seorang TRAINER?\p"
	.string "Hal pertama yang harus kamu lakukan\n"
	.string "adalah membuat POKéMON mempelajari\lgerakan CUT.\p"
	.string "Jika aku ingat benar, seseorang di\n"
	.string "kota ini memiliki CUT.$"

RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown:
	.string "SCOTT: Hmm…\p"
	.string "Tingkat bakat para siswa di sini\n"
	.string "tidak diketahui. Potensinya ada.$"

RustboroCity_PokemonSchool_Text_ScottStoneBadge:
	.string "SCOTT: Oh, apa itu?\p"
	.string "Itu STONE BADGE, kan?\n"
	.string "Itu cukup mengesankan, menurutku.\p"
	.string "Tapi, tahukah kamu, aku ingin sekali\n"
	.string "melihatmu bertarung.\p"
	.string "Sulit untuk mengetahui seperti apa kamu\n"
	.string "sebagai TRAINER dari LEAGUE BADGE.$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge:
	.string "Halo? Bukankah kita pernah bertemu?\n"
	.string "Aku rasa di PETALBURG CITY.\p"
	.string "Izinkan aku memperkenalkan diri.\n"
	.string "Namaku SCOTT.\p"
	.string "Aku telah berkeliling ke mana-mana\n"
	.string "mencari TRAINER yang luar biasa.\p"
	.string "Lebih spesifiknya, aku mencari\n"
	.string "ahli pertarungan POKéMON.\p"
	.string "Oh, apa itu?\n"
	.string "Itu STONE BADGE, kan?\p"
	.string "Itu cukup mengesankan, menurutku, untuk\n"
	.string "seorang TRAINER pemula sepertimu.\p"
	.string "Tapi, tahukah kamu, aku ingin sekali\n"
	.string "melihatmu bertarung.\p"
	.string "Sulit untuk mengetahui seperti apa kamu\n"
	.string "sebagai TRAINER dari LEAGUE BADGE.$"

