#include "elden_ring_event_flags.hpp"

namespace er::event_flags
{
	static event_flag_map_t grace_map{};
	static event_flag_map_t map_piece_map{};
	static event_flag_map_t cook_book_map{};
	static event_flag_map_t affinities_map{};

	const event_flag_map_t &GetGraceMap() { return grace_map; }
	const event_flag_map_t &GetMapPieceMap() { return map_piece_map; }
	const event_flag_map_t &GetCookBookMap() { return cook_book_map; }
	const event_flag_map_t &GetAffinitiesMap() { return affinities_map; }
}

// BonfireWarpParam
static auto er_event_flags_init_grace_map = [&]() -> bool
{
	er::event_flags::grace_map[76860] = "[Abyssal Woods] Abyssal Woods";
	er::event_flags::grace_map[76864] = "[Abyssal Woods] Church Ruins";
	er::event_flags::grace_map[76861] = "[Abyssal Woods] Divided Falls";
	er::event_flags::grace_map[76862] = "[Abyssal Woods] Forsaken Graveyard";
	er::event_flags::grace_map[76863] = "[Abyssal Woods] Woodland Trail";

	er::event_flags::grace_map[71402] = "[Academy of Raya Lucaria] Church of the Cuckoo";
	er::event_flags::grace_map[71401] = "[Academy of Raya Lucaria] Debate Parlor";
	er::event_flags::grace_map[71400] = "[Academy of Raya Lucaria] Raya Lucaria Grand Library";
	er::event_flags::grace_map[71403] = "[Academy of Raya Lucaria] Schoolhouse Classroom";

	er::event_flags::grace_map[71214] = "[Ainsel River Main] Ainsel River Main";
	er::event_flags::grace_map[71219] = "[Ainsel River Main] Nokstella Waterfall Basin";
	er::event_flags::grace_map[71215] = "[Ainsel River Main] Nokstella, Eternal City";
	er::event_flags::grace_map[71213] = "[Ainsel River] Ainsel River Downstream";
	er::event_flags::grace_map[71212] = "[Ainsel River] Ainsel River Sluice Gate";
	er::event_flags::grace_map[71211] = "[Ainsel River] Ainsel River Well Depths";
	er::event_flags::grace_map[71240] = "[Ainsel River] Astel, Naturalborn of the Void";
	er::event_flags::grace_map[71210] = "[Ainsel River] Dragonkin Soldier of Nokstella";

	er::event_flags::grace_map[76300] = "[Altus Plateau] Abandoned Coffin";
	er::event_flags::grace_map[76303] = "[Altus Plateau] Altus Highway Junction";
	er::event_flags::grace_map[76301] = "[Altus Plateau] Altus Plateau";
	er::event_flags::grace_map[73205] = "[Altus Plateau] Altus Tunnel";
	er::event_flags::grace_map[76306] = "[Altus Plateau] Bower of Bounty";
	er::event_flags::grace_map[76322] = "[Altus Plateau] Castellan's Hall";
	er::event_flags::grace_map[76302] = "[Altus Plateau] Erdtree,Gazing Hill";
	er::event_flags::grace_map[76304] = "[Altus Plateau] Forest,Spanning Greatbridge";
	er::event_flags::grace_map[73204] = "[Altus Plateau] Old Altus Tunnel";
	er::event_flags::grace_map[73118] = "[Altus Plateau] Perfumer's Grotto";
	er::event_flags::grace_map[76305] = "[Altus Plateau] Rampartside Path";
	er::event_flags::grace_map[76307] = "[Altus Plateau] Road of Iniquity Side Path";
	er::event_flags::grace_map[73119] = "[Altus Plateau] Sage's Cave";
	er::event_flags::grace_map[73008] = "[Altus Plateau] Sainted Hero's Grave";
	er::event_flags::grace_map[76320] = "[Altus Plateau] Shaded Castle Ramparts";
	er::event_flags::grace_map[76321] = "[Altus Plateau] Shaded castle Inner Gate";
	er::event_flags::grace_map[73012] = "[Altus Plateau] Unsightly Catacombs";
	er::event_flags::grace_map[76313] = "[Altus Plateau] Windmill Heights";
	er::event_flags::grace_map[76308] = "[Altus Plateau] Windmill Village";

	er::event_flags::grace_map[76944] = "[Ancient Ruins of Rauh] Ancient Ruins, Grand Stairway";
	er::event_flags::grace_map[76945] = "[Ancient Ruins of Rauh] Church of the Bud";
	er::event_flags::grace_map[76943] = "[Ancient Ruins of Rauh] Church of the Bud, Main Entrance";
	er::event_flags::grace_map[76941] = "[Ancient Ruins of Rauh] Rauh Ancient Ruins, East";
	er::event_flags::grace_map[76942] = "[Ancient Ruins of Rauh] Rauh Ancient Ruins, West";
	er::event_flags::grace_map[76940] = "[Ancient Ruins of Rauh] Viaduct Minor Tower";

	er::event_flags::grace_map[76208] = "[Bellum Highway] Bellum Church";
	er::event_flags::grace_map[76240] = "[Bellum Highway] Church of Inhibition";
	er::event_flags::grace_map[76207] = "[Bellum Highway] East Raya Lucaria Gate";
	er::event_flags::grace_map[76239] = "[Bellum Highway] Frenzied Flame Village Outskirts";

	er::event_flags::grace_map[72001] = "[Belurat, Tower Settlement] Belurat, Tower Settlement";
	er::event_flags::grace_map[72002] = "[Belurat, Tower Settlement] Small Private Altar";
	er::event_flags::grace_map[72003] = "[Belurat, Tower Settlement] Stagefront";
	er::event_flags::grace_map[72000] = "[Belurat, Tower Settlement] Theatre of the Divine Beast";

	er::event_flags::grace_map[73120] = "[Caelid] Abandoned Cave";
	er::event_flags::grace_map[76403] = "[Caelid] Caelem Ruins";
	er::event_flags::grace_map[73015] = "[Caelid] Caelid Catacombs";
	er::event_flags::grace_map[76405] = "[Caelid] Caelid Highway South";
	er::event_flags::grace_map[76404] = "[Caelid] Cathedral of Dragon Communion";
	er::event_flags::grace_map[76415] = "[Caelid] Chair,Crypt of Sellia";
	er::event_flags::grace_map[76420] = "[Caelid] Chamber Outside the Plaza";
	er::event_flags::grace_map[76418] = "[Caelid] Church of the Plague";
	er::event_flags::grace_map[76410] = "[Caelid] Deep Siofra Well";
	er::event_flags::grace_map[76402] = "[Caelid] Fort Gael North";
	er::event_flags::grace_map[73207] = "[Caelid] Gael Tunnel";
	er::event_flags::grace_map[73121] = "[Caelid] Gaol Cave";
	er::event_flags::grace_map[76417] = "[Caelid] Impassable Greatbridge";
	er::event_flags::grace_map[73014] = "[Caelid] Minor Erdtree Catacombs";
	er::event_flags::grace_map[73257] = "[Caelid] Rear Gael Tunnel Entrance";
	er::event_flags::grace_map[76419] = "[Caelid] Redmane Castle Plaza";
	er::event_flags::grace_map[76401] = "[Caelid] Rotview Balcony";
	er::event_flags::grace_map[76414] = "[Caelid] Sellia Backstreets";
	er::event_flags::grace_map[73208] = "[Caelid] Sellia Crystal Tunnel";
	er::event_flags::grace_map[76416] = "[Caelid] Sellia Under,Stair";
	er::event_flags::grace_map[76400] = "[Caelid] Smoldering Church";
	er::event_flags::grace_map[76409] = "[Caelid] Smoldering Wall";
	er::event_flags::grace_map[76411] = "[Caelid] Southern Aeonia Swamp Bank";
	er::event_flags::grace_map[76422] = "[Caelid] Starscourge Radahn";
	er::event_flags::grace_map[73016] = "[Caelid] War,Dead Catacombs";

	er::event_flags::grace_map[73010] = "[Capital Outskirts] Auriza Hero's Grave";
	er::event_flags::grace_map[73013] = "[Capital Outskirts] Auriza Side Tomb";
	er::event_flags::grace_map[76314] = "[Capital Outskirts] Capital Rampart";
	er::event_flags::grace_map[73430] = "[Capital Outskirts] Divine Tower of West Altus";
	er::event_flags::grace_map[73432] = "[Capital Outskirts] Divine Tower of West Altus: Gate";
	er::event_flags::grace_map[76311] = "[Capital Outskirts] Hermit Merchant's Shack";
	er::event_flags::grace_map[76310] = "[Capital Outskirts] Minor Erdtree Church";
	er::event_flags::grace_map[76312] = "[Capital Outskirts] Outer Wall Battleground";
	er::event_flags::grace_map[76309] = "[Capital Outskirts] Outer Wall Phantom Tree";
	er::event_flags::grace_map[73431] = "[Capital Outskirts] Sealed Tunnel";

	er::event_flags::grace_map[76821] = "[Castle Ensis] Castle Ensis Checkpoint";
	er::event_flags::grace_map[76822] = "[Castle Ensis] Castle,Lord's Chamber";
	er::event_flags::grace_map[76823] = "[Castle Ensis] Ensis Moongazing Grounds";

	er::event_flags::grace_map[76831] = "[Cerulean Coast] Cerulean Coast";
	er::event_flags::grace_map[76835] = "[Cerulean Coast] Cerulean Coast Cross";
	er::event_flags::grace_map[76832] = "[Cerulean Coast] Cerulean Coast West";
	er::event_flags::grace_map[76834] = "[Cerulean Coast] Finger Ruins of Rhia";
	er::event_flags::grace_map[76833] = "[Cerulean Coast] The Fissure";

	er::event_flags::grace_map[76841] = "[Charo's Hidden Grave] Charo's Hidden Grave";
	er::event_flags::grace_map[74102] = "[Charo's Hidden Grave] Lamenter's Gaol";

	er::event_flags::grace_map[76653] = "[Consecrated Snowfield] Apostate Derelict";
	er::event_flags::grace_map[73112] = "[Consecrated Snowfield] Cave of the Forlorn";
	er::event_flags::grace_map[76550] = "[Consecrated Snowfield] Consecrated Snowfield";
	er::event_flags::grace_map[73019] = "[Consecrated Snowfield] Consecrated Snowfield Catacombs";
	er::event_flags::grace_map[76551] = "[Consecrated Snowfield] Inner Consecrated Snowfield";
	er::event_flags::grace_map[76652] = "[Consecrated Snowfield] Ordina, Liturgical Town";
	er::event_flags::grace_map[73211] = "[Consecrated Snowfield] Yelough Anix Tunnel";

	er::event_flags::grace_map[71310] = "[Crumbling Farum Azula] Beside the Great Bridge";
	er::event_flags::grace_map[71303] = "[Crumbling Farum Azula] Crumbling Beast Grave";
	er::event_flags::grace_map[71304] = "[Crumbling Farum Azula] Crumbling Beast Grave Depths";
	er::event_flags::grace_map[71306] = "[Crumbling Farum Azula] Dragon Temple";
	er::event_flags::grace_map[71302] = "[Crumbling Farum Azula] Dragon Temple Altar";
	er::event_flags::grace_map[71308] = "[Crumbling Farum Azula] Dragon Temple Lift";
	er::event_flags::grace_map[71309] = "[Crumbling Farum Azula] Dragon Temple Rooftop";
	er::event_flags::grace_map[71307] = "[Crumbling Farum Azula] Dragon Temple Transept";
	er::event_flags::grace_map[71301] = "[Crumbling Farum Azula] Dragonlord Placidusax";
	er::event_flags::grace_map[71300] = "[Crumbling Farum Azula] Maliketh, the Black Blade";
	er::event_flags::grace_map[71305] = "[Crumbling Farum Azula] Tempest,Facing Balcony";

	er::event_flags::grace_map[71235] = "[Deeproot Depths] Across the Roots";
	er::event_flags::grace_map[71233] = "[Deeproot Depths] Deeproot Depths";
	er::event_flags::grace_map[71232] = "[Deeproot Depths] Great Waterfall Crest";
	er::event_flags::grace_map[71230] = "[Deeproot Depths] Prince of Death's Throne";
	er::event_flags::grace_map[71231] = "[Deeproot Depths] Root,Facing Cliffs";
	er::event_flags::grace_map[71234] = "[Deeproot Depths] The Nameless Eternal City";

	er::event_flags::grace_map[71503] = "[Elphael, Brace of the Haligtree] Drainage Channel";
	er::event_flags::grace_map[71502] = "[Elphael, Brace of the Haligtree] Elphael Inner Wall";
	er::event_flags::grace_map[71504] = "[Elphael, Brace of the Haligtree] Haligtree Roots";
	er::event_flags::grace_map[71500] = "[Elphael, Brace of the Haligtree] Malenia, Goddess of Rot";
	er::event_flags::grace_map[71501] = "[Elphael, Brace of the Haligtree] Prayer Room";

	er::event_flags::grace_map[72015] = "[Enir-Ilim] Cleansing Chamber Anteroom";
	er::event_flags::grace_map[72016] = "[Enir-Ilim] Divine Gate Front Staircase";
	er::event_flags::grace_map[72012] = "[Enir-Ilim] Enir-Ilim: Outer Wall";
	er::event_flags::grace_map[72013] = "[Enir-Ilim] First Rise";
	er::event_flags::grace_map[72010] = "[Enir-Ilim] Gate of Divinity";
	er::event_flags::grace_map[72014] = "[Enir-Ilim] Spiral Rise";

	er::event_flags::grace_map[76507] = "[Flame Peak] Church of Repose";
	er::event_flags::grace_map[73017] = "[Flame Peak] Giant,Conquering Hero's Grave";
	er::event_flags::grace_map[73018] = "[Flame Peak] Giants' Mountaintop Catacombs";

	er::event_flags::grace_map[76850] = "[Foot of the Jagged Peak] Foot of the Jagged Peak";
	er::event_flags::grace_map[76840] = "[Foot of the Jagged Peak] Grand Altar of Dragon Communion";

	er::event_flags::grace_map[73451] = "[Forbidden Lands] Divine Tower of East Altus";
	er::event_flags::grace_map[73450] = "[Forbidden Lands] Divine Tower of East Altus: Gate";
	er::event_flags::grace_map[76500] = "[Forbidden Lands] Forbidden Lands";
	er::event_flags::grace_map[76502] = "[Forbidden Lands] Grand Lift of Rold";
	er::event_flags::grace_map[73020] = "[Forbidden Lands] Hidden Path to the Haligtree";

	er::event_flags::grace_map[74100] = "[Gravesite Plain] Belurat Gaol";
	er::event_flags::grace_map[76813] = "[Gravesite Plain] Castle Front";
	er::event_flags::grace_map[76804] = "[Gravesite Plain] Cliffroad Terminus";
	er::event_flags::grace_map[74301] = "[Gravesite Plain] Dragon's Pit";
	er::event_flags::grace_map[74351] = "[Gravesite Plain] Dragon's Pit Terminus";
	er::event_flags::grace_map[76812] = "[Gravesite Plain] Ellac River Cave";
	er::event_flags::grace_map[76830] = "[Gravesite Plain] Ellac River Downstream";
	er::event_flags::grace_map[74000] = "[Gravesite Plain] Fog Rift Catacombs";
	er::event_flags::grace_map[76800] = "[Gravesite Plain] Gravesite Plain";
	er::event_flags::grace_map[76805] = "[Gravesite Plain] Greatbridge, North";
	er::event_flags::grace_map[76803] = "[Gravesite Plain] Main Gate Cross";
	er::event_flags::grace_map[76810] = "[Gravesite Plain] Pillar Path Cross";
	er::event_flags::grace_map[76811] = "[Gravesite Plain] Pillar Path Waypoint";
	er::event_flags::grace_map[74300] = "[Gravesite Plain] Rivermouth Cave";
	er::event_flags::grace_map[74200] = "[Gravesite Plain] Ruined Forge Lava Intake";
	er::event_flags::grace_map[76801] = "[Gravesite Plain] Scorched Ruins";
	er::event_flags::grace_map[76802] = "[Gravesite Plain] Three,Path Cross";

	er::event_flags::grace_map[76454] = "[Greyoll's Dragonbarrow] Bestial Sanctum";
	er::event_flags::grace_map[73440] = "[Greyoll's Dragonbarrow] Divine Tower of Caelid: Basement";
	er::event_flags::grace_map[73441] = "[Greyoll's Dragonbarrow] Divine Tower of Caelid: Center";
	er::event_flags::grace_map[73110] = "[Greyoll's Dragonbarrow] Dragonbarrow Cave";
	er::event_flags::grace_map[76452] = "[Greyoll's Dragonbarrow] Dragonbarrow Fork";
	er::event_flags::grace_map[76450] = "[Greyoll's Dragonbarrow] Dragonbarrow West";
	er::event_flags::grace_map[76456] = "[Greyoll's Dragonbarrow] Farum Greatbridge";
	er::event_flags::grace_map[76453] = "[Greyoll's Dragonbarrow] Fort Faroth";
	er::event_flags::grace_map[73460] = "[Greyoll's Dragonbarrow] Isolated Divine Tower";
	er::event_flags::grace_map[76451] = "[Greyoll's Dragonbarrow] Isolated Merchant's Shack";
	er::event_flags::grace_map[76455] = "[Greyoll's Dragonbarrow] Lenne's Rise";
	er::event_flags::grace_map[73111] = "[Greyoll's Dragonbarrow] Sellia Hideaway";

	er::event_flags::grace_map[76851] = "[Jagged Peak] Jagged Peak Mountainside";
	er::event_flags::grace_map[76852] = "[Jagged Peak] Jagged Peak Summit";
	er::event_flags::grace_map[76853] = "[Jagged Peak] Rest of the Dread Dragon";

	er::event_flags::grace_map[71218] = "[Lake of Rot] Grand Cloister";
	er::event_flags::grace_map[71216] = "[Lake of Rot] Lake of Rot Shoreside";

	er::event_flags::grace_map[71125] = "[Leyndell, Ashen Capital] Divine Bridge";
	er::event_flags::grace_map[71122] = "[Leyndell, Ashen Capital] East Capital Rampart";
	er::event_flags::grace_map[71120] = "[Leyndell, Ashen Capital] Elden Throne";
	er::event_flags::grace_map[71121] = "[Leyndell, Ashen Capital] Erdtree Sanctuary";
	er::event_flags::grace_map[71123] = "[Leyndell, Ashen Capital] Leyndell, Capital of Ash";
	er::event_flags::grace_map[71124] = "[Leyndell, Ashen Capital] Queen's Bedchamber";
	er::event_flags::grace_map[71104] = "[Leyndell, Royal Capital] Avenue Balcony";
	er::event_flags::grace_map[71109] = "[Leyndell, Royal Capital] Divine Bridge";
	er::event_flags::grace_map[71102] = "[Leyndell, Royal Capital] East Capital Rampart";
	er::event_flags::grace_map[71100] = "[Leyndell, Royal Capital] Elden Throne";
	er::event_flags::grace_map[71101] = "[Leyndell, Royal Capital] Erdtree Sanctuary";
	er::event_flags::grace_map[71108] = "[Leyndell, Royal Capital] Fortified Manor, First Floor";
	er::event_flags::grace_map[71103] = "[Leyndell, Royal Capital] Lower Capital Church";
	er::event_flags::grace_map[71107] = "[Leyndell, Royal Capital] Queen's Bedchamber";
	er::event_flags::grace_map[71105] = "[Leyndell, Royal Capital] West Capital Rampart";

	er::event_flags::grace_map[76108] = "[Limgrave] Agheel Lake North";
	er::event_flags::grace_map[76106] = "[Limgrave] Agheel Lake South";
	er::event_flags::grace_map[76103] = "[Limgrave] Artist's Shack";
	er::event_flags::grace_map[76110] = "[Limgrave] Church of Dragon Communion";
	er::event_flags::grace_map[76100] = "[Limgrave] Church of Elleh";
	er::event_flags::grace_map[73115] = "[Limgrave] Coastal Cave";
	er::event_flags::grace_map[76105] = "[Limgrave] Fort Haight West";
	er::event_flags::grace_map[76111] = "[Limgrave] Gatefront Ruins";
	er::event_flags::grace_map[73103] = "[Limgrave] Groveside Cave";
	er::event_flags::grace_map[73117] = "[Limgrave] Highroad Cave";
	er::event_flags::grace_map[73201] = "[Limgrave] Limgrave Tunnels";
	er::event_flags::grace_map[76114] = "[Limgrave] Mistwood Outskirts";
	er::event_flags::grace_map[73004] = "[Limgrave] Murkwater Catacombs";
	er::event_flags::grace_map[73100] = "[Limgrave] Murkwater Cave";
	er::event_flags::grace_map[76116] = "[Limgrave] Murkwater Coast";
	er::event_flags::grace_map[76113] = "[Limgrave] Seaside Ruins";
	er::event_flags::grace_map[73002] = "[Limgrave] Stormfoot Catacombs";
	er::event_flags::grace_map[76119] = "[Limgrave] Summonwater Village Outskirts";
	er::event_flags::grace_map[76101] = "[Limgrave] The First Step";
	er::event_flags::grace_map[76104] = "[Limgrave] Third Church of Marika";
	er::event_flags::grace_map[76120] = "[Limgrave] Waypoint Ruins Cellar";

	er::event_flags::grace_map[73106] = "[Liurnia of the Lakes] Academy Crystal Cave";
	er::event_flags::grace_map[76204] = "[Liurnia of the Lakes] Academy Gate Town";
	er::event_flags::grace_map[76217] = "[Liurnia of the Lakes] Artist's Shack";
	er::event_flags::grace_map[76238] = "[Liurnia of the Lakes] Behind Caria Manor";
	er::event_flags::grace_map[73005] = "[Liurnia of the Lakes] Black Knife Catacombs";
	er::event_flags::grace_map[76216] = "[Liurnia of the Lakes] Boilprawn Shack";
	er::event_flags::grace_map[76224] = "[Liurnia of the Lakes] Church of Vows";
	er::event_flags::grace_map[73006] = "[Liurnia of the Lakes] Cliffbottom Catacombs";
	er::event_flags::grace_map[76237] = "[Liurnia of the Lakes] Converted Tower";
	er::event_flags::grace_map[76243] = "[Liurnia of the Lakes] Crystalline Woods";
	er::event_flags::grace_map[73422] = "[Liurnia of the Lakes] Divine Tower of Liurnia";
	er::event_flags::grace_map[76242] = "[Liurnia of the Lakes] East Gate Bridge Trestle";
	er::event_flags::grace_map[76223] = "[Liurnia of the Lakes] Eastern Liurnia Lake Shore";
	er::event_flags::grace_map[76234] = "[Liurnia of the Lakes] Eastern Tableland";
	er::event_flags::grace_map[76236] = "[Liurnia of the Lakes] Fallen Ruins of the Lake";
	er::event_flags::grace_map[76219] = "[Liurnia of the Lakes] Folly on the Lake";
	er::event_flags::grace_map[76210] = "[Liurnia of the Lakes] Foot of the Four Belfries";
	er::event_flags::grace_map[76222] = "[Liurnia of the Lakes] Gate Town Bridge";
	er::event_flags::grace_map[76233] = "[Liurnia of the Lakes] Gate Town North";
	er::event_flags::grace_map[76209] = "[Liurnia of the Lakes] Grand Lift of Dectus";
	er::event_flags::grace_map[76245] = "[Liurnia of the Lakes] Jarburg";
	er::event_flags::grace_map[76212] = "[Liurnia of the Lakes] Kingsrealm Ruins";
	er::event_flags::grace_map[76200] = "[Liurnia of the Lakes] Lake,Facing Cliffs";
	er::event_flags::grace_map[73105] = "[Liurnia of the Lakes] Lakeside Crystal Cave";
	er::event_flags::grace_map[76202] = "[Liurnia of the Lakes] Laskyar Ruins";
	er::event_flags::grace_map[76221] = "[Liurnia of the Lakes] Liurnia Highway North";
	er::event_flags::grace_map[76244] = "[Liurnia of the Lakes] Liurnia Highway South";
	er::event_flags::grace_map[76201] = "[Liurnia of the Lakes] Liurnia Lake Shore";
	er::event_flags::grace_map[73421] = "[Liurnia of the Lakes] Liurnia Tower Bridge";
	er::event_flags::grace_map[76206] = "[Liurnia of the Lakes] Main Academy Gate";
	er::event_flags::grace_map[76214] = "[Liurnia of the Lakes] Main Caria Manor Gate";
	er::event_flags::grace_map[76231] = "[Liurnia of the Lakes] Manor Lower Level";
	er::event_flags::grace_map[76230] = "[Liurnia of the Lakes] Manor Upper Level";
	er::event_flags::grace_map[76226] = "[Liurnia of the Lakes] Mausoleum Compound";
	er::event_flags::grace_map[76247] = "[Liurnia of the Lakes] Ranni's Chamber";
	er::event_flags::grace_map[76228] = "[Liurnia of the Lakes] Ranni's Rise";
	er::event_flags::grace_map[76229] = "[Liurnia of the Lakes] Ravine,Veiled Village";
	er::event_flags::grace_map[73202] = "[Liurnia of the Lakes] Raya Lucaria Crystal Tunnel";
	er::event_flags::grace_map[76218] = "[Liurnia of the Lakes] Revenger's Shack";
	er::event_flags::grace_map[76213] = "[Liurnia of the Lakes] Road to the Manor";
	er::event_flags::grace_map[76232] = "[Liurnia of the Lakes] Royal Moongazing Grounds";
	er::event_flags::grace_map[76225] = "[Liurnia of the Lakes] Ruined Labyrinth";
	er::event_flags::grace_map[76203] = "[Liurnia of the Lakes] Scenic Isle";
	er::event_flags::grace_map[76215] = "[Liurnia of the Lakes] Slumbering Wolf's Shack";
	er::event_flags::grace_map[76211] = "[Liurnia of the Lakes] Sorcerer's Isle";
	er::event_flags::grace_map[76205] = "[Liurnia of the Lakes] South Raya Lucaria Gate";
	er::event_flags::grace_map[73104] = "[Liurnia of the Lakes] Stillwater Cave";
	er::event_flags::grace_map[73420] = "[Liurnia of the Lakes] Study Hall Entrance";
	er::event_flags::grace_map[76241] = "[Liurnia of the Lakes] Temple Quarter";
	er::event_flags::grace_map[76227] = "[Liurnia of the Lakes] The Four Belfries";
	er::event_flags::grace_map[76235] = "[Liurnia of the Lakes] The Ravine";
	er::event_flags::grace_map[76220] = "[Liurnia of the Lakes] Village of the Albinaurics";
	er::event_flags::grace_map[73003] = "[Liurnia of the Lakes]Road's End Catacombs";

	er::event_flags::grace_map[72800] = "[Midra's Manse] Discussion Chamber";
	er::event_flags::grace_map[72801] = "[Midra's Manse] Manse Hall";
	er::event_flags::grace_map[72802] = "[Midra's Manse] Midra's Library";
	er::event_flags::grace_map[72803] = "[Midra's Manse] Second Floor Chamber";

	er::event_flags::grace_map[71506] = "[Miquella's Haligtree] Haligtree Canopy";
	er::event_flags::grace_map[71505] = "[Miquella's Haligtree] Haligtree Promenade";
	er::event_flags::grace_map[71507] = "[Miquella's Haligtree] Haligtree Town";
	er::event_flags::grace_map[71508] = "[Miquella's Haligtree] Haligtree Town Plaza";

	er::event_flags::grace_map[71250] = "[Mohgwyn Palace] Cocoon of the Empyrean";
	er::event_flags::grace_map[71252] = "[Mohgwyn Palace] Dynasty Mausoleum Entrance";
	er::event_flags::grace_map[71253] = "[Mohgwyn Palace] Dynasty Mausoleum Midpoint";
	er::event_flags::grace_map[71251] = "[Mohgwyn Palace] Palace Approach Ledge,Road";

	er::event_flags::grace_map[76252] = "[Moonlight Altar] Altar South";
	er::event_flags::grace_map[76251] = "[Moonlight Altar] Cathedral of Manus Celes";
	er::event_flags::grace_map[76250] = "[Moonlight Altar] Moonlight Altar";

	er::event_flags::grace_map[76503] = "[Mountaintops of the Giants] Ancient Snow Valley Ruins";
	er::event_flags::grace_map[76522] = "[Mountaintops of the Giants] Castle Sol Main Gate";
	er::event_flags::grace_map[76524] = "[Mountaintops of the Giants] Castle Sol Rooftop";
	er::event_flags::grace_map[76523] = "[Mountaintops of the Giants] Church of the Eclipse";
	er::event_flags::grace_map[76509] = "[Mountaintops of the Giants] Fire Giant";
	er::event_flags::grace_map[76505] = "[Mountaintops of the Giants] First Church of Marika";
	er::event_flags::grace_map[76508] = "[Mountaintops of the Giants] Foot of the Forge";
	er::event_flags::grace_map[76510] = "[Mountaintops of the Giants] Forge of the Giants";
	er::event_flags::grace_map[76504] = "[Mountaintops of the Giants] Freezing Lake";
	er::event_flags::grace_map[76506] = "[Mountaintops of the Giants] Giant's Gravepost";
	er::event_flags::grace_map[76521] = "[Mountaintops of the Giants] Snow Valley Ruins Overlook";
	er::event_flags::grace_map[73122] = "[Mountaintops of the Giants] Spiritcaller's Cave";
	er::event_flags::grace_map[76520] = "[Mountaintops of the Giants] Whiteridge Road";
	er::event_flags::grace_map[76501] = "[Mountaintops of the Giants] Zamor Ruins";

	er::event_flags::grace_map[76350] = "[Mt. Gelmir] Bridge of Iniquity";
	er::event_flags::grace_map[76356] = "[Mt. Gelmir] Craftman's Shack";
	er::event_flags::grace_map[76351] = "[Mt. Gelmir] First Mt. Gelmir Campsite";
	er::event_flags::grace_map[73009] = "[Mt. Gelmir] Gelmir Hero's Grave";
	er::event_flags::grace_map[76352] = "[Mt. Gelmir] Ninth Mt. Gelmir Campsite";
	er::event_flags::grace_map[76357] = "[Mt. Gelmir] Primeval Sorcerer Azur";
	er::event_flags::grace_map[76353] = "[Mt. Gelmir] Road of Iniquity";
	er::event_flags::grace_map[73107] = "[Mt. Gelmir] Seethewater Cave";
	er::event_flags::grace_map[76354] = "[Mt. Gelmir] Seethewater River";
	er::event_flags::grace_map[76355] = "[Mt. Gelmir] Seethewater Terminus";
	er::event_flags::grace_map[73109] = "[Mt. Gelmir] Volcano Cave";
	er::event_flags::grace_map[73007] = "[Mt. Gelmir] Wyndham Catacombs";

	er::event_flags::grace_map[71224] = "[Nokron, Eternal City] Ancestral Woods";
	er::event_flags::grace_map[71225] = "[Nokron, Eternal City] Aqueduct,Facing Cliffs";
	er::event_flags::grace_map[71220] = "[Nokron, Eternal City] Great Waterfall Basin";
	er::event_flags::grace_map[71221] = "[Nokron, Eternal City] Mimic Tear";
	er::event_flags::grace_map[71226] = "[Nokron, Eternal City] Night's Sacred Ground";
	er::event_flags::grace_map[71271] = "[Nokron, Eternal City] Nokron, Eternal City";

	er::event_flags::grace_map[76912] = "[Rauh Base] Ancient Ruins Base";
	er::event_flags::grace_map[76914] = "[Rauh Base] Ravine North";
	er::event_flags::grace_map[74001] = "[Rauh Base] Scorpion River Catacombs";
	er::event_flags::grace_map[74203] = "[Rauh Base] Taylew's Ruined Forge";
	er::event_flags::grace_map[76913] = "[Rauh Base] Temple Town Ruins";

	er::event_flags::grace_map[71190] = "[Roundtable Hold] Table of Lost Grace";

	er::event_flags::grace_map[73900] = "[Ruin,Strewn Precipice] Magma Wyrm Makar";
	er::event_flags::grace_map[73901] = "[Ruin,Strewn Precipice] Ruin,Strewn Precipice";
	er::event_flags::grace_map[73902] = "[Ruin,Strewn Precipice] Ruin,Strewn Precipice Overlook";

	er::event_flags::grace_map[76910] = "[Scadu Altus] Behind the Fort of Reprimand";
	er::event_flags::grace_map[74101] = "[Scadu Altus] Bonny Gaol";
	er::event_flags::grace_map[76903] = "[Scadu Altus] Bonny Village";
	er::event_flags::grace_map[76904] = "[Scadu Altus] Bridge Leading to the Village";
	er::event_flags::grace_map[76916] = "[Scadu Altus] Castle Watering Hole";
	er::event_flags::grace_map[76906] = "[Scadu Altus] Cathedral of Manus Metyr";
	er::event_flags::grace_map[76905] = "[Scadu Altus] Church District Highroad";
	er::event_flags::grace_map[74002] = "[Scadu Altus] Darklight Catacombs";
	er::event_flags::grace_map[72500] = "[Scadu Altus] Finger Birthing Grounds";
	er::event_flags::grace_map[76909] = "[Scadu Altus] Fort of Reprimand";
	er::event_flags::grace_map[76900] = "[Scadu Altus] Highroad Cross";
	er::event_flags::grace_map[76908] = "[Scadu Altus] Moorth Highway, South";
	er::event_flags::grace_map[76902] = "[Scadu Altus] Moorth Ruins";
	er::event_flags::grace_map[76918] = "[Scadu Altus] Recluses' River Downstream";
	er::event_flags::grace_map[76917] = "[Scadu Altus] Recluses' River Upstream";
	er::event_flags::grace_map[74202] = "[Scadu Altus] Ruined Forge of Starfall Past";
	er::event_flags::grace_map[76907] = "[Scadu Altus] Scadu Altus, West";
	er::event_flags::grace_map[76911] = "[Scadu Altus] Scaduview Cross";

	er::event_flags::grace_map[76936] = "[Scaduview] Fingerstone Hill";
	er::event_flags::grace_map[76935] = "[Scaduview] Hinterland";
	er::event_flags::grace_map[76937] = "[Scaduview] Hinterland Bridge";
	er::event_flags::grace_map[76960] = "[Scaduview] Scadutree Base";
	er::event_flags::grace_map[76930] = "[Scaduview] Scaduview";
	er::event_flags::grace_map[76931] = "[Scaduview] Shadow Keep, Back Gate";

	er::event_flags::grace_map[72106] = "[Shadow Keep, Church District] Church District Entrance";
	er::event_flags::grace_map[72107] = "[Shadow Keep, Church District] Sunken Chapel";
	er::event_flags::grace_map[72108] = "[Shadow Keep, Church District] Tree,Worship Passage";
	er::event_flags::grace_map[72109] = "[Shadow Keep, Church District] Tree,Worship Sanctum";

	er::event_flags::grace_map[72101] = "[Shadow Keep] Main Gate Plaza";
	er::event_flags::grace_map[72102] = "[Shadow Keep] Shadow Keep Main Gate";

	er::event_flags::grace_map[71227] = "[Siofra River] Below the Well";
	er::event_flags::grace_map[71222] = "[Siofra River] Siofra River Bank";
	er::event_flags::grace_map[71270] = "[Siofra River] Siofra River Well Depths";
	er::event_flags::grace_map[71223] = "[Siofra River] Worshippers' Woods";

	er::event_flags::grace_map[72114] = "[Specimen Storehouse] Dark Chamber Entrance";
	er::event_flags::grace_map[72110] = "[Specimen Storehouse] Messmer's Dark Chamber";
	er::event_flags::grace_map[72116] = "[Specimen Storehouse] Storehouse, Back Section";
	er::event_flags::grace_map[72111] = "[Specimen Storehouse] Storehouse, First Floor";
	er::event_flags::grace_map[72112] = "[Specimen Storehouse] Storehouse, Fourth Floor";
	er::event_flags::grace_map[72117] = "[Specimen Storehouse] Storehouse, Loft";
	er::event_flags::grace_map[72113] = "[Specimen Storehouse] Storehouse, Seventh Floor";
	er::event_flags::grace_map[72120] = "[Specimen Storehouse] West Rampart";

	er::event_flags::grace_map[72202] = "[Stone Coffin Fissure] Fissure Cross";
	er::event_flags::grace_map[72204] = "[Stone Coffin Fissure] Fissure Depths";
	er::event_flags::grace_map[72203] = "[Stone Coffin Fissure] Fissure Waypoint";
	er::event_flags::grace_map[72200] = "[Stone Coffin Fissure] Garden of Deep Purple";
	er::event_flags::grace_map[72201] = "[Stone Coffin Fissure] Stone Coffin Fissure";

	er::event_flags::grace_map[71900] = "[Stone Platform] Fractured Marika";

	er::event_flags::grace_map[71002] = "[Stormhill] Castleward Tunnel";
	er::event_flags::grace_map[73011] = "[Stormhill] Deathtouched Catacombs";
	er::event_flags::grace_map[73412] = "[Stormhill] Divine Tower of Limgrave";
	er::event_flags::grace_map[73410] = "[Stormhill] Limgrave Tower Bridge";
	er::event_flags::grace_map[71001] = "[Stormhill] Margit, the Fell Omen";
	er::event_flags::grace_map[76117] = "[Stormhill] Saintsbridge";
	er::event_flags::grace_map[76102] = "[Stormhill] Stormhill Shack";
	er::event_flags::grace_map[76118] = "[Stormhill] Warmaster's Shack";

	er::event_flags::grace_map[71003] = "[Stormveil Castle] Gateside Chamber";
	er::event_flags::grace_map[71000] = "[Stormveil Castle] Godrick the Grafted";
	er::event_flags::grace_map[71006] = "[Stormveil Castle] Liftside Chamber";
	er::event_flags::grace_map[71005] = "[Stormveil Castle] Rampart Tower";
	er::event_flags::grace_map[71007] = "[Stormveil Castle] Secluded Cell";
	er::event_flags::grace_map[71004] = "[Stormveil Castle] Stormveil Cliffside";
	er::event_flags::grace_map[71008] = "[Stormveil Castle] Stormveil Main Gate";

	er::event_flags::grace_map[71800] = "[Stranded Graveyard] Cave of Knowledge";
	er::event_flags::grace_map[71801] = "[Stranded Graveyard] Stranded Graveyard";

	er::event_flags::grace_map[73500] = "[Subterranean Shunning,Grounds] Cathedral of the Forsaken";
	er::event_flags::grace_map[73502] = "[Subterranean Shunning,Grounds] Forsaken Depths";
	er::event_flags::grace_map[73504] = "[Subterranean Shunning,Grounds] Frenzied Flame Proscription";
	er::event_flags::grace_map[73503] = "[Subterranean Shunning,Grounds] Leyndell Catacombs";
	er::event_flags::grace_map[73501] = "[Subterranean Shunning,Grounds] Underground Roadside";

	er::event_flags::grace_map[76406] = "[Swamp of Aeonia] Aeonia Swamp Shore";
	er::event_flags::grace_map[76407] = "[Swamp of Aeonia] Astray from Caelid Highway North";
	er::event_flags::grace_map[76412] = "[Swamp of Aeonia] Heart of Aeonia";
	er::event_flags::grace_map[76413] = "[Swamp of Aeonia] Inner Aeonia";

	er::event_flags::grace_map[71606] = "[Volcano Manor] Abductor Virgin";
	er::event_flags::grace_map[71605] = "[Volcano Manor] Audience Pathway";
	er::event_flags::grace_map[71604] = "[Volcano Manor] Guest Hall";
	er::event_flags::grace_map[71603] = "[Volcano Manor] Prison Town Church";
	er::event_flags::grace_map[71600] = "[Volcano Manor] Rykard, Lord of Blasphemy";
	er::event_flags::grace_map[71607] = "[Volcano Manor] Subterranean Inquisition Chamber";
	er::event_flags::grace_map[71601] = "[Volcano Manor] Temple of Eiglay";
	er::event_flags::grace_map[71602] = "[Volcano Manor] Volcano Manor";

	er::event_flags::grace_map[76154] = "[Weeping Peninsula] Ailing Village Outskirts";
	er::event_flags::grace_map[76159] = "[Weeping Peninsula] Behind the Castle";
	er::event_flags::grace_map[76155] = "[Weeping Peninsula] Beside the Crater,Pocked Glade";
	er::event_flags::grace_map[76160] = "[Weeping Peninsula] Beside the Rampart Gaol";
	er::event_flags::grace_map[76157] = "[Weeping Peninsula] Bridge of Sacrifice";
	er::event_flags::grace_map[76158] = "[Weeping Peninsula] Castle Morne Lift";
	er::event_flags::grace_map[76151] = "[Weeping Peninsula] Castle Morne Rampart";
	er::event_flags::grace_map[76150] = "[Weeping Peninsula] Church of Pilgrimage";
	er::event_flags::grace_map[73101] = "[Weeping Peninsula] Earthbore Cave";
	er::event_flags::grace_map[76162] = "[Weeping Peninsula] Fourth Church of Marika";
	er::event_flags::grace_map[73001] = "[Weeping Peninsula] Impaler's Catacombs";
	er::event_flags::grace_map[76156] = "[Weeping Peninsula] Isolated Merchant's Shack";
	er::event_flags::grace_map[76161] = "[Weeping Peninsula] Morne Moangrave";
	er::event_flags::grace_map[73200] = "[Weeping Peninsula] Morne Tunnel";
	er::event_flags::grace_map[76153] = "[Weeping Peninsula] South of the Lookout Tower";
	er::event_flags::grace_map[73000] = "[Weeping Peninsula] Tombsward Catacombs";
	er::event_flags::grace_map[73102] = "[Weeping Peninsula] Tombsward Cave";
	er::event_flags::grace_map[76152] = "[Weeping Peninsula] Weeping Evergaol";

	return true;
}();

