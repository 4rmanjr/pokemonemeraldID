//gemini
Route111_Text_MakingRoomUseTMToMakeYourOwn:
	.string "Apa itu?\n"
	.string "Apa yang sedang kulakukan?\p"
	.string "Aku sedang berpikir untuk membuat\n"
	.string "ruanganku sendiri di sini\l"
	.string "menggunakan gerakan POKéMON.\p"
	.string "Aku tahu! Aku akan memberimu TM ini.\n"
	.string "Maukah kamu menggunakannya untuk\l"
	.string "membuat ruangmu sendiri?$"

Route111_Text_ExplainSecretPower:
	.string "Cari pohon besar yang terlihat\n"
	.string "seperti bisa menjatuhkan sulur.\p"
	.string "Gunakan SECRET POWER di depan pohon.\n"
	.string "Beberapa sulur akan lepas & jatuh,\l"
	.string "jadi kamu bisa memanjat pohon.\p"
	.string "Kamu akan menemukan banyak ruang\n"
	.string "untuk menaruh barang favoritmu.\p"
	.string "Itu akan jadi ruang rahasiamu…\n"
	.string "MARKAS RAHASIA!\l"
	.string "Kamu juga harus membuat satu.\p"
	.string "Hal lain, kamu tidak selalu harus\n"
	.string "membuat MARKAS RAHASIA-mu di pohon.\p"
	.string "Coba gunakan SECRET POWER pada\n"
	.string "dinding batu yang punya lekukan\l"
	.string "kecil.\p"
	.string "Aku juga akan mencari tempat lain.\n"
	.string "Oke, sampai jumpa!$"

Route111_Text_DontWantThis:
	.string "Oh, kamu tidak mau ini?\n"
	.string "Kalau kamu berubah pikiran,\l"
	.string "beritahu aku, oke?$"

Route111_Text_DontHaveAnyRoom:
	.string "Oh, kamu tidak punya ruang\n"
	.string "untuk ini.\p"
	.string "Aku akan menyimpannya, jadi\n"
	.string "kembalilah nanti, oke?$"

Route111_EventScript_SecretPowerMan::
	lock
	faceplayer
	msgbox Route111_Text_MakingRoomUseTMToMakeYourOwn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_EventScript_GiveSecretPower
	msgbox Route111_Text_DontWantThis, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_GiveSecretPower::
	giveitem ITEM_TM_SECRET_POWER
	goto_if_eq VAR_RESULT, FALSE, Route111_EventScript_NoRoomForSecretPower
	msgbox Route111_Text_ExplainSecretPower, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_RECEIVED_SECRET_POWER
	clearflag FLAG_HIDE_SLATEPORT_CITY_TM_SALESMAN
	call_if_eq VAR_FACING, DIR_WEST, Route111_EventScript_SecretPowerManExit
	call_if_eq VAR_FACING, DIR_EAST, Route111_EventScript_SecretPowerManExit
	call_if_eq VAR_FACING, DIR_NORTH, Route111_EventScript_SecretPowerManExitNorth
	removeobject VAR_LAST_TALKED
	release
	end

Route111_EventScript_SecretPowerManExit::
	applymovement VAR_LAST_TALKED, Route111_Movement_SecretPowerManExit
	waitmovement 0
	return

Route111_EventScript_SecretPowerManExitNorth::
	applymovement VAR_LAST_TALKED, Route111_Movement_SecretPowerManExitNorth
	waitmovement 0
	return

Route111_EventScript_NoRoomForSecretPower::
	msgbox Route111_Text_DontHaveAnyRoom, MSGBOX_DEFAULT
	release
	end

Route111_Movement_SecretPowerManExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

Route111_Movement_SecretPowerManExitNorth:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end
