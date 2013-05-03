static int
nft_rule_expr_bitwise_snprintf_json(char *buf, size_t size,
				   struct nft_expr_bitwise *bitwise)
{
	int len = size, offset = 0, ret;

	ret = snprintf(buf, len, "\"sreg\" : %u,"
				"\"dreg\" : %u,",
		       bitwise->sreg, bitwise->dreg);
	SNPRINTF_BUFFER_SIZE(ret, size, len, offset);

	ret = snprintf(buf+offset, len, "\"mask\" : \"");
	SNPRINTF_BUFFER_SIZE(ret, size, len, offset);

	ret = nft_data_reg_snprintf(buf+offset, len, &bitwise->mask,
				    NFT_RULE_O_XML, 0, DATA_VALUE);
	SNPRINTF_BUFFER_SIZE(ret, size, len, offset);

	ret = snprintf(buf+offset, len, "\",\"xor\" : \"");
	SNPRINTF_BUFFER_SIZE(ret, size, len, offset);

	ret = nft_data_reg_snprintf(buf+offset, len, &bitwise->xor,
				    NFT_RULE_O_XML, 0, DATA_VALUE);
	SNPRINTF_BUFFER_SIZE(ret, size, len, offset);

	ret = snprintf(buf+offset, len, "\"");
	SNPRINTF_BUFFER_SIZE(ret, size, len, offset);

	return offset;
}
