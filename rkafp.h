#ifndef _RKAFP_H
#define _RKAFP_H

struct update_part {
	char name[32];
	char filename[60];
	unsigned int nand_size;
	unsigned int pos;
	unsigned int nand_addr;
	unsigned int padded_size;
	unsigned int size;
};

#define RKAFP_MAGIC "RKAF"

struct update_header {
	char magic[4];
	unsigned int length;
	char model[0x22];
	char id[0x1e];
	char manufacturer[0x38];
	unsigned int unknown1;
	unsigned int version;
	unsigned int num_parts;

	/*
		RK2919: num_parts = 16    , reserved len = 0x74. Header len 2048.
		RK3562: num_parts = 20 (?), reserved len =   34. Header len 4096.
	*/
	struct update_part parts[35];	// 35 entries can fit in 4096 bytes header.
	unsigned char reserved[34];
};

struct param_header {
	char magic[4];
	unsigned int length;
};

#endif // _RKAFP_H
