// Copyright (c) 2011-2016 The Cryptonote developers, The PalladiumCoin Developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <cstdint>
#include <initializer_list>

namespace CryptoNote {
	namespace parameters {

		const uint64_t CRYPTONOTE_MAX_BLOCK_NUMBER = 500000000;
		const size_t   CRYPTONOTE_MAX_BLOCK_BLOB_SIZE = 500000000;
		const size_t   CRYPTONOTE_MAX_TX_SIZE = 1000000000;
		const uint64_t CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX = 0x21c105;
		const size_t   CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW = 60;
		const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT = 60 * 60 * 2;
		const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW = 60;

		//22 million atomic units
		//1 coin = 10^8 atomic units
		const uint64_t MONEY_SUPPLY = UINT64_C(200000000000000);
		const unsigned EMISSION_SPEED_FACTOR = 20;
		static_assert(EMISSION_SPEED_FACTOR <= 8 * sizeof(uint64_t), "Bad EMISSION_SPEED_FACTOR");


		const size_t   CRYPTONOTE_REWARD_BLOCKS_WINDOW = 100;
		const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE = 20000; //size of block (bytes) after which reward for block calculated using block size
		const size_t   CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE = 600;
		const size_t   CRYPTONOTE_DISPLAY_DECIMAL_POINT = 8;
		const uint64_t MINIMUM_FEE = 100000;
		const uint64_t DEFAULT_DUST_THRESHOLD = MINIMUM_FEE;

		//TODO Define preferred block's target time
		const uint64_t DIFFICULTY_TARGET = 120; // seconds
		const uint64_t EXPECTED_NUMBER_OF_BLOCKS_PER_DAY = 24 * 60 * 60 / DIFFICULTY_TARGET;
		const size_t   DIFFICULTY_WINDOW = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY; // blocks
		const size_t   DIFFICULTY_WINDOW_V2 = 17;

		const size_t   DIFFICULTY_CUT = 60;  // timestamps to cut after sorting
		const size_t   DIFFICULTY_LAG = 15;
		static_assert(2 * DIFFICULTY_CUT <= DIFFICULTY_WINDOW - 2, "Bad DIFFICULTY_WINDOW or DIFFICULTY_CUT");

		const size_t   MAX_BLOCK_SIZE_INITIAL = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE * 10;;
		const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR = 100 * 1024;
		const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR = 365 * 24 * 60 * 60 / DIFFICULTY_TARGET;

		const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS = 1;
		const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS = DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS;

		const uint64_t CRYPTONOTE_MEMPOOL_TX_LIVETIME = 60 * 60 * 24;     //seconds, one day
		const uint64_t CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME = 60 * 60 * 24 * 7; //seconds, one week
		const uint64_t CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL = 7;  // CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL * CRYPTONOTE_MEMPOOL_TX_LIVETIME = time to forget tx

		const size_t   FUSION_TX_MAX_SIZE = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE * 30 / 100;
		const size_t   FUSION_TX_MIN_INPUT_COUNT = 12;
		const size_t   FUSION_TX_MIN_IN_OUT_COUNT_RATIO = 4;

		const char     CRYPTONOTE_BLOCKS_FILENAME[] = "blocks.dat";
		const char     CRYPTONOTE_BLOCKINDEXES_FILENAME[] = "blockindexes.dat";
		const char     CRYPTONOTE_BLOCKSCACHE_FILENAME[] = "blockscache.dat";
		const char     CRYPTONOTE_POOLDATA_FILENAME[] = "poolstate.bin";
		const char     P2P_NET_DATA_FILENAME[] = "p2pstate.bin";
		const char     CRYPTONOTE_BLOCKCHAIN_INDICES_FILENAME[] = "blockchainindices.dat";
		const char     MINER_CONFIG_FILE_NAME[] = "miner_conf.json";
	} // parameters


	const char     CRYPTONOTE_NAME[] = "palladiumcoin";
	const char GENESIS_COINBASE_TX_HEX[] = "013c01ff00018fc4f95a029b2e4c0281c0b02e7c53291a94d1d0cbff8883f8024f5142ee494ffbbd08807121016b1876482df415df9fe9e2aa7890aad9502b357aae9110b91ef1458549933975";

	const uint8_t  CURRENT_TRANSACTION_VERSION = 1;
	const uint8_t  BLOCK_MAJOR_VERSION_1 = 1;
	const uint8_t  BLOCK_MAJOR_VERSION_2 = 2;
	const uint8_t  BLOCK_MINOR_VERSION_0 = 0;

	const size_t   BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT = 10000;  //by default, blocks ids count in synchronizing
	const size_t   BLOCKS_SYNCHRONIZING_DEFAULT_COUNT = 200;    //by default, blocks count in blocks downloading
	const size_t   COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT = 1000;


	const int      P2P_DEFAULT_PORT = 45174;
	const int      RPC_DEFAULT_PORT = 62722;

	const size_t   P2P_LOCAL_WHITE_PEERLIST_LIMIT = 1000;
	const size_t   P2P_LOCAL_GRAY_PEERLIST_LIMIT = 5000;

	const size_t   P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE = 16 * 1024 * 1024; // 16 MB
	const uint32_t P2P_DEFAULT_CONNECTIONS_COUNT = 8;
	const size_t   P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT = 70;
	const uint32_t P2P_DEFAULT_HANDSHAKE_INTERVAL = 60;            // seconds
	const uint32_t P2P_DEFAULT_PACKET_MAX_SIZE = 50000000;      // 50000000 bytes maximum packet size
	const uint32_t P2P_DEFAULT_PEERS_IN_HANDSHAKE = 250;
	const uint32_t P2P_DEFAULT_CONNECTION_TIMEOUT = 5000;          // 5 seconds
	const uint32_t P2P_DEFAULT_PING_CONNECTION_TIMEOUT = 2000;          // 2 seconds
	const uint64_t P2P_DEFAULT_INVOKE_TIMEOUT = 60 * 2 * 1000; // 2 minutes
	const size_t   P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT = 5000;          // 5 seconds
	const char     P2P_STAT_TRUSTED_PUB_KEY[] = "0101010101010101010101010101010102010101010101010101010101010101";


	const std::initializer_list<const char*> SEED_NODES = {
	  "144.217.14.221:45174",
	  "37.187.244.214:45174",
	  "84.200.105.175:45174",
	  "seed.greyblockgames.com:45174",
	  "traid.me:45174",
	};

	struct CheckpointData {
		uint32_t height;
		const char* blockId;
	};

#ifdef __GNUC__
	__attribute__((unused))
#endif

		// You may add here other checkpoints using the following format:
		// {<block height>, "<block hash>"},
		const std::initializer_list<CheckpointData> CHECKPOINTS = {
		  { 4000, "8b5a63cb0299a6c451bbae49df9cb6827bd0f19250ae6cd532faddff89eda281" },
		  { 8000, "8c383350fa5e2de80e75c1115affde770b1a52d71702aabb348e8c1063b260c4" },
		  { 12000, "07512c8f09695f4959a68e98440cc0d1174b39a7eb5ff7da4e0838e62c7e2b7d" },
		  { 14950, "0141c33f8136a2bd73756ebccbf0c6dd0d47e98e9045c87a6653da28f1ad5672" },
		  { 20800, "0eab5c1d9f2941b9e225129cb340a774b07593264ba3a1cba2ffdd687b4586b1" },
		  { 23800, "012009e671fd49acd1e3626ad4dea99d5e1a17a018961472efacbb1d0fe855d9"}

	};
}

#define ALLOW_DEBUG_COMMANDS
