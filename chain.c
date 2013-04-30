static int nft_chain_snprintf_xml(char *buf, size_t size, struct nft_chain *c)
{
	return snprintf(buf, size,
		"{ \"chain\": {"
			"\"name\": \"%s\","
			"\"handle\": %lu,"
			"\"bytes\": %lu,"
			"\"packets\": %lu,"
			"\"properties\": {"
				"\"flags\" : %d,"
				"\"type\" : \"%s\","
				"\"table\" : \"%s\","
				"\"prio\" : %d,"
				"\"use\" : %d,"
				"\"hooknum\" : %d,"
				"\"policy\" : %d,"
				"\"family\" : %d"
			"}"
		"}"
		"}",
			c->name, c->handle, c->bytes, c->packets,
			c->flags, c->type, c->table, c->prio,
			c->use, c->hooknum, c->policy, c->family);
}
