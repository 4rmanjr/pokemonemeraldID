//gemini
MysteryGiftScript_VisitingTrainer::
	setvaddress MysteryGiftScript_VisitingTrainer
	special ValidateEReaderTrainer
	vgoto_if_eq VAR_RESULT, 0, MysteryGiftScript_VisitingTrainerArrived
	lock
	faceplayer
	vmessage sText_MysteryGiftVisitingTrainerInstructions
	waitmessage
	waitbuttonpress
	release
	end

MysteryGiftScript_VisitingTrainerArrived:
	lock
	faceplayer
	vmessage sText_MysteryGiftVisitingTrainerArrived
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftVisitingTrainerInstructions:
	.string "Terima kasih telah menggunakan\n"
	.string "Sistem MYSTERY GIFT.\p"
	.string "Dengan memegang WONDER CARD ini,\n"
	.string "kamu bisa ikut survei di\l"
	.string "POKéMON MART.\p"
	.string "Gunakan survei ini untuk\n"
	.string "mengundang TRAINER ke KOTA SOOTOPOLIS.\p"
	.string "…Aku akan memberimu kata sandi\n"
	.string "rahasia untuk survei:\p"
	.string "“GIVE ME\n"
	.string "AWESOME TRAINER”\p"
	.string "Tulis itu di survei & kirim ke\n"
	.string "SISTEM KOMUNIKASI\l"
	.string "NIRKABEL.$"

sText_MysteryGiftVisitingTrainerArrived:
	.string "Terima kasih telah menggunakan\n"
	.string "Sistem MYSTERY GIFT.\p"
	.string "Seorang TRAINER telah tiba di\n"
	.string "KOTA SOOTOPOLIS mencarimu.\p"
	.string "Kami harap kamu akan menikmati\n"
	.string "pertarungan melawan TRAINER tamu.\p"
	.string "Kamu bisa mengundang TRAINER lain\n"
	.string "dengan memasukkan kata sandi lain.\p"
	.string "Coba cari kata sandi lain yang\n"
	.string "mungkin berfungsi.$"
