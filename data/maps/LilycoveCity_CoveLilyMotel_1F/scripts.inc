LilycoveCity_CoveLilyMotel_1F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_1F_EventScript_MotelOwner::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot, MSGBOX_DEFAULT
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem, MSGBOX_DEFAULT
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar, MSGBOX_DEFAULT
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_BlockingTV::
	lockall
	playse SE_PIN
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV
	applymovement LOCALID_MOTEL_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer
	waitmovement 0
	applymovement LOCALID_MOTEL_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn
	waitmovement 0
	release
	end

LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV:
	face_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer:
	walk_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn:
	face_down
	walk_down
	face_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot:
	.string "Hm, jadi mereka melipatgandakan tamu\n"
	.string "dengan POKéMON sebagai atraksi?\p"
	.string "Hm, mungkin aku harus membuat POKéMON\n"
	.string "lucu sebagai maskot penginapan kami.\p"
	.string "Apa itu akan menarik lebih banyak tamu\n"
	.string "untuk menginap?$"

LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua:
	.string "Oh, maaf, maaf!\n"
	.string "Aku terlalu asyik menonton TV!\p"
	.string "Sejak TEAM AQUA datang ke kota, para\n"
	.string "turis jadi menjauh.$"

LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV:
	.string "Hei, yang di depan awas!\n"
	.string "Aku tidak bisa melihat TV!$"

LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem:
	.string "Luar biasa! Kamu bilang POKéMON\n"
	.string "menemukan barang hilang seseorang?\p"
	.string "Itu hebat. Jika kita punya POKéMON\n"
	.string "pintar seperti itu…\p"
	.string "Kita bisa menemukan barang apa pun yang\n"
	.string "tamu kita salah taruh…$"

LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted:
	.string "Oh, maaf, maaf!\n"
	.string "Aku terlalu asyik menonton TV!\p"
	.string "Aku dengar seseorang telah menggerebek\n"
	.string "MARKAS TEAM AQUA.\p"
	.string "Berkat itu, kami baru saja mendapat\n"
	.string "reservasi dari grup besar.\p"
	.string "Itu perusahaan bernama… Uh…\n"
	.string "GAME apalah…$"

LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar:
	.string "Luar biasa! POKéMON penjaga rumah\n"
	.string "menangkap pencuri?\p"
	.string "Itu hebat. Jika kita punya POKéMON\n"
	.string "tangguh sebagai penjaga keamanan…\p"
	.string "Kita bisa memberikan keamanan lebih\n"
	.string "untuk para tamu.$"

LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner:
	.string "Oh, maaf, maaf!\n"
	.string "Aku terlalu asyik menonton TV.\p"
	.string "Oh, ya. Rombongan besar tamu tiba\n"
	.string "beberapa saat yang lalu.\p"
	.string "Mereka memesan atas nama GAME FREAK,\n"
	.string "jadi kurasa mereka pembuat game.\p"
	.string "Astaga, aku harus segera menyiapkan\n"
	.string "makan malam mereka!$"

