//gemini
MysteryGiftScript_BattleCard::
	setvaddress MysteryGiftScript_BattleCard
	vgoto_if_set FLAG_MYSTERY_GIFT_DONE, MysteryGiftScript_BattleCardInfo
	setorcopyvar VAR_RESULT, GET_CARD_BATTLES_WON
	specialvar VAR_0x8008, GetMysteryGiftCardStat
	vgoto_if_ne VAR_0x8008, REQUIRED_CARD_BATTLES, MysteryGiftScript_BattleCardInfo
	lock
	faceplayer
	vmessage sText_MysteryGiftBattleCountCard_WonPrize
	waitmessage
	waitbuttonpress
	giveitem ITEM_POTION
	release
	setflag FLAG_MYSTERY_GIFT_DONE
	end

MysteryGiftScript_BattleCardInfo:
	lock
	faceplayer
	vmessage sText_MysteryGiftBattleCountCard
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftBattleCountCard:
	.string "Terima kasih telah menggunakan\n"
	.string "Sistem MYSTERY GIFT.\p"
	.string "KARTU HITUNGAN PERTARUNGAN-mu\n"
	.string "mencatat rekor pertarunganmu\l"
	.string "melawan TRAINER dengan KARTU\l"
	.string "yang sama.\p"
	.string "Cari & lawan TRAINER yang\n"
	.string "memiliki KARTU yang sama denganmu.\p"
	.string "Kamu bisa memeriksa peringkat\n"
	.string "keseluruhan dengan membaca BERITA.\p"
	.string "Silakan coba!$"

sText_MysteryGiftBattleCountCard_WonPrize:
	.string "Terima kasih telah menggunakan\n"
	.string "Sistem MYSTERY GIFT.\p"
	.string "Selamat!\p"
	.string "Kamu telah memenangkan hadiah\n"
	.string "karena memenangkan tiga\l"
	.string "pertarungan!\p"
	.string "Kami harap kamu akan terinspirasi\n"
	.string "untuk bertarung lagi.$"
