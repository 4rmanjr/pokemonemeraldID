BattleFrontier_OutsideEast_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_OutsideEast_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideEast_OnTransition
	.byte 0

BattleFrontier_OutsideEast_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo
	end

BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

BattleFrontier_OutsideEast_OnTransition:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	call_if_unset FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_ShowSudowoodo
	end

BattleFrontier_OutsideEast_EventScript_ShowSudowoodo::
	clearflag FLAG_HIDE_BATTLE_FRONTIER_SUDOWOODO
	return

BattleFrontier_OutsideEast_EventScript_BattleTowerSign::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePalaceSign::
	msgbox BattleFrontier_OutsideEast_Text_BattlePalaceSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattleArenaSign::
	msgbox BattleFrontier_OutsideEast_Text_BattleArenaSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePyramidSign::
	msgbox BattleFrontier_OutsideEast_Text_BattlePyramidSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_NinjaBoy::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man1::
	msgbox BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Hiker::
	msgbox BattleFrontier_OutsideEast_Text_PyramidTooHarsh, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_HexManiac::
	msgbox BattleFrontier_OutsideEast_Text_ThriveInDarkness, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt1::
	msgbox BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Cook::
	lock
	msgbox BattleFrontier_OutsideEast_Text_BelieveInYouBuddy, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BattleFrontier_OutsideEast_EventScript_RichBoy::
	msgbox BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_ExpertF::
	msgbox BattleFrontier_OutsideEast_Text_OnceBeatGymLeader, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_TriathleteF::
	msgbox BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Twin::
	msgbox BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man2::
	lock
	msgbox BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_TriathleteM::
	msgbox BattleFrontier_OutsideEast_Text_DidScottBringYouHere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Sudowoodo::
	lock
	faceplayer
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_FRONTIER_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
	waitmovement 0
	release
	end

BattleFrontier_OutsideEast_EventScript_WaterSudowoodo::
	lock
	faceplayer
	special DoWateringBerryTreeAnim
	waitstate
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_FRONTIER_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
	waitmovement 0
	msgbox gText_Sudowoodo_Attacked, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_SUDOWOODO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_FRONTIER_SUDOWOODO
	setwildbattle SPECIES_SUDOWOODO, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	setflag FLAG_DEFEATED_SUDOWOODO
	release
	end

BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo::
	setflag FLAG_DEFEATED_SUDOWOODO
	goto Common_EventScript_RemoveStaticPokemon
	end

BattleFrontier_OutsideEast_Movement_SudowoodoShake:
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	step_end

BattleFrontier_OutsideEast_EventScript_Maniac1::
	msgbox BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Girl::
	msgbox BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_PsychicM::
	msgbox BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man3::
	msgbox BattleFrontier_OutsideEast_Text_GotWipedOut, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman1::
	msgbox BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman2::
	msgbox BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt2::
	msgbox BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Maniac2::
	lock
	msgbox BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Woman3::
	lock
	msgbox BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_RankingHallSign::
	msgbox BattleFrontier_OutsideEast_Text_RankingHallSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_ExchangeCornerSign::
	msgbox BattleFrontier_OutsideEast_Text_ExchangeCornerSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_Gentleman::
	msgbox BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_OldWoman::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone
	msgbox BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone::
	msgbox BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Camper::
	msgbox BattleFrontier_OutsideEast_Text_StickyMonWithLongTail, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_Text_BattleTowerSign:
	.string "Ini BATTLE TOWER!\n"
	.string "Pertahankan kemenangan beruntun sebagai\l"
	.string "TRAINER terkuat!$"

BattleFrontier_OutsideEast_Text_BattlePalaceSign:
	.string "Ini BATTLE PALACE!\n"
	.string "Perhatikan terus pertarungan POKéMON!$"

BattleFrontier_OutsideEast_Text_BattleArenaSign:
	.string "Ini BATTLE ARENA!\n"
	.string "Biarkan tim terkuat berkumpul!$"

BattleFrontier_OutsideEast_Text_BattlePyramidSign:
	.string "Ini BATTLE PYRAMID!\n"
	.string "Lanjutkan melalui Battle Quest!$"

BattleFrontier_OutsideEast_Text_RankingHallSign:
	.string "BATTLE FRONTIER RANKING HALL\n"
	.string "Targetkan rekor baru!$"

