static int
nft_rule_expr_cmp_snprintf_json(char *buf, size_t size, struct nft_expr_cmp *cmp)
{
	int len = size, offset = 0, ret;

	ret = snprintf(buf, len, "\"sreg\" : %u ,\"op\" : \"%s\", \"cmpdata\" : \"",
		       cmp->sreg, expr_cmp_str[cmp->op]);
	SNPRINTF_BUFFER_SIZE(ret, size, len, offset);

	ret = nft_data_reg_snprintf(buf+offset, len, &cmp->data,
				    NFT_RULE_O_XML, 0, DATA_VALUE);
	SNPRINTF_BUFFER_SIZE(ret, size, len, offset);

	ret = snprintf(buf+offset, len, "\"");
	SNPRINTF_BUFFER_SIZE(ret, size, len, offset);

	return offset;
}
