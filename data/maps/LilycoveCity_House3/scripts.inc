LilycoveCity_House3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_House3_OnTransition
	.byte 0

LilycoveCity_House3_OnTransition:
	random 4
	copyvar VAR_TEMP_1, VAR_RESULT
	end

LilycoveCity_House3_EventScript_PokefanF::
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_House3_EventScript_DeclinePokeblockLearn
	msgbox LilycoveCity_House3_Text_ExplainPokeblocks, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_DeclinePokeblockLearn::
	msgbox LilycoveCity_House3_Text_OhAreYouSure, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_Man::
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_HappyToHaveQuadruplets, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_GameBoyKid1::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid2::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid3::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid4::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_WereDoingMultiBattle::
	msgbox LilycoveCity_House3_Text_GoingToWinMultiBattles, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereMixingRecords::
	msgbox LilycoveCity_House3_Text_LikeMixingAtRecordCorner, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereBlendingBerries::
	msgbox LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereDoingContest::
	msgbox LilycoveCity_House3_Text_GoingToEnterContest, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks:
	.string "Oh, astaga! Kamu bepergian sendirian?\n"
	.string "Tapi kamu masih sangat muda! Hebat sekali!\p"
	.string "Aku yakin anak-anakku bisa belajar\n"
	.string "satu atau dua hal darimu!\p"
	.string "Aku? Aku adalah master {POKEBLOCK}.\p"
	.string "Jika aku sedikit serius, aku bisa\n"
	.string "membuat {POKEBLOCK} yang hebat.\p"
	.string "Maukah kamu belajar dariku,\n"
	.string "seorang master {POKEBLOCK}?$"

LilycoveCity_House3_Text_OhAreYouSure:
	.string "Oh? Kamu yakin?\p"
	.string "Kamu tidak seharusnya selalu mencoba\n"
	.string "melakukan semuanya sendiri, sayang!$"

LilycoveCity_House3_Text_ExplainPokeblocks:
	.string "Oh, bagus! Kamu anak yang pintar!\n"
	.string "Ini akan sedikit panjang, jadi dengarkan baik-baik!\p"
	.string "Apa kamu siap?\p"
	.string "Jika kamu perhatikan {POKEBLOCK}, kamu akan\n"
	.string "lihat ada peringkat berdasarkan 'rasa'-nya.\p"
	.string "Semakin rendah peringkat 'rasa'-nya,\n"
	.string "semakin bagus. Jangan lupakan ini!\p"
	.string "{POKEBLOCK} yang bagus memiliki peringkat\n"
	.string "'rasa' yang rendah dan level yang tinggi.\p"
	.string "POKéMON juga bisa makan lebih banyak\n"
	.string "{POKEBLOCK} bagus daripada yang biasa.\p"
	.string "Dan ini penting.\p"
	.string "Jika kamu ingin membuat {POKEBLOCK} yang\n"
	.string "lembut, gunakan berbagai jenis BERRY.\p"
	.string "Jangan pelit--jenis BERRY mempengaruhi\n"
	.string "kelembutan {POKEBLOCK}.\p"
	.string "Dan satu hal lagi.\p"
	.string "Semakin banyak orang yang mencampur\n"
	.string "BERRY, semakin lembut {POKEBLOCK}-nya.\p"
	.string "Itulah mengapa kamu harus berbicara\n"
	.string "dengan orang lain dan membuat {POKEBLOCK} bersama.\p"
	.string "Itu saja yang perlu kamu tahu untuk\n"
	.string "membuat {POKEBLOCK} yang bagus.\p"
	.string "Jika semua orang punya POKéMON yang\n"
	.string "mereka sayangi, {POKEBLOCK} yang lembut,\l"
	.string "dan keluarga yang penuh kasih, dunia\l"
	.string "akan menjadi tempat yang lebih bahagia.\p"
	.string "Jangan menyerah, sayang!$"

LilycoveCity_House3_Text_HappyToHaveQuadruplets:
	.string "Saat istriku melahirkan anak kembar\n"
	.string "empat, tentu saja aku terkejut.\p"
	.string "Tapi, sekarang, melihat mereka bermain\n"
	.string "bersama, itu membuatku bahagia.$"

LilycoveCity_House3_Text_GoingToWinMultiBattles:
	.string "Kami akan melakukan MULTI BATTLE, tapi\n"
	.string "aku tahu aku akan menang.$"

LilycoveCity_House3_Text_LikeMixingAtRecordCorner:
	.string "Kami suka mencampur berbagai hal di\n"
	.string "RECORD CORNER.\p"
	.string "Tapi apa yang tercampur?$"

LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender:
	.string "Kami akan membuat {POKEBLOCK} super\n"
	.string "dengan BERRY BLENDER!$"

LilycoveCity_House3_Text_GoingToEnterContest:
	.string "Aku ingin pamer betapa tangguhnya\n"
	.string "POKéMON-ku, jadi kami akan mengikuti\l"
	.string "CONTEST bersama.$"

