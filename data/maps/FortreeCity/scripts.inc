FortreeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, FortreeCity_OnResume
	.byte 0

FortreeCity_OnTransition:
	setflag FLAG_VISITED_FORTREE_CITY
	end

FortreeCity_OnResume:
	setstepcallback STEP_CB_FORTREE_BRIDGE
	end

FortreeCity_EventScript_Man::
	msgbox FortreeCity_Text_SawGiganticPokemonInSky, MSGBOX_NPC
	end

FortreeCity_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_KECLEON_FLED_FORTREE, FortreeCity_EventScript_WomanGymAccessible
	msgbox FortreeCity_Text_SomethingBlockingGym, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_WomanGymAccessible::
	msgbox FortreeCity_Text_ThisTimeIllBeatWinona, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_Girl::
	msgbox FortreeCity_Text_TreesGrowByDrinkingRainwater, MSGBOX_NPC
	end

FortreeCity_EventScript_OldMan::
	msgbox FortreeCity_Text_EveryoneHealthyAndLively, MSGBOX_NPC
	end

FortreeCity_EventScript_Boy::
	msgbox FortreeCity_Text_BugPokemonComeThroughWindow, MSGBOX_NPC
	end

FortreeCity_EventScript_GameboyKid::
	msgbox FortreeCity_Text_PokemonThatEvolveWhenTraded, MSGBOX_NPC
	end

FortreeCity_EventScript_CitySign::
	msgbox FortreeCity_Text_CitySign, MSGBOX_SIGN
	end

FortreeCity_EventScript_GymSign::
	msgbox FortreeCity_Text_GymSign, MSGBOX_SIGN
	end

FortreeCity_EventScript_Kecleon::
	lock
	faceplayer
	checkitem ITEM_DEVON_SCOPE
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_EventScript_AskUseDevonScope
	msgbox FortreeCity_Text_SomethingUnseeable, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_AskUseDevonScope::
	msgbox FortreeCity_Text_UnseeableUseDevonScope, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FortreeCity_EventScript_UseDevonScope
	release
	end

FortreeCity_EventScript_UseDevonScope::
	msgbox FortreeCity_Text_UsedDevonScopePokemonFled, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Movement_KecleonAppears
	waitmovement 0
	waitse
	playmoncry SPECIES_KECLEON, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	applymovement VAR_LAST_TALKED, FortreeCity_Movement_KecleonFlee
	waitmovement 0
	removeobject VAR_LAST_TALKED
	setflag FLAG_KECLEON_FLED_FORTREE
	release
	end

FortreeCity_Movement_KecleonFlee:
	walk_right
	step_end

FortreeCity_Text_SawGiganticPokemonInSky:
	.string "Tak ada yang percaya, tapi aku melihat\n"
	.string "POKéMON raksasa di langit.\p"
	.string "Ia tampak menggeliat saat terbang\n"
	.string "menuju ROUTE 131.\p"
	.string "Ngomong-ngomong… Sniff…\n"
	.string "Um… Kamu, uh…bau hangus.\p"
	.string "Apa kamu habis dari gunung berapi\n"
	.string "atau semacamnya?$"

FortreeCity_Text_SomethingBlockingGym:
	.string "Aku mau ke GYM POKéMON, tapi ada\n"
	.string "sesuatu yang menghalangi jalan.\p"
	.string "Padahal aku sudah susah payah\n"
	.string "berlatih di ROUTE 120…$"

FortreeCity_Text_ThisTimeIllBeatWinona:
	.string "Aku membawa POKéMON kebanggaanku.\n"
	.string "Kali ini, aku akan kalahkan WINONA.$"

FortreeCity_Text_TreesGrowByDrinkingRainwater:
	.string "Tanah menyerap air hujan, dan pohon\n"
	.string "tumbuh dengan meminum air itu…\p"
	.string "FORTREE CITY kita ada karena\n"
	.string "adanya air dan tanah.$"

FortreeCity_Text_EveryoneHealthyAndLively:
	.string "KOTA ini terdiri dari rumah-rumah\n"
	.string "yang dibangun di atas pohon.\p"
	.string "Mungkin karena gaya hidup itu, semua\n"
	.string "orang sehat dan bersemangat.\p"
	.string "Bahkan aku sendiri--merasa seolah\n"
	.string "tiga puluh tahun lebih muda.$"

FortreeCity_Text_BugPokemonComeThroughWindow:
	.string "Tinggal di atas pohon tidak masalah.\p"
	.string "Tapi kadang POKéMON BUG masuk\n"
	.string "lewat jendela.\l"
	.string "Itu bisa sangat mengejutkan.$"

FortreeCity_Text_PokemonThatEvolveWhenTraded:
	.string "Ada POKéMON yang berevolusi saat\n"
	.string "ditukar! Begitu yang kudengar.$"

FortreeCity_Text_SomethingUnseeable:
	.string "Sesuatu yang tak terlihat menghalangi\n"
	.string "jalan.$"

FortreeCity_Text_UnseeableUseDevonScope:
	.string "Sesuatu yang tak terlihat menghalangi\n"
	.string "jalan.\p"
	.string "Mau pakai DEVON SCOPE?$"

FortreeCity_Text_UsedDevonScopePokemonFled:
	.string "{PLAYER} memakai DEVON SCOPE.\p"
	.string "POKéMON yang tak terlihat menjadi\n"
	.string "terlihat sepenuhnya!\p"
	.string "POKéMON yang terkejut itu kabur!$"

FortreeCity_Text_CitySign:
	.string "FORTREE CITY\n"
	.string "“Kota puncak pohon yang bermain\l"
	.string "dengan alam.”$"

FortreeCity_Text_GymSign:
	.string "GYM POKéMON KOTA FORTREE\n"
	.string "PEMIMPIN: WINONA\p"
	.string "“Sang pengguna burung yang terbang\n"
	.string "ke penjuru dunia.”$"

