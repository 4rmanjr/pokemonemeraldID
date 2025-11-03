@ All the LOCALID constants used in this file are essentially redundant.
@ They're all used to have the NPC the player talked to turn back so they're facing
@ their original direction (because they're watching/participating in the contests).
@ They could all be substituted for VAR_LAST_TALKED.
LilycoveCity_ContestHall_MapScripts::
	.byte 0

LilycoveCity_ContestHall_EventScript_Boy1::
	msgbox LilycoveCity_ContestHall_Text_TodayWonSmartnessContest, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Boy2::
	msgbox LilycoveCity_ContestHall_Text_EnteredBunchOfContests, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Girl::
	msgbox LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Sailor::
	msgbox LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_SmartContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EnteredWrongContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_RaisedMonToBeSmart, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience1::
	msgbox LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_StillLoveSmartnessContests, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_OverdidGrooming, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_InTheMiddleOfContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyAzurillWasDistracted, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_NeverWonBattleButContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PetalDanceIsMarvel, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience1::
	lockall
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_ContestHall_Text_MyChildIsInContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 25
	msgbox LilycoveCity_ContestHall_Text_ComeOnDear, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyStageSign::
	msgbox LilycoveCity_ContestHall_Text_BeautyContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_CuteStageSign::
	msgbox LilycoveCity_ContestHall_Text_CuteContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartStageSign::
	msgbox LilycoveCity_ContestHall_Text_SmartContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_Text_TodayWonSmartnessContest:
	.string "POKéMON ini pernah memenangkan\n"
	.string "BEAUTY CONTEST di sini sebelumnya.\p"
	.string "Nah, tebak? Hari ini, aku membuatnya\n"
	.string "memenangkan SMARTNESS CONTEST!\p"
	.string "Kemampuanku bahkan membuatku takut…$"

LilycoveCity_ContestHall_Text_EnteredBunchOfContests:
	.string "Aku sudah mengikuti banyak CONTEST,\n"
	.string "jadi aku mulai mengerti cara kerjanya.\p"
	.string "Jika kamu di COOLNESS CONTEST, jurus\n"
	.string "keren diterima sebagai daya tarik.\p"
	.string "Tapi jurus cerdas dan imut tidak\n"
	.string "begitu diterima, misalnya.$"

LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks:
	.string "Anak muda yang menang tadi punya\n"
	.string "banyak sekali {POKEBLOCK} yang berbeda.\p"
	.string "Apa bisa menang jika punya sebanyak\n"
	.string "itu?$"

LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous:
	.string "Whoa, tempat ini besar sekali!\p"
	.string "Tegang sekali suasananya… Tidak\n"
	.string "seperti aula CONTEST di pedesaan.$"

LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal:
	.string "MC: Oke, POKéMON CERDAS dan\n"
	.string "TRAINER-nya, apa kalian siap?!\p"
	.string "Berikan penampilan terbaikmu!\n"
	.string "Ayo tunjukkan daya tarikmu!$"

LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest:
	.string "JURI: Apa kamu menikmati CONTEST\n"
	.string "ini?\p"
	.string "Kembalilah dengan tiga teman, dan\n"
	.string "kalian semua bisa mengikuti CONTEST!$"

LilycoveCity_ContestHall_Text_EnteredWrongContest:
	.string "Ayayayay…\n"
	.string "Aku salah masuk CONTEST.\p"
	.string "Aku memasukkan POKéMON tangguh ini\n"
	.string "ke SMARTNESS CONTEST…\p"
	.string "Ayo, buat mereka terkesan dengan\n"
	.string "ROCK SMASH yang terlihat cerdas.$"

LilycoveCity_ContestHall_Text_RaisedMonToBeSmart:
	.string "Aku telah menghabiskan bertahun-tahun,\n"
	.string "dan semua kebijaksanaanku, untuk\l"
	.string "membesarkan POKéMON ini menjadi\l"
	.string "cerdas.\p"
	.string "Ia tidak akan mudah dikalahkan oleh\n"
	.string "POKéMON anak kemarin sore.\p"
	.string "Istriku sayang, apa kamu melihat ini?$"

LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext:
	.string "Itu dia!\p"
	.string "Jika POKéMON-ku melakukan jurus\n"
	.string "cerdas berikutnya, semangat penonton\l"
	.string "akan memuncak!$"

LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife:
	.string "Oh, tidak!\p"
	.string "LEECH LIFE ZUBAT kesayanganku sangat\n"
	.string "imut, jadi aku terus menggunakannya!\p"
	.string "Tapi orang-orang jahat ini sama\n"
	.string "sekali tidak menghargainya!$"

LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa:
	.string "Kiyaaah! Kakek tampan sekali!$"

LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves:
	.string "Bahkan ketika TRAINER memasukkan\n"
	.string "jenis POKéMON yang sama, mereka\l"
	.string "semua tampaknya menggunakan jurus\l"
	.string "yang berbeda untuk daya tarik.\p"
	.string "Sama seperti orang memiliki gaya\n"
	.string "bertarung yang berbeda.$"

LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers:
	.string "Menurutku POKéMON terlihat lebih\n"
	.string "pintar dari TRAINER mereka. Jauh\l"
	.string "lebih pintar.$"

LilycoveCity_ContestHall_Text_StillLoveSmartnessContests:
	.string "Pada akhirnya, aku tetap suka\n"
	.string "SMARTNESS CONTESTS.\p"
	.string "Warna hijau intelektual itu…\n"
	.string "Sangat… Sangat… Keren.$"

LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest:
	.string "MC: Apa kamu juga ikut BEAUTY\n"
	.string "CONTEST? Semoga berhasil!$"

LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty:
	.string "JURI: Ah, setiap POKéMON di sini\n"
	.string "adalah model kecantikan yang murni!\p"
	.string "Astaga, aku hampir lupa memberi\n"
	.string "mereka nilai!$"

LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty:
	.string "POKéMON secantik ini…\n"
	.string "Tidak ada duanya.\p"
	.string "Mata semua orang akan terpaku pada\n"
	.string "kecantikanku.$"

LilycoveCity_ContestHall_Text_OverdidGrooming:
	.string "Waaaah!\p"
	.string "Aku menyisir dan merawat POKéMON-ku\n"
	.string "dengan hati-hati untuk CONTEST ini…\p"
	.string "Tapi aku berlebihan…\n"
	.string "Bulu POKéMON-ku jadi acak-acakan…\p"
	.string "Apa yang harus kulakukan?$"

LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam:
	.string "AURORA BEAM ini sangat menyilaukan,\n"
	.string "JURI tidak akan bisa melihatnya.\p"
	.string "Uh, tunggu sebentar…\n"
	.string "Kalau begitu jadi tidak ada artinya!$"

LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe:
	.string "POKéMON cantik ini mirip sekali\n"
	.string "denganku waktu muda.\p"
	.string "Tepat saat aku mengatakan itu,\n"
	.string "suamiku menyemburkan kopi yang\l"
	.string "diminumnya.\p"
	.string "Apa aku mengatakan sesuatu yang lucu?$"

LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy:
	.string "Kamu tahu, jika aku menang di BEAUTY\n"
	.string "CONTEST, tentu itu membuatku senang.\l"
	.string "Lebih dari biasanya.$"

LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon:
	.string "Wahahahah!\p"
	.string "Coba lihat semua POKéMON cantik\n"
	.string "itu!\l"
	.string "Aku suka sekali kemewahan seperti\l"
	.string "ini!$"

LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone:
	.string "Kamu tidak bisa selalu menang hanya\n"
	.string "dengan kecantikan saja.\p"
	.string "Kamu harus merawat POKéMON-mu agar\n"
	.string "bagus dan berkilau seperti milikku.$"

LilycoveCity_ContestHall_Text_InTheMiddleOfContest:
	.string "MC: Uh-oh! Halo!\n"
	.string "Kami sedang di tengah-tengah CONTEST!\p"
	.string "Silakan masuk melalui loket\n"
	.string "pendaftaran kami dan keluar, oke?$"

LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals:
	.string "JURI: Oh, daya tarik yang menawan\n"
	.string "dan imut!\p"
	.string "Ya ampun! Daya tarik WATER SPORT\n"
	.string "yang sangat menggemaskan!$"

LilycoveCity_ContestHall_Text_MyAzurillWasDistracted:
	.string "Oh, tidak… AZURILL manisku\n"
	.string "terganggu oleh POKéMON lain.$"

LilycoveCity_ContestHall_Text_NeverWonBattleButContest:
	.string "POKéMON-ku tidak pernah menang dalam\n"
	.string "pertarungan, tapi masukkan ke\l"
	.string "CONTEST dan lihat saja!$"

LilycoveCity_ContestHall_Text_PetalDanceIsMarvel:
	.string "PETAL DANCE POKéMON-ku adalah\n"
	.string "keajaiban keanggunan.\p"
	.string "Aku tidak akan membiarkan siapa pun\n"
	.string "mengganggu penampilannya.$"
	
LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter:
	.string "POKéMON semua orang sangat imut.\p"
	.string "Namun, jika POKéMON-ku membuat\n"
	.string "daya tarik yang imut…\p"
	.string "Aku yakin itu akan jauh lebih imut\n"
	.string "dari yang lain.$"

LilycoveCity_ContestHall_Text_MyChildIsInContest:
	.string "Anakku ada di CONTEST ini.$"

LilycoveCity_ContestHall_Text_ComeOnDear:
	.string "Ayo, sayang. Semangat!\n"
	.string "POKéMON-mu yang terbaik!$"

LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest:
	.string "Menurutku gadis di sana itu yang\n"
	.string "paling imut dari semuanya.\p"
	.string "Apa katamu? Mereka menilai POKéMON\n"
	.string "dari penampilannya?$"

LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn:
	.string "Ohh, melihat semua POKéMON imut\n"
	.string "ini, membuatku ingin punya sendiri!\p"
	.string "Aku akan pergi menangkap beberapa!$"

LilycoveCity_ContestHall_Text_BeautyContestStage:
	.string "PANGGUNG BEAUTY CONTEST\n"
	.string "TERPIKAT OLEH POKéMON CANTIK!$"

LilycoveCity_ContestHall_Text_CuteContestStage:
	.string "PANGGUNG CUTENESS CONTEST\n"
	.string "TERPESONA OLEH POKéMON IMUT!$"

LilycoveCity_ContestHall_Text_SmartContestStage:
	.string "PANGGUNG SMARTNESS CONTEST\n"
	.string "TERKESAN OLEH POKéMON CERDAS!$"
