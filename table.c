#include <stdio.h>
#include <string.h>

static int nft_table_snprintf_json(char *buf, size_t size, struct nft_table *t)
{
	return snprintf(buf, size,
			"{\"table\" : {"
			"\"name\" : \"%s\"," 
			"\"properties\" : {"
				"\"family\" : %u,"
				"\"flags\" : %d,"
				"\"table_flags\" : %d"
				"}"
			"}"
			"}" ,
			t->name, t->family, t->flags, t->table_flags);
}
