static int
nft_rule_expr_immediate_snprintf_json(char *buf, size_t len,
				     struct nft_rule_expr *e, uint32_t flags)
{
	int size = len, offset = 0, ret;
	struct nft_expr_immediate *imm = (struct nft_expr_immediate *)e->data;

	ret = snprintf(buf, len, "\"dreg\" : %u,"
				"\"immediatedata\" : \"", imm->dreg);
	SNPRINTF_BUFFER_SIZE(ret, size, len, offset);


	if (e->flags & (1 << NFT_EXPR_IMM_DATA)) {
		ret = nft_data_reg_snprintf(buf+offset, len, &imm->data,
					    NFT_RULE_O_XML, flags, DATA_VALUE);
		SNPRINTF_BUFFER_SIZE(ret, size, len, offset);

	} else if (e->flags & (1 << NFT_EXPR_IMM_VERDICT)) {
		ret = nft_data_reg_snprintf(buf+offset, len, &imm->data,
					  NFT_RULE_O_XML, flags, DATA_VERDICT);
		SNPRINTF_BUFFER_SIZE(ret, size, len, offset);

	} else if (e->flags & (1 << NFT_EXPR_IMM_CHAIN)) {
		ret = nft_data_reg_snprintf(buf+offset, len, &imm->data,
					    NFT_RULE_O_XML, flags, DATA_CHAIN);
		SNPRINTF_BUFFER_SIZE(ret, size, len, offset);
	}

	ret = snprintf(buf+offset, len, "\"");
	SNPRINTF_BUFFER_SIZE(ret, size, len, offset);

	return offset;
}
