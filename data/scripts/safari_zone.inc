//gemini
SafariZone_EventScript_OutOfBallsMidBattle::
	setvar VAR_SAFARI_ZONE_STATE, 1
	special ExitSafariMode
	setwarp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 2, 5
	end

SafariZone_EventScript_Exit::
	setvar VAR_SAFARI_ZONE_STATE, 1
	special ExitSafariMode
	warp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 2, 5
	waitstate
	end

SafariZone_EventScript_RetirePrompt::
	lockall
	msgbox SafariZone_Text_WouldYouLikeToExit, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_Retire
	releaseall
	end

SafariZone_EventScript_Retire::
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_TimesUp::
	lockall
	playse SE_DING_DONG
	message SafariZone_Text_TimesUp
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_OutOfBalls::
	lockall
	playse SE_DING_DONG
	message SafariZone_Text_OutOfBalls
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

EventScript_PokeBlockFeeder::
	lockall
	special GetPokeblockFeederInFront
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPresent
	msgbox SafariZone_Text_PlacePokeblockOnFeeder, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_ChoosePokeblock
	releaseall
	end

SafariZone_EventScript_ChoosePokeblock::
	fadescreen FADE_TO_BLACK
	special OpenPokeblockCaseOnFeeder
	waitstate
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPlaced
#ifdef BUGFIX
	releaseall  @ Only gets called from EventScript_PokeBlockFeeder which uses lockall.
#endif
	end

SafariZone_EventScript_PokeblockPlaced::
	message SafariZone_Text_PokeblockWasPlaced
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_EventScript_PokeblockPresent::
	message SafariZone_Text_PokeblockStillHere
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_Text_WouldYouLikeToExit:
	.string "Apakah kamu ingin keluar dari SAFARI\n"
	.string "ZONE sekarang?$"

SafariZone_Text_TimesUp:
	.string "Ding-dong! Waktunya habis!\n"
	.string "Permainan SAFARI-mu selesai.$"

SafariZone_Text_OutOfBalls:
	.string "Kamu kehabisan SAFARI BALL.\n"
	.string "Permainan SAFARI-mu selesai.$"

SafariZone_Text_PlacePokeblockOnFeeder:
	.string "Apakah kamu ingin menaruh {POKEBLOCK}\n"
	.string "di {POKEBLOCK} FEEDER?$"

SafariZone_Text_PokeblockStillHere:
	.string "{STR_VAR_1} yang kamu tinggalkan\n"
	.string "sebelumnya masih ada di sini.$"

SafariZone_Text_PokeblockWasPlaced:
	.string "{STR_VAR_1} telah diletakkan\n"
	.string "di {POKEBLOCK} FEEDER.$"

Route121_SafariZoneEntrance_Text_WelcomeToSafariZone:
	.string "Selamat datang di SAFARI ZONE!\p"
	.string "Di sini, kamu bisa menyaksikan banyak\n"
	.string "jenis POKéMON yang jarang terlihat\l"
	.string "di HOENN.\p"
	.string "Dan, kamu akan melihat mereka dalam\n"
	.string "keadaan liar & tak terkendali di\l"
	.string "habitat alami mereka.\p"
	.string "Terlebih lagi, kami telah membuka\n"
	.string "gerbang untuk para TRAINER POKéMON.\p"
	.string "Kamu dianjurkan untuk menangkap\n"
	.string "POKéMON untuk disimpan!\p"
	.string "Masuklah & nikmati SAFARI ZONE!$"

Route121_SafariZoneEntrance_Text_WelcomeFirstTime:
	.string "Selamat datang di SAFARI ZONE!\n"
	.string "Apakah ini pertama kalinya kamu ke\l"
	.string "sini?$"

Route121_SafariZoneEntrance_Text_ComeInAndEnjoy:
	.string "Masuklah & nikmati SAFARI ZONE!$"

Route121_SafariZoneEntrance_Text_FirstTimeInfo:
	.string "Saat kamu masuk SAFARI ZONE, kamu akan\n"
	.string "mendapat 30 SAFARI BALL untuk\l"
	.string "menangkap POKéMON.\p"
	.string "Permainan SAFARI akan berakhir saat\n"
	.string "SAFARI BALL-mu habis, atau setelah\l"
	.string "kamu berjalan 500 langkah.\p"
	.string "Masuklah & nikmati SAFARI ZONE!$"

