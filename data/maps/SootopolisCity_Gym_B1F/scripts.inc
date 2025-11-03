//gemini
SootopolisCity_Gym_B1F_MapScripts::
	.byte 0

SootopolisCity_Gym_B1F_EventScript_Andrea::
	trainerbattle_single TRAINER_ANDREA, SootopolisCity_Gym_B1F_Text_AndreaIntro, SootopolisCity_Gym_B1F_Text_AndreaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_AndreaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Crissy::
	trainerbattle_single TRAINER_CRISSY, SootopolisCity_Gym_B1F_Text_CrissyIntro, SootopolisCity_Gym_B1F_Text_CrissyDefeat
	msgbox SootopolisCity_Gym_B1F_Text_CrissyPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Brianna::
	trainerbattle_single TRAINER_BRIANNA, SootopolisCity_Gym_B1F_Text_BriannaIntro, SootopolisCity_Gym_B1F_Text_BriannaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_BriannaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Connie::
	trainerbattle_single TRAINER_CONNIE, SootopolisCity_Gym_B1F_Text_ConnieIntro, SootopolisCity_Gym_B1F_Text_ConnieDefeat
	msgbox SootopolisCity_Gym_B1F_Text_ConniePostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Bridget::
	trainerbattle_single TRAINER_BRIDGET, SootopolisCity_Gym_B1F_Text_BridgetIntro, SootopolisCity_Gym_B1F_Text_BridgetDefeat
	msgbox SootopolisCity_Gym_B1F_Text_BridgetPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Olivia::
	trainerbattle_single TRAINER_OLIVIA, SootopolisCity_Gym_B1F_Text_OliviaIntro, SootopolisCity_Gym_B1F_Text_OliviaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_OliviaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Tiffany::
	trainerbattle_single TRAINER_TIFFANY, SootopolisCity_Gym_B1F_Text_TiffanyIntro, SootopolisCity_Gym_B1F_Text_TiffanyDefeat
	msgbox SootopolisCity_Gym_B1F_Text_TiffanyPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Bethany::
	trainerbattle_single TRAINER_BETHANY, SootopolisCity_Gym_B1F_Text_BethanyIntro, SootopolisCity_Gym_B1F_Text_BethanyDefeat
	msgbox SootopolisCity_Gym_B1F_Text_BethanyPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Annika::
	trainerbattle_single TRAINER_ANNIKA, SootopolisCity_Gym_B1F_Text_AnnikaIntro, SootopolisCity_Gym_B1F_Text_AnnikaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_AnnikaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Daphne::
	trainerbattle_single TRAINER_DAPHNE, SootopolisCity_Gym_B1F_Text_DaphneIntro, SootopolisCity_Gym_B1F_Text_DaphneDefeat
	msgbox SootopolisCity_Gym_B1F_Text_DaphnePostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_Text_AndreaIntro:
	.string "Akan kutunjukkan padamu teknik\n"
	.string "menawan yang kupelajari dari\l"
	.string "PEMIMPIN kami, JUAN!$"

SootopolisCity_Gym_B1F_Text_AndreaDefeat:
	.string "Maafkan aku, JUAN…$"

SootopolisCity_Gym_B1F_Text_AndreaPostBattle:
	.string "Lihat apa yang terjadi jika kamu\n"
	.string "memecahkan semua ubin lantai.$"

SootopolisCity_Gym_B1F_Text_CrissyIntro:
	.string "Kamu datang jauh-jauh ke sini,\n"
	.string "tetapi kamu tidak akan bisa melihat\l"
	.string "JUAN.\p"
	.string "Tidak akan, jika kamu kalah dariku!$"

SootopolisCity_Gym_B1F_Text_CrissyDefeat:
	.string "Kamu kuat! Aku tertipu oleh\n"
	.string "penampilan imutmu!$"

SootopolisCity_Gym_B1F_Text_CrissyPostBattle:
	.string "Kamu mungkin cukup baik untuk\n"
	.string "menghindari dihabisi oleh JUAN\l"
	.string "dalam sekali pukul.$"

SootopolisCity_Gym_B1F_Text_DaphneIntro:
	.string "Pemandangan JUAN memimpin\n"
	.string "pertempuran…\p"
	.string "Keindahannya yang luar biasa\n"
	.string "membuatku terdorong untuk menjadi\l"
	.string "TRAINER.$"

SootopolisCity_Gym_B1F_Text_DaphneDefeat:
	.string "Kamu bertarung dengan keindahan\n"
	.string "yang melebihi kemampuanku…$"

SootopolisCity_Gym_B1F_Text_DaphnePostBattle:
	.string "Keanggunan yang kamu bawa ke dalam\n"
	.string "pertempuran sungguh luar biasa.\p"
	.string "Oh… Aku sangat beruntung telah\n"
	.string "menemukan POKéMON.$"

