static int
nft_rule_expr_meta_snprintf(char *buf, size_t len, uint32_t type,
			    uint32_t flags, struct nft_rule_expr *e)
{
	struct nft_expr_meta *meta = (struct nft_expr_meta *)e->data;

	switch(type) {
	case NFT_RULE_O_JSON:
		return snprintf(buf, len, "\"dreg\" : %u,"
					  "\"key\" : %u",
				meta->dreg, meta->key);
	case NFT_RULE_O_XML:
		return snprintf(buf, len, "<dreg>%u</dreg>"
					  "<key>%u</key>",
				meta->dreg, meta->key);
	case NFT_RULE_O_DEFAULT:
		return snprintf(buf, len, "dreg=%u key=%u ",
				meta->dreg, meta->key);
	default:
		break;
	}
	return -1;
}