Route121_SafariZoneEntrance_Text_WouldYouLikeToPlay:
	.string "Selamat datang di SAFARI ZONE!\p"
	.string "Tangkap semua yang kamu bisa hanya\n"
	.string "dengan ¥500! Mau bermain SAFARI Game?$"

Route121_SafariZoneEntrance_Text_PlayAnotherTime:
	.string "Baiklah.\n"
	.string "Silakan bermain lain kali!$"

Route121_SafariZoneEntrance_Text_NotEnoughMoney:
	.string "Uangmu tidak cukup.\n"
	.string "Maaf.$"

Route121_SafariZoneEntrance_Text_ThatWillBe500Please:
	.string "Itu ¥500, ya.$"

Route121_SafariZoneEntrance_Text_HereAreYourSafariBalls:
	.string "Ini SAFARI BALL-mu.$"

Route121_SafariZoneEntrance_Text_Received30SafariBalls:
	.string "{PLAYER} menerima 30 SAFARI BALL.$"

Route121_SafariZoneEntrance_Text_PleaseEnjoyYourself:
	.string "Kami akan memberitahumu saat\n"
	.string "permainanmu selesai.\p"
	.string "Jadi, sampai saat itu, bersenang-\n"
	.string "senanglah! Silakan mulai petualangan\l"
	.string "liarmu!$"

Route121_SafariZoneEntrance_Text_PCIsFull:
	.string "Maaf!\n"
	.string "PC BOX-mu penuh.$"

Route121_SafariZoneEntrance_Text_YouNeedPokeblockCase:
	.string "Maaf!\n"
	.string "Kamu sepertinya tidak punya\l"
	.string "{POKEBLOCK} CASE.\p"
	.string "Permainan SAFARI-mu akan lebih\n"
	.string "bermanfaat jika kamu memakai\l"
	.string "{POKEBLOCK}.\p"
	.string "Silakan kembali dengan {POKEBLOCK}\n"
	.string "CASE.\p"
	.string "Kamu bisa mendapatkan {POKEBLOCK}\n"
	.string "CASE dari LILYCOVE CONTEST HALL.$"

SafariZone_South_Text_StillHaveTimeExit:
	.string "Kamu masih punya waktu. Apakah kamu\n"
	.string "ingin keluar dari SAFARI ZONE\l"
	.string "sekarang?$"

SafariZone_South_Text_EnjoyTheRestOfYourAdventure:
	.string "Silakan nikmati sisa petualangan\n"
	.string "liarmu!$"

SafariZone_South_Text_ExitEarlyThankYouForPlaying:
	.string "Baiklah.\p"
	.string "Aku akan mengambil kembali SAFARI\n"
	.string "BALL-mu yang tersisa.\p"
	.string "Terima kasih sudah bermain.\n"
	.string "Kami harap bisa bertemu lagi.$"

SafariZone_South_Text_GoodLuck:
	.string "Semoga berhasil!\p"
	.string "Jika kamu butuh sesuatu, jangan ragu\n"
	.string "untuk memberitahuku!$"

SafariZone_South_Text_Boy:
	.string "Tahukah kamu?\p"
	.string "Jika kamu menaruh {POKEBLOCK} di kotak\n"
	.string "persegi itu, POKéMON akan berkumpul.$"

SafariZone_South_Text_Man:
	.string "Aku ingin terus masuk lebih dalam, tapi\n"
	.string "aku lupa membawa SEPEDA.\p"
	.string "Ada firasat kalau POKéMON langka\n"
	.string "tinggal di daerah terpencil.$"

SafariZone_Southwest_Text_Woman:
	.string "Kadang, saat aku melempar {POKEBLOCK}\n"
	.string "ke POKéMON, itu diabaikan.\p"
	.string "Apakah POKéMON punya kesukaan &\n"
	.string "ketidaksukaan soal makanan mereka?$"

SafariZone_Northwest_Text_Man:
	.string "Terengah… Terengah…\n"
	.string "Aku… berhasil sampai sini… tapi…\p"
	.string "Aku lelah… Aku tidak punya energi\n"
	.string "untuk menangkap POKéMON…$"

