PetalburgWoods_MapScripts::
	.byte 0

PetalburgWoods_EventScript_DevonResearcherLeft::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherLeft
	waitmovement 0
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachPlayer
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement LOCALID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitLeft
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherRight::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerRight
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherRight
	waitmovement 0
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement LOCALID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitRight
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherIntro::
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherLookAround
	waitmovement 0
	msgbox PetalburgWoods_Text_NotAOneToBeFound, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_DevonResearcherPostBattle::
	msgbox PetalburgWoods_Text_YouveGotSomeNerve, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaRunAway
	waitmovement 0
	removeobject LOCALID_PETALBURG_WOODS_GRUNT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox PetalburgWoods_Text_ThatWasAwfullyClose, MSGBOX_DEFAULT
	giveitem ITEM_GREAT_BALL
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_BagFull
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_BagFull::
	msgbox PetalburgWoods_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_DevonResearcherFinish::
	msgbox PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro, MSGBOX_DEFAULT
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherStartExit
	waitmovement 0
	msgbox PetalburgWoods_Text_ICantBeWastingTime, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_RemoveDevonResearcher::
	removeobject LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE
	setvar VAR_PETALBURG_WOODS_STATE, 1
	releaseall
	end

PetalburgWoods_Movement_DevonResearcherLookAround:
	face_up
	delay_16
	delay_4
	face_right
	delay_16
	delay_8
	face_left
	delay_16
	delay_8
	face_down
	delay_16
	face_right
	delay_16
	delay_8
	face_up
	delay_16
	step_end

PetalburgWoods_Movement_DevonResearcherExitLeft:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft:
	delay_16
	face_player
	walk_down
	walk_down
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerRight:
	delay_16
	face_player
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

PetalburgWoods_Movement_DevonResearcherExitRight:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_WatchResearcherLeave:
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight:
	walk_fast_down
	walk_fast_right
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherStartExit:
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_up
	step_end

PetalburgWoods_Movement_AquaApproachResearcherLeft:
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaBackOff:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

PetalburgWoods_Movement_AquaRunAway:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachResearcherRight:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaEntrance:
	walk_down
	walk_down
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachPlayer:
	walk_down
	step_end

PetalburgWoods_EventScript_Boy1::
	msgbox PetalburgWoods_Text_StayOutOfTallGrass, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Boy2::
	msgbox PetalburgWoods_Text_HiddenItemsExplanation, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_MIRACLE_SEED, PetalburgWoods_EventScript_ExplainMiracleSeed
	msgbox PetalburgWoods_Text_TryUsingThisItem, MSGBOX_DEFAULT
	giveitem ITEM_MIRACLE_SEED
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MIRACLE_SEED
	release
	end

PetalburgWoods_EventScript_ExplainMiracleSeed::
	msgbox PetalburgWoods_Text_MiracleSeedExplanation, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_Sign1::
	msgbox PetalburgWoods_Text_TrainerTipsExperience, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Sign2::
	msgbox PetalburgWoods_Text_TrainerTipsPP, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Lyle::
	trainerbattle_single TRAINER_LYLE, PetalburgWoods_Text_GoBugPokemonTeam, PetalburgWoods_Text_ICouldntWin
	msgbox PetalburgWoods_Text_ImOutOfPokeBalls, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_EventScript_James::
	trainerbattle_single TRAINER_JAMES_1, PetalburgWoods_Text_InstantlyPopularWithBugPokemon, PetalburgWoods_Text_CantBePopularIfILose, PetalburgWoods_EventScript_TryRegisterJames
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, PetalburgWoods_EventScript_JamesRematch
	setvar VAR_0x8004, TRAINER_JAMES_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_TryRegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_TryRegisterJames::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames
	release
	end

PetalburgWoods_EventScript_RegisterJames::
	msgbox PetalburgWoods_Text_IWantRematch1, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_TryRegisterJames2::
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_RegisterJames2::
	msgbox PetalburgWoods_Text_IWantRematch2, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_JamesRematch::
	trainerbattle_rematch TRAINER_JAMES_1, PetalburgWoods_Text_MyPokemonHaveGrown, PetalburgWoods_Text_CantBePopularIfLose
	msgbox PetalburgWoods_Text_IveBeenTrainingHard, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_Text_NotAOneToBeFound:
	.string "Hmmm… Tidak ada satu pun yang\n"
	.string "ketemu…$"

