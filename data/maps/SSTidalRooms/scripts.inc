//gemini
SSTidalRooms_MapScripts::
	.byte 0

SSTidalRooms_EventScript_SnatchGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_SNATCH, SSTidalRooms_EventScript_ExplainSnatch
	msgbox SSTidalRooms_Text_NotSuspiciousTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_SNATCH
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_SNATCH
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_EventScript_ExplainSnatch::
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_EventScript_Bed::
	lockall
	msgbox SSTidalRooms_Text_TakeRestOnBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	call SSTidalRooms_EventScript_ProgessCruiseAfterBed
	releaseall
	end

SSTidalRooms_EventScript_Colton::
	trainerbattle_single TRAINER_COLTON, SSTidalRooms_Text_ColtonIntro, SSTidalRooms_Text_ColtonDefeat
	msgbox SSTidalRooms_Text_ColtonPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Micah::
	trainerbattle_single TRAINER_MICAH, SSTidalRooms_Text_MicahIntro, SSTidalRooms_Text_MicahDefeat
	msgbox SSTidalRooms_Text_MicahPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Thomas::
	trainerbattle_single TRAINER_THOMAS, SSTidalRooms_Text_ThomasIntro, SSTidalRooms_Text_ThomasDefeat
	msgbox SSTidalRooms_Text_ThomasPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Jed::
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_JedIntro, SSTidalRooms_Text_JedDefeat, SSTidalRooms_Text_JedNotEnoughMons
	msgbox SSTidalRooms_Text_JedPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Lea::
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_LeaIntro, SSTidalRooms_Text_LeaDefeat, SSTidalRooms_Text_LeaNotEnoughMons
	msgbox SSTidalRooms_Text_LeaPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Garret::
	trainerbattle_single TRAINER_GARRET, SSTidalRooms_Text_GarretIntro, SSTidalRooms_Text_GarretDefeat
	msgbox SSTidalRooms_Text_GarretPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Naomi::
	trainerbattle_single TRAINER_NAOMI, SSTidalRooms_Text_NaomiIntro, SSTidalRooms_Text_NaomiDefeat
	msgbox SSTidalRooms_Text_NaomiPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_Text_TakeRestOnBed:
	.string "Ada tempat tidur… Mari\n"
	.string "beristirahat.$"

SSTidalRooms_Text_ColtonIntro:
	.string "Aku sering berlayar ke KOTA\n"
	.string "LILYCOVE.\p"
	.string "Aku suka sekali menghadiri KONTEST,\n"
	.string "tahu.$"

SSTidalRooms_Text_ColtonDefeat:
	.string "Itu adalah pertandingan yang\n"
	.string "menyenangkan!$"

SSTidalRooms_Text_ColtonPostBattle:
	.string "Aku sangat bersemangat membayangkan\n"
	.string "jenis POKéMON apa yang akan aku\l"
	.string "lihat di KONTEST berikutnya.\l"
	.string "Antisipasi itu menggairahkan!$"

SSTidalRooms_Text_MicahIntro:
	.string "Apakah teman-teman Kamu kuat?$"

SSTidalRooms_Text_MicahDefeat:
	.string "Teman-teman Kamu memang kuat.$"

SSTidalRooms_Text_MicahPostBattle:
	.string "Teman tidak harus manusia. Bagiku,\n"
	.string "POKéMON adalah teman yang berharga!$"

SSTidalRooms_Text_ThomasIntro:
	.string "Nak… Apa Kamu mengetuk pintu?$"

SSTidalRooms_Text_ThomasDefeat:
	.string "Kekalahan harus diterima tanpa\n"
	.string "tergesa-gesa atau panik.$"

SSTidalRooms_Text_ThomasPostBattle:
	.string "Tidak pernah kesal dalam situasi\n"
	.string "apa pun adalah kode etik PRIA\l"
	.string "TERHORMAT.$"

SSTidalRooms_Text_JedIntro:
	.string "JED: Aku merasa sedikit malu\n"
	.string "tentang ini, tapi… Kami akan\l"
	.string "menunjukkan kekuatan mesra kami!$"

SSTidalRooms_Text_JedDefeat:
	.string "JED: Huh…$"

SSTidalRooms_Text_JedPostBattle:
	.string "JED: Ini pertama kalinya kekuatan\n"
	.string "mesra kami tidak bisa menang! Kamu\l"
	.string "pasti TRAINER yang hebat!$"

SSTidalRooms_Text_JedNotEnoughMons:
	.string "JED: Kamu hanya punya satu POKéMON?\n"
	.string "Bukankah itu terlalu sepi?$"

SSTidalRooms_Text_LeaIntro:
	.string "LEA: Aku merasa sedikit konyol,\n"
	.string "tapi… Kami akan menunjukkan\l"
	.string "kekuatan mesra kami!$"

SSTidalRooms_Text_LeaDefeat:
	.string "LEA: Oh, boo!$"

SSTidalRooms_Text_LeaPostBattle:
	.string "LEA: Aku tidak percaya! Kekuatan\n"
	.string "mesra kami gagal… Kamu pasti\l"
	.string "TRAINER yang hebat!$"

SSTidalRooms_Text_LeaNotEnoughMons:
	.string "LEA: Aku ingin bertarung… Tapi Kamu\n"
	.string "bahkan tidak punya dua POKéMON…$"

SSTidalRooms_Text_GarretIntro:
	.string "Ah, Kamu datang tepat waktu.\p"
	.string "Aku bosan, tahu. Kamu boleh\n"
	.string "menghiburku.$"

SSTidalRooms_Text_GarretDefeat:
	.string "…Cukup.$"

SSTidalRooms_Text_GarretPostBattle:
	.string "Mungkin aku akan meminta Ayah\n"
	.string "membelikan kapal pesiar untukku.\l"
	.string "Kapal pesiar untukku dan POKéMON!$"

SSTidalRooms_Text_NaomiIntro:
	.string "Oh, Kamu TRAINER yang menggemaskan.\n"
	.string "Apa Kamu mau minum teh? Atau Kamu\l"
	.string "lebih memilih bertarung?$"

SSTidalRooms_Text_NaomiDefeat:
	.string "Aku mengerti. Kamu tipe yang aktif.$"

SSTidalRooms_Text_NaomiPostBattle:
	.string "Pelayaran dunia dengan kapal pesiar\n"
	.string "mewah memiliki daya tarik\l"
	.string "tersendiri, harus aku akui…\p"
	.string "Tapi, aku akui ada sisi menarik\n"
	.string "dari tur HOENN dengan feri.$"

SSTidalRooms_Text_NotSuspiciousTakeThis:
	.string "Uh… Hai! Aku… Aku tidak bertingkah\n"
	.string "mencurigakan! Uh… Kamu boleh ambil\l"
	.string "ini! Gratis!\p"
	.string "Itu… Jujur, aku tidak MENCURI-nya\n"
	.string "dari seseorang! Aku tidak akan\l"
	.string "pernah melakukan hal seperti itu!\l"
	.string "Itu bersih! Kamu bisa\l"
	.string "menggunakannya!$"

SSTidalRooms_Text_ExplainSnatch:
	.string "SNATCH mencuri efek menguntungkan\n"
	.string "dari gerakan tertentu sebelum dapat\l"
	.string "digunakan oleh musuh atau sekutu.$"
