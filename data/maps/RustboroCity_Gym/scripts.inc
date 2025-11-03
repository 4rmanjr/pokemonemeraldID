RustboroCity_Gym_MapScripts::
	.byte 0

RustboroCity_Gym_EventScript_Roxanne::
	trainerbattle_single TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxanneIntro, RustboroCity_Gym_Text_RoxanneDefeat, RustboroCity_Gym_EventScript_RoxanneDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Gym_EventScript_RoxanneRematch
	goto_if_unset FLAG_RECEIVED_TM_ROCK_TOMB, RustboroCity_Gym_EventScript_GiveRockTomb
	msgbox RustboroCity_Gym_Text_RoxannePostBattle, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneDefeated::
	message RustboroCity_Gym_Text_ReceivedStoneBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox RustboroCity_Gym_Text_StoneBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_BADGE01_GET
	setvar VAR_RUSTBORO_CITY_STATE, 1
	addvar VAR_PETALBURG_GYM_STATE, 1
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	goto RustboroCity_Gym_EventScript_GiveRockTomb
	end

RustboroCity_Gym_EventScript_GiveRockTomb::
	giveitem ITEM_TM_ROCK_TOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_ROCK_TOMB
	msgbox RustboroCity_Gym_Text_ExplainRockTomb, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneRematch::
	trainerbattle_rematch_double TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxannePreRematch, RustboroCity_Gym_Text_RoxanneRematchDefeat, RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons
	msgbox RustboroCity_Gym_Text_RoxannePostRematch, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Josh::
	trainerbattle_single TRAINER_JOSH, RustboroCity_Gym_Text_JoshIntro, RustboroCity_Gym_Text_JoshDefeat
	msgbox RustboroCity_Gym_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Tommy::
	trainerbattle_single TRAINER_TOMMY, RustboroCity_Gym_Text_TommyIntro, RustboroCity_Gym_Text_TommyDefeat
	msgbox RustboroCity_Gym_Text_TommyPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Marc::
	trainerbattle_single TRAINER_MARC, RustboroCity_Gym_Text_MarcIntro, RustboroCity_Gym_Text_MarcDefeat
	msgbox RustboroCity_Gym_Text_MarcPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_RUSTBORO_GYM, RustboroCity_Gym_EventScript_GymGuidePostVictory
	msgbox RustboroCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_GymGuidePostVictory::
	msgbox RustboroCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_GymStatueCertified::
	msgbox RustboroCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_GymStatue::
	msgbox RustboroCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_RegisterRoxanne::
	lockall
	pokenavcall RustboroCity_Gym_Text_RoxanneRegisterCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Gym_Text_RegisteredRoxanne, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
	clearflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	releaseall
	end

RustboroCity_Gym_Text_GymGuideAdvice:
	.string "Yo, apa kabar?\p"
	.string "Dengar, temanku!\n"
	.string "Apakah kamu ingin menjadi JUARA?\p"
	.string "Aku bukan TRAINER, bukan aku, tapi aku\n"
	.string "pasti bisa memberimu saran kemenangan.\p"
	.string "Sudah beres, kalau begitu! Kita akan\n"
	.string "mengincar KEJUARAAN POKéMON bersama!\p"
	.string "Tugasmu sebagai TRAINER adalah\n"
	.string "mengumpulkan LENCANA GYM, kan?\p"
	.string "Tapi PEMIMPIN GYM bukan lawan yang\n"
	.string "mudah!\p"
	.string "Dan di sinilah aku berperan!\n"
	.string "Aku di sini untuk memberikan saran\l"
	.string "ahli!\p"
	.string "ROXANNE, PEMIMPIN GYM, adalah\n"
	.string "pengguna POKéMON tipe BATU.\p"
	.string "Tipe BATU sangat tahan lama, tapi\n"
	.string "tidak tahan terhadap gerakan tipe\l"
	.string "AIR dan tipe RUMPUT.\p"
	.string "Temui aku setelahnya, jika kamu\n"
	.string "mengalahkan PEMIMPIN GYM.\p"
	.string "Baiklah, lakukanlah!$"