PetalburgWoods_Text_HaveYouSeenShroomish:
	.string "Halo, apa Kamu melihat POKéMON\n"
	.string "bernama SHROOMISH di sekitar sini?\p"
	.string "Aku sangat suka POKéMON itu.$"

PetalburgWoods_Text_IWasGoingToAmbushYou:
	.string "Aku tadinya mau menyergap Kamu,\n"
	.string "tapi Kamu malah berlama-lama di\l"
	.string "HUTAN PETALBURG, kan?\p"
	.string "Aku bosan menunggu, jadi Aku datang\n"
	.string "ke sini!$"

PetalburgWoods_Text_HandOverThosePapers:
	.string "Kamu! PENELITI DEVON!\p"
	.string "Serahkan dokumen-dokumen itu!$"

PetalburgWoods_Text_YouHaveToHelpMe:
	.string "Aiyeeeh!\p"
	.string "Kamu POKéMON TRAINER, kan? Kamu\n"
	.string "harus menolong Aku, kumohon!$"

PetalburgWoods_Text_NoOneCrossesTeamAqua:
	.string "Hah? Apa yang Kamu pikirkan? Apa,\n"
	.string "Kamu mau melindunginya?\p"
	.string "Tidak ada yang lolos jika berurusan\n"
	.string "dengan TEAM AQUA, bahkan anak kecil\l"
	.string "sekalipun!\p"
	.string "Ayo, tantang Aku bertarung!$"

PetalburgWoods_Text_YoureKiddingMe:
	.string "Kamu bercanda! Kamu tangguh!$"

PetalburgWoods_Text_YouveGotSomeNerve:
	.string "Grrr… Kamu berani-beraninya ikut\n"
	.string "campur urusan TEAM AQUA! Ayo,\l"
	.string "tantang Aku bertarung lagi!\p"
	.string "Aku harap Aku bisa melakukannya,\n"
	.string "tapi POKéMON-ku habis…\p"
	.string "Dan, hei, kami dari TEAM AQUA juga\n"
	.string "mengincar sesuatu di RUSTBORO.\p"
	.string "Hari ini Aku biarkan Kamu pergi!$"

PetalburgWoods_Text_ThatWasAwfullyClose:
	.string "Fiuh… Itu hampir saja terjadi!\p"
	.string "Berkat Kamu, dia tidak merampas\n"
	.string "dokumen penting ini dari Aku.\p"
	.string "Begini, Aku akan memberimu GREAT\n"
	.string "BALL sebagai ucapan terima kasih\l"
	.string "Aku!$"

PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro:
	.string "Bukankah anggota TEAM AQUA itu\n"
	.string "bilang mereka juga mengincar\l"
	.string "sesuatu di RUSTBORO?$"

PetalburgWoods_Text_ICantBeWastingTime:
	.string "Gawat! Ini krisis! Aku tidak boleh\n"
	.string "membuang waktu!$"

PetalburgWoods_Text_YoureLoadedWithItems:
	.string "Barang Kamu sudah penuh. Aku tidak\n"
	.string "bisa memberimu GREAT BALL ini.$"

PetalburgWoods_Text_GoBugPokemonTeam:
	.string "Aku menangkap banyak sekali\n"
	.string "POKéMON!\p"
	.string "Maju, maju, maju! Tim POKéMON\n"
	.string "Serangga Aku!$"

PetalburgWoods_Text_ICouldntWin:
	.string "Aku punya POKéMON sebanyak ini,\n"
	.string "tapi Aku tetap tidak bisa menang…$"

PetalburgWoods_Text_ImOutOfPokeBalls:
	.string "Aku menangkap banyak POKéMON.\n"
	.string "Sekarang POKé BALL-ku habis.$"

