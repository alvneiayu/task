static int
nft_rule_expr_payload_snprintf_json(char *buf, size_t len, uint32_t type,
			       uint32_t flags, struct nft_rule_expr *e)
{
	struct nft_expr_payload *payload = (struct nft_expr_payload *)e->data;

	switch(type) {
	case NFT_RULE_O_JSON:
		return snprintf(buf, len, "\"dreg\" : %u,"
					  "\"base\" : %u, \"offset\" : %u,"
					  "\"len\" : %u",
				payload->dreg, payload->base,
					payload->offset, payload->len);

	case NFT_RULE_O_XML:
		return snprintf(buf, len, "<dreg>%u</dreg>"
					  "<base>%u</base><offset>%u</offset>"
					  "<len>%u</len>",
				payload->dreg, payload->base,
					payload->offset, payload->len);

	case NFT_RULE_O_DEFAULT:
		return snprintf(buf, len, "dreg=%u base=%u offset=%u len=%u ",
				payload->dreg, payload->base,
				payload->offset, payload->len);
	default:
		break;
	}
	return -1;
}