RustboroCity_Gym_Text_GymGuidePostVictory:
	.string "Wah! Kemenangan yang menakjubkan!\n"
	.string "Sorakanku pasti berhasil!\p"
	.string "Hebat!\n"
	.string "Periksa KARTU TRAINER-mu.\p"
	.string "LENCANA BATU yang kamu dapatkan\n"
	.string "seharusnya sudah tercatat dengan\l"
	.string "benar di sana.\p"
	.string "Dengan kata lain…\p"
	.string "Kamu telah menapaki langkah pertama\n"
	.string "menuju KEJUARAAN!\p"
	.string "Itu pasti terasa luar biasa!$"

RustboroCity_Gym_Text_JoshIntro:
	.string "Jangan remehkan kami TRAINER GYM!\n"
	.string "Aku akan menunjukkan mengapa kami\l"
	.string "lebih baik!$"

RustboroCity_Gym_Text_JoshDefeat:
	.string "Kamu terlalu hebat bagiku…$"

RustboroCity_Gym_Text_JoshPostBattle:
	.string "Kamu belum melihat apa-apa dari\n"
	.string "kekuatan menakutkan tipe BATU!$"

RustboroCity_Gym_Text_TommyIntro:
	.string "Kalau kamu tidak bisa mengalahkanku,\n"
	.string "kamu tidak akan punya kesempatan\l"
	.string "melawan ROXANNE!$"

RustboroCity_Gym_Text_TommyDefeat:
	.string "Wow! Kamu punya potensi!$"

RustboroCity_Gym_Text_TommyPostBattle:
	.string "ROXANNE beberapa kali lebih kuat\n"
	.string "daripada aku.\p"
	.string "Sebaiknya kamu berhati-hati!$"

RustboroCity_Gym_Text_MarcIntro:
	.string "Kita mungkin berada di tengah kota,\n"
	.string "tapi kenapa?\p"
	.string "POKéMON BATU-ku butuh ruang untuk\n"
	.string "mengamuk!$"

RustboroCity_Gym_Text_MarcDefeat:
	.string "Oh, astaga!\n"
	.string "Penantang kita ini pelanggan yang\l"
	.string "bersemangat!$"

RustboroCity_Gym_Text_MarcPostBattle:
	.string "Aku harus mengakui kehebatan PEMIMPIN\n"
	.string "kita.\p"
	.string "Butuh kecerdasan dan akal sehat baginya\n"
	.string "untuk memilih tipe BATU di usianya\l"
	.string "yang muda.$"

RustboroCity_Gym_Text_RoxanneIntro:
	.string "Halo, aku ROXANNE, PEMIMPIN\n"
	.string "GYM POKéMON RUSTBORO.\p"
	.string "Aku menjadi PEMIMPIN GYM agar aku\n"
	.string "bisa menerapkan apa yang kupelajari\l"
	.string "di SEKOLAH TRAINER POKéMON dalam\l"
	.string "pertarungan.\p"
	.string "Maukah kamu menunjukkan bagaimana\n"
	.string "kamu bertarung, dan dengan POKéMON\l"
	.string "yang mana?$"

RustboroCity_Gym_Text_RoxanneDefeat:
	.string "Jadi…\n"
	.string "Aku kalah…\p"
	.string "Sepertinya aku masih banyak yang\n"
	.string "harus kupelajari…\p"
	.string "Aku mengerti.\p"
	.string "Aturan LIGA POKéMON menyatakan bahwa\n"
	.string "TRAINER harus diberikan ini jika\l"
	.string "mereka mengalahkan PEMIMPIN GYM.\p"
	.string "Terimalah LENCANA BATU resmi LIGA\n"
	.string "POKéMON.$"

RustboroCity_Gym_Text_ReceivedStoneBadge:
	.string "{PLAYER} mendapatkan LENCANA BATU\n"
	.string "dari ROXANNE.$"

RustboroCity_Gym_Text_StoneBadgeInfoTakeThis:
	.string "LENCANA BATU meningkatkan kekuatan\n"
	.string "SERANGAN POKéMON-mu.\p"
	.string "Ini juga memungkinkan mereka\n"
	.string "menggunakan gerakan HM CUT di luar\l"
	.string "pertarungan.\p"
	.string "Tolong bawa ini juga.$"