SootopolisCity_Gym_B1F_Text_ConnieIntro:
	.string "Aku harus mengajarimu betapa\n"
	.string "kerasnya sebuah pertempuran.$"

SootopolisCity_Gym_B1F_Text_ConnieDefeat:
	.string "Oh. Kamu kuat.$"

SootopolisCity_Gym_B1F_Text_ConniePostBattle:
	.string "Akan kuberitahu sesuatu yang bagus.\p"
	.string "Jika kamu ingin mencapai JUAN, kamu\n"
	.string "perlu berjalan di setiap ubin\l"
	.string "lantai sekali.$"

SootopolisCity_Gym_B1F_Text_BridgetIntro:
	.string "GYM POKéMON tingkat tertinggi di\n"
	.string "wilayah HOENN…\p"
	.string "Itulah GYM SOOTOPOLIS.$"

SootopolisCity_Gym_B1F_Text_BridgetDefeat:
	.string "Betapa tingginya tingkatmu!$"

SootopolisCity_Gym_B1F_Text_BridgetPostBattle:
	.string "Daripada merasa puas berada di GYM\n"
	.string "yang kuat, aku membayangkan\l"
	.string "berlatih di tempat lain akan\l"
	.string "membuatmu lebih kuat. Tapi di atas\l"
	.string "segalanya, itu terlihat lebih\l"
	.string "menyenangkan.$"

SootopolisCity_Gym_B1F_Text_OliviaIntro:
	.string "Aku melatih POKéMON-ku bersama\n"
	.string "dengan JUAN.\p"
	.string "Jangan berpikir aku lemah.$"

SootopolisCity_Gym_B1F_Text_OliviaDefeat:
	.string "Aku kalah…$"

SootopolisCity_Gym_B1F_Text_OliviaPostBattle:
	.string "Menurutku kamu punya potensi.\n"
	.string "Kenapa kamu tidak tinggal dan\l"
	.string "berlatih bersama kami?$"

SootopolisCity_Gym_B1F_Text_TiffanyIntro:
	.string "Meluncur dengan anggun di atas es\n"
	.string "tanpa melintasi garis apa pun…\p"
	.string "Seorang TRAINER yang melakukan\n"
	.string "pertunjukan itu akan menjadi indah\l"
	.string "nan elegan!$"

SootopolisCity_Gym_B1F_Text_TiffanyDefeat:
	.string "Baiklah, permisi?!$"

SootopolisCity_Gym_B1F_Text_TiffanyPostBattle:
	.string "Ini sangat jelas, tapi seberapa\n"
	.string "kuatnya dirimu sebagai TRAINER\l"
	.string "tidak ada hubungannya dengan\l"
	.string "seberapa muda atau tua dirimu.$"

SootopolisCity_Gym_B1F_Text_BethanyIntro:
	.string "Saat aku bersama POKéMON-ku, waktu\n"
	.string "berlalu begitu saja sebelum kamu\l"
	.string "bisa berkata, “Aduh!“$"

SootopolisCity_Gym_B1F_Text_BethanyDefeat:
	.string "Aduh!$"

SootopolisCity_Gym_B1F_Text_BethanyPostBattle:
	.string "Aku berharap bisa melupakan\n"
	.string "penyebab kekalahan sebelum aku\l"
	.string "sempat berkata “Aduh!“$"

SootopolisCity_Gym_B1F_Text_AnnikaIntro:
	.string "Aku bisa bertarung dengan POKéMON\n"
	.string "yang sangat langka jika kamu mau.$"

SootopolisCity_Gym_B1F_Text_AnnikaDefeat:
	.string "Oh, begitu! Apakah kamu melihat\n"
	.string "POKéMON-ku dengan baik?$"

SootopolisCity_Gym_B1F_Text_AnnikaPostBattle:
	.string "Aku datang ke GYM ini karena JUAN\n"
	.string "memuji POKéMON kesayanganku.\p"
	.string "Oh, andai saja aku bertemu JUAN\n"
	.string "bertahun-tahun yang lalu saat aku\l"
	.string "masih muda…$"

SootopolisCity_Gym_B1F_Text_BriannaIntro:
	.string "Kikik… Ekspresi murammu sangat\n"
	.string "menawan.$"

SootopolisCity_Gym_B1F_Text_BriannaDefeat:
	.string "Ya ampun. Aku terlalu bersikap\n"
	.string "lunak padamu.$"

SootopolisCity_Gym_B1F_Text_BriannaPostBattle:
	.string "Aku yakin kamu tidak akan bisa\n"
	.string "menyentuh JUAN. Kikik…$"
