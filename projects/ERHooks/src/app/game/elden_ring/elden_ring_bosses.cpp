#include "elden_ring_bosses.hpp"

namespace er::bosses
{
	static boss_map_t base_bosses_map{};
	static boss_map_t dlc_bosses_map{};

	const boss_map_t &GetBaseBosses() { return base_bosses_map; }
	const boss_map_t &GetDLCBosses() { return dlc_bosses_map; }
}

// https://github.com/FrankvdStam/SoulSplitter/blob/main/src/SoulMemory/EldenRing/Boss.cs

auto er_bosses_init_base_bosses_map = [&]()
{
	er::bosses::base_bosses_map = 
	{
		{
			"Stranded Graveyard",
			{
				{ 18000850, "Soldier of Godrick - Stranded Graveyard" },
				{ 18000800, "Ulcerated Tree Spirit - Stranded Graveyard" }
			}
		},

		{
			"Chapel of Anticipation",
			{
				{ 10010800, "Grafted Scion - Chapel of Anticipation" }
			}
		},

		{
			"Limgrave",
			{
				{ 1042360800, "Tree Sentinel - Church of Elleh" },
				{ 1042370800, "Crucible Knight - Stormhill Evergaol" },
				{ 1042380800, "Deathbird - Stormgate" },
				{ 1042380850, "Ball-Bearing Hunter - Warmaster's Shack" },
				{ 1043360800, "Flying Dragon Agheel - Dragon-Burnt Ruins" },
				{ 1043370800, "Night's Cavalry - Agheel Lake North" },
				{ 1044350800, "Bloodhound Knight Darriwill - Forlorn Hound Evergaol" },
				{ 1044360800, "Mad Pumpkin Head - Waypoint Ruins" },
				{ 1045390800, "Tibia Mariner - Summonwater Village" },
				{ 30000800, "Cemetery Shade - Tombsward Catacombs" },
				{ 30020800, "Erdtree Burial Watchdog - Stormfoot Catacombs" },
				{ 30040800, "Grave Warden Duelist - Murkwater Catacombs" },
				{ 30110800, "Black Knife Assassin - Deathtouched Catacombs" },
				{ 31000800, "Patches - Murkwater Cave" },
				{ 31020800, "Miranda the Blighted Bloom - Tombsward Cave" },
				{ 31030800, "Beastman of Farum Azula - Groveside Cave" },
				{ 31150800, "Demi-Human Chief - Coastal Cave" },
				{ 31170800, "Guardian Golem - Highroad Cave" },
				{ 32010800, "Stonedigger Troll - Limgrave Tunnels" }
			}
		},

		{
			"Weeping Peninsula",
			{
				{ 1042330800, "Ancient Hero of Zamor - Weeping Evergaol" },
				{ 1043300800, "Leonine Misbegotten - Castle Morne" },
				{ 1043330800, "Erdtree Avatar - Minor Erdtree" },
				{ 1044320800, "Deathbird - Castle Morne Approach" },
				{ 1044320850, "Night's Cavalry - Castle Morne Approach" },
				{ 30010800, "Erdtree Burial Watchdog - Impaler's Catacombs" },
				{ 31010800, "Runebear - Earthbore Cave" },
				{ 32000800, "Scaly Misbegotten - Morne Tunnel" }
			}
		},

		{
			"Stormveil Castle",
			{
				{ 10000850, "Margit, the Fell Omen - Stormveil Castle" },
				{ 10000800, "Godrick the Grafted - Stormveil Castle" },
			}
		},

		{
			"Liurnia of the Lakes",
			{
				{ 1033420800, "Alecto, Black Knife Ringleader - Moonlight Altar" },
				{ 1033430800, "Erdtree Avatar - Revenger's Shack" },
				{ 1033450800, "Bols, Carian Knight - Cuckoo's Evergaol" },
				{ 1034420800, "Glintstone Dragon Adula - Moonfolk Ruins" },
				{ 1034450800, "Glintstone Dragon Smarag - Meeting Place" },
				{ 1034480800, "Royal Revenant - Kingsrealm Ruins" },
				{ 1035420800, "Omenkiller - Village of the Albinaurics" },
				{ 1035500800, "Royal Knight Loretta - Carian Manor" },
				{ 1036450800, "Death Rite Bird - Gate Town Northwest" },
				{ 1036480800, "Night's Cavalry - East Raya Lucaria Gate" },
				{ 1036500800, "Onyx Lord - Royal Grave Evergaol" },
				{ 1037420800, "Deathbird - Laskyar Ruins" },
				{ 1037460800, "Ball-Bearing Hunter - Church of Vows" },
				{ 1038410800, "Adan, Thief of Fire - Malefactor's Evergaol" },
				{ 1038480800, "Erdtree Avatar - Minor Erdtree" },
				{ 1039430800, "Night's Cavalry - Liurnia Highway Far North" },
				{ 1039440800, "Tibia Mariner - Jarburg" },
				{ 30030800, "Spirit-Caller Snail - Road's End Catacombs" },
				{ 30050800, "Cemetery Shade - Black Knife Catacombs" },
				{ 30050850, "Black Knife Assassin - Black Knife Catacombs" },
				{ 30060800, "Erdtree Burial Watchdog - Cliffbottom Catacombs" },
				{ 31040800, "Cleanrot Knight - Stillwater Cave" },
				{ 31050800, "Bloodhound Knight - Lakeside Crystal Cave" },
				{ 31060800, "Crystalians - Academy Crystal Cave" },
				{ 32020800, "Crystalian (Ringblade) - Raya Lucaria Crystal Tunnel" },
				{ 39200800, "Magma Wyrm Makar - Ruin-Strewn Precipice" }
			}
		},

		{
			"Academy of Raya Lucaria",
			{
				{ 14000800, "Rennala, Queen of the Full Moon - Academy of Raya Lucaria" },
				{ 14000850, "Red Wolf of Radagon - Academy of Raya Lucaria" }
			}
		},

		{
			"Caelid",
			{
				{ 1047400800, "Putrid Avatar - Minor Erdtree" },
				{ 1048370800, "Decaying Ekzykes - Caelid Highway South" },
				{ 1048400800, "Pumpkinhead Duo - Caelem Ruins" },
				{ 1049370800, "Night's Cavalry - Southern Aeonia Swamp Bank" },
				{ 1049370850, "Death Rite Bird - Southern Aeonia Swamp Bank" },
				{ 1049380800, "Commander O'Neil - East Aeonia Swamp" },
				{ 1049390800, "Nox Priest - West Sellia" },
				{ 1049390850, "Battlemage Hugues - Sellia Crystal Tunnel Entrance" },
				{ 1051360800, "Crucible Knight - Redmane Castle" },
				{ 1051400800, "Putrid Avatar - Dragonbarrow Fork" },
				{ 1051430800, "Black Blade Kindred - Bestial Sanctum" },
				{ 1052410800, "Flying Dragon Greyll - Dragonbarrow" },
				{ 1052410850, "Night's Cavalry - Dragonbarrow" },
				{ 1252380800, "Starscourge Radahn - Battlefield" },
				{ 30140800, "Erdtree Burial Watchdog - Minor Erdtree Catacombs" },
				{ 30150800, "Cemetery Shade - Caelid Catacombs" },
				{ 30160800, "Putrid Tree Spirit - War-Dead Catacombs" },
				{ 31110800, "Putrid Crystalians - Sellia Hideaway" },
				{ 31200800, "Cleanrot Knight - Abandoned Cave" },
				{ 31210800, "Frenzied Duelist - Gaol Cave" },
				{ 32070800, "Magma Wyrm - Gael Tunnel" },
				{ 32080800, "Fallingstar Beast - Sellia Crystal Tunnel" },
				{ 34130800, "Godskin Apostle - Divine Tower of Caelid" }
			}
		},

		{
			"Greyoll's Dragonbarrow",
			{
				{ 1048410800, "Bell-Bearing Hunter - Isolated Merchant's Shack" },
				{ 31100800, "Beastman of Farum Azula - Dragonbarrow Cave" }
			}
		},

		{
			"Altus Plateau",
			{
				{ 1037510800, "Ancient Dragon Lansseax - Abandoned Coffin" },
				{ 1038510800, "Demi-Human Queen - Lux Ruins" },
				{ 1038520800, "Tibia Mariner - Wyndham Ruins" },
				{ 1039500800, "Godefroy the Grafted - Golden Lineage Evergaol" },
				{ 1039510800, "Night's Cavalry - Altus Highway" },
				{ 1039540800, "Elemer of the Briar - Shaded Castle" },
				{ 1040520800, "Black Knife Assassin - Sainted Hero's Grave Entrance" },
				{ 1040530800, "Sanguine Noble - Writheblood Ruins" },
				{ 1041500800, "Fallingstar Beast - South of Tree Sentinel Duo" },
				{ 1041510800, "Tree Sentinel - Tree Sentinel Duo" },
				{ 1041520800, "Ancient Dragon Lansseax - Rampartside Path" },
				{ 1041530800, "Wormface - Woodfolk Ruins" },
				{ 1042550800, "Godskin Apostle - Windmill Heights" },
				{ 30070800, "Erdtree Burial Watchdog - Wyndham Catacombs" },
				{ 30080800, "Ancient Hero of Zamor - Sainted Hero's Grave" },
				{ 30100800, "Crucible Knight (Tree Spear) - Auriza Hero's Grave" },
				{ 30100800, "Crucible Knight Ordovis - Auriza Hero's Grave" },
				{ 30130800, "Grave Warden Duelist - Auriza Side Tomb" },
				{ 31180800, "Miranda the Blighted Bloom - Perfumer's Grotto" },
				{ 31190800, "Black Knife Assassin - Sage's Cave" },
				{ 31190850, "Necromancer Garris - Sage's Cave" },
				{ 32040800, "Stonedigger Troll - Old Altus Tunnel" },
				{ 32050800, "Crystalian (Ringblade) - Altus Tunnel" },
				{ 32050800, "Crystalian (Spear) - Altus Tunnel" },
				{ 34120800, "Onyx Lord - Divine Tower of West Altus" }
			}
		},

		{
			"Mt. Gelmir",
			{
				{ 1035530800, "Magma Wyrm - Seethewater Terminus" },
				{ 1036540800, "Full-Grown Fallingstar Beast - Crater" },
				{ 1037530800, "Demi-Human Queen - Primeval Sorcerer Azur" },
				{ 1037540810, "Ulcerated Tree Spirit - Minor Erdtree" },
				{ 30090800, "Red Wolf of the Champion - Gelmir Hero's Grave" },
				{ 30120800, "Misbegotten Warrior - Unsightly Catacombs" },
				{ 30120800, "Perfumer Tricia - Unsightly Catacombs" },
				{ 31070800, "Kindred of Rot - Seethewater Cave" },
				{ 31090800, "Demi-Human Queen Margot - Volcano Cave" }
			}
		},

		{
			"Volcano Manor",
			{
				{ 16000800, "Rykard, Lord of Blasphemy - Volcano Manor" },
				{ 16000850, "Godskin Noble - Volcano Manor" },
				{ 16000860, "Abductor Virgins - Volcano Manor" }
			}
		},

		{
			"Capital Outskirts",
			{
				{ 1043530800, "Ball-Bearing Hunter - Hermit Merchant's Shack" },
				{ 1044530800, "Deathbird - Minor Erdtree" },
				{ 1045520800, "Draconic Tree Sentinel - Capital Rampart" },
				{ 34140850, "Fell Twins - Divine Tower of East Altus" }
			}
		},

		{
			"Leyndell",
			{
				{ 11000800, "Morgott, the Omen King - Leyndell" },
				{ 11000850, "Godfrey, First Elden Lord - Leyndell" }
			}
		},

		{
			"Forbidden Lands",
			{
				{ 30202800, "Stray Mimic Tear - Hidden Path to the Haligtree" },
				{ 1048510800, "Night's Cavalry - Forbidden Lands" },
				{ 1049520800, "Black Blade Kindred - Before Grand Lift of Rold" }
			}
		},

		{
			"Mountaintops of the Giants",
			{
				{ 1050560800, "Great Wyrm Theodorix - Albinauric Rise" },
				{ 1050570800, "Death Rite Bird - West of Castle Soul" },
				{ 1051570800, "Commander Niall - Castle Soul" },
				{ 1052520800, "Fire Giant - Giant's Forge" },
				{ 1052560800, "Erdtree Avatar - Minor Erdtree" },
				{ 1053560800, "Roundtable Knight Vyke - Lord Contender's Evergaol" },
				{ 1248550800, "Night's Cavalry - Southwest" },
				{ 1254560800, "Borealis the Freezing Fog - Freezing Fields" },
				{ 30170800, "Ancient Hero of Zamor - Giant-Conquering Hero's Grave" },
				{ 30180800, "Ulcerated Tree Sprit - Giants' Mountaintop Catacombs" },
				{ 31120800, "Misbegotten Crusader - Cave of the Forlorn" },
				{ 31220800, "Spirit-Caller Snail - Spiritcaller's Cave" }
			}
		},

		{
			"Crumbling Farum Azula",
			{
				{ 13000800, "Maliketh, The Black Blade - Crumbling Farum Azula" },
				{ 13000830, "Dragonlord Placidusax - Crumbling Farum Azula" },
				{ 13000850, "Godskin Duo - Crumbling Farum Azula" }
			}
		},

		{
			"Consecrated Snowfield",
			{
				{ 1048570800, "Death Rite Bird - Ordina, Liturgical Town" },
				{ 1050570850, "Putrid Avatar - Minor Erdtree" },
				{ 30190800, "Putrid Grave Warden Duelist - Consecrated Snowfield Catacombs" },
				{ 32110800, "Astel, Stars of Darkness - Yelough Anix Tunnel" }
			}
		},

		{
			"Miquella's Haligtree",
			{
				{ 15000800, "Malenia, Blade of Miquella - Miquella's Haligtree" },
				{ 15000850, "Loretta, Knight of the Haligtree - Miquella's Haligtree" }
			}
		},

		{
			"Siofra River",
			{
				{ 12020800, "Valiant Gargoyles - Siofra River" },
				{ 12020830, "Dragonkin Soldier - Siofra River" },
				{ 12020850, "Mimic Tear - Siofra River" },
				{ 12080800, "Ancestor Spirit - Siofra River" }
			}
		},

		{
			"Ainsel River",
			{
				{ 12010800, "Dragonkin Soldier of Nokstella - Ainsel River" }
			}
		},

		{
			"Nokron, Eternal City",
			{
				{ 12090800, "Regal Ancestor Spirit - Nokron, Eternal City" }
			}
		},

		{
			"Deeproot Depths",
			{
				{ 12030390, "Crucible Knight Sirulia - Deeproot Depths" },
				{ 12030800, "Fia's Champions - Deeproot Depths" },
				{ 12030850, "Lichdragon Fortissax - Deeproot Depths" }
			}
		},

		{
			"Lake of Rot",
			{
				{ 12010850, "Dragonkin Soldier - Lake of Rot" },
				{ 12040800, "Astel, Naturalborn of the Void - Lake of Rot" }
			}
		},

		{
			"Leyndell, Ashen Capital",
			{
				{ 11050800, "Hoarah Loux - Leyndell" },
				{ 11050850, "Sir Gideon Ofnir, the All-Knowing - Leyndell" }
			}
		},

		{
			"Subterranean Shunning-Grounds",
			{
				{ 35000800, "Mohg, The Omen - Subterranean Shunning-Grounds" },
				{ 35000850, "Esgar, Priest of Blood - Subterranean Shunning-Grounds" }
			}
		},

		{
			"Mohgwyn Palace",
			{
				{ 12050800, "Mohg, Lord of Blood - Mohgwyn Palace" }
			}
		},

		{
			"Elden Throne",
			{
				{ 19000800, "Elden Beast - Elden Throne" }
			}
		}
	};

	return true;
}();