// WorldMapPieceParam
static auto er_event_flags_init_map_piece_map = [&]() -> bool
{
	er::event_flags::map_piece_map[62000] = "Allow Map Display: Lands Between";
	er::event_flags::map_piece_map[62002] = "Allow Map Display: Shadow of the Erdtree";

	er::event_flags::map_piece_map[62010] = "Limgrave West";
	er::event_flags::map_piece_map[62011] = "Weeping Peninsula";
	er::event_flags::map_piece_map[62012] = "Limgrave East";
	er::event_flags::map_piece_map[62020] = "Liurnia East";
	er::event_flags::map_piece_map[62021] = "Liurnia North";
	er::event_flags::map_piece_map[62022] = "Liurnia West";
	er::event_flags::map_piece_map[62030] = "Altus Plateau";
	er::event_flags::map_piece_map[62031] = "Leyndell Royal Capital";
	er::event_flags::map_piece_map[62032] = "Mt. Gelmir";
	er::event_flags::map_piece_map[62040] = "Caelid";
	er::event_flags::map_piece_map[62041] = "Dragonbarrow";
	er::event_flags::map_piece_map[62050] = "Mountaintops of the Giants West";
	er::event_flags::map_piece_map[62051] = "Mountaintops of the Giants East";
	er::event_flags::map_piece_map[62052] = "Consecrated Snowfield";
	er::event_flags::map_piece_map[62004] = "Starfall Crater";
	er::event_flags::map_piece_map[62060] = "Ainsel River";
	er::event_flags::map_piece_map[62061] = "Lake of Rot";
	er::event_flags::map_piece_map[62062] = "Mohgwyn Palace";
	er::event_flags::map_piece_map[62063] = "Siofra River";
	er::event_flags::map_piece_map[62064] = "Deeproot Depths";

	er::event_flags::map_piece_map[62080] = "Gravesite Plain";
	er::event_flags::map_piece_map[62081] = "Scadu Altus";
	er::event_flags::map_piece_map[62082] = "Southern Shore";
	er::event_flags::map_piece_map[62083] = "Rauh Ruins";
	er::event_flags::map_piece_map[62084] = "Abyss";

	return true;
}();