PetalburgWoods_Text_InstantlyPopularWithBugPokemon:
	.string "Kalau Kamu bawa POKéMON Serangga ke\n"
	.string "sekolah, Kamu akan langsung\l"
	.string "populer!$"

PetalburgWoods_Text_CantBePopularIfILose:
	.string "Aku tidak bisa populer kalau Aku\n"
	.string "kalah.$"

PetalburgWoods_Text_PeopleRespectYou:
	.string "Kalau Kamu punya POKéMON Serangga\n"
	.string "yang besar, orang-orang akan\l"
	.string "menghormati Kamu.$"

PetalburgWoods_Text_IWantRematch1:
	.string "Aku mau tanding ulang saat POKéMON\n"
	.string "Serangga Aku sudah besar nanti!\p"
	.string "Aku mendaftarkan Kamu ke POKéNAV\n"
	.string "Aku!$"

PetalburgWoods_Text_IWantRematch2:
	.string "Aku mau tanding ulang saat POKéMON\n"
	.string "Serangga Aku sudah besar nanti!\p"
	.string "Aku mendaftarkan Kamu ke POKéNAV\n"
	.string "Aku!$"

PetalburgWoods_Text_MyPokemonHaveGrown:
	.string "POKéMON Serangga Aku sudah tumbuh.\n"
	.string "Aku akan populer lagi.$"

PetalburgWoods_Text_CantBePopularIfLose:
	.string "Aku tidak bisa populer kalau Aku\n"
	.string "kalah.$"

PetalburgWoods_Text_IveBeenTrainingHard:
	.string "Kamu bisa jadi populer kalau punya\n"
	.string "POKéMON kuat, kan? Jadi, Aku\l"
	.string "berlatih keras.$"

PetalburgWoods_Text_StayOutOfTallGrass:
	.string "Hei! POKéMON Kamu baik-baik saja?\p"
	.string "Kalau POKéMON Kamu lemah dan Kamu\n"
	.string "mau menghindari pertarungan, Kamu\l"
	.string "harus menjauhi rumput tinggi.$"

PetalburgWoods_Text_HiddenItemsExplanation:
	.string "Kadang-kadang, ada benda di tanah\n"
	.string "meskipun Kamu tidak bisa\l"
	.string "melihatnya.\p"
	.string "Itu sebabnya Aku selalu mengecek\n"
	.string "tempat Aku berjalan.$"

PetalburgWoods_Text_TryUsingThisItem:
	.string "Oh, keren! Itu BADGE dari RUSTBORO\n"
	.string "GYM!\p"
	.string "Kamu pasti seorang TRAINER. Kamu\n"
	.string "harus coba pakai item ini.$"

PetalburgWoods_Text_MiracleSeedExplanation:
	.string "Ini MIRACLE SEED. Jika POKéMON\n"
	.string "memegang item ini, gerakan tipe\l"
	.string "RUMPUT miliknya jadi lebih kuat.\p"
	.string "Selain MIRACLE SEED, Aku rasa ada\n"
	.string "item nyaman lain yang bisa dipegang\l"
	.string "POKéMON.$"

PetalburgWoods_Text_TrainerTipsExperience:
	.string "TIPS TRAINER\p"
	.string "Setiap POKéMON yang muncul sekali\n"
	.string "saja dalam pertarungan akan\l"
	.string "mendapat Poin EXP.\p"
	.string "Untuk melatih POKéMON yang lemah,\n"
	.string "taruh ia di paling kiri daftar tim.\p"
	.string "Segera setelah pertarungan dimulai,\n"
	.string "tukar ia keluar. Ia akan mendapat\l"
	.string "Poin EXP tanpa terluka sedikit pun.$"

PetalburgWoods_Text_TrainerTipsPP:
	.string "TIPS TRAINER\p"
	.string "Selain Hit Points (HP), POKéMON\n"
	.string "memiliki Power Points (PP) yang\l"
	.string "dipakai untuk mengeluarkan jurus\n"
	.string "saat bertarung.\p"
	.string "Jika PP POKéMON habis, ia harus\n"
	.string "dibawa ke POKéMON CENTER.$"
