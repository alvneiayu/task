static int
nft_rule_expr_counter_snprintf(char *buf, size_t len, uint32_t type,
			       uint32_t flags, struct nft_rule_expr *e)
{
	struct nft_expr_counter *ctr = (struct nft_expr_counter *)e->data;

	switch(type) {
	case NFT_RULE_O_XML:
		return snprintf(buf, len, "<pkts>%lu</pkts><bytes>%lu</bytes>",
				ctr->pkts, ctr->bytes);
	case NFT_RULE_O_JSON:
		return snprintf(buf, len, "\"pkts\" : %lu, \"bytes\" : %lu",
				ctr->pkts, ctr->bytes);
	case NFT_RULE_O_DEFAULT:
		return snprintf(buf, len, "pkts=%lu bytes=%lu ",
				ctr->pkts, ctr->bytes);
	default:
		break;
	}
	return -1;
}