RustboroCity_Gym_Text_ExplainRockTomb:
	.string "MESIN TEKNIS itu, TM39,\n"
	.string "berisi ROCK TOMB.\p"
	.string "Ini tidak hanya menimbulkan kerusakan\n"
	.string "dengan menjatuhkan batu, tapi juga\l"
	.string "menurunkan KECEPATAN.\p"
	.string "Jika kamu menggunakan TM, itu\n"
	.string "langsung mengajarkan gerakan itu\l"
	.string "kepada POKéMON.\p"
	.string "Ingat, TM hanya bisa digunakan sekali,\n"
	.string "jadi pikirkan baik-baik sebelum\l"
	.string "menggunakannya.$"

RustboroCity_Gym_Text_RoxannePostBattle:
	.string "Karena kamu sangat kuat, kamu harus\n"
	.string "menantang PEMIMPIN GYM lainnya.\p"
	.string "Dengan bertarung melawan banyak\n"
	.string "TRAINER, kamu akan belajar banyak\l"
	.string "hal.$"

RustboroCity_Gym_Text_GymStatue:
	.string "GYM POKéMON KOTA RUSTBORO$"

RustboroCity_Gym_Text_GymStatueCertified:
	.string "GYM POKéMON KOTA RUSTBORO\p"
	.string "TRAINER BERSERTIFIKAT ROXANNE:\n"
	.string "{PLAYER}$"

RustboroCity_Gym_Text_RoxanneRegisterCall:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "ROXANNE: Oh, halo, {PLAYER}?\n"
	.string "Ini ROXANNE dari KOTA RUSTBORO.\p"
	.string "Aku dengar dari BRAWLY bahwa kamu\n"
	.string "naik pangkat di antara TRAINER\l"
	.string "dengan sangat cepat.\p"
	.string "Yah, aku tidak mau berpikir bahwa\n"
	.string "aku tidak bisa mengalahkanmu.\p"
	.string "Aku janji, aku akan mempersiapkan\n"
	.string "GYM-ku agar kamu bisa menantang\l"
	.string "kami lagi.\p"
	.string "Kuharap kamu menantikan kesempatan\n"
	.string "itu sama sepertiku!\p"
	.string "… … … … … …\n"
	.string "… … … … … Klik!$"

RustboroCity_Gym_Text_RegisteredRoxanne:
	.string "PEMIMPIN GYM ROXANNE terdaftar\n"
	.string "di POKéNAV.$"

RustboroCity_Gym_Text_RoxannePreRematch:
	.string "ROXANNE: Aku sangat senang bertemu\n"
	.string "denganmu lagi. Aku ROXANNE,\l"
	.string "PEMIMPIN GYM di sini.\p"
	.string "Aku yakin kita berdua telah mengalami\n"
	.string "banyak pertarungan sejak terakhir\l"
	.string "kita bertemu.\p"
	.string "Aku ingin melihat seberapa jauh\n"
	.string "kita telah berkembang. Mari kita\l"
	.string "bertarung!$"

RustboroCity_Gym_Text_RoxanneRematchDefeat:
	.string "Grr…\n"
	.string "Lagi-lagi, aku kalah…$"

RustboroCity_Gym_Text_RoxannePostRematch:
	.string "ROXANNE: Aku masih banyak yang harus\n"
	.string "kupelajari dalam bertarung POKéMON.\p"
	.string "Kesadaran itu membuatku semakin\n"
	.string "mencintai pertarungan!$"

RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons:
	.string "ROXANNE: Aku sangat senang bertemu\n"
	.string "denganmu lagi. Aku ROXANNE,\l"
	.string "PEMIMPIN GYM di sini.\p"
	.string "Aku yakin kita berdua telah mengalami\n"
	.string "banyak pertarungan sejak terakhir\l"
	.string "kita bertemu.\p"
	.string "Aku ingin melihat seberapa jauh\n"
	.string "kita telah berkembang…\p"
	.string "Oh, tidak…\n"
	.string "Kamu hanya punya satu POKéMON?\p"
	.string "Tolong kembali dengan setidaknya\n"
	.string "satu POKéMON lagi.$"