auto er_bosses_init_dlc_bosses_map = [&]()
{
	er::bosses::dlc_bosses_map =
	{
		{
			"Gravesite Plain",
			{
				{ 2045440800, "Ghostflame Dragon - Gravesite Plain" },
				{ 2046410800, "Blackgaol Knight - Western Nameless Mausoleum" },
				{ 41000800, "Demi-Human Swordmaster Onze - Belurat Gaol" },
				{ 41020800, "Lamenter - Lamenter's Gaol" },
				{ 43000800, "Chief Bloodfiend - Rivermouth Cave" }
			}
		},

		{
			"Belurat, Tower Settlement",
			{
				{ 20000800, "Divine Beast Dancing Lion - Belurat, Tower Settlement" }
			}
		},

		{
			"Castle Ensis",
			{
				{ 2048440800, "Rellana, Twin Moon Knight - Castle Ensis" }
			}
		},

		{
			"Scadu Altus",
			{
				{ 2044470800, "Rugalea the Great Red Bear - Rauh Base" },
				{ 2046450800, "Red Bear - Northern Nameless Mausoleum" },
				{ 2047450800, "Black Knight Garrew - Fog Rift Fort" },
				{ 2049430800, "Ghostflame Dragon" },
				{ 2049430850, "Black Knight Edredd - Fort of Reprimand" },
				{ 2049440800, "Dryleaf Dane - Moorth Ruins" },
				{ 2049450800, "Ralva the Great Red Bear" },
				{ 2051440800, "Rakshasa - Eastern Nameless Mausoleum" },
				{ 2051450800, "Count Ymir, Mother of Fingers - Cathedral of Manus Metyr" },
				{ 25000800, "Metyr, Mother of Fingers - Cathedral of Manus Metyr" },
				{ 40000800, "Death Knight - Fog Rift Catacombs" },
				{ 40010800, "Death Knight - Scorpion River Catacombs" },
				{ 41010800, "Curseblade Labirith - Bonny Gaol" }
			}
		},

		{
			"Cerulean Coast",
			{
				{ 2046380800, "Dancer of Ranah - Southern Nameless Mausoleum" },
				{ 2048380850, "Ghostflame Dragon - Cerulean Coast" },
				{ 22000800, "Putrescent Knight - Stone Coffin Fissure" }
			}
		},

		{
			"Charo's Hidden Grave",
			{
				{ 2046400800, "Demi-Human Queen Marigga - Charo's Hidden Grave" },
				{ 2047390800, "Death Rite Bird - Charo's Hidden Grave" }
			}
		},

		{
			"Jagged Peak",
			{
				{ 2049410800, "Jagged Peak Drake - Foot of the Jagged Peak" },
				{ 2052400800, "Jagged Peak Drake - Jagged Peak Mountainside" },
				{ 2054390800, "Bayle the Dread - Jagged Peak Summit" },
				{ 2054390850, "Ancient Dragon Senessax - Jagged Peak Mountainside" },
				{ 43010800, "Ancient Dragon-Man - Dragon's Pit" }
			}
		},

		{
			"Abyssal Woods",
			{
				{ 2052430800, "Jori, Elder Inquisitor - Darklight Catacombs" },
				{ 28000800, "Midra, Lord of Frenzied Flame - Midra's Manse" }
			}
		},

		{
			"Scaduview",
			{
				{ 2049480800, "Commander Gaius - Scaduview" },
				{ 2050470800, "Tree Sentinel - Hinterland" },
				{ 2050480860, "Tree Sentinel - Hinterland Bridge" },
				{ 2050480800, "Scadutree Avatar - Scadutree Base" },
				{ 2052480800, "Fallingstar Beast - Fingerstone Hill" }
			}
		},

		{
			"Shadow Keep",
			{
				{ 21000850, "Golden Hippopotamus - Main Gate Plaza" },
				{ 21010800, "Base Serpent Messmer - Messmer's Dark Chamber" }
			}
		},

		{
			"Ancient Ruins of Rauh",
			{
				{ 2046460800, "Divine Beast Dancing Lion - Ancient Ruins of Rauh" }
			}
		},

		{
			"Church of the Bud",
			{
				{ 2044450800, "Romina, Saint of the Bud - Church of the Bud" }
			}
		},

		{
			"Enir-Ilim",
			{
				{ 20010800, "Radahn, Consort of Miquella - Enir-Ilim" }
			}
		}
	};

	return true;
}();