// ShopLineupParam_Recipe
static auto er_event_flags_init_cook_book_map = [&]() -> bool
{
	er::event_flags::cook_book_map[68000] = "Ancient Dragon Apostle's Cookbook [1]";
	er::event_flags::cook_book_map[68010] = "Ancient Dragon Apostle's Cookbook [2]";
	er::event_flags::cook_book_map[68030] = "Ancient Dragon Apostle's Cookbook [3]";
	er::event_flags::cook_book_map[68020] = "Ancient Dragon Apostle's Cookbook [4]";
	
	er::event_flags::cook_book_map[68740] = "Ancient Dragon Knight's Cookbook [1]";
	er::event_flags::cook_book_map[68780] = "Ancient Dragon Knight's Cookbook [2]";
	
	er::event_flags::cook_book_map[68910] = "Antiquity Scholar's Cookbook [1]";
	er::event_flags::cook_book_map[68860] = "Antiquity Scholar's Cookbook [2]";
	
	er::event_flags::cook_book_map[67200] = "Armorer's Cookbook [1]";
	er::event_flags::cook_book_map[67210] = "Armorer's Cookbook [2]";
	er::event_flags::cook_book_map[67280] = "Armorer's Cookbook [3]";
	er::event_flags::cook_book_map[67260] = "Armorer's Cookbook [4]";
	er::event_flags::cook_book_map[67310] = "Armorer's Cookbook [5]";
	er::event_flags::cook_book_map[67300] = "Armorer's Cookbook [6]";
	er::event_flags::cook_book_map[67250] = "Armorer's Cookbook [7]";
	
	er::event_flags::cook_book_map[68800] = "Battlefield Priest's Cookbook [1]";
	er::event_flags::cook_book_map[68820] = "Battlefield Priest's Cookbook [2]";
	er::event_flags::cook_book_map[68890] = "Battlefield Priest's Cookbook [3]";
	er::event_flags::cook_book_map[68930] = "Battlefield Priest's Cookbook [4]";
	
	er::event_flags::cook_book_map[68200] = "Fevor's Cookbook [1]";
	er::event_flags::cook_book_map[68220] = "Fevor's Cookbook [2]";
	er::event_flags::cook_book_map[68210] = "Fevor's Cookbook [3]";
	
	er::event_flags::cook_book_map[68920] = "Finger-Weaver's Cookbook [1]";
	er::event_flags::cook_book_map[68580] = "Finger-Weaver's Cookbook [2]";
	
	er::event_flags::cook_book_map[68770] = "Fire Knight's Cookbook [1]";
	er::event_flags::cook_book_map[68900] = "Fire Knight's Cookbook [2]";
	
	er::event_flags::cook_book_map[68520] = "Forager Brood Cookbook [1]";
	er::event_flags::cook_book_map[68530] = "Forager Brood Cookbook [2]";
	er::event_flags::cook_book_map[68540] = "Forager Brood Cookbook [3]";
	er::event_flags::cook_book_map[68550] = "Forager Brood Cookbook [4]";
	er::event_flags::cook_book_map[68560] = "Forager Brood Cookbook [5]";
	er::event_flags::cook_book_map[68510] = "Forager Brood Cookbook [6]";
	er::event_flags::cook_book_map[68830] = "Forager Brood Cookbook [7]";
	
	er::event_flags::cook_book_map[68400] = "Frenzied's Cookbook [1]";
	er::event_flags::cook_book_map[68410] = "Frenzied's Cookbook [2]";
	
	er::event_flags::cook_book_map[67410] = "Glintstone Craftsman's Cookbook [1]";
	er::event_flags::cook_book_map[67450] = "Glintstone Craftsman's Cookbook [2]";
	er::event_flags::cook_book_map[67480] = "Glintstone Craftsman's Cookbook [3]";
	er::event_flags::cook_book_map[67400] = "Glintstone Craftsman's Cookbook [4]";
	er::event_flags::cook_book_map[67420] = "Glintstone Craftsman's Cookbook [5]";
	er::event_flags::cook_book_map[67460] = "Glintstone Craftsman's Cookbook [6]";
	er::event_flags::cook_book_map[67470] = "Glintstone Craftsman's Cookbook [7]";
	er::event_flags::cook_book_map[67440] = "Glintstone Craftsman's Cookbook [8]";
	
	er::event_flags::cook_book_map[68940] = "Grave Keeper's Cookbook [1]";
	er::event_flags::cook_book_map[68850] = "Grave Keeper's Cookbook [2]";
	
	er::event_flags::cook_book_map[68590] = "Greater Potentate's Cookbook [1]";
	er::event_flags::cook_book_map[68730] = "Greater Potentate's Cookbook [2]";
	er::event_flags::cook_book_map[68690] = "Greater Potentate's Cookbook [3]";
	er::event_flags::cook_book_map[68600] = "Greater Potentate's Cookbook [4]";
	er::event_flags::cook_book_map[68610] = "Greater Potentate's Cookbook [5]";
	er::event_flags::cook_book_map[68720] = "Greater Potentate's Cookbook [6]";
	er::event_flags::cook_book_map[68630] = "Greater Potentate's Cookbook [7]";
	er::event_flags::cook_book_map[68680] = "Greater Potentate's Cookbook [8]";
	er::event_flags::cook_book_map[68640] = "Greater Potentate's Cookbook [9]";
	er::event_flags::cook_book_map[68650] = "Greater Potentate's Cookbook [10]";
	er::event_flags::cook_book_map[68660] = "Greater Potentate's Cookbook [11]";
	er::event_flags::cook_book_map[68620] = "Greater Potentate's Cookbook [12]";
	er::event_flags::cook_book_map[68700] = "Greater Potentate's Cookbook [13]";
	er::event_flags::cook_book_map[68710] = "Greater Potentate's Cookbook [14]";
	
	er::event_flags::cook_book_map[68810] = "Igon's Cookbook [1]";
	er::event_flags::cook_book_map[68570] = "Igon's Cookbook [2]";
	
	er::event_flags::cook_book_map[68790] = "Loyal Knight's Cookbook";
	
	er::event_flags::cook_book_map[68750] = "Mad Craftsman's Cookbook [1]";
	er::event_flags::cook_book_map[68670] = "Mad Craftsman's Cookbook [2]";
	er::event_flags::cook_book_map[68880] = "Mad Craftsman's Cookbook [3]";
	
	er::event_flags::cook_book_map[67610] = "Missionary's Cookbook [1]";
	er::event_flags::cook_book_map[67600] = "Missionary's Cookbook [2]";
	er::event_flags::cook_book_map[67650] = "Missionary's Cookbook [3]";
	er::event_flags::cook_book_map[67640] = "Missionary's Cookbook [4]";
	er::event_flags::cook_book_map[67630] = "Missionary's Cookbook [5]";
	er::event_flags::cook_book_map[67130] = "Missionary's Cookbook [6]";
	er::event_flags::cook_book_map[68230] = "Missionary's Cookbook [7]";
	
	er::event_flags::cook_book_map[67000] = "Nomadic Warrior's Cookbook [1]";
	er::event_flags::cook_book_map[67110] = "Nomadic Warrior's Cookbook [2]";
	er::event_flags::cook_book_map[67010] = "Nomadic Warrior's Cookbook [3]";
	er::event_flags::cook_book_map[67800] = "Nomadic Warrior's Cookbook [4]";
	er::event_flags::cook_book_map[67830] = "Nomadic Warrior's Cookbook [5]";
	er::event_flags::cook_book_map[67020] = "Nomadic Warrior's Cookbook [6]";
	er::event_flags::cook_book_map[67050] = "Nomadic Warrior's Cookbook [7]";
	er::event_flags::cook_book_map[67880] = "Nomadic Warrior's Cookbook [8]";
	er::event_flags::cook_book_map[67430] = "Nomadic Warrior's Cookbook [9]";
	er::event_flags::cook_book_map[67030] = "Nomadic Warrior's Cookbook [10]";
	er::event_flags::cook_book_map[67220] = "Nomadic Warrior's Cookbook [11]";
	er::event_flags::cook_book_map[67060] = "Nomadic Warrior's Cookbook [12]";
	er::event_flags::cook_book_map[67080] = "Nomadic Warrior's Cookbook [13]";
	er::event_flags::cook_book_map[67870] = "Nomadic Warrior's Cookbook [14]";
	er::event_flags::cook_book_map[67900] = "Nomadic Warrior's Cookbook [15]";
	er::event_flags::cook_book_map[67290] = "Nomadic Warrior's Cookbook [16]";
	er::event_flags::cook_book_map[67100] = "Nomadic Warrior's Cookbook [17]";
	er::event_flags::cook_book_map[67270] = "Nomadic Warrior's Cookbook [18]";
	er::event_flags::cook_book_map[67070] = "Nomadic Warrior's Cookbook [19]";
	er::event_flags::cook_book_map[67230] = "Nomadic Warrior's Cookbook [20]";
	er::event_flags::cook_book_map[67120] = "Nomadic Warrior's Cookbook [21]";
	er::event_flags::cook_book_map[67890] = "Nomadic Warrior's Cookbook [22]";
	er::event_flags::cook_book_map[67090] = "Nomadic Warrior's Cookbook [23]";
	er::event_flags::cook_book_map[67910] = "Nomadic Warrior's Cookbook [24]";
	
	er::event_flags::cook_book_map[67840] = "Perfumer's Cookbook [1]";
	er::event_flags::cook_book_map[67850] = "Perfumer's Cookbook [2]";
	er::event_flags::cook_book_map[67860] = "Perfumer's Cookbook [3]";
	er::event_flags::cook_book_map[67920] = "Perfumer's Cookbook [4]";
	
	er::event_flags::cook_book_map[68760] = "St. Trina Disciple's Cookbook [1]";
	er::event_flags::cook_book_map[68950] = "St. Trina Disciple's Cookbook [2]";
	er::event_flags::cook_book_map[68840] = "St. Trina Disciple's Cookbook [3]";
	
	er::event_flags::cook_book_map[68870] = "Tibia's Cookbook";

	return true;
}();

// ??? (dumped manually)
static auto er_event_flags_init_affinities_map = [&]() -> bool
{
	er::event_flags::affinities_map[60130] = "Whetstone Knife";

	er::event_flags::affinities_map[65610] = "Heavy";
	er::event_flags::affinities_map[65620] = "Keen";
	er::event_flags::affinities_map[65630] = "Quality";

	er::event_flags::affinities_map[65640] = "Fire";
	er::event_flags::affinities_map[65650] = "Flame Art";

	er::event_flags::affinities_map[65660] = "Lightning";
	er::event_flags::affinities_map[65670] = "Sacred";

	er::event_flags::affinities_map[65680] = "Magic";
	er::event_flags::affinities_map[65690] = "Frost";

	er::event_flags::affinities_map[65700] = "Poison";
	er::event_flags::affinities_map[65710] = "Blood";
	er::event_flags::affinities_map[65720] = "Occult";

	return true;
}();