BattleFrontier_OutsideEast_Text_ExchangeCornerSign:
	.string "BATTLE POINT EXCHANGE SERVICE CORNER\n"
	.string "Tukarkan Battle Point-mu!$"

BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial:
	.string "Wow!\n"
	.string "Besar sekali!\p"
	.string "BATTLE TOWER terasa istimewa.\n"
	.string "Berbeda dari yang lain.$"

BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier:
	.string "Ambisi besarku adalah menaklukkan\n"
	.string "BATTLE FRONTIER dan POKéMON\l"
	.string "LEAGUE.\p"
	.string "Dan jika mimpiku menjadi kenyataan…\p"
	.string "Aku… Aku akan meminta MIMI di sebelah\n"
	.string "untuk menjadi temanku!$"

BattleFrontier_OutsideEast_Text_PyramidTooHarsh:
	.string "BATTLE PYRAMID terlalu berat!\n"
	.string "Aku tidak bisa sampai ke puncak!\p"
	.string "Karena kehabisan pilihan, mungkin aku bisa\n"
	.string "memanjat dari luar…$"

BattleFrontier_OutsideEast_Text_ThriveInDarkness:
	.string "Aku berkembang dalam kegelapan…\n"
	.string "Ya… Apa yang layak untukku?\l"
	.string "Tidak lain adalah BATTLE PYRAMID…\p"
	.string "Bagaimana kalau berkelana dalam kegelapan\n"
	.string "dan dalam keputusasaan total?$"

BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam:
	.string "Aku tidak tidur selama seminggu, tapi kemudian\n"
	.string "aku membentuk tim pamungkas!\p"
	.string "Aku tidak bisa membayangkan diriku kalah, serius.\n"
	.string "Kami akan menyerbu BATTLE ARENA!$"

BattleFrontier_OutsideEast_Text_DidScottBringYouHere:
	.string "Apa SCOTT membawamu ke sini juga?\n"
	.string "Ada apa dengan orang itu?\p"
	.string "Sepertinya dia benar-benar tahu\n"
	.string "cara menemukan TRAINER berbakat, tapi…\p"
	.string "Aku belum pernah melihatnya bertarung\n"
	.string "secara langsung.$"

BattleFrontier_OutsideEast_Text_BelieveInYouBuddy:
	.string "ZIGG!\n"
	.string "Aku percaya padamu, sobat kecil!\p"
	.string "Aku akan membuatkan ZIGG kecilku makanan\n"
	.string "lezat favoritmu jika kamu menang!$"

BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant:
	.string "ZIGZAGOON terlihat kosong…$"

BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody:
	.string "Orang-orang memanggilku orang usil,\n"
	.string "tapi aku tidak bisa menahannya.\p"
	.string "Topimu miring!\n"
	.string "Oh, tidak, sampah di tanah!\l"
	.string "Ups, sudah hampir waktunya makan malam!\p"
	.string "Aku tidak tahu apa aku bisa tahan hanya\n"
	.string "menonton di BATTLE PALACE…$"

BattleFrontier_OutsideEast_Text_OnceBeatGymLeader:
	.string "Aku mungkin tidak terlihat mengesankan sekarang,\n"
	.string "tapi aku pernah mengalahkan seorang GYM LEADER.\p"
	.string "Siapa tahu, mungkin aku harus mencobanya\n"
	.string "lagi untuk meraih kemenangan.$"

BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles:
	.string "Aku cepat di atas SEPEDA, dan itu juga\n"
	.string "berlaku untuk caraku bertarung.\p"
	.string "Aku memenangkan pertandingan dalam sekejap\n"
	.string "mata!$"

BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon:
	.string "Aku lebih baik dari ayahku\n"
	.string "dalam POKéMON.$"

BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy:
	.string "Ayo, sayangku!\n"
	.string "Dapatkan beberapa kemenangan untuk Ayah!\p"
	.string "Kamu sama seperti ibumu,\n"
	.string "jadi kamu akan mendominasi!$"

BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena:
	.string "Tidak mudah untuk sampai ke sini,\n"
	.string "tapi aku pernah dengar tentang gadis\l"
	.string "cantik di BATTLE ARENA.\p"
	.string "Bukannya dia, tahu tidak apa yang\n"
	.string "kutemukan?\p"
	.string "Kerumunan seniman bela diri yang berkeringat,\n"
	.string "bau, dan primitif!$"

BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere:
	.string "Aku terkadang melihat pria tua yang\n"
	.string "terlihat sangat penting masuk ke sana.\p"
	.string "Dia punya POKéMON yang sangat hebat.\n"
	.string "Tapi dia kelihatannya sangat baik.$"

BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid:
	.string "Apa kamu tahu?\n"
	.string "Legenda BATTLE PYRAMID?\p"
	.string "Ketika datang seorang TRAINER percaya diri\n"
	.string "mencapai puncak emas,\l"
	.string "akan muncul seorang pria di antara pria.\p"
	.string "Tidak tahu legenda itu?\n"
	.string "Tentu saja tidak!\l"
	.string "Aku baru saja mengarangnya!\p"
	.string "Apa artinya?\n"
	.string "Itu, temanku, aku tidak bisa bilang!$"

BattleFrontier_OutsideEast_Text_GotWipedOut:
	.string "Astaga! Ya ampun!\n"
	.string "Aku belum pernah kalah sekalipun sebelumnya!\p"
	.string "Tapi aku dihajar habis-habisan tanpa\n"
	.string "belas kasihan sama sekali!\p"
	.string "Lalu aku dibilang tidak punya\n"
	.string "bakat?! Astaga!$"

BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower:
	.string "Orang ini bertemu dengan TRAINER yang\n"
	.string "sangat tangguh saat dia berada di tantangan\l"
	.string "BATTLE TOWER.\p"
	.string "Sekarang lihat dia…\p"
	.string "Kamu harus berhati-hati jika kamu\n"
	.string "memutuskan untuk pergi ke BATTLE TOWER.$"

BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll:
	.string "Ya!\n"
	.string "Akhirnya aku punya cukup Battle Point!\p"
	.string "Kurasa aku akan menukarnya dengan BONEKA\n"
	.string "besar lainnya!$"

BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere:
	.string "Oh, ya, oke!\n"
	.string "Jadi ini RANKING HALL!\p"
	.string "Aku ingin tercatat dalam sejarah sebagai\n"
	.string "juara super dan namaku\l"
	.string "tercatat di sini untuk selamanya.$"

BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou:
	.string "Denganmu di sisiku, aku bisa melakukan apa saja.$"

BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome:
	.string "Ooh, sayang, kamu luar biasa!\p"
	.string "Ooh, aku tidak bisa menunggu lagi!\p"
	.string "Ayo kita ke MULTI BATTLE ROOM\n"
	.string "sekarang juga!\p"
	.string "Jika kita bersama di BATTLE SALON,\n"
	.string "kekuatan cinta kita akan mengalahkan\l"
	.string "semua orang yang kita temui.\p"
	.string "Di hadapan kita, sayang, semuanya\n"
	.string "akan runtuh seperti domino!$"

BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers:
	.string "BATTLE FRONTIER bukan hanya untuk\n"
	.string "TRAINER yang tangguh.\p"
	.string "Sepertinya, banyak orang dengan kemampuan\n"
	.string "khusus telah diundang.\p"
	.string "Pria itu, SCOTT…\p"
	.string "Dia mungkin membangun tempat ini untuk\n"
	.string "tujuan yang lebih besar…$"

BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle:
	.string "Permisi, anak muda.\n"
	.string "Apa penglihatanmu bagus?\p"
	.string "Ada pohon aneh di depan sana, dan bagi\n"
	.string "mataku yang lelah, pohon itu tampak bergoyang.$"

BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere:
	.string "Permisi, anak muda.\n"
	.string "Apa ingatanmu bagus?\p"
	.string "Aku punya firasat dulu ada\n"
	.string "pohon aneh di depan sini.$"

BattleFrontier_OutsideEast_Text_StickyMonWithLongTail:
	.string "Aku…\n"
	.string "Aku melihatnya!\p"
	.string "Ada semacam POKéMON lengket\n"
	.string "dengan ekor panjang di depan!\p"
	.string "Ia bersembunyi di bawah batu besar, dan\n"
	.string "terus menatapku!$"