SafariZone_North_Text_Fisherman:
	.string "Aku sedang mencari POKéMON AIR yang\n"
	.string "tidak terlihat di HOENN.\p"
	.string "Apakah kamu tahu di mana danau itu?$"

SafariZone_North_Text_Man:
	.string "Aku akan menangkap banyak POKéMON\n"
	.string "langka di sini & menukarnya dengan\l"
	.string "teman-temanku!$"

SafariZone_South_Text_Youngster:
	.string "Aku menaruh {POKEBLOCK} di {POKEBLOCK}\n"
	.string "FEEDER. Tapi sepertinya sudah hilang.\p"
	.string "Kurasa POKéMON pasti memakannya\n"
	.string "tanpa aku sadari.$"

Route121_SafariZoneEntrance_Text_TrainerTip:
	.string "TIPS TRAINER SAFARI ZONE!\p"
	.string "Lempar {POKEBLOCK} ke POKéMON liar agar\n"
	.string "mereka tidak mudah kabur.$"

SafariZone_Southwest_Text_RestHouseSign:
	.string "“Istirahatkan kakimu yang lelah.”\n"
	.string "RUMAH ISTIRAHAT$"

SafariZone_RestHouse_Text_Youngster:
	.string "Aku tidak punya {POKEBLOCK}, tapi aku\n"
	.string "berhasil menangkap banyak POKéMON.\p"
	.string "Kamu bisa meningkatkan peluang\n"
	.string "menangkap dengan mendekati mereka\l"
	.string "sebelum melempar SAFARI BALL.$"

SafariZone_RestHouse_Text_PsychicM:
	.string "Jika kamu memakai {POKEBLOCK}, POKéMON\n"
	.string "liar tidak akan cepat kabur.\p"
	.string "Tidak banyak gunanya memberi\n"
	.string "{POKEBLOCK} ke POKéMON yang tidak\l"
	.string "mudah kabur.$"

SafariZone_RestHouse_Text_FatMan:
	.string "Jika kamu menaruh {POKEBLOCK} di FEEDER,\n"
	.string "POKéMON akan tertarik padanya.\p"
	.string "Kurasa POKéMON dengan sifat yang\n"
	.string "sama tertarik pada {POKEBLOCK}\l"
	.string "tertentu.$"

SafariZone_South_Text_AreaOffLimits1:
	.string "Area ini masih dalam pembangunan.\n"
	.string "Maaf, tidak boleh masuk!$"

SafariZone_Southeast_Text_ExpansionIsFinished:
	.string "Proyek perluasan SAFARI ZONE sudah\n"
	.string "selesai sekarang.\p"
	.string "Kami harap kamu akan menikmati area\n"
	.string "baru ini.$"

SafariZone_South_Text_AreaOffLimits2:
	.string "Area ini masih dalam pembangunan.\n"
	.string "Maaf, tidak boleh masuk!$"

SafariZone_Southeast_Text_LittleGirl:
	.string "Wow! Asyik! Aku belum pernah melihat\n"
	.string "POKéMON ini sebelumnya!$"

SafariZone_Southeast_Text_FatMan:
	.string "POKéMON di area ini semuanya baru\n"
	.string "bagiku.\p"
	.string "Dan aku boleh menangkap POKéMON langka\n"
	.string "ini! Keren sekali!$"

SafariZone_Southeast_Text_RichBoy:
	.string "POKéMON di sekitar sini sepertinya\n"
	.string "berasal dari tempat selain HOENN.$"

SafariZone_Northeast_Text_Boy:
	.string "Aku hanya punya beberapa SAFARI BALL\n"
	.string "tersisa.\p"
	.string "Aku kesulitan memutuskan apa yang\n"
	.string "harus aku tangkap.$"

SafariZone_Northeast_Text_Woman:
	.string "Aku dengar kamu bisa melihat PIKACHU\n"
	.string "di sini. Di mana ya?$"

SafariZone_Northeast_Text_Girl:
	.string "Oh, sial!\n"
	.string "Aku tidak bisa menangkap apa pun!\p"
	.string "Aku akan membuang-buang biaya masuk\n"
	.string "jika tidak menangkap sesuatu!$"
