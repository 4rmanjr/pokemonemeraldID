//gemini
MysteryGiftScript_AuroraTicket::
	setvaddress MysteryGiftScript_AuroraTicket
	lock
	faceplayer
	vgoto_if_set FLAG_RECEIVED_AURORA_TICKET, AuroraTicket_Obtained
	vgoto_if_set FLAG_BATTLED_DEOXYS, AuroraTicket_Obtained
	checkitem ITEM_AURORA_TICKET
	vgoto_if_eq VAR_RESULT, TRUE, AuroraTicket_Obtained
	vmessage sText_AuroraTicketForYou
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_AURORA_TICKET
	vgoto_if_eq VAR_RESULT, FALSE, AuroraTicket_NoBagSpace
	giveitem ITEM_AURORA_TICKET
	setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
	setflag FLAG_RECEIVED_AURORA_TICKET
	vmessage sText_AuroraTicketUseAtPort
	waitmessage
	waitbuttonpress
	release
	end

AuroraTicket_NoBagSpace:
	vmessage sText_AuroraTicketBagFull
	waitmessage
	waitbuttonpress
	release
	end

AuroraTicket_Obtained:
	vmessage sText_AuroraTicketThankYou
	waitmessage
	waitbuttonpress
	release
	end

sText_AuroraTicketForYou:
	.string "Terima kasih telah menggunakan\n"
	.string "Sistem MYSTERY GIFT.\p"
	.string "Kamu pasti {PLAYER}.\n"
	.string "Ada tiket di sini untukmu.$"

sText_AuroraTicketUseAtPort:
	.string "Sepertinya ini untuk digunakan\n"
	.string "di pelabuhan KOTA LILYCOVE.\p"
	.string "Kenapa tidak kamu coba & lihat\n"
	.string "ada apa?$"

sText_AuroraTicketThankYou:
	.string "Terima kasih telah menggunakan\n"
	.string "Sistem MYSTERY GIFT.$"

sText_AuroraTicketBagFull:
	.string "Oh, maaf, {PLAYER}.\n"
	.string "SAKU ITEM PENTING di TAS-mu penuh.\p"
	.string "Tolong simpan sesuatu di PC-mu,\n"
	.string "lalu kembalilah untuk ini.$